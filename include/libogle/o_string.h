#ifndef _HEADER_GUARD_OGLE_STRING_H_
#define _HEADER_GUARD_OGLE_STRING_H_

#include "libogle/o_common.h"

#define OGLE_STRING_TRUE "true"
#define OGLE_STRING_FALSE "false"

bool ogle_string_is_inside(const char* str, int32_t len, int32_t c);
int32_t ogle_string_length(const char* str);
int32_t ogle_string_compare(const char* a, int32_t alen, const char* b, int32_t blen);
int32_t ogle_string_icompare(const char* a, int32_t alen, const char* b, int32_t blen);
bool ogle_string_equals(const char* a, int32_t alen, const char* b, int32_t blen);
bool ogle_string_iequals(const char* a, int32_t alen, const char* b, int32_t blen);

bool ogle_string_to_bool(const char* str);
int8_t ogle_string_to_int8(const char* str);
int16_t ogle_string_to_int16(const char* str);
int32_t ogle_string_to_int32(const char* str);
int64_t ogle_string_to_int64(const char* str);
uint8_t ogle_string_to_uint8(const char* str);
uint16_t ogle_string_to_uint16(const char* str);
uint32_t ogle_string_to_uint32(const char* str);
uint64_t ogle_string_to_uint64(const char* str);
float ogle_string_to_float(const char* str);
double ogle_string_to_double(const char* str);

bool ogle_string_from_bool(char* buffer, int32_t buffer_size, bool value);
bool ogle_string_from_int8(char* buffer, int32_t buffer_size, int8_t value);
bool ogle_string_from_int16(char* buffer, int32_t buffer_size, int16_t value);
bool ogle_string_from_int32(char* buffer, int32_t buffer_size, int32_t value);
bool ogle_string_from_int64(char* buffer, int32_t buffer_size, int64_t value);
bool ogle_string_from_uint8(char* buffer, int32_t buffer_size, uint8_t value);
bool ogle_string_from_uint16(char* buffer, int32_t buffer_size, uint16_t value);
bool ogle_string_from_uint32(char* buffer, int32_t buffer_size, uint32_t value);
bool ogle_string_from_uint64(char* buffer, int32_t buffer_size, uint64_t value);
bool ogle_string_from_float(char* buffer, int32_t buffer_size, float value);
bool ogle_string_from_double(char* buffer, int32_t buffer_size, double value);

#endif // _HEADER_GUARD_OGLE_STRING_H_
