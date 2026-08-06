/* ********************************************************************
 * FILE: encode.h
 * OWNER / מי מממשת: שלד - מוכן (מודול משותף)
 * STATUS: READY
 * מה עושים כאן: בניית מילת הקידוד של 32 סיביות לכל אחד משלושת הפורמטים. שני המעברים משתמשים באותן פונקציות, כדי שהקידוד יהיה זהה תמיד.
 * ******************************************************************** */

/*
 * encode.h - building the 32-bit machine word of an instruction.
 * These are pure functions: they receive the field values and return
 * the assembled word. Pass 1 calls them with what is already known
 * (symbol-dependent fields as 0), and pass 2 calls them again with the
 * final values and overwrites the word via image_set_instruction.
 */
#ifndef ENCODE_H
#define ENCODE_H

/* R-format: opcode(31-26) rs(25-21) rt(20-16) rd(15-11) funct(10-6) unused(5-0) */
unsigned long build_r_word(unsigned int opcode, unsigned int funct,
                           int rs, int rt, int rd);

/* I-format: opcode(31-26) rs(25-21) rt(20-16) immed(15-0).
   immed may be negative; it is stored in 16-bit two's complement.
   The caller must verify beforehand that immed fits in 16 bits. */
unsigned long build_i_word(unsigned int opcode, int rs, int rt, long immed);

/* J-format: opcode(31-26) reg(25) address(24-0).
   reg_flag is 1 when the jump target is a register (then address holds
   the register number), and 0 when the target is a label address. */
unsigned long build_j_word(unsigned int opcode, int reg_flag, long address);

#endif /* ENCODE_H */
