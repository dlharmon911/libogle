#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_texture.h"

int32_t ogle_texture_create(o_texture_t** texture, const o_texture_data_t* data)
{
	if (NULL == texture)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Texture pointer is null.");
		return -1;
	}
	
	if (NULL == data)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Texture data pointer is null.");
		return -1;
	}
	
	if (NULL == data->m_filename)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Texture filename is null.");
		return -1;
	}
	
	*texture = al_load_bitmap(data->m_filename);
	
	if (NULL == *texture)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Failed to load texture from filename: %s", data->m_filename);
		return -1;
	}
	
	if (data->m_apply_mask)
	{
		al_convert_mask_to_alpha(*texture, al_map_rgb(255, 0, 255));
	}

	return 0;
}

void ogle_texture_destroy(o_texture_t* texture)
{
	if (texture)
	{
		al_destroy_bitmap(texture);
	}
}