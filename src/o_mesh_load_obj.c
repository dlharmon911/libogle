#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_math.h"
#include "libogle/o_file.h"
#include "libogle/o_vector3.h"
#include "libogle/o_object.h"
#include "libogle/o_char.h"
#include "libogle/o_string.h"
#include "libogle/o_stringview.h"
#include "libogle/o_mesh.h"

#define OGLE_STRING_MAX 1024

static o_stringview_t ogle_read_obj_line(ALLEGRO_FILE* file)
{
	static char _ogle_string[OGLE_STRING_MAX];

	o_stringview_t view = ogle_stringview_file_read_line(file, _ogle_string, OGLE_STRING_MAX);

	view = ogle_stringview_trim_whitespace(view);

	return view;
}

typedef struct o_obj_data_tag_t
{
	int32_t m_vertex_count;
	int32_t m_normal_count;
	int32_t m_texcoord_count;
	int32_t m_face_count;
	o_vector2_t* m_texcoords;
	o_vector3_t* m_normals;
} o_obj_data_t;

static int32_t ogle_obj_data_get_counts(ALLEGRO_FILE* file, o_obj_data_t* obj_data)
{
	if (file == NULL || obj_data == NULL)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid arguments to %s", __func__);
		return -1;
	}
	o_stringview_t line;

	while (!al_feof(file))
	{
		line = ogle_read_obj_line(file);

		if (ogle_stringview_cstr_starts_with(line, "v "))
		{
			obj_data->m_vertex_count++;
		}
		else if (ogle_stringview_cstr_starts_with(line, "vn "))
		{
			obj_data->m_normal_count++;
		}
		else if (ogle_stringview_cstr_starts_with(line, "vt "))
		{
			obj_data->m_texcoord_count++;
		}
		else if (ogle_stringview_cstr_starts_with(line, "f "))
		{
			obj_data->m_face_count++;
		}
	}

	al_fseek(file, 0, ALLEGRO_SEEK_SET);

	return 0;
}

static int32_t ogle_obj_data_zero(o_obj_data_t* obj_data)
{
	if (obj_data == NULL)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid argument to %s", __func__);
		return -1;
	}

	obj_data->m_vertex_count = 0;
	obj_data->m_normal_count = 0;
	obj_data->m_texcoord_count = 0;
	obj_data->m_face_count = 0;
	obj_data->m_texcoords = NULL;
	obj_data->m_normals = NULL;

	return 0;
}

static int32_t _ogle_obj_data_initializer(o_obj_data_t* obj_data, void* data)
{
	if (obj_data == NULL || data == NULL)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid argument to %s", __func__);
		return -1;
	}

	ALLEGRO_FILE* file = (ALLEGRO_FILE*)data;

	if (ogle_obj_data_get_counts(file, obj_data) != 0)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to get counts from OBJ file");
		return -1;
	}

	return 0;
}

static void ogle_obj_data_unitializer(o_obj_data_t* obj_data)
{
	if (obj_data == NULL)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid argument to %s", __func__);
		return;
	}

	if (obj_data->m_texcoords)
	{
		free(obj_data->m_texcoords);
		obj_data->m_texcoords = NULL;
	}

	if (obj_data->m_normals)
	{
		free(obj_data->m_normals);
		obj_data->m_normals = NULL;
	}
}

static int32_t ogle_obj_data_initializer(o_obj_data_t* obj_data, void* data)
{
	if (obj_data == NULL || data == NULL)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid argument to %s", __func__);
		return -1;
	}

	ogle_obj_data_zero(obj_data);

	if (_ogle_obj_data_initializer(obj_data, data) != 0)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to initialize OBJ data");
		ogle_obj_data_unitializer(obj_data);
		return -1;
	}

	return 0;
}

int32_t ogle_mesh_data_load_obj_f(ALLEGRO_FILE* file, o_mesh_data_t* mesh_data)
{
	if (file == NULL || mesh_data == NULL)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid arguments to %s", __func__);
		return -1;
	}

	o_obj_data_t* obj_data = ogle_object_create(sizeof(o_obj_data_t), ogle_obj_data_initializer, file);
	if (obj_data == NULL)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to create OBJ data object");
		return -1;
	}



	ogle_object_destroy(obj_data, ogle_obj_data_unitializer);

	return 0;
}

int32_t ogle_mesh_data_load_obj(const char* filename, o_mesh_data_t* mesh_data)
{
	if (filename == NULL || mesh_data == NULL)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid arguments to %s", __func__);
		return -1;
	}

	ALLEGRO_FILE* file = al_fopen(filename, "rb");
	int32_t result = 0;

	if (!file)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Failed to open OBJ file: %s", filename);
		return -1;
	}

	result = ogle_mesh_data_load_obj_f(file, mesh_data);

	al_fclose(file);

	return result;
}