/* ********************************************************************
 * FILE: second_pass.h
 * OWNER / מי מממשת: ליה
 * STATUS: TODO - לממש
 * מה עושים כאן: הממשק של המעבר השני.
 * ******************************************************************** */

/*
 * second_pass.h - the second pass of the assembler.
 * OWNER: Lia.
 */
#ifndef SECOND_PASS_H
#define SECOND_PASS_H

#include <stdio.h>
#include "globals.h"
#include "symbol_table.h"
#include "memory_image.h"
#include "output.h"

/* Runs the second pass over the .am file: completes the encodings that
   need symbol values, marks entry symbols, and fills ext_list with every
   J-type use of an external symbol. Returns TRUE if no errors were found. */
boolean second_pass(FILE *am_file, const char *filename, memory_image *img,
                    symbol_table *symtab, ext_use **ext_list);

#endif /* SECOND_PASS_H */
