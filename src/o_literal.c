#include "libogle/o_common.h"
#include "libogle/o_literal.h"

int32_t ogle_literal_size(int32_t type)
{
	switch (type)
	{
	case OGLE_LITERAL_TYPE_INT8:
		return sizeof(int8_t);
	case OGLE_LITERAL_TYPE_INT16:
		return sizeof(int16_t);
	case OGLE_LITERAL_TYPE_INT32:
		return sizeof(int32_t);
	case OGLE_LITERAL_TYPE_INT64:
		return sizeof(int64_t);
	case OGLE_LITERAL_TYPE_UINT8:
		return sizeof(uint8_t);
	case OGLE_LITERAL_TYPE_UINT16:
		return sizeof(uint16_t);
	case OGLE_LITERAL_TYPE_UINT32:
		return sizeof(uint32_t);
	case OGLE_LITERAL_TYPE_UINT64:
		return sizeof(uint64_t);
	case OGLE_LITERAL_TYPE_FLOAT:
		return sizeof(float);
	case OGLE_LITERAL_TYPE_DOUBLE:
		return sizeof(double);
	case OGLE_LITERAL_TYPE_CHAR_PTR:
		return sizeof(char*);
	case OGLE_LITERAL_TYPE_VOID_PTR:
		return sizeof(void*);
	default:
		return -1;
	}
}

o_literal_t ogle_literal_create_int8(int8_t value)
{
	return (o_literal_t) 
	{
		.m_value.m_i8 = value,
		.m_type = OGLE_LITERAL_TYPE_INT8,
		.m_size = sizeof(int8_t)
	};
}

o_literal_t ogle_literal_create_int16(int16_t value)
{
	return (o_literal_t)
	{
		.m_value.m_i16 = value,
		.m_type = OGLE_LITERAL_TYPE_INT16,
		.m_size = sizeof(int16_t)
	};
}

o_literal_t ogle_literal_create_int32(int32_t value)
{
	return (o_literal_t)
	{
		.m_value.m_i32 = value,
		.m_type = OGLE_LITERAL_TYPE_INT32,
		.m_size = sizeof(int32_t)
	};
}

o_literal_t ogle_literal_create_int64(int64_t value)
{
	return (o_literal_t)
	{
		.m_value.m_i64 = value,
		.m_type = OGLE_LITERAL_TYPE_INT64,
		.m_size = sizeof(int64_t)
	};
}

o_literal_t ogle_literal_create_uint8(uint8_t value)
{
	return (o_literal_t)
	{
		.m_value.m_u8 = value,
		.m_type = OGLE_LITERAL_TYPE_UINT8,
		.m_size = sizeof(uint8_t)
	};
}

o_literal_t ogle_literal_create_uint16(uint16_t value)
{
	return (o_literal_t)
	{
		.m_value.m_u16 = value,
		.m_type = OGLE_LITERAL_TYPE_UINT16,
		.m_size = sizeof(uint16_t)
	};
}

o_literal_t ogle_literal_create_uint32(uint32_t value)
{
	return (o_literal_t)
	{
		.m_value.m_u32 = value,
		.m_type = OGLE_LITERAL_TYPE_UINT32,
		.m_size = sizeof(uint32_t)
	};
}

o_literal_t ogle_literal_create_uint64(uint64_t value)
{
	return (o_literal_t)
	{
		.m_value.m_u64 = value,
		.m_type = OGLE_LITERAL_TYPE_UINT64,
		.m_size = sizeof(uint64_t)
	};
}

o_literal_t ogle_literal_create_float(float value)
{
	return (o_literal_t)
	{
		.m_value.m_float = value,
		.m_type = OGLE_LITERAL_TYPE_FLOAT,
		.m_size = sizeof(float)
	};
}

o_literal_t ogle_literal_create_double(double value)
{
	return (o_literal_t)
	{
		.m_value.m_double = value,
		.m_type = OGLE_LITERAL_TYPE_DOUBLE,
		.m_size = sizeof(double)
	};
}

o_literal_t ogle_literal_create_char_ptr(char* value, int32_t size)
{
	return (o_literal_t)
	{
		.m_value.m_char_ptr = value,
		.m_type = OGLE_LITERAL_TYPE_CHAR_PTR,
		.m_size = size
	};
}

o_literal_t ogle_literal_create_void_ptr(void* value, int32_t size)
{
	return (o_literal_t)
	{
		.m_value.m_void_ptr = value,
		.m_type = OGLE_LITERAL_TYPE_VOID_PTR,
		.m_size = size
	};
}
