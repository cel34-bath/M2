# Documentation Style Guide

This guide sets the documentation standards for the refresh on `doc-updates`.
It is intentionally short and operational.

It is a repo-local companion to the upstream Macaulay2 documentation guidance:

- <https://github.com/Macaulay2/M2/wiki/Package-Writing-Style-Guide>
- <https://macaulay2.com/doc/Macaulay2/share/doc/Macaulay2/Macaulay2Doc/html/_writing_spdocumentation.html>

This file adopts the documentation-specific rules from those sources. Broader
package-coding and naming rules still live in the upstream wiki.

## Priorities

1. Optimize for a mathematically literate user trying to accomplish something.
2. Make the next step obvious.
3. Keep examples trustworthy.

## General Rules

- Write for the page's audience, not for someone already reading the source.
- Prefer direct present-tense statements over historical notes or speculation.
- Do not leave `TODO`, `FIXME`, `Section XX`, or references to missing follow-up
  tutorials in user-facing pages.
- Avoid stale course framing, version-era notes, or performance caveats unless
  they are still relevant.
- If a symbol or page is important enough to export, it should normally be
  documented rather than left behind `undocumented`.
- Use Unicode where appropriate, such as in authors' names or mathematically
  standard terminology.

## Page Types

### Function And Method Pages

When the doc surface supports it, include:

- `Headline`
- `Usage`
- `Inputs`
- `Outputs`
- a short explanation of behavior and context
- at least one example or a strong cross-reference
- `SeeAlso`

The `Headline` should be a brief phrase, not a complete sentence, and should
avoid referring to variables by name when possible.

If an option materially changes behavior, document the option node too.
For method functions, document the return type when possible so the
documentation generator can place the method in the right type-level views.
In `Outputs`, say not only the type but also what mathematical object or value
is returned. Use multiple output entries only when the function actually
returns a sequence with multiple components.

### Package Landing Pages

A package landing page should answer these questions quickly:

- What does the package do?
- What package needs to be loaded?
- Are there external prerequisites?
- Where should a new user start?
- Where are the main examples or tutorials?

### Tutorials

- State the goal of the tutorial early.
- Say what packages need to be loaded.
- Present examples in an order a reader can follow.
- Separate tutorial guidance from raw test material.
- If a tutorial assumes external software, say so near the top.

### Internal Or Generated Docs

- Say whether the page is hand-maintained or generated.
- Point readers toward the right source file or build context.
- Do not pretend an internal page is a user-facing landing page.

## Conventions From Built-In Documentation

- Use lowercase for titles and headlines unless a proper noun requires
  capitalization.
- Use `TO` to reference Macaulay2 functions, options, variables, packages, and
  related documentation nodes as hyperlinks.
- `Inputs`, `Outputs`, and `Consequences` entries should not end with periods.
- Prefer the existing documentation templates and page shapes already used in
  `PackageTemplate.m2`, `Macaulay2Doc`, and `SimpleDoc`.

## Examples

- Prefer one minimal example and one slightly richer example over a long dump.
- Examples should be runnable when practical.
- If output is expensive, unstable, or externally dependent, say so explicitly.
- Do not leave an example block in place if it has become misleading.
- Each exported data type, method, and function should have a documentation
  page, and each documentation page should normally include an example.
- Choose examples that illustrate usage clearly without consuming excessive CPU
  time or memory.
- Do not place multiple large example blocks back-to-back without explanatory
  text between them.
- Do not reload the package being documented inside example code.
- In `Usage` and `Outputs`, avoid assigning a single returned value to a
  variable unless that assignment is needed to explain a later step.

## Navigation And Cross-References

- Every new page should be reachable from at least one parent page.
- `SeeAlso`, `Subnodes`, and top-level navigation should point somewhere useful.
- Avoid orphan pages and commented-out navigation.
- Surface high-value guides from landing pages instead of burying them deep in
  the tree.

## Tone And Terminology

- Explain package-specific or Macaulay2-specific terms when they are not obvious
  from context.
- Prefer concrete nouns and verbs over vague phrases like “this stuff” or
  “various things”.
- Start sentences with English words, not identifiers or symbols.
- Use Macaulay2 identifiers as code references, not as English words in prose.
- Use lowercase common nouns like “list” or “hash table” unless you are naming
  the class `List` or `HashTable`.
- End prose sentences with periods or question marks, not with a colon used in
  place of a sentence.
- Make each sentence a real sentence with a subject and a verb.
- Keep acknowledgements and contributor lists off user landing pages unless they
  are actively maintained and clearly belong there.

## Verification Standard

Before merge, documentation changes should satisfy these expectations:

- the page was previewed in rendered form when practical
- links and cross-references were checked
- examples were rerun when the change affects them
- the PR states what was verified and what was not
