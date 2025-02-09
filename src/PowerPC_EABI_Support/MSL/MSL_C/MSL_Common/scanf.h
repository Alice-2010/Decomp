#ifndef _MSL_SCANF_H
    #define _MSL_SCANF_H

    #include "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/file_def.h"
    #include "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/restrict_def.h"
    #include "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/va_list_def.h"

    #ifdef __cplusplus
        extern "C" {
    #endif

    int scanf(const char *RESTRICT format, ...);
    int fscanf(FILE *RESTRICT stream, const char *RESTRICT format, ...);
    int sscanf(const char *RESTRICT buffer, const char *RESTRICT format, ...);

    int vscanf(const char *RESTRICT format, va_list vlist);
    int vfscanf(FILE *RESTRICT stream, const char *RESTRICT format, va_list vlist);
    int vsscanf(const char *RESTRICT buffer, const char *RESTRICT format, va_list vlist);

    #ifdef __cplusplus
        }
    #endif

#endif
