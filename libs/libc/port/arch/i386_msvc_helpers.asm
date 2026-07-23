; 64-bit integer arithmetic helpers for the clang-cl / MSVC i686 ABI.
;
; clang, targeting i686-pc-windows-msvc (incl. via clang-cl), lowers
; long long / unsigned long long multiply, divide, remainder and shift
; operations to calls to these fixed helper names instead of its own
; portable compiler-rt builtins (__udivdi3 etc) -- that's what "MSVC
; ABI compatible" means here. They normally live in MSVC's libcmt.lib;
; we don't link the real MSVC CRT (/NODEFAULTLIB, no CRT init), so we
; supply our own. Reimplemented from scratch with a plain schoolbook
; binary long division -- not extracted from any Microsoft binary.
; Calling conventions below were determined empirically (llvm-objdump
; against libcmt.lib) since Microsoft doesn't publish them.
;
; Stack-argument routines (div/mul family):
;   [esp+4]  = a_lo, [esp+8]  = a_hi   (first 64-bit operand)
;   [esp+12] = b_lo, [esp+16] = b_hi   (second 64-bit operand)
;   quotient/product returned in EDX:EAX; callee pops the 16 bytes of
;   args (ret 16). The *dvrm variants also return the remainder in
;   ECX:EBX (ECX = high, EBX = low); EBX/ECX are not preserved for
;   those two, unlike the plain div/mul routines.
;
; Register-argument routines (shifts):
;   EDX:EAX = value, CL = shift count. Result in EDX:EAX. Plain ret.

bits 32

section .text

global __aulldiv
global __alldiv
global __aulldvrm
global __alldvrm
global __aullrem
global __allrem
global __allmul
global __allshl
global __allshr
global __aullshr

; -------------------------------------------------------------------
; ox_udiv64 (internal only, no ABI contract with callers of this file)
; in:  edx:eax = dividend, ecx:ebx = divisor (ecx = hi, ebx = lo)
; out: edx:eax = quotient, edi:esi = remainder (edi = hi, esi = lo)
; preserves ebx, ecx; clobbers ebp internally but restores it.
; -------------------------------------------------------------------
ox_udiv64:
    push ebp
    xor esi, esi
    xor edi, edi
    mov ebp, 64
.loop:
    shl eax, 1
    rcl edx, 1
    rcl esi, 1
    rcl edi, 1
    cmp edi, ecx
    ja .subtract
    jb .skip
    cmp esi, ebx
    jb .skip
.subtract:
    sub esi, ebx
    sbb edi, ecx
    or eax, 1
.skip:
    dec ebp
    jnz .loop
    pop ebp
    ret

; -------------------------------------------------------------------
__aulldiv:
    push ebx
    push esi
    push edi
    mov eax, [esp+16]
    mov edx, [esp+20]
    mov ebx, [esp+24]
    mov ecx, [esp+28]
    call ox_udiv64
    pop edi
    pop esi
    pop ebx
    ret 16

; -------------------------------------------------------------------
__alldiv:
    push ebx
    push esi
    push edi
    mov eax, [esp+16]
    mov edx, [esp+20]
    mov ebx, [esp+24]
    mov ecx, [esp+28]

    mov edi, edx
    xor edi, ecx        ; edi bit31 = sign(a) xor sign(b) (quotient sign)
    push edi

    test edx, edx
    jns .a_pos
    neg eax
    adc edx, 0
    neg edx
.a_pos:
    test ecx, ecx
    jns .b_pos
    neg ebx
    adc ecx, 0
    neg ecx
.b_pos:
    call ox_udiv64

    pop edi
    test edi, edi
    jns .q_pos
    neg eax
    adc edx, 0
    neg edx
.q_pos:
    pop edi
    pop esi
    pop ebx
    ret 16

; -------------------------------------------------------------------
__aulldvrm:
    push esi
    push edi
    push ebp
    mov eax, [esp+16]
    mov edx, [esp+20]
    mov ebx, [esp+24]
    mov ecx, [esp+28]
    call ox_udiv64        ; edx:eax = quotient, edi:esi = remainder
    mov ecx, edi
    mov ebx, esi
    pop ebp
    pop edi
    pop esi
    ret 16

