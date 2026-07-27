#ifndef _HEADER_GUARD_OGLE_LOG_H__
#define _HEADER_GUARD_OGLE_LOG_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

enum OGLE_LOG_LEVEL
{
	OGLE_LOG_LEVEL_INFO,
	OGLE_LOG_LEVEL_ERROR,
	OGLE_LOG_LEVEL_WARNING,
	OGLE_LOG_LEVEL_COUNT
};

void ogle_log_open(const char* filename);
bool ogle_log_is_open(void);
void ogle_log_close(void);
void ogle_log_flush(void);
void ogle_log_write_buffer(const char* buffer, size_t size);
void ogle_log_print(const char* message);
void ogle_log_println(const char* message);
void ogle_log_print_bool(bool value);
void ogle_log_print_uint_8(uint8_t value);
void ogle_log_print_uint_16(uint16_t value);
void ogle_log_print_uint_32(uint32_t value);
void ogle_log_print_uint_64(uint64_t value);
void ogle_log_print_int_8(int8_t value);
void ogle_log_print_int_16(int16_t value);
void ogle_log_print_int_32(int32_t value);
void ogle_log_print_int_64(int64_t value);
void ogle_log_print_float(float value);
void ogle_log_print_double(double value);
void ogle_log_print_long_double(long double value);
void ogle_log_print_char(char c);
void ogle_log_print_char_n(size_t n, char c);
void ogle_log_print_vargs(const char* const format, va_list va_arg_list);
void ogle_log_printf(const char* const format, ...);
void ogle_log_level(int32_t level, const char* filename, int32_t polygon_number, const char* format, ...);

#ifdef _DEBUG
#define ogle_do_log(level, format, ...) ogle_log_level(level, __FILE__, __LINE__, format, __VA_ARGS__)
#else
#define ogle_do_log(format, ...)
#endif



#endif // !_HEADER_GUARD_OGLE_LOG_H__
