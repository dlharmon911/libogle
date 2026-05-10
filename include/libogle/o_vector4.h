#ifndef _HEADER_GUARD_OGLE_VECTOR4_H_
#define _HEADER_GUARD_OGLE_VECTOR4_H_

#include "libogle/o_common.h"
#include "libogle/o_vector2.h"
#include "libogle/o_vector3.h"


typedef struct o_vector4_tag_t
{
	float m_x;
	float m_y;
	float m_z;
	float m_w;
} o_vector4_t;


o_vector4_t ogle_vector4_zero(void);
o_vector3_t ogle_vector4_xyz(o_vector4_t vector);
o_vector2_t ogle_vector4_xy(o_vector4_t vector);

#endif // _HEADER_GUARD_OGLE_VECTOR4_H_
