#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_math.h"
#include "libogle/o_vector2.h"
#include "libogle/o_vector3.h"
#include "libogle/o_mesh.h"
#include "libogle/o_darray.h"
#include "libogle/o_utilities.h"

#define OGLE_MESH_DATA_FILE_BYTE_COUNT_PER_LINE 16
static const char* OGLE_MESH_DATA_OBJ_HEADER = "# OBJ mesh data: %s\n# Do not hand edit!\n\n";
#define OGLE_MESH_DATA_EPSILON 0.000001f

static bool _ogle_mesh_data_is_normal_unique(o_vector3_t normal, const o_vertex_t* vertices, int32_t vcount)
{
	for (int32_t i = 0; i < vcount; ++i)
	{
		if (fabsf(normal.m_x - vertices[i].m_normal.m_x) <= OGLE_MESH_DATA_EPSILON &&
			fabsf(normal.m_y - vertices[i].m_normal.m_y) <= OGLE_MESH_DATA_EPSILON &&
			fabsf(normal.m_z - vertices[i].m_normal.m_z) <= OGLE_MESH_DATA_EPSILON)
		{
			return false;
		}
	}

	return true;
}

static bool _ogle_mesh_data_is_uv_unique(o_vector2_t uv, const o_vertex_t* vertices, int32_t vcount)
{
	for (int32_t i = 0; i < vcount; ++i)
	{
		if (fabsf(uv.m_x - vertices[i].m_uv.m_x) <= OGLE_MESH_DATA_EPSILON &&
			fabsf(uv.m_y - vertices[i].m_uv.m_y) <= OGLE_MESH_DATA_EPSILON)
		{
			return false;
		}
	}

	return true;
}

