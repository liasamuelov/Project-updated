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


/* ------------------------------------------------------------------ *
 * חוזה הפענוח המשותף - סוכם בזום 6.8.
 * מאיה מממשת את הפונקציות האלה ב-utils.c (המעבר הראשון צריך אותן
 * ראשון); שני המעברים משתמשים רק בהן ולא מפרקים שורות בעצמם.
 * ------------------------------------------------------------------ */

/* If the line starts with a label definition ("LABEL:"), copies the
   label (without the ':') into label_out, sets *rest to point right
   after the ':', and returns TRUE. Otherwise returns FALSE and sets
   *rest to the beginning of the line. Does NOT validate the label:
   the caller validates with is_legal_label and reports the error. */
boolean extract_label(const char *line, char *label_out, const char **rest);

/* Returns TRUE if name is a legal label: starts with a letter,
   contains only letters and digits, at most MAX_LABEL_LENGTH
   characters, and is not a reserved word (see is_reserved_word). */
boolean is_legal_label(const char *name);

/* Splits the operand part of a statement (the text after the operation
   name) into at most 3 operands, separated by single commas, with any
   amount of spaces/tabs around them. Returns the number of operands
   found (0 is legal, e.g. hlt), or -1 on a syntax error - missing
   comma, consecutive commas, comma before the first or after the last
   operand, or extraneous text - in which case *error_msg is set to a
   fixed English message for report_error. */
int split_operands(const char *text, char operands[3][MAX_LINE_LENGTH + 1],
                   const char **error_msg);

/* Parses an operand of the form "$N". Returns the register number in
   the range 0..NUM_REGISTERS-1, or -1 if the operand is not a legal
   register (no '$', not a number, or out of range). */
int parse_register(const char *operand);

/* Parses a whole decimal number with an optional leading + or - sign
   into *value_out. Returns FALSE if the operand is not a legal number.
   Range checking (16 bits for immed, .db/.dh/.dw sizes) is done by the
   caller, because the legal range depends on the context. */
boolean parse_number(const char *operand, long *value_out);

#endif /* UTILS_H */

