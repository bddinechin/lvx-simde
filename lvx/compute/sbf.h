/* SPDX-License-Identifier: MIT
 * LVX packed subtract-from, with the saturate modifier, and the plain
 * subtract built on it.
 *
 * SBF* is "subtract FROM": sbf $d = $x, $y computes y - x.  So an ordinary
 * a - b is sbf(b, a), with the operands swapped -- the same definition KVX
 * carries (#define kvx_subus(a, b) kvx_sbfus(b, a)).  Getting this backwards
 * computes b - a, assembles cleanly, and is wrong only in the values, which
 * is why validation/tests/micro exercises both operand orders.
 */
#if !defined(LVX_COMPUTE_SBF_H)
#define LVX_COMPUTE_SBF_H
#include "../bits/types.h"

#define lvx_sbfbx(a, b)   __builtin_lvx_sbfbx((a), (b), "")
#define lvx_sbfsbx(a, b)  __builtin_lvx_sbfbx((a), (b), ".s")
#define lvx_sbfusbx(a, b) __builtin_lvx_sbfbx((a), (b), ".us")

#define lvx_sbfho(a, b)   __builtin_lvx_sbfho((a), (b), "")
#define lvx_sbfsho(a, b)  __builtin_lvx_sbfho((a), (b), ".s")
#define lvx_sbfusho(a, b) __builtin_lvx_sbfho((a), (b), ".us")

/* a - b, saturating.  Operands swapped, per the note above. */
#define lvx_subbx(a, b)   lvx_sbfbx((b), (a))
#define lvx_subsbx(a, b)  lvx_sbfsbx((b), (a))
#define lvx_subusbx(a, b) lvx_sbfusbx((b), (a))

#define lvx_subho(a, b)   lvx_sbfho((b), (a))
#define lvx_subsho(a, b)  lvx_sbfsho((b), (a))
#define lvx_subusho(a, b) lvx_sbfusho((b), (a))

#endif /* LVX_COMPUTE_SBF_H */
