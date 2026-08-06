/* ********************************************************************
 * FILE: utils.c
 * OWNER / מי מממשת: שלד - מוכן
 * STATUS: READY
 * מה עושים כאן: פונקציות עזר כלליות (רווחים, שמות קבצים, מחרוזות) לשימוש שתיכן.
 * ******************************************************************** */

/*
 * utils.c - implementation of the general-purpose helpers.
 */
#include <stdlib.h>
#include <string.h>
#include "utils.h"

const char *skip_whitespace(const char *s)
{
    while (*s == ' ' || *s == '\t')
        s++;
    return s;
}

void strip_newline(char *line)
{
    size_t len = strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
        line[len - 1] = '\0';
        len--;
    }
}

boolean is_empty_line(const char *line)
{
    const char *p = skip_whitespace(line);
    return (*p == '\0' || *p == '\n') ? TRUE : FALSE;
}

boolean is_comment_line(const char *line)
{
    const char *p = skip_whitespace(line);
    return (*p == ';') ? TRUE : FALSE;
}

char *dup_string(const char *s)
{
    char *copy = malloc(strlen(s) + 1);
    if (copy != NULL)
        strcpy(copy, s);
    return copy;
}

boolean has_extension(const char *filename, const char *extension)
{
    size_t name_len = strlen(filename);
    size_t ext_len = strlen(extension);
    if (name_len < ext_len)
        return FALSE;
    return (strcmp(filename + name_len - ext_len, extension) == 0) ? TRUE : FALSE;
}

char *replace_extension(const char *filename, const char *new_extension)
{
    const char *dot = strrchr(filename, '.');
    size_t base_len = (dot != NULL) ? (size_t)(dot - filename) : strlen(filename);
    char *result = malloc(base_len + strlen(new_extension) + 1);
    if (result == NULL)
        return NULL;
    memcpy(result, filename, base_len);
    result[base_len] = '\0';
    strcat(result, new_extension);
    return result;
}

const char *skip_whitespace_and_one_coma(const char *s)
{
    int c=0;
    while( (*s == ' ' || *s == '\t'||*s==',')&&(c<1)){
        if(*s==',')c++;
        s++;
    }
    return s;
}

char* get_next_word(char *line,char *res){
    //written by maya
    int j=0;
    line=skip_white_spaces(line);
    while(*line!=' ' && *line!='\t' && *line!='\n'&&*line!='\0'&& *line!=','){
        res[j]=line;line++;j++;
    }
    res[j]='\0';
    return line;
}