; -------------------------------------------------------------------
__alldvrm:
    push esi
    push edi
    push ebp
    mov eax, [esp+16]
    mov edx, [esp+20]
    mov ebx, [esp+24]
    mov ecx, [esp+28]

    mov ebp, edx
    xor ebp, ecx         ; quotient sign
    push edx             ; save dividend sign (for remainder sign)
    push ebp             ; save quotient sign

    test edx, edx
    jns .a_pos
    neg eax
    adc edx, 0
    neg edx
.a_pos:
    test ecx, ecx
    jns .b_pos
    neg ebx
    adc ecx, 0
    neg ecx
.b_pos:
    call ox_udiv64        ; edx:eax = |a|/|b|, edi:esi = |a|%|b|

    pop ebp               ; quotient sign
    test ebp, ebp
    jns .q_pos
    neg eax
    adc edx, 0
    neg edx
.q_pos:
    mov ecx, edi
    mov ebx, esi

    pop ebp               ; dividend sign (remainder takes dividend's sign)
    test ebp, ebp
    jns .r_pos
    neg ebx
    adc ecx, 0
    neg ecx
.r_pos:
    pop ebp
    pop edi
    pop esi
    ret 16

; -------------------------------------------------------------------
__aullrem:
    push ebx
    push esi
    push edi
    mov eax, [esp+16]
    mov edx, [esp+20]
    mov ebx, [esp+24]
    mov ecx, [esp+28]
    call ox_udiv64
    mov edx, edi
    mov eax, esi
    pop edi
    pop esi
    pop ebx
    ret 16

; -------------------------------------------------------------------
__allrem:                  ; signed remainder only (takes dividend's sign)
    push ebx
    push esi
    push edi
    mov eax, [esp+16]
    mov edx, [esp+20]
    mov ebx, [esp+24]
    mov ecx, [esp+28]

    push edx              ; save dividend sign

    test edx, edx
    jns .a_pos
    neg eax
    adc edx, 0
    neg edx
.a_pos:
    test ecx, ecx
    jns .b_pos
    neg ebx
    adc ecx, 0
    neg ecx
.b_pos:
    call ox_udiv64         ; edi:esi = |a| % |b|
    mov edx, edi
    mov eax, esi

    pop edi                ; dividend sign
    test edi, edi
    jns .r_pos
    neg eax
    adc edx, 0
    neg edx
.r_pos:
    pop edi
    pop esi
    pop ebx
    ret 16

; -------------------------------------------------------------------
__allmul:
    push ebx
    mov eax, [esp+8]      ; a_lo
    mov ecx, [esp+20]     ; b_hi
    imul ecx, eax         ; ecx = a_lo * b_hi (low 32 bits)
    mov ebx, [esp+12]     ; a_hi
    imul ebx, [esp+16]    ; ebx = a_hi * b_lo (low 32 bits)
    add ebx, ecx
    mov eax, [esp+8]      ; a_lo
    mul dword [esp+16]    ; edx:eax = a_lo * b_lo (full 64-bit)
    add edx, ebx
    pop ebx
    ret 16

; -------------------------------------------------------------------
__allshl:
    cmp cl, 64
    jae .zero
    cmp cl, 32
    jae .more32
    shld edx, eax, cl
    shl eax, cl
    ret
.more32:
    mov edx, eax
    xor eax, eax
    and cl, 31
    shl edx, cl
    ret
.zero:
    xor eax, eax
    xor edx, edx
    ret

; -------------------------------------------------------------------
__allshr:                  ; arithmetic (signed)
    cmp cl, 64
    jae .allsign
    cmp cl, 32
    jae .more32
    shrd eax, edx, cl
    sar edx, cl
    ret
.more32:
    mov eax, edx
    sar edx, 31
    and cl, 31
    sar eax, cl
    ret
.allsign:
    sar edx, 31
    mov eax, edx
    ret

; -------------------------------------------------------------------
__aullshr:                 ; logical (unsigned)
    cmp cl, 64
    jae .zero
    cmp cl, 32
    jae .more32
    shrd eax, edx, cl
    shr edx, cl
    ret
.more32:
    mov eax, edx
    xor edx, edx
    and cl, 31
    shr eax, cl
    ret
.zero:
    xor eax, eax
    xor edx, edx
    ret
