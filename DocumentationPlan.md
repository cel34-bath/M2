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

- `docs`: default label for documentation work.
- `docs-build`: install, build, packaging, or toolchain documentation.
- `docs-reference`: reference pages, generated docs, or API-style docs.
- `docs-package`: package-specific documentation.
- `docs-tutorial`: tutorials, examples, and teaching-oriented docs.
- `docs-editors`: editor integration and syntax-highlighting docs.
- `needs-math-review`: requires subject-matter review for correctness.
- `needs-example`: examples must be rerun or rewritten.
- `good-first-issue`: suitable for a new contributor.
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

13. Review `NumericalAlgebraicGeometry` documentation.
    Paths: `M2/Macaulay2/packages/NumericalAlgebraicGeometry/README`,
    `M2/Macaulay2/packages/NumericalAlgebraicGeometry/TST/README.txt`
    Done when: overview, prerequisites, and example/test references are current.

14. Review `NumericalSchubertCalculus` documentation.
    Paths: `M2/Macaulay2/packages/NumericalSchubertCalculus/README` and related
    README files under that package
    Done when: the overview and supporting README files still reflect the
    current package layout and usage.

15. Review `OldChainComplexes` documentation structure.
    Paths: `M2/Macaulay2/packages/OldChainComplexes/docs/*.m2`
    Done when: the landing points, narrative flow, and page naming are coherent
    for a newcomer to the package docs.

16. Review `MergeTeX` documentation.
    Paths: `M2/Macaulay2/packages/MergeTeX/README.md`
    Done when: setup and usage notes are accurate and concise.

17. Review `TropicalToric` documentation.
    Paths: `M2/Macaulay2/packages/TropicalToric/README.md`
    Done when: the README accurately describes scope, entry points, and any
    external assumptions.

18. Review `MonodromySolver` example documentation.
    Paths: `M2/Macaulay2/packages/MonodromySolver/paper-examples/README.md`
    Done when: the example documentation clearly states what is reproducible and
    what environment assumptions exist.

19. Identify packages missing an overview or landing page.
    Paths: `M2/Macaulay2/packages/`
    Done when: missing-package-doc issues are filed as discrete follow-ups
    instead of one vague umbrella task.

### Tutorials, Examples, And Teaching Material

20. Audit the Computations Book landing page.
    Paths: `M2/Macaulay2/tests/ComputationsBook/README`
    Done when: the top-level description, navigation, and reader expectations
    are current.

21. Review chapter-level Computations Book README files for stale terminology.
    Paths: `M2/Macaulay2/tests/ComputationsBook/*/README`
    Done when: terminology, chapter descriptions, and references are consistent
    across the chapter folders.

22. Verify a representative sample of tutorial examples.
    Paths: selected files under `M2/Macaulay2/tests/ComputationsBook/`
    Done when: issues are filed for broken, outdated, or confusing examples and
    the verified sample is documented in the issue.

### Repository-Wide Cleanup

23. Run a broken-link sweep across Markdown and README files.
    Paths: repo-wide Markdown and README files, excluding third-party submodules
    Done when: broken internal links, moved files, and stale external links are
    fixed or captured in follow-up issues.

24. Standardize branch-name and workflow references in docs.
    Paths: repo-wide documentation files
    Done when: references to outdated branch names or outdated GitHub workflows
    are corrected where appropriate.

25. Identify documentation that belongs in the repo instead of only on the wiki.
    Paths: top-level docs and places that link heavily to the wiki
    Done when: critical contributor guidance has a repo-local home or a tracked
    follow-up issue.

26. Create a `good-first-issue` wave for new documentation contributors.
    Paths: GitHub issues and labels
    Done when: at least five narrowly scoped doc issues are labeled and ready to
    assign.

## Notes For Leads

1. Keep the integration branch stable enough that people can branch from it
   without inheriting unrelated work.
2. Prefer issues with exact paths over issues framed as "improve docs".
3. If a task changes both mathematical content and prose, ask for math review
   explicitly instead of assuming an editorial review is enough.
