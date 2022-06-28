#include "s21_string.h"
#if defined(__APPLE__) && defined(__MACH__)
    #define PLATFORM_NAME "OSX"
    #define ERROR_NUM 107
    #define STR_ERROR "Unknown error: "
    #define ERRLIST {"Undefined error: 0", "Operation not permitted", \
"No such file or directory", "No such process", \
"Interrupted system call", "Input/output error", \
"Device not configured", "Argument list too long", \
"Exec format error", "Bad file descriptor", \
"No child processes", "Resource deadlock avoided", \
"Cannot allocate memory", "Permission denied", \
"Bad address", "Block device required", "Resource busy", \
"File exists", "Cross-device link", \
"Operation not supported by device", \
"Not a directory", "Is a directory", \
"Invalid argument", "Too many open files in system", \
"Too many open files", "Inappropriate ioctl for device", \
"Text file busy", "File too large", "No space left on device", \
"Illegal seek", "Read-only file system", "Too many links", \
"Broken pipe", "Numerical argument out of domain", \
"Result too large", "Resource temporarily unavailable", \
"Operation now in progress", "Operation already in progress", \
"Socket operation on non-socket", "Destination address required", \
"Message too long", "Protocol wrong type for socket", \
"Protocol not available", "Protocol not supported", \
"Socket type not supported", "Operation not supported", \
"Protocol family not supported", \
"Address family not supported by protocol family", \
"Address already in use", "Can't assign requested address", \
"Network is down", "Network is unreachable", \
"Network dropped connection on reset", \
"Software caused connection abort", "Connection reset by peer", \
"No buffer space available", "Socket is already connected", \
"Socket is not connected", "Can't send after socket shutdown", \
"Too many references: can't splice", "Operation timed out", \
"Connection refused", "Too many levels of symbolic links", \
"File name too long", "Host is down", "No route to host", \
"Directory not empty", "Too many processes", "Too many users", \
"Disc quota exceeded", "Stale NFS file handle", \
"Too many levels of remote in path", "RPC struct is bad", \
"RPC version wrong", "RPC prog. not avail", "Program version wrong", \
"Bad procedure for program", "No locks available", \
"Function not implemented", "Inappropriate file type or format", \
"Authentication error", "Need authenticator", "Device power is off", \
"Device error", "Value too large to be stored in data type", \
"Bad executable (or shared library)", "Bad CPU type in executable", \
"Shared library version mismatch", "Malformed Mach-o file", \
"Operation canceled", "Identifier removed", "No message of desired type", \
"Illegal byte sequence", "Attribute not found", "Bad message", \
"EMULTIHOP (Reserved)", "No message available on STREAM", \
"ENOLINK (Reserved)", "No STREAM resources", "Not a STREAM", \
"Protocol error", "STREAM ioctl timeout", \
"Operation not supported on socket", "Policy not found", \
"State not recoverable", "Previous owner died", \
"Interface output queue is full"}
#elif defined(__linux__)
    #define PLATFORM_NAME "linux"
    #define ERROR_NUM 133
    #define STR_ERROR "Unknown error "
    #define ERRLIST {"Success", "Operation not permitted", \
