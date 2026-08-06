/* ********************************************************************
 * FILE: macro_table.h
 * OWNER / מי מממשת: ליה
 * STATUS: TODO - מוגדר, לממש ב-c
 * מה עושים כאן: הממשק של טבלת המאקרואים. המבנים והפרוטוטיפים כבר מוגדרים, המימוש בקובץ ה-c עלייך.
 * ******************************************************************** */

/*
 * macro_table.h - the macro table used by the pre-assembler.
 * Each macro has a name and a list of source lines (its body).
 * Implemented as linked lists with dynamic allocation, exactly like
 * symbol_table - use symbol_table.c as your reference pattern.
 */
#ifndef MACRO_TABLE_H
#define MACRO_TABLE_H

#include "globals.h"

/* One source line inside a macro body */
typedef struct macro_line {
    char *text;                 /* the line itself, dynamically allocated */
    struct macro_line *next;
} macro_line;

/* One macro: its name and the list of its body lines (kept in order) */
typedef struct macro_node {
    char *name;                 /* macro name, dynamically allocated */
    macro_line *first_line;
    macro_line *last_line;      /* kept so add_line appends in O(1) */
    struct macro_node *next;
} macro_node;

typedef struct {
    macro_node *head;
} macro_table;

/* Initializes an empty macro table. */
void macrotab_init(macro_table *table);

/* Returns the macro with the given name, or NULL if there is no such macro. */
macro_node *macrotab_find(const macro_table *table, const char *name);

/* Adds a new empty macro with the given name and returns its node
   (NULL on allocation failure). The caller must first verify that the
   name is legal (not a reserved word, not already defined). */
macro_node *macrotab_add(macro_table *table, const char *name);

/* Appends one body line to the macro (at the end, to keep the order).
   Returns FALSE on allocation failure. */
boolean macrotab_add_line(macro_node *macro, const char *line);

/* Frees all macros and all their lines. */
void macrotab_free(macro_table *table);

#endif /* MACRO_TABLE_H */
