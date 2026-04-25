# Documentation Plan

This file coordinates the documentation refresh work currently landing on
`doc-updates`.

Use GitHub issues and a GitHub Project to track execution. Do not treat this
file as the day-to-day checklist for every edit. Its job is to define scope,
workflow, and the first backlog to turn into issues.

## Goals

1. Improve the accuracy of user-facing documentation.
2. Make documentation work easier to claim, review, and finish.
3. Standardize how documentation tasks are described and verified.
4. Keep pull requests small enough for mathematical and editorial review.

## Working Model

1. Create a GitHub Project named `M2 Documentation Refresh`.
2. Use columns `Backlog`, `Ready`, `In Progress`, `In Review`, and `Done`.
3. File one GitHub issue per documentation task.
4. Link each issue to the relevant paths, a clear owner, and a definition of
   done.
5. Land focused pull requests into `doc-updates`, not one large omnibus PR.
6. Close the issue only after review and any needed follow-up verification.

## Suggested Labels

- `documentation`: default label for documentation work.
- `docs-build`: install, build, packaging, or toolchain documentation.
- `docs-reference`: reference pages, generated docs, or API-style docs.
- `docs-package`: package-specific documentation.
- `docs-tutorial`: tutorials, examples, and teaching-oriented docs.
- `docs-editors`: editor integration and syntax-highlighting docs.
- `needs-math-review`: requires subject-matter review for correctness.
- `needs-example`: examples must be rerun or rewritten.
- `good first issue`: suitable for a new contributor.
- `blocked`: cannot proceed until another issue lands.

## Definition Of Done

A documentation issue is done when all of the following are true:

1. The affected files and audience are identified in the issue.
2. The updated text is accurate for the current code or workflow.
3. Examples, commands, or screenshots were rerun when practical, or the PR
   explicitly notes what could not be rerun.
4. Links and cross-references in the touched files were checked.
5. The PR description states how the change was verified.
6. The issue is linked to the PR and any follow-up work is split into new
   issues instead of hidden in review comments.

## Issue Size Guidance

- Small: one file or one tightly scoped topic; target one review.
- Medium: one subsystem or one package doc surface; may span several files.
- Large: an audit or rewrite that should be split into smaller child issues.

Default to small or medium issues. Large issues should usually be tracking
issues, not implementation issues.

## Review Checklist

When reviewing documentation PRs, check:

1. Is the text correct for the current version of the code?
2. Is the intended audience clear?
3. Do the examples still run, or is any uncertainty called out?
4. Are links, package names, branch names, and paths still current?
5. Is the PR small enough to review without hidden scope?

## Starter Backlog

The items below are intended to become GitHub issues. Each one is small enough
to assign to a person or pair, and together they cover the main documentation
surfaces already present in this repository.

### Coordination And Contributor Guidance

1. Audit top-level contribution guidance.
   Paths: `README.md`, `.github/pull_request_template.md`
   Done when: contributor-facing instructions are current, critical workflow
   notes live in the repo when possible, and stale references are removed or
   flagged.

2. Add a short documentation contributor guide.
   Paths: `DocumentationPlan.md`, new guide if needed
   Done when: contributors can tell where package docs, internal docs, and
   README-style docs live, and how to claim work.

3. Define documentation style conventions.
   Paths: new guide or repo-local section linked from `DocumentationPlan.md`
   Done when: reviewers have a shared standard for headings, code blocks, link
   style, example formatting, and tone.

4. Establish the documentation project board and label set on GitHub.
   Paths: GitHub Project and repo labels
   Done when: the board exists, labels are created, and at least the initial
   backlog issues are loaded.

### Build, Install, And Tooling Docs

5. Audit the main build overview.
   Paths: `M2/README.md`, `M2/BUILD/README.md`
   Done when: supported workflows, prerequisite expectations, and entry points
   are clear and non-duplicative.

6. Review container and packaging documentation.
   Paths: `M2/BUILD/docker/README.md`, `M2/BUILD/docker/*/README.md`,
   `M2/BUILD/rpm/README.md`
   Done when: the supported images and packaging flows are accurately described
   and obsolete instructions are called out.

