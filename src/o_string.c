#include "libogle/o_common.h"
#include "libogle/o_string.h"
#include "libogle/o_char.h"

bool ogle_string_is_inside(const char* str, int32_t len, int32_t c)
{
	if (str == NULL)
	{
		return false;
	}

	for (int32_t i = 0; i < len; ++i)
	{
		if ((int32_t)str[i] == c)
		{
			return true;
		}
	}

	return false;
}

int32_t ogle_string_length(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}

	int32_t length = 0;
	while (*str)
	{
		++length;
		++str;
	}
	return length;
}

int32_t ogle_string_compare(const char* a, int32_t alen, const char* b, int32_t blen)
{
	int32_t len = (alen < blen) ? alen : blen;

	for (int32_t i = 0; i < len; ++i)
	{
		int32_t cmp = ogle_char_compare((int32_t)a[i], (int32_t)b[i]);

		if (cmp != 0)
		{
			return cmp;
		}
	}

	return ogle_char_compare((int32_t)*a, (int32_t)*b);
}

int32_t ogle_string_icompare(const char* a, int32_t alen, const char* b, int32_t blen)
{
	int32_t len = (alen < blen) ? alen : blen;

	for (int32_t i = 0; i < len; ++i)
	{
		int32_t cmp = ogle_char_icompare((int32_t)a[i], (int32_t)b[i]);
		if (cmp != 0)
		{
			return cmp;
		}
	}

	return ogle_char_icompare((int32_t)a[alen - 1], (int32_t)b[blen - 1]);
}

bool ogle_string_equals(const char* a, int32_t alen, const char* b, int32_t blen)
{
	return 0 == ogle_string_compare(a, alen, b, blen);
}

bool ogle_string_iequals(const char* a, int32_t alen, const char* b, int32_t blen)
{
	return 0 == ogle_string_icompare(a, alen, b, blen);
}