"No such file or directory", "No such process", \
"Interrupted system call", "Input/output error", \
"No such device or address", "Argument list too long", \
"Exec format error", "Bad file descriptor", \
"No child processes", "Resource temporarily unavailable", \
"Cannot allocate memory", "Permission denied", "Bad address", \
"Block device required", "Device or resource busy", \
"File exists", "Invalid cross-device link", "No such device", \
"Not a directory", "Is a directory", "Invalid argument", \
"Too many open files in system", "Too many open files", \
"Inappropriate ioctl for device", "Text file busy", \
"File too large", "No space left on device", "Illegal seek", \
"Read-only file system", "Too many links", "Broken pipe", \
"Numerical argument out of domain", \
"Numerical result out of range", "Resource deadlock avoided", \
"File name too long", "No locks available", \
"Function not implemented", "Directory not empty", \
"Too many levels of symbolic links", "(null)", \
"No message of desired type", "Identifier removed", \
"Channel number out of range", "Level 2 not synchronized", \
"Level 3 halted", "Level 3 reset", "Link number out of range", \
"Protocol driver not attached", "No CSI structure available", \
"Level 2 halted", "Invalid exchange", "Invalid request descriptor", \
"Exchange full", "No anode", "Invalid request code", \
"Invalid slot", "(null)", "Bad font file format", \
"Device not a stream", "No data available", "Timer expired", \
"Out of streams resources", "Machine is not on the network", \
"Package not installed", "Object is remote", "Link has been severed", \
"Advertise error", "Srmount error", "Communication error on send", \
"Protocol error", "Multihop attempted", "RFS specific error", \
"Bad message", "Value too large for defined data type", \
"Name not unique on network", "File descriptor in bad state", \
"Remote address changed", "Can not access a needed shared library", \
"Accessing a corrupted shared library", \
".lib section in a.out corrupted", \
"Attempting to link in too many shared libraries", \
"Cannot exec a shared library directly", \
"Invalid or incomplete multibyte or wide character", \
"Interrupted system call should be restarted", "Streams pipe error", \
"Too many users", "Socket operation on non-socket", \
"Destination address required", "Message too long", \
"Protocol wrong type for socket", "Protocol not available", \
"Protocol not supported", "Socket type not supported", \
"Operation not supported", "Protocol family not supported", \
"Address family not supported by protocol", "Address already in use", \
"Cannot assign requested address", "Network is down", \
"Network is unreachable", "Network dropped connection on reset", \
"Software caused connection abort", "Connection reset by peer", \
"No buffer space available", \
"Transport endpoint is already connected", \
"Transport endpoint is not connected", \
"Cannot send after transport endpoint shutdown", \
"Too many references: cannot splice", "Connection timed out", \
"Connection refused", "Host is down", "No route to host", \
"Operation already in progress", "Operation now in progress", \
"Stale file handle", "Structure needs cleaning", \
"Not a XENIX named type file", "No XENIX semaphores available", \
"Is a named type file", "Remote I/O error", \
"Disk quota exceeded", "No medium found", "Wrong medium type", \
"Operation canceled", "Required key not available", \
"Key has expired", "Key has been revoked", \
"Key was rejected by service", "Owner died", \
"State not recoverable", \
"Operation not possible due to RF-kill", \
"Memory page has hardware error"}
#endif

char *s21_strerror(int errnum) {
static char *str[] = ERRLIST;
char error[4096] = {0};
char stt[10];
static char strr[4096] = {'\0'};
for (int i = 0; i < 4096; i++)
    strr[i] = '\0';
if (errnum > (ERROR_NUM - 1) || errnum < 0) {
    s21_itoa(errnum, stt);
    s21_strcpy(error, STR_ERROR);
    s21_strncat(error, stt, s21_strlen(error));
    } else {
        s21_strcat(error, str[errnum]);
    }
    s21_strcat(strr, error);
    return strr;
}

void s21_itoa(int errnum, char* stt) {
int is_minus = 0;
if (errnum < 0) {
        errnum = (-1) * errnum;
        is_minus = 1;
}
int razryad = 0, errnum1 = errnum;
while (errnum1) {
    errnum1 = errnum1 / 10;
    razryad++;
}
if (is_minus == 1)
    *stt++ = '-';
while (razryad) {
    *stt++ = errnum/pow(10, (razryad - 1)) + 48;
    errnum = errnum % (int)pow(10, razryad - 1);
    razryad--;
}
*stt = '\0';
}

int s21_sprintf(const char* str, char* format, ...) {
    va_list list;
    va_start(list, format);
    int width, precision, lenght, end_flag = 0;
    char specify;
    struct flags flag;
    char* str_changed = (char*)str;
    while (*format != '\0' && !end_flag)  {
    s21_parcer(&format, &flag, &width, &precision, &lenght, &specify, &str_changed, &end_flag);
    s21_switcher(specify, lenght, &str_changed, &list, &flag, width, precision, end_flag);
    format++;
    }
    string_null_filler(&str_changed);
    va_end(list);
    return s21_strlen(str);
}

char* s21_strtok(char* str, const char* delim) {
    static char* str1 = 0;
    if (str)
        str1 = str;
    else if (!str1)
        return 0;
    str = str1 + s21_strspn(str1, delim);
    str1 = str + s21_strcspn(str, delim);
    if (str1 == str)
        return str1 = 0;
    str1 = *str1 ? *str1 = 0, str1 + 1 : 0;
    return str;
}

