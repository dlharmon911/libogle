#include "libogle/o_common.h"
#include "libogle/o_log.h"
#include "libogle/o_vector2.h"
#include "libogle/o_vector3.h"
#include "libogle/o_vector4.h"
#include "libogle/o_camera.h"
#include "libogle/o_transform.h"
#include "libogle/o_ray.h"
#include "libogle/o_plane.h"
#include <math.h>

void ogle_transform_use(const o_transform_t* trans)
{
	if (!trans)
	{
		return;
	}

	al_use_transform(trans);
}

void ogle_transform_use_projection(const o_transform_t* trans)
{
	if (!trans)
	{
		return;
	}

	al_use_projection_transform(trans);
}

void ogle_transform_copy(o_transform_t* dest, const o_transform_t* src)
{
	if (!dest || !src)
	{
		return;
	}

	al_copy_transform(dest, src);
}

void ogle_transform_identity(o_transform_t* trans)
{
	if (!trans)
	{
		return;
	}

	al_identity_transform(trans);
}

void ogle_transform_build(o_transform_t* trans, o_vector2_t position, o_vector2_t scale, float theta)
{
	if (!trans)
	{
		return;
	}

	al_build_transform(trans, position.m_x, position.m_y, scale.m_x, scale.m_y, theta);
}

void ogle_transform_camera_build(o_transform_t* trans, const o_camera_t* camera)
{
	if (!trans)
	{
		return;
	}

	if (!camera)
	{
		return;
	}

	float y = camera->m_lookat.m_y - camera->m_pitch;

	al_build_camera_transform(trans, 
		camera->m_position.m_x, camera->m_position.m_y, camera->m_position.m_z, 
		camera->m_lookat.m_x, y, camera->m_lookat.m_z, 
		camera->m_up.m_x, camera->m_up.m_y, camera->m_up.m_z);
}

void ogle_transform_translate_2d(o_transform_t* trans, o_vector2_t translation)
{
	if (!trans)
	{
		return;
	}

	al_translate_transform(trans, translation.m_x, translation.m_y);
}

void ogle_transform_translate_3d(o_transform_t* trans, o_vector3_t translation)
{
	if (!trans)
	{
		return;
	}

	al_translate_transform_3d(trans, translation.m_x, translation.m_y, translation.m_z);
}

void ogle_transform_rotate_2d(o_transform_t* trans, float theta)
{
	if (!trans)
	{
		return;
	}

	al_rotate_transform(trans, theta);
}

void ogle_transform_rotate_3d(o_transform_t* trans, o_vector3_t axis, float angle)
{
	if (!trans)
	{
		return;
	}

	al_rotate_transform_3d(trans, axis.m_x, axis.m_y, axis.m_z, angle);
}

void ogle_transform_scale_2d(o_transform_t* trans, o_vector2_t scale)
{
	if (!trans)
	{
		return;
	}

	al_scale_transform(trans, scale.m_x, scale.m_y);
}

void ogle_transform_scale_3d(o_transform_t* trans, o_vector3_t scale)
{
	if (!trans)
	{
		return;
	}

	al_scale_transform_3d(trans, scale.m_x, scale.m_y, scale.m_z);
}

o_vector2_t ogle_transform_coordinates_2d(const o_transform_t* trans, o_vector2_t vec)
{
	if (!trans)
	{
		return (o_vector2_t) { 0 };
	}

	al_transform_coordinates(trans, &vec.m_x, &vec.m_y);

	return vec;
}

o_vector3_t ogle_transform_coordinates_3d(const o_transform_t* trans, o_vector3_t vec)
{
	if (!trans)
	{
		return (o_vector3_t){ 0 };
	}

	al_transform_coordinates_3d(trans, &vec.m_x, &vec.m_y, &vec.m_z);

	return vec;
}

o_vector4_t ogle_transform_coordinates_4d(const o_transform_t* trans, o_vector4_t vec)
{
	if (!trans)
	{
		return (o_vector4_t) { 0 };
	}

	al_transform_coordinates_4d(trans, &vec.m_x, &vec.m_y, &vec.m_z, &vec.m_w);

	return vec;
}

o_vector3_t ogle_transform_coordinates_3d_projective(const o_transform_t* trans, o_vector3_t vec)
{
	if (!trans)
	{
		return (o_vector3_t) { 0 };
	}

	al_transform_coordinates_3d_projective(trans, &vec.m_x, &vec.m_y, &vec.m_z);

	return vec;
}

void ogle_transform_compose(o_transform_t* trans, const o_transform_t* other)
{
	if (!trans || !other)
	{
		return;
	}

	al_compose_transform(trans, other);
}

const o_transform_t* ogle_transform_get_current(void)
{
	return al_get_current_transform();
}

