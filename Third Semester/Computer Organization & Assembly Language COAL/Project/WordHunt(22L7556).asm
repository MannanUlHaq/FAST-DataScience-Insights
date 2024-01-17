[org 0x0100]
jmp Start

WelcomeMessage: db 'Welcome to WORD HUNT Game!', 0
StartMessage: db 'Press Any Key to Start', 0
LoadingMessage: db 'Loading', 0
Dot: db '.', 0
LevelCompletedMessage: db 'Level Completed!', 0
LevelFailedMessage: db 'You Lose!!', 0
EnterWordMessage: db 'Enter a WORD:', 0
CursorPoint: db '____', 0
EnteredWordMessage: db 'Your Input:', 0
CorrectWordMessage: db 'Hidden Word:', 0
GameEndMessage: db 'Game Over!', 0
QuitMessage: db 'Press Any Key to Quit...', 0
GameWinMessage: db 'You Win!!!', 0

music_length: dw 8472
music_data: incbin "Music.imf"

Cursor: db ' ', 0
Timer_String: db 'Time: 20 seconds', 0
              db 'Time: 19 seconds', 0
              db 'Time: 18 seconds', 0
              db 'Time: 17 seconds', 0
              db 'Time: 16 seconds', 0
              db 'Time: 15 seconds', 0
              db 'Time: 14 seconds', 0
              db 'Time: 13 seconds', 0
              db 'Time: 12 seconds', 0
              db 'Time: 11 seconds', 0
              db 'Time: 10 seconds', 0
              db 'Time: 09 seconds', 0
              db 'Time: 08 seconds', 0
              db 'Time: 07 seconds', 0
              db 'Time: 06 seconds', 0
              db 'Time: 05 seconds', 0
              db 'Time: 04 seconds', 0
              db 'Time: 03 seconds', 0
              db 'Time: 02 seconds', 0
              db 'Time: 01 seconds', 0
              db 'Time: 00 seconds', 0

Level1Message: db 'Level: 1', 0
Level1ScoreMessage: db 'Score : 00', 0
Level1Alphabets: db '       L       ', '       A       ', '       J       ', '       Z       ', '       E       ', '       O       ', '       G       ', '       I       ', '       K       ', '       N       ', '       V       ', '       L       ', '       M       ', '       Q       ', '       T       ', '       E       '
Level1BoxesColor: db 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F
Level1BoxesDelay: db 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
Level1Hint: db 'HINT: A strong feeling of affection', 0
Level1Word: db 'LOVE', 0
Level1BoxesDelayAfterPlay: db 10, 0, 0, 0, 0, 10, 0, 0, 0, 0, 10, 0, 0, 0, 0, 10
Level1BoxesColorAfterWin: db 0x3F, 0x0F, 0x0F, 0x0F, 0x0F, 0x3F, 0x0F, 0x0F, 0x0F, 0x0F, 0x3F, 0x0F, 0x0F, 0x0F, 0x0F, 0x3F
Level1BoxesColorAfterFail: db 0x4F, 0x0F, 0x0F, 0x0F, 0x0F, 0x4F, 0x0F, 0x0F, 0x0F, 0x0F, 0x4F, 0x0F, 0x0F, 0x0F, 0x0F, 0x4F
ScoreAfterLevel1: db 'New Score : 10', 0

Level2Message: db 'Level: 2', 0
Level2ScoreMessage: db 'Score : 10', 0
Level2Alphabets: db '       C       ', '       R       ', '       E       ', '       O       ', '       T       ', '       A       ', '       M       ', '       P       ', '       T       ', '       I       ', '       M       ', '       E       ', '       N       ', '       N       ', '       Q       ', '       R       '
Level2BoxesColor: db 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F
Level2BoxesDelay: db 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
Level2Hint1: db 'First Word HINT: The endless progression of existence', 0
Level2Word1: db 'TIME', 0
Level2Hint2: db 'Second Word HINT: Falls from the sky', 0
Level2Word2: db 'RAIN', 0
Level2BoxesDelayAfterPlay1: db 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0
Level2BoxesDelayAfterPlay2: db 0, 10, 0, 0, 0, 10, 0, 0, 0, 10, 0, 0, 0, 10, 0, 0
Level2BoxesColorAfterWin1: db 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x3F, 0x3F, 0x3F, 0x3F, 0x0F, 0x0F, 0x0F, 0x0F
Level2BoxesColorAfterFail1: db 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x4F, 0x4F, 0x4F, 0x4F, 0x0F, 0x0F, 0x0F, 0x0F
Level2BoxesColorAfterWin2: db 0x0F, 0x3F, 0x0F, 0x0F, 0x0F, 0x3F, 0x0F, 0x0F, 0x3F, 0x3F, 0x3F, 0x3F, 0x0F, 0x3F, 0x0F, 0x0F
Level2BoxesColorAfterFail2: db 0x0F, 0x4F, 0x0F, 0x0F, 0x0F, 0x4F, 0x0F, 0x0F, 0x3F, 0x4F, 0x3F, 0x3F, 0x0F, 0x4F, 0x0F, 0x0F
ScoreAfterLevel2: db 'New Score : 30', 0

