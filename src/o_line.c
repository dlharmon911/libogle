#include "libogle/o_common.h"
#include "libogle/o_math.h"
#include "libogle/o_vector2.h"
#include "libogle/o_color.h"
#include "libogle/o_line.h"

o_line_t ogle_line_create(o_vector2_t start, o_vector2_t end)
{
	return (o_line_t) { .m_start = start, .m_end = end };
}

o_line_t ogle_line_create_f(float start_x, float start_y, float end_x, float end_y)
{
	return (o_line_t) { .m_start = (o_vector2_t){ .m_x = start_x, .m_y = start_y }, .m_end = (o_vector2_t){ .m_x = end_x, .m_y = end_y } };
}

void ogle_line_draw(o_line_t line, o_color_t color, float thickness)
{
	al_draw_line(line.m_start.m_x, line.m_start.m_y, line.m_end.m_x, line.m_end.m_y, color, thickness);
}

o_vector2_t ogle_line_center(o_line_t line)
{
	return ogle_vector2_mul_ff(ogle_vector2_add(line.m_start, line.m_end), 0.5f);
}

o_vector2_t ogle_line_normal(o_line_t line)
{
	o_vector2_t direction = ogle_line_direction(line);
	return ogle_vector2_normalize((o_vector2_t){-direction.m_y, direction.m_x});
}

o_vector2_t ogle_line_direction(o_line_t line)
{
	return ogle_vector2_normalize(ogle_vector2_sub(line.m_end, line.m_start));
}

o_vector2_t ogle_line_closest_point(o_line_t line, o_vector2_t point)
{
	o_vector2_t line_direction = ogle_line_direction(line);
	o_vector2_t line_to_point = ogle_vector2_sub(point, line.m_start);
	float t = ogle_vector2_dot(line_to_point, line_direction);
	t = ogle_math_clamp_f(t, 0.0f, ogle_vector2_length(ogle_vector2_sub(line.m_end, line.m_start)));
	return ogle_vector2_add(line.m_start, ogle_vector2_mul_ff(line_direction, t));
}

o_vector2_t ogle_line_distance_vector(o_line_t line, o_vector2_t point)
{
	o_vector2_t closest_point = ogle_line_closest_point(line, point);
	return ogle_vector2_sub(point, closest_point);
}