char* s21_strstr(const char* str1, const char* str2) {
    int i = 0;
    char* str3 = (char*)str1;
    while (*(str1 + i)) {
        if ( s21_memcmp(str3++, str2, s21_strlen(str2)) == 0 )
            return --str3;
        i++;
    }
    return 0;
}

char* s21_strrchr(const char* str, int c) {
    char* string = (char*)str;
    int i = s21_strlen(str);
    while (i >= 0) {
        if (string[i] == c)
            return (string + i);
        i--;
    }
    string = 0;
    return string;
}

s21_size_t s21_strspn(const char* str1, const char* str2) {
    int lenght = 0, i = 0, j = 0, flag;
    while (*(str1 + i)) {
        flag = 0;
        while (*(str2 + j)) {
            if (*(str1 + i) == *(str2 + j)) {
                lenght++;
                flag = 1;
                break;
            }
            j++;
        }
        j = 0;
        i++;
        if (flag == 0)
            break;
    }
    return (s21_size_t)lenght;
}

s21_size_t s21_strcspn(const char* str1, const char* str2) {
    s21_size_t count = 0;
    int i = 0, flag = 0;
    while (*(str1 + count)) {
        while (*(str2 + i)) {
            if (*(str1 + count) == *(str2 + i)) {
                flag = 1;
                break;
            } else {
                i++;
            }
        }
        if (flag == 1)
        break;
        i = 0;
        count++;
    }
    return count;
}

s21_size_t s21_strlen(const char* str) {
    s21_size_t len = 0;
    while (*(str + len))
        len++;
    return len;
}

char* s21_strpbrk(const char* str1, const char* str2) {
    int i = 0, count = 0, flag = 0;
    char* str11 = (char*)str1;
    while (*(str1 + count)) {
        while (*(str2 + i)) {
            if (*(str1 + count) == *(str2 + i)) {
                flag = 1;
                break;
            } else {
                i++;
            }
        }
        if (flag == 1)
            return (str11 + count);
        i = 0;
        count++;
    }
    return 0;
}

char* s21_strncpy(char* dest, const char* src, s21_size_t n) {
    int i = 0;
    while (n--) {
        *(dest + i) = *(src + i);
        i++;
    }
    return dest;
}

char* s21_strcpy(char* dest, const char* src) {
    char *tmp = dest;
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return tmp;
}

char* s21_strcat(char* dest, const char* src) {
    unsigned char* s1 = (unsigned char*)dest;
    unsigned char* s2 = (unsigned char*)src;
    int i = 0, j = 0, k = 0;
    while (s1[i] != '\0')
        i++;
    while (s2[j] != '\0')
        j++;
    k = i + j;
    j = 0;
    while (i < k) {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    return (dest);
}

char* s21_strncat(char* dest, const char* src, s21_size_t n) {
    int i = 0;
    while (*(dest + i))
        i++;
    for (int j = 0; j < (int)n; j++) {
        *(dest + i + j) = *(src + j);
    }
    return dest;
}

// int s21_strcmp(const char* str1, const char* str2) {
//     int i = 0;
//     for (i = 0; *(str1 + i); i++) {
//         if (*(str1 + i) == *(str2 + i)) {
//             i++;
//         } else {
//             break;
//         }
//     }
//     return *(str1+i) - *(str2+i);
// }

int s21_strcmp(const char* str1, const char* str2) {
    unsigned char* s1 = (unsigned char*)str1;
    unsigned char* s2 = (unsigned char*)str2;
    if (s1[0] == '\0')
        return (-(*s2));
    if (s2[0] == '\0')
        return (*s1);
    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (0);
}

void* s21_memmove(void* dest, const void* src, s21_size_t n) {
    const unsigned char* src1 = src;
    unsigned char* dest1 = dest;
    for (s21_size_t i = 0; i < n; i++)
        dest1[i] = src1[i];
    return dest;
}

void *s21_memset(void* str, int c, s21_size_t n) {
    unsigned char* str1 = str;
    while (n--) {
        *str1 = c;
        str1++;
    }
    return str;
}

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
    const unsigned char* string1 = str1, *string2 = str2;
    int i = 0, m = (int)n;
    while (i < m) {
        if (string1[i] == string2[i]) {
            i++;
        } else {
            i++;
            break;
        }
    }
    return string1[i-1]-string2[i-1];
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char *p = (unsigned char*)str;
    int m = (int)n;
    while (m > 0) {
        if (*p != (unsigned char)c)
            p++;
        else
            return p;
        m--;
    }
    return 0;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *dp = dest;
    const char *sp = src;
    while (n--)
        *dp++ = *sp++;
    return dest;
}

