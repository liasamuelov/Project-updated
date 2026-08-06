; each of the following lines contains one deliberate error,
; for testing the error handling of the assembler
MAIN: adx $3,$5,$9
add $3,$5
add $3,$5,$99
1BAD: hlt
.db 7,,8
.dh 99999999
jmp
