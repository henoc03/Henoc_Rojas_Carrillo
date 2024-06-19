#######################################
#            Snake Project            #
# Curso: Fundamentos de arquitectura  #
#             Anio: 2023              #
#         Ajustes del Bitmap          #
#      Width in pixels: 8             #
#      Heigh in Pixels: 8	          #
#      Display Width in Pixels: 512   #
#      Display Height in Pixels: 256  #	
#######################################

.data

display:           .space 0x80000 # Bitmap display de 512 ancho x 256 alto
xVel:              .word 0    #velocidad de X
yVel:              .word 0    #velocidad de Y
snakeXposition:    .word 10   #posicion en x pixel 256
snakeYposition:    .word 13  #posicion en y pixel 256
tail:              .word 3880		# Posicion de la cola
appleXposition:    .word 32   #posicion en X de la manzana
appleYposition:    .word 10   #posicion en Y de la manzana 
snakeUp:           .word	0x0000ff00	# pixel mover arriba
snakeDown:         .word	0x0100ff00	# pixel mover abajo
snakeLeft:         .word	0x0200ff00	# pixel mover izquierda
snakeRight:        .word	0x0300ff00	# pixel mover derecha
ConversionX:       .word 64   #Escala de conversion pixels en X
ConversionY:       .word 4    #Escala de conversion pixels en Y

.text

main:

## Establecer parametros del fondo
	la $t0, display       #Cargar direccion del bitmap display
	li $t1, 2048          #Guardar cantidad de pixels 512*256
	li $t2, 0x2E2E2E     #Guardar color gris oscuro para fondo

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
	
	
#snake pixels inicial
	la	$t0, display           #cargar direccion de display
	lw	$s2, tail		       #cargar tail
	lw	$s3, snakeUp		   #cargar snakeRight
	add	$t1, $s2, $t0		   #Iniciar tail en display
	sw	$s3, 0($t1)		       #Dibujar pixel de snake
	addi $t1, $t1, -256		   #t1 es el sigueinte tail
	sw	$s3, 0($t1)		       #Dibujar pixel en snake actual


	jal paintApple
## Poner la cabeza de la serpiente en bitmap
entradaLoop:

	lw	$t3, 0xffff0004		#Toma la entrada por teclado y la almacena en t1
	
	addi	$v0, $zero, 32	# syscall sleep
	addi	$a0, $zero, 120	# 120 ms
	syscall
	
	beq	$t3, 119, moverArriba	#si tecla presionada = w, se mueve hacia arriba.
	beq	$t3, 115, moverAbajo	#si tecla presionada = s, se mueve hacia abajo.
	beq	$t3, 100, moverDere	#si tecla presionada = d, se mueve hacia la derecha.
	beq	$t3, 97, moverIzq	#si tecla presionada = a, se mueve hacia la izquierda.
	beq	$t3, 0, moverArriba	#Arranca moviendose arriba.
	
moverArriba:
	lw	$s3, snakeUp	   # Carga direccion de la serpiente
	add	$a0, $s3, $zero	   #guarda la direccion en el argumento
	jal	moverSnake
	# actualizar movimeinto en pantalla
	jal actualizaSnake
	j	exitMove	

moverAbajo:
	lw	$s3, snakeDown	# Carga direccion de la serpiente
	add	$a0, $s3, $zero	#guarda la direccion en el argumento
	jal	moverSnake
	# actualizar movimeinto en pantalla
	jal 	actualizaSnake
	j	exitMove
	
moverIzq:
	lw	$s3, snakeLeft	# Carga direccion de la serpiente
	add	$a0, $s3, $zero	#guarda la direccion en el argumento
	jal	moverSnake
	# actualizar movimeinto en pantalla
	jal 	actualizaSnake
	j	exitMove
	
moverDere:
	lw	$s3, snakeRight	# Carga direccion de la serpiente
	add	$a0, $s3, $zero	#guarda la direccion en el argumento
	jal	moverSnake
	# actualizar movimeinto en pantalla
	jal 	actualizaSnake
	j	exitMove

exitMove:
	j 	entradaLoop		#Recursion de lectura de entrada


