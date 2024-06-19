![Texto alternativo](assets\Iconos.jpg)

# Tarea programada 4
### Autores: 
Ignacio Redondo y Henoc Rojas

Esta tarea tiene como objetivo implementar una matriz con una matriz de relación en la cual los usuarios se encuentran relacionados por medio de números enteros dentro de las filas y columnas que conforman la matriz. Como esta matriz debe ser dinámica se diseño una plantilla en la cual la matriz está definida por listas de nodos para las columnas y filas, en donde la distribución de los nodos simila el comportamiento de una matriz tanto en su diagrama como en sus algoritmos de busqueda y escritura.

Este es un esquema del diseño utilizado para los nodos:

![Texto alternativo](assets\Esquema.jpg)

El nodo consta de 3 punteros a otros nodos los cuales son nextRow, nextCol y prev. Además de contar con un puntero de tipo parametrizado "object" el cual guarda el objeto en cuestion, además de una variable de tipo entero que guarda la relación en esa posición.

El siguiente es un diagrama del funcionamiento de la matriz de relación: 

![Texto alternativo](assets\matrizDiagrama.jpg)

En este ejemplo de matriz el objeto [1] y el objeto [4] poseen una relación mutua. El objeto [2] tiene una relación con el objeto [3] y el objeto [3] tiene una relación con el objeto [1].

## Implementación

### Flirty
    
Flirty es una app de citas romanticas en la cual los usuarios logueados tienen la posibilidad de entablar relaciones entre ellos. Estas personas pueden dar follow a los usuarios registrados y si dos usuarios se dan follow mutuamente entonces se genera un match, desplegando un mensaje especial.

### Train
Esta aplicacion tiene la funcionalidad de interconectar estaciones de tren según las tarifas entre cada una de estas.

### Employ-E
Employ-E es una app que se encarga de registrar cuales empleados se encuentran dentro de un mismo grupo de trabajo. En el caso de que dos empleados trabajen en el mismo departamento, se genera una relacion estre ellos dos.
