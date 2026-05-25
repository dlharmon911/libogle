#ifndef _HEADER_GUARD_OGLE_STRING_H_
#define _HEADER_GUARD_OGLE_STRING_H_

#include "libogle/o_common.h"

bool ogle_string_is_inside(const char* str, int32_t len, int32_t c);
int32_t ogle_string_length(const char* str);
int32_t ogle_string_compare(const char* a, int32_t alen, const char* b, int32_t blen);
int32_t ogle_string_icompare(const char* a, int32_t alen, const char* b, int32_t blen);
bool ogle_string_equals(const char* a, int32_t alen, const char* b, int32_t blen);
bool ogle_string_iequals(const char* a, int32_t alen, const char* b, int32_t blen);

#endif // _HEADER_GUARD_OGLE_STRING_H_
