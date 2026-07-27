#ifndef _HEADER_GUARD_OGLE_CIRCLE_H_
#define _HEADER_GUARD_OGLE_CIRCLE_H_

#include "libogle/o_common.h"
#include "libogle/o_vector2.h"
#include "libogle/o_color.h"

typedef struct o_circle_tag_t
{
	o_vector2_t m_center;
	float m_radius;
} o_circle_t;

void ogle_circle_draw(o_circle_t circle, o_color_t color, float thickness);
void ogle_circle_draw_filled(o_circle_t circle, o_color_t color);
void ogle_circle_draw_bordered(o_circle_t circle, o_color_t color, o_color_t border_color, float border_thickness);

#endif // _HEADER_GUARD_OGLE_CIRCLE_H_
