#include "libogle/o_common.h"
#include "libogle/o_string.h"
#include "libogle/o_char.h"

bool ogle_string_is_inside(const char* str, size_t len, int32_t c)
{
	if (str == NULL)
	{
		return false;
	}

	for (size_t i = 0; i < len; ++i)
	{
		if ((int32_t)str[i] == c)
		{
			return true;
		}
	}

	return false;
}

size_t ogle_string_length(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}

	size_t length = 0;
	while (*str)
	{
		++length;
		++str;
	}
	return length;
}

int32_t ogle_string_compare(const char* a, size_t alen, const char* b, size_t blen)
{
	size_t len = (alen < blen) ? alen : blen;

	for (size_t i = 0; i < len; ++i)
	{
		int32_t cmp = ogle_char_compare((int32_t)a[i], (int32_t)b[i]);

		if (cmp != 0)
		{
			return cmp;
		}
	}

	return ogle_char_compare((int32_t)*a, (int32_t)*b);
}

int32_t ogle_string_icompare(const char* a, size_t alen, const char* b, size_t blen)
{
	size_t len = (alen < blen) ? alen : blen;

	for (size_t i = 0; i < len; ++i)
	{
		int32_t cmp = ogle_char_icompare((int32_t)a[i], (int32_t)b[i]);
		if (cmp != 0)
		{
			return cmp;
		}
	}

	return ogle_char_icompare((int32_t)a[alen - 1], (int32_t)b[blen - 1]);
}

bool ogle_string_equals(const char* a, size_t alen, const char* b, size_t blen)
{
	if (alen != blen)
	{
		return false;
	}

	return 0 == ogle_string_compare(a, alen, b, blen);
}

bool ogle_string_iequals(const char* a, size_t alen, const char* b, size_t blen)
{
	if (alen != blen)
	{
		return false;
	}

	return 0 == ogle_string_icompare(a, alen, b, blen);
}

bool ogle_string_to_bool(const char* str)
{
	if (str == NULL)
	{
		return false;
	}

	size_t len = ogle_string_length(str);

	if (len == 4 && ogle_string_icompare(str, len, OGLE_STRING_TRUE, 4) == 0)
	{
		return true;
	}

	return false;
}

int8_t ogle_string_to_int8(const char* str)
{
	if (str == NULL)
	{
		return 0;
	}
	char* temp = NULL;
	long value = strtol(str, &temp, 10);

	if (value < INT8_MIN || value > INT8_MAX)
	{
		value = 0;
	}
	else if (temp != NULL && *temp != '\0')
	{
		value = 0;
	}

	return (int8_t)value;
}

int16_t ogle_string_to_int16(const char* str)
{
	char* temp = NULL;
	long value = strtol(str, &temp, 10);

	if (value < INT16_MIN || value > INT16_MAX)
	{
		value = 0;
	}
	else if (temp != NULL && *temp != '\0')
	{
		value = 0;
	}

	return (int16_t)value;
}

int32_t ogle_string_to_int32(const char* str)
{
	char* temp = NULL;
	long value = strtol(str, &temp, 10);

	if (value < INT32_MIN || value > INT32_MAX)
	{
		value = 0;
	}
	else if (temp != NULL && *temp != '\0')
	{
		value = 0;
	}

	return (int32_t)value;
}

int64_t ogle_string_to_int64(const char* str)
{
	char* temp = NULL;
	
	long long value = strtoll(str, &temp, 10);
	
	if (value < INT64_MIN || value > INT64_MAX)
	{
		value = 0;
	}
	else if (temp != NULL && *temp != '\0')
	{
		value = 0;
	}

	return (int64_t)value;
}

uint8_t ogle_string_to_uint8(const char* str)
{
	char* temp = NULL;
	unsigned long value = strtoul(str, &temp, 10);
	if (value > UINT8_MAX)
	{
		value = 0;
	}
	else if (temp != NULL && *temp != '\0')
	{
		value = 0;
	}
	return (uint8_t)value;
}

uint16_t ogle_string_to_uint16(const char* str)
{
	char* temp = NULL;
	unsigned long value = strtoul(str, &temp, 10);
	if (value > UINT16_MAX)
	{
		value = 0;
	}
	else if (temp != NULL && *temp != '\0')
	{
		value = 0;
	}
	return (uint16_t)value;
}

uint32_t ogle_string_to_uint32(const char* str)
{
	char* temp = NULL;
	unsigned long value = strtoul(str, &temp, 10);
	if (value > UINT32_MAX)
	{
		value = 0;
	}
	else if (temp != NULL && *temp != '\0')
	{
		value = 0;
	}
	return (uint32_t)value;
}

uint64_t ogle_string_to_uint64(const char* str)
{
	char* temp = NULL;
	unsigned long long value = strtoull(str, &temp, 10);
	if (value > UINT64_MAX)
	{
		value = 0;
	}
	else if (temp != NULL && *temp != '\0')
	{
		value = 0;
	}
	return (uint64_t)value;
}

float ogle_string_to_float(const char* str)
{
	char* temp = NULL;
	float value = strtof(str, &temp);
	if ((value == HUGE_VALF || value == -HUGE_VALF) && errno == ERANGE)
	{
		value = 0.0f;
	}
	else if (temp != NULL && *temp != '\0')
	{
		value = 0.0f;
	}
	return value;
}