moverSnake:


	addiu 	$sp, $sp, -24	  # reserva espacio en la pila para $ra y $fp
	sw 	$fp, 0($sp)	          #Guarda $fp en la pila
	sw 	$ra, 4($sp)	          #Guarda %ra en la pila
	addiu 	$fp, $sp, 20	  #Setea el mover frame pointer
	lw	$t0, snakeXposition   #carga posicion de snake en X
	lw	$t1, snakeYposition	  #carga posicion de snake en Y
	lw	$t2, ConversionX	  #carga conversion de X (64)
	mult $t1, $t2		      #(Y * 64)
	mflo $t3			      # t3 = (Y * 64)
	add	$t3, $t3, $t0		  # t3 = (Y * 64) + X
	lw	$t2, ConversionY	  #carga conversion de Y (4)
	mult $t3, $t2		      # (Y * 64 + X) * 4
	mflo $t0			      # t0 = (Y * 64 + X) * 4
	la 	$t1, display    	  #carga display
	add	$t0, $t1, $t0		  # t0 = (Y * 64 + X) * 4 + display
	lw	$t4, 0($t0)		      #Guarda pixel original
	sw	$a0, 0($t0)		      #guarda direccion y color de bitmap

	lw	$t2, snakeUp		  #cargar mover arriba
	beq	$a0, $t2, velUp	      #Si direccion = arriba salta a velUp

	lw	$t2, snakeDown		  #cargar mover abajo
	beq	$a0, $t2, velDown	      #Si direccion = abajo salta a velUp

	lw	$t2, snakeLeft		  #cargar mover  izquierda
	beq	$a0, $t2, velLeft 	  #Si direccion = izq salta a velLeft

	lw	$t2, snakeRight		  #cargar mover derecha
	beq	$a0, $t2, velRight	  #Si direccion = derecha sala a dercha
	
velUp:
	addi $t5, $zero, 0		    #Velocidadx x = 0
	addi $t6, $zero, -1	 	    #verlocicad y = -1
	sw	$t5, xVel		        #carga las direcciones actualizadas
	sw	$t6, yVel		        #carga las direcciones actualizadas
	j exitVel
	
velDown:
	addi $t5, $zero, 0		    #velocidad x = 0
	addi $t6, $zero, 1 		    #velocidad y = 1
	sw	$t5, xVel		        #carga las direcciones actualizadas
	sw	$t6, yVel		        #carga las direcciones actualizadas
	j exitVel
	
velLeft:
	addi $t5, $zero, -1		    #velocidad X = -1
	addi $t6, $zero, 0 		    #Velocidad Y = 0
	sw	$t5, xVel		        #carga las direcciones actualizadas
	sw	$t6, yVel		        #carga las direcciones actualizadas
	j exitVel
	
velRight:
	addi $t5, $zero, 1	      	#velocidad X = 1
	addi $t6, $zero, 0 		    #velocidad Y = 0
	sw	$t5, xVel		        #carga las direcciones actualizadas
	sw	$t6, yVel		        #carga las direcciones actualizadas
	j exitVel
	
exitVel:
	
	li 	$t2, 0x00ff0000		        #carga color rojo
	bne	$t2, $t4, noEstaEnManzana	#si el color es distinto de rojo
	
	jal nuevaManzanaRand
	jal	paintApple
	j	exitMoverSnake
	
noEstaEnManzana:

	li	$t2, 0x2E2E2E		        # Carga color gris
	beq	$t2, $t4, movimientoValido	#si la cabeza esta sobre color gris
	addi 	$v0, $zero, 10	        #terminar ejecucion
	syscall
	
movimientoValido:

	lw	$t0, tail		        #cargar tail
	la 	$t1, display     	    #cargar direccion de display
	add	$t2, $t0, $t1		    #Enviar direccion de tail a display
	li 	$t3, 0x2E2E2E		    #cargar color gris
	lw	$t4, 0($t2)		        #carga direccion de tail y color
	sw	$t3, 0($t2)		        #cambia color de tail por color del fondo
	
	lw	$t5, snakeUp			            #carga snakeUp
	beq	$t5, $t4, tailUp		            #si direccion y color de tail son iguales a snakeUp
	
	lw	$t5, snakeDown			            #carga snakeDown
	beq	$t5, $t4, tailDown	                #si direccion y color de tail son iguales a snakeDown
	
	lw	$t5, snakeLeft			            #carga snakeLeft
	beq	$t5, $t4, tailLeft	                #si direccion y color de tail son iguales a snakeLeft
	
	lw	$t5, snakeRight			            #carga snakeRight
	beq	$t5, $t4, tailRight	                #si direccion y color de tail son iguales a snakeRight
	
tailUp:
	addi	$t0, $t0, -256		            #tail - 256 para que suba
	sw	$t0, tail		                    #guardar en memoria
	j exitMoverSnake
	
tailDown:
	addi	$t0, $t0, 256		            # tail + 256 para que baje
	sw	$t0, tail		                    #guardar en memoria
	j exitMoverSnake
	
tailLeft:
	addi	$t0, $t0, -4		             # tail - 1 para mover izquierda 
	sw	$t0, tail		                     #guardar en memoria
	j exitMoverSnake
	
tailRight:
	addi	$t0, $t0, 4		                 #tail + 1 para mover derecha
	sw	$t0, tail		                     #guardar en memoria
	j exitMoverSnake
	