char *s21_strchr(const char *str, int c) {
    while (*str != (char)c)
        if (!*str++)
            return 0;
    return (char *)str;
}

int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
int m = (int)n, i;
for (i = 0; i < m; i++) {
    if (str1[i] != str2[i]) {
        i++;
        break;
    }
}
return ((unsigned char)*(str1 + i - 1) - (unsigned char)*(str2 + i - 1));
}

void s21_switcher(char specify, int lenght, char** str_changed, va_list* list, \
struct flags* flag, int width, int precision, int end_flag) {
    if (end_flag != 1) {
    if (specify == 'd' || specify == 'i') {
        if (lenght == 0) {
            int arg = va_arg(*list, int);
            int_filler(str_changed, arg, flag, width, precision);
        } else if (lenght == 1) {
            short int arg = va_arg(*list, int);
            int_filler(str_changed, arg, flag, width, precision);
        } else if (lenght == 2) {
            long int arg = va_arg(*list, long int);
            int_filler(str_changed, arg, flag, width, precision);
        }
    } else if (specify == 'u') {
        if (lenght == 0) {
            unsigned int arg = va_arg(*list, unsigned int);
            unsigned_filler(str_changed, arg, flag, width, precision);
        } else if (lenght == 1) {
            unsigned short arg = va_arg(*list, unsigned int);
            unsigned_filler(str_changed, arg, flag, width, precision);
        } else if (lenght == 2) {
            unsigned long arg = va_arg(*list, unsigned long);
            unsigned_filler(str_changed, arg, flag, width, precision);
        }
    } else if (specify == 'f') {
        double arg = va_arg(*list, double);
        s21_float_filler(str_changed, arg, flag, width, precision);
    } else if (specify == 's' && lenght == 0) {
        char* arg = va_arg(*list, char*);
        string_filler_char(str_changed, arg, flag, width, precision);
    } else if (specify == 's' && lenght == 2) {
    wchar_t* arg = va_arg(*list, wchar_t*);
    string_filler(str_changed, arg, flag, width, precision);
    } else if (specify == 'c' && lenght == 0) {
        char arg = va_arg(*list, int);
        char_filler(str_changed, arg, flag, width);
    } else if (specify == 'c' && lenght == 2) {
        wchar_t arg = va_arg(*list, int);
        char_filler(str_changed, arg, flag, width);
    } else if (specify == '%') {
        **str_changed = '%';
        *str_changed = *str_changed + 1;
    }
    }
}


void s21_parcer(char** format, struct flags* flag, int* width, int* precision, \
int* lenght, char* specify, char** dest, int* end_flag) {
        flag->minus = 0;
        flag->plus = 0;
        flag->space = 0;
        *width = 0;
        *precision = 0;
        *lenght = 0;
        *specify = '\0';
        s21_sprintf_finder(format, dest, end_flag);
        if (*end_flag != 1) {
        s21_sprintf_flags(format, flag);
        s21_sprintf_width(format, width);
        s21_sprintf_precision(format, precision);
        s21_sprintf_lenght(format, lenght);
        s21_sprintf_specify(format, specify);
        }
}

void s21_sprintf_finder(char** format, char** dest, int* end_flag) {
while (**format != '%') {
    if (**format == '\0') {
        *end_flag = 1;
        break;
    }
    **dest = **format;
    *dest = *dest + 1;
        *format = *format + 1;
}
}

void s21_sprintf_flags(char** format, struct flags* f) {
    (*format)++;
    while (**format == '+' || **format == '-' || **format == ' ') {
    switch (**format) {
        case '+':
            f->plus = 1;
            *format = *format + 1;
            break;
        case '-':
            f->minus = 1;
            *format = *format + 1;
            break;
        case ' ':
            f->space = 1;
            *format = *format + 1;
            break;
    }
}
}

void s21_sprintf_width(char** format, int* width) {
    while (*(*format) >= '0' && *(*format) <= '9') {
        *width = *width * 10 + ((int)*(*format) - 48);
        *format = *format + 1;
    }
}

