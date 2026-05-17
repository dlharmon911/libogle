#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_math.h"
#include "libogle/o_vector3.h"
#include "libogle/o_mesh.h"

static int32_t _ogle_obj_file_counter(ALLEGRO_FILE* file, o_mesh_data_init_data_t* init_data)
{
	if (!file || !init_data)
	{
		return -1;
	}
	char line[256] = { 0 };

	init_data->m_vertex_count = 0;
	init_data->m_index_count = 0;

	while (al_fgets(file, line, sizeof(line)))
	{
		size_t len = strlen(line);

		if (len < 2)
		{
			continue;
		}

		if (line[0] == 'v' && line[1] == ' ')
		{
			++init_data->m_vertex_count;
		}
		else if (line[0] == 'f' && line[1] == ' ')
		{
			++init_data->m_index_count;
		}
	}

	al_fseek(file, 0, ALLEGRO_SEEK_SET);

	return 0;
}

int32_t _ogle_mesh_data_loader_obj(ALLEGRO_FILE* file, o_mesh_data_t* object)
{
	o_mesh_data_init_data_t init_data =
	{
		.m_vertex_count = 0,
		.m_index_count = 0
	};

	if (!object || !file)
	{
		return -1;
	}

	if (_ogle_obj_file_counter(file, &init_data) < 0)
	{
		return -1;
	}

	if (ogle_mesh_data_initializer(object, &init_data) < 0)
	{
		return -1;
	}

	return 0;
}
