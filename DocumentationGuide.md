# Documentation Guide

This guide is for contributors working on the documentation refresh in
`aalmousa/M2`. Use it together with [DocumentationPlan.md](DocumentationPlan.md)
and [DocumentationStyleGuide.md](DocumentationStyleGuide.md).

The repo-local guides are aligned with these upstream documentation references:

- <https://github.com/Macaulay2/M2/wiki/Package-Writing-Style-Guide>
- <https://macaulay2.com/doc/Macaulay2/share/doc/Macaulay2/Macaulay2Doc/html/_writing_spdocumentation.html>

Use the upstream pages for the full package-writing and documentation syntax
details. Use this guide for the branch workflow, local preview, and review
expectations for the documentation refresh.

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

## Workflow

1. Claim or create an issue in `aalmousa/M2` and track it in the
   `M2 Documentation Refresh` project.
2. Branch from `doc-updates`.
3. Keep the PR focused on one issue or one child issue.
4. Open pull requests against `aalmousa/M2:doc-updates`, not `master`.
5. If the scope grows, split follow-up work into new issues instead of widening
   the PR.

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
