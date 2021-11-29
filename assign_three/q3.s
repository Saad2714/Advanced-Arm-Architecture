;Even Odd	
	AREA greatest, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY
      
__main  FUNCTION
	
	  MOV R0,#0x20000000
	  MOV R3,#0x00000000

	  ADD R1,R0, #0x00000004 ; for byte addressable memory next successive location differ by 4
;	ADD R1,R0, #0x00000005 Q1
  
	  ADD R2, R1, #0x00000004

	  MOV R4, #0x514
  
	  MOV R5, #0x81

	  MOV R6, #0x21

	  STR R4, [R0]

	  STR R5, [R1]

	  STR R6, [R2]

	  LDR R7, [R0]

	  LDR R8, [R1]
	  LDR R9, [R2]
      MOV R0,#01          ; Storing 0x01 for AND operation
      ;LDR R1,=array       ; Storing base address of array
      ;MOV R2,#0X09        ; Initializing counter 
	  TST R7,#01      ; 'AND'ing to check whether number is odd or even
      BNE J1
	  ADD R3,#01

J1	  TST R8,#01      ; 'AND'ing to check whether number is odd or even
      BNE J2
	  ADD R3,#01

J2	  TST R9,#01      ; 'AND'ing to check whether number is odd or even
      BNE J3
	  ADD R3,#01

J3 	  MOV R0, R3
	  BL printMsg
stop B stop
	  ; R3 register will have count of number of even numbers.
      ;SUBS R2,R2,#01
      ;BPL lbl
;array DCD  0x11223344, 0x12345671, 0x002917343, 0x00000001, 0x62398746, 0xAB56E3CD, 0x0A761BC7, 0x623ABC46, 0xAB86E3BD, 0x0A761DE8,  
      END
      
      
;Number of even elements in an array.
	AREA greatest, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY
      
__main  FUNCTION

	; for byte addressable memory next successive location differ by 4

	MOV R0,#0x20000000
	MOV R8, #04
	MOV R9,#0x00000000	;stores the result.
	ADD R1, R0, #0x00000004 
	ADD R2, R1, #0x00000004
	ADD R3, R2, #0x00000004

	MOV R4, #012
	MOV R5, #015
	MOV R6, #017
	MOV R7, #022

	STR R4, [R0]
	STR R5, [R1]
	STR R6, [R2]
	STR R7, [R3]

J1	LDR R4, [R0]
	TST R4,#01      ; checking even number by taking and with 1.
  	BNE J2
	ADD R9,#01

J2	ADD R0,R0,#0x4
	SUBS R8,R8,#01
	CMP R8,#00
	BNE J1
	MOV R0,R9
	BL printMsg

stop B stop  
	ENDFUNC
      END

;Even Odd	
	AREA even, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY
      
__main  FUNCTION
	MOV R0, #0x20000000
    MOV R2, #01          ; Storing 0x01 for AND operation
	MOV R5, #05				; size of array
	MOV R7, #06
	
LOOP1	SUBS R5, R5, #01
		STR R7, [R0]
		ADD R7, #01
		ADD R0, #04
		CMP R5, #00
		BNE LOOP1

		MOV R0, #0x20000000
		LDR R1, [R0]
		MOV R5, #05

LOOP	TST R1, R2
		BNE INCR
		ADD R12, #01
INCR	ADD R0, #04
		LDR R1, [R0]
		SUBS R5, R5, #01
		CMP R5, #00
		BNE LOOP
		MOV R0, R12
		BL printMsg
stop	B stop
		ENDFUNC
		END