	
	AREA greatest, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg	
	ENTRY

;input1 RN 0 ; R0 -> input
;input2 RN 1 ; R1 -> input
;input3 RN 2 ; R2 -> input
;temp RN 3
;result RN 4 ; R4 -> output
      
__main  FUNCTION
	
	MOV R0,#0x20000000

	ADD R1,R0, #0x00000004 ; for byte addressable memory next successive location differ by 4
;	ADD R1,R0, #0x00000005 Q1 4 for Q2
  
	ADD R2, R1, #0x00000004
	;	ADD R2, R1, #0x00000005 Q1

	MOV R4, #0x1234

	MOV R5, #0x664

	MOV R6, #0x5144

	STR R4, [R0]

	STR R5, [R1]

	STR R6, [R2]

	LDR R7, [R0]

	LDR R8, [R1]

	LDR R9, [R2]
;	MOV input1, #5
;	MOV input2, #10
;	MOV input3, #6
	
	CMP R7, R8
	ITE GT
	MOVGT R10, R7; if input1 > input2, temp = input1
	MOVLE R10, R8; if input1 <= input2, temp = input2
	
	CMP R9, R10
	ITE GT
	MOVGT R4, R9; if input3 > temp, result = input3
	MOVLE R4, R10; if temp <= input3, result = temp
	MOV R0,R4
	BL printMsg
stop B stop ; stop program
	ENDFUNC
	END 