7. Review editor integration documentation.
   Paths: `M2/Macaulay2/editors/README.md`,
   `M2/Macaulay2/editors/emacs/README.md`,
   `M2/Macaulay2/editors/vim/README_linux`,
   `M2/Macaulay2/editors/vim/README_macos`,
   `M2/Macaulay2/editors/prism/README.md`,
   `M2/Macaulay2/editors/pygments/README.md`
   Done when: installation and usage instructions match the current editor
   tooling and redundant text is reduced.

8. Document how to verify documentation changes locally.
   Paths: repo-local guide or existing README files
   Done when: contributors know what to run for doc-adjacent checks and how to
   report partial verification.

### Internal And Generated Documentation

9. Audit the internal documentation landing page.
   Paths: `M2/Macaulay2/docs/index.rst`, `M2/Macaulay2/docs/modules.rst`
   Done when: the landing page accurately describes what is generated, what is
   hand-maintained, and where readers should start.

10. Review Sphinx and Doxygen build assumptions.
    Paths: `M2/Macaulay2/docs/CMakeLists.txt`, `M2/Macaulay2/docs/conf.py`,
    `M2/Macaulay2/docs/Doxyfile.in`
    Done when: build expectations are documented and mismatches between config
    and prose are recorded or fixed.

11. Inventory major gaps in internal docs coverage.
    Paths: `M2/Macaulay2/docs/`, generated output as needed
    Done when: missing modules, weak landing pages, and unclear navigation are
    captured as follow-up issues instead of remaining implicit.

### Package Documentation

12. Audit the package documentation entry point.
    Paths: `M2/Macaulay2/packages/README`
    Done when: readers can understand how package docs are organized and how to
    discover package-specific documentation.

13. Redesign the main Macaulay2 documentation landing page.
    Paths: `M2/Macaulay2/packages/Macaulay2Doc/ov_top.m2`
    Done when: the landing page is organized for mathematicians and other
    users trying to find examples, tutorials, package docs, and topic-based
    entry points, and the rendered html has been previewed locally.

14. Surface buried high-value guides from the main documentation landing page.
    Paths: `M2/Macaulay2/packages/Macaulay2Doc/ov_top.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/ov_debugging.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/ov_language.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/ov_packages.m2`,
    `M2/Macaulay2/packages/BeginningMacaulay2.m2`
    Done when: the homepage or nearby top-level navigation makes it easier to
    find `BeginningMacaulay2`, `debugging`, `the debugger`, `error handling`,
    and practical package-usage guidance, and any new links have been checked
    in rendered html.

15. Remove or relocate the stale contributor list on the main documentation landing page.
    Paths: `M2/Macaulay2/packages/Macaulay2Doc/ov_top.m2`,
    related author or acknowledgement pages as needed
    Done when: the hand-maintained documentation-contributor list no longer
    clutters the homepage, and any remaining attribution is either accurate and
    maintainable or moved to a more appropriate page.

16. Review `NumericalAlgebraicGeometry` documentation.
    Paths: `M2/Macaulay2/packages/NumericalAlgebraicGeometry/README`,
    `M2/Macaulay2/packages/NumericalAlgebraicGeometry/TST/README.txt`
    Done when: overview, prerequisites, and example/test references are current.

17. Review `NumericalSchubertCalculus` documentation.
    Paths: `M2/Macaulay2/packages/NumericalSchubertCalculus/README` and related
    README files under that package
    Done when: the overview and supporting README files still reflect the
    current package layout and usage.

18. Review `OldChainComplexes` documentation structure.
    Paths: `M2/Macaulay2/packages/OldChainComplexes/docs/*.m2`
    Done when: the landing points, narrative flow, and page naming are coherent
    for a newcomer to the package docs.

19. Review `MergeTeX` documentation.
    Paths: `M2/Macaulay2/packages/MergeTeX/README.md`
    Done when: setup and usage notes are accurate and concise.

20. Review `TropicalToric` documentation.
    Paths: `M2/Macaulay2/packages/TropicalToric/README.md`
    Done when: the README accurately describes scope, entry points, and any
    external assumptions.

21. Review `MonodromySolver` example documentation.
    Paths: `M2/Macaulay2/packages/MonodromySolver/paper-examples/README.md`
    Done when: the example documentation clearly states what is reproducible and
    what environment assumptions exist.

