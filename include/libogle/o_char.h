#ifndef _HEADER_GUARD_OGLE_CHAR_H_
#define _HEADER_GUARD_OGLE_CHAR_H_

#include "libogle/o_common.h"

int32_t ogle_char_compare(int32_t a, int32_t b);
int32_t ogle_char_icompare(int32_t a, int32_t b);
bool ogle_char_equal(int32_t a, int32_t b);
bool ogle_char_iequal(int32_t a, int32_t b);
int32_t ogle_char_to_lower(int32_t c);
int32_t ogle_char_to_upper(int32_t c);
bool ogle_char_is_whitespace(int32_t c);
bool ogle_char_is_lower(int32_t c);
bool ogle_char_is_upper(int32_t c);
bool ogle_char_is_digit(int32_t c);
bool ogle_char_is_alpha(int32_t c);
bool ogle_char_is_alphanumeric(int32_t c);
bool ogle_char_is_hex_digit(int32_t c);

#endif // _HEADER_GUARD_OGLE_CHAR_H_
