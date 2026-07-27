#ifndef _HEADER_GUARD_OGLE_VECTOR3_H_
#define _HEADER_GUARD_OGLE_VECTOR3_H_

#include "libogle/o_common.h"
#include "libogle/o_vector2.h"

typedef struct o_vector3_tag_t
{
	float m_x;
	float m_y;
	float m_z;
} o_vector3_t;

o_vector3_t ogle_vector3_zero(void);
o_vector3_t ogle_vector3_ff(float f);
o_vector3_t ogle_vector3_f(float x, float y, float z);
o_vector3_t ogle_vector3(o_vector3_t other);
o_vector2_t ogle_vector3_xy(o_vector3_t vector);
float ogle_vector3_x(o_vector3_t vector);
float ogle_vector3_y(o_vector3_t vector);
float ogle_vector3_z(o_vector3_t vector);
float ogle_vector3_squared_length(o_vector3_t vector);
float ogle_vector3_length(o_vector3_t vector);
float ogle_vector3_distance(o_vector3_t vector1, o_vector3_t vector2);
float ogle_vector3_dot(o_vector3_t vector1, o_vector3_t vector2);
o_vector3_t ogle_vector3_cross(o_vector3_t vector1, o_vector3_t vector2);
o_vector3_t ogle_vector3_add_ff(o_vector3_t vector, float f);
o_vector3_t ogle_vector3_add_f(o_vector3_t vector, float x, float y, float z);
o_vector3_t ogle_vector3_add(o_vector3_t vector1, o_vector3_t vector3);
o_vector3_t ogle_vector3_sub_ff(o_vector3_t vector, float f);
o_vector3_t ogle_vector3_sub_f(o_vector3_t vector, float x, float y, float z);
o_vector3_t ogle_vector3_sub(o_vector3_t vector1, o_vector3_t vector3);
o_vector3_t ogle_vector3_mul_ff(o_vector3_t vector, float f);
o_vector3_t ogle_vector3_mul_f(o_vector3_t vector, float x, float y, float z);
o_vector3_t ogle_vector3_mul(o_vector3_t vector1, o_vector3_t vector3);
o_vector3_t ogle_vector3_div_ff(o_vector3_t vector, float f);
o_vector3_t ogle_vector3_div_f(o_vector3_t vector, float x, float y, float z);
o_vector3_t ogle_vector3_div(o_vector3_t vector1, o_vector3_t vector2);
bool ogle_vector3_equal(o_vector3_t vector1, o_vector3_t vector2);
o_vector3_t ogle_vector3_normalize(o_vector3_t vector);
o_vector3_t ogle_vector3_lerp(o_vector3_t vector1, o_vector3_t vector2, float t);
o_vector3_t ogle_vector3_clamp(o_vector3_t vector, o_vector3_t min, o_vector3_t max);
o_vector3_t ogle_vector3_rotate_xy(o_vector3_t vector, float angle);
o_vector3_t ogle_vector3_rotate_xz(o_vector3_t vector, float angle);
o_vector3_t ogle_vector3_rotate_yz(o_vector3_t vector, float angle);
o_vector3_t ogle_vector3_difference(o_vector3_t vector, o_vector3_t other);
o_vector3_t ogle_vector3_abs(o_vector3_t vector);
ALLEGRO_PRIM_STORAGE ogle_vector3_storage_type(void);
void ogle_vector3_set_shader(const char* var_name, o_vector3_t vector);
o_vector3_t ogle_vector3_rotate_axis(o_vector3_t v, o_vector3_t axis, float angle_deg);

#endif // _HEADER_GUARD_OGLE_VECTOR3_H_
