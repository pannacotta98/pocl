/* This file adds declarations missing from opencl-c.h.

   Copyright (c) 2011-2017 Pekka Jääskeläinen / TUT
                 2024 Pekka Jääskeläinen / Intel Finland Oy
   Copyright (c) 2017 Michal Babej / Tampere University of Technology

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to
   deal in the Software without restriction, including without limitation the
   rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
   sell copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
   IN THE SOFTWARE.
*/

#ifndef _CLANG_OPENCL_H
#define _CLANG_OPENCL_H

#ifndef SKIP_HEADER_INCLUDE
/* Use the declarations shipped with Clang. */
#ifndef _OPENCL_H_
/* Check for _OPENCL_H already here because the kernel compiler loads the
   header beforehand, but cannot find the file due to include paths not
   set up. */
#include "opencl-c.h"
#endif
#endif

/* We can include this header directly (to patch up opencl-c.h without
   including _kernel.h, thus need to define the attribute macros here. */
#ifndef _CL_OVERLOADABLE

#if __has_attribute(__overloadable__)
#  define _CL_OVERLOADABLE __attribute__((__overloadable__))
#else
#  define _CL_OVERLOADABLE
#endif

#endif

#ifndef _CL_READNONE

#if __has_attribute(__const__)
#  define _CL_READNONE __attribute__((__const__))
#else
#  define _CL_READNONE
#endif

#endif

#ifndef _CL_CONV

#if __has_attribute(__convergent__)
#  define _CL_CONV __attribute__((__convergent__))
#else
#  define _CL_CONV
#endif

#endif

/* Some of the geometric builtins are defined only up to 4 vectors, but we
   implement them all: */
#ifdef cl_khr_fp16
#pragma OPENCL EXTENSION cl_khr_fp16 : enable
half _CL_OVERLOADABLE _CL_READNONE length (half8 p);
half _CL_OVERLOADABLE _CL_READNONE length (half16 p);

half _CL_OVERLOADABLE _CL_READNONE fast_length (half8 p);
half _CL_OVERLOADABLE _CL_READNONE fast_length (half16 p);

half8 _CL_OVERLOADABLE _CL_READNONE normalize (half8 p);
half16 _CL_OVERLOADABLE _CL_READNONE normalize (half16 p);

half8 _CL_OVERLOADABLE _CL_READNONE fast_normalize (half8 p);
half16 _CL_OVERLOADABLE _CL_READNONE fast_normalize (half16 p);

half _CL_OVERLOADABLE _CL_READNONE dot (half8 p0, half8 p1);
half _CL_OVERLOADABLE _CL_READNONE dot (half16 p0, half16 p1);
#endif

float _CL_OVERLOADABLE _CL_READNONE length (float8 p);
float _CL_OVERLOADABLE _CL_READNONE length (float16 p);

float _CL_OVERLOADABLE _CL_READNONE fast_length (float8 p);
float _CL_OVERLOADABLE _CL_READNONE fast_length (float16 p);

float8 _CL_OVERLOADABLE _CL_READNONE normalize (float8 p);
float16 _CL_OVERLOADABLE _CL_READNONE normalize (float16 p);

float8 _CL_OVERLOADABLE _CL_READNONE fast_normalize (float8 p);
float16 _CL_OVERLOADABLE _CL_READNONE fast_normalize (float16 p);

float _CL_OVERLOADABLE _CL_READNONE dot (float8 p0, float8 p1);
float _CL_OVERLOADABLE _CL_READNONE dot (float16 p0, float16 p1);

#ifdef cl_khr_fp64
#pragma OPENCL EXTENSION cl_khr_fp64 : enable

double _CL_OVERLOADABLE _CL_READNONE length (double8 p);
double _CL_OVERLOADABLE _CL_READNONE length (double16 p);

double _CL_OVERLOADABLE _CL_READNONE fast_length (double p);
double _CL_OVERLOADABLE _CL_READNONE fast_length (double2 p);
double _CL_OVERLOADABLE _CL_READNONE fast_length (double3 p);
double _CL_OVERLOADABLE _CL_READNONE fast_length (double4 p);
double _CL_OVERLOADABLE _CL_READNONE fast_length (double8 p);
double _CL_OVERLOADABLE _CL_READNONE fast_length (double16 p);

