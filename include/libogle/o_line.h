#ifndef _HEADER_GUARD_OGLE_LINE_H_
#define _HEADER_GUARD_OGLE_LINE_H_

#include "libogle/o_common.h"
#include "libogle/o_vector2.h"
#include "libogle/o_color.h"

#define OGLE_LINE_POINT_COUNT 2

typedef struct o_line_tag_t
{
	union
	{
		struct
		{
			o_vector2_t m_start;
			o_vector2_t m_end;
		};
		o_vector2_t m_point[OGLE_LINE_POINT_COUNT];
	};
} o_line_t;

o_line_t ogle_line_create(o_vector2_t start, o_vector2_t end);
o_line_t ogle_line_create_f(float start_x, float start_y, float end_x, float end_y);
void ogle_line_draw(o_line_t line, o_color_t color, float thickness);
o_vector2_t ogle_line_center(o_line_t line);
o_vector2_t ogle_line_normal(o_line_t line);
o_vector2_t ogle_line_direction(o_line_t line);
o_vector2_t ogle_line_closest_point(o_line_t line, o_vector2_t point);
o_vector2_t ogle_line_distance_vector(o_line_t line, o_vector2_t point);

#endif // _HEADER_GUARD_OGLE_LINE_H_