const o_transform_t* ogle_transform_get_current_inverse(void)
{
	return al_get_current_inverse_transform();
}

const o_transform_t* ogle_transform_get_current_projection(void)
{
	return al_get_current_projection_transform();
}

void ogle_transform_invert(o_transform_t* trans)
{
	if (!trans)
	{
		return;
	}
	
	al_invert_transform(trans);
}

void ogle_transform_transpose(o_transform_t* trans)
{
	if (!trans)
	{
		return;
	}

	al_transpose_transform(trans);
}

int32_t ogle_transform_check_inverse(const o_transform_t* trans, float tolerance)
{
	if (!trans)
	{
		return -1;
	}

	return al_check_inverse(trans, tolerance);
}

void ogle_transform_orthographic(o_transform_t* trans, o_vector2_t top_left, o_vector2_t bottom_right, float n, float f)
{
	al_orthographic_transform(trans, top_left.m_x, top_left.m_y, n, bottom_right.m_x, bottom_right.m_y, f);
}

void ogle_transform_perspective(o_transform_t* trans, o_vector2_t top_left, o_vector2_t bottom_right, float n, float f)
{
	al_perspective_transform(trans, top_left.m_x, top_left.m_y, n, bottom_right.m_x, bottom_right.m_y, f);
}

void ogle_transform_horizontal_shear(o_transform_t* trans, float theta)
{
	al_horizontal_shear_transform(trans, theta);
}

void ogle_transform_vertical_shear(o_transform_t* trans, float theta)
{
	al_vertical_shear_transform(trans, theta);
}

void ogle_transform_set_shader(const char* name, const o_transform_t* transform)
{
	if (!name || !transform)
	{
		return;
	}

	al_set_shader_matrix(name, transform);
}

int32_t ogle_transform_invert_4x4(o_transform_t* dest, const o_transform_t* src)
{
	if (!dest || !src)
	{
		return -1;
	}

	const float* m = (const float*)src->m;
	float inv[16] = { 0 };
	float det = 0;

	inv[0] = m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15] + 
			 m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];

	inv[4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15] - 
			  m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];

	inv[8] = m[4] * m[9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15] + 
			 m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[9];

	inv[12] = -m[4] * m[9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14] - 
			   m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[9];

	inv[1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15] - 
			  m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];

	inv[5] = m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15] + 
			 m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];

	inv[9] = -m[0] * m[9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15] - 
			  m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[9];

	inv[13] = m[0] * m[9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14] + 
			  m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[9];

	inv[2] = m[1] * m[6] * m[15] - m[1] * m[7] * m[14] - m[5] * m[2] * m[15] + 
			 m[5] * m[3] * m[14] + m[13] * m[2] * m[7] - m[13] * m[3] * m[6];

	inv[6] = -m[0] * m[6] * m[15] + m[0] * m[7] * m[14] + m[4] * m[2] * m[15] - 
			  m[4] * m[3] * m[14] - m[12] * m[2] * m[7] + m[12] * m[3] * m[6];

	inv[10] = m[0] * m[5] * m[15] - m[0] * m[7] * m[13] - m[4] * m[1] * m[15] + 
			  m[4] * m[3] * m[13] + m[12] * m[1] * m[7] - m[12] * m[3] * m[5];

	inv[14] = -m[0] * m[5] * m[14] + m[0] * m[6] * m[13] + m[4] * m[1] * m[14] - 
			   m[4] * m[2] * m[13] - m[12] * m[1] * m[6] + m[12] * m[2] * m[5];

	inv[3] = -m[1] * m[6] * m[11] + m[1] * m[7] * m[10] + m[5] * m[2] * m[11] - 
			  m[5] * m[3] * m[10] - m[9] * m[2] * m[7] + m[9] * m[3] * m[6];

	inv[7] = m[0] * m[6] * m[11] - m[0] * m[7] * m[10] - m[4] * m[2] * m[11] + 
			 m[4] * m[3] * m[10] + m[8] * m[2] * m[7] - m[8] * m[3] * m[6];

	inv[11] = -m[0] * m[5] * m[11] + m[0] * m[7] * m[9] + m[4] * m[1] * m[11] - 
			   m[4] * m[3] * m[9] - m[8] * m[1] * m[7] + m[8] * m[3] * m[5];

	inv[15] = m[0] * m[5] * m[10] - m[0] * m[6] * m[9] - m[4] * m[1] * m[10] + 
			  m[4] * m[2] * m[9] + m[8] * m[1] * m[6] - m[8] * m[2] * m[5];

	det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

	if (fabsf(det) < 0.00001f)
	{
		return -1;
	}

	det = 1.0f / det;

	float* out = (float*)dest->m;
	for (int i = 0; i < 16; i++)
	{
		out[i] = inv[i] * det;
	}

	return 0;
}

