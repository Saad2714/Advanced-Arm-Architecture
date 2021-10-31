	;Fibonacci
	
	AREA     appcode, CODE, READONLY
	EXPORT __main 
	IMPORT printMsg
		
	ENTRY 

__main FUNCTION
		MOV R8, #07
		MOV R1, #00
		MOV R2, #01

loop    CMP R8, #00
		BLE stop        ; Jump if less than or equal to

		MOV R4, R2
		ADD R2, R2, R1
		MOV R5, R2
		;MOV R2,
		MOV R0, R2
		BL printMsg
		MOV R2, R5
		MOV R1, R4
		SUB R8, #01
		B loop          ; Jump back to loop

stop B stop 		; stop program
	ENDFUNC
	
	END
	
	
	