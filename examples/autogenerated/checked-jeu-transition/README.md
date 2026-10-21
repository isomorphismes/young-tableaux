# Executed checked jeu de taquin transition slice

The model in `types/YoungTableaux/CheckedJeu.idric` admits partitions and cells
with proof fields obtained from executable Boolean checks. The domain matches
the native board: 64 rows/columns and 256 cells. It validates containment,
complete unique entry coverage, positive entries, weak rows and strict columns.
Ordinary skew fillings and fillings with a hole have separate types.

`begin_slide` opens a removable inner corner. `forward_step` moves the smaller
neighbor into the hole; equal neighbors choose below. The terminal step removes
an outer corner and returns an ordinary filling. All transitions recheck the
invariants. Bounded fuel makes trace termination explicit.

`TransitionChecks.idric` is an actual executable driver. The checked Ithon
harness compiles it through the real pinned Idriç compiler, executes it, and
compares all observations with the unchanged native engine. Sixteen fixtures
cover ties, each one-neighbor case, empty and single boards, multiple inner
corners, and malformed inputs. Eight direct admission controls include
coordinates 4294967297. Three separately compiled bad models must be rejected.
The existing thirteen decision/provenance rules still compile and execute.

Compiler bundle: Cat Food run 38090627721/artifact 11684276190, source
94dfd99bd3e376507fedc8611053b7173b2519f0, bundled Chez 10.4.1. The harness checks
exit status, executable existence and compiler error text, because this compiler
revision can return zero on an elaboration failure. Source correspondence alone
is never acceptance. Native compilation uses qualified ICK.

Restoration on 2026-10-21 compiled and executed through Flexible Pipes. The
reconstructed harness initially failed Ithon checking at an untyped foreign
digest expression; binding that digest as `str` repairs the boundary. No Python
fallback was introduced. RSK, Android lowering and replacing native kernels are
outside this first slice. Fresh CI artifacts carry the acceptance verdicts.
