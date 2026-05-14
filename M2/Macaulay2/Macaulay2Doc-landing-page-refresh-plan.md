# Macaulay2Doc Landing Page Refresh Plan

## Summary

Rework the `Macaulay2Doc` landing page from a mostly subject-first table of contents into four audience-first hubs:

1. Getting Started
2. For the Working Mathematician
3. For Contributors
4. For Advanced Users

These sections should act as curated entry points into the existing documentation, not as strict partitions of the entire docs tree. Existing reference and tutorial nodes should remain reusable, and a given node may appear in more than one hub when that makes the navigation clearer.

The main goal is to add an audience layer above the current overview and reference material, rather than rewriting all deep reference pages at once.

## Current Structure

The current top-level landing page is defined in `packages/Macaulay2Doc/ov_top.m2`.

The current main sections are:

- Getting Started
- Reference Manual
- Mathematical Objects
- Mathematical Tutorials
- Mathematical Computations
- Appendix

Relevant existing overview sources already include:

- `ov_getting_started.m2`
- `ov_first_session.m2`
- `ov_language.m2`
- `ov_packages.m2`
- `ov_documentation.m2`
- `ov_developers.m2`
- `ov_rings.m2`
- `ov_ideals.m2`
- `ov_matrices.m2`
- `ov_modules.m2`
- `ov_ringmaps.m2`
- `ov_lists.m2`
- `ov_hashtables.m2`
- `ov_types.m2`
- `ov_methods.m2`
- `ov_debugging.m2`
- `ov_system.m2`
- `ov_threads.m2`

The load order is controlled by `packages/Macaulay2Doc/loads.m2`, so any structural refresh should be reflected there as well.

## Audience-Hub Architecture

### 1. Getting Started

This section should answer:

> I installed Macaulay2. How do I begin, how do I interact with it, and how do I get unstuck?

Use these existing nodes directly:

- `setting up Macaulay2`
- `a first Macaulay2 session`
- `reading the documentation`
- `getting help or reporting bugs`
- `using Macaulay2 with Emacs`
- `using Macaulay2 in a terminal`
- `invoking the Macaulay2 program`

Add these new overview nodes:

- `Getting Started with Macaulay2`
  - A short front-door guide that links to installation, first session, editors, help, and reading the docs.
- `First mathematical workflow in Macaulay2`
  - A short path showing how to define a ring, build an ideal, compute something, inspect the output, and look up more help.
- `How to choose a data type`
  - A practical guide for common user choices such as `List` vs `Sequence` vs `MutableList`, `HashTable` vs `MutableHashTable`, `Set`, and matrices vs mutable matrices.

This should be the only section that is fully beginner-safe.

### 2. For the Working Mathematician

This section should answer:

> I want to do mathematics in Macaulay2. Where are the main objects, computations, tutorials, and packages?

Use these existing nodes:

- `rings`
- `ideals`
- `matrices`
- `modules`
- `morphisms`
- `chain complexes`
- `varieties and sheaves`
- `commutative algebra`
- `homological algebra`
- `algebraic geometry`
- `combinatorics`
- `analytic functions`
- `packages provided with Macaulay2`

Use these current tutorial nodes:

- `A first course in commutative algebra`
- `Tutorial: Modules in Macaulay2`
- `Tutorial: Elementary uses of Gröbner bases`
- `Tutorial: Canonical Embeddings of Plane Curves and Gonality`
- `Tutorial: Fano varieties`
- `Tutorial: Divisors`

Add these new overview nodes:

- `Mathematics in Macaulay2`
  - The main hub for mathematical workflows.
- `Core mathematical objects`
  - A guide explaining the relationship between rings, ideals, matrices, modules, maps, and complexes.
- `Finding the right package`
  - A package-discovery hub pointing into `packages provided with Macaulay2`.

This section should replace the current split between `Mathematical Objects`, `Mathematical Tutorials`, and `Mathematical Computations` on the landing page.

### 3. For Contributors

This section should answer:

> How do I add or improve things in Macaulay2?

Use these existing nodes:

- `creating a package`
- `packages`
- `writing documentation`
- `SimpleDoc :: SimpleDoc`
- `installPackage`
- `check Package`
- `debug Package`
- `The authors of Macaulay2 packages`
- `Core`
- `the interpreter of Macaulay2`
- `the engine of Macaulay2`
- `how Macaulay2 finds its files`

Add these new overview nodes:

- `Contributing to Macaulay2`
  - The main contributor hub.
- `Contributing a package`
  - A package-author path covering structure, exports, docs, tests, install/check, and pull requests.
- `Contributing documentation`
  - A docs-author path covering hypertext/simpledoc, `installPackage`, review cycle, and style conventions.
- `Contributing to the core system`
  - An orientation node for core, interpreter, engine, build, and runtime layout.
- `Documentation refresh project`
  - Optional tracker-style node if the docs refresh effort should be visible from the documentation itself.

This section should make three contributor tracks explicit:

- package contributors
- documentation contributors
- core contributors

### 4. For Advanced Users

This section should answer:

> I already use Macaulay2. How do I understand the language, types, methods, debugging, system behavior, and performance-oriented features?

Use these existing nodes:

- `The Macaulay2 language`
- `basic data types`
- `strings and nets`
- `lists and sequences`
- `hash tables`
- `what a class is`
- `installing methods`
- `inheritance`
- `making new classes`
- `making a new method function`
- `debugging`
- `the debugger`
- `parallel programming with threads and tasks`
- `system facilities`
- `how Macaulay2 finds its files`

