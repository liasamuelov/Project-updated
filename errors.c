/* ********************************************************************
 * FILE: errors.c
 * OWNER / מי מממשת: מאיה
 * STATUS: בסיס מוכן - להרחיב
 * מה עושים כאן: דיווח שגיאות עם שם קובץ ומספר שורה. מאיה מרחיבה בסוגי שגיאות לפי הצורך של המעבר הראשון.
 * ******************************************************************** */

/*
 * errors.c - implementation of error reporting.
 */
#include <stdio.h>
#include <stdarg.h>
#include "errors.h"

void report_error(const char *filename, int line_number, const char *format, ...)
{
    va_list args;
    if (line_number > 0)
        printf("%s:%d: error: ", filename, line_number);
    else
        printf("%s: error: ", filename);
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
}