Level3Message: db 'Level: 3', 0
Level3ScoreMessage: db 'Score : 30', 0
Level3Alphabets: db '       R       ', '       N       ', '       Z       ', '       S       ', '       C       ', '       O       ', '       A       ', '       L       ', '       B       ', '       V       ', '       I       ', '       T       ', '       G       ', '       U       ', '       N       ', '       F       '
Level3BoxesColor: db 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F
Level3BoxesDelay: db 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
Level3Hint1: db "First Word HINT: Ibrahim's barbie girl", 0
Level3Word1: db 'ZAIN', 0
Level3Hint2: db "Second Word HINT: Gujjar's favorite toy", 0
Level3Word2: db 'GUN', 0
Level3Hint3: db "Third Word HINT: Dr. Sana Fatima's secret weapon for torturing students", 0
Level3Word3: db 'COAL', 0
Level3BoxesDelayAfterPlay1: db 0, 0, 10, 0, 0, 0, 10, 0, 0, 0, 10, 0, 0, 0, 10, 0
Level3BoxesDelayAfterPlay2: db 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 10, 0
Level3BoxesDelayAfterPlay3: db 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0
Level3BoxesColorAfterWin1: db 0x0F, 0x0F, 0x3F, 0x0F, 0x0F, 0x0F, 0x3F, 0x0F, 0x0F, 0x0F, 0x3F, 0x0F, 0x0F, 0x0F, 0x3F, 0x0F
Level3BoxesColorAfterFail1: db 0x0F, 0x0F, 0x4F, 0x0F, 0x0F, 0x0F, 0x4F, 0x0F, 0x0F, 0x0F, 0x4F, 0x0F, 0x0F, 0x0F, 0x4F, 0x0F
Level3BoxesColorAfterWin2: db 0x0F, 0x0F, 0x3F, 0x0F, 0x0F, 0x0F, 0x3F, 0x0F, 0x0F, 0x0F, 0x3F, 0x0F, 0x3F, 0x3F, 0x3F, 0x0F
Level3BoxesColorAfterFail2: db 0x0F, 0x0F, 0x3F, 0x0F, 0x0F, 0x0F, 0x3F, 0x0F, 0x0F, 0x0F, 0x3F, 0x0F, 0x4F, 0x4F, 0x4F, 0x0F
Level3BoxesColorAfterWin3: db 0x0F, 0x0F, 0x3F, 0x0F, 0x3F, 0x3F, 0x3F, 0x3F, 0x0F, 0x0F, 0x3F, 0x0F, 0x3F, 0x3F, 0x3F, 0x0F
Level3BoxesColorAfterFail3: db 0x0F, 0x0F, 0x3F, 0x0F, 0x4F, 0x4F, 0x4F, 0x4F, 0x0F, 0x0F, 0x3F, 0x0F, 0x3F, 0x3F, 0x3F, 0x0F
ScoreAfterLevel3: db 'New Score : 60', 0

; Function to clear the Screen
clrscr:
    push es
    push ax
    push di

    mov ax, 0xb800
    mov es, ax
    mov di, 0

nextloc:
    mov word [es:di], 0x7020
    add di, 2
    cmp di, 4000
    jne nextloc

    pop di
    pop ax
    pop es
    ret

; Functions For Designing