double8 _CL_OVERLOADABLE _CL_READNONE normalize (double8 p);
double16 _CL_OVERLOADABLE _CL_READNONE normalize (double16 p);

double8 _CL_OVERLOADABLE _CL_READNONE fast_normalize (double8 p);
double16 _CL_OVERLOADABLE _CL_READNONE fast_normalize (double16 p);

double _CL_OVERLOADABLE _CL_READNONE dot (double8 p0, double8 p1);
double _CL_OVERLOADABLE _CL_READNONE dot (double16 p0, double16 p1);

#endif

/**************************************************************************/

#if defined(cl_intel_subgroups_char)
/* The char version is missing from opencl-c.h */
char _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (char, uint sub_group_local_id);
char2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (char2, uint sub_group_local_id);
char3 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (char3, uint sub_group_local_id);
char4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (char4, uint sub_group_local_id);
char8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (char8, uint sub_group_local_id);

uchar _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (uchar, uint sub_group_local_id);
uchar2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (uchar2, uint sub_group_local_id);
uchar3 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (uchar3, uint sub_group_local_id);
uchar4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (uchar4, uint sub_group_local_id);
uchar8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (uchar8, uint sub_group_local_id);

char _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (char, uint);
char2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (char2, uint);
char3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (char3, uint);
char4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (char4, uint);
char8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (char8, uint);
char16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (char16, uint);

uchar _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (uchar, uint);
uchar2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (uchar2, uint);
uchar3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (uchar3, uint);
uchar4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (uchar4, uint);
uchar8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (uchar8, uint);
uchar16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (uchar16, uint);

char _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (char cur,
                                                                 char next,
                                                                 uint);
char2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (char2 cur,
                                                                  char2 next,
                                                                  uint);
char3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (char3 cur,
                                                                  char3 next,
                                                                  uint);
char4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (char4 cur,
                                                                  char4 next,
                                                                  uint);
char8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (char8 cur,
                                                                  char8 next,
                                                                  uint);
char16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (char16 cur,
                                                                   char16 next,
                                                                   uint);

uchar _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (uchar cur,
                                                                  uchar next,
                                                                  uint);
uchar2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (uchar2 cur,
                                                                   uchar2 next,
                                                                   uint);
uchar3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (uchar3 cur,
                                                                   uchar3 next,
                                                                   uint);
uchar4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (uchar4 cur,
                                                                   uchar4 next,
                                                                   uint);
uchar8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (uchar8 cur,
                                                                   uchar8 next,
                                                                   uint);
uchar16 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_shuffle_down (uchar16 cur, uchar16 next, uint);

char _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (char cur,
                                                               char next,
                                                               uint);
char2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (char2 cur,
                                                                char2 next,
                                                                uint);
char3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (char3 cur,
                                                                char3 next,
                                                                uint);
char4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (char4 cur,
                                                                char4 next,
                                                                uint);
char8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (char8 cur,
                                                                char8 next,
                                                                uint);
char16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (char16 cur,
                                                                 char16 next,
                                                                 uint);

uchar _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (uchar cur,
                                                                uchar next,
                                                                uint);
uchar2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (uchar2 cur,
                                                                 uchar2 next,
                                                                 uint);
uchar3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (uchar3 cur,
                                                                 uchar3 next,
                                                                 uint);
uchar4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (uchar4 cur,
                                                                 uchar4 next,
                                                                 uint);
uchar8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (uchar8 cur,
                                                                 uchar8 next,
                                                                 uint);
uchar16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (uchar16 cur,
                                                                  uchar16 next,
                                                                  uint);

char _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (char, uint);
char2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (char2, uint);
char3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (char3, uint);
char4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (char4, uint);
char8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (char8, uint);
char16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (char16,
                                                                  uint);

uchar _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (uchar, uint);
uchar2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (uchar2,
                                                                  uint);
