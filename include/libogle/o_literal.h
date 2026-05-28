#ifndef _HEADER_GUARD_OGLE_LITERALH_
#define _HEADER_GUARD_OGLE_LITERALH_

#include "libogle/o_common.h"

enum OGLE_LITERAL_TYPE
{
	OGLE_LITERAL_TYPE_INT8,
	OGLE_LITERAL_TYPE_INT16,
	OGLE_LITERAL_TYPE_INT32,
	OGLE_LITERAL_TYPE_INT64,
	OGLE_LITERAL_TYPE_UINT8,
	OGLE_LITERAL_TYPE_UINT16,
	OGLE_LITERAL_TYPE_UINT32,
	OGLE_LITERAL_TYPE_UINT64,
	OGLE_LITERAL_TYPE_FLOAT,
	OGLE_LITERAL_TYPE_DOUBLE,
	OGLE_LITERAL_TYPE_CHAR_PTR,
	OGLE_LITERAL_TYPE_VOID_PTR,
	OGLE_LITERAL_TYPE_COUNT
};

typedef struct o_literal_tag_t
{
	union
	{
		int8_t m_i8;
		int16_t m_i16;
		int32_t m_i32;
		int64_t m_i64;
		uint8_t m_u8;
		uint16_t m_u16;
		uint32_t m_u32;
		uint64_t m_u64;
		float m_float;
		double m_double;
		char* m_char_ptr;
		void* m_void_ptr;
	} m_value;
	int32_t m_type;
	int32_t m_size;
} o_literal_t;

int32_t ogle_literal_size(int32_t type);
o_literal_t ogle_literal_create_int8(int8_t value);
o_literal_t ogle_literal_create_int16(int16_t value);
o_literal_t ogle_literal_create_int32(int32_t value);
o_literal_t ogle_literal_create_int64(int64_t value);
o_literal_t ogle_literal_create_uint8(uint8_t value);
o_literal_t ogle_literal_create_uint16(uint16_t value);
o_literal_t ogle_literal_create_uint32(uint32_t value);
o_literal_t ogle_literal_create_uint64(uint64_t value);
o_literal_t ogle_literal_create_float(float value);
o_literal_t ogle_literal_create_double(double value);
o_literal_t ogle_literal_create_char_ptr(char* value, int32_t size);
o_literal_t ogle_literal_create_void_ptr(void* value, int32_t size);

#endif // _HEADER_GUARD_OGLE_LITERALH_
