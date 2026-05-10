#ifndef _HEADER_GUARD_OGLE_TRANSFORM_H_
#define _HEADER_GUARD_OGLE_TRANSFORM_H_

#include "libogle/o_common.h"
#include "libogle/o_vector2.h"
#include "libogle/o_vector3.h"
#include "libogle/o_vector4.h"
#include "libogle/o_camera.h"
#include "libogle/o_plane.h"

typedef ALLEGRO_TRANSFORM o_transform_t;

typedef struct o_world_transform_tag_t
{
	o_transform_t m_projection;
	o_transform_t m_view;
	o_transform_t m_model;
} o_world_transform_t;

void ogle_transform_use(const o_transform_t* trans);
void ogle_transform_use_projection(const o_transform_t* trans);
void ogle_transform_copy(o_transform_t* dest, const o_transform_t* src);
void ogle_transform_identity(o_transform_t* trans);
void ogle_transform_build(o_transform_t* trans, o_vector2_t position, o_vector2_t scale, float theta);
void ogle_transform_camera_build(o_transform_t* trans, const o_camera_t* camera);
void ogle_transform_translate_2d(o_transform_t* trans, o_vector2_t translation);
void ogle_transform_translate_3d(o_transform_t* trans, o_vector3_t translation);
void ogle_transform_rotate_2d(o_transform_t* trans, float theta);
void ogle_transform_rotate_3d(o_transform_t* trans, o_vector3_t axis, float angle);
void ogle_transform_scale_2d(o_transform_t* trans, o_vector2_t scale);
void ogle_transform_scale_3d(o_transform_t* trans, o_vector3_t scale);
o_vector2_t ogle_transform_coordinates_2d(const o_transform_t* trans, o_vector2_t vec);
o_vector3_t ogle_transform_coordinates_3d(const o_transform_t* trans, o_vector3_t vec);
o_vector4_t ogle_transform_coordinates_4d(const o_transform_t* trans, o_vector4_t vec);
o_vector3_t ogle_transform_coordinates_3d_projective(const o_transform_t* trans, o_vector3_t vec);
void ogle_transform_compose(o_transform_t* trans, const o_transform_t* other);
const o_transform_t* ogle_transform_get_current(void);
const o_transform_t* ogle_transform_get_current_inverse(void);
const o_transform_t* ogle_transform_get_current_projection(void);
void ogle_transform_invert(o_transform_t* trans);
void ogle_transform_transpose(o_transform_t* trans);
int32_t ogle_transform_check_inverse(const o_transform_t* trans, float tolerance);
void ogle_transform_orthographic(o_transform_t* trans, o_vector2_t top_left, o_vector2_t bottom_right, float n, float f);
void ogle_transform_perspective(o_transform_t* trans, o_vector2_t top_left, o_vector2_t bottom_right, float n, float f);
void ogle_transform_horizontal_shear(o_transform_t* trans, float theta);
void ogle_transform_vertical_shear(o_transform_t* trans, float theta);
void ogle_transform_set_shader(const char* name, const o_transform_t* transform);
int32_t ogle_transform_invert_4x4(o_transform_t* dest, const o_transform_t* src);

#endif // _HEADER_GUARD_OGLE_TRANSFORM_H_