uchar3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (uchar3,
                                                                  uint);
uchar4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (uchar4,
                                                                  uint);
uchar8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (uchar8,
                                                                  uint);
uchar16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (uchar16,
                                                                   uint);

char _CL_OVERLOADABLE _CL_CONV intel_sub_group_reduce_add (char x);
uchar _CL_OVERLOADABLE _CL_CONV intel_sub_group_reduce_add (uchar x);
char _CL_OVERLOADABLE _CL_CONV intel_sub_group_reduce_min (char x);
uchar _CL_OVERLOADABLE _CL_CONV intel_sub_group_reduce_min (uchar x);
char _CL_OVERLOADABLE _CL_CONV intel_sub_group_reduce_max (char x);
uchar _CL_OVERLOADABLE _CL_CONV intel_sub_group_reduce_max (uchar x);

char _CL_OVERLOADABLE _CL_CONV intel_sub_group_scan_exclusive_add (char x);
uchar _CL_OVERLOADABLE _CL_CONV
intel_sub_group_scan_exclusive_add (uchar x);
char _CL_OVERLOADABLE _CL_CONV intel_sub_group_scan_exclusive_min (char x);
uchar _CL_OVERLOADABLE _CL_CONV
intel_sub_group_scan_exclusive_min (uchar x);
char _CL_OVERLOADABLE _CL_CONV intel_sub_group_scan_exclusive_max (char x);
uchar _CL_OVERLOADABLE _CL_CONV
intel_sub_group_scan_exclusive_max (uchar x);

char _CL_OVERLOADABLE _CL_CONV intel_sub_group_scan_inclusive_add (char x);
uchar _CL_OVERLOADABLE _CL_CONV
intel_sub_group_scan_inclusive_add (uchar x);
char _CL_OVERLOADABLE _CL_CONV intel_sub_group_scan_inclusive_min (char x);
uchar _CL_OVERLOADABLE _CL_CONV
intel_sub_group_scan_inclusive_min (uchar x);
char _CL_OVERLOADABLE _CL_CONV intel_sub_group_scan_inclusive_max (char x);
uchar _CL_OVERLOADABLE _CL_CONV
intel_sub_group_scan_inclusive_max (uchar x);

#if defined(__opencl_c_images)
uchar _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc (read_only image2d_t, int2);
uchar2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc2 (read_only image2d_t, int2);
uchar4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc4 (read_only image2d_t, int2);
uchar8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc8 (read_only image2d_t, int2);
uchar16 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc16 (read_only image2d_t, int2);

#if defined(__opencl_c_read_write_images)
uchar _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc (read_write image2d_t, int2);
uchar2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc2 (read_write image2d_t, int2);
uchar4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc4 (read_write image2d_t, int2);
uchar8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc8 (read_write image2d_t, int2);
uchar16 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc16 (read_write image2d_t, int2);
#endif // defined(__opencl_c_read_write_images)
#endif // defined(__opencl_c_images)

uchar _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc (const global uchar *p);
uchar2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc2 (const global uchar *p);
uchar4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc4 (const global uchar *p);
uchar8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc8 (const global uchar *p);
uchar16 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc16 (const global uchar *p);

uchar _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc (const local uchar *p);
uchar2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc2 (const local uchar *p);
uchar4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc4 (const local uchar *p);
uchar8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc8 (const local uchar *p);
uchar16 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_uc16 (const local uchar *p);

