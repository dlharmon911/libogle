#include "libogle/o_common.h"
#include "libogle/o_vector2.h"
#include "libogle/o_vector3.h"
#include "libogle/o_vector4.h"


o_vector4_t ogle_vector4_zero(void)
{
	return (o_vector4_t) { 0.0f, 0.0f, 0.0f, 0.0f };
}

o_vector3_t ogle_vector4_xyz(o_vector4_t vector)
{
	return (o_vector3_t) { vector.m_x, vector.m_y, vector.m_z };
}

o_vector2_t ogle_vector4_xy(o_vector4_t vector)
{
	return (o_vector2_t) { vector.m_x, vector.m_y };
}
