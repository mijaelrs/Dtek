.data

.align 2

numbers: .space 40

.align 2

.text
	la $t1,numbers
	addi $s0, $0, 10
loop:
	sw $s0, 0($t1)
	addi $t1, $t1, 4
	addi $s0, $s0, -1
	bne $s0, $0, loop
	la $t1,numbers
	lw $s0,0($t1)
	lw $s1,4($t1)
	add $s2, $s0, $s1

stop: 	j stop