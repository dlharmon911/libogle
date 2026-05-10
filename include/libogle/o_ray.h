#ifndef _HEADER_GUARD_OGLE_RAY_H_
#define _HEADER_GUARD_OGLE_RAY_H_

#include "libogle/o_common.h"
#include "libogle/o_vector3.h"

typedef struct o_ray_tag_t 
{
	o_vector3_t m_origin;
	o_vector3_t m_direction;
} o_ray_t;


#endif // _HEADER_GUARD_OGLE_RAY_H_