static int32_t _ogle_mesh_data_write_normal(ALLEGRO_FILE* file, o_vector3_t normal)
{
	if (al_fprintf(file, "vn %f %f %f\n", normal.m_x, normal.m_y, normal.m_z) < 0)
	{
		return -1;
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_uv(ALLEGRO_FILE* file, o_vector2_t uv)
{
	if (al_fprintf(file, "vt %f %f\n", uv.m_x, uv.m_y) < 0)
	{
		return -1;
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_uv_coordinates(ALLEGRO_FILE* file, const o_vertex_t* vertices, int32_t count)
{
	int32_t uv_count = 1;
	_ogle_mesh_data_write_uv(file, vertices[0].m_uv);

	for (int32_t i = 1; i < count; ++i)
	{
		if (!_ogle_mesh_data_is_uv_unique(vertices[i].m_uv, vertices, i))
		{
			continue;
		}

		if (_ogle_mesh_data_write_uv(file, vertices[i].m_uv) < 0)
		{
			return -1;
		}

		++uv_count;
	}

	if (al_fprintf(file, "# %d UV coordinates\n\n", uv_count) < 0)
	{
		return -1;
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_normals(ALLEGRO_FILE* file, const o_vertex_t* vertices, int32_t count)
{
	int32_t normal_count = 1;
	_ogle_mesh_data_write_normal(file, vertices[0].m_normal);

	for (int32_t i = 1; i < count; ++i)
	{
		if (!_ogle_mesh_data_is_normal_unique(vertices[i].m_normal, vertices, i))
		{
			continue;
		}

		if (_ogle_mesh_data_write_normal(file, vertices[i].m_normal) < 0)
		{
			return -1;
		}

		++normal_count;
	}

	if (al_fprintf(file, "# %d normals\n\n", normal_count) < 0)
	{
		return -1;
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_vertex(ALLEGRO_FILE* file, const o_vertex_t* vertex)
{
	if (al_fprintf(file, "v %f %f %f ", vertex->m_position.m_x, vertex->m_position.m_y, vertex->m_position.m_z) < 0)
	{
		return -1;
	}
	
	if (al_fprintf(file, "%f %f %f\n", vertex->m_color.r, vertex->m_color.g, vertex->m_color.b) < 0)
	{
		return -1;
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_vertices(ALLEGRO_FILE* file, const o_vertex_t* vertices, int32_t count)
{
	for (int32_t i = 0; i < count; ++i)
	{
		if (_ogle_mesh_data_write_vertex(file, vertices + i) < 0)
		{
			return -1;
		}
	}

	if (al_fprintf(file, "# %d vertices\n\n", count) < 0)
	{
		return -1;
	}

	return 0;
}

static int32_t _ogle_mesh_data_get_normal_index(o_vector3_t normal, const o_vertex_t* vertices, int32_t vertex_count)
{
	int32_t normal_index = 1;

	for (int32_t i = 0; i < vertex_count; ++i)
	{
		if (!_ogle_mesh_data_is_normal_unique(vertices[i].m_normal, vertices, i))
		{
			continue;
		}

		if (fabsf(normal.m_x - vertices[i].m_normal.m_x) <= OGLE_MESH_DATA_EPSILON &&
			fabsf(normal.m_y - vertices[i].m_normal.m_y) <= OGLE_MESH_DATA_EPSILON &&
			fabsf(normal.m_z - vertices[i].m_normal.m_z) <= OGLE_MESH_DATA_EPSILON)
		{
			return normal_index;
		}

		++normal_index;
	}

	return normal_index;
}

static int32_t _ogle_mesh_data_get_uv_index(o_vector2_t uv, const o_vertex_t* vertices, int32_t vertex_count)
{
	int32_t uv_index = 1;

	for (int32_t i = 0; i < vertex_count; ++i)
	{
		if (!_ogle_mesh_data_is_uv_unique(vertices[i].m_uv, vertices, i))
		{
			continue;
		}

		if (fabsf(uv.m_x - vertices[i].m_uv.m_x) <= OGLE_MESH_DATA_EPSILON &&
			fabsf(uv.m_y - vertices[i].m_uv.m_y) <= OGLE_MESH_DATA_EPSILON)
		{
			return uv_index;
		}

		++uv_index;
	}

	return 1;
}

static int32_t _ogle_mesh_data_write_face_index(ALLEGRO_FILE* file, const o_mesh_data_t* mesh_data, int32_t face_index)
{
	int32_t index = mesh_data->m_indices[face_index];
	o_vector2_t uv = mesh_data->m_vertices[index].m_uv;
	o_vector3_t normal = mesh_data->m_vertices[index].m_normal;

	int32_t vertex_index = 1 + index;
	int32_t uv_index = _ogle_mesh_data_get_uv_index(uv, mesh_data->m_vertices, mesh_data->m_vertex_count);
	int32_t normal_index = _ogle_mesh_data_get_normal_index(normal, mesh_data->m_vertices, mesh_data->m_vertex_count);

	if (al_fprintf(file, " %d/%d/%d", vertex_index, uv_index, normal_index) < 0)
	{
		return -1;
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_faces(ALLEGRO_FILE* file, const o_mesh_data_t* mesh_data)
{
	for (int32_t i = 0; i < mesh_data->m_index_count; i += 3)
	{
		if (al_fprintf(file, "f") < 0)
		{
			return -1;
		}

		for (int32_t j = 0; j < 3; ++j)
		{
			if (_ogle_mesh_data_write_face_index(file, mesh_data, i + j) < 0)
			{
				return -1;
			}
		}

		if (al_fprintf(file, "\n") < 0)
		{
			return -1;
		}
	}
	
	if (al_fprintf(file, "# %d faces\n\n", mesh_data->m_index_count / 3) < 0)
	{
		return -1;
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_obj(ALLEGRO_FILE* file, const char* name, const o_mesh_data_t* mesh_data)
{
	if (al_fprintf(file, OGLE_MESH_DATA_OBJ_HEADER, name) < 0)
	{
		return -1;
	}

	if (_ogle_mesh_data_write_vertices(file, mesh_data->m_vertices, mesh_data->m_vertex_count) < 0)
	{
		return -1;
	}

	if (_ogle_mesh_data_write_uv_coordinates(file, mesh_data->m_vertices, mesh_data->m_vertex_count) < 0)
	{
		return -1;
	}

	if (_ogle_mesh_data_write_normals(file, mesh_data->m_vertices, mesh_data->m_vertex_count) < 0)
	{
		return -1;
	}

	if (_ogle_mesh_data_write_faces(file, mesh_data) < 0)
	{
		return -1;
	}

	return 0;
}

int32_t ogle_mesh_data_save_obj(const char* filename, const char* name, const o_mesh_data_t* mesh_data)
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

	result = _ogle_mesh_data_write_obj(file, name, mesh_data);

	al_fclose(file);

	OGLE_DO_LOG(OGLE_LOG_LEVEL_INFO, "Mesh data saved to file: %s", filename);

	return result;
}