drawBorder:
   push bp
   mov bp, sp
   push ax
   push bx
   push cx
   push di
   push si

   mov ax, 0xb800
   mov es, ax

   mov al, 80
   mul byte [bp + 10]
   add ax, [bp + 6]
   shl ax, 1
   mov di, ax
   push di

   mov cx, [bp + 4]
   sub cx, [bp + 6]
   push cx

   mov ah, 0x7F
   mov al, 0xB0

   rep stosw

   pop bx
   pop di
   push bx
   dec bx
   shl bx, 1
   add di, 160

   mov cx, [bp + 8]
   sub cx, [bp + 10]
   sub cx, 2

Borderloop1:
   mov si, di
   mov word [es:si], ax
   add si, bx
   mov word [es:si], ax
   sub si, bx
   add di, 160
   loop Borderloop1

   pop cx

   rep stosw

   pop si
   pop di
   pop cx
   pop bx
   pop ax
   pop bp
   ret 8

scrPattern:
    push ax
    push cx
    push dx
    push di
    push es

    mov ax, 0xb800
    mov es, ax
    mov di, 1324

    mov ax, 0x7720
    mov dx, 10

Patternloop:
    mov cx, 36
    push di
    rep stosw
    pop di
    sub dx, 1
    cmp dx, 0
    je donePattern
    add di, 160
    jmp Patternloop

donePattern:
    mov ax, 8
    push ax
    mov ax, 18
    push ax
    mov ax, 22
    push ax
    mov ax, 58
    push ax
    call drawBorder

    pop es
    pop di
    pop dx
    pop cx
    pop ax
    ret

fillscr:
    push es
    push ax
    push di

    mov ax, 0xb800
    mov es, ax
    mov di, 0
    mov ah, 0x7F
    mov al, 97

nextlocation:
    mov word [es:di], ax
    add al, 1
    cmp al, 122
    je repeat
    add di, 2
    cmp di, 4000
    jne nextlocation
    jmp donefill

repeat:
    mov al, 97
    add di, 2
    cmp di, 4000
    jne nextlocation

donefill:
    call scrPattern

    pop di
    pop ax
    pop es
    ret

;Function to get Length of String
strlen:
    push bp
    mov bp, sp
    push es
    push cx
    push di
    les di, [bp+4]
    mov cx, 0xffff
    xor al, al
    repne scasb
    mov ax, 0xffff
    sub ax, cx
    dec ax
    pop di
    pop cx
    pop es
    pop bp
    ret 4

; Function to print Strings
printstr:
    push bp
    mov bp, sp
    push es
    push ax
    push cx
    push si
    push di
    push ds
    mov ax, [bp+4]
    push ax
    call strlen
    cmp ax, 0
    jz doneprint
    mov cx, ax
    mov ax, 0xb800
    mov es, ax
    mov al, 80
    mul byte [bp+8]
    add ax, [bp+10]
    shl ax, 1
    mov di, ax
    mov si, [bp+4]
    mov ah, [bp+6]
    cld

nextchar:
    lodsb
    stosw
    loop nextchar

doneprint:
    pop di
    pop si
    pop cx
    pop ax
    pop es
    pop bp
    ret 8

; Function to wait for any Key press
waitForAnyKeyPress:
    push ax
    push di

    call PlayMusicDelay

    cmp di, 1
    je jumpNext

    mov ax, 0
    int 0x16

jumpNext:
    call Beep
    
    pop di
    pop ax
    ret

; Delay Function
Delay:
    push bp
    mov bp, sp
    push cx
    push dx

delayLoop:
    mov cl, [bp + 4]
    cmp cl, 0
    je doneDelay

outerLoop:
    mov dx, 65535

innerLoop:
    dec dx
    jnz innerLoop

    dec cl
    jnz outerLoop

doneDelay:
    pop dx
    pop cx
    pop bp
    ret 2

; Functions to print an 4x4 Grid

printGridDesign:
    push ax
    push cx
    push dx
    push di
    push es

    mov ax, 0xb800
    mov es, ax
    mov di, 530

    mov ax, 0x7FB0
    mov dx, 17

Designloop:
    mov cx, 30
    push di
    rep stosw
    pop di
    sub dx, 1
    cmp dx, 0
    je doneDesign
    add di, 160
    jmp Designloop

doneDesign:
    pop es
    pop di
    pop dx
    pop cx
    pop ax
    ret

