# Documentation Guide

This guide is for contributors working on the documentation refresh in
`aalmousa/M2`. Use it together with [DocumentationPlan.md](DocumentationPlan.md).

The repo-local guides are aligned with these upstream documentation references:

- <https://github.com/Macaulay2/M2/wiki/Package-Writing-Style-Guide>
- <https://macaulay2.com/doc/Macaulay2/share/doc/Macaulay2/Macaulay2Doc/html/_writing_spdocumentation.html>

Use the upstream pages for the full package-writing and documentation syntax
details. Use this guide for the branch workflow, local preview, and review
expectations for the documentation refresh, along with the repo-local
documentation standards that reviewers should enforce.

## Scope

The main documentation surfaces in this repository are:

- Core and user-facing docs: `M2/Macaulay2/packages/Macaulay2Doc/`
- Package docs: `M2/Macaulay2/packages/<Package>/` and package `.m2` files
- Internal docs: `M2/Macaulay2/docs/`
- Repo-level docs: `README.md`, `M2/BUILD/`, `M2/Macaulay2/editors/`, and
  related README files

Edit source documentation, not generated html.

Macaulay2 documentation is written in one of two supported forms:

- `document(List)` using the list-based hypertext format
- `doc(String)` using the string-based `SimpleDoc` format

Documentation entries belong to a package and should occur after that package's
`beginDocumentation()` section.

## What Good Documentation Must Do

- Help a mathematically literate user do the next thing quickly.
- Make the next useful page, package, or example easy to find.
- Stay accurate for the current code.
- Keep examples small, clear, and trustworthy.

## Workflow

1. Claim or create an issue in `aalmousa/M2` and track it in the
   `M2 Documentation Refresh` project.
2. Branch from `doc-updates`.
3. Keep the PR focused on one issue or one child issue.
4. Open pull requests against `aalmousa/M2:doc-updates`, not `master`.
5. If the scope grows, split follow-up work into new issues instead of widening
   the PR.

## Documentation Standards

### Required Standards

- Do not leave `TODO`, `FIXME`, `Section XX`, or references to missing
  follow-up tutorials in user-facing pages.
- Avoid stale course framing, old version-era notes, and obsolete performance
  caveats unless they still matter.
- If a symbol is exported, it should normally be documented rather than left
  `undocumented`.
- Every new page should be reachable from at least one parent page.
- Preview the rendered page when practical, and check links and
  cross-references before merge.

### Function And Method Pages

When the documentation surface supports it, include:

- `Headline`
- `Usage`
- `Inputs`
- `Outputs`
- a short explanation of behavior
- at least one example or a strong cross-reference
- `SeeAlso`

Use these conventions:

- Keep titles and headlines lowercase unless a proper noun requires capitals.
- Make the `Headline` a short phrase, not a full sentence.
- Use `TO` for links to functions, options, variables, packages, and doc
  nodes.
- Do not end `Inputs`, `Outputs`, or `Consequences` entries with periods.
- In `Outputs`, say both the type and what mathematical object or value is
  returned.
- For method functions, document the return type when possible.
- If an option materially changes behavior, document the option node too.
- Prefer the page shapes already used in `PackageTemplate.m2`, `Macaulay2Doc`,
  and `SimpleDoc`.

### Package Landing Pages

A package landing page should answer these questions quickly:

- What does the package do?
- What package needs to be loaded?
- Are there external prerequisites?
- Where should a new user start?
- Where are the main examples or tutorials?

### Tutorials

- State the goal near the top.
- Say what packages need to be loaded.
- Present examples in an order a reader can follow.
- Keep explanatory text separate from raw test material.
- If external software or setup is required, say so early.

### Internal Or Generated Docs

- Say whether the page is hand-maintained or generated.
- Point readers to the right source file or build context.
- Do not present an internal page as a user-facing landing page.

### Writing Rules

- Write for the page's audience, not for someone already reading the source.
- Prefer direct present-tense statements.
- Explain package-specific or Macaulay2-specific terms when they are not
  obvious.
