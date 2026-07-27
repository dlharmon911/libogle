#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_font.h"

int32_t ogle_font_create(o_font_t** font, const o_font_data_t* data)
{
	if (NULL == font)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Font pointer is null.");
		return -1;
	}

	if (NULL == data)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Font data pointer is null.");
		return -1;
	}

	if (data->m_type == OGLE_FONT_TYPE_BUILTIN)
	{
		*font = al_create_builtin_font();
		if (NULL == *font)
		{
			ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Failed to load font from filename: %s", data->m_filename);
			return -1;
		}
		return 0;
	}

	if (NULL == data->m_filename)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Font filename is null.");
		return -1;
	}

	if (0 == data->m_size)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Font size cannot be zero.");
		return -1;
	}

	if (data->m_type < 0 || data->m_type >= OGLE_FONT_TYPE_COUNT)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Unsupported font type: %d", data->m_type);
		return -1;
	}

	if (data->m_type == OGLE_FONT_TYPE_TTF)
	{
		*font = al_load_ttf_font(data->m_filename, data->m_size, data->m_flags);
	}
	else if (data->m_type == OGLE_FONT_TYPE_BITMAP)
	{
		*font = al_load_font(data->m_filename, data->m_size, data->m_flags);
	}

	if (NULL == *font)
	{
		ogle_do_log(OGLE_LOG_LEVEL_ERROR, "Failed to load font from filename: %s", data->m_filename);
		return -1;
	}

	return 0;
}

void ogle_font_destroy(o_font_t* font)
{
	if (font)
	{
		al_destroy_font(font);
	}
}
