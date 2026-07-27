#ifndef _HEADER_GUARD_OGLE_VECTOR2_H_
#define _HEADER_GUARD_OGLE_VECTOR2_H_

#include "libogle/o_common.h"

typedef struct o_vector2_tag_t
{
	float m_x;
	float m_y;
} o_vector2_t;

o_vector2_t ogle_vector2_zero(void);
o_vector2_t ogle_vector2_ff(float f);
o_vector2_t ogle_vector2_f(float x, float y);
o_vector2_t ogle_vector2(o_vector2_t other);
float ogle_vector2_x(o_vector2_t vector);
float ogle_vector2_y(o_vector2_t vector);
float ogle_vector2_squared_length(o_vector2_t vector);
float ogle_vector2_length(o_vector2_t vector);
float ogle_vector2_distance(o_vector2_t vector1, o_vector2_t vector2);
float ogle_vector2_dot(o_vector2_t vector1, o_vector2_t vector2);
float ogle_vector2_cross(o_vector2_t vector1, o_vector2_t vector2);
o_vector2_t ogle_vector2_add_ff(o_vector2_t vector, float f);
o_vector2_t ogle_vector2_add_f(o_vector2_t vector, float x, float y);
o_vector2_t ogle_vector2_add(o_vector2_t vector1, o_vector2_t vector2);
o_vector2_t ogle_vector2_sub_ff(o_vector2_t vector, float f);
o_vector2_t ogle_vector2_sub_f(o_vector2_t vector, float x, float y);
o_vector2_t ogle_vector2_sub(o_vector2_t vector1, o_vector2_t vector2);
o_vector2_t ogle_vector2_mul_ff(o_vector2_t vector, float f);
o_vector2_t ogle_vector2_mul_f(o_vector2_t vector, float x, float y);
o_vector2_t ogle_vector2_mul(o_vector2_t vector1, o_vector2_t vector2);
o_vector2_t ogle_vector2_div_ff(o_vector2_t vector, float f);
o_vector2_t ogle_vector2_div_f(o_vector2_t vector, float x, float y);
o_vector2_t ogle_vector2_div(o_vector2_t vector1, o_vector2_t vector2);
bool ogle_vector2_equal(o_vector2_t vector1, o_vector2_t vector2);
o_vector2_t ogle_vector2_normalize(o_vector2_t vector);
o_vector2_t ogle_vector2_lerp(o_vector2_t vector1, o_vector2_t vector2, float t);
o_vector2_t ogle_vector2_clamp(o_vector2_t vector, o_vector2_t min, o_vector2_t max);
o_vector2_t ogle_vector2_rotate(o_vector2_t vector, float angle);
o_vector2_t ogle_vector2_perpendicular(o_vector2_t vector);
o_vector2_t ogle_vector2_difference(o_vector2_t vector, o_vector2_t other);
o_vector2_t ogle_vector2_abs(o_vector2_t vector);
ALLEGRO_PRIM_STORAGE ogle_vector2_storage_type(void);
void ogle_vector2_set_shader(const char* var_name, o_vector2_t vector);

#endif // _HEADER_GUARD_OGLE_VECTOR2_H_