- Use Macaulay2 identifiers as code references, not as English words in prose.
- Start sentences with English words, not identifiers or symbols.
- Use lowercase common nouns like `list` or `hash table` unless you mean the
  class `List` or `HashTable`.
- Write real sentences with normal punctuation.
- Use Unicode where appropriate.
- Keep contributor lists off user landing pages unless they are actively
  maintained and clearly belong there.

### Examples

- Each documented exported data type, method, and function should normally have
  at least one example.
- Prefer one minimal example and one slightly richer example over a long dump.
- Choose examples that show real usage without consuming excessive CPU time or
  memory.
- If output is expensive, unstable, or externally dependent, say so explicitly.
- Do not place large example blocks back-to-back without explanation.
- Do not reload the package being documented inside examples.
- In `Usage` and `Outputs`, avoid assigning a single returned value to a
  variable unless that assignment is needed to explain a later step.

## Before Editing

- Identify the audience first: end user, package user, contributor, or internal
  maintainer.
- Find the source page that actually generates the docs you want to change.
- Prefer improving an existing landing page or tutorial path over creating a
  second entry point for the same material.
- Check whether the issue should carry `needs-math-review` or `needs-example`.

## Local Preview

Assume `$M2BUILDDIR` points to an existing build tree. For most documentation
changes, rebuild only the package you touched.

For prose, navigation, or landing-page edits that do not change example code:

```sh
make -C "$M2BUILDDIR/Macaulay2/packages" \
  PACKAGES=Macaulay2Doc \
  RemakePackages=false \
  RemakeAllDocumentation=false \
  CheckDocumentation=false \
  IARGS='RunExamples => false'
```

Replace `Macaulay2Doc` with the package you edited. The regenerated html usually
appears under:

```text
$M2BUILDDIR/usr-dist/common/share/doc/Macaulay2/<PackageName>/html/
```

If you changed examples or expected output, use the normal package rebuild:

```sh
make -C "$M2BUILDDIR/Macaulay2/packages" \
  PACKAGES=YourPackage \
  RemakePackages=false \
  RemakeAllDocumentation=false
```

For package docs, also use `viewHelp` or `installPackage` when that is the
quickest way to confirm the rendered result.

For a normal documentation-writing cycle, the built-in documentation recommends:

1. edit the documentation source
2. run `installPackage("YourPackage")`
3. review the result with `viewHelp`

Reserve the expensive flags for final verification:

- `RunExamples => false`: fastest preview for text-only edits
- default example behavior: normal path for example changes
- `RerunExamples=true`: rerun all examples for one package
- `RemakeAllDocumentation=true`: full package-doc rebuild
- `CheckDocumentation=true`: stronger completeness check

If there is a pre-existing build failure, say exactly what page or command you
were still able to verify.

## Verification

Every documentation PR should say what was checked locally. Use this checklist:

- the affected page renders or `viewHelp` shows the expected change
- links, `SeeAlso`, `Subnodes`, and top-level navigation were checked
- examples were rerun when practical, or the PR says why they were not
- any external prerequisite or setup instructions were checked against current
  reality

Before merge, also confirm:

- the PR says what was verified and what was not
- the change matches the current audience and page type
- any unresolved uncertainty about examples or outputs is stated plainly

## Labels And Review

Use the repo labels to keep work triageable:

- `documentation`: default label for documentation work
- `docs-build`, `docs-reference`, `docs-package`, `docs-tutorial`,
  `docs-editors`: documentation area labels
- `needs-math-review`: use when correctness depends on mathematical review
- `needs-example`: use when examples or outputs should be rerun
- `blocked`: use when another issue must land first

## Definition Of Done

A documentation change is ready when:

1. The audience and affected files are clear.
2. The text is accurate for the current code or workflow.
3. Links and cross-references were checked.
4. Examples were rerun when practical, or the limitation is stated plainly.
5. The PR explains verification and links the relevant issue.
