// Copyright 2026, The Macaulay2 Authors.

#include "interface/ring.h"
#include "relem.hpp"
#include "util.hpp"
#include "weylalg.hpp"
#include "RingTest.hpp"
#include "util-polyring-creation.hpp"

class WeylAlgebraTestAccessor {
 public:
  static ring_elem binomial(const WeylAlgebra* W, int top, int bottom) {
    return W->binomial(top, bottom);
  }
  static ring_elem multinomial(const WeylAlgebra* W,
                               const ring_elem a,
                               const_exponents exptop,
                               const_exponents expbottom) {
    return W->multinomial(a, exptop, expbottom);
  }
  static const Ring* coefficientRing(const WeylAlgebra* W) {
    return W->getCoefficients();
  }
  static int nderivatives(const WeylAlgebra* W) {
    return W->_nderivatives;
  }
};

// Test fixture: creates a WeylAlgebra QQ[x,y,Dx,Dy]
class WeylAlgebraTest : public ::testing::Test {
 protected:
  const WeylAlgebra* W = nullptr;
  const Ring* K = nullptr;  // coefficient ring (QQ)

  void SetUp() override {
    W = simpleWeylAlgebra(0, {"x", "y", "Dx", "Dy"}, {0, 1}, {2, 3});
    K = WeylAlgebraTestAccessor::coefficientRing(W);
  }

  // Helper: check that a ring_elem in K equals a given long value
  void expectEqualLong(ring_elem actual, long expected) {
    ring_elem exp = K->from_long(expected);
    EXPECT_TRUE(K->is_equal(actual, exp));
  }
};

TEST_F(WeylAlgebraTest, create)
{
  EXPECT_FALSE(W->is_commutative_ring());
  EXPECT_TRUE(W->is_weyl_algebra());
  EXPECT_EQ(4, W->n_vars());
  EXPECT_EQ(2, WeylAlgebraTestAccessor::nderivatives(W));

  std::string ans {"WeylAlgebra(QQGMP[x,y,Dx,Dy,\n"
                   "  DegreeLength => 1,\n"
                   "  Degrees => {1, 1, -1, -1},\n"
                   "  Heft => {1},\n"
                   "  MonomialOrder => {\n"
                   "    GRevLex => {1,1,1,1},\n"
                   "    Position => Up\n"
                   "    }\n"
                   "  ])" };
  buffer o;
  W->text_out(o);
  EXPECT_EQ(ans, std::string(o.str()));
}

TEST_F(WeylAlgebraTest, commutator)
{
  // Test Dx*x - x*Dx == 1 (the defining Weyl relation)
  RingElement *x = new RingElement(W, W->var(0));
  RingElement *Dx = new RingElement(W, W->var(2));
  RingElement *one = new RingElement(W, W->from_long(1));

  RingElement *DxTimesX = (*Dx) * (*x);
  RingElement *xTimesDx = (*x) * (*Dx);
  RingElement *commutator = (*DxTimesX) - (*xTimesDx);
  EXPECT_TRUE(commutator->is_equal(*one));

  // Test Dy*y - y*Dy == 1
  RingElement *y = new RingElement(W, W->var(1));
  RingElement *Dy = new RingElement(W, W->var(3));

  RingElement *DyTimesY = (*Dy) * (*y);
  RingElement *yTimesDy = (*y) * (*Dy);
  RingElement *commutator2 = (*DyTimesY) - (*yTimesDy);
  EXPECT_TRUE(commutator2->is_equal(*one));

  // Test Dx*y - y*Dx == 0 (cross terms commute)
  RingElement *zero = new RingElement(W, W->from_long(0));
  RingElement *DxTimesY = (*Dx) * (*y);
  RingElement *yTimesDx = (*y) * (*Dx);
  RingElement *cross = (*DxTimesY) - (*yTimesDx);
  EXPECT_TRUE(cross->is_equal(*zero));
}

TEST_F(WeylAlgebraTest, binomial)
{
  // binomial(n, k) = n! / (k! * (n-k)!)
  // Results are ring elements in the coefficient ring K (QQ).

  // Base cases
  expectEqualLong(WeylAlgebraTestAccessor::binomial(W, 0, 0), 1);
  expectEqualLong(WeylAlgebraTestAccessor::binomial(W, 5, 0), 1);
  expectEqualLong(WeylAlgebraTestAccessor::binomial(W, 5, 1), 5);

  // Standard values
  expectEqualLong(WeylAlgebraTestAccessor::binomial(W, 5, 2), 10);
  expectEqualLong(WeylAlgebraTestAccessor::binomial(W, 5, 3), 10);
  expectEqualLong(WeylAlgebraTestAccessor::binomial(W, 5, 5), 1);
  expectEqualLong(WeylAlgebraTestAccessor::binomial(W, 6, 3), 20);
  expectEqualLong(WeylAlgebraTestAccessor::binomial(W, 10, 5), 252);

  // Larger values (beyond the cached binomtable)
  expectEqualLong(WeylAlgebraTestAccessor::binomial(W, 20, 10), 184756);
  expectEqualLong(WeylAlgebraTestAccessor::binomial(W, 30, 15), 155117520);
}

TEST_F(WeylAlgebraTest, multinomial)
{
  // multinomial(c, top, bottom) = c * product_i binomial(top[i], bottom[i])
  // where the product is over the _nderivatives derivative pairs.
  // Here _nderivatives = 2 (for Dx, Dy).

  ring_elem one = K->from_long(1);

  // All bottom entries zero: result should be c * 1 = c
  {
    int top[] = {5, 3};
    int bottom[] = {0, 0};
    expectEqualLong(WeylAlgebraTestAccessor::multinomial(W, one, top, bottom), 1);
  }

  // Single nonzero bottom entry: should give binomial(5,2) = 10
  {
    int top[] = {5, 3};
    int bottom[] = {2, 0};
    expectEqualLong(WeylAlgebraTestAccessor::multinomial(W, one, top, bottom), 10);
  }

  // Both entries nonzero: binomial(5,2) * binomial(3,1) = 10 * 3 = 30
  {
    int top[] = {5, 3};
    int bottom[] = {2, 1};
    expectEqualLong(WeylAlgebraTestAccessor::multinomial(W, one, top, bottom), 30);
  }

  // With a scalar coefficient: 7 * binomial(4,2) * binomial(6,3) = 7 * 6 * 20 = 840
  {
    ring_elem seven = K->from_long(7);
    int top[] = {4, 6};
    int bottom[] = {2, 3};
    expectEqualLong(WeylAlgebraTestAccessor::multinomial(W, seven, top, bottom), 840);
  }
}
