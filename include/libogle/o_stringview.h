#ifndef _HEADER_GUARD_OGLE_STRINGVIEW_H_
#define _HEADER_GUARD_OGLE_STRINGVIEW_H_

#include "libogle/o_common.h"

typedef struct o_stringview_tag_t
{
	const char* m_data;
	int32_t m_length;
} o_stringview_t;

o_stringview_t ogle_stringview();
o_stringview_t ogle_stringview_buffer(const char* str, int32_t length);
o_stringview_t ogle_stringview_cstr(const char* str);
const char* ogle_stringview_data(o_stringview_t view);
int32_t ogle_stringview_length(o_stringview_t view);
o_stringview_t ogle_stringview_ltrim_count(o_stringview_t view, int32_t count);
o_stringview_t ogle_stringview_rtrim_count(o_stringview_t view, int32_t count);
o_stringview_t ogle_stringview_ltrim_whitespace(o_stringview_t view);
o_stringview_t ogle_stringview_rtrim_whitespace(o_stringview_t view);
o_stringview_t ogle_stringview_trim_whitespace(o_stringview_t view);
bool ogle_stringview_equals(o_stringview_t a, o_stringview_t b);
bool ogle_stringview_iequals(o_stringview_t a, o_stringview_t b);
int32_t ogle_stringview_compare(o_stringview_t a, o_stringview_t b);
int32_t ogle_stringview_icompare(o_stringview_t a, o_stringview_t b);
bool ogle_stringview_starts_with(o_stringview_t view, o_stringview_t prefix);
bool ogle_stringview_ends_with(o_stringview_t view, o_stringview_t suffix);
bool ogle_stringview_cstr_equals_(o_stringview_t a, const char* b);
bool ogle_stringview_cstr_iequals_(o_stringview_t a, const char* b);
int32_t ogle_stringview_cstr_compare_(o_stringview_t a, const char* b);
int32_t ogle_stringview_cstr_icompare_(o_stringview_t a, const char* b);
bool ogle_stringview_cstr_starts_with(o_stringview_t view, const char* prefix);
bool ogle_stringview_cstr_ends_with(o_stringview_t view, const char* suffix);
o_stringview_t ogle_stringview_tokenize(o_stringview_t view, int32_t delimiter, o_stringview_t* out_token);
o_stringview_t ogle_stringview_tokenize_identifier(o_stringview_t view, o_stringview_t* out_token);
o_stringview_t ogle_stringview_tokenize_double(o_stringview_t view, double* out_value);
o_stringview_t ogle_stringview_tokenize_float(o_stringview_t view, float* out_value);
o_stringview_t ogle_stringview_tokenize_i32(o_stringview_t view, int32_t* out_value);
o_stringview_t ogle_stringview_tokenize_u32(o_stringview_t view, uint32_t* out_value);
o_stringview_t ogle_stringview_tokenize_i64(o_stringview_t view, int64_t* out_value);
o_stringview_t ogle_stringview_tokenize_u64(o_stringview_t view, uint64_t* out_value);
o_stringview_t ogle_stringview_file_read_line(ALLEGRO_FILE* file, char* buffer, int32_t buffer_size);

#endif // _HEADER_GUARD_OGLE_STRINGVIEW_H_
