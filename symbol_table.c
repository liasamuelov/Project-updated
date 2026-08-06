/* ********************************************************************
 * FILE: symbol_table.c
 * OWNER / מי מממשת: ליה
 * STATUS: READY - לקרוא ולהבין
 * מה עושים כאן: טבלת הסמלים: רשימה מקושרת של תווית + כתובת + מאפיינים. כבר ממומשת. ליה: לקרוא עד שמבינים כל שורה, זו התבנית המדויקת ל-macro_table.c.
 * ******************************************************************** */

/*
 * symbol_table.c - linked-list implementation of the symbol table.
 */
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "utils.h"

void symtab_init(symbol_table *table)
{
    table->head = NULL;
}

symbol_node *symtab_find(const symbol_table *table, const char *name)
{
    symbol_node *node;
    for (node = table->head; node != NULL; node = node->next) {
        if (strcmp(node->name, name) == 0)
            return node;
    }
    return NULL;
}

symbol_node *symtab_add(symbol_table *table, const char *name,
                        long value, unsigned int attributes)
{
    symbol_node *node = malloc(sizeof(symbol_node));
    if (node == NULL)
        return NULL;
    node->name = dup_string(name);
    if (node->name == NULL) {
        free(node);
        return NULL;
    }
    node->value = value;
    node->attributes = attributes;
    node->next = table->head;
    table->head = node;
    return node;
}

void symtab_add_attribute(symbol_node *node, unsigned int attribute)
{
    node->attributes |= attribute;
}

void symtab_offset_data_symbols(symbol_table *table, long offset)
{
    symbol_node *node;
    for (node = table->head; node != NULL; node = node->next) {
        if (node->attributes & SYM_DATA)
            node->value += offset;
    }
}

void symtab_free(symbol_table *table)
{
    symbol_node *node = table->head;
    while (node != NULL) {
        symbol_node *next = node->next;
        free(node->name);
        free(node);
        node = next;
    }
    table->head = NULL;
}

boolean check_label(char *name, symbol_table *table){
    //written by maya
    int label_len=sizeof(name);
    if(label_len>MAX_LABEL_LENGTH||label_len==0){
        return FALSE;
    }
    if(!is_letter(name[0])||name[label_len-1]!=':'){
        return FALSE;
    }
    name[label_len-1]!='\0'; //erase ':'
    if(symtab_find(table,name)!=NULL){
        return FALSE;
    }
    while(*name!='\0'){
        if(!(is_letter(*name)||is_number(*name)){
            return FALSE;
        }
        name++;
    }
    return TRUE;
}
