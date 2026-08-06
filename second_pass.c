/* ********************************************************************
 * FILE: second_pass.c
 * OWNER / מי מממשת: ליה
 * STATUS: TODO - לממש
 * מה עושים כאן: המעבר השני: השלמת הקידוד בעזרת טבלת הסמלים, טיפול ב-entry וב-extern. האלגוריתם המלא, צעד-צעד, בהערה למטה.
 * ******************************************************************** */

/*
 * second_pass.c - the second pass of the assembler.
 * OWNER: Lia.
 *
 * TODO: implement according to the booklet's second-pass algorithm:
 *   1. Read the next line; on EOF go to step 9.
 *   2. Skip empty and comment lines.
 *   3. If the line starts with a label definition, skip the label.
 *   4. Directive lines other than .entry: nothing to do here.
 *   5. .entry: find the operand symbol in the table and add SYM_ENTRY with
 *      symtab_add_attribute; if the symbol is missing, report an error.
 *   6. Instruction lines: complete the missing encoding using the symbol
 *      table and image_set_instruction:
 *      - Conditional branches (beq/bne/blt/bgt): immed = symbol address
 *        minus this instruction's address (the distance can be negative);
 *        a branch to an external symbol is an error.
 *      - J-type (jmp/la/call with a label operand): address field = symbol
 *        value; for an external symbol encode 0 and call extlist_add with
 *        this instruction's address.
 *      - A symbol that does not exist in the table is an error.
 *   7. Track the current instruction address exactly like the first pass
 *      (advance by 4 per instruction line).
 *   8. Keep reporting errors and continue scanning.
 *   9. Return TRUE only if no errors were found (only then are output
 *      files written).
 */
#include <stdio.h>
#include "second_pass.h"

boolean second_pass(FILE *am_file, const char *filename, memory_image *img,
                    symbol_table *symtab, ext_use **ext_list)
{
    (void)am_file;
    (void)filename;
    (void)img;
    (void)symtab;
    (void)ext_list;
    printf("second_pass: not implemented yet (owner: Lia)\n");
    return TRUE;
}
