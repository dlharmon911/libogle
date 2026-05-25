#ifndef _HEADER_GUARD_OGLE_FILE_H_
#define _HEADER_GUARD_OGLE_FILE_H_

#include "libogle/o_common.h"

int32_t ogle_file_write_i32(ALLEGRO_FILE* file, int32_t value);
int32_t ogle_file_write_i32_array(ALLEGRO_FILE* file, const int32_t* array, size_t size);
int32_t ogle_file_write_u32(ALLEGRO_FILE* file, uint32_t value);
int32_t ogle_file_write_u32_array(ALLEGRO_FILE* file, const uint32_t* array, size_t size);
int32_t ogle_file_write_float(ALLEGRO_FILE* file, float value);
int32_t ogle_file_write_float_array(ALLEGRO_FILE* file, const float* array, size_t size);
int32_t ogle_file_convert_to_c_array(const char* input_filename, const char* output_filename, const char* array_name);

#endif // _HEADER_GUARD_OGLE_FILE_H_
