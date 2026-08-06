/* ********************************************************************
 * FILE: memory_image.c
 * OWNER / מי מממשת: שלד - מוכן
 * STATUS: READY
 * מה עושים כאן: תמונות הקוד והנתונים (IC/DC), אריזה ב-little-endian. רק להשתמש, לא לגעת.
 * ******************************************************************** */

/*
 * memory_image.c - implementation of the code and data images.
 */
#include "memory_image.h"

void image_init(memory_image *img)
{
    img->ic = IC_INIT_VALUE;
    img->dc = 0;
}

boolean image_set_instruction(memory_image *img, long address, unsigned long word)
{
    long index = address - IC_INIT_VALUE;
    if (index < 0 || index + 4 > CODE_IMAGE_MAX)
        return FALSE;
    /* little-endian: the least significant byte goes to the lowest address */
    img->code[index]     = (unsigned char)(word & 0xFF);
    img->code[index + 1] = (unsigned char)((word >> 8) & 0xFF);
    img->code[index + 2] = (unsigned char)((word >> 16) & 0xFF);
    img->code[index + 3] = (unsigned char)((word >> 24) & 0xFF);
    return TRUE;
}

boolean image_add_instruction(memory_image *img, unsigned long word)
{
    if (image_set_instruction(img, img->ic, word) == FALSE)
        return FALSE;
    img->ic += 4;
    return TRUE;
}

boolean image_add_data(memory_image *img, long value, int size)
{
    int i;
    unsigned long uvalue = (unsigned long)value;
    if (img->dc + size > DATA_IMAGE_MAX)
        return FALSE;
    for (i = 0; i < size; i++)
        img->data[img->dc + i] = (unsigned char)((uvalue >> (8 * i)) & 0xFF);
    img->dc += size;
    return TRUE;
}