22. Identify packages missing an overview or landing page.
    Paths: `M2/Macaulay2/packages/`
    Done when: missing-package-doc issues are filed as discrete follow-ups
    instead of one vague umbrella task.

Audit summary from the first static distributed-package scan on `2026-04-25`:
the 294 distributed packages showed no broken relative links in their
README/Markdown files, 13 packages had almost no visible doc entry point, and
131 packages still had doc-surface `TODO` or `undocumented` markers that need
triage.

23. Expand landing pages and entry-point docs for low-surface distributed packages.
    Paths: `M2/Macaulay2/packages/Browse.m2`,
    `M2/Macaulay2/packages/Benchmark.m2`,
    `M2/Macaulay2/packages/Dmodules.m2`,
    `M2/Macaulay2/packages/Schubert2.m2`,
    `M2/Macaulay2/packages/Schubert2/doc.m2`,
    `M2/Macaulay2/packages/RationalPoints.m2`,
    `M2/Macaulay2/packages/BeginningMacaulay2.m2`,
    `M2/Macaulay2/packages/Serialization.m2`,
    `M2/Macaulay2/packages/Units.m2`,
    `M2/Macaulay2/packages/RandomCurves.m2`,
    `M2/Macaulay2/packages/VectorGraphics.m2`,
    `M2/Macaulay2/packages/WhitneyStratifications.m2`,
    `M2/Macaulay2/packages/Msolve.m2`
    Done when: each package has a visible overview or landing page, and the
    user-facing packages in this group have at least one clear example or
    tutorial path.

24. Finish algebra and geometry package docs that still contain explicit TODO or undocumented placeholders.
    Paths: `M2/Macaulay2/packages/LocalRings.m2`,
    `M2/Macaulay2/packages/LocalRings/doc.m2`,
    `M2/Macaulay2/packages/LocalRings/examples.m2`,
    `M2/Macaulay2/packages/Saturation.m2`,
    `M2/Macaulay2/packages/Saturation/doc.m2`,
    `M2/Macaulay2/packages/Saturation/quotient-doc.m2`,
    `M2/Macaulay2/packages/Saturation/saturate-doc.m2`,
    `M2/Macaulay2/packages/MinimalPrimes.m2`,
    `M2/Macaulay2/packages/MinimalPrimes/doc.m2`,
    `M2/Macaulay2/packages/PrimaryDecomposition/doc.m2`,
    `M2/Macaulay2/packages/PrimaryDecomposition/examples.m2`,
    `M2/Macaulay2/packages/IntegralClosure.m2`,
    `M2/Macaulay2/packages/Triangulations.m2`,
    `M2/Macaulay2/packages/Truncations.m2`,
    `M2/Macaulay2/packages/Truncations/docs.m2`,
    `M2/Macaulay2/packages/Varieties/*.m2`
    Done when: the explicit `TODO` and `undocumented` placeholders in these
    package doc surfaces are either resolved or split into smaller tracked
    issues, and navigation problems such as the orphan `quotient` node in
    `Saturation/quotient-doc.m2` are fixed or documented.

25. Finish interface and application package docs that still contain explicit TODO or undocumented placeholders.
    Paths: `M2/Macaulay2/packages/SCSCP/docs.m2`,
    `M2/Macaulay2/packages/SCSCP/examples.m2`,
    `M2/Macaulay2/packages/Python/doc.m2`,
    `M2/Macaulay2/packages/Python/doc/tutorials.m2`,
    `M2/Macaulay2/packages/ReactionNetworks.m2`,
    `M2/Macaulay2/packages/ReactionNetworks/Readme.md`,
    `M2/Macaulay2/packages/Cremona/documentation.m2`,
    `M2/Macaulay2/packages/NumericalAlgebraicGeometry/doc.m2`,
    `M2/Macaulay2/packages/NumericalSchubertCalculus/README`,
    `M2/Macaulay2/packages/Bertini/doc.m2`,
    `M2/Macaulay2/packages/BernsteinSato/DOC/*.m2`,
    `M2/Macaulay2/packages/VectorGraphics.m2`,
    `M2/Macaulay2/packages/WhitneyStratifications.m2`,
    `M2/Macaulay2/packages/Msolve.m2`
    Done when: undocumented exports or explicit `TODO` notes in these package
    docs are reduced, external prerequisites are explained where needed, and
    the package docs give a clear starting point for first-time users.

