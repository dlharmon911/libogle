#include "libogle/o_common.h"
#include "libogle/o_vector2.h"
#include "libogle/o_color.h"
#include "libogle/o_circle.h"

void ogle_circle_draw(o_vector2_t center, float radius, o_color_t color, float thickness)
{
	al_draw_circle(center.m_x, center.m_y, radius, color, thickness);
}

void ogle_circle_draw_filled(o_vector2_t center, float radius, o_color_t color)
{
	al_draw_filled_circle(center.m_x, center.m_y, radius, color);
}

void ogle_circle_draw_bordered(o_vector2_t center, float radius, o_color_t color, o_color_t border_color, float border_thickness)
{
	al_draw_filled_circle(center.m_x, center.m_y, radius, color);
	al_draw_circle(center.m_x, center.m_y, radius, border_color, border_thickness);
}
