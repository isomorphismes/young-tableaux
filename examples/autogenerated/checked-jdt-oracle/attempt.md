# Check the actual JDT visual oracle

Purpose: migrate the new owned tests/jeu_visual_contract.py from merged PR 19
to mandatory checked Ithon while preserving the real painter/state-transition
positive and all four actual C source mutants. C remains compiled by explicitly
qualified ICK; Idriç mathematical transition/provenance checks remain separate.

Type sketch: compiler argv are text lists; mutations are fixed four-text tuples;
override paths are a typed dictionary; exit status is an integer; streams and
digests are text. Paths, argparse and process objects are explicit foreign
standard-library boundaries. No owned Python module is imported as foreign.
Source order, flags, mutation substrings, exact positive/refusal diagnostics,
output streams, executable hashes and receipt bytes are preserved.

The actual frontend first rejected implicit sorted because it has no predefined
static type. The reduced original is retained in sorted.pi. Importing the real
standard-library builtin explicitly supplies that foreign callable boundary;
the source list remains explicitly typed. Current-head native execution must
still pass before integration. Missing compiler refusal and frontend admission
are not a successful painter run.

The next actual frontend attempt refused list[str] concatenation. The reduced
original is list-concat.pi. Typed list extension preserves exactly the same
compiler argv order and bytes without that unsupported operator.

The third actual refusal was an untyped empty list passed as a foreign
argparse default; empty-foreign-argument.pi retains it. An explicitly typed
list[str] default preserves exactly the same parser behavior.

The fourth refusal was a foreign str.strip result nested in concatenation,
retained in untyped-method-result.pi. Binding that result to text clears the
observed boundary without changing the emitted diagnostic.

The complete final module is admitted by the actual accepted frontend and
refuses the absent compiler at the intended existence gate. Hosted qualification
uses accepted Ithon main 74ab6d6044b07b76a910978437a34a6b5ac6acda and the
maintained explicit ICK producer 903b2cb27ea572c9c6cb2ffa9f39e0fbf06ec9f8.
The Idriç mathematical consumer also uses that ICK for its native support;
an ambient host compiler is not a substitute. Current-head native/mutant and
Idriç execution remain required, separate gates.

The older audit_renderer.py and independent_audit.py remain separately named
legacy migration debt. This does not claim the whole of merged PR 19 was
Ithon-qualified or that an APK was installed/tested on any physical device.
