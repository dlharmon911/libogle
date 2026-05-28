#ifndef _HEADER_GUARD_OGLE_FILE_H_
#define _HEADER_GUARD_OGLE_FILE_H_

#include "libogle/o_common.h"
#include "libogle/o_literal.h"

int32_t ogle_file_write_bool(ALLEGRO_FILE* file, bool value);
int32_t ogle_file_write_bool_array(ALLEGRO_FILE* file, const bool* array, size_t size);
int32_t ogle_file_write_i8(ALLEGRO_FILE* file, int8_t value);
int32_t ogle_file_write_i8_array(ALLEGRO_FILE* file, const int8_t* array, size_t size);
int32_t ogle_file_write_i16(ALLEGRO_FILE* file, int16_t value);
int32_t ogle_file_write_i16_array(ALLEGRO_FILE* file, const int16_t* array, size_t size);
int32_t ogle_file_write_i32(ALLEGRO_FILE* file, int32_t value);
int32_t ogle_file_write_i32_array(ALLEGRO_FILE* file, const int32_t* array, size_t size);
int32_t ogle_file_write_i64(ALLEGRO_FILE* file, int64_t value);
int32_t ogle_file_write_i64_array(ALLEGRO_FILE* file, const int64_t* array, size_t size);
int32_t ogle_file_write_u8(ALLEGRO_FILE* file, uint8_t value);
int32_t ogle_file_write_u8_array(ALLEGRO_FILE* file, const uint8_t* array, size_t size);
int32_t ogle_file_write_u16(ALLEGRO_FILE* file, uint16_t value);
int32_t ogle_file_write_u16_array(ALLEGRO_FILE* file, const uint16_t* array, size_t size);
int32_t ogle_file_write_u32(ALLEGRO_FILE* file, uint32_t value);
int32_t ogle_file_write_u32_array(ALLEGRO_FILE* file, const uint32_t* array, size_t size);
int32_t ogle_file_write_u64(ALLEGRO_FILE* file, uint64_t value);
int32_t ogle_file_write_u64_array(ALLEGRO_FILE* file, const uint64_t* array, size_t size);
int32_t ogle_file_write_f32(ALLEGRO_FILE* file, float value);
int32_t ogle_file_write_f32_array(ALLEGRO_FILE* file, const float* array, size_t size);
int32_t ogle_file_write_f64(ALLEGRO_FILE* file, double value);
int32_t ogle_file_write_f64_array(ALLEGRO_FILE* file, const double* array, size_t size);
int32_t ogle_file_read_bool(ALLEGRO_FILE* file, bool* value);
int32_t ogle_file_read_bool_array(ALLEGRO_FILE* file, bool* array, size_t size);
int32_t ogle_file_read_i8(ALLEGRO_FILE* file, int8_t* value);
int32_t ogle_file_read_i8_array(ALLEGRO_FILE* file, int8_t* array, size_t size);
int32_t ogle_file_read_i16(ALLEGRO_FILE* file, int16_t* value);
int32_t ogle_file_read_i16_array(ALLEGRO_FILE* file, int16_t* array, size_t size);
int32_t ogle_file_read_i32(ALLEGRO_FILE* file, int32_t* value);
int32_t ogle_file_read_i32_array(ALLEGRO_FILE* file, int32_t* array, size_t size);
int32_t ogle_file_read_i64(ALLEGRO_FILE* file, int64_t* value);
int32_t ogle_file_read_i64_array(ALLEGRO_FILE* file, int64_t* array, size_t size);
int32_t ogle_file_read_u8(ALLEGRO_FILE* file, uint8_t* value);
int32_t ogle_file_read_u8_array(ALLEGRO_FILE* file, uint8_t* array, size_t size);
int32_t ogle_file_read_u16(ALLEGRO_FILE* file, uint16_t* value);
int32_t ogle_file_read_u16_array(ALLEGRO_FILE* file, uint16_t* array, size_t size);
int32_t ogle_file_read_u32(ALLEGRO_FILE* file, uint32_t* value);
int32_t ogle_file_read_u32_array(ALLEGRO_FILE* file, uint32_t* array, size_t size);
int32_t ogle_file_read_u64(ALLEGRO_FILE* file, uint64_t* value);
int32_t ogle_file_read_u64_array(ALLEGRO_FILE* file, uint64_t* array, size_t size);
int32_t ogle_file_read_f32(ALLEGRO_FILE* file, float* value);
int32_t ogle_file_read_f32_array(ALLEGRO_FILE* file, float* array, size_t size);
int32_t ogle_file_read_f64(ALLEGRO_FILE* file, double* value);
int32_t ogle_file_read_f64_array(ALLEGRO_FILE* file, double* array, size_t size);
int32_t ogle_file_write_literal(ALLEGRO_FILE* file, int32_t type, const void* value);
int32_t ogle_file_write_literal_array(ALLEGRO_FILE* file, int32_t type, const void* array, size_t size);
int32_t ogle_file_read_literal(ALLEGRO_FILE* file, int32_t type, void* value);
int32_t ogle_file_read_literal_array(ALLEGRO_FILE* file, int32_t type, void* array, size_t size);

int32_t ogle_file_convert_to_c_array(const char* input_filename, const char* output_filename, const char* array_name);

#endif // _HEADER_GUARD_OGLE_FILE_H_
