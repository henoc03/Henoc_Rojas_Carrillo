#######################################
#            Snake Project            #
# Curso: Fundamentos de arquitectura  #
#             Anio: 2023               #
#         Ajustes del Bitmap          #
#      Width in pixels: 8             #
#      Heigh in Pixels: 8	      #
#      Display Width in Pixels: 512   #
#      Display Height in Pixels: 256  #	
#######################################

.data


#la cabeza estara ubicada por defecto inicial en el centro del display


#La ubicacion de la manzana estara definida por valores randoms


display:         .space 0x80000 # Bitmap display de 512 ancho x 256 alto
Puntos:          .word 0    #Suma 1 punto por cada manzana consumida
ConversionX:     .word 64   #Escala de conversion pixels en X
ConversionY:     .word 4    #Escala de conversion pixels en Y
snakeXposition:  .word 10   #posicion en x pixel 256
snakeYposition:  .word 15   #posicion en y pixel 256
appleXposition:  .word 32   #posicion en X de la manzana (será un valor random)
appleYposition:  .word 10   #posicion en Y de la manzana (será un valor random)


.text

main:

## Establecer parametros del fondo
	la $t0, display       #Cargar direccion del bitmap display
	li $t1, 2048          #Guardar cantidad de pixels 512*256
	li $t2, 0x9496A2      #Guardar color verde oscuro para fondo

paintBackground:
	#addi $t0, $t0, -16
	sw $t2, -16($t0)   #Pasar color al bitmap
	addi $t0, $t0, 4   #Avanzar al siguiente bit
	addi $t1,$t1, -1   #Restar a la cantidad de pixels
	bnez $t1, paintBackground

## Establecer parametros del borde superior
	la $t0, display  #Cargar direccion del bitmap display
	add $t1, $zero, 64     #Guardar cantidad de pixels 512/8
	li $t2, 0x0C1EBA      #Guardar color verde oscuro para fondo 

paintTop:
	sw $t2, 0($t0)   #Pasar color al bitmap
	addi $t0, $t0, 4 #Avanzar al siguiente bit
	addi $t1,$t1, -1 #Restar a la cantidad de pixels
	bnez $t1, paintTop
	
## Establecer parametros del borde inferior
	la $t0, display  #Cargar direccion del bitmap display
	addi $t1, $zero, 64    #Guardar cantidad de pixels 2048-64
	addi $t0, $t0, 7936    #LLegar al pixel inicial de la fila inferior
	
paintBot:
	sw $t2, 0($t0)     #Pasar color al bitmap
	addi $t0, $t0, 4   #Avanzar al siguiente bit
	addi $t1,$t1, -1   #Restar a la cantidad de pixels
	bnez $t1, paintBot #Retornar hasta que $t1 sea cero

## Establecer parametros del borde izquierdo
	la $t0, display        #Cargar direccion del bitmap display
	addi $t1, $zero, 32    #Guardar cantidad de pixels 256/8
	##addi $t0, $t0, -16     #Pixel de inicio
paintLeft:
	sw $t2, 0($t0)       #Pasar color al bitmap
	addi $t0,$t0, 256   #Saltar al pixel en la posicion inferior
	addi $t1,$t1, -1     #Restar a la cantidad de pixels
	bnez $t1, paintLeft #Retornar hasta que $t1 sea cero

## Establecer parametros del borde derecho
	la $t0, display        #Cargar direccion del bitmap display
	addi $t1, $zero, 32    #Guardar cantidad de pixels 2048-64
	addi $t0, $t0, 252     #Pixel de inicio
paintRight:
	sw $t2, 0($t0)	     #Pasar color al bitmap
	addi $t0,$t0,256     #Saltar al pixel en la posicion inferior
	addi $t1,$t1, -1     #Restar a la cantidad de pixels
	bnez $t1, paintRight #Retornar hasta que $t1 sea cero
	
	