void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_uc (global uchar *p,
                                                      uchar data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_uc2 (global uchar *p,
                                                       uchar2 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_uc4 (global uchar *p,
                                                       uchar4 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_uc8 (global uchar *p,
                                                       uchar8 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_uc16 (global uchar *p,
                                                       uchar16 data);

void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_uc (local uchar *p,
                                                      uchar data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_uc2 (local uchar *p,
                                                       uchar2 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_uc4 (local uchar *p,
                                                       uchar4 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_uc8 (local uchar *p,
                                                       uchar8 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_uc16 (local uchar *p,
                                                       uchar16 data);

#if defined(__opencl_c_images)
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_uc (write_only image2d_t, int2, uchar);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_uc2 (write_only image2d_t, int2, uchar2);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_uc4 (write_only image2d_t, int2, uchar4);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_uc8 (write_only image2d_t, int2, uchar8);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_uc16 (write_only image2d_t, int2, uchar16);

#if defined(__opencl_c_read_write_images)
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_uc (read_write image2d_t, int2, uchar);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_uc2 (read_write image2d_t, int2, uchar2);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_uc4 (read_write image2d_t, int2, uchar4);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_uc8 (read_write image2d_t, int2, uchar8);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_uc16 (read_write image2d_t, int2, uchar16);
#endif // defined(__opencl_c_read_write_images)
#endif // defined(__opencl_c_images)

#endif // cl_intel_subgroups_char

/**************************************************************************/

#if defined(cl_intel_subgroups_short)
/* The short version is missing from opencl-c.h */
short _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (short, uint sub_group_local_id);
short2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (short2, uint sub_group_local_id);
short3 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (short3, uint sub_group_local_id);
short4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (short4, uint sub_group_local_id);
short8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (short8, uint sub_group_local_id);

ushort _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (ushort, uint sub_group_local_id);
ushort2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (ushort2, uint sub_group_local_id);
ushort3 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (ushort3, uint sub_group_local_id);
ushort4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (ushort4, uint sub_group_local_id);
ushort8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_broadcast (ushort8, uint sub_group_local_id);

short _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (short, uint);
short2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (short2, uint);
short3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (short3, uint);
short4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (short4, uint);
short8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (short8, uint);
short16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (short16, uint);

ushort _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (ushort, uint);
ushort2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (ushort2, uint);
ushort3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (ushort3, uint);
ushort4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (ushort4, uint);
ushort8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (ushort8, uint);
ushort16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle (ushort16, uint);

short _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (short cur,
                                                                 short next,
                                                                 uint);
short2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (short2 cur,
                                                                  short2 next,
                                                                  uint);
short3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (short3 cur,
                                                                  short3 next,
                                                                  uint);
short4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (short4 cur,
                                                                  short4 next,
                                                                  uint);
short8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (short8 cur,
                                                                  short8 next,
                                                                  uint);
short16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (short16 cur,
                                                                   short16 next,
                                                                   uint);

ushort _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (ushort cur,
                                                                  ushort next,
                                                                  uint);
ushort2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (ushort2 cur,
                                                                   ushort2 next,
                                                                   uint);
ushort3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (ushort3 cur,
                                                                   ushort3 next,
                                                                   uint);
ushort4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (ushort4 cur,
                                                                   ushort4 next,
                                                                   uint);
ushort8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_down (ushort8 cur,
                                                                   ushort8 next,
                                                                   uint);
ushort16 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_shuffle_down (ushort16 cur, ushort16 next, uint);

short _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (short cur,
                                                               short next,
                                                               uint);
short2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (short2 cur,
                                                                short2 next,
                                                                uint);
short3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (short3 cur,
                                                                short3 next,
                                                                uint);
short4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (short4 cur,
                                                                short4 next,
                                                                uint);
short8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (short8 cur,
                                                                short8 next,
                                                                uint);
short16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (short16 cur,
                                                                 short16 next,
                                                                 uint);

ushort _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (ushort cur,
                                                                ushort next,
                                                                uint);
ushort2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (ushort2 cur,
                                                                 ushort2 next,
                                                                 uint);
ushort3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (ushort3 cur,
                                                                 ushort3 next,
                                                                 uint);
ushort4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (ushort4 cur,
                                                                 ushort4 next,
                                                                 uint);
ushort8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (ushort8 cur,
                                                                 ushort8 next,
                                                                 uint);
ushort16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_up (ushort16 cur,
                                                                  ushort16 next,
                                                                  uint);

short _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (short, uint);
short2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (short2, uint);
short3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (short3, uint);
short4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (short4, uint);
short8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (short8, uint);
short16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (short16,
                                                                  uint);

ushort _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (ushort, uint);
ushort2 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (ushort2,
                                                                  uint);
ushort3 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (ushort3,
                                                                  uint);
ushort4 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (ushort4,
                                                                  uint);
ushort8 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (ushort8,
                                                                  uint);
ushort16 _CL_OVERLOADABLE _CL_CONV intel_sub_group_shuffle_xor (ushort16,
                                                                   uint);

short _CL_OVERLOADABLE _CL_CONV intel_sub_group_reduce_add (short x);
ushort _CL_OVERLOADABLE _CL_CONV intel_sub_group_reduce_add (ushort x);
short _CL_OVERLOADABLE _CL_CONV intel_sub_group_reduce_min (short x);
ushort _CL_OVERLOADABLE _CL_CONV intel_sub_group_reduce_min (ushort x);
short _CL_OVERLOADABLE _CL_CONV intel_sub_group_reduce_max (short x);
ushort _CL_OVERLOADABLE _CL_CONV intel_sub_group_reduce_max (ushort x);

short _CL_OVERLOADABLE _CL_CONV intel_sub_group_scan_exclusive_add (short x);
ushort _CL_OVERLOADABLE _CL_CONV
intel_sub_group_scan_exclusive_add (ushort x);
short _CL_OVERLOADABLE _CL_CONV intel_sub_group_scan_exclusive_min (short x);
ushort _CL_OVERLOADABLE _CL_CONV
intel_sub_group_scan_exclusive_min (ushort x);
short _CL_OVERLOADABLE _CL_CONV intel_sub_group_scan_exclusive_max (short x);
ushort _CL_OVERLOADABLE _CL_CONV
intel_sub_group_scan_exclusive_max (ushort x);

short _CL_OVERLOADABLE _CL_CONV intel_sub_group_scan_inclusive_add (short x);
ushort _CL_OVERLOADABLE _CL_CONV
intel_sub_group_scan_inclusive_add (ushort x);
short _CL_OVERLOADABLE _CL_CONV intel_sub_group_scan_inclusive_min (short x);
ushort _CL_OVERLOADABLE _CL_CONV
intel_sub_group_scan_inclusive_min (ushort x);
short _CL_OVERLOADABLE _CL_CONV intel_sub_group_scan_inclusive_max (short x);
ushort _CL_OVERLOADABLE _CL_CONV
intel_sub_group_scan_inclusive_max (ushort x);

#if defined(__opencl_c_images)
ushort _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us (read_only image2d_t, int2);
ushort2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us2 (read_only image2d_t, int2);
ushort4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us4 (read_only image2d_t, int2);
ushort8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us8 (read_only image2d_t, int2);
ushort16 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us16 (read_only image2d_t, int2);

#if defined(__opencl_c_read_write_images)
ushort _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us (read_write image2d_t, int2);
ushort2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us2 (read_write image2d_t, int2);
ushort4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us4 (read_write image2d_t, int2);
ushort8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us8 (read_write image2d_t, int2);
ushort16 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us16 (read_write image2d_t, int2);
#endif // defined(__opencl_c_read_write_images)
#endif // defined(__opencl_c_images)

ushort _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us (const global ushort *p);
ushort2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us2 (const global ushort *p);
ushort4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us4 (const global ushort *p);
ushort8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us8 (const global ushort *p);
ushort16 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us16 (const global ushort *p);

ushort _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us (const local ushort *p);
ushort2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us2 (const local ushort *p);
ushort4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us4 (const local ushort *p);
ushort8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us8 (const local ushort *p);
ushort16 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_us16 (const local ushort *p);

void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_us (global ushort *p,
                                                      ushort data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_us2 (global ushort *p,
                                                       ushort2 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_us4 (global ushort *p,
                                                       ushort4 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_us8 (global ushort *p,
                                                       ushort8 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_us16 (global ushort *p,
                                                       ushort16 data);

void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_us (local ushort *p,
                                                      ushort data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_us2 (local ushort *p,
                                                       ushort2 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_us4 (local ushort *p,
                                                       ushort4 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_us8 (local ushort *p,
                                                       ushort8 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_us16 (local ushort *p,
                                                       ushort16 data);

#if defined(__opencl_c_images)
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_us (write_only image2d_t, int2, ushort);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_us2 (write_only image2d_t, int2, ushort2);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_us4 (write_only image2d_t, int2, ushort4);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_us8 (write_only image2d_t, int2, ushort8);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_us16 (write_only image2d_t, int2, ushort16);

#if defined(__opencl_c_read_write_images)
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_us (read_write image2d_t, int2, ushort);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_us2 (read_write image2d_t, int2, ushort2);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_us4 (read_write image2d_t, int2, ushort4);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_us8 (read_write image2d_t, int2, ushort8);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_us16 (read_write image2d_t, int2, ushort16);
#endif // defined(__opencl_c_read_write_images)
#endif // defined(__opencl_c_images)

#endif // cl_intel_subgroups_short

/**************************************************************************/

#if defined(cl_intel_subgroups_long)

#if defined(__opencl_c_images)
ulong _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul (read_only image2d_t, int2);
ulong2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul2 (read_only image2d_t, int2);
ulong4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul4 (read_only image2d_t, int2);
ulong8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul8 (read_only image2d_t, int2);

#if defined(__opencl_c_read_write_images)
ulong _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul (read_write image2d_t, int2);
ulong2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul2 (read_write image2d_t, int2);
ulong4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul4 (read_write image2d_t, int2);
ulong8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul8 (read_write image2d_t, int2);
#endif // defined(__opencl_c_read_write_images)
#endif // defined(__opencl_c_images)

ulong _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul (const global ulong *p);
ulong2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul2 (const global ulong *p);
ulong4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul4 (const global ulong *p);
ulong8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul8 (const global ulong *p);

ulong _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul (const local ulong *p);
ulong2 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul2 (const local ulong *p);
ulong4 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul4 (const local ulong *p);
ulong8 _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_read_ul8 (const local ulong *p);

void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_ul (global ulong *p,
                                                      ulong data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_ul2 (global ulong *p,
                                                       ulong2 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_ul4 (global ulong *p,
                                                       ulong4 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_ul8 (global ulong *p,
                                                       ulong8 data);

void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_ul (local ulong *p,
                                                      ulong data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_ul2 (local ulong *p,
                                                       ulong2 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_ul4 (local ulong *p,
                                                       ulong4 data);
void _CL_OVERLOADABLE _CL_CONV intel_sub_group_block_write_ul8 (local ulong *p,
                                                       ulong8 data);

#if defined(__opencl_c_images)
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_ul (write_only image2d_t, int2, ulong);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_ul2 (write_only image2d_t, int2, ulong2);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_ul4 (write_only image2d_t, int2, ulong4);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_ul8 (write_only image2d_t, int2, ulong8);

#if defined(__opencl_c_read_write_images)
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_ul (read_write image2d_t, int2, ulong);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_ul2 (read_write image2d_t, int2, ulong2);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_ul4 (read_write image2d_t, int2, ulong4);
void _CL_OVERLOADABLE _CL_CONV
intel_sub_group_block_write_ul8 (read_write image2d_t, int2, ulong8);
#endif // defined(__opencl_c_read_write_images)
#endif // defined(__opencl_c_images)

#endif // cl_intel_subgroups_long

/**************************************************************************/

#ifdef cl_intel_split_work_group_barrier
void _CL_OVERLOADABLE
intel_work_group_barrier_arrive (cl_mem_fence_flags flags);
void _CL_OVERLOADABLE intel_work_group_barrier_wait (cl_mem_fence_flags flags);
// For OpenCL C 2.0 or newer:
#if defined(__OPENCL_CPP_VERSION__) || (__OPENCL_C_VERSION__ >= CL_VERSION_2_0)
void _CL_OVERLOADABLE
intel_work_group_barrier_arrive (cl_mem_fence_flags flags, memory_scope scope);
void _CL_OVERLOADABLE intel_work_group_barrier_wait (cl_mem_fence_flags flags,
                                                     memory_scope scope);
#endif
#endif // cl_intel_split_work_group_barrier

#endif
