/* ********************************************************************
 * FILE: assembler.c
 * OWNER / מי מממשת: שלד - מוכן
 * STATUS: READY
 * מה עושים כאן: התוכנית הראשית: מריצה על כל קובץ קלט את 4 השלבים (קדם-אסמבלר, מעבר ראשון, מעבר שני, פלט). לא צריך לגעת.
 * ******************************************************************** */

/*
 * assembler.c - main driver of the assembler (course 20465, MMN 14).
 *
 * The assembler receives one or more .as source files as command-line
 * arguments and processes each file independently through four stages:
 *   1. pre-assembler: macro expansion, produces the .am file;
 *   2. first pass:    symbol table + partial encoding;
 *   3. second pass:   completes the encoding using the symbol table;
 *   4. output:        writes .ob (and .ent/.ext when relevant).
 * If any stage finds errors, no output files are created for that file
 * and the assembler moves on to the next input file.
 */
#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "utils.h"
#include "preprocessor.h"
#include "symbol_table.h"
#include "memory_image.h"
#include "first_pass.h"
#include "second_pass.h"
#include "output.h"

static boolean process_file(const char *as_filename);

int main(int argc, char *argv[])
{
    int i;

    if (argc < 2) {
        printf("Usage: %s file1.as [file2.as ...]\n", argv[0]);
        return EXIT_FAILURE;
    }
    for (i = 1; i < argc; i++) {
        printf("--- processing %s ---\n", argv[i]);
        if (process_file(argv[i]) == TRUE)
            printf("--- %s: done ---\n", argv[i]);
        else
            printf("--- %s: finished with errors, no output files created ---\n", argv[i]);
    }
    return EXIT_SUCCESS;
}

/* Runs the full pipeline on a single source file.
   Returns TRUE if the file was assembled without errors. */
static boolean process_file(const char *as_filename)
{
    char *am_filename;
    FILE *am_file;
    memory_image img;
    symbol_table symtab;
    ext_use *ext_list = NULL;
    boolean ok;

    if (has_extension(as_filename, ".as") == FALSE) {
        printf("error: %s: input files must have the .as extension\n", as_filename);
        return FALSE;
    }

    am_filename = replace_extension(as_filename, ".am");
    if (am_filename == NULL) {
        printf("error: memory allocation failed\n");
        return FALSE;
    }

    /* Stage 1: pre-assembler (macro expansion) */
    if (preprocess_file(as_filename, am_filename) == FALSE) {
        free(am_filename);
        return FALSE;
    }

    am_file = fopen(am_filename, "r");
    if (am_file == NULL) {
        printf("error: cannot open %s\n", am_filename);
        free(am_filename);
        return FALSE;
    }

    image_init(&img);
    symtab_init(&symtab);

    /* Stage 2: first pass */
    ok = first_pass(am_file, am_filename, &img, &symtab);

    /* Stage 3: second pass (only if the first pass found no errors) */
    if (ok == TRUE) {
        rewind(am_file);
        ok = second_pass(am_file, am_filename, &img, &symtab, &ext_list);
    }

    /* Stage 4: output files (only if there were no errors at all) */
    if (ok == TRUE)
        ok = write_output_files(as_filename, &img, &symtab, ext_list);

    fclose(am_file);
    free(am_filename);
    symtab_free(&symtab);
    extlist_free(ext_list);
    return ok;
}
