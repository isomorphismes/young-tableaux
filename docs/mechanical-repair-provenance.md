# SUN YT-MECHANICAL-01: dependency repairs

Current disposition: native and typed host qualification passed at
dc0ad4c785d8f67b52cdad1c1b4c59bb569fb485, but managed runtime admission and
release integration remain BLOCKED. Flexible Pipes issue #67 contains an
explicit human prohibition on C++ Grease. Its current shared Lua PR #52 still
requires an independently accepted compatible C++-free closure. The historical
C++ artifact rebuilt below cannot satisfy that requirement. The restriction
was found after the compatibility runs; those runs are retained as observations
and are NOT_ELIGIBLE for managed Grease/Lua admission. The consumer now stops
before acquiring that artifact. No shell substitution or policy waiver is made.

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

Rebuilt historical artifact 12239653583 has ZIP SHA-256
ef23118d46f8cc6fcce92dedad9d3480b1931db39748d8aaee18862115dd1894.
Its compiled engine SHA-256 remains exactly
7e31cd05b7a9d8fb2a4a9e003a7f3fcb0159138506d17f0fb28da8cbe22aa85c.
The rebuild used the unchanged owner launcher and engine digest. It restores
the implementation bytes, but the C++ implementation is disallowed by the
managed-runtime policy. It is not an accepted consumer replacement.

The paired APKs built at dc0ad4c are historical build candidates only. A1:
4b153997e78e134f5530c08e040206d8a051c939048241a83f7442b8d38bd1ae;
C67: 90ea9a6babba52130ea9464907a372b1fb365407d2428472d90d403875fdaa07.
Both have package org.functorialgames.youngtableaux, versionCode 9, minSdk 26
and the unchanged test signer. They are not Cat Food-delivered or physically
accepted. The source candidate for versionCode 10 and Flexible Pipes paired
production remains unexecuted on a permitted Grease closure.
