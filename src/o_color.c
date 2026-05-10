#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_color.h"

o_color_t ogle_color_map_rgb_u32(uint32_t rgb)
{
	return al_map_rgb((rgb & 0xff0000) >> 16, (rgb & 0x00ff00) >> 8, (rgb & 0x0000ff));
}

uint32_t ogle_color_unmap_rgb_u32(o_color_t color)
{
	uint8_t r, g, b;
	al_unmap_rgb(color, &r, &g, &b);
	return ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
}

o_color_t ogle_color_map_rgba_u32(uint32_t rgba)
{
	return al_map_rgba((rgba & 0xff000000) >> 24, (rgba & 0x00ff0000) >> 16, (rgba & 0x0000ff00) >> 8, (rgba & 0x000000ff));
}

uint32_t ogle_color_unmap_rgba_u32(o_color_t color)
{
	uint8_t r, g, b, a;
	al_unmap_rgba(color, &r, &g, &b, &a);
	return ((uint32_t)r << 24) | ((uint32_t)g << 16) | ((uint32_t)b << 8) | (uint32_t)a;
}

o_color_t ogle_color_map_rgb_array_u8(const uint8_t* array)
{
	if (!array)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid argument(s) passed to ogle_color_map_rgb_array_u8");
		return OGLE_COLOR_BLACK;
	}

	return al_map_rgb(array[0], array[1], array[2]);
}

void ogle_color_unmap_rgb_array_u8(o_color_t color, uint8_t* array)
{
	if (!array)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid argument(s) passed to ogle_color_unmap_rgb_array_u8");
		return;
	}

	al_unmap_rgb(color, &array[0], &array[1], &array[2]);
}

o_color_t ogle_color_map_rgba_array_u8(const uint8_t* array)
{
	if (!array)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid argument(s) passed to ogle_color_map_rgba_array_u8");
		return OGLE_COLOR_BLACK;
	}

	return al_map_rgba(array[0], array[1], array[2], array[3]);
}

void ogle_color_unmap_rgba_array_u8(o_color_t color, uint8_t* array)
{
	if (!array)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Invalid argument(s) passed to ogle_color_unmap_rgba_array_u8");
		return;
	}

	al_unmap_rgba(color, &array[0], &array[1], &array[2], &array[3]);
}

void ogle_color_set_shader(const char* var_name, o_color_t color)
{
	al_set_shader_float_vector(var_name, 4, (const float*)&color, 1);
}
