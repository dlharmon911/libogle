#ifndef _HEADER_GUARD_OGLE_STRINGVIEW_H_
#define _HEADER_GUARD_OGLE_STRINGVIEW_H_

#include "libogle/o_common.h"

typedef struct o_stringview_tag_t
{
	const char* m_data;
	size_t m_length;
} o_stringview_t;

o_stringview_t ogle_stringview_empty();
o_stringview_t ogle_stringview_buffer(const char* str, size_t length);
o_stringview_t ogle_stringview_cstr(const char* str);
bool ogle_stringview_is_empty(o_stringview_t view);
const char* ogle_stringview_data(o_stringview_t view);
size_t ogle_stringview_length(o_stringview_t view);
o_stringview_t ogle_stringview_ltrim_count(o_stringview_t view, size_t count);
o_stringview_t ogle_stringview_rtrim_count(o_stringview_t view, size_t count);
o_stringview_t ogle_stringview_ltrim_whitespace(o_stringview_t view);
o_stringview_t ogle_stringview_rtrim_whitespace(o_stringview_t view);
o_stringview_t ogle_stringview_trim_whitespace(o_stringview_t view);
bool ogle_stringview_equals(o_stringview_t a, o_stringview_t b);
bool ogle_stringview_iequals(o_stringview_t a, o_stringview_t b);
int32_t ogle_stringview_compare(o_stringview_t a, o_stringview_t b);
int32_t ogle_stringview_icompare(o_stringview_t a, o_stringview_t b);
int32_t ogle_stringview_compare_cstr(o_stringview_t a, const char* b);
int32_t ogle_stringview_icompare_cstr(o_stringview_t a, const char* b);
bool ogle_stringview_starts_with(o_stringview_t view, o_stringview_t prefix);
bool ogle_stringview_ends_with(o_stringview_t view, o_stringview_t suffix);
bool ogle_stringview_equals_cstr(o_stringview_t a, const char* b);
bool ogle_stringview_iequals_cstr(o_stringview_t a, const char* b);
int32_t ogle_stringview_compare_cstr(o_stringview_t a, const char* b);
int32_t ogle_stringview_icompare_cstr(o_stringview_t a, const char* b);
bool ogle_stringview_starts_with_cstr(o_stringview_t view, const char* prefix);
bool ogle_stringview_ends_with_cstr(o_stringview_t view, const char* suffix);
o_stringview_t ogle_stringview_tokenize(o_stringview_t view, int32_t delimiter, o_stringview_t* out_token);
o_stringview_t ogle_stringview_tokenize_identifier(o_stringview_t view, o_stringview_t* out_token);
o_stringview_t ogle_stringview_tokenize_double(o_stringview_t view, double* out_value);
o_stringview_t ogle_stringview_tokenize_float(o_stringview_t view, float* out_value);
o_stringview_t ogle_stringview_tokenize_i32(o_stringview_t view, int32_t* out_value);
o_stringview_t ogle_stringview_tokenize_u32(o_stringview_t view, uint32_t* out_value);
o_stringview_t ogle_stringview_tokenize_i64(o_stringview_t view, int64_t* out_value);
o_stringview_t ogle_stringview_tokenize_u64(o_stringview_t view, uint64_t* out_value);
o_stringview_t ogle_stringview_file_read_polygon(ALLEGRO_FILE* file, char* buffer, int32_t buffer_size);
ALLEGRO_USTR* ogle_stringview_to_ustr(o_stringview_t view);
o_stringview_t ogle_stringview_from_ustr(ALLEGRO_USTR* ustr);
void ogle_stringview_print(o_stringview_t view);
void ogle_stringview_fprint(ALLEGRO_FILE* file, o_stringview_t view);

#endif // _HEADER_GUARD_OGLE_STRINGVIEW_H_