printGrid:
    push bp
    mov bp, sp
    push ax
    push bx
    push cx
    push dx
    push si
    push di
    push es

    mov ax, 0xb800
    mov es, ax
    mov di, 530

    mov ax, 0
    mov bx, 0

    mov si, [bp + 8]

    mov cx, 4
    mov dx, 4

gridLoop:
    push di
    add di, 160
boxLoop:
    add di, 4

    push cx
    push dx
    mov cx, 5
    mov dx, 3

    push si
    mov si, [bp + 6]
    mov ah, [si + bx]
    mov si, [bp + 4]
    push dx
    mov dx, 0
    mov dl, [si + bx]
    push dx
    call Delay
    add bx, 1
    pop dx
    pop si

    push di
boxRow:
    push di
rowLoop:
    lodsb
    stosw
    loop rowLoop

    sub dx, 1
    cmp dx, 0
    je nextBox
    mov cx, 5
    pop di
    add di, 160
    jmp boxRow

nextBox:
    pop di
    pop di
    pop dx
    pop cx

    add di, 10

    sub cx, 1
    cmp cx, 0
    je nextGridRow
    jmp boxLoop

nextGridRow:
    pop di
    sub dx, 1
    cmp dx, 0
    je doneGrid
    mov cx, 4
    add di, 640
    jmp gridLoop

doneGrid:
    pop es
    pop di
    pop si
    pop dx
    pop cx
    pop bx
    pop ax
    pop bp
    ret 6

; Print Enter Word Instruction
Instruction:
    push ax

    mov ax, 5
    push ax
    mov ax, 10
    push ax
    mov ax, 0x70
    push ax
    mov ax, EnterWordMessage
    push ax
    call printstr

    mov ax, 5
    push ax
    mov ax, 11
    push ax
    mov ax, 0x70
    push ax
    mov ax, CursorPoint
    push ax
    call printstr
    
    pop ax
    ret

; Function to Compare Strings
strcmp:
    push bp
    mov bp, sp
    push cx
    push si
    push di
    push es
    push ds

    lds si, [bp+4]
    les di, [bp+8]

    push ds
    push si
    call strlen
    mov cx, ax

    push es
    push di
    call strlen
    cmp cx, ax
    jne exitfalse

    add cx, 1
    mov ax, 1
    repe cmpsb
    jcxz exitsimple

exitfalse:
    mov ax, 0

exitsimple:
    pop ds
    pop es
    pop di
    pop si
    pop cx
    pop bp
    ret 8

; User Input Function
InputwithTimer:
    push bp
    mov bp, sp
    sub sp, 2
    push ax
    push bx
    push cx
    push dx
    push si
    push di

    mov ax, 0
    mov dx, 0
    mov word [bp - 2], 5

    mov si, Timer_String
    mov di, 0

next_print:
    mov ax, 6
    push ax
    mov ax, 1
    push ax
    mov ax, 0x70
    push ax
    mov ax, si
    push ax
    call printstr

    add si, 17
    add dx, 1
    mov bx, 400

repeat_InputDelay:
    push bx
    mov cx, 800

InputDelay:
    mov ax, 0
    mov bx, 0

    mov ah, 1
    int 0x16
    mov bl, al
    cmp bx, 0
    jz no_input

    mov ah, 0x0
    int 0x16

    call Beep

    cmp bx, 13
    je endInput

    cmp bx, 27
    je Escape

    cmp bx, 8
    je Backspace

    mov [Cursor], bx
    mov ax, [bp - 2]
    add word [bp - 2], 1
    push ax
    mov ax, 11
    push ax
    mov ax, 0x70
    push ax
    mov ax, Cursor
    push ax
    call printstr

    cmp bx, 'a'
    jl skipLower
    cmp bx, 'z'
    jg skipLower

    sub bx, 32

skipLower:
    mov [UserInput + di], bx
    inc di

no_input:
    dec cx
    jnz InputDelay

    pop bx

    dec bx
    jnz repeat_InputDelay

    cmp dx, 21
    jne next_print

endInput:
    mov byte [UserInput + di], 0

    pop bx
    pop di
    pop si
    pop dx
    pop cx
    pop bx
    pop ax
    mov sp, bp
    pop bp
    ret

Escape:
    jmp End

Backspace:
    mov byte [Cursor], '_'
    sub word [bp - 2], 1
    mov ax, [bp - 2]
    push ax
    mov ax, 11
    push ax
    mov ax, 0x70
    push ax
    mov ax, Cursor
    push ax
    call printstr
    
    dec di

    jmp no_input