## Poner la cabeza de la serpiente en bitmap
entradaLoop:
	lw $t1, 0xffff0004     #Toma la entrada por teclado y la almacena en t1
	
	addi	$v0, $zero, 32	# syscall sleep
	addi	$a0, $zero, 120	# 120ms
	syscall
	
	beq $t1, 119, moverArriba  #si tecla presionada = w, se mueve hacia arriba.
	beq $t1, 115, moverAbajo   #si tecla presionada = s, se mueve hacia abajo.
	beq $t1, 100, moverDere    #si tecla presionada = d, se mueve hacia la derecha.
	beq $t1, 97, moverIzq      #si tecla presionada = a, se mueve hacia la izquierda.
	beq $t1, 0, moverDere      #Arranca moviendose a la derecha

moverArriba:
	lw $t1, snakeYposition   #carga posicion en Y
	lw $t2, snakeXposition	 #carga posicion en X
	addi $t1, $t1, -1  	 #Resta 1 para que suba un pixel
	beq $t1, 0, exit         #Si toca borde termina ejecucion
	sw $t1, snakeYposition   #Actualiza el valor en Y
	sw $t2, snakeXposition	 #Actualiza el valor en X
	jal choqueConManzana	 #Evalua si choca con manzana
	
	jal paintBack            #Actualiza el fondo y lo pinta para borar rastro de snake
	jal paintSnake             #Salta a imprimir snake head y dentro de esta se llama a paintApple
	jal paintApple             #Salta a imprimir manzana
	j entradaLoop              #Recursion de lectura de entrada
moverAbajo:
	lw $t1, snakeYposition   #carga posicion en Y
	lw $t2, snakeXposition	 #carga posicion en X
	addi $t1, $t1, 1  	 #Suma 1 para que baje un pixel
	beq $t1, 31, exit         #Si toca borde termina ejecucion
	sw $t1, snakeYposition   #Actualiza el valor en Y
	sw $t2, snakeXposition	 #Actualiza el valor en X
	jal choqueConManzana	 #Evalua si choca con manzana
	
	jal paintBack            #Actualiza el fondo y lo pinta para borar rastro de snake
	jal paintSnake             #Salta a imprimir snake head y dentro de esta se llama a paintApple
	jal paintApple             #Salta a imprimir manzana
	j entradaLoop              #Recursion de lectura de entrada

moverDere:
	lw $t1, snakeYposition   #carga posicion en Y
	lw $t2, snakeXposition	 #carga posicion en X
	addi $t2, $t2, 1  	 #Suma 1 para que se mueva a un pixel a la derecha
	beq $t2, 63, exit         #Si toca borde termina ejecucion
	sw $t1, snakeYposition   #Actualiza el valor en Y
	sw $t2, snakeXposition	 #Actualiza el valor en X
	jal choqueConManzana	 #Evalua si choca con manzana
	
	jal paintBack            #Actualiza el fondo y lo pinta para borar rastro de snake
	jal paintSnake             #Salta a imprimir snake head y dentro de esta se llama a paintApple
	jal paintApple             #Salta a imprimir manzana
	j entradaLoop              #Recursion de lectura de entrada

moverIzq:
	lw $t1, snakeYposition   #carga posicion en Y
	lw $t2, snakeXposition	 #carga posicion en X
	addi $t2, $t2, -1  	 #Resta 1 para que se mueva a un pixel a la izquierda
	beq $t2, 0, exit         #Si toca borde termina ejecucion
	sw $t1, snakeYposition   #Actualiza el valor en Y
	sw $t2, snakeXposition	 #Actualiza el valor en X
	jal choqueConManzana	 #Evalua si choca con manzana
	
	jal paintBack            #Actualiza el fondo y lo pinta para borar rastro de snake
	jal paintSnake             #Salta a imprimir snake head y dentro de esta se llama a paintApple
	jal paintApple             #Salta a imprimir manzana
	j entradaLoop              #Recursion de lectura de entrada


paintBack:
      	## Establecer parametros del fondo
      	#addiu $sp, $sp, -4    #reserva espacio en la pila para $ra
      	#sw    $ra, 0($sp)     #Guarda $ra en la pila
	la $t0, display       #Cargar direccion del bitmap display
	li $t1, 2048          #Guardar cantidad de pixels 512*256
	li $t2, 0x9496A2      #Guardar color verde oscuro para fondo
paintBackgroundRepeat:
	#addi $t0, $t0, -16
	sw $t2, -16($t0)   #Pasar color al bitmap
	addi $t0, $t0, 4   #Avanzar al siguiente bit
	addi $t1,$t1, -1   #Restar a la cantidad de pixels
	bnez $t1, paintBackgroundRepeat
	jr $ra             #retorna a mover..
	
	
