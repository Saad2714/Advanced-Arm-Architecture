	AREA greatest, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY


__main  FUNCTION
	MOV R0, #0x20000000
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

	

L1		ADD R0,R0,#0x4
        LDR R3,[R0] ;get next data
		CMP R2,R3
		BGT L2
		MOV R2,R3  ;R2 = R3 as R3 is larger
		
L2   	SUBS R1,R1,#01  ;Decrement the Counter
		CMP R1,#00
		BNE L1
		MOV R0,R2
		BL printMsg
stop    B stop ; stop program
	 ENDFUNC
	 END










; Largest number in an array.
	AREA greatest, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY

__main  FUNCTION
	
	MOV R8, #03 ; ARRAY LENGTH
	MOV R0, #0x20000000;ADDRESS 
    ; adding memory spaces from R0 till array length
	ADD R1, R0, #0x00000004
	ADD R2, R1, #0x00000004
	ADD R3, R2, #0x00000004
; random numbers adding in array
	MOV R4, #0x10
	MOV R5, #0x15
	MOV R6, #0x27
	MOV R7, #0021
; storing the numbers taking memory from R0 till R3
	STR R4, [R0]
	STR R5, [R1]
	STR R6, [R2]
	STR R7, [R3]
	
	LDR R4, [R0]

J1	ADD R0,R0,#0x4      ; comparing registers
     	LDR R5,[R0] ;load
		CMP R4,R5; comparing the two registers
		BGT J2  ; branching if R4 is greater than R5
		MOV R4,R5   ;eslse moving r4 to r5
		
J2   SUBS R8,R8,#01
		CMP R8,#00          
		BNE J1
		MOV R0,R4       
		BL printMsg         ;printing message 
stop    B stop ; stop program
	 ENDFUNC
	 END 

