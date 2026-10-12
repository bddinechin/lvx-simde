/* SPDX-License-Identifier: MIT
 * LVX packed add, with the saturate modifier.
 *
 * One builtin per lane shape, saturation selected by the third argument --
 * "" plain, ".s" signed-saturating, ".us" unsigned-saturating -- which is the
 * same shape as KVX's __builtin_kvx_add(a, b, ".us").
 */
#if !defined(LVX_COMPUTE_ADD_H)
#define LVX_COMPUTE_ADD_H
#include "../bits/types.h"

#define lvx_addbx(a, b)   __builtin_lvx_addbx((a), (b), "")
#define lvx_addsbx(a, b)  __builtin_lvx_addbx((a), (b), ".s")
#define lvx_addusbx(a, b) __builtin_lvx_addbx((a), (b), ".us")

#define lvx_addho(a, b)   __builtin_lvx_addho((a), (b), "")
#define lvx_addsho(a, b)  __builtin_lvx_addho((a), (b), ".s")
#define lvx_addusho(a, b) __builtin_lvx_addho((a), (b), ".us")

#endif /* LVX_COMPUTE_ADD_H */