Add these new overview nodes:

- `Advanced use of Macaulay2`
  - The main hub for language internals and power-user workflows.
- `Data types and mutability`
  - A bridge from beginner-facing type guidance into deeper type documentation.
- `Methods, dispatch, and classes`
  - A guide into `what a class is`, method installation, and inheritance.
- `Debugging and introspection`
  - A guide into debugging, backtraces, and package debugging.
- `System layout and runtime behavior`
  - A guide into startup, file layout, package loading, and the application directory.
- `Parallelism and performance`
  - A guide into threads, tasks, and engine parallelism.

This section should replace the current experience of burying language and power-user material under `Reference Manual`.

## Proposed New Nodes

The first wave of new high-value overview nodes should be:

- `Getting Started with Macaulay2`
- `First mathematical workflow in Macaulay2`
- `How to choose a data type`
- `Mathematics in Macaulay2`
- `Core mathematical objects`
- `Finding the right package`
- `Contributing to Macaulay2`
- `Contributing a package`
- `Contributing documentation`
- `Contributing to the core system`
- `Advanced use of Macaulay2`
- `Data types and mutability`
- `Methods, dispatch, and classes`
- `Debugging and introspection`
- `System layout and runtime behavior`
- `Parallelism and performance`

The highest-priority new node should be `How to choose a data type`, because it fills a real navigation gap for both beginners and advanced users.

## Proposed Source Tree

To support the new audience layer, reorganize the `packages/Macaulay2Doc/` overview sources around hubs and guides.

Recommended layout:

```text
packages/Macaulay2Doc/
  landing/
    home.m2
  audience/
    getting_started.m2
    working_mathematician.m2
    contributors.m2
    advanced_users.m2
  guides/
    guide_first_workflow.m2
    guide_choose_data_type.m2
    guide_core_objects.m2
    guide_find_package.m2
    guide_contributing_package.m2
    guide_contributing_docs.m2
    guide_contributing_core.m2
    guide_methods_dispatch.m2
    guide_debugging_introspection.m2
    guide_system_runtime.m2
    guide_parallelism_performance.m2
  subjects/
    ov_rings.m2
    ov_ideals.m2
    ov_matrices.m2
    ov_modules.m2
    ov_ringmaps.m2
    ov_analytic_functions.m2
    ov_groebner_bases.m2
    ...
  language/
    ov_language.m2
    ov_lists.m2
    ov_hashtables.m2
    ov_types.m2
    ov_methods.m2
    ov_debugging.m2
    ov_system.m2
    ov_threads.m2
  contributors/
    ov_packages.m2
    ov_documentation.m2
    ov_developers.m2
  tutorials/
    tu_modules.m2
    tu_elementary.m2
    tu_canEmbed.m2
    tu_divisors.m2
    tu_Fano.m2
    ...
```

This is a target structure, not a requirement for a single PR. The initial refresh can create the audience and guide layers first, then move files incrementally.

## Implementation Notes

### Landing Page

- Replace the current monolithic top-page structure in `ov_top.m2` with an audience-first landing page.
- The landing page should be short and scannable.
- Each section should include:
  - a one-sentence audience description
  - a small number of high-signal entry links
  - optionally, one short paragraph clarifying how to use that section

### `ov_top.m2`

- `ov_top.m2` should stop being the only place where overall documentation structure lives.
- It should become either:
  - a thin home-page file, or
  - a wrapper that links to the four audience hubs

The reusable structure should be moved into the new audience and guide files.

### `loads.m2`

Revise `loads.m2` to load by layer:

1. landing page
2. audience hubs
3. guide nodes
4. subject overviews
5. language and advanced overviews
6. contributor overviews
7. deep reference and tutorial material

This will make the documentation structure easier to maintain and reason about.

### Node Strategy

- The new audience hubs should be first-class nodes.
- Deep reference nodes should remain reusable link targets.
- Avoid unnecessary churn in existing deep reference nodes.
- The main restructure should happen at the hub and overview layer.

## Test and Verification Plan

After implementation, verify:

- `Macaulay2Doc` builds successfully.
- The new landing page renders correctly in generated HTML.
- The new audience hubs are visible and easy to scan.
- Every link from the landing page and the four hubs resolves correctly.
- The new `How to choose a data type` node links correctly into:
  - `lists and sequences`
  - `hash tables`
  - `what a class is`
  - mutable-matrix documentation
- Tutorials remain reachable from the mathematician hub.
- Contributor hubs point to working package, documentation, and core entry nodes.
- `loads.m2` order still yields a sensible table of contents.

## Assumptions and Defaults

- This is a broader structural refresh, not just a visual rewrite of the current top page.
- The four sections are audience hubs, not strict partitions.
- Duplication of links across sections is intentional when it improves navigation.
- Deep reference nodes should mostly remain intact.
- URL and node-title compatibility are not the primary constraint, but unnecessary deep-node churn should still be avoided.
- The first new content node to add should be `How to choose a data type`.

## Suggested Rollout Order

1. Add the planning note and agree on the audience-hub structure.
2. Refactor the landing page into the four hubs without rewriting all deeper docs.
3. Add `How to choose a data type`.
4. Add the other missing guide nodes.
5. Reorganize source files and `loads.m2` incrementally.
6. Polish cross-linking and reduce dead-end nodes.
