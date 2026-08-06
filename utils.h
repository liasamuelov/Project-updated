/* ********************************************************************
 * FILE: utils.h
 * OWNER / מי מממשת: שלד - מוכן
 * STATUS: READY
 * מה עושים כאן: הממשק של פונקציות העזר.
 * ******************************************************************** */

/*
 * utils.h - small general-purpose helpers used by all modules
 * (whitespace handling, line classification, filename manipulation).
 */
#ifndef UTILS_H
#define UTILS_H

#include "globals.h"

/* Returns a pointer to the first character in s that is not a space or a tab. */
const char *skip_whitespace(const char *s);

/* Removes a trailing '\n' (and '\r', for files edited on Windows) in place. */
void strip_newline(char *line);

/* Returns TRUE if the line contains only whitespace characters. */
boolean is_empty_line(const char *line);

/* Returns TRUE if the first non-whitespace character of the line is ';'. */
boolean is_comment_line(const char *line);

/* Allocates and returns a copy of s (strdup is not part of ANSI C).
   Returns NULL on allocation failure. */
char *dup_string(const char *s);

/* Returns TRUE if filename ends with the given extension (e.g. ".as"). */
boolean has_extension(const char *filename, const char *extension);

/* Returns a newly allocated filename in which the extension of filename
   (the part starting at the last '.') is replaced by new_extension.
   If filename has no extension, new_extension is simply appended.
   The caller is responsible for freeing the result. */
char *replace_extension(const char *filename, const char *new_extension);

#endif /* UTILS_H */
