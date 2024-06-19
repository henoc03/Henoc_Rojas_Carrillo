# Examen Automático

<p align="center">
  <img src="https://th.bing.com/th/id/OIP.6h4K1OOodgq4W4G3XI3yewHaHa?pid=ImgDet&rs=1" width="256" height="256">
</p>

Este proyecto consiste en la implementación de un sistema que genera exámenes automáticamente de biología de tercer año para una institución educativa. El objetivo es reducir el tiempo invertido por los profesores en la elaboración de exámenes, aprovechando el hecho de que las preguntas se repiten con el tiempo.

## Funcionalidad

El programa cuenta con un banco de preguntas y es capaz de generar un examen nuevo con base en la cantidad de preguntas requeridas y el puntaje total mínimo. El sistema selecciona preguntas aleatorias del banco, asegurándose de que se cumplan ambas condiciones.

Las preguntas del examen pueden ser de diferentes tipos, los cuales se pueden agregar y personalizar en el programa. Hasta ahora, se han implementado los siguientes tipos de preguntas:

- Selección única: Se presentan 4 posibles respuestas y solo una es correcta.
- Selección múltiple: Se presentan 4 posibles respuestas y puede haber una o más correctas.
- Complete: Se muestra una oración incompleta y se solicita al estudiante que complete la palabra o frase que la termina.
- Verdadero o falso: Se presenta una afirmación y el estudiante debe indicar si es verdadera o falsa.
- Desarrollo: Se presenta una pregunta y el estudiante debe dar una respuesta amplia. Esta pregunta es por puntos extra y se guardara en un txt que posteriormente el docente revisara y decidira si otorgar o no los puntos extra.

## Cómo utilizar el programa

1. Ejecutar el programa.
2. Ingresar la cantidad de preguntas deseadas para el examen.
3. Ingresar los puntos mínimos requeridos para el examen (por la implementacion y el valor de cada pregunta, los puntos minimos no pueden ser mayores que la multiplicacion de preguntas totales por 1.5).
4. El programa generará automáticamente el examen con preguntas aleatorias del banco.
5. Se mostrará cada pregunta una por una y se solicitarán las respuestas correspondientes.
6. Al finalizar, se mostrará la calificación obtenida sobre 100.

## Autor del Proyecto

- Henoc Rojas Carrillo, C26764
- Ignacio Redondo Alfaro, C06420