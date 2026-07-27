#include "libogle/o_common.h"
#include "libogle/o_char.h"
#include "libogle/o_string.h"
#include "libogle/o_stringview.h"

static const char* OGLE_EMPTY_STRING = "";

o_stringview_t ogle_stringview_empty()
{
	o_stringview_t view =
	{
		.m_data = OGLE_EMPTY_STRING,
		.m_length = 0
	};

	return view;
}


o_stringview_t ogle_stringview_buffer(const char* str, size_t length)
{
	if (str == NULL)
	{
		str = OGLE_EMPTY_STRING;
		length = 0;
	}

	o_stringview_t view =
	{
		.m_data = str,
		.m_length = length
	};

	return view;
}

o_stringview_t ogle_stringview_cstr(const char* str)
{
	if (str == NULL)
	{
		str = OGLE_EMPTY_STRING;
	}

	o_stringview_t view =
	{
		.m_data = str,
		.m_length = ogle_string_length(str)
	};
	return view;
}

bool ogle_stringview_is_empty(o_stringview_t view)
{
	return (NULL == view.m_data || view.m_length == 0);
}

const char* ogle_stringview_data(o_stringview_t view)
{
	if (view.m_data == NULL || view.m_length <= 0)
	{
		return "";
	}

	return view.m_data;
}

size_t ogle_stringview_length(o_stringview_t view)
{
	return view.m_length;
}

o_stringview_t ogle_stringview_ltrim_count(o_stringview_t view, size_t count)
{
	if (count > view.m_length)
	{
		count = view.m_length;
	}

	view.m_data += count;
	view.m_length -= count;

	return view;
}

o_stringview_t ogle_stringview_rtrim_count(o_stringview_t view, size_t count)
{
	if (count > view.m_length)
	{
		count = view.m_length;
	}

	view.m_length -= count;

	return view;
}

o_stringview_t ogle_stringview_ltrim_whitespace(o_stringview_t view)
{
	while (view.m_length > 0 && ogle_char_is_whitespace(*view.m_data))
	{
		view.m_data++;
		view.m_length--;
	}

	return view;
}

o_stringview_t ogle_stringview_rtrim_whitespace(o_stringview_t view)
{
	while (view.m_length > 0 && ogle_char_is_whitespace(view.m_data[view.m_length - 1]))
	{
		view.m_length--;
	}

	return view;
}

o_stringview_t ogle_stringview_trim_whitespace(o_stringview_t view)
{
	view = ogle_stringview_ltrim_whitespace(view);
	view = ogle_stringview_rtrim_whitespace(view);
	return view;
}

bool ogle_stringview_equals(o_stringview_t a, o_stringview_t b)
{
	return ogle_string_equals(a.m_data, a.m_length, b.m_data, b.m_length);
}

bool ogle_stringview_iequals(o_stringview_t a, o_stringview_t b)
{
	return ogle_string_iequals(a.m_data, a.m_length, b.m_data, b.m_length);
}

int32_t ogle_stringview_compare(o_stringview_t a, o_stringview_t b)
{
	return ogle_string_compare(a.m_data, a.m_length, b.m_data, b.m_length);
}

int32_t ogle_stringview_icompare(o_stringview_t a, o_stringview_t b)
{
	return ogle_string_icompare(a.m_data, a.m_length, b.m_data, b.m_length);
}

bool ogle_stringview_starts_with(o_stringview_t view, o_stringview_t prefix)
{
	if (prefix.m_length > view.m_length)
	{
		return false;
	}

	return ogle_string_equals(view.m_data, prefix.m_length, prefix.m_data, prefix.m_length);
}

bool ogle_stringview_ends_with(o_stringview_t view, o_stringview_t suffix)
{
	if (suffix.m_length > view.m_length)
	{
		return false;
	}

	return ogle_string_equals(view.m_data + view.m_length - suffix.m_length, suffix.m_length, suffix.m_data, suffix.m_length);
}

bool ogle_stringview_cstr_equals_(o_stringview_t a, const char* b)
{
	size_t blen = ogle_string_length(b);
	return ogle_string_equals(a.m_data, a.m_length, b, blen);
}

bool ogle_stringview_cstr_iequals_(o_stringview_t a, const char* b)
{
	size_t blen = ogle_string_length(b);
	return ogle_string_iequals(a.m_data, a.m_length, b, blen);
}

int32_t ogle_stringview_cstr_compare_(o_stringview_t a, const char* b)
{
	size_t blen = ogle_string_length(b);
	return ogle_string_compare(a.m_data, a.m_length, b, blen);
}

int32_t ogle_stringview_cstr_icompare_(o_stringview_t a, const char* b)
{
	size_t blen = ogle_string_length(b);
	return ogle_string_icompare(a.m_data, a.m_length, b, blen);
}

bool ogle_stringview_cstr_starts_with(o_stringview_t view, const char* prefix)
{
	size_t plen = ogle_string_length(prefix);

	if (plen > view.m_length)
	{
		return false;
	}

	return ogle_string_equals(view.m_data, plen, prefix, plen);
}

bool ogle_stringview_cstr_ends_with(o_stringview_t view, const char* suffix)
{
	size_t slen = ogle_string_length(suffix);

	if (slen > view.m_length)
	{
		return false;
	}

	return ogle_string_equals(view.m_data + view.m_length - slen, slen, suffix, slen);
}