; Play Game Function
startGameLevel:
    push bp
    mov bp, sp

    call InputwithTimer

    mov ax, 62
    push ax
    mov ax, 7
    push ax
    mov ax, 0x70
    push ax
    mov ax, EnteredWordMessage
    push ax
    call printstr

    mov ax, 62
    push ax
    mov ax, 13
    push ax
    mov ax, 0x70
    push ax
    mov ax, CorrectWordMessage
    push ax
    call printstr

    push ds
    mov ax, [bp + 4]
    push ax
    push ds
    mov ax, UserInput
    push ax
    call strcmp

    cmp ax, 0
    je LevelFail

LevelWin:
    mov ax, 62
    push ax
    mov ax, 8
    push ax
    mov ax, 0x7B
    push ax
    mov ax, UserInput
    push ax
    call printstr

    mov ax, 62
    push ax
    mov ax, 14
    push ax
    mov ax, 0x7B
    push ax
    mov ax, [bp + 4]
    push ax
    call printstr

    mov ax, [bp + 12]
    push ax
    mov ax, [bp + 10]
    push ax
    mov ax, [bp + 6]
    push ax
    call printGrid

    mov ax, 20
    push ax
    call Delay

    mov ax, 1

    jmp LevelDone

LevelFail:
    mov ax, 62
    push ax
    mov ax, 8
    push ax
    mov ax, 0x7C
    push ax
    mov ax, UserInput
    push ax
    call printstr

    mov ax, 62
    push ax
    mov ax, 14
    push ax
    mov ax, 0x7B
    push ax
    mov ax, [bp + 4]
    push ax
    call printstr

    mov ax, [bp + 12]
    push ax
    mov ax, [bp + 8]
    push ax
    mov ax, [bp + 6]
    push ax
    call printGrid

    mov ax, 20
    push ax
    call Delay

    mov ax, 0

LevelDone:
    pop bp
    ret 10    

; Print Level Number
printLevel:
    push bp
    mov bp, sp
    push ax

    mov ax, 36
    push ax
    mov ax, 12
    push ax
    mov ax, 0x70
    push ax
    mov ax, [bp + 4]
    push ax
    call printstr

    pop ax
    pop bp
    ret 2

; Print Loading Message
printLoading:
    push ax

    mov ax, 34
    push ax
    mov ax, 13
    push ax
    mov ax, 0x79
    push ax
    mov ax, LoadingMessage
    push ax
    call printstr

    ; Print Dots
    mov ax, 10
    push ax
    call Delay
    mov ax, 41
    push ax
    mov ax, 13
    push ax
    mov ax, 0x79
    push ax
    mov ax, Dot
    push ax
    call printstr
    mov ax, 10
    push ax
    call Delay
    mov ax, 42
    push ax
    mov ax, 13
    push ax
    mov ax, 0x79
    push ax
    mov ax, Dot
    push ax
    call printstr
    mov ax, 10
    push ax
    call Delay
    mov ax, 43
    push ax
    mov ax, 13
    push ax
    mov ax, 0x79
    push ax
    mov ax, Dot
    push ax
    call printstr
    mov ax, 10
    push ax
    call Delay
    mov ax, 44
    push ax
    mov ax, 13
    push ax
    mov ax, 0x79
    push ax
    mov ax, Dot
    push ax
    call printstr
    mov ax, 10
    push ax
    call Delay
    mov ax, 45
    push ax
    mov ax, 13
    push ax
    mov ax, 0x79
    push ax
    mov ax, Dot
    push ax
    call printstr
    
    pop ax
    ret

; Beep Sound Function
Beep:
    push ax
    push bx
    push cx

    mov al, 182
    out 43h, al

    mov ax, 2711
    out 42h, al
    mov al, ah
    out 42h, al

    in al, 61h
    or al, 00000011b
    out 61h, al

    mov bx, 150

pause1:
    mov cx, 150
pause2:
    dec cx
    jne pause2

    dec bx
    jne pause1

    in al, 61h
    and al, 11111100b
    out 61h, al

    pop cx
    pop bx
    pop ax
    ret

; Music Function
PlayMusicDelay:
    push ax
    push bx
    push cx
    push dx
    push si

    mov si, 0
    mov di, 0

