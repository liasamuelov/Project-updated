/* ********************************************************************
 * FILE: output.c
 * OWNER / מי מממשת: שלד - מוכן
 * STATUS: READY
 * מה עושים כאן: כתיבת קובצי הפלט ob/ent/ext בפורמט המדויק של החוברת. לא צריך לגעת.
 * ******************************************************************** */

/*
 * output.c - writes the .ob, .ent and .ext files in the exact formats
 * defined by the booklet. Already implemented in the skeleton.
 */
#include <stdio.h>
#include <stdlib.h>
#include "output.h"
#include "utils.h"

boolean extlist_add(ext_use **list, const char *symbol_name, long address)
{
    ext_use *node = malloc(sizeof(ext_use));
    if (node == NULL)
        return FALSE;
    node->symbol_name = dup_string(symbol_name);
    if (node->symbol_name == NULL) {
        free(node);
        return FALSE;
    }
    node->address = address;
    node->next = *list;
    *list = node;
    return TRUE;
}

void extlist_free(ext_use *list)
{
    while (list != NULL) {
        ext_use *next = list->next;
        free(list->symbol_name);
        free(list);
        list = next;
    }
}

/* Writes the memory picture: a header line with the code length and the
   data length, then rows of a 4-digit decimal address followed by up to
   4 bytes in 2-digit uppercase hexadecimal. The data image is written
   right after the code image, with contiguous addresses. */
static void write_object_image(FILE *f, const memory_image *img)
{
    long code_len = img->ic - IC_INIT_VALUE;
    long data_len = img->dc;
    long total = code_len + data_len;
    long i;

    fprintf(f, "%ld %ld\n", code_len, data_len);
    for (i = 0; i < total; i++) {
        unsigned char byte;
        byte = (i < code_len) ? img->code[i] : img->data[i - code_len];
        if (i % 4 == 0)
            fprintf(f, "%04ld", (long)IC_INIT_VALUE + i);
        fprintf(f, " %02X", (unsigned int)byte);
        if (i % 4 == 3)
            fprintf(f, "\n");
    }
    if (total % 4 != 0)
        fprintf(f, "\n");
}

boolean write_output_files(const char *as_filename, const memory_image *img,
                           const symbol_table *symtab, const ext_use *ext_list)
{
    char *filename;
    FILE *f;
    const symbol_node *sym;
    const ext_use *use;
    boolean any_entry = FALSE;

    /* .ob file: always created */
    filename = replace_extension(as_filename, ".ob");
    if (filename == NULL)
        return FALSE;
    f = fopen(filename, "w");
    if (f == NULL) {
        printf("error: cannot create %s\n", filename);
        free(filename);
        return FALSE;
    }
    write_object_image(f, img);
    fclose(f);
    free(filename);

    /* .ent file: only if at least one symbol carries the entry attribute */
    for (sym = symtab->head; sym != NULL; sym = sym->next) {
        if (sym->attributes & SYM_ENTRY)
            any_entry = TRUE;
    }
    if (any_entry == TRUE) {
        filename = replace_extension(as_filename, ".ent");
        if (filename == NULL)
            return FALSE;
        f = fopen(filename, "w");
        if (f == NULL) {
            printf("error: cannot create %s\n", filename);
            free(filename);
            return FALSE;
        }
        for (sym = symtab->head; sym != NULL; sym = sym->next) {
            if (sym->attributes & SYM_ENTRY)
                fprintf(f, "%s %04ld\n", sym->name, sym->value);
        }
        fclose(f);
        free(filename);
    }

    /* .ext file: only if the code actually uses external symbols */
    if (ext_list != NULL) {
        filename = replace_extension(as_filename, ".ext");
        if (filename == NULL)
            return FALSE;
        f = fopen(filename, "w");
        if (f == NULL) {
            printf("error: cannot create %s\n", filename);
            free(filename);
            return FALSE;
        }
        for (use = ext_list; use != NULL; use = use->next)
            fprintf(f, "%s %04ld\n", use->symbol_name, use->address);
        fclose(f);
        free(filename);
    }
    return TRUE;
}
