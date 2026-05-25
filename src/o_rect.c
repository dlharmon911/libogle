#include "libogle/o_common.h"
#include "libogle/o_color.h"
#include "libogle/o_vector2.h"
#include "libogle/o_rect.h"

void ogle_rect_draw_gradient(ALLEGRO_SHADER* shader, o_vector2_t pos, o_vector2_t size, o_color_t color_a, o_color_t color_b, int32_t direction)
{
	if (!shader)
	{
		return;
	}

	if (direction < 0 || direction >= OGLE_RECT_GRADIENT_DIRECTION_COUNT)
	{
		direction = 0;
	}

	ALLEGRO_BITMAP* target = al_get_target_bitmap();
	o_vector2_t resolution = { (float)al_get_bitmap_width(target), (float)al_get_bitmap_height(target) };

	al_use_shader(shader);
	al_set_shader_int("u_direction", direction);
	al_set_shader_float_vector("u_position", 2, &pos.m_x, 1);
	al_set_shader_float_vector("u_resolution", 2, &resolution.m_x, 1);
	al_set_shader_float_vector("u_size", 2, &size.m_x, 1);
	al_set_shader_float_vector("u_color_a", 3, &color_a.r, 1);
	al_set_shader_float_vector("u_color_b", 3, &color_b.r, 1);
	al_draw_filled_rectangle(pos.m_x, pos.m_y, size.m_x, size.m_y, al_map_rgb(0, 0, 0));
	al_use_shader(NULL);
}

void ogle_rect_draw_rounded(o_vector2_t pos, o_vector2_t size, float radius, o_color_t background_color)
{
	al_draw_filled_rounded_rectangle(pos.m_x, pos.m_y, pos.m_x + size.m_x, pos.m_y + size.m_y, radius, radius, background_color);
}

void ogle_rect_draw_rounded_bordered(o_vector2_t pos, o_vector2_t size, float radius, o_color_t background_color, o_color_t border_color, float border_thickness)
{
	al_draw_filled_rounded_rectangle(pos.m_x, pos.m_y, pos.m_x + size.m_x, pos.m_y + size.m_y, radius, radius, background_color);
	al_draw_rounded_rectangle(pos.m_x, pos.m_y, pos.m_x + size.m_x, pos.m_y + size.m_y, radius, radius, border_color, border_thickness);
}
