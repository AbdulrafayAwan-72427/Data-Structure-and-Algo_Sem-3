.model small
.stack 100h

.data
    prompt    db 10, 13, 'Enter a single-digit number (use - for negative digits): $'
    pos_msg   db 10, 13, 'The number is POSITIVE.$'
    neg_msg   db 10, 13, 'The number is NEGATIVE.$'
    zero_msg  db 10, 13, 'The number is ZERO.$'

.code
main proc

    mov ax, @data
    mov ds, ax
    mov ah, 9
    lea dx, prompt
    int 21h

    mov ah, 1
    int 21h
    mov bl, al         
    cmp bl, '-'
    je is_negative

    cmp bl, '0'
    je is_zero

 
    jmp is_positive

is_negative:
    mov ah, 9
    lea dx, neg_msg
    int 21h
    jmp exit_program

is_zero:
    mov ah, 9
    lea dx, zero_msg
    int 21h
    jmp exit_program

is_positive:  
    mov ah, 9
    lea dx, pos_msg
    int 21h
    jmp exit_program

exit_program:
    mov ah, 4Ch
    int 21h

main endp
end main
