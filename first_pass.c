/* ********************************************************************
 * FILE: first_pass.c
 * OWNER / מי מממשת: מאיה
 * STATUS: TODO - לממש
 * מה עושים כאן: המעבר הראשון: בניית טבלת הסמלים, קידוד כל מה שאפשר כבר עכשיו, וגילוי שגיאות תחביר. האלגוריתם המלא, צעד-צעד, בהערה למטה.
 * ******************************************************************** */

/*
 * first_pass.c - the first pass of the assembler.
 * OWNER: Maya.
 *
 * TODO: implement according to the booklet's first-pass algorithm:
 *   1.  IC = 100, DC = 0 (image_init already does this).
 *   2.  Read the next line; on EOF go to step 17.
 *   3.  Skip empty and comment lines (is_empty_line / is_comment_line).
 *   4.  Check line length: more than MAX_LINE_LENGTH characters is an error.
 *   5.  If the line starts with a label, validate it (legal syntax, at most
 *       MAX_LABEL_LENGTH characters, not a reserved word, not already
 *       defined) and remember that a symbol is being defined.
 *   6.  .db/.dw/.dh/.asciz: insert the label (if any) with attribute
 *       SYM_DATA and value DC, then encode the numbers/characters into the
 *       data image with image_add_data (validate ranges per size!).
 *   7.  .entry: handled in the second pass, skip here.
 *   8.  .extern: insert the operand symbol with value 0 and SYM_EXTERNAL.
 *   9.  Otherwise this is an instruction line: insert the label (if any)
 *       with attribute SYM_CODE and value IC.
 *   10. Look up the operation with find_instruction; unknown name is an
 *       error. Parse the operands by instruction type (R/I/J), checking
 *       operand count, commas, register range 0..NUM_REGISTERS-1, and
 *       immediate range (16 bits, two's complement).
 *   11. Encode whatever is already known with image_add_instruction
 *       (opcode, funct, registers, arithmetic immediates); fields that
 *       need symbol values stay 0 and are completed in the second pass.
 *   12. On EOF: if errors were found, stop (no second pass, no output).
 *       Otherwise save ICF/DCF, call symtab_offset_data_symbols(symtab, ICF)
 *       so data symbols sit after the code in the final memory picture.
 *
 * Report every error with report_error and keep going: the assembler must
 * find as many errors as possible in one run.
 */
#include <stdio.h>
#include "first_pass.h"

boolean first_pass(FILE *am_file, const char *filename,
                   memory_image *img, symbol_table *symtab)
{
    (void)am_file;
    (void)filename;
    (void)img;
    (void)symtab;
    printf("first_pass: not implemented yet (owner: Maya)\n");
    return TRUE;
}
