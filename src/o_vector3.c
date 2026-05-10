#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_math.h"
#include "libogle/o_vector2.h"
#include "libogle/o_vector3.h"

o_vector3_t ogle_vector3_zero(void)
{
	return (o_vector3_t) { 0.0f, 0.0f, 0.0f };
}

o_vector3_t ogle_vector3_ff(float f)
{
	return (o_vector3_t) { f, f, f };
}

o_vector3_t ogle_vector3_f(float x, float y, float z)
{
	return (o_vector3_t) { x, y, z };
}

o_vector3_t ogle_vector3(o_vector3_t other)
{
	return other;
}

o_vector2_t ogle_vector3_xy(o_vector3_t vector)
{
	return (o_vector2_t) { vector.m_x, vector.m_y };
}

float ogle_vector3_x(o_vector3_t vector)
{
	return vector.m_x;
}

float ogle_vector3_y(o_vector3_t vector)
{
	return vector.m_y;
}

float ogle_vector3_z(o_vector3_t vector)
{
	return vector.m_z;
}

float ogle_vector3_squared_length(o_vector3_t vector)
{
	return vector.m_x * vector.m_x + vector.m_y * vector.m_y + vector.m_z * vector.m_z;
}

float ogle_vector3_length(o_vector3_t vector)
{
	return sqrtf(ogle_vector3_squared_length(vector));
}

float ogle_vector3_distance(o_vector3_t vector1, o_vector3_t vector2)
{
	return ogle_vector3_length(ogle_vector3_sub(vector1, vector2));
}

float ogle_vector3_dot(o_vector3_t vector1, o_vector3_t vector2)
{
	return vector1.m_x * vector2.m_x + vector1.m_y * vector2.m_y + vector1.m_z * vector2.m_z;
}

o_vector3_t ogle_vector3_cross(o_vector3_t vector1, o_vector3_t vector2)
{
	float x = vector1.m_y * vector2.m_z - vector1.m_z * vector2.m_y;
	float y = vector1.m_z * vector2.m_x - vector1.m_x * vector2.m_z;
	float z = vector1.m_x * vector2.m_y - vector1.m_y * vector2.m_x;

	return (o_vector3_t) { x, y, z };
}

o_vector3_t ogle_vector3_add_ff(o_vector3_t vector, float f)
{
	return (o_vector3_t) { vector.m_x + f, vector.m_y + f, vector.m_z + f };
}

o_vector3_t ogle_vector3_add_f(o_vector3_t vector, float x, float y, float z)
{
	return (o_vector3_t) { vector.m_x + x, vector.m_y + y, vector.m_z + z };
}

o_vector3_t ogle_vector3_add(o_vector3_t vector1, o_vector3_t vector3)
{
	return (o_vector3_t) { vector1.m_x + vector3.m_x, vector1.m_y + vector3.m_y, vector1.m_z + vector3.m_z };
}

o_vector3_t ogle_vector3_sub_ff(o_vector3_t vector, float f)
{
	return (o_vector3_t) { vector.m_x - f, vector.m_y - f, vector.m_z - f };
}

o_vector3_t ogle_vector3_sub_f(o_vector3_t vector, float x, float y, float z)
{
	return (o_vector3_t) { vector.m_x - x, vector.m_y - y, vector.m_z - z };
}

o_vector3_t ogle_vector3_sub(o_vector3_t vector1, o_vector3_t vector3)
{
	return (o_vector3_t) { vector1.m_x - vector3.m_x, vector1.m_y - vector3.m_y, vector1.m_z - vector3.m_z };
}

o_vector3_t ogle_vector3_mul_ff(o_vector3_t vector, float f)
{
	return (o_vector3_t) { vector.m_x* f, vector.m_y* f, vector.m_z* f };
}

o_vector3_t ogle_vector3_mul_f(o_vector3_t vector, float x, float y, float z)
{
	return (o_vector3_t) { vector.m_x* x, vector.m_y* y, vector.m_z* z };
}

o_vector3_t ogle_vector3_mul(o_vector3_t vector1, o_vector3_t vector3)
{
	return (o_vector3_t) { vector1.m_x* vector3.m_x, vector1.m_y* vector3.m_y, vector1.m_z* vector3.m_z };
}

o_vector3_t ogle_vector3_div_ff(o_vector3_t vector, float f)
{
	if (ogle_math_is_zero_f(f))
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_WARNING, "Attempted to divide vector by zero.\n");
		return vector;
	}

	return (o_vector3_t) { vector.m_x / f, vector.m_y / f, vector.m_z / f };
}

