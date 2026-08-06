/* ********************************************************************
 * FILE: errors.h
 * OWNER / מי מממשת: מאיה
 * STATUS: בסיס מוכן - להרחיב
 * מה עושים כאן: הממשק של דיווח השגיאות.
 * ******************************************************************** */

/*
 * errors.h - centralized error reporting.
 * OWNER: Maya (errors). Extend this module with error-code enums and
 * any bookkeeping needed (e.g. a per-file error counter).
 */
#ifndef ERRORS_H
#define ERRORS_H

#include "globals.h"

/* Prints a formatted error message to stdout (as the booklet requires),
   in the form "file:line: error: message". Line numbering starts at 1.
   Pass line_number 0 for errors that are not tied to a specific line. */
void report_error(const char *filename, int line_number, const char *format, ...);

#endif /* ERRORS_H */
