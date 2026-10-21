# SUN YT-MECHANICAL-01: dependency repairs

The native C1–C10 repairs already landed in 4436601f57d22b27c6f524c4174abe55c247bf91.
This work preserves those implementations and adds fresh qualification rather
than repeating their merge. Historical audit failures remain historical evidence.

## Android compiler producer

AI-CI [PR #303, Qualify AArch64 ICK GNU property notes at the Android assembler
boundary](https://github.com/isomorphisms/ai-ci/pull/303) merged as
837d0a214c82c7be01cd25d5c114ee8057025f5c. Its exact candidate
82cc8716b3feb05a05e5aa7fa0bac7b4db40f8c6 passed
[run 39368855052](https://github.com/isomorphisms/ai-ci/actions/runs/39368855052)
on ARMv7, AArch64 and x86-64, with ICK
fbe86e23d55cfec2000c08e61deea2a407fd7175, GCC
6294f1d9e7536e5ffcde09d1528c918d63abfef5 and NDK 27.2.12479018.

The owning configuration disables an assembler capability that belongs to the
bootstrap GNU assembler but is absent from the consuming NDK assembler. GCC's
existing fallback emits GNU property notes. The actual assembled AArch64 fixture
retains BTI, PAC and GCS; removing its property section is rejected. Security
features are not stripped or disabled. Consumer compiler qualification reruns at
the explicit merged producer pin. Physical execution is NOT_RUN.

## Grease recovery

The missing workflow artifact 11419719229 was rebuilt by its owning source job:
[run 37478624499, attempt 2](https://github.com/dilapidated-shed/grease/actions/runs/37478624499),
job 118445864340, source ba869518c7d850de6c47d8c6234654575e264e6c,
Oils gitlink 5651cf97a1b5042f24f14112a7ade9a1518eb0bc. Inherited C++ specs,
libc, fallocate, mmap and accelerometer checks passed.

Replacement artifact 12239653583 has ZIP SHA-256
ef23118d46f8cc6fcce92dedad9d3480b1931db39748d8aaee18862115dd1894.
Its compiled engine SHA-256 remains exactly
7e31cd05b7a9d8fb2a4a9e003a7f3fcb0159138506d17f0fb28da8cbe22aa85c.
The consumer keeps the unchanged owner launcher and engine digest. This is a
rebuilt implementation from the owning source, not an interpreter substitution.