void s21_sprintf_precision(char** format, int* precision) {
    if (**format == '.') {
    *format = *format + 1;
    if (**format >= '0' && **format <= '9') {
        while (**format >= '0' && **format <= '9') {
        *precision = *precision * 10 + ((int)**format - 48);
        *format = *format + 1;
        }
    } else {
        *precision = -2;
    }
    } else {
        *precision = -1;
    }
}

void s21_sprintf_lenght(char** format, int* flag_lenght) {
    switch (**format) {
        case 'h':
            *flag_lenght = 1;
            *format = *format + 1;
            break;
        case 'l':
            *flag_lenght = 2;
            *format = *format + 1;
            break;
        default:
            *flag_lenght = 0;
            break;
    }
}

void s21_sprintf_specify(char** format, char* specify) {
    char* test_string = "cdifsu%";
    *specify = *(s21_strchr(test_string, **format));
}

void char_filler(char** dest, wchar_t arg, struct flags* flag, int width) {
if (flag->minus == 1) {
        **dest = arg;
        *dest = *dest + 1;
}
if (width != 0)
        width--;
while (width--) {
        **dest = ' ';
        *dest = *dest + 1;
}
if (flag->minus == 0) {
        **dest = arg;
        *dest = *dest + 1;
}
}

void parts_finder(long double number, long double* int_part, long double* float_part) {
*float_part = modfl(number, int_part);
}

void s21_float_filler(char** dest, long double arg, struct flags* flag, int width, int precision) {
long double float_part = 0, int_part_float = 0;
int is_minus = 0;
if (precision == -1)
    precision = 6;
if (precision == -2)
    precision = 0;
parts_finder(arg, &int_part_float, &float_part);
long long int int_part = (long long int)int_part_float;
if (int_part < 0)
        int_part = (-1) * int_part;
if (float_part < 0)
        float_part = (-1) * float_part;
if (arg < 0)
        is_minus = 1;
int int_razryad = razryad_finder(int_part);
char* buffer_int = (char*)malloc(sizeof(char) * (int_razryad + 1));
char* buffer_float = (char*)malloc(sizeof(char) * (precision + 1));
char* buffer_int1 = buffer_int;
char* buffer_float1 = buffer_float;
s21_int_to_char(&buffer_int, int_part, int_razryad);
s21_int_to_char_float(&buffer_float, float_part, precision, 16);
if (flag->minus == 1) {
        float_filler_left(dest, &buffer_int, &buffer_float, flag, width, precision, int_razryad, is_minus);
} else {
        float_filler_right(dest, &buffer_int, &buffer_float, flag, width, precision, int_razryad, is_minus);
}
free(buffer_int1);
free(buffer_float1);
}

void s21_int_to_char_float(char** buffer_float, long double number, int precision, int razryad) {
    int n = s21_min(precision, razryad);
    if (n != 0)
        n--;
    char* h = *buffer_float;
    do  {
        number *= 10;
        **buffer_float = (int)number + 48;
        *buffer_float = *buffer_float + 1;
        number = number - (int)number;
    } while (n--);
    if (precision > razryad) {
        for (int i = 0; i < (precision - razryad); i++) {
            **buffer_float = '0';
            *buffer_float = *buffer_float + 1;
        }
    } else {
        number *= 10;
        if ( (int)number >= 5 ) {
            while (1) {
                *buffer_float = *buffer_float - 1;
                if (**buffer_float == '9') {
                    **buffer_float = '0';
                } else {
                    **buffer_float = **buffer_float + 1;
                    break;
                }
            }
        }
    }
*buffer_float = h;
}


void float_filler_right(char** dest, char** buffer_int, char** buffer_float, \
struct flags* flag, int width, int precision, int int_razryad, int is_minus) {
if (flag->plus == 1 || is_minus == 1) {
        float_width_filler(dest, width-1, precision, int_razryad);
        if (is_minus == 1) {
                **dest = '-';
        } else {
                **dest = '+';
        }
        *dest = *dest + 1;
        float_arg_filler(dest, buffer_int, buffer_float, precision, int_razryad);
} else if (flag->space == 1 && is_minus == 0) {
        **dest = ' ';
        *dest = *dest + 1;
        float_width_filler(dest, width-1, precision, int_razryad);
        float_arg_filler(dest, buffer_int, buffer_float, precision, int_razryad);
} else {
        float_width_filler(dest, width, precision, int_razryad);
        float_arg_filler(dest, buffer_int, buffer_float, precision, int_razryad);
}
}

