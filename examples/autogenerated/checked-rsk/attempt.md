# Checked RSK mathematical boundaries

Raw integer rows, letters, biletters and matrix weights enter through checked
constructors. A semistandard filling has a partition shape, positive entries,
weak rows and strict columns. A standard filling also has exactly the alphabet
1 through its size. These are different types, as are words and permutations.
Ordered biwords and rectangular natural matrices have their own admissions.

The current native interface bounds a board to 64 rows/columns and 256 cells,
RSK inputs to 64 letters, and entries to signed 32-bit positive integers. These
are explicit interface limits, not definitions of the mathematical objects.
Checks precede expansion or narrowing; all raw numeric inputs use Integer.

Central operations:

- checked_word : List Integer → Maybe CheckedWord
- checked_permutation : List Integer → Maybe CheckedPermutation
- checked_biword : List (Integer, Integer) → Maybe CheckedBiword
- checked_matrix : List (List Integer) → Maybe CheckedMatrix
- checked_semistandard : List (List Integer) → Maybe SemistandardFilling
- checked_standard : List (List Integer) → Maybe StandardFilling
- insert_letter : SemistandardFilling → Integer → Maybe RowInsertion
- word/permutation/biword/matrix insertion → checked partial trace
- completion → family-specific result; incomplete traces cannot be completed
- inverse_permutation : PermutationPair → Maybe CheckedPermutation

Partial permutation prefixes need not have alphabet 1 through prefix length.
They remain semistandard traces; only complete permutation pairs have two
standard fillings. Pair shape equality and trace size are checked evidence.
The public constructors do not export their raw proof-bearing constructors.

The row insertion and reverse insertion algorithms reconcile the earlier
`Idriç` branch's `Young/Core.idric`; they retain the first-strictly-greater bump
and rightmost-strictly-smaller reverse bump. Existing native kernels and
embedded modified Lua retain their ownership. This is a host-executed semantic
boundary and oracle, not an Android backend replacement or a blanket port.

Qualification compiles actual Idriç with the existing pinned 94dfd99b compiler,
executes complete observations against qualified ICK native output, and rejects
compiled mathematical/admission mutants. The orchestration is checked Ithon.
No ordinary Python fallback or alternative compiler is introduced. Execution
results and failures are retained in build/typed-rsk-evidence; current evidence
is reported separately from historical records. The same qualification is
bound into the existing Flexible Pipes host interface and typed workflow.

Language boundary: ordinary checked records, private constructors, So evidence,
bounded recursive algorithms and Chez host execution are supported by the
pinned compiler. Android lowering, FFI installation and physical execution
remain separate qualification boundaries. A future native adapter must preserve
these admissions and observations before replacing the existing native owner.

The initial compilation failed at inherited `index'` argument order. A named,
structurally recursive `at_index` removes that accidental representation-level
dependency. The first compiled execution then rejected the empty standard
alphabet because descending `[1..0]` is not an empty list. Explicit `one_through`
handles zero and retains the empty word, permutation and tableaux as valid
objects. Both failures were found through the actual compiler/executable; no
fallback was used. Qualification directories are cleared per compilation so
stale executable or mutant files cannot be reused.

The final corpus has 2,041 complete prefix observations over 366 inputs: all
words on three letters through length four, every permutation through size
five, the decreasing size-64 permutation, repeated-letter and INT_MAX words,
ordered repeated biwords, all 81 two-by-two matrices with weights 0..2, and
empty/size-64 matrix cases. All 155 permutation inverses must recover their
original input. Three type errors and eight separately compiled mathematical
mutants are required rejections, including reversed inverse output order.
Actual commands and results are retained by the host pipeline, with separate
compiler and execution logs for each model. Hosted workflow evidence is fresh
only after the exact branch head runs; this record does not promote old CI.
