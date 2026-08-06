/* ********************************************************************
 * FILE: output.h
 * OWNER / מי מממשת: שלד - מוכן
 * STATUS: READY
 * מה עושים כאן: הממשק של קובצי הפלט + רשימת השימושים בסמלים חיצוניים.
 * ******************************************************************** */

/*
 * output.h - creation of the output files (.ob, .ent, .ext), and the list
 * of code addresses that use external symbols (filled by the second pass).
 * Already implemented in the skeleton.
 */
#ifndef OUTPUT_H
#define OUTPUT_H

#include "globals.h"
#include "symbol_table.h"
#include "memory_image.h"

/* One use of an external symbol as an operand of a J-type instruction:
   the symbol name and the address of the instruction that uses it.
   The second pass appends a node for every such use. */
typedef struct ext_use {
    char *symbol_name;
    long address;
    struct ext_use *next;
} ext_use;

/* Adds a use of an external symbol to the list. Returns FALSE on
   allocation failure. */
boolean extlist_add(ext_use **list, const char *symbol_name, long address);

/* Frees the whole list. */
void extlist_free(ext_use *list);

/* Writes the output files next to the source file:
   .ob always; .ent only if some symbol has the entry attribute;
   .ext only if the external-use list is not empty.
   Returns TRUE on success. */
boolean write_output_files(const char *as_filename, const memory_image *img,
                           const symbol_table *symtab, const ext_use *ext_list);

#endif /* OUTPUT_H */
