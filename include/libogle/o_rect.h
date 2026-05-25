#ifndef _HEADER_GUARD_OGLE_RECT_H_
#define _HEADER_GUARD_OGLE_RECT_H_

#include "libogle/o_common.h"
#include "libogle/o_color.h"
#include "libogle/o_vector2.h"

enum OGLE_RECT_GRADIENT_DIRECTION
{
	OGLE_RECT_GRADIENT_DIRECTION_LEFT_TO_RIGHT,
	OGLE_RECT_GRADIENT_DIRECTION_TOP_TO_BOTTOM,
	OGLE_RECT_GRADIENT_DIRECTION_RIGHT_TO_LEFT,
	OGLE_RECT_GRADIENT_DIRECTION_BOTTOM_TO_TOP,
	OGLE_RECT_GRADIENT_DIRECTION_TOP_LEFT_TO_BOTTOM_RIGHT,
	OGLE_RECT_GRADIENT_DIRECTION_TOP_RIGHT_TO_BOTTOM_LEFT,
	OGLE_RECT_GRADIENT_DIRECTION_BOTTOM_LEFT_TO_TOP_RIGHT,
	OGLE_RECT_GRADIENT_DIRECTION_BOTTOM_RIGHT_TO_TOP_LEFT,
	OGLE_RECT_GRADIENT_DIRECTION_COUNT
};

void ogle_rect_draw_gradient(ALLEGRO_SHADER* shader, o_vector2_t pos, o_vector2_t size, o_color_t color_a, o_color_t color_b, int32_t direction);
void ogle_rect_draw_rounded(o_vector2_t pos, o_vector2_t size, float radius, o_color_t background_color);
void ogle_rect_draw_rounded_bordered(o_vector2_t pos, o_vector2_t size, float radius, o_color_t background_color, o_color_t border_color, float border_thickness);

#endif // _HEADER_GUARD_OGLE_RECT_H_
