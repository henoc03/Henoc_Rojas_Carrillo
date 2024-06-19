#######################################
#            Snake Project            #
# Curso: Fundamentos de arquitectura  #
#             Año: 2023               #
#         Ajustes del Bitmap          #
#      Width in pixels: 8             #
#      Heigh in Pixels: 8	      #
#      Display Width in Pixels: 512   #
#      Display Height in Pixels: 256  #	
#######################################

.data


#la cabeza estara ubicada por defecto inicial en el centro del display


#La ubicacion de la manzana estara definida por valores randoms


display: .space 0x80000 # Bitmap display de 512 ancho x 256 alto

ConversionX: .word 64
ConversionY: .word 4

snakeXposition: .word 32     #posicion en x pixel 256
snakeYposition:  .word 16    #posicion en y pixel 256

appleXposition:  .word 32     #posicion en X de la manzana (será un valor random)
appleYposition: .word 10      #posicion en Y de la manzana (será un valor random)


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



exit: 
	addi $v0, $zero, 10
	syscall





	

   
