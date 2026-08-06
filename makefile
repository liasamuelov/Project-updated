CC = gcc
CFLAGS = -Wall -ansi -pedantic
OBJS = assembler.o preprocessor.o macro_table.o encode.o first_pass.o second_pass.o \
       output.o instructions.o symbol_table.o memory_image.o utils.o errors.o

assembler: $(OBJS)
	$(CC) $(CFLAGS) -o assembler $(OBJS)

assembler.o: assembler.c globals.h utils.h preprocessor.h first_pass.h \
             second_pass.h output.h symbol_table.h memory_image.h
preprocessor.o: preprocessor.c preprocessor.h globals.h macro_table.h
macro_table.o: macro_table.c macro_table.h globals.h utils.h
first_pass.o: first_pass.c first_pass.h globals.h symbol_table.h memory_image.h
second_pass.o: second_pass.c second_pass.h globals.h symbol_table.h \
               memory_image.h output.h
output.o: output.c output.h globals.h symbol_table.h memory_image.h utils.h
instructions.o: instructions.c instructions.h globals.h
symbol_table.o: symbol_table.c symbol_table.h globals.h utils.h
memory_image.o: memory_image.c memory_image.h globals.h
utils.o: utils.c utils.h globals.h
errors.o: errors.c errors.h globals.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o assembler tests/*.am tests/*.ob tests/*.ent tests/*.ext
encode.o: encode.c encode.h
