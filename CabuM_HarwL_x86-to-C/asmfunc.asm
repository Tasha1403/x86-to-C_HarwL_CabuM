section .text
bits 64
default rel ;to handle address relocation

global kernelA

kernelA:
	push rbp
    mov rbp, rsp
    add rbp, 16             ; return address of call and push rbp
    mov r10, 0              ; counter
    movss xmm1, [rdx]       ; move A into xmm1 register
    

    ; 1st = ecx(n), 2nd = xmm1 = rdx(a), 3rd = xmm2 = r8 (x), 4th = xmm3 = r9(y), 5th = stack

    loop:
        movss xmm0, [r8 + r10*4]
        movss xmm2, [r9 + r10*4]
        mulss xmm0, xmm1                  ; Multiply x[i] with A
        addss xmm0, xmm2                  ; Add y[i]
        mov r11, [rbp+32]                 ; element
        movss [r11+r10*4], xmm0           ; Store the result in z[i]

        inc r10
        cmp r10, rcx            ; Decrement loop counter
        jnz loop                ; Loop until ecx is zero

    pop rbp

    ret
