#include "libogle/o_common.h"
#include "libogle/o_char.h"
#include "libogle/o_string.h"

static const char* OGLE_WHITESPACE_CHARS = " \t\n\r\f\v";

int32_t ogle_char_compare(int32_t a, int32_t b)
{
	if (a < b)
	{
		return -1;
	}
	else if (a > b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int32_t ogle_char_icompare(int32_t a, int32_t b)
{
	int32_t lower_a = ogle_char_to_lower(a);
	int32_t lower_b = ogle_char_to_lower(b);

	return ogle_char_compare(lower_a, lower_b);
}

bool ogle_char_equal(int32_t a, int32_t b)
{
	return ogle_char_compare(a, b) == 0;
}

bool ogle_char_iequal(int32_t a, int32_t b)
{
	return ogle_char_icompare(a, b) == 0;
}

int32_t ogle_char_to_lower(int32_t c)
{
	if (ogle_char_is_upper(c))
	{
		return c + ('a' - 'A');
	}

	return c;
}

int32_t ogle_char_to_upper(int32_t c)
{
	if (ogle_char_is_lower(c))
	{
		return c - ('a' - 'A');
	}
	return c;
}

bool ogle_char_is_lower(int32_t c)
{
	return c >= 'a' && c <= 'z';
}

bool ogle_char_is_upper(int32_t c)
{
	return c >= 'A' && c <= 'Z';
}

bool ogle_char_is_digit(int32_t c)
{
	return c >= '0' && c <= '9';
}

bool ogle_char_is_alpha(int32_t c)
{
	return ogle_char_is_lower(c) || ogle_char_is_upper(c);
}

bool ogle_char_is_alphanumeric(int32_t c)
{
	return ogle_char_is_alpha(c) || ogle_char_is_digit(c);
}

bool ogle_char_is_whitespace(int32_t c)
{
	size_t length = ogle_string_length(OGLE_WHITESPACE_CHARS);

	return ogle_string_is_inside(OGLE_WHITESPACE_CHARS, length, c);
}

bool ogle_char_is_hex_digit(int32_t c)
{
	return ogle_char_is_digit(c) ||
		(c >= 'a' && c <= 'f') ||
		(c >= 'A' && c <= 'F');
}
