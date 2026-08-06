/* ********************************************************************
 * FILE: memory_image.h
 * OWNER / מי מממשת: שלד - מוכן
 * STATUS: READY
 * מה עושים כאן: הממשק של תמונות הזיכרון.
 * ******************************************************************** */

/*
 * memory_image.h - the code image and data image built by the assembler,
 * together with the IC and DC counters. The booklet allows a fixed maximum
 * size for the memory images only (all other structures must be dynamic).
 * Values are stored little-endian, as the imaginary machine requires.
 */
#ifndef MEMORY_IMAGE_H
#define MEMORY_IMAGE_H

#include "globals.h"

#define CODE_IMAGE_MAX 8192
#define DATA_IMAGE_MAX 8192

typedef struct {
    unsigned char code[CODE_IMAGE_MAX]; /* code[0] is address IC_INIT_VALUE */
    long ic;                            /* next free address in the code image */
    unsigned char data[DATA_IMAGE_MAX]; /* data[0] is offset 0 */
    long dc;                            /* next free offset in the data image */
} memory_image;

/* Resets the image: ic = IC_INIT_VALUE, dc = 0. */
void image_init(memory_image *img);

/* Writes a 32-bit instruction word at the given address (little-endian),
   without advancing ic. Used by the second pass to complete encodings.
   Returns FALSE if the address is out of range. */
boolean image_set_instruction(memory_image *img, long address, unsigned long word);

/* Appends a 32-bit instruction word at ic (little-endian) and advances
   ic by 4. Returns FALSE if the code image is full. */
boolean image_add_instruction(memory_image *img, unsigned long word);

/* Appends a value of the given size in bytes (1 for .db, 2 for .dh,
   4 for .dw, 1 for each .asciz character) to the data image, little-endian,
   and advances dc. Returns FALSE if the data image is full. */
boolean image_add_data(memory_image *img, long value, int size);

#endif /* MEMORY_IMAGE_H */
