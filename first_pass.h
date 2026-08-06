/* ********************************************************************
 * FILE: first_pass.h
 * OWNER / מי מממשת: מאיה
 * STATUS: TODO - לממש
 * מה עושים כאן: הממשק של המעבר הראשון.
 * ******************************************************************** */

/*
 * first_pass.h - the first pass of the assembler.
 * OWNER: Maya.
 */
#ifndef FIRST_PASS_H
#define FIRST_PASS_H

#include <stdio.h>
#include "globals.h"
#include "symbol_table.h"
#include "memory_image.h"

/* Runs the first pass over the expanded (.am) source file:
   builds the symbol table, encodes everything that can already be encoded
   (data, opcode/funct/register fields, immediates of arithmetic I-type),
   and reports syntax errors. At the end, offsets the data symbols and the
   data addresses by ICF. Returns TRUE if no errors were found. */
boolean first_pass(FILE *am_file, const char *filename,
                   memory_image *img, symbol_table *symtab);

#endif /* FIRST_PASS_H */