next_note:
    mov dx, 388h
    mov al, [si + music_data]
    out dx, al

    mov dx, 389h
    mov al, [si + music_data + 1]
    out dx, al

    mov bx, [si + music_data + 2]

    add si, 4

repeat_delay:
    mov cx, 500
MusicDelay:
    mov ah, 1
    int 0x16
    jne StopMusic

    loop MusicDelay

    dec bx
    jg repeat_delay

    cmp si, [music_length]
    jb next_note
    jmp MusicEnd

StopMusic:
    mov ah, 0x0
    int 0x16

    mov di, 1

    mov si, 8400
    jmp next_note

MusicEnd:
    pop si
    pop dx
    pop cx
    pop bx
    pop ax
    ret

Start:
    call clrscr
    call fillscr

    ; Print Welcome Message
    mov ax, 27
    push ax
    mov ax, 12
    push ax
    mov ax, 0x70
    push ax
    mov ax, WelcomeMessage
    push ax
    call printstr

    ; Print Start Message
    mov ax, 29
    push ax
    mov ax, 13
    push ax
    mov ax, 0xFA
    push ax
    mov ax, StartMessage
    push ax
    call printstr

    call waitForAnyKeyPress

    ;Level: 1
    
    call clrscr

    ; Print Level
    mov ax, Level1Message
    push ax
    call printLevel

    ; Print Loading Message
    call printLoading
    
    call clrscr

    ; Print Level
    mov ax, 36
    push ax
    mov ax, 1
    push ax
    mov ax, 0x70
    push ax
    mov ax, Level1Message
    push ax
    call printstr

    ; Print Score
    mov ax, 66
    push ax
    mov ax, 1
    push ax
    mov ax, 0x79
    push ax
    mov ax, Level1ScoreMessage
    push ax
    call printstr

    ; Print Hint
    mov ax, 5
    push ax
    mov ax, 22
    push ax
    mov ax, 0x7A
    push ax
    mov ax, Level1Hint
    push ax
    call printstr

    call printGridDesign

    mov ax, Level1Alphabets
    push ax
    mov ax, Level1BoxesColor
    push ax
    mov ax, Level1BoxesDelay
    push ax
    call printGrid

    call Instruction

    mov ax, Level1Alphabets
    push ax
    mov ax, Level1BoxesColorAfterWin
    push ax
    mov ax, Level1BoxesColorAfterFail
    push ax
    mov ax, Level1BoxesDelayAfterPlay
    push ax
    mov ax, Level1Word
    push ax
    call startGameLevel

    cmp ax, 0
    je FailedLevel1

    call clrscr

    mov ax, 32
    push ax
    mov ax, 12
    push ax
    mov ax, 0x7A
    push ax
    mov ax, LevelCompletedMessage
    push ax
    call printstr

    mov ax, 33
    push ax
    mov ax, 13
    push ax
    mov ax, 0x79
    push ax
    mov ax, ScoreAfterLevel1
    push ax
    call printstr

    mov ax, 50
    push ax
    call Delay

    jmp Level2

FailedLevel1:
    call clrscr

    mov ax, 35
    push ax
    mov ax, 12
    push ax
    mov ax, 0x7C
    push ax
    mov ax, LevelFailedMessage
    push ax
    call printstr

    mov ax, 35
    push ax
    mov ax, 13
    push ax
    mov ax, 0x79
    push ax
    mov ax, Level1ScoreMessage
    push ax
    call printstr

    mov ax, 50
    push ax
    call Delay

    jmp End

Level2:
    ;Level: 2
    
    call clrscr

    ; Print Level
    mov ax, Level2Message
    push ax
    call printLevel

    ; Print Loading Message
    call printLoading

Level2FirstWord:    
    call clrscr

    ; Print Level
    mov ax, 36
    push ax
    mov ax, 1
    push ax
    mov ax, 0x70
    push ax
    mov ax, Level2Message
    push ax
    call printstr

    ; Print Score
    mov ax, 66
    push ax
    mov ax, 1
    push ax
    mov ax, 0x79
    push ax
    mov ax, Level2ScoreMessage
    push ax
    call printstr

    ; First Word

    ; Print Hint
    mov ax, 5
    push ax
    mov ax, 22
    push ax
    mov ax, 0x7A
    push ax
    mov ax, Level2Hint1
    push ax
    call printstr

    call printGridDesign

    mov ax, Level2Alphabets
    push ax
    mov ax, Level2BoxesColor
    push ax
    mov ax, Level2BoxesDelay
    push ax
    call printGrid

    call Instruction

    mov ax, Level2Alphabets
    push ax
    mov ax, Level2BoxesColorAfterWin1
    push ax
    mov ax, Level2BoxesColorAfterFail1
    push ax
    mov ax, Level2BoxesDelayAfterPlay1
    push ax
    mov ax, Level2Word1
    push ax
    call startGameLevel

    cmp ax, 0
    je FailedLevel2FirstWord

