#include <allegro5/allegro_memfile.h>
#include <time.h>
#include "libogle/o_common.h"
#include "libogle/o_file.h"

int32_t ogle_file_write_i32(ALLEGRO_FILE* file, int32_t value)
{
	return ogle_file_write_u32_array(file, (const uint32_t*)&value, 1);
}

int32_t ogle_file_write_i32_array(ALLEGRO_FILE* file, const int32_t* array, size_t size)
{
	return ogle_file_write_u32_array(file, (const uint32_t*)array, size);
}

int32_t ogle_file_write_u32(ALLEGRO_FILE* file, uint32_t value)
{
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
	for (size_t i = 0; i < size; ++i)
	{
		if (ogle_file_write_u32(file, array[i]) < 0)
		{
			return -1;
		}
	}

	return 0;
}

int32_t ogle_file_write_float(ALLEGRO_FILE* file, float value)
{
	return ogle_file_write_u32_array(file, (const uint32_t*)&value, 1);
}

int32_t ogle_file_write_float_array(ALLEGRO_FILE* file, const float* array, size_t size)
{
	return ogle_file_write_u32_array(file, (const uint32_t*)array, size);
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
