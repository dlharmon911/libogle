#include "libogle/o_common.h"
#include "libogle/o_vector2.h"
#include "libogle/o_color.h"
#include "libogle/o_circle.h"

void ogle_circle_draw(o_circle_t circle, o_color_t color, float thickness)
{
	al_draw_circle(circle.m_center.m_x, circle.m_center.m_y, circle.m_radius, color, thickness);
}

void ogle_circle_draw_filled(o_circle_t circle, o_color_t color)
{
	al_draw_filled_circle(circle.m_center.m_x, circle.m_center.m_y, circle.m_radius, color);
}

void ogle_circle_draw_bordered(o_circle_t circle, o_color_t color, o_color_t border_color, float border_thickness)
{
	al_draw_filled_circle(circle.m_center.m_x, circle.m_center.m_y, circle.m_radius, color);
	al_draw_circle(circle.m_center.m_x, circle.m_center.m_y, circle.m_radius, border_color, border_thickness);
}
