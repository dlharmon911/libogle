#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_math.h"
#include "libogle/o_vector2.h"
#include "libogle/o_vector3.h"
#include "libogle/o_mesh.h"
#include "libogle/o_darray.h"
#include "libogle/o_utilities.h"

#define OGLE_MESH_DATA_FILE_BYTE_COUNT_PER_LINE 16

static int32_t _ogle_byte_count = 0;

static int32_t _ogle_mesh_data_write_u8(ALLEGRO_FILE* file, uint8_t value)
{
	if (al_fprintf(file, "0x%02x, ", value) < 0)
	{
		return -1;
	}

	++_ogle_byte_count;

	if (_ogle_byte_count == OGLE_MESH_DATA_FILE_BYTE_COUNT_PER_LINE)
	{
		if (al_fprintf(file, "\n\t") < 0)
		{
			return -1;
		}
		_ogle_byte_count = 0;
	}

	return 0;
}


static int32_t _ogle_mesh_data_write_u32(ALLEGRO_FILE* file, uint32_t value)
{
#ifdef ALLEGRO_LITTLE_ENDIAN
	ogle_utilities_swap_bytes(&value, sizeof(value));
#endif

	const uint8_t* bytes = (const uint8_t*)&value;

	for (int i = 0; i < sizeof(value); ++i)
	{
		if (_ogle_mesh_data_write_u8(file, bytes[i]) < 0)
		{
			return -1;
		}
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_f32(ALLEGRO_FILE* file, float value)
{
	const uint32_t* v = (const uint32_t*)&value;
	return _ogle_mesh_data_write_u32(file, *v);
}

static int32_t _ogle_mesh_data_write_color(ALLEGRO_FILE* file, const ALLEGRO_COLOR* vec)
{
	const float* f = (const float*)vec;

	for (int i = 0; i < 4; ++i)
	{
		if (_ogle_mesh_data_write_f32(file, f[i]) < 0)
		{
			return -1;
		}
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_vec3(ALLEGRO_FILE* file, const o_vector3_t* vec)
{
	const float* f = (const float*)vec;

	for (int i = 0; i < 3; ++i)
	{
		if (_ogle_mesh_data_write_f32(file, f[i]) < 0)
		{
			return -1;
		}
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_vec2(ALLEGRO_FILE* file, const o_vector2_t* vec)
{
	const float* f = (const float*)vec;

	for (int i = 0; i < 2; ++i)
	{
		if (_ogle_mesh_data_write_f32(file, f[i]) < 0)
		{
			return -1;
		}
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_vertex(ALLEGRO_FILE* file, const o_vertex_t* vertex)
{
	if (_ogle_mesh_data_write_vec3(file, &vertex->m_position) < 0)
	{
		return -1;
	}

	if (_ogle_mesh_data_write_vec2(file, &vertex->m_uv) < 0)
	{
		return -1;
	}

	if (_ogle_mesh_data_write_vec3(file, &vertex->m_normal) < 0)
	{
		return -1;
	}

	if (_ogle_mesh_data_write_color(file, &vertex->m_color) < 0)
	{
		return -1;
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_vertices(ALLEGRO_FILE* file, const o_vertex_t* vertices, int32_t count)
{
	if (_ogle_mesh_data_write_u32(file, (uint32_t)count) < 0)
	{
		return -1;
	}

	for (int32_t i = 0; i < count; ++i)
	{
		if (_ogle_mesh_data_write_vertex(file, &vertices[i]) < 0)
		{
			return -1;
		}
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_indices(ALLEGRO_FILE* file, const int32_t* indices, int32_t count)
{
	if (_ogle_mesh_data_write_u32(file, (uint32_t)count) < 0)
	{
		return -1;
	}

	for (int32_t i = 0; i < (count - 1); ++i)
	{
		if (_ogle_mesh_data_write_u32(file, (uint32_t)indices[i]) < 0)
		{
			return -1;
		}
	}

	const uint8_t* last_index = (const uint8_t*)&indices[count - 1];

	if (al_fprintf(file, "0x%02x, 0x%02x, 0x%02x, 0x%02x", last_index[0], last_index[1], last_index[2], last_index[3]) < 0)
	{
		return -1;
	}

	return 0;
}

static size_t _ogle_mesh_data_calculate_byte_count(const o_mesh_data_t* mesh_data)
{
	size_t vertex_data_size = sizeof(uint32_t) + (sizeof(o_vertex_t) * mesh_data->m_vertex_count);
	size_t index_data_size = sizeof(uint32_t) + (sizeof(uint32_t) * mesh_data->m_index_count);
	return vertex_data_size + index_data_size;
}

static int32_t _ogle_mesh_data_write_h(ALLEGRO_FILE* file, const char* name, const o_mesh_data_t* mesh_data)
{
	_ogle_byte_count = 0;

	if (al_fprintf(file, "// Mesh data for %s\n// Do not modify manually\n\n", name) < 0)
	{
		return -1;
	}

	size_t byte_count = _ogle_mesh_data_calculate_byte_count(mesh_data);

	if (al_fprintf(file, "#define %s_SIZE %zu\n\n", name, byte_count) < 0)
	{
		return -1;
	}

	if (al_fprintf(file, "const uint8_t %s_DATA[%s_SIZE] =\n{\n\t", name, name) < 0)
	{
		return -1;
	}

	if (_ogle_mesh_data_write_vertices(file, mesh_data->m_vertices, mesh_data->m_vertex_count))
	{
		return -1;
	}

	if (_ogle_mesh_data_write_indices(file, mesh_data->m_indices, mesh_data->m_index_count) < 0)
	{
		return -1;
	}

	if (al_fprintf(file, "\n};\n\n") < 0)
	{
		return -1;
	}

	return 0;
}

int32_t ogle_mesh_data_save_h(const char* filename, const char* name, const o_mesh_data_t* mesh_data)
{
	ALLEGRO_FILE* file = NULL;
	int32_t result = 0;

	if (!filename || !mesh_data || !mesh_data->m_vertices || !mesh_data->m_indices)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid parameters for saving mesh data to file");
		return -1;
	}

	file = al_fopen(filename, "wb");
	if (!file)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to open file for writing mesh data: %s", filename);
		return -1;
	}

	result = _ogle_mesh_data_write_h(file, name, mesh_data);

	al_fclose(file);

	OGLE_DO_LOG(OGLE_LOG_LEVEL_INFO, "Mesh data saved to file: %s", filename);

	return result;
}
