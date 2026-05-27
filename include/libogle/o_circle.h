#ifndef _HEADER_GUARD_OGLE_CIRCLE_H_
#define _HEADER_GUARD_OGLE_CIRCLE_H_

#include "libogle/o_common.h"
#include "libogle/o_vector2.h"
#include "libogle/o_color.h"

void ogle_circle_draw(o_vector2_t center, float radius, o_color_t color, float thickness);
void ogle_circle_draw_filled(o_vector2_t center, float radius, o_color_t color);
void ogle_circle_draw_bordered(o_vector2_t center, float radius, o_color_t color, o_color_t border_color, float border_thickness);

#endif // _HEADER_GUARD_OGLE_CIRCLE_H_
