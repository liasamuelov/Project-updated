/* ********************************************************************
 * FILE: preprocessor.c
 * OWNER / מי מממשת: ליה
 * STATUS: TODO - לממש
 * מה עושים כאן: קדם-אסמבלר: פרישת מאקרואים ויצירת קובץ am. כרגע רק מעתיק את הקובץ. האלגוריתם המלא, צעד-צעד, בהערה למטה.
 * ******************************************************************** */

/*
 * preprocessor.c - the pre-assembler (macro expansion) stage.
 * OWNER: Lia.
 *
 * TODO: implement the real macro expansion. Skeleton algorithm from the
 * booklet ("skeleton algorithm of the pre-assembler"):
 *   1. Read the next line from the source file; on EOF go to step 9.
 *   2. If the first field is a macro name that exists in the macro table,
 *      replace it by the stored macro lines and go back to step 1.
 *   3. If the first field is not "mcro" (a macro definition opener),
 *      go to step 6.
 *   4. Turn on the "inside macro" flag, record the macro name in the macro
 *      table. Checks required by the booklet: the macro name is not a
 *      reserved word (use is_reserved_word), and there are no extra
 *      characters on the definition line or on the mcroend line.
 *   5. Remove the definition line from the output.
 *   6. Read the next line; on EOF go to step 9.
 *   7. If "mcroend" was reached, remove it and turn off the flag; otherwise,
 *      while the flag is on, append the line to the macro table (and do not
 *      copy it to the output), then go back to step 6.
 *   8. Return to step 1.
 *   9. Save the expanded file (.am).
 * Store macro bodies in a dynamically allocated structure (e.g. a linked
 * list of lines per macro), not in a fixed-size array.
 * Also remember: a symbol may not serve both as a macro name and as a label.
 *
 * CURRENT PLACEHOLDER: copies file.as to file.am unchanged, so the rest of
 * the pipeline can already be developed and tested on macro-free files.
 */
#include <stdio.h>
#include "preprocessor.h"

boolean preprocess_file(const char *as_filename, const char *am_filename)
{
    FILE *in;
    FILE *out;
    int c;

    in = fopen(as_filename, "r");
    if (in == NULL) {
        printf("error: cannot open input file %s\n", as_filename);
        return FALSE;
    }
    out = fopen(am_filename, "w");
    if (out == NULL) {
        printf("error: cannot create output file %s\n", am_filename);
        fclose(in);
        return FALSE;
    }
    while ((c = fgetc(in)) != EOF)
        fputc(c, out);
    fclose(in);
    fclose(out);
    return TRUE;
}
