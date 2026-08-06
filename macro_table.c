/* ********************************************************************
 * FILE: macro_table.c
 * OWNER / מי מממשת: ליה
 * STATUS: TODO - לממש
 * מה עושים כאן: טבלת המאקרואים לקדם-אסמבלר. לממש בדיוק לפי התבנית של symbol_table.c (אותו דפוס של רשימה מקושרת).
 * ******************************************************************** */

/*
 * macro_table.c - implementation of the macro table.
 * Hint: open symbol_table.c next to this file. macrotab_find is the same
 * idea as symtab_find, macrotab_add is the same idea as symtab_add, and
 * macrotab_free is the same idea as symtab_free (but also frees the lines
 * of every macro). Use dup_string from utils.h for string copies.
 */
#include <stdlib.h>
#include <string.h>
#include "macro_table.h"
#include "utils.h"

void macrotab_init(macro_table *table)
{
    table->head = NULL;
}

macro_node *macrotab_find(const macro_table *table, const char *name)
{
    /* TODO (ליה): לעבור על הרשימה ולהשוות שמות עם strcmp,
       בדיוק כמו symtab_find בקובץ symbol_table.c */
    (void)table;
    (void)name;
    return NULL;
}

macro_node *macrotab_add(macro_table *table, const char *name)
{
    /* TODO (ליה): להקצות macro_node חדש עם malloc, להעתיק את השם עם
       dup_string, לאתחל first_line/last_line ל-NULL, ולחבר לראש הרשימה,
       בדיוק כמו symtab_add */
    (void)table;
    (void)name;
    return NULL;
}

boolean macrotab_add_line(macro_node *macro, const char *line)
{
    /* TODO (ליה): להקצות macro_line חדש, להעתיק את הטקסט עם dup_string,
       ולחבר אותו בסוף הרשימה (בעזרת last_line) כדי לשמור על סדר השורות */
    (void)macro;
    (void)line;
    return FALSE;
}

void macrotab_free(macro_table *table)
{
    /* TODO (ליה): לשחרר כל מאקרו: קודם את כל שורות הגוף שלו, אחר כך את
       השם ואת החוליה עצמה, כמו symtab_free */
    (void)table;
}