Level2SecondWord:
    call clrscr

    ; Print Level
    mov ax, 36
    push ax
    mov ax, 1
    push ax
    mov ax, 0x70
    push ax
    mov ax, Level2Message
    push ax
    call printstr

    ; Print Score
    mov ax, 66
    push ax
    mov ax, 1
    push ax
    mov ax, 0x79
    push ax
    mov ax, Level2ScoreMessage
    push ax
    call printstr

    ; Second Word

    ; Print Hint
    mov ax, 5
    push ax
    mov ax, 22
    push ax
    mov ax, 0x7A
    push ax
    mov ax, Level2Hint2
    push ax
    call printstr

    call printGridDesign

    mov ax, Level2Alphabets
    push ax
    mov ax, Level2BoxesColorAfterWin1
    push ax
    mov ax, Level2BoxesDelay
    push ax
    call printGrid

    call Instruction

    mov ax, Level2Alphabets
    push ax
    mov ax, Level2BoxesColorAfterWin2
    push ax
    mov ax, Level2BoxesColorAfterFail2
    push ax
    mov ax, Level2BoxesDelayAfterPlay2
    push ax
    mov ax, Level2Word2
    push ax
    call startGameLevel

FailedLevel2FirstWord:
    cmp ax, 0
    je FailedLevel2

    call clrscr

    mov ax, 32
    push ax
    mov ax, 12
    push ax
    mov ax, 0x7A
    push ax
    mov ax, LevelCompletedMessage
    push ax
    call printstr

    mov ax, 33
    push ax
    mov ax, 13
    push ax
    mov ax, 0x79
    push ax
    mov ax, ScoreAfterLevel2
    push ax
    call printstr

    mov ax, 50
    push ax
    call Delay

    jmp Level3

FailedLevel2:
    call clrscr

    mov ax, 35
    push ax
    mov ax, 12
    push ax
    mov ax, 0x7C
    push ax
    mov ax, LevelFailedMessage
    push ax
    call printstr

    mov ax, 35
    push ax
    mov ax, 13
    push ax
    mov ax, 0x79
    push ax
    mov ax, Level2ScoreMessage
    push ax
    call printstr

    mov ax, 50
    push ax
    call Delay

    jmp End

Level3:
    ;Level: 3
    
    call clrscr

    ; Print Level
    mov ax, Level3Message
    push ax
    call printLevel

    ; Print Loading Message
    call printLoading

Level3FirstWord:    
    call clrscr

    ; Print Level
    mov ax, 36
    push ax
    mov ax, 1
    push ax
    mov ax, 0x70
    push ax
    mov ax, Level3Message
    push ax
    call printstr

    ; Print Score
    mov ax, 66
    push ax
    mov ax, 1
    push ax
    mov ax, 0x79
    push ax
    mov ax, Level3ScoreMessage
    push ax
    call printstr

    ; First Word

    ; Print Hint
    mov ax, 5
    push ax
    mov ax, 22
    push ax
    mov ax, 0x7A
    push ax
    mov ax, Level3Hint1
    push ax
    call printstr

    call printGridDesign

    mov ax, Level3Alphabets
    push ax
    mov ax, Level3BoxesColor
    push ax
    mov ax, Level3BoxesDelay
    push ax
    call printGrid

    call Instruction

    mov ax, Level3Alphabets
    push ax
    mov ax, Level3BoxesColorAfterWin1
    push ax
    mov ax, Level3BoxesColorAfterFail1
    push ax
    mov ax, Level3BoxesDelayAfterPlay1
    push ax
    mov ax, Level3Word1
    push ax
    call startGameLevel

    cmp ax, 0
    je FailedLevel3FirstWord

