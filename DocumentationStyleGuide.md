# Documentation Style Guide

This guide sets the documentation standards for the refresh on `doc-updates`.
It is intentionally short and operational.

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

If an option materially changes behavior, document the option node too.

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

## Examples

- Prefer one minimal example and one slightly richer example over a long dump.
- Examples should be runnable when practical.
- If output is expensive, unstable, or externally dependent, say so explicitly.
- Do not leave an example block in place if it has become misleading.

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
- Keep acknowledgements and contributor lists off user landing pages unless they
  are actively maintained and clearly belong there.

## Verification Standard

Before merge, documentation changes should satisfy these expectations:

- the page was previewed in rendered form when practical
- links and cross-references were checked
- examples were rerun when the change affects them
- the PR states what was verified and what was not
