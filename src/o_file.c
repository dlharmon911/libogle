#include <allegro5/allegro_memfile.h>
#include <time.h>
#include "libogle/o_common.h"
#include "libogle/o_literal.h"
#include "libogle/o_file.h"

size_t ogle_file_size(ALLEGRO_FILE* file)
{
	int64_t current_position = 0;
	int64_t end_position = 0;

	if (!file)
	{
		return 0;
	}

	current_position = al_ftell(file);

	if (current_position < 0)
	{
		return 0;
	}

	if (!al_fseek(file, 0, ALLEGRO_SEEK_END))
	{
		return 0;
	}

	end_position = al_ftell(file);

	if (end_position < 0)
	{
		return 0;
	}

	if (!al_fseek(file, current_position, ALLEGRO_SEEK_SET))
	{
		return 0;
	}

	return (size_t)end_position;
}

int32_t ogle_file_write_bool(ALLEGRO_FILE* file, bool value)
{
	return ogle_file_write_u8(file, value ? 1 : 0);
}

int32_t ogle_file_write_bool_array(ALLEGRO_FILE* file, const bool* array, size_t size)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == array)
	{
		return -1;
	}
	
	for (size_t i = 0; i < size; ++i)
	{
		if (ogle_file_write_bool(file, array[i]) < 0)
		{
			return -1;
		}
	}
	
	return 0;
}

int32_t ogle_file_write_i8(ALLEGRO_FILE* file, int8_t value)
{
	return ogle_file_write_u8_array(file, (const uint8_t*)&value, 1);
}

int32_t ogle_file_write_i8_array(ALLEGRO_FILE* file, const int8_t* array, size_t size)
{
	return ogle_file_write_u8_array(file, (const uint8_t*)array, size);
}

int32_t ogle_file_write_i16(ALLEGRO_FILE* file, int16_t value)
{
	return ogle_file_write_u16_array(file, (const uint16_t*)&value, 1);
}

int32_t ogle_file_write_i16_array(ALLEGRO_FILE* file, const int16_t* array, size_t size)
{
	return ogle_file_write_u16_array(file, (const uint16_t*)array, size);
}

int32_t ogle_file_write_i32(ALLEGRO_FILE* file, int32_t value)
{
	return ogle_file_write_u32_array(file, (const uint32_t*)&value, 1);
}

int32_t ogle_file_write_i32_array(ALLEGRO_FILE* file, const int32_t* array, size_t size)
{
	return ogle_file_write_u32_array(file, (const uint32_t*)array, size);
}

int32_t ogle_file_write_i64(ALLEGRO_FILE* file, int64_t value)
{
	return ogle_file_write_u64_array(file, (const uint64_t*)&value, 1);
}

int32_t ogle_file_write_i64_array(ALLEGRO_FILE* file, const int64_t* array, size_t size)
{
	return ogle_file_write_u64_array(file, (const uint64_t*)array, size);
}

int32_t ogle_file_write_u8(ALLEGRO_FILE* file, uint8_t value)
{
	if (NULL == file)
	{
		return -1;
	}

	if (al_fwrite(file, &value, sizeof(uint8_t)) != sizeof(uint8_t))
	{
		return -1;
	}
	
	return 0;
}

int32_t ogle_file_write_u8_array(ALLEGRO_FILE* file, const uint8_t* array, size_t size)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == array)
	{
		return -1;
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (ogle_file_write_u8(file, array[i]) < 0)
		{
			return -1;
		}
	}

	return 0;
}

int32_t ogle_file_write_u16(ALLEGRO_FILE* file, uint16_t value)
{
	if (NULL == file)
	{
		return -1;
	}

#ifdef ALLEGRO_BIG_ENDIAN
	ogle_utilities_swap_bytes(&value, sizeof(uint16_t));
#endif

	if (al_fwrite(file, &value, sizeof(uint16_t)) != sizeof(uint16_t))
	{
		return -1;
	}

	return 0;
}

int32_t ogle_file_write_u16_array(ALLEGRO_FILE* file, const uint16_t* array, size_t size)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == array)
	{
		return -1;
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (ogle_file_write_u16(file, array[i]) < 0)
		{
			return -1;
		}
	}

	return 0;
}

