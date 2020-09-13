.data
	newLine: .asciiz "\n" 
	zero:	.float 0.0 
.text

main:

	addi $sp $sp -40

	
	addi $s0, $zero, 0
	sw $s0 0($sp)
	
	addi $s0, $zero, 0
	sw $s0 4($sp)
	
	addi $s0, $zero, 0
	sw $s0 8($sp)
	
	addi $s0, $zero, 0
	sw $s0 12($sp)
	
	addi $s0, $zero, 0
	sw $s0 12($sp)
	
	addi $s0, $zero, 1
	sw $s0 0($sp)
	
	addi $s0, $zero, 2
	sw $s0 4($sp)
	
	addi $s0, $zero, 3
	sw $s0 8($sp)
	
	addi $t0, $zero, 3
	addi $t1, $zero, 3

	bne $t0, $t1, Else0
	
	lw $s0, 8($sp) 
	jal printl

	j EndIf0
	
	Else0:
	
	lw $s0, 0($sp) 
	jal printl
	
	EndIf0:

	addi $t0, $zero, 0
	addi $t1, $zero, 10
	While0:	
	bgt $t0, $t1, Exit0
	
	lw $s0, 0($sp) 
	jal printl
	
	addi $s0, $zero, 1
	sw $s0 12($sp)


	j While0


Exit0:
	

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

