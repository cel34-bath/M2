# Documentation Style Guide

Use this guide for documentation work on `doc-updates`.

It follows the documentation-specific guidance in:

- <https://github.com/Macaulay2/M2/wiki/Package-Writing-Style-Guide>
- <https://macaulay2.com/doc/Macaulay2/share/doc/Macaulay2/Macaulay2Doc/html/_writing_spdocumentation.html>

For broader package-coding rules, use the upstream wiki.

## What Good Documentation Must Do

- Help a mathematically literate user do the next thing quickly.
- Make the next useful page, package, or example easy to find.
- Stay accurate for the current code.
- Keep examples small, clear, and trustworthy.

## Required Standards

- Do not leave `TODO`, `FIXME`, `Section XX`, or references to missing follow-up
  tutorials in user-facing pages.
- Avoid stale course framing, old version-era notes, and obsolete performance
  caveats unless they still matter.
- If a symbol is exported, it should normally be documented rather than left
  `undocumented`.
- Every new page should be reachable from at least one parent page.
- Preview the rendered page when practical, and check links and cross-references
  before merge.

## Function And Method Pages

When the doc surface supports it, include:

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
- Use `TO` for links to functions, options, variables, packages, and doc nodes.
- Do not end `Inputs`, `Outputs`, or `Consequences` entries with periods.
- In `Outputs`, say both the type and what mathematical object or value is
  returned.
- For method functions, document the return type when possible.
- If an option materially changes behavior, document the option node too.
- Prefer the existing page shapes already used in `PackageTemplate.m2`,
  `Macaulay2Doc`, and `SimpleDoc`.

## Package Landing Pages

A package landing page should answer these questions quickly:

- What does the package do?
- What package needs to be loaded?
- Are there external prerequisites?
- Where should a new user start?
- Where are the main examples or tutorials?

## Tutorials

- State the goal near the top.
- Say what packages need to be loaded.
- Present examples in an order a reader can follow.
- Keep explanatory text separate from raw test material.
- If external software or setup is required, say so early.

## Internal Or Generated Docs

- Say whether the page is hand-maintained or generated.
- Point readers to the right source file or build context.
- Do not present an internal page as a user-facing landing page.

## Writing Rules

- Write for the page's audience, not for someone already reading the source.
- Prefer direct present-tense statements.
- Explain package-specific or Macaulay2-specific terms when they are not
  obvious.
- Use Macaulay2 identifiers as code references, not as English words in prose.
- Start sentences with English words, not identifiers or symbols.
- Use lowercase common nouns like “list” or “hash table” unless you mean the
  class `List` or `HashTable`.
- Write real sentences with normal punctuation.
- Use Unicode where appropriate.
- Keep contributor lists off user landing pages unless they are actively
  maintained and clearly belong there.

## Examples

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

## Before Merge

- the page renders correctly, or `viewHelp` shows the expected result
- links, `SeeAlso`, `Subnodes`, and top-level navigation were checked
- examples were rerun when the change affects them, or the PR explains why not
- the PR says what was verified and what was not