o_vector3_t ogle_vector3_div_f(o_vector3_t vector, float x, float y, float z)
{
	if (ogle_math_is_zero_f(x) || ogle_math_is_zero_f(y))
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_WARNING, "Attempted to divide vector by zero.\n");
		return vector;
	}

	return (o_vector3_t) { vector.m_x / x, vector.m_y / y, vector.m_z / z };
}

o_vector3_t ogle_vector3_div(o_vector3_t vector1, o_vector3_t vector2)
{
	if (ogle_math_is_zero_f(vector2.m_x) || ogle_math_is_zero_f(vector2.m_y) || ogle_math_is_zero_f(vector2.m_z))
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_WARNING, "Attempted to divide vector by zero.\n");
		return vector1;
	}

	return (o_vector3_t) { vector1.m_x / vector2.m_x, vector1.m_y / vector2.m_y, vector1.m_z / vector2.m_z };
}

bool ogle_vector3_equal(o_vector3_t vector1, o_vector3_t vector2)
{
	return ogle_math_is_equal_f(vector1.m_x, vector2.m_x) && ogle_math_is_equal_f(vector1.m_y, vector2.m_y) && ogle_math_is_equal_f(vector1.m_z, vector2.m_z);
}

o_vector3_t ogle_vector3_normalize(o_vector3_t vector)
{
	float length = ogle_vector3_length(vector);

	if (ogle_math_is_zero_f(length))
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_WARNING, "Attempted to normalize a zero-length vector.\n");
		return vector;
	}

	return ogle_vector3_div_ff(vector, length);
}

o_vector3_t ogle_vector3_lerp(o_vector3_t vector1, o_vector3_t vector2, float t)
{
	return ogle_vector3_add(vector1, ogle_vector3_mul_ff(ogle_vector3_sub(vector2, vector1), t));
}

o_vector3_t ogle_vector3_clamp(o_vector3_t vector, o_vector3_t min, o_vector3_t max)
{
	return (o_vector3_t) { ogle_math_clamp_f(vector.m_x, min.m_x, max.m_x), ogle_math_clamp_f(vector.m_y, min.m_y, max.m_y), ogle_math_clamp_f(vector.m_z, min.m_z, max.m_z) };
}

o_vector3_t ogle_vector3_rotate_xy(o_vector3_t vector, float angle)
{
	float cos_angle = cosf(angle);
	float sin_angle = sinf(angle);
	return (o_vector3_t) { vector.m_x* cos_angle - vector.m_y * sin_angle, vector.m_x* sin_angle + vector.m_y * cos_angle, vector.m_z }; {}
}

o_vector3_t ogle_vector3_rotate_xz(o_vector3_t vector, float angle)
{
	float cos_angle = cosf(angle);
	float sin_angle = sinf(angle);

	return (o_vector3_t) { vector.m_x* cos_angle - vector.m_z * sin_angle, vector.m_y, vector.m_x* sin_angle + vector.m_z * cos_angle };
}

o_vector3_t ogle_vector3_rotate_yz(o_vector3_t vector, float angle)
{
	float cos_angle = cosf(angle);
	float sin_angle = sinf(angle);
	return (o_vector3_t) { vector.m_x, vector.m_y* cos_angle - vector.m_z * sin_angle, vector.m_y* sin_angle + vector.m_z * cos_angle };
}

o_vector3_t ogle_vector3_difference(o_vector3_t vector, o_vector3_t other)
{
	return ogle_vector3_abs(ogle_vector3_sub(vector, other));
}

o_vector3_t ogle_vector3_abs(o_vector3_t vector)
{
	return (o_vector3_t) { fabsf(vector.m_x), fabsf(vector.m_y), fabsf(vector.m_z) };
}

ALLEGRO_PRIM_STORAGE ogle_vector3_storage_type(void)
{
	return ALLEGRO_PRIM_FLOAT_3;
}

void ogle_vector3_set_shader(const char* var_name, o_vector3_t vector)
{
	const ALLEGRO_SHADER* shader = al_get_current_shader();

	if (!shader)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_WARNING, "No shader is currently active. Cannot set shader variable '%s'.\n", var_name);
		return;
	}

	if (!var_name)
	{
		OGLE_DO_LOG(OGLE_LOG_LEVEL_ERROR, "Variable name is NULL.\n");
		return;
	}

	al_set_shader_float_vector(var_name, 3, &vector.m_x, 1);
}