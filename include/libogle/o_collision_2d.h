#ifndef _HEADER_GUARD_OGLE_COLLISION_2D_H_
#define _HEADER_GUARD_OGLE_COLLISION_2D_H_

#include "libogle/o_common.h"
#include "libogle/o_vector2.h"
#include "libogle/o_circle.h"
#include "libogle/o_line.h"

bool ogle_collision_2d_circle_circle(o_circle_t circle1, o_circle_t circle2);
bool ogle_collision_2d_circle_line(o_circle_t circle, o_line_t line);
bool ogle_collision_2d_line_line(o_line_t line1, o_line_t line2);

#endif // _HEADER_GUARD_OGLE_COLLISION_2D_H_
