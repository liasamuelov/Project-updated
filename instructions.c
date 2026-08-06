/* ********************************************************************
 * FILE: instructions.c
 * OWNER / מי מממשת: שלד - מוכן
 * STATUS: READY
 * מה עושים כאן: טבלת כל ההוראות של המכונה (opcode/funct) ובדיקת מילים שמורות. רק להשתמש, לא לגעת.
 * ******************************************************************** */

/*
 * instructions.c - the full instruction table of the imaginary machine,
 * taken from the opcode/funct table in the project booklet.
 */
#include <string.h>
#include "instructions.h"

static const instruction_info instruction_table[] = {
    /* R-type arithmetic and logic: shared opcode 0, distinguished by funct */
    {"add",  INST_R,  0, 1, 3},
    {"sub",  INST_R,  0, 2, 3},
    {"and",  INST_R,  0, 3, 3},
    {"or",   INST_R,  0, 4, 3},
    {"nor",  INST_R,  0, 5, 3},
    /* R-type copy instructions: shared opcode 1, distinguished by funct */
    {"move", INST_R,  1, 1, 2},
    {"mvhi", INST_R,  1, 2, 2},
    {"mvlo", INST_R,  1, 3, 2},
    /* I-type arithmetic and logic */
    {"addi", INST_I, 10, 0, 3},
    {"subi", INST_I, 11, 0, 3},
    {"andi", INST_I, 12, 0, 3},
    {"ori",  INST_I, 13, 0, 3},
    {"nori", INST_I, 14, 0, 3},
    /* I-type conditional branches */
    {"bne",  INST_I, 15, 0, 3},
    {"beq",  INST_I, 16, 0, 3},
    {"blt",  INST_I, 17, 0, 3},
    {"bgt",  INST_I, 18, 0, 3},
    /* I-type load / store */
    {"lb",   INST_I, 19, 0, 3},
    {"sb",   INST_I, 20, 0, 3},
    {"lw",   INST_I, 21, 0, 3},
    {"sw",   INST_I, 22, 0, 3},
    {"lh",   INST_I, 23, 0, 3},
    {"sh",   INST_I, 24, 0, 3},
    /* J-type */
    {"jmp",  INST_J, 30, 0, 1},
    {"la",   INST_J, 31, 0, 1},
    {"call", INST_J, 32, 0, 1},
    {"hlt",  INST_J, 63, 0, 0}
};

#define INSTRUCTION_COUNT (sizeof(instruction_table) / sizeof(instruction_table[0]))

/* Directive names (without the leading '.') and macro keywords are also
   reserved and cannot serve as labels or macro names. */
static const char *other_reserved[] = {
    "db", "dw", "dh", "asciz", "entry", "extern", "mcro", "mcroend"
};

#define OTHER_RESERVED_COUNT (sizeof(other_reserved) / sizeof(other_reserved[0]))

const instruction_info *find_instruction(const char *name)
{
    size_t i;
    for (i = 0; i < INSTRUCTION_COUNT; i++) {
        if (strcmp(instruction_table[i].name, name) == 0)
            return &instruction_table[i];
    }
    return NULL;
}

boolean is_reserved_word(const char *name)
{
    size_t i;
    if (find_instruction(name) != NULL)
        return TRUE;
    for (i = 0; i < OTHER_RESERVED_COUNT; i++) {
        if (strcmp(other_reserved[i], name) == 0)
            return TRUE;
    }
    return FALSE;
}
