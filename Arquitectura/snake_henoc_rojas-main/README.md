# Snake_Henoc_Rojas

## Descripción del proyecto

El objetivo de este proyecto es recrear el juego Snake implementado en Mips (emulador de ensamblador), esto con la intención de fortalecer el uso correcto de este sistema. Para ello es importante definir las reglas del juego.

El juego Snake se basa en una serpiente la cual está en constante movimiento dentro de un área cuadrada, en esta área aparecen manzanas de manera aleatoria y el objetivo que tenemos como jugadores es controlar la serpiente con el objetivo de comer estas manzanas y hacer más grande a la serpiente.

Dentro de las limitaciones con las que nos encontramos es que la serpiente nunca puede tocar los bordes del área que la encierra, de lo contrario perderemos, otra limitación es que la serpiente no puede colisionar contra su propio cuerpo, es decir que si la cabeza toca cualquier otra parte del cuerpo de la serpiente automáticamente perderemos el juego.

La regla anterior deja implícita a la siguiente regla, y es que la serpiente no puede hacer cambios de sentido en dirección contraria al movimiento actual, ya que esto representaría devolverse sobre su propio cuerpo lo cual nos haría perder. Es así que si la serpiente va hacia la izquierda, solamente podrá cambiar de sentido hacia arriba o hacia abajo, pero nunca hacia la derecha porque esto significa que chocará con su propio cuerpo.

Otra de las cosas sumamente importantes para tomar en cuenta es que la serpiente con cada manzana que come su cola se alarga un segmento, lo que significa que a medida que la serpiente crezca el juego se tornará más complicado.

## Milestones

### Primer Milestone:
El objetivo para esta fecha será entregar un programa donde se definan las variables a utilizar así como un bitmap en el que se encuentre la serpiente y la manzana.

### Segundo Milestone
La cabeza de la serpiente se mueve por el tablero y esta se come a las manzanas al cochar con ellas, se genera una nueva manzana de manera aleatoria en el mapa.
Retos: Al mover la cabeza esta deja un rastro en el mapa y por ende hay que limpiar ese rastro
Posibles soluciones: Crear un pixel cola que siga a la cabeza por detras, este pixel tail debe ser del mismo color que el fondo y ir un ciclo de programa por detras. Esto tambien puede servir para definir el crecimiento de la serpiente, haciendo que por cada manzana que se come, el pixel tail se atrasa un ciclo, para que de esta manera la serpiente se alargue un pixel visualmente.

### Tercer Milestone
En este milestone se hace crecer a la serpiente, además se modifica el algoritmo que pinta a la serpiente para poder incluir la funcionalidad de la cola y evitar el refresco constante de pantalla. De igual manera se incluyen las reglas de que si se hace un movimiento en sentido contrario la serpiente se detenga, y si toca su propio cuerpo tambien se detendrá.
Como objetivo para milestone 4 queda pendiente el implementar un sistema de puntajes y como obcional se me ocurre la idea de implementar algo que por cada 5 manzanas consumidas la velocidad aumente un aproximado del 10%.

### Cuarto Milestone
En esta entrega se incorpora un sistema que cuenta los puntos obtenidos y los imprime en consola al terminar el juego, ademas se incluye la funcionalidad de aumentar la velocidad al consumir una manzana, en este caso la velocidad se aumenta reduciendo el tiempo del sleep para el loop de entrada, por cada manzana disminuye 2 milisegundos.
