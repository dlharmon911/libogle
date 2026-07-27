#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_shader.h"

int32_t ogle_shader_create(o_shader_t** shader, const o_shader_data_t* data)
{
	if (NULL == shader)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Texture pointer is null.");
		return -1;
	}

	if (NULL == data)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Texture data pointer is null.");
		return -1;
	}

	if (NULL == data->m_pixel_path)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Shader filename is null.");
		return -1;
	}

	if (!al_filename_exists(data->m_pixel_path))
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Shader file does not exist at filename: %s", data->m_pixel_path);
		return -1;
	}

	if (NULL == data->m_vertex_path)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Shader filename is null.");
		return -1;
	}

	if (!al_filename_exists(data->m_vertex_path))
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Shader file does not exist at filename: %s", data->m_vertex_path);
		return -1;
	}

	*shader = al_create_shader(ALLEGRO_SHADER_GLSL);

	if (NULL == *shader)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Failed to create shader.");
		return -1;
	}

	if (!al_attach_shader_source_file(*shader, ALLEGRO_PIXEL_SHADER, data->m_pixel_path))
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Failed to attach pixel shader from filename: %s", data->m_pixel_path);
		al_destroy_shader(*shader);
		return -1;
	}

	if (!al_attach_shader_source_file(*shader, ALLEGRO_VERTEX_SHADER, data->m_vertex_path))
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Failed to attach vertex shader from filename: %s", data->m_vertex_path);
		al_destroy_shader(*shader);
		return -1;
	}

	if (!al_build_shader(*shader))
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Failed to build shader. Log: %s", al_get_shader_log(*shader));
		al_destroy_shader(*shader);
		return -1;
	}

	return 0;
}

void ogle_shader_destroy(o_shader_t* shader)
{
	if (shader)
	{
		al_destroy_shader(shader);
	}
}
