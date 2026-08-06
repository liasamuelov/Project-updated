# MMN 14 - Assembler (course 20465, semester 2026b)

פרויקט האסמבלר של ליה ומאיה. בראש כל קובץ מקור יש כותרת שאומרת מי מממשת
אותו ומה עושים בו. הוראות גיט מלאות בקובץ `GIT.md`.

## Build and run
```
make
./assembler tests/ps.as
```
Compiles with `gcc -Wall -ansi -pedantic` and must stay warning-free
(the course deducts points otherwise). Submission must include the compiled
executable for Ubuntu, the makefile, and at least 3 valid and 3 invalid
example runs with screenshots.

## Modules and owners
| File | Role | Owner | Status |
|---|---|---|---|
| assembler.c | main driver, per-file pipeline | skeleton | done |
| preprocessor.c/.h | macro expansion (.as to .am) | Lia | TODO (currently a pass-through copy) |
| macro_table.c/.h | macro table for the pre-assembler | Lia | TODO (interface ready, follow symbol_table.c) |
| first_pass.c/.h | symbol table + partial encoding + syntax errors | Maya | TODO (algorithm in comments) |
| second_pass.c/.h | completes encoding, entries, externals | Lia | TODO (algorithm in comments) |
| output.c/.h | .ob / .ent / .ext writers, externals list | skeleton | done |
| symbol_table.c/.h | linked-list symbol table | done (Lia: read + understand) | done |
| memory_image.c/.h | code/data images, IC/DC, little-endian packing | skeleton | done |
| instructions.c/.h | full opcode/funct table, reserved words | skeleton | done |
| utils.c/.h | whitespace, filenames, string helpers | shared | done |
| errors.c/.h | error reporting API | Maya (extend with error kinds) | basic version done |

## Ground rules (from the booklet)
- Every function gets a header comment; meaningful names everywhere;
  no magic numbers. Documentation and code quality are ~40% of the grade.
- All data structures except the memory images must be dynamic
  (linked lists / malloc), not fixed arrays.
- The project must be original work. External code (including code found
  online) is a disciplinary offense - keep the repository private.
