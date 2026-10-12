/* SPDX-License-Identifier: MIT
 * LVX vector types for SIMDe.
 *
 * KVX's compiler ships int8x16_t and friends as native types; lvx-gcc does
 * not, so they are GCC vector extensions here.  The element types match the
 * modes the __builtin_lvx_* prototypes are declared with -- V16QI is
 * `signed char' x16, V8HI `short' x8 -- because a mismatch is an argument-type
 * error at every call site rather than anything subtle.
 */
#if !defined(LVX_BITS_TYPES_H)
#define LVX_BITS_TYPES_H

typedef signed char        lvx_int8x16_t  __attribute__((vector_size(16)));
typedef short              lvx_int16x8_t  __attribute__((vector_size(16)));
typedef int                lvx_int32x4_t  __attribute__((vector_size(16)));
typedef long long          lvx_int64x2_t  __attribute__((vector_size(16)));

#endif /* LVX_BITS_TYPES_H */