26. Curate package example and tutorial surfaces that are present but unfinished or hard to navigate.
    Paths: `M2/Macaulay2/packages/LocalRings/examples.m2`,
    `M2/Macaulay2/packages/PrimaryDecomposition/examples.m2`,
    `M2/Macaulay2/packages/BernsteinSato/DOC/*.m2`,
    `M2/Macaulay2/packages/Bertini/TST/*.tst.m2`,
    `M2/Macaulay2/packages/NumericalAlgebraicGeometry/README`,
    `M2/Macaulay2/packages/NumericalAlgebraicGeometry/TST/README.txt`,
    `M2/Macaulay2/packages/Python/doc/tutorials.m2`,
    `M2/Macaulay2/packages/ReactionNetworks/example*.m2`,
    `M2/Macaulay2/packages/SCSCP/examples.m2`,
    `M2/Macaulay2/packages/OldChainComplexes/docs/*.m2`
    Done when: the example entry points in this set are labeled clearly as
    tutorials, demos, or tests, obviously unfinished sections are completed or
    trimmed, and readers can tell which files are meant to be read first.

27. Record the first full distributed-package documentation audit and keep it split into follow-up waves.
    Paths: `M2/Macaulay2/packages/=distributed-packages`,
    `DocumentationPlan.md`
    Done when: the audit results remain summarized in the plan with counts, and
    the high-priority packages from that scan are represented by explicit
    follow-up items instead of one umbrella note.

### Tutorials, Examples, And Teaching Material

28. Review `BeginningMacaulay2` as a first-user tutorial.
    Paths: `M2/Macaulay2/packages/BeginningMacaulay2.m2`,
    `M2/Macaulay2/packages/BeginningMacaulay2/tutorial`
    Done when: the tutorial still works as a modern first stop for new users,
    obvious stale workflow assumptions are corrected, and its role in the main
    documentation navigation is clear.

29. Refresh the commutative algebra tutorial set and its dated course framing.
    Paths: `M2/Macaulay2/packages/Macaulay2Doc/ov_examples.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/tu_elementary.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/loads.m2`
    Done when: the `Fall 2005` / `Math 634` framing is either removed or
    intentionally contextualized, tutorial titles and descriptions are clearer
    for current users, and the exposed examples still make sense as entry
    points.

30. Refresh `Tutorial: Modules in Macaulay2`.
    Paths: `M2/Macaulay2/packages/Macaulay2Doc/tu_modules.m2`
    Done when: stale references such as `Section XX` and speculative
    future-behavior notes are removed or rewritten, and the tutorial still
    reads coherently for users learning modules from examples.

31. Refresh `Tutorial: Divisors`.
    Paths: `M2/Macaulay2/packages/Macaulay2Doc/tu_divisors.m2`
    Done when: obsolete forward references such as the missing “next divisor
    tutorial” and historical performance notes are removed or replaced, and the
    stated scope matches current functionality.

32. Audit the advanced geometry tutorials for clarity and dated assumptions.
    Paths: `M2/Macaulay2/packages/Macaulay2Doc/tu_canEmbed.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/tu_Fano.m2`
    Done when: terminology, caveats, and example framing have been reviewed for
    current readers, and any stale notes are split into follow-up issues or
    fixed.

33. Audit the Computations Book landing page.
    Paths: `M2/Macaulay2/tests/ComputationsBook/README`
    Done when: the top-level description, navigation, and reader expectations
    are current.

34. Review chapter-level Computations Book README files for stale terminology.
    Paths: `M2/Macaulay2/tests/ComputationsBook/*/README`
    Done when: terminology, chapter descriptions, and references are consistent
    across the chapter folders.

35. Verify a representative sample of tutorial examples.
    Paths: selected files under `M2/Macaulay2/tests/ComputationsBook/`
    Done when: issues are filed for broken, outdated, or confusing examples and
    the verified sample is documented in the issue.

### Core Language And Reference Documentation