o_stringview_t ogle_stringview_tokenize(o_stringview_t view, int32_t delimiter, o_stringview_t* out_token)
{
	size_t i = 0;

	if (!out_token)
	{
		return view;
	}

	if (!view.m_data || view.m_length <= 0)
	{
		if (out_token)
		{
			out_token->m_data = OGLE_EMPTY_STRING;
			out_token->m_length = 0;
		}
		return view;
	}

	for (i = 0; i < view.m_length; ++i)
	{
		if (view.m_data[i] == delimiter)
		{
			break;
		}
	}

	out_token->m_data = view.m_data;
	out_token->m_length = i;

	view.m_data += i;
	if (i < view.m_length)
	{
		view.m_data += 1;
	}
	view.m_length -= i;
	if (view.m_length < 0)
	{
		view.m_length = 0;
	}
	return view;
}

static bool ogle_is_identifier_start_char(int32_t c)
{
	return (c == '_') || ogle_char_is_alpha(c);
}

static bool ogle_is_identifier_char(int32_t c)
{
	return (c == '_') || ogle_char_is_alphanumeric(c);
}

o_stringview_t ogle_stringview_tokenize_identifier(o_stringview_t view, o_stringview_t* out_token)
{
	int32_t i = 0;
	if (!out_token)
	{
		return view;
	}
	
	if (!view.m_data || view.m_length <= 0)
	{
		if (out_token)
		{
			out_token->m_data = OGLE_EMPTY_STRING;
			out_token->m_length = 0;
		}
		return view;
	}

	if (!ogle_is_identifier_start_char(view.m_data[0]))
	{
		if (out_token)
		{
			out_token->m_data = OGLE_EMPTY_STRING;
			out_token->m_length = 0;
		}
		return view;
	}
	
	for (i = 1; i < view.m_length; ++i)
	{
		char c = view.m_data[i];
		if (!ogle_is_identifier_char(c))
		{
			break;
		}
	}
	out_token->m_data = view.m_data;
	out_token->m_length = i;
	view.m_data += i;
	view.m_length -= i;
	if (view.m_length < 0)
	{
		view.m_length = 0;
	}
	return view;
}

o_stringview_t ogle_stringview_tokenize_double(o_stringview_t view, double* out_value)
{
	char* endptr = NULL;
	
	if (!out_value)
	{
		return view;
	}

	*out_value = strtod(view.m_data, &endptr);

	view.m_data = endptr;
	view.m_length -= endptr - view.m_data;

	if (view.m_length < 0)
	{
		view.m_length = 0;
	}

	return view;
}

o_stringview_t ogle_stringview_tokenize_float(o_stringview_t view, float* out_value)
{
	char* endptr = NULL;

	if (!out_value)
	{
		return view;
	}

	*out_value = strtof(view.m_data, &endptr);

	view.m_data = endptr;
	view.m_length -= endptr - view.m_data;

	if (view.m_length < 0)
	{
		view.m_length = 0;
	}

	return view;
}

o_stringview_t ogle_stringview_tokenize_i32(o_stringview_t view, int32_t* out_value)
{
	char* endptr = NULL;
	if (!out_value)
	{
		return view;
	}
	*out_value = (int32_t)strtol(view.m_data, &endptr, 10);
	view.m_data = endptr;
	view.m_length -= endptr - view.m_data;
	if (view.m_length < 0)
	{
		view.m_length = 0;
	}
	return view;
}

o_stringview_t ogle_stringview_tokenize_u32(o_stringview_t view, uint32_t* out_value)
{
	char* endptr = NULL;
	if (!out_value)
	{
		return view;
	}
	*out_value = (uint32_t)strtoul(view.m_data, &endptr, 10);
	view.m_data = endptr;
	view.m_length -= endptr - view.m_data;
	if (view.m_length < 0)
	{
		view.m_length = 0;
	}
	return view;
}

o_stringview_t ogle_stringview_tokenize_i64(o_stringview_t view, int64_t* out_value)
{
	char* endptr = NULL;
	if (!out_value)
	{
		return view;
	}
	*out_value = (int64_t)strtoll(view.m_data, &endptr, 10);
	view.m_data = endptr;
	view.m_length -= endptr - view.m_data;
	if (view.m_length < 0)
	{
		view.m_length = 0;
	}
	return view;
}

o_stringview_t ogle_stringview_tokenize_u64(o_stringview_t view, uint64_t* out_value)
{
	char* endptr = NULL;
	if (!out_value)
	{
		return view;
	}
	*out_value = (uint64_t)strtoull(view.m_data, &endptr, 10);
	view.m_data = endptr;
	view.m_length -= endptr - view.m_data;
	if (view.m_length < 0)
	{
		view.m_length = 0;
	}
	return view;
}

o_stringview_t ogle_stringview_file_read_polygon(ALLEGRO_FILE* file, char* buffer, int32_t buffer_size)
{
	if (!file || !buffer || buffer_size <= 0)
	{
		return (o_stringview_t) { OGLE_EMPTY_STRING, 0 };
	}

	size_t byte_count = (size_t)buffer_size;

	memset(buffer, 0, byte_count);

	if (al_fgets(file, buffer, byte_count) == NULL)
	{
		return (o_stringview_t) { buffer, 0 };
	}

	return (o_stringview_t) { buffer, ogle_string_length(buffer) };
}

ALLEGRO_USTR* ogle_stringview_to_ustr(o_stringview_t view)
{
	if (view.m_data == NULL || view.m_length <= 0)
	{
		return al_ustr_dup(al_ustr_empty_string());
	}

	return al_ustr_new_from_buffer(view.m_data, view.m_length);
}

o_stringview_t ogle_stringview_from_ustr(ALLEGRO_USTR* ustr)
{
	if (!ustr)
	{
		return (o_stringview_t) { OGLE_EMPTY_STRING, 0 };
	}
	const char* data = al_cstr(ustr);
	size_t length = al_ustr_size(ustr);
	return (o_stringview_t) { data, length };
}
