main:
	li $a1, 0x10
	li $a2, 3
	div $a0, $a1, $a2
	mul $t1, $a0, $a2
	sub $v0, $a1, $t1
	