36. Audit core overview links, placeholders, and navigation gaps.
    Paths: `M2/Macaulay2/packages/Macaulay2Doc/ov_top.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/ov_getting_started.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/ov_documentation.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/ov_modules.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/ov_ringmaps.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/ov_groebner_bases.m2`
    Done when: top-level `TO` and `SeeAlso` targets have been spot-checked,
    placeholder or commented-out navigation such as missing troubleshooting or
    contributor entry points is either resolved or split into tracked follow-up
    work, and any broken or stale links found in these core overview pages are
    fixed or recorded.

37. Triage the core function docs that are still explicitly marked `status: TODO`.
    Paths: `M2/Macaulay2/packages/Macaulay2Doc/functions/*-doc.m2`
    Done when: the current `status: TODO` set has been reviewed, the most
    important exported functions are grouped into actionable follow-up issues,
    and the backlog distinguishes between missing coverage, thin coverage, and
    pages that mostly need examples.

38. Document exported text, rendering, and serialization methods that are still marked undocumented.
    Paths: `M2/Macaulay2/packages/Macaulay2Doc/functions/expression-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/hypertext-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/html-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/mathML-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/tex-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/texMath-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/toString-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/toExternalString-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/format-doc.m2`
    Done when: exported methods in this cluster no longer rely on generic
    `undocumented` placeholders, and the docs explain what these routines are
    for with at least one concrete example or cross-reference per page.

39. Document exported filesystem, REPL, and utility functions that still have TODO or undocumented coverage.
    Paths: `M2/Macaulay2/packages/Macaulay2Doc/functions/isDirectory-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/isRegularFile-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/readDirectory-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/readlink-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/realpath-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/removeDirectory-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/findSynonyms-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/isGlobalSymbol-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/use-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/net-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/peek-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/index-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/clean-doc.m2`
    Done when: the exported utilities in this group have enough explanation and
    examples to be discoverable from the docs without reading source, and
    obvious TODO markers or undocumented method placeholders are removed.

40. Document exported algebra, Gröbner, and linear-algebra functions that still have TODO or undocumented coverage.
    Paths: `M2/Macaulay2/packages/Macaulay2Doc/functions/map-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/kernel-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/gb-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/gbRemove-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/forceGB-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/tensor-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/wedgeProduct-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/rank-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/SVD-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/eigenvalues-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/eigenvectors-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/mingens-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/degrees-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/someTerms-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/monomials-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/GF-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/pseudoRemainder-doc.m2`
    Done when: this cluster of exported mathematical functions has been triaged
    into concrete documentation fixes with examples where needed, and clearly
    missing or placeholder pages are no longer hidden behind `status: TODO`.

41. Expand thin explanations and examples in the core getting-started, debugging, and module docs.
    Paths: `M2/Macaulay2/packages/Macaulay2Doc/ov_getting_started.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/ov_debugging.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/ov_modules.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/generators-doc.m2`,
    `M2/Macaulay2/packages/Macaulay2Doc/functions/preimage-doc.m2`
    Done when: the docs add the missing explanatory context called out in the
    source comments, stale “needs upgrades” notes are resolved, and example
    gaps such as the missing `preimage` example or the unsalvaged
    `generators` examples are addressed.

### Repository-Wide Cleanup

42. Run a broken-link sweep across Markdown and README files.
    Paths: repo-wide Markdown and README files, excluding third-party submodules
    Done when: broken internal links, moved files, and stale external links are
    fixed or captured in follow-up issues.

43. Standardize branch-name and workflow references in docs.
    Paths: repo-wide documentation files
    Done when: references to outdated branch names or outdated GitHub workflows
    are corrected where appropriate.

44. Identify documentation that belongs in the repo instead of only on the wiki.
    Paths: top-level docs and places that link heavily to the wiki
    Done when: critical contributor guidance has a repo-local home or a tracked
    follow-up issue.

45. Create a `good-first-issue` wave for new documentation contributors.
    Paths: GitHub issues and labels
    Done when: at least five narrowly scoped doc issues are labeled and ready to
    assign.

## Notes For Leads

1. Keep the integration branch stable enough that people can branch from it
   without inheriting unrelated work.
2. Prefer issues with exact paths over issues framed as "improve docs".
3. If a task changes both mathematical content and prose, ask for math review
   explicitly instead of assuming an editorial review is enough.
