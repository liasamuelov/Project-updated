/* ********************************************************************
 * FILE: globals.h
 * OWNER / מי מממשת: שלד - מוכן
 * STATUS: READY
 * מה עושים כאן: קבועים משותפים לכל הפרויקט (אורך שורה, IC התחלתי וכו'). לא צריך לגעת.
 * ******************************************************************** */

/*
 * globals.h - project-wide constants and basic shared types.
 * Included by every module.
 */
#ifndef GLOBALS_H
#define GLOBALS_H

/* Maximum length of a source line, not including the '\n' character */
#define MAX_LINE_LENGTH 80

/* Buffer size for reading a line: content + '\n' + '\0' + one extra
   character used to detect lines that are longer than allowed */
#define LINE_BUFFER_SIZE (MAX_LINE_LENGTH + 3)

/* Maximum length of a label (symbol) name */
#define MAX_LABEL_LENGTH 31

/* The code image is built to be loaded starting at this address */
#define IC_INIT_VALUE 100

/* Number of general registers ($0 .. $31) */
#define NUM_REGISTERS 32

/* Simple boolean type (ANSI C has no stdbool.h) */
typedef enum { FALSE = 0, TRUE = 1 } boolean;

#endif /* GLOBALS_H */
