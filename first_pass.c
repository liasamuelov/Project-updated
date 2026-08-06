/* ********************************************************************
 * FILE: first_pass.c
 * OWNER / מי מממשת: מאיה
 * STATUS: TODO - לממש
 * מה עושים כאן: המעבר הראשון: בניית טבלת הסמלים, קידוד כל מה שאפשר כבר עכשיו, וגילוי שגיאות תחביר. האלגוריתם המלא, צעד-צעד, בהערה למטה.
 * ******************************************************************** */

/*
 * first_pass.c - the first pass of the assembler.
 * OWNER: Maya.
 *
 * TODO: implement according to the booklet's first-pass algorithm:
 *   1.  IC = 100, DC = 0 (image_init already does this).
 *   2.  Read the next line; on EOF go to step 17.
 *   3.  Skip empty and comment lines (is_empty_line / is_comment_line).
 *   4.  Check line length: more than MAX_LINE_LENGTH characters is an error.
 *   5.  If the line starts with a label, validate it (legal syntax, at most
 *       MAX_LABEL_LENGTH characters, not a reserved word, not already
 *       defined) and remember that a symbol is being defined.
 *   6.  .db/.dw/.dh/.asciz: insert the label (if any) with attribute
 *       SYM_DATA and value DC, then encode the numbers/characters into the
 *       data image with image_add_data (validate ranges per size!).
 *   7.  .entry: handled in the second pass, skip here.
 *   8.  .extern: insert the operand symbol with value 0 and SYM_EXTERNAL.
 *   9.  Otherwise this is an instruction line: insert the label (if any)
 *       with attribute SYM_CODE and value IC.
 *   10. Look up the operation with find_instruction; unknown name is an
 *       error. Parse the operands by instruction type (R/I/J), checking
 *       operand count, commas, register range 0..NUM_REGISTERS-1, and
 *       immediate range (16 bits, two's complement).
 *   11. Encode whatever is already known with image_add_instruction
 *       (opcode, funct, registers, arithmetic immediates); fields that
 *       need symbol values stay 0 and are completed in the second pass.
 *   12. On EOF: if errors were found, stop (no second pass, no output).
 *       Otherwise save ICF/DCF, call symtab_offset_data_symbols(symtab, ICF)
 *       so data symbols sit after the code in the final memory picture.
 *
 * Report every error with report_error and keep going: the assembler must
 * find as many errors as possible in one run.
 */
#include <stdio.h>
#include "first_pass.h"
#include <string.h>

boolean first_pass(FILE *am_file, const char *filename,memory_image *img, symbol_table *symtab){
    boolean error_flag=FALSE;
    //(void)am_file;
    //(void)filename;
    (void)img;
    (void)symtab;
    image_init(img);
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    fp = fopen(filename, "r");
    int line_counter=0;
    char *word[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, fp) != NULL){
        line_counter++;
        if(line[0]=='\n'||is_empty_line(line)||is_comment_line(line)){
            continue;
        }
        //check line size
        if(sizeof(line)>MAX_LINE_LENGTH){
            report_error(filename,line_counter);//add error type
            coninue;
        }
        line=get_word(line,word);
        instruction_info command_info=find_instruction(word);
        if(command_info==NULL){
            //command is either a label or error, let's check if it's a valid label
            char *label;
            strcpy(label,word);
            //command is a label;
            int label_len=sizeof(label);
            if(!check_label(symtab, label)){
                error_flag=TRUE;
                report_error(filename,line_counter);//add error type
                continue;
            }
            label[label_len-1]='\0';//removing ':'
            line=get_word(line,word);
            if(sizeof(line)==0){
                report_error(filename,line_counter);//add error type
                continue;
            }
            char *command;
            strcpy(command,word);
            instruction_info label_type=find_instruction(command);
            if(label_type==NULL){
                report_error(filename,line_counter);//add error type
                continue;
            }


            //symtab_add(symtab, command);
        }
        
    }
    //printf("first_pass: not implemented yet (owner: Maya)\n");
    return error_flag;
}