exitMoverSnake:
	
	lw 	$ra, 4($sp)	                         #Restaurar de pila $ra
	lw 	$fp, 0($sp)	                         #Restaurar de pila $fp
	addiu 	$sp, $sp, 24	                 #Restauras sp
	jr 	$ra		                             #volver a mover...
	
actualizaSnake:

	addiu 	$sp, $sp, -24	  # reserva espacio en la pila para $ra y $fp
	sw 	$fp, 0($sp)	          #Guarda $fp en la pila
	sw 	$ra, 4($sp)	          #Guarda %ra en la pila
	addiu $fp, $sp, 20	      #Setea el mover frame pointer

	lw	$t3, xVel	          #cargar xVel
	lw	$t4, yVel	          #cargar yVel
	lw	$t5, snakeXposition	  #cargar snakeXposition 
	lw	$t6, snakeYposition	  #cargar snakeYposition
	add	$t6, $t6, $t4	      #Actualiza yposition
	add	$t5, $t5, $t3	      #Actualiza xposition
	sw	$t5, snakeXposition	  #guarda xposition actualizada
	sw	$t6, snakeYposition	  #guarda yposition actualizada
	
	lw 	$ra, 4($sp)	          #restaura $ra de la pila
	lw 	$fp, 0($sp)	          #restaura $fp de la pila
	addiu 	$sp, $sp, 24	  #restaura $sp
	jr 	$ra		              #retorna a mover...


paintApple:
	addiu 	$sp, $sp, -24	  # reserva espacio en la pila para $ra y $fp
	sw 	$fp, 0($sp)	          #Guarda $fp en la pila
	sw 	$ra, 4($sp)	          #Guarda %ra en la pila
	addiu 	$fp, $sp, 20	  #Setea el mover frame pointer
	
	lw	$t0, appleXposition		#cargar apple x
	lw	$t1, appleYposition		#cargar apple y
	lw	$t2, ConversionX	    #cargar conversionx
	mult $t1, $t2		        # appleYposition * 64
	mflo $t3			        # t3 = appleYposition * 64
	add	$t3, $t3, $t0		    # t3 = appleYposition * 64 + appleXposition
	lw	$t2, ConversionY	    # t2 = 4
	mult $t3, $t2		        #(snakeYposition * 64 + appleXposition) * 4
	mflo	$t0			        #(appleYposition * 64 + appleXposition) * 4
	la 	$t1, display	        #carga direccion de display
	add	$t0, $t1, $t0		    #(appleYposition * 64 + appleXposition) * 4 + display
	li	$t4, 0x00ff0000         #cargar color rojo        
	sw	$t4, 0($t0)		        #guardar direccion y color en display
	
	lw 	$ra, 4($sp)	          #restaura $ra de la pila
	lw 	$fp, 0($sp)	          #restaura $fp de la pila
	addiu $sp, $sp, 24	      #restaura $sp
	jr 	$ra		              #retorna a mover...

nuevaManzanaRand:
	addiu 	$sp, $sp, -24	  # reserva espacio en la pila para $ra y $fp
	sw 	$fp, 0($sp)	          #Guarda $fp en la pila
	sw 	$ra, 4($sp)	          #Guarda %ra en la pila
	addiu 	$fp, $sp, 20	  #Setea el mover frame pointer

redoRandom:		
	addi $v0, $zero, 42	    #random int 
	addi $a1, $zero, 63	    #limite superior
	syscall
	add	$t1, $zero, $a0	    #random appleXposition
	
	addi $v0, $zero, 42	    #random int 
	addi $a1, $zero, 31	    #limite superior
	syscall
	add	$t2, $zero, $a0	    #random appleYposition
	
	lw	$t3, ConversionX	#cargar conversionX
	mult $t2, $t3		    #appleYposition * 64
	mflo $t4			    #appleYposition * 64
	add	$t4, $t4, $t1		#appleYposition * 64 + random appleXposition
	lw	$t3, ConversionY	#cargar conversionY
	mult $t3, $t4		    # (random appleYposition * 64 + random appleXposition) * 4
	mflo $t4			    # (random appleYposition * 64 + random appleXposition) * 4
	
	la 	$t0, display	    #cargar direccion de display
	add	$t0, $t4, $t0		#(appleYposition * 64 + appleXposition) * 4 + display
	lw	$t5, 0($t0)		    #cargar pixel en t0
	
	li	$t6, 0x2E2E2E		#Cargar color gris claro
	beq	$t5, $t6, validApple	#si la posicion es valida
	j redoRandom

validApple:
	sw	$t1, appleXposition   #guarda la posicion de nueva manzana
	sw	$t2, appleYposition	  #guarda la posicion de nueva manzana

	lw 	$ra, 4($sp)	          #restaura $ra de la pila
	lw 	$fp, 0($sp)	          #restaura $fp de la pila
	addiu $sp, $sp, 24	      #restaura $sp
	jr 	$ra		              #retorna a mover...