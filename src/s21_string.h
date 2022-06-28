#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#define s21_NULL (void*)0
#define s21_size_t unsigned long long
struct flags {
    int plus;
    int minus;
    int space;
};
//  |  Part 1
//  V
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void* str1, const void* str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void* s21_memmove(void* dest, const void* src, s21_size_t n);
void* s21_memset(void* str, int c, s21_size_t n);
char* s21_strcat(char* dest, const char* src);
char* s21_strncat(char* dest, const char* src, s21_size_t n);
char* s21_strchr(const char* str, int c);
int s21_strcmp(const char* str1, const char* str2);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
char* s21_strcpy(char* dest, const char* src);
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
s21_size_t s21_strcspn(const char* str1, const char* str2);
char* s21_strerror(int errnum);
void s21_itoa(int errnum, char* stt);  // int to ASCII
s21_size_t s21_strlen(const char* str);
char* s21_strpbrk(const char* str1, const char* str2);
char* s21_strrchr(const char* str, int c);
s21_size_t s21_strspn(const char* str1, const char* str2);
char* s21_strstr(const char* str1, const char* str2);
char* s21_strtok(char* str, const char* delim);
//  |  Part 2 sprintf.h
//  V
int s21_sprintf(const char* str, char* format, ...);
void s21_sprintf_finder(char** format, char** dest, int* end_flag);
void s21_parcer(char** format, struct flags* flag, int* width, \
int* precision, int* lenght, char* specify, char** dest, int* end_flag);
void s21_sprintf_flags(char** format, struct flags* flag);
void s21_sprintf_width(char** format, int* width);
void s21_sprintf_precision(char** format, int* precision/*, int* enter_flag*/);
void s21_sprintf_lenght(char** format, int* lenght);
void s21_sprintf_specify(char** format, char* specify);
void char_filler(char** dest, wchar_t arg, struct flags* flag, int width);
void s21_switcher(char specify, int lenght, char** str_changed, \
va_list* list, struct flags* flag, int width, int precision, int end_flag);
//  |  s21_float.h
//  V
void parts_finder(long double number, long double* int_part, long double* float_part);
void s21_float_filler(char** dest, long double arg, struct flags* flag, int width, int precision);
void s21_int_to_char_float(char** buffer_float, long double number, \
int precision, int razryad);
void float_filler_right(char** dest, char** buffer_int, char** buffer_float, \
struct flags* flag, int width, int precision, int int_razryad, int is_minus);
void float_filler_left(char** dest, char** buffer_int, char** buffer_float, \
struct flags* flag, int width, int precision, int int_razryad, int is_minus);
void float_width_filler(char** dest, int width, int precision, int int_razryad);
void float_arg_filler(char** dest, char** buffer_int, char** buffer_float, int precision, int int_razryad);
//  |  s21_int.h
//  V
void int_filler(char** dest, long int arg, struct flags* flag, int width, int precision);
void int_filler_right(char** dest, char** buffer, struct flags* flag, \
int width, int precision, int razryad, int is_minus);
void int_filler_left(char** dest, char** buffer, struct flags* flag, \
int width, int precision, int razryad, int is_minus);
int s21_max(int x1, int x2);
void int_width_filler(char** dest, int width, int precision, int razryad);
void int_precision_filler(char** dest, int precision, int razryad);
void int_arg_filler(char** dest, char** buffer, int razryad);
void s21_int_to_char(char** buffer, long long int arg, int razryad);
int razryad_finder(long long int number);
int unsigned_razryad_finder(unsigned long number);
void unsigned_filler(char** dest, unsigned long arg, struct flags* flag, int width, int precision);
void s21_unsigned_to_char(char** buffer, unsigned long arg, int razryad);
//  |  s21_print_string.h
//  V
void string_filler(char** dest, wchar_t* arg, struct flags* flag, int width, int precision);
int s21_min(int x1, int x2);
void string_null_filler(char** dest);
void string_width_filler(char** dest, int width, int precision, int str_lenght);
void string_arg_filler(char** dest, wchar_t* arg, int precision, int str_lenght);
void string_filler_char(char** dest, char* arg, struct flags* flag, int width, int precision);
void string_arg_filler_char(char** dest, char* arg, int precision, int str_lenght);
s21_size_t s21_strlen_self(wchar_t* arg);
//  |  Part 5
//  V
void *s21_to_upper(const char *str);  //  return copy of str to upper register
void *s21_to_lower(const char *str);  //  return copy of str to lower register
void *s21_insert(const char *src, const char *str, s21_size_t start_index);  //  return new str with insert
void *s21_trim(const char *src, const char *trim_chars);
#endif  //  SRC_S21_STRING_H_
