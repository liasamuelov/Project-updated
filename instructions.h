/* ********************************************************************
 * FILE: instructions.h
 * OWNER / מי מממשת: שלד - מוכן
 * STATUS: READY
 * מה עושים כאן: הממשק של טבלת ההוראות. רק להשתמש, לא לגעת.
 * ******************************************************************** */

/*
 * instructions.h - the instruction set of the imaginary machine.
 * Provides lookup of an instruction by its name, and a reserved-word
 * check used when validating label and macro names.
 */
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "globals.h"

/* The three instruction encoding formats */
typedef enum { INST_R, INST_I, INST_J } instruction_type;

typedef struct {
    const char *name;      /* instruction name, always lower case */
    instruction_type type; /* R / I / J */
    unsigned int opcode;
    unsigned int funct;    /* 0 when the instruction has no funct field */
    int num_operands;      /* number of operands in the assembly syntax */
} instruction_info;

/* Returns the table entry of the given instruction name,
   or NULL if no such instruction exists. */
const instruction_info *find_instruction(const char *name);

/* Returns TRUE if name is a reserved word of the language (an instruction
   name, a directive name without the '.', or mcro/mcroend), and therefore
   cannot be used as a label name or as a macro name. */
boolean is_reserved_word(const char *name);

#endif /* INSTRUCTIONS_H */