void float_filler_left(char** dest, char** buffer_int, char** buffer_float, \
struct flags* flag, int width, int precision, int int_razryad, int is_minus) {
if (flag->plus == 1 || is_minus == 1) {
        if (is_minus == 1) {
                **dest = '-';
        } else {
                **dest = '+';
        }
        *dest = *dest + 1;
        float_arg_filler(dest, buffer_int, buffer_float, precision, int_razryad);
        float_width_filler(dest, width-1, precision, int_razryad);
} else if (flag->space == 1 && is_minus == 0) {
        **dest = ' ';
        *dest = *dest + 1;
        float_arg_filler(dest, buffer_int, buffer_float, precision, int_razryad);
        float_width_filler(dest, width-1, precision, int_razryad);
} else {
        float_arg_filler(dest, buffer_int, buffer_float, precision, int_razryad);
        float_width_filler(dest, width, precision, int_razryad);
}
}

void float_width_filler(char** dest, int width, int precision, int int_razryad) {
if (precision != 0) {
        for (int i = 0; i < (width - (int_razryad + precision + 1)); i++) {
                **dest = ' ';
                *dest = *dest + 1;
        }
} else {
        for (int i = 0; i < (width - (int_razryad + precision)); i++) {
                **dest = ' ';
                *dest = *dest + 1;
        }
}
}

void float_arg_filler(char** dest, char** buffer_int, char** buffer_float, int precision, int int_razryad) {
for (int i = 0; i < int_razryad; i++) {
        **dest = **buffer_int;
        *dest = *dest + 1;
        *buffer_int = *buffer_int + 1;
}
char* save_b = *dest;
if (precision != 0) {
    **dest = '.';
    *dest = *dest + 1;
} else {
    if ( **buffer_float >= '5' ) {
            while (1) {
                *dest = *dest - 1;
                if (**dest == '9') {
                    **dest = '0';
                } else {
                    **dest = **dest + 1;
                    break;
                }
            }
        }
    *dest = save_b;
}
for (int i = 0; i < precision; i++) {
        **dest = **buffer_float;
        *dest = *dest + 1;
        *buffer_float = *buffer_float + 1;
}
}

void int_filler(char** dest, long int arg, struct flags* flag, int width, int precision) {
int razryad = razryad_finder(arg);
int is_minus = 0;
if (arg < 0) {
        is_minus = 1;
    arg = (-1) * arg;
}
if (precision == -1)
        precision = 1;
if (precision == -2)
        precision = 0;
int maximum = s21_max(razryad, width);
maximum = s21_max(maximum, precision);
char* buffer = malloc(sizeof(char) * (maximum + 1));
char* buffer1 = buffer;
s21_int_to_char(&buffer, arg, razryad);
if (flag->minus == 0) {
        int_filler_right(dest, &buffer, flag, width, precision, razryad, is_minus);
} else {
        int_filler_left(dest, &buffer, flag, width, precision, razryad, is_minus);
}
free(buffer1);
}

void unsigned_filler(char** dest, unsigned long arg, struct flags* flag, int width, int precision) {
int razryad = unsigned_razryad_finder(arg);
int is_minus = 0;
if (precision == -1)
        precision = 1;
if (precision == -2)
        precision = 0;
int maximum = s21_max(razryad, width);
maximum = s21_max(maximum, precision);
char* buffer = malloc(sizeof(char) * (maximum + 1));
char* buffer1 = buffer;
s21_unsigned_to_char(&buffer, arg, razryad);
if (flag->minus == 0) {
        int_filler_right(dest, &buffer, flag, width, precision, razryad, is_minus);
} else {
        int_filler_left(dest, &buffer, flag, width, precision, razryad, is_minus);
}
free(buffer1);
}

int unsigned_razryad_finder(unsigned long number) {
int razryad = 0;
while (number) {
        number = (unsigned long)(number / 10);
        razryad++;
}
return razryad;
}

int razryad_finder(long long int number) {
int razryad = 0;
while (number) {
        number = (long int)(number / 10);
        razryad++;
}
return razryad;
}

