/* ********************************************************************
 * FILE: symbol_table.h
 * OWNER / מי מממשת: ליה
 * STATUS: READY - לקרוא ולהבין
 * מה עושים כאן: הממשק של טבלת הסמלים. המעבר הראשון (מאיה) כותב אליה, המעבר השני (ליה) קורא ממנה.
 * ******************************************************************** */

/*
 * symbol_table.h - the symbol (label) table, implemented as a linked list
 * with dynamic allocation, as required by the booklet.
 * OWNER: Lia (data tables).
 */
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "globals.h"

/* Symbol attributes, stored as a bit mask so a symbol can carry
   more than one attribute (e.g. data + entry). */
#define SYM_CODE     1
#define SYM_DATA     2
#define SYM_ENTRY    4
#define SYM_EXTERNAL 8

typedef struct symbol_node {
    char *name;                /* symbol name, dynamically allocated */
    long value;                /* address (or 0 for external symbols) */
    unsigned int attributes;   /* bit mask of SYM_* values */
    struct symbol_node *next;
} symbol_node;

typedef struct {
    symbol_node *head;
} symbol_table;

/* Initializes an empty table. */
void symtab_init(symbol_table *table);

/* Returns the node of the symbol with the given name, or NULL if absent. */
symbol_node *symtab_find(const symbol_table *table, const char *name);

/* Adds a new symbol to the table and returns its node
   (NULL on allocation failure). Does not check for duplicates:
   the caller must call symtab_find first and report an error if needed. */
symbol_node *symtab_add(symbol_table *table, const char *name,
                        long value, unsigned int attributes);

/* Adds an attribute (SYM_ENTRY etc.) to an existing symbol. */
void symtab_add_attribute(symbol_node *node, unsigned int attribute);

/* Adds offset to the value of every symbol marked as data.
   Called at the end of the first pass with offset = ICF, because the
   data image is placed in memory right after the code image. */
void symtab_offset_data_symbols(symbol_table *table, long offset);

/* Frees all nodes in the table. */
void symtab_free(symbol_table *table);

#endif /* SYMBOL_TABLE_H */