int32_t ogle_file_write_u32(ALLEGRO_FILE* file, uint32_t value)
{
	if (NULL == file)
	{
		return -1;
	}

#ifdef ALLEGRO_BIG_ENDIAN
	ogle_utilities_swap_bytes(&value, sizeof(uint32_t));
#endif

	if (al_fwrite(file, &value, sizeof(uint32_t)) != sizeof(uint32_t))
	{
		return -1;
	}

	return 0;
}

int32_t ogle_file_write_u32_array(ALLEGRO_FILE* file, const uint32_t* array, size_t size)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == array)
	{
		return -1;
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (ogle_file_write_u32(file, array[i]) < 0)
		{
			return -1;
		}
	}

	return 0;
}

int32_t ogle_file_write_u64(ALLEGRO_FILE* file, uint64_t value)
{
	if (NULL == file)
	{
		return -1;
	}

#ifdef ALLEGRO_BIG_ENDIAN
	ogle_utilities_swap_bytes(&value, sizeof(uint64_t));
#endif

	if (al_fwrite(file, &value, sizeof(uint64_t)) != sizeof(uint64_t))
	{
		return -1;
	}

	return 0;
}

int32_t ogle_file_write_u64_array(ALLEGRO_FILE* file, const uint64_t* array, size_t size)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == array)
	{
		return -1;
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (ogle_file_write_u64(file, array[i]) < 0)
		{
			return -1;
		}
	}

	return 0;
}

int32_t ogle_file_write_f32(ALLEGRO_FILE* file, float value)
{
	return ogle_file_write_u32_array(file, (const uint32_t*)&value, 1);
}

int32_t ogle_file_write_f32_array(ALLEGRO_FILE* file, const float* array, size_t size)
{
	return ogle_file_write_u32_array(file, (const uint32_t*)array, size);
}

int32_t ogle_file_write_f64(ALLEGRO_FILE* file, double value)
{
	return ogle_file_write_u64_array(file, (const uint64_t*)&value, 1);
}

int32_t ogle_file_write_f64_array(ALLEGRO_FILE* file, const double* array, size_t size)
{
	return ogle_file_write_u64_array(file, (const uint64_t*)array, size);
}

int32_t ogle_file_read_bool(ALLEGRO_FILE* file, bool* value)
{
	uint8_t temp;
	if (ogle_file_read_u8(file, &temp) < 0)
	{
		return -1;
	}
	*value = (temp != 0);
	return 0;
}

int32_t ogle_file_read_bool_array(ALLEGRO_FILE* file, bool* array, size_t size)
{
	if (NULL == file)
	{
		return -1;
	}
	if (NULL == array)
	{
		return -1;
	}
	for (size_t i = 0; i < size; ++i)
	{
		if (ogle_file_read_bool(file, &array[i]) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int32_t ogle_file_read_i8(ALLEGRO_FILE* file, int8_t* value)
{
	return ogle_file_read_u8(file, (uint8_t*)value);
}

int32_t ogle_file_read_i8_array(ALLEGRO_FILE* file, int8_t* array, size_t size)
{
	return ogle_file_read_u8_array(file, (uint8_t*)array, size);
}

int32_t ogle_file_read_i16(ALLEGRO_FILE* file, int16_t* value)
{
	return ogle_file_read_u16(file, (uint16_t*)value);
}

int32_t ogle_file_read_i16_array(ALLEGRO_FILE* file, int16_t* array, size_t size)
{
	return ogle_file_read_u16_array(file, (uint16_t*)array, size);
}

int32_t ogle_file_read_i32(ALLEGRO_FILE* file, int32_t* value)
{
	return ogle_file_read_u32(file, (uint32_t*)value);
}

int32_t ogle_file_read_i32_array(ALLEGRO_FILE* file, int32_t* array, size_t size)
{
	return ogle_file_read_u32_array(file, (uint32_t*)array, size);
}

int32_t ogle_file_read_i64(ALLEGRO_FILE* file, int64_t* value)
{
	return ogle_file_read_u64(file, (uint64_t*)value);
}

int32_t ogle_file_read_i64_array(ALLEGRO_FILE* file, int64_t* array, size_t size)
{
	return ogle_file_read_u64_array(file, (uint64_t*)array, size);
}

int32_t ogle_file_read_u8(ALLEGRO_FILE* file, uint8_t* value)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == value)
	{
		return -1;
	}

	if (al_fread(file, value, sizeof(uint8_t)) != sizeof(uint8_t))
	{
		return -1;
	}

	return 0;
}

int32_t ogle_file_read_u8_array(ALLEGRO_FILE* file, uint8_t* array, size_t size)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == array)
	{
		return -1;
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (ogle_file_read_u8(file, array + i) < 0)
		{
			return -1;
		}
	}

	return 0;
}

