.data
	newLine: .asciiz "\n" 
	zero:	.float 0.0 
.text

main:

	addi $sp $sp -40

	
	#declare variable
	
	addi $s0, $zero, 0
	sw $s0 0($sp)
	
	#declare variable
	
	addi $s0, $zero, 0
	sw $s0 4($sp)
	
	#declare variable
	
	addi $s0, $zero, 0
	sw $s0 8($sp)
	
	#declare variable
	
	addi $s0, $zero, 0
	sw $s0 12($sp)
	
	addi $t0, $zero, 0
	
	#assign value
	
	sw $t0 12($sp)
	
	addi $t1, $zero, 3
	
	#assign value
	
	sw $t1 0($sp)
	
	addi $t2, $zero, 2
	
	#assign value
	
	sw $t2 4($sp)
	
	lw $t3, 0($sp)
	
	lw $t4, 4($sp)
	#SUB
	
	sub $t4, $t3, $t4
	
	#assign value
	
	sw $t4 8($sp)

	While0:	
	lw $t5, 12($sp)
	
	addi $t6, $zero, 10
	

	bgt $t5, $t6, Exit0
	
	#If statement
	
	lw $t7, 8($sp)
	
	addi $t0, $zero, 1
	

	bne $t0, $t7, Else0
	
	lw $t1, 8($sp)
	
	#print
	
	lw $s0, 8($sp) 
	jal printl
	
	lw $t2, 12($sp)
	
	addi $t3, $zero, 1
	#ADD
	
	add $t3, $t3, $t2
	
	#assign value
	
	sw $t3 12($sp)

	j EndIf0
	
	Else0:
	
	EndIf0:


	j While0


Exit0:
	
	addi $t4, $zero, 3
	
	lw $t5, 4($sp)
	#MULT
	
	mul $t5, $t5, $t4
	
	#assign value
	
	sw $t5 8($sp)
	
	addi $t6, $zero, 0
	
	#assign value
	
	sw $t6 12($sp)

	While1:	
	lw $t7, 12($sp)
	
	addi $t0, $zero, 10
	

	bgt $t7, $t0, Exit1
	
	lw $t1, 12($sp)
	
	addi $t2, $zero, 1
	#ADD
	
	add $t2, $t2, $t1
	
	#assign value
	
	sw $t2 12($sp)
	
	#If statement
	
	lw $t3, 8($sp)
	
	addi $t4, $zero, 6
	

	bne $t4, $t3, Else1
	
	lw $t5, 12($sp)
	
	#print
	
	lw $s0, 12($sp) 
	jal printl

	j EndIf1
	
	Else1:
	
	EndIf1:


	j While1


Exit1:
	

li	$v0 10
	syscall

	
printl:

	li $v0, 1
 	move $a0, $s0
 	syscall

 	li $v0, 4
 	la $a0, newLine
 	syscall

 	jr $ra

