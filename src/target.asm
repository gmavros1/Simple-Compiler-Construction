.data
	newLine: .ascizz "\n" 
	zero:	.float 0.0 
.text

main:
	
	addi $s0, $zero, 0 
	addi $sp $sp -4
	sw $s0 0($sp)
	
	addi $s0, $zero, 0 
	addi $sp $sp -4
	sw $s0 4($sp)
	
	addi $s0, $zero, 0 
	addi $sp $sp -4
	sw $s0 8($sp)
	
	lw $s0, 4($sp) 
	jal printl
	

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

