# Executable mathematical boundaries

The mathematical kernels remain in `app/core`; embedded modified Lua still owns
its existing interaction/composition layer. The checked Idriç modules supply
executable admissions and independent host semantics for the shared tableau,
RSK and jeu de taquin boundaries. The earlier `Idriç` branch's row and reverse
insertion algorithms are reconciled here rather than introducing another app.

| Boundary | Checked owner | Guarantee |
|---|---|---|
| Partition / cell | `CheckedJeu.idric` | Positive nonincreasing rows; bounded size and coordinates |
| Ordinary skew filling | `CheckedJeu.idric` | Containment, exact unique cell coverage, positive entries, weak rows, strict columns |
| Active slide | `CheckedJeu.idric` | Separate hole type; checked opening, each move and corner removal |
| Rectification | `CheckedJeu.idric` | Repeated checked slides; result type certifies empty inner shape |
| Straight semistandard / standard filling | `CheckedRSK.idric` | Valid bounded shape and order; standard also requires exactly 1 through size |
| Word / permutation | `CheckedRSK.idric` | Positive representable letters; permutation also requires exactly 1 through length |
| Biword | `CheckedRSK.idric` | Positive paired letters in lexicographic order, including equal-top ordering |
| Natural matrix | `CheckedRSK.idric` | Rectangular nonnegative weights; check expanded size before replication |
| Partial RSK trace | `CheckedRSK.idric` | Equal insertion/recording shapes, processed size, bump path; permits nonstandard permutation prefixes |
| Completed RSK families | `CheckedRSK.idric` | Completion required; standard/standard, semistandard/standard, semistandard/semistandard remain distinct |
| Permutation inverse | `CheckedRSK.idric` | Accepts only a completed standard/standard pair; returns a checked permutation |

Proof-bearing constructors are private. Public admission functions obtain `So`
certificates from value checks. Wrong-family/unfinished inverse calls and a
forged raw word constructor must fail actual Idriç checking. Raw RSK numeric
inputs use unbounded `Integer`, so negative and oversized values are rejected
before any narrowing or matrix expansion.

The current native interface uses 64 rows/columns, 256 board cells, at most 64
RSK letters and positive signed 32-bit entries. These limits are explicit
interface restrictions. Mathematical tableaux and words are not defined by
machine bounds. Full permutation prefixes keep semistandard insertion fillings:
the prefix `[3]` of `[3,1,2]` is valid although its alphabet is not `1..1`.

`tests/typed_rsk_contract.pi` compiles and executes the actual Idriç source,
then compares every observed prefix's entries, shapes, bump path and inserted
value with the existing qualified-ICK native engine. It checks completion,
inverse round trips, rejected raw admissions and compiled semantic mutants.
`tests/typed_jeu_contract.pi` retains the original decision/provenance and
single-slide checks and adds full native rectification comparisons and a
compiled no-op rectification mutant. All new orchestration is checked Ithon.
Compiler exit zero alone is insufficient: executable existence and compiler
error output are checked too.

The RSK corpus compares 2,041 prefixes across 366 inputs, with all 155
permutation inverse round trips, eight compiled rejecting mutants and three
rejected type fixtures. It includes all permutations through size five and the
decreasing size-64 permutation. The jeu corpus retains 18 complete slide
traces, adds six rectifications, checks 12 raw admissions and rejects five
compiled mutants while preserving the original 13 decision/provenance rules.

The reproducible host interface is `ci/flexible-pipes-typed.json`; its assignment
is `ci/typed-boundary-assignment.txt`. The comprehensive host interface also
requires RSK qualification. The existing exact-head typed workflow preserves
the compiler/execution output, rejected type examples, mutant observations and
plain receipts under `build/typed-rsk-evidence` and `build/typed-jeu-evidence`.

This is host semantic execution. It does not replace the broader
`Operations.idric` / `Types.idr` inventories with certified implementations of
shifted, ribbon, oscillating or K constructions. Those remain explicitly
unsupported. Nor does a host pipeline receipt establish managed
controller/Kitchen/Ike admission. Actual embedded-Lua admission and APK
qualification still require the existing compatible C++-free Grease closure;
see `ci/managed-runtime-prerequisite.tsv`. A1/C67 execution requires separate
physical-device evidence.