int32_t ogle_file_read_u16(ALLEGRO_FILE* file, uint16_t* value)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == value)
	{
		return -1;
	}

	if (al_fread(file, value, sizeof(uint16_t)) != sizeof(uint16_t))
	{
		return -1;
	}

#ifdef ALLEGRO_BIG_ENDIAN
	ogle_utilities_swap_bytes(value, sizeof(uint16_t));
#endif

	return 0;
}

int32_t ogle_file_read_u16_array(ALLEGRO_FILE* file, uint16_t* array, size_t size)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == array)
	{
		return -1;
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (ogle_file_read_u16(file, array + i) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int32_t ogle_file_read_u32(ALLEGRO_FILE* file, uint32_t* value)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == value)
	{
		return -1;
	}

	if (al_fread(file, value, sizeof(uint32_t)) != sizeof(uint32_t))
	{
		return -1;
	}

#ifdef ALLEGRO_BIG_ENDIAN
	ogle_utilities_swap_bytes(value, sizeof(uint32_t));
#endif

	return 0;
}

int32_t ogle_file_read_u32_array(ALLEGRO_FILE* file, uint32_t* array, size_t size)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == array)
	{
		return -1;
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (ogle_file_read_u32(file, array + i) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int32_t ogle_file_read_u64(ALLEGRO_FILE* file, uint64_t* value)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == value)
	{
		return -1;
	}

	if (al_fread(file, value, sizeof(uint64_t)) != sizeof(uint64_t))
	{
		return -1;
	}

#ifdef ALLEGRO_BIG_ENDIAN
	ogle_utilities_swap_bytes(value, sizeof(uint64_t));
#endif

	return 0;
}