choqueConManzana:

	##variables 
	# $t0 posicion snake X
	# $t1 posicion snake Y
	# $t2 posicion apple X
	# $t3 posicion apple Y
	# $t4 random X
	# $t5 random Y
	
	addiu $sp, $sp, -4  #Reserva 4 para gurdar la direccion de retorno a mover...
	sw $ra, 0($sp)      #Guarda la direccion de retorno a mover...
	
	lw $t0, snakeXposition  #Caraga posicion de snake en X
	lw $t1, snakeYposition  #Carga posicion de snake en Y
	lw $t2, appleXposition  #Carga posicion de apple en X
	lw $t3, appleYposition  #Carga posicion de apple en Y
	
	bne $t0, $t2, exitChoqueManzana  #Verifica igualdad de posiciones en X y sale del choque con manzana y vuelve e mover...
	bne $t1, $t3, exitChoqueManzana  #Verifica igualdad de posiciones en Y y sale del choque con manzana y vuelve e mover...
	
	##Crea random X
	addi	$v0, $zero, 42	# random int 
	addi	$a1, $zero, 61	# rango superior
	syscall
	add	$t4, $zero, $a0 # guarda random appleX
	addi	$t4, $t4, 1	#suma 1 para dejar rango entre 1 - 62
	
	##Crea random Y
	addi	$v0, $zero, 42	# random int 
	addi	$a1, $zero, 29	# rango superior
	syscall
	add	$t5, $zero, $a0 # guarda random appleY
	addi	$t5, $t5, 1	#suma 1 para dejar rango entre 1 - 30
	
	sw $t4, appleXposition  #Actualiza apple X con nuevo valor
	sw $t5, appleYposition  #Actualiza apple Y con nuevo valor
	
	j exitChoqueManzana     #Retorna a mover...
	

exitChoqueManzana:
	lw $ra, 0($sp)      #Carga direccion de retorno
	addiu $sp, $sp, 4   #Restaura el stack pointer
	jr $ra              #Retorna a mover...


paintSnake:
	la $t0, display         #Cargar display
	lw $t1, ConversionX     #t1 = 64
	li $t2, 0x35F010        #Cargar color verde de la serpiente
	#addi $t0, $t0, -4      #Posicion inicial en display
	lw $t3, snakeYposition  #Cargar posicion de la serpiente en Y
	mult $t3, $t1           #(16 * 64)
	mflo $t5                #t5 = (16*64)
	lw $t3, snakeXposition  #Cargar posicion de la serpiente en X
	add $t5,$t5,$t3         # t5 = (16*64)+32
	lw $t1, ConversionY     # t1 = 4
	mult $t5, $t1           # ((16*64)+32)*4
	mflo $t5                #t5 = ((16*64)+32)*4
	add $t0, $t0, $t5       # Display en posicion central
	sw  $t2, 0($t0)         #Pasar color a bitmap
	jr $ra  #Retorno a entrada loop
	##j paintApple            #Salta a paint apple (si la cabeza toca manzana, la manzana se pone en otra posicion
	
	

paintApple:
	la $t0, display         #Cargar display
	lw $t1, ConversionX     #t1 = 64
	li $t2, 0xF70000         #Cargar color verde de la serpiente
	#addi $t0, $t0, -4      #Posicion inicial en display
	lw $t3, appleYposition  #Cargar posicion de la manzana en Y
	mult $t3, $t1           #(16 * 64)
	mflo $t5                #t5 = (16*64)
	lw $t3, appleXposition  #Cargar posicion de la manzana en X
	add $t5,$t5,$t3         # t5 = (16*64)+32
	lw $t1, ConversionY     # t1 = 4
	mult $t5, $t1           # ((16*64)+32)*4
	mflo $t5                #t5 = ((16*64)+32)*4
	add $t0, $t0, $t5       # Display en posicion central
	sw  $t2, 0($t0)         #Pasar color a bitmap
	jr $ra                  #Retorno a entrada loop
	##j entradaLoop           #Retorno a loop de entrada

exit: 
	addi $v0, $zero, 10
	syscall





   