Level3SecondWord:
    call clrscr

    ; Print Level
    mov ax, 36
    push ax
    mov ax, 1
    push ax
    mov ax, 0x70
    push ax
    mov ax, Level3Message
    push ax
    call printstr

    ; Print Score
    mov ax, 66
    push ax
    mov ax, 1
    push ax
    mov ax, 0x79
    push ax
    mov ax, Level3ScoreMessage
    push ax
    call printstr

    ; Second Word

    ; Print Hint
    mov ax, 5
    push ax
    mov ax, 22
    push ax
    mov ax, 0x7A
    push ax
    mov ax, Level3Hint2
    push ax
    call printstr

    call printGridDesign

    mov ax, Level3Alphabets
    push ax
    mov ax, Level3BoxesColorAfterWin1
    push ax
    mov ax, Level3BoxesDelay
    push ax
    call printGrid

    call Instruction

    mov ax, Level3Alphabets
    push ax
    mov ax, Level3BoxesColorAfterWin2
    push ax
    mov ax, Level3BoxesColorAfterFail2
    push ax
    mov ax, Level3BoxesDelayAfterPlay2
    push ax
    mov ax, Level3Word2
    push ax
    call startGameLevel

FailedLevel3FirstWord:
    cmp ax, 0
    je FailedLevel3SecondWord

Level3ThirdWord:
    call clrscr

    ; Print Level
    mov ax, 36
    push ax
    mov ax, 1
    push ax
    mov ax, 0x70
    push ax
    mov ax, Level3Message
    push ax
    call printstr

    ; Print Score
    mov ax, 66
    push ax
    mov ax, 1
    push ax
    mov ax, 0x79
    push ax
    mov ax, Level3ScoreMessage
    push ax
    call printstr

    ; Third Word

    ; Print Hint
    mov ax, 5
    push ax
    mov ax, 22
    push ax
    mov ax, 0x7A
    push ax
    mov ax, Level3Hint3
    push ax
    call printstr

    call printGridDesign

    mov ax, Level3Alphabets
    push ax
    mov ax, Level3BoxesColorAfterWin2
    push ax
    mov ax, Level3BoxesDelay
    push ax
    call printGrid

    call Instruction

    mov ax, Level3Alphabets
    push ax
    mov ax, Level3BoxesColorAfterWin3
    push ax
    mov ax, Level3BoxesColorAfterFail3
    push ax
    mov ax, Level3BoxesDelayAfterPlay3
    push ax
    mov ax, Level3Word3
    push ax
    call startGameLevel

FailedLevel3SecondWord:
    cmp ax, 0
    je FailedLevel3

    call clrscr

    mov ax, 32
    push ax
    mov ax, 12
    push ax
    mov ax, 0x7A
    push ax
    mov ax, LevelCompletedMessage
    push ax
    call printstr

    mov ax, 33
    push ax
    mov ax, 13
    push ax
    mov ax, 0x79
    push ax
    mov ax, ScoreAfterLevel3
    push ax
    call printstr

    mov ax, 50
    push ax
    call Delay

    jmp GameWin

FailedLevel3:
    call clrscr

    mov ax, 35
    push ax
    mov ax, 12
    push ax
    mov ax, 0x7C
    push ax
    mov ax, LevelFailedMessage
    push ax
    call printstr

    mov ax, 35
    push ax
    mov ax, 13
    push ax
    mov ax, 0x79
    push ax
    mov ax, Level3ScoreMessage
    push ax
    call printstr

    mov ax, 50
    push ax
    call Delay

    jmp End

GameWin:
    call clrscr

    ; Print Win Game Message
    mov ax, 35
    push ax
    mov ax, 12
    push ax
    mov ax, 0xFA
    push ax
    mov ax, GameWinMessage
    push ax
    call printstr

    mov ax, 60
    push ax
    call Delay

End:
    call clrscr
    call fillscr

    ; Print End Game Message
    mov ax, 35
    push ax
    mov ax, 12
    push ax
    mov ax, 0x70
    push ax
    mov ax, GameEndMessage
    push ax
    call printstr

    ; Print Quit Message
    mov ax, 28
    push ax
    mov ax, 13
    push ax
    mov ax, 0xFA
    push ax
    mov ax, QuitMessage
    push ax
    call printstr

    call waitForAnyKeyPress
    call clrscr

    mov ax, 0x4c00
    int 0x21

    UserInput: db 0