double ogle_string_to_double(const char* str)
{
	char* temp = NULL;
	double value = strtod(str, &temp);
	if ((value == HUGE_VAL || value == -HUGE_VAL) && errno == ERANGE)
	{
		value = 0.0;
	}
	else if (temp != NULL && *temp != '\0')
	{
		value = 0.0;
	}
	return value;
}

bool ogle_string_from_bool(char* buffer, size_t buffer_size, bool value)
{
	const char* str = value ? OGLE_STRING_TRUE : OGLE_STRING_FALSE;
	size_t len = ogle_string_length(str);
	if (buffer_size < len + 1)
	{
		return false;
	}
	for (size_t i = 0; i < len; ++i)
	{
		buffer[i] = str[i];
	}
	buffer[len] = '\0';
	return true;
}

bool ogle_string_from_int8(char* buffer, size_t buffer_size, int8_t value)
{
	char temp[12]; // Enough to hold -128 and null terminator
	int length = snprintf(temp, sizeof(temp), "%d", value);
	if (length < 0 || length >= buffer_size)
	{
		return false;
	}
	for (size_t i = 0; i < length; ++i)
	{
		buffer[i] = temp[i];
	}
	buffer[length] = '\0';
	return true;
}

bool ogle_string_from_int16(char* buffer, size_t buffer_size, int16_t value)
{
	char temp[12]; // Enough to hold -32768 and null terminator
	int length = snprintf(temp, sizeof(temp), "%d", value);
	if (length < 0 || length >= buffer_size)
	{
		return false;
	}
	for (size_t i = 0; i < length; ++i)
	{
		buffer[i] = temp[i];
	}
	buffer[length] = '\0';
	return true;
}

bool ogle_string_from_int32(char* buffer, size_t buffer_size, int32_t value)
{
	char temp[12]; // Enough to hold -2147483648 and null terminator
	int length = snprintf(temp, sizeof(temp), "%d", value);
	if (length < 0 || length >= buffer_size)
	{
		return false;
	}
	for (size_t i = 0; i < length; ++i)
	{
		buffer[i] = temp[i];
	}
	buffer[length] = '\0';
	return true;
}

bool ogle_string_from_int64(char* buffer, size_t buffer_size, int64_t value)
{
	char temp[21]; // Enough to hold -9223372036854775808 and null terminator
	int length = snprintf(temp, sizeof(temp), "%lld", value);
	if (length < 0 || length >= buffer_size)
	{
		return false;
	}
	for (size_t i = 0; i < length; ++i)
	{
		buffer[i] = temp[i];
	}
	buffer[length] = '\0';
	return true;
}

bool ogle_string_from_uint8(char* buffer, size_t buffer_size, uint8_t value)
{
	char temp[4]; // Enough to hold 255 and null terminator
	int length = snprintf(temp, sizeof(temp), "%u", value);
	if (length < 0 || length >= buffer_size)
	{
		return false;
	}
	for (size_t i = 0; i < length; ++i)
	{
		buffer[i] = temp[i];
	}
	buffer[length] = '\0';
	return true;
}

bool ogle_string_from_uint16(char* buffer, size_t buffer_size, uint16_t value)
{
	char temp[6]; // Enough to hold 65535 and null terminator
	int length = snprintf(temp, sizeof(temp), "%u", value);
	if (length < 0 || length >= buffer_size)
	{
		return false;
	}
	for (size_t i = 0; i < length; ++i)
	{
		buffer[i] = temp[i];
	}
	buffer[length] = '\0';
	return true;
}

bool ogle_string_from_uint32(char* buffer, size_t buffer_size, uint32_t value)
{
	char temp[11]; // Enough to hold 4294967295 and null terminator
	int length = snprintf(temp, sizeof(temp), "%u", value);
	if (length < 0 || length >= buffer_size)
	{
		return false;
	}
	for (size_t i = 0; i < length; ++i)
	{
		buffer[i] = temp[i];
	}
	buffer[length] = '\0';
	return true;
}

bool ogle_string_from_uint64(char* buffer, size_t buffer_size, uint64_t value)
{
	char temp[21]; // Enough to hold 18446744073709551615 and null terminator
	int length = snprintf(temp, sizeof(temp), "%llu", value);
	if (length < 0 || length >= buffer_size)
	{
		return false;
	}
	for (size_t i = 0; i < length; ++i)
	{
		buffer[i] = temp[i];
	}
	buffer[length] = '\0';
	return true;
}

bool ogle_string_from_float(char* buffer, size_t buffer_size, float value)
{
	char temp[32]; // Enough to hold float representation and null terminator
	int length = snprintf(temp, sizeof(temp), "%g", value);
	if (length < 0 || length >= buffer_size)
	{
		return false;
	}
	for (size_t i = 0; i < length; ++i)
	{
		buffer[i] = temp[i];
	}
	buffer[length] = '\0';
	return true;
}

bool ogle_string_from_double(char* buffer, size_t buffer_size, double value)
{
	char temp[32]; // Enough to hold double representation and null terminator
	int length = snprintf(temp, sizeof(temp), "%g", value);
	if (length < 0 || length >= buffer_size)
	{
		return false;
	}
	for (size_t i = 0; i < length; ++i)
	{
		buffer[i] = temp[i];
	}
	buffer[length] = '\0';
	return true;
}
