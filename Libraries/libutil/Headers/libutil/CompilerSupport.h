/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree.
 */

#ifndef __libutil_CompilerSupport_h
#define __libutil_CompilerSupport_h

#if defined(_MSC_VER) && !defined(__clang__)
#define LIBUTIL_PACKED_STRUCT_BEGIN __pragma(pack(push, 1))
#define LIBUTIL_PACKED_STRUCT_END __pragma(pack(pop))
#else
#define LIBUTIL_PACKED_STRUCT_BEGIN
#define LIBUTIL_PACKED_STRUCT_END __attribute__((__packed__))
#define LIBUTIL_PACKED_STRUCT_END_ALIGNED_FOUR __attribute__((__packed__, aligned(4)))
#endif

#endif  // !__libutil_CompilerSupport_h
