#include "libogle/o_common.h"
#include "libogle/o_math.h"
#include "libogle/o_vector2.h"
#include "libogle/o_circle.h"
#include "libogle/o_line.h"
#include "libogle/o_collision_2d.h"

bool ogle_collision_2d_circle_circle(o_circle_t circle1, o_circle_t circle2)
{
	o_vector2_t center_distance_vector = ogle_vector2_sub(circle1.m_center, circle2.m_center);
	float center_distance_squared = ogle_vector2_squared_length(center_distance_vector);
	float radius_sum = circle1.m_radius + circle2.m_radius;
	return center_distance_squared <= (radius_sum * radius_sum);
}

bool ogle_collision_2d_circle_line(o_circle_t circle, o_line_t line)
{
	o_vector2_t closest_point = ogle_line_closest_point(line, circle.m_center);
	o_vector2_t distance_vector = ogle_vector2_sub(circle.m_center, closest_point);
	float distance_squared = ogle_vector2_squared_length(distance_vector);
	return distance_squared <= (circle.m_radius * circle.m_radius);
}

bool ogle_collision_2d_line_line(o_line_t line1, o_line_t line2)
{
	o_vector2_t p = line1.m_start;
	o_vector2_t r = ogle_vector2_sub(line1.m_end, line1.m_start);
	o_vector2_t q = line2.m_start;
	o_vector2_t s = ogle_vector2_sub(line2.m_end, line2.m_start);
	float r_cross_s = ogle_vector2_cross(r, s);
	o_vector2_t q_minus_p = ogle_vector2_sub(q, p);
	float q_minus_p_cross_r = ogle_vector2_cross(q_minus_p, r);
	if (ogle_math_is_equal_f(r_cross_s, 0.0f))
	{
		if (ogle_math_is_equal_f(q_minus_p_cross_r, 0.0f))
		{
			// Lines are collinear
			return false; // For simplicity, we return false for collinear lines
		}
		else
		{
			// Lines are parallel and non-intersecting
			return false;
		}
	}
	float t = ogle_vector2_cross(q_minus_p, s) / r_cross_s;
	float u = q_minus_p_cross_r / r_cross_s;
	return (t >= 0.0f && t <= 1.0f) && (u >= 0.0f && u <= 1.0f);
}
