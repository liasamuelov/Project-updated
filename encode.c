/* ********************************************************************
 * FILE: encode.c
 * OWNER / מי מממשת: שלד - מוכן (מודול משותף)
 * STATUS: READY
 * מה עושים כאן: המימוש של בניית מילות הקידוד, בהזזות ביטים ומסכות לפי טבלאות הפורמטים בחוברת.
 * ******************************************************************** */

/*
 * encode.c - implementation of the instruction-word builders.
 * Each field is masked to its exact width and shifted to its position.
 * Negative values (immed) become two's complement automatically by the
 * unsigned masking.
 */
#include "encode.h"

unsigned long build_r_word(unsigned int opcode, unsigned int funct,
                           int rs, int rt, int rd)
{
    unsigned long word = 0;
    word |= ((unsigned long)opcode & 0x3FUL) << 26;   /* 6 bits: 31-26 */
    word |= ((unsigned long)rs     & 0x1FUL) << 21;   /* 5 bits: 25-21 */
    word |= ((unsigned long)rt     & 0x1FUL) << 16;   /* 5 bits: 20-16 */
    word |= ((unsigned long)rd     & 0x1FUL) << 11;   /* 5 bits: 15-11 */
    word |= ((unsigned long)funct  & 0x1FUL) << 6;    /* 5 bits: 10-6  */
    return word;                                      /* bits 5-0 stay 0 */
}

unsigned long build_i_word(unsigned int opcode, int rs, int rt, long immed)
{
    unsigned long word = 0;
    word |= ((unsigned long)opcode & 0x3FUL)   << 26;
    word |= ((unsigned long)rs     & 0x1FUL)   << 21;
    word |= ((unsigned long)rt     & 0x1FUL)   << 16;
    word |= ((unsigned long)immed  & 0xFFFFUL);       /* 16 bits, two's complement */
    return word;
}

unsigned long build_j_word(unsigned int opcode, int reg_flag, long address)
{
    unsigned long word = 0;
    word |= ((unsigned long)opcode   & 0x3FUL)      << 26;
    word |= ((unsigned long)reg_flag & 0x1UL)       << 25;
    word |= ((unsigned long)address  & 0x1FFFFFFUL);  /* 25 bits: 24-0 */
    return word;
}
