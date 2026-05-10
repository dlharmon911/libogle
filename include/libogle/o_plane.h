#ifndef _HEADER_GUARD_OGLE_PLANE_H_
#define _HEADER_GUARD_OGLE_PLANE_H_

#include "libogle/o_common.h"
#include "libogle/o_vector3.h"

typedef struct o_plane_tag_t 
{
	o_vector3_t m_normal;
	float m_distance;
} o_plane_t;

float ogle_plane_distance_to_point(const o_plane_t* plane, o_vector3_t point);

#endif // _HEADER_GUARD_OGLE_PLANE_H_
