#ifndef _HEADER_GUARD_OGLE_COLOR_H_
#define _HEADER_GUARD_OGLE_COLOR_H_

#include "libogle/o_common.h"

typedef ALLEGRO_COLOR o_color_t;

#define OGLE_COLOR_WHITE al_map_rgba_f(1.0f, 1.0f, 1.0f, 1.0f)
#define OGLE_COLOR_BLACK al_map_rgba_f(0.0f, 0.0f, 0.0f, 1.0f)
#define OGLE_COLOR_EIGENGRAU al_map_rgba_f(0.0862745f, 0.0862745f, 0.12941176, 1.0f)

o_color_t ogle_color_map_rgb_u32(uint32_t rgb);
uint32_t ogle_color_unmap_rgb_u32(o_color_t color);
o_color_t ogle_color_map_rgba_u32(uint32_t rgba);
uint32_t ogle_color_unmap_rgba_u32(o_color_t color);


o_color_t ogle_color_map_rgb_array_u8(const uint8_t* array);
void ogle_color_unmap_rgb_array_u8(o_color_t color, uint8_t* array);
o_color_t ogle_color_map_rgba_array_u8(const uint8_t* array);
void ogle_color_unmap_rgba_array_u8(o_color_t color, uint8_t* array);
void ogle_color_set_shader(const char* var_name, o_color_t color);

#endif // _HEADER_GUARD_OGLE_COLOR_H_