void int_filler_right(char** dest, char** buffer, struct flags* flag, \
int width, int precision, int razryad, int is_minus) {
if (flag->plus == 1 || (flag->space == 1 && is_minus == 1) || is_minus == 1) {
        if (is_minus == 1) {
        int_width_filler(dest, width-1, precision, razryad);
        **dest = '-';
        *dest = *dest + 1;
        } else {
        int_width_filler(dest, width-1, precision, razryad);
        **dest = '+';
        *dest = *dest + 1;
        }
        int_precision_filler(dest, precision, razryad);
        int_arg_filler(dest, buffer, razryad);
} else if (flag->space == 1) {
        int_width_filler(dest, width-1, precision, razryad);
        **dest = ' ';
    *dest = *dest + 1;
        int_precision_filler(dest, precision, razryad);
        int_arg_filler(dest, buffer, razryad);
} else {
        int_width_filler(dest, width, precision, razryad);
        int_precision_filler(dest, precision, razryad);
        int_arg_filler(dest, buffer, razryad);
}
}

void int_filler_left(char** dest, char** buffer, struct flags* flag, \
int width, int precision, int razryad, int is_minus) {
if (flag->plus == 1 || (flag->space == 1 && is_minus == 1) || is_minus == 1) {
          if (is_minus == 1) {
                **dest = '-';
                *dest = *dest + 1;
          } else {
                **dest = '+';
                *dest = *dest + 1;
          }
          int_precision_filler(dest, precision, razryad);
          int_arg_filler(dest, buffer, razryad);
          int_width_filler(dest, width-1, precision, razryad);
} else if (flag->space == 1) {
          **dest = ' ';
    *dest = *dest + 1;
          int_precision_filler(dest, precision, razryad);
          int_arg_filler(dest, buffer, razryad);
          int_width_filler(dest, width-1, precision, razryad);
} else {
          int_precision_filler(dest, precision, razryad);
          int_arg_filler(dest, buffer, razryad);
          int_width_filler(dest, width, precision, razryad);
}
}

int s21_max(int x1, int x2) {
if (x2 > x1)
        x1 = x2;
return x1;
}

void int_width_filler(char** dest, int width, int precision, int razryad) {
        for (int i = 0; i < (width - s21_max(precision, razryad)); i++) {
                **dest = ' ';
                *dest = *dest + 1;
        }
}

void int_precision_filler(char** dest, int precision, int razryad) {
        for (int i = 0; i < (precision - razryad); i++) {
                **dest = '0';
                *dest = *dest + 1;
}
}

void int_arg_filler(char** dest, char** buffer, int razryad) {
for (int i = 0; i < razryad; i++) {
        **dest = **buffer;
        *dest = *dest + 1;
        *buffer = *buffer + 1;
}
}

void s21_int_to_char(char** buffer, long long int arg, int razryad) {
int fictive_razryad = razryad;
char** buffer1 = buffer;
for (int i = 0; i < razryad; i++) {
        *(*buffer + i) = arg/(pow(10, (fictive_razryad - 1))) + 48;
        arg = (arg % (long int)(pow(10, (fictive_razryad - 1))));
        fictive_razryad--;
}
*buffer = *buffer1;
}

void s21_unsigned_to_char(char** buffer, unsigned long arg, int razryad) {
int fictive_razryad = razryad;
char** buffer1 = buffer;
for (int i = 0; i < razryad; i++) {
        *(*buffer + i) = arg/(pow(10, (fictive_razryad - 1))) + 48;
        arg = (arg % (unsigned long)(pow(10, (fictive_razryad - 1))));
        fictive_razryad--;
}
*buffer = *buffer1;
}

void string_filler(char** dest, wchar_t* arg, struct flags* flag, int width, int precision) {
int str_lenght = (int)s21_strlen_self(arg);
if (precision == -2)
    precision = 0;
if (flag->minus == 0) {
        string_width_filler(dest, width, precision, str_lenght);
        string_arg_filler(dest, arg, precision, str_lenght);
} else {
        string_arg_filler(dest, arg, precision, str_lenght);
        string_width_filler(dest, width, precision, str_lenght);
}
}

void string_null_filler(char** dest) {
**dest = 0;
}

s21_size_t s21_strlen_self(wchar_t* arg) {
s21_size_t counter = 0;
while (*arg++)
        counter++;
return counter;
}

int s21_min(int x1, int x2) {
if (x2 < x1)
        x1 = x2;
return x1;
}

void string_width_filler(char** dest, int width, int precision, int str_lenght) {
if (precision != -1) {
    for (int i = 0; i < width - s21_min(str_lenght, precision); i++) {
        **dest = ' ';
        *dest = *dest + 1;
}
} else {
        for (int i = 0; i < width - str_lenght; i++) {
                **dest = ' ';
                *dest = *dest + 1;
        }
}
}

