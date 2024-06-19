# Tarea programada 2: Coloreto

Este es un programa de consola, que permite inicializar el juego Coloreto. Dicho programa está escrito en C++ y hace uso de clases, objetos y variedad de metodos para la estructuración de la información.


## Agregar archivos al repositorio

- [ ] [Crear](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#create-a-file) o [subir](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#upload-a-file) archivos
- [ ] [Agregar archivos usando la línea de comando](https://docs.gitlab.com/ee/gitlab-basics/add-file.html#add-a-file-using-the-command-line) o inserta un repositorio Git existente con el siguiente comando:

```
cd existing_repo
git remote add origin https://git.ucr.ac.cr/HENOC.ROJAS/tarea-programada-2_coloreto.git
git branch -M main
git push -uf origin main
```

## Integre con sus herramientas

- [ ] [Configurar integraciones de proyecto](https://git.ucr.ac.cr/HENOC.ROJAS/tarea-programada-2_coloreto/-/settings/integrations)

## Colabora con tu equipo

- [ ] [Invitar a miembros del equipo y colaboradores](https://docs.gitlab.com/ee/user/project/members/)
- [ ] [Crear un nuevo merge request](https://docs.gitlab.com/ee/user/project/merge_requests/creating_merge_requests.html)
- [ ] [Cerrar problemas automáticamente a partir de merge requests](https://docs.gitlab.com/ee/user/project/issues/managing_issues.html#closing-issues-automatically)
- [ ] [Habilitar aprobaciones de merge request](https://docs.gitlab.com/ee/user/project/merge_requests/approvals/)
- [ ] [Automáticamente hacer merge cuando el pipeline sea exitoso](https://docs.gitlab.com/ee/user/project/merge_requests/merge_when_pipeline_succeeds.html)

## Probar e implementar

Usar la integracion continua built-in  en GitLab.

- [ ] [Empezar con GitLab CI/CD](https://docs.gitlab.com/ee/ci/quick_start/index.html)
- [ ] [Analice su código en busca de vulnerabilidades conocidas con Static Application Security Testing(SAST)](https://docs.gitlab.com/ee/user/application_security/sast/)
- [ ] [Implementar en Kubernetes, Amazon EC2, o Amazon ECS usando Auto Deploy](https://docs.gitlab.com/ee/topics/autodevops/requirements.html)
- [ ] [Implementaciones pull-based para mejorar la gestión de Kubernetes](https://docs.gitlab.com/ee/user/clusters/agent/)
- [ ] [Configurar entornos protegidos](https://docs.gitlab.com/ee/ci/environments/protected_environments.html)

***

## Nombre
Coloreto, juego de cartas y estrategia. 

## Descripcion del juego
Coloretto es un juego de cartas, estrategia y toma de decisiones en el que los jugadores compiten  para acumular la mayor cantidad de puntos para coleccionar juegos de cartas de colores. 

 El juego utiliza una baraja de cartas que consta de diferentes palos. El objetivo del juego es acumular la mayor cantidad de puntos al final del juego. 

 En cada turno, los jugadores pueden colocar una carta en una de las filas de colores disponibles. Al colocar una carta, el jugador tiene la opción de tomar todas las cartas del mismo color de la fila o tomar una  carta del mazo central.

 El juego continúa hasta que se agoten todas las cartas del mazo central. Luego, los jugadores suman sus puntos y el que haya acumulado más puntos al final de la partida es el ganador.


## Visuales
(Las siguientes imagenes no son de una misma partida, solo es para que se visualicen la etapas del juego)

![imagen 1](/assets/ss01.jpg)
![imagen 2](/assets/ss02.JPG)
![imagen 3](/assets/ss03.jpg)
![imagen 4](/assets/ss04.jpg)
![imagen 5](/assets/ss05.png)




## Instalacion
### Requisitos
* Compilador de C++: Asegúrate de tener un compilador de C++ instalado en tu sistema. 
* Entorno de desarrollo integrado (IDE): Si prefieres utilizar un entorno de desarrollo integrado para compilar y ejecutar tu proyecto, se recomienda Visual Studio Code con el complemento C++, o bien cualquier otro IDE de tu elección. Asegúrate de tener instalado el IDE de tu preferencia antes de continuar.
### Pasos de instalación y ejecucion en Windows
1. Descarga el código fuente del proyecto desde el repositorio o mediante la opción de clonar el repositorio utilizando Git.
2. Abre el archivo main.cpp en tu IDE o editor de código.
3. Compila el código fuente: Desde el IDE simplemente busca la opcion de comppilar. Si se utiliza el compilador GCC desde la línea de comandos, puedes ejecutar el siguiente comando en la carpeta del proyecto: ```
g++ main.cpp -o output.exe ```
Esto generará un archivo ejecutable llamado output.exe en la misma carpeta.
4. Ejecuta el programa: Si estás utilizando un IDE, generalmente hay un botón o opción para ejecutar el programa desde el IDE mismo. Si estás utilizando la línea de comandos, puedes ejecutar el siguiente comando: ```output.exe ``` 


## Funcionamiento del programa
###  ¿Cómo se utiliza o cuales son los pasos del programa?
Primero se despliega un menu con tres opciones: 
1. Set colors: Pide la cantidad de colores. 
2. Set players: Pide la cantidad de jugadores. 
3. Start game: Crea el juego y lo empieza.

Ahora se muestra el estado actual del juego, como las cartas en el tablero y en los mazos de los jugadores.
Luego, se le pide al jugador que elija una opción:
* Opción 1: Tomar una carta del mazo y colocarla en su mazo.
* Opción 2: Tomar todas las cartas de una fila del tablero y agregarlas a su mazo.

Si no hay filas completas en el tablero, se permiten ambas opciones. Si hay filas completas, solo se permite la opción 2.

Después de que todos los jugadores han tomado su turno, se muestra la puntuación actualizada de los jugadores.

## Suposiciones de programación
En la elaboracion del proyecto se establece una cantidad maxima de 12 colores, donde estos son los que vienen por defecto en SetConsoleTextAttribute() de Windows asignados por numeros.

Ademas, es dinamico, sin embargo se recomienda que sea siempre 2 jugadores minimo y maximo 4 jugadores.

Se supone que tenga una nocion correcta y logica cuando se le pidan datos especificos.


## Autores
* Henoc Rojas Carrillo
* Dylan Antonio Torres Gaitan
* Gael Alpizar Alfaro 


## Curso
* CI-0113-2023

![](https://devirinvestments.s3.eu-west-1.amazonaws.com/img/catalog/product/8436017225709-1200-face3d-copy.jpg)

