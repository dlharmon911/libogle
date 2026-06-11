#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_math.h"
#include "libogle/o_file.h"
#include "libogle/o_vector2.h"
#include "libogle/o_vector3.h"
#include "libogle/o_mesh.h"
#include "libogle/o_darray.h"
#include "libogle/o_utilities.h"


static int32_t _ogle_mesh_data_write_bin_vertex(ALLEGRO_FILE* file, const o_vertex_t* vertex)
{
	if (!file || !vertex)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid parameters for writing vertex to file");
		return -1;
	}

	//if (ogle_file_write_float_array(file, &vertex->m_position.m_x, sizeof(vertex->m_position) / sizeof(float)) < 0)
	//{
	//	OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to write vertex position to file");
	//	return -1;
	//}

	//if (ogle_file_write_float_array(file, &vertex->m_uv.m_x, sizeof(vertex->m_uv) / sizeof(float)) < 0)
	//{
	//	OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to write vertex UV coordinates to file");
	//	return -1;
	//}

	//if (ogle_file_write_float_array(file, &vertex->m_normal.m_x, sizeof(vertex->m_normal) / sizeof(float)) < 0)
	//{
	//	OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to write vertex normal to file");
	//	return -1;
	//}

	//if (ogle_file_write_float_array(file, &vertex->m_color.r, sizeof(vertex->m_color) / sizeof(float)) < 0)
	//{
	//	OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to write vertex color to file");
	//	return -1;
	//}

	return 0;
}

static int32_t _ogle_mesh_data_write_bin_vertices(ALLEGRO_FILE* file, const o_vertex_t* vertices, int32_t count)
{
	if (!file || !vertices || count <= 0)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid parameters for writing vertices to file");
		return -1;
	}

	if (ogle_file_write_i32(file, count) < 0)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to write vertex count to file");
		return -1;
	}

	for (int32_t i = 0; i < count; ++i)
	{
		if (_ogle_mesh_data_write_bin_vertex(file, vertices + i) < 0)
		{
			OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to write vertex to file");
			return -1;
		}
	}

	return 0;
}

static int32_t _ogle_mesh_data_write_bin_faces(ALLEGRO_FILE* file, const int32_t* indices, int32_t count)
{
	if (!file || !indices || count <= 0)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid parameters for writing faces to file");
		return -1;
	}

	if (ogle_file_write_i32(file, count) < 0)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to write face index count to file");
		return -1;
	}

	for (int32_t i = 0; i < count; ++i)
	{
		if (ogle_file_write_i32(file, indices[i]) < 0)
		{
			OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to write face index to file");
			return -1;
		}
	}

	return 0;
}

int32_t ogle_mesh_data_save_bin_f(ALLEGRO_FILE* file, const o_mesh_data_t* mesh_data)
{
	if (!file || !mesh_data || !mesh_data->m_vertices || !mesh_data->m_indices)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid parameters for saving mesh data to file");
		return -1;
	}

	if (_ogle_mesh_data_write_bin_vertices(file, mesh_data->m_vertices, mesh_data->m_vertex_count) < 0)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to write vertices to file");
		return -1;
	}

	if (_ogle_mesh_data_write_bin_faces(file, mesh_data->m_indices, mesh_data->m_index_count) < 0)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to write faces to file");
		return -1;
	}

	return 0;
}

int32_t ogle_mesh_data_save_bin(const char* filename, const o_mesh_data_t* mesh_data)
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

	result = ogle_mesh_data_save_bin_f(file, mesh_data);

	al_fclose(file);

	OGLE_DO_LOG(OGLE_LOG_LEVEL_INFO, "Mesh data saved to file: %s", filename);

	return result;
}