void string_arg_filler(char** dest, wchar_t* arg, int precision, int str_lenght) {
if (precision != -1) {
        for (int i = 0; i < s21_min(str_lenght, precision); i++) {
                **dest = *arg;
                *dest = *dest + 1;
                arg++;
        }
} else {
        for (int i = 0; i < str_lenght; i++) {
                **dest = *arg;
                *dest = *dest + 1;
                arg++;
        }
}
}

void string_filler_char(char** dest, char* arg, struct flags* flag, int width, int precision) {
int str_lenght = (int)s21_strlen(arg);
if (precision == -2)
    precision = 0;
if (flag->minus == 0) {
        string_width_filler(dest, width, precision, str_lenght);
        string_arg_filler_char(dest, arg, precision, str_lenght);
} else {
        string_arg_filler_char(dest, arg, precision, str_lenght);
        string_width_filler(dest, width, precision, str_lenght);
}
}

void string_arg_filler_char(char** dest, char* arg, int precision, int str_lenght) {
if (precision != -1) {
        for (int i = 0; i < s21_min(str_lenght, precision); i++) {
                **dest = *arg;
                *dest = *dest + 1;
                arg++;
        }
} else {
        for (int i = 0; i < str_lenght; i++) {
                **dest = *arg;
                *dest = *dest + 1;
                arg++;
        }
}
}

//  |  Part 5
//  V

void *s21_to_upper(const char *str) {
    int i = 0;
    int len = 0;
    char c;
    while (str[len] != '\0')
        len++;
    char* buffer = (char*)malloc(sizeof(char) * len);
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            c = (char)((int)str[i]) - 32;
            buffer[i] = c;
        } else {
            buffer[i] = str[i];
        }
        i++;
    }
    buffer[i] = '\0';
    return buffer;
}

void *s21_to_lower(const char *str) {
    int i = 0;
    int len = 0;
    char c;
    while (str[len] != '\0')
        len++;
    char* buffer = (char*)malloc(sizeof(char) * len);
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            c = (char)((int)str[i]) + 32;
            buffer[i] = c;
        } else {
            buffer[i] = str[i];
        }
        i++;
    }
    buffer[i] = '\0';
    return buffer;
}

void *s21_trim(const char *src, const char *trim_chars) {
    int src_len = 0, trim_len = 0, left = 0, right = 0;
    while (src[src_len] != '\0')
        src_len++;
    while (trim_chars[trim_len] != '\0')
        trim_len++;
    int flag_break = 0;
    for (int i = 0, count = 0; i < src_len && flag_break == 0; ++i) {
        for (int j = 0; j < trim_len; ++j)
            if (src[i] != trim_chars[j])
                ++count;
        if (count == trim_len) {
            left = i;
            flag_break = 1;
        }
        count = 0;
    }
    flag_break = 0;
    for (int i = src_len-1, count = 0; i >= 0 && flag_break == 0; --i) {
        for (int j = 0; j < trim_len; ++j)
            if (src[i] != trim_chars[j])
                ++count;
        if (count == trim_len) {
            right = i;
            flag_break = 1;
        }
        count = 0;
    }
    char* buff = (char*)malloc(sizeof(char) * (src_len + trim_len));
    for (int i = 0; i < (src_len + trim_len); i++) {
        buff[i] = '\0';
    }
    if (left < right) {
        for (int i = 0, j = left; i < right - left + 1; ++i, ++j)
            buff[i] = src[j];
        buff[right+1] = '\0';
    }
    return buff;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    int lenght_source = s21_strlen(src);
    int lenght_str = s21_strlen(str);
    char* s1 = (char*)malloc(sizeof(char) * (lenght_source + lenght_str));
    for (int i = 0; i < (lenght_source + lenght_str); i++) {
        s1[i] = '\0';
    }
    int i = 0, j = 0;
    char s3[200] = {0};
    for (i = start_index, j = 0; i <= lenght_source; i++, j++) {
        s3[j] = src[i];
    }
    s21_memcpy(s1, src, start_index);
    s21_strcat(s1, str);
    s21_strcat(s1, s3);
    *(s1 + lenght_source + lenght_str) = '\0';
    return s1;
}