int32_t ogle_file_read_u64_array(ALLEGRO_FILE* file, uint64_t* array, size_t size)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == array)
	{
		return -1;
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (ogle_file_read_u64(file, array + i) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int32_t ogle_file_read_f32(ALLEGRO_FILE* file, float* value)
{
	return ogle_file_read_u32(file, (uint32_t*)value);
}

int32_t ogle_file_read_f32_array(ALLEGRO_FILE* file, float* array, size_t size)
{
	return ogle_file_read_u32_array(file, (uint32_t*)array, size);
}

int32_t ogle_file_read_f64(ALLEGRO_FILE* file, double* value)
{
	return ogle_file_read_u64(file, (uint64_t*)value);
}

int32_t ogle_file_read_f64_array(ALLEGRO_FILE* file, double* array, size_t size)
{
	return ogle_file_read_u64_array(file, (uint64_t*)array, size);
}

int32_t ogle_file_write_literal(ALLEGRO_FILE* file, int32_t type, const void* value)
{
	if (NULL == file)
	{
		return -1;
	}

	if (NULL == value)
	{
		return -1;
	}

	if (type < 0 || type >= OGLE_LITERAL_TYPE_COUNT)
	{
		return -1;
	}

	switch (type)
	{
	case OGLE_LITERAL_TYPE_INT8: return ogle_file_write_i8(file, *(const int8_t*)value);
	case OGLE_LITERAL_TYPE_INT16: return ogle_file_write_i16(file, *(const int16_t*)value);
	case OGLE_LITERAL_TYPE_INT32: return ogle_file_write_i32(file, *(const int32_t*)value);
	case OGLE_LITERAL_TYPE_INT64: return ogle_file_write_i64(file, *(const int64_t*)value);
	case OGLE_LITERAL_TYPE_UINT8: return ogle_file_write_u8(file, *(const uint8_t*)value);
	case OGLE_LITERAL_TYPE_UINT16: return ogle_file_write_u16(file, *(const uint16_t*)value);
	case OGLE_LITERAL_TYPE_UINT32: return ogle_file_write_u32(file, *(const uint32_t*)value);
	case OGLE_LITERAL_TYPE_UINT64: return ogle_file_write_u64(file, *(const uint64_t*)value);
	case OGLE_LITERAL_TYPE_FLOAT: return ogle_file_write_f32(file, *(const float*)value);
	case OGLE_LITERAL_TYPE_DOUBLE: return ogle_file_write_f64(file, *(const double*)value);
	default: return -1;
	}

	return -1;
}
int32_t ogle_file_write_literal_array(ALLEGRO_FILE* file, int32_t type, const void* array, size_t size)
{
	if (NULL == file)
	{
		return -1;
	}
	if (NULL == array)
	{
		return -1;
	}
	if (type < 0 || type >= OGLE_LITERAL_TYPE_COUNT)
	{
		return -1;
	}

	switch (type)
	{
	case OGLE_LITERAL_TYPE_INT8: return ogle_file_write_i8_array(file, (const int8_t*)array, size);
	case OGLE_LITERAL_TYPE_INT16: return ogle_file_write_i16_array(file, (const int16_t*)array, size);
	case OGLE_LITERAL_TYPE_INT32: return ogle_file_write_i32_array(file, (const int32_t*)array, size);
	case OGLE_LITERAL_TYPE_INT64: return ogle_file_write_i64_array(file, (const int64_t*)array, size);
	case OGLE_LITERAL_TYPE_UINT8: return ogle_file_write_u8_array(file, (const uint8_t*)array, size);
	case OGLE_LITERAL_TYPE_UINT16: return ogle_file_write_u16_array(file, (const uint16_t*)array, size);
	case OGLE_LITERAL_TYPE_UINT32: return ogle_file_write_u32_array(file, (const uint32_t*)array, size);
	case OGLE_LITERAL_TYPE_UINT64: return ogle_file_write_u64_array(file, (const uint64_t*)array, size);
	case OGLE_LITERAL_TYPE_FLOAT: return ogle_file_write_f32_array(file, (const float*)array, size);
	case OGLE_LITERAL_TYPE_DOUBLE: return ogle_file_write_f64_array(file, (const double*)array, size);
	default: return -1;
	}

	return -1;
}

int32_t ogle_file_read_literal(ALLEGRO_FILE* file, int32_t type, void* value)
{
	if (NULL == file)
	{
		return -1;
	}
	if (NULL == value)
	{
		return -1;
	}
	if (type < 0 || type >= OGLE_LITERAL_TYPE_COUNT)
	{
		return -1;
	}
	switch (type)
	{
	case OGLE_LITERAL_TYPE_INT8: return ogle_file_read_i8(file, (int8_t*)value);
	case OGLE_LITERAL_TYPE_INT16: return ogle_file_read_i16(file, (int16_t*)value);
	case OGLE_LITERAL_TYPE_INT32: return ogle_file_read_i32(file, (int32_t*)value);
	case OGLE_LITERAL_TYPE_INT64: return ogle_file_read_i64(file, (int64_t*)value);
	case OGLE_LITERAL_TYPE_UINT8: return ogle_file_read_u8(file, (uint8_t*)value);
	case OGLE_LITERAL_TYPE_UINT16: return ogle_file_read_u16(file, (uint16_t*)value);
	case OGLE_LITERAL_TYPE_UINT32: return ogle_file_read_u32(file, (uint32_t*)value);
	case OGLE_LITERAL_TYPE_UINT64: return ogle_file_read_u64(file, (uint64_t*)value);
	case OGLE_LITERAL_TYPE_FLOAT: return ogle_file_read_f32(file, (float*)value);
	case OGLE_LITERAL_TYPE_DOUBLE: return ogle_file_read_f64(file, (double*)value);
	default: return -1;
	}
	return -1;
}

int32_t ogle_file_read_literal_array(ALLEGRO_FILE* file, int32_t type, void* array, size_t size)
{
	if (NULL == file)
	{
		return -1;
	}
	if (NULL == array)
	{
		return -1;
	}
	if (type < 0 || type >= OGLE_LITERAL_TYPE_COUNT)
	{
		return -1;
	}
	switch (type)
	{
	case OGLE_LITERAL_TYPE_INT8: return ogle_file_read_i8_array(file, (int8_t*)array, size);
	case OGLE_LITERAL_TYPE_INT16: return ogle_file_read_i16_array(file, (int16_t*)array, size);
	case OGLE_LITERAL_TYPE_INT32: return ogle_file_read_i32_array(file, (int32_t*)array, size);
	case OGLE_LITERAL_TYPE_INT64: return ogle_file_read_i64_array(file, (int64_t*)array, size);
	case OGLE_LITERAL_TYPE_UINT8: return ogle_file_read_u8_array(file, (uint8_t*)array, size);
	case OGLE_LITERAL_TYPE_UINT16: return ogle_file_read_u16_array(file, (uint16_t*)array, size);
	case OGLE_LITERAL_TYPE_UINT32: return ogle_file_read_u32_array(file, (uint32_t*)array, size);
	case OGLE_LITERAL_TYPE_UINT64: return ogle_file_read_u64_array(file, (uint64_t*)array, size);
	case OGLE_LITERAL_TYPE_FLOAT: return ogle_file_read_f32_array(file, (float*)array, size);
	case OGLE_LITERAL_TYPE_DOUBLE: return ogle_file_read_f64_array(file, (double*)array, size);
	default: return -1;
	}
	return -1;
}

static int32_t _ogle_file_load_to_memory(const char* filename, void** data, size_t* size)
{
	if (!filename)
	{
		return -1;
	}

	if (!data)
	{
		return -1;
	}

	if (!size)
	{
		return -1;
	}

	ALLEGRO_FILE* file = al_fopen(filename, "rb");
	if (!file)
	{
		return -1;
	}

	size_t file_size = al_fsize(file);

	void* buffer = al_malloc(file_size);
	if (!buffer)
	{
		al_fclose(file);
		return -1;
	}

	size_t read_size = al_fread(file, buffer, file_size);

	al_fclose(file);

	if (read_size != file_size)
	{
		al_free(buffer);
		return -1;
	}

	*data = buffer;
	*size = file_size;

	return 0;
}

static int32_t _ogle_file_save_from_memory(const char* filename, const void* data, size_t size)
{
	if (!filename)
	{
		return -1;
	}
	if (!data)
	{
		return -1;
	}

	if (size == 0)
	{
		return -1;
	}

	ALLEGRO_FILE* file = al_fopen(filename, "wb");
	if (!file)
	{
		return -1;
	}

	size_t written_size = al_fwrite(file, data, size);

	al_fclose(file);

	if (written_size != size)
	{
		return -1;
	}

	return 0;
}

static int32_t _ogle_save_to_c_array(const char* filename, const char* name, const void* data, size_t size)
{
	if (!filename)
	{
		return -1;
	}

	if (!name)
	{
		return -1;
	}

	if (!data)
	{
		return -1;
	}

	if (size == 0)
	{
		return -1;
	}

	ALLEGRO_FILE* file = al_fopen(filename, "wb");
	if (!file)
	{
		return -1;
	}

	time_t now = time(NULL);
	char time_str[64];
	ctime_s(time_str, sizeof(time_str), &now);

	al_fprintf(file, "// Auto-generated file. Do not edit.\n");
	al_fprintf(file, "// Generated on: %s\n\n", time_str);
	al_fprintf(file, "#include <stdint.h>\n\n");
	al_fprintf(file, "#define %s_SIZE %zu\n\n", name, size);
	al_fprintf(file, "uint8_t %s[%s_SIZE] =\n{\n", name, name);

	const uint8_t* cdata = (const uint8_t*)data;

	for (size_t i = 0; i < size; ++i)
	{
		if (i % 16 == 0)
		{
			al_fprintf(file, "\t");
		}

		al_fprintf(file, "0x%02x", cdata[i]);

		if (i < size - 1)
		{
			al_fprintf(file, ",");
		}

		if ((i + 1) % 16 == 0)
		{
			al_fprintf(file, "\n");
		}
		else
		{
			al_fprintf(file, " ");
		}
	}

	al_fprintf(file, "\n};\n");

	al_fclose(file);

	return 0;
}

int32_t ogle_file_convert_to_c_array(const char* input_filename, const char* output_filename, const char* array_name)
{
	void* data = NULL;
	size_t size = 0;

	if (_ogle_file_load_to_memory(input_filename, &data, &size) != 0)
	{
		return -1;
	}

	int32_t result = _ogle_save_to_c_array(output_filename, array_name, data, size);
	al_free(data);
	return result;
}
