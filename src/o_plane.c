#include "libogle/o_common.h"
#include "libogle/o_vector3.h"
#include "libogle/o_plane.h"

float ogle_plane_distance_to_point(const o_plane_t* plane, o_vector3_t point)
{
	float dot_product = ogle_vector3_dot(plane->m_normal, point);

	return dot_product - plane->m_distance;
}
