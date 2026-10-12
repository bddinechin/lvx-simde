/* SPDX-License-Identifier: MIT
 * LVX packed min/max.  Unlike add/sbf, signedness is in the NAME here
 * (maxbx vs maxubx) rather than in a modifier, because these map to GCC's
 * smax/umax optabs directly and carry no modifier operand.
 */
#if !defined(LVX_COMPUTE_MINMAX_H)
#define LVX_COMPUTE_MINMAX_H
#include "../bits/types.h"

#define lvx_maxbx(a, b)  __builtin_lvx_maxbx((a), (b))
#define lvx_maxubx(a, b) __builtin_lvx_maxubx((a), (b))
#define lvx_maxho(a, b)  __builtin_lvx_maxho((a), (b))
#define lvx_maxuho(a, b) __builtin_lvx_maxuho((a), (b))

#define lvx_minbx(a, b)  __builtin_lvx_minbx((a), (b))
#define lvx_minubx(a, b) __builtin_lvx_minubx((a), (b))
#define lvx_minho(a, b)  __builtin_lvx_minho((a), (b))
#define lvx_minuho(a, b) __builtin_lvx_minuho((a), (b))

#endif /* LVX_COMPUTE_MINMAX_H */
