/* SPDX-License-Identifier: MIT
 * LVX packed lane compares: COMP*, which packs one bit per lane into a GPR
 * rather than producing a 0/-1 vector.  (The 0/-1 form is COMPN*, and plain C
 * `a < b' on a vector already gets it, so it needs nothing here.)
 *
 * The condition is a modifier string, not part of the mnemonic, so these take
 * it as the third argument the way the ISA writes it -- compbx.lt, compho.eq.
 * The ten relational conditions are available; the ISA's .any/.none (bit tests
 * over an AND) are not wired into the builtin yet.
 *
 * The result is an int and needs no masking above the lane bits: COMP* zeroes
 * its whole destination register before writing them.
 */
#if !defined(LVX_COMPUTE_COMPARE_H)
#define LVX_COMPUTE_COMPARE_H
#include "../bits/types.h"

#define lvx_compbx(a, b, cc) __builtin_lvx_compbx((a), (b), (cc))
#define lvx_compho(a, b, cc) __builtin_lvx_compho((a), (b), (cc))
#define lvx_compwq(a, b, cc) __builtin_lvx_compwq((a), (b), (cc))
#define lvx_compdp(a, b, cc) __builtin_lvx_compdp((a), (b), (cc))

/* The sign bit of every lane, gathered into an int -- SSE's MOVMSKB and NEON's
   absent-by-design equivalent.  A signed `< 0' per lane IS the sign bit, so
   this is one COMPBX against a zero the compiler hoists; the portable fallback
   it replaces is a 16-iteration serial load/shift/or chain.  */
#define lvx_msbmaskbx(a) lvx_compbx ((a), (lvx_int8x16_t) { 0 }, ".lt")
#define lvx_msbmaskho(a) lvx_compho ((a), (lvx_int16x8_t) { 0 }, ".lt")
#define lvx_msbmaskwq(a) lvx_compwq ((a), (lvx_int32x4_t) { 0 }, ".lt")
#define lvx_msbmaskdp(a) lvx_compdp ((a), (lvx_int64x2_t) { 0 }, ".lt")

#endif /* LVX_COMPUTE_COMPARE_H */
