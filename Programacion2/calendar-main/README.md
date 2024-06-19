# CalendarPro

</center>


<div align="center">

  <img src = "https://static.vecteezy.com/system/resources/previews/000/288/043/original/business-calendar-vector-icon.jpg" width = "    200" height = "200" >

</div>


CalendarPro es una aplicación de calendario desarrollada en C++ que permite a los usuarios de una organización crear, manipular y seguir todo tipo de reuniones y eventos, así como compartirlos con otras personas. La funcionalidad principal de la aplicación es personalizar un calendario por persona, estableciendo también vínculos con los calendarios de otros usuarios y permitiendo la compartición de información para una mejor organización del día.

## Características principales

- **Creación y gestión de reuniones y eventos:** Los usuarios pueden crear y administrar reuniones y eventos en su calendario personalizado.
- **Compartir calendarios:** Los usuarios pueden compartir su calendario con otras personas, lo que facilita la colaboración y la organización conjunta.
- **Herencia y polimorfismo:** La aplicación utiliza herencia y polimorfismo para generar calendarios, accesos y acciones adecuadas para cada tipo de usuario y reservación.
- **Usuarios con niveles de jerarquía:** La organización cuenta con usuarios en diferentes niveles de jerarquía:
  - Individual Contributor: Personas responsables únicamente de sí mismas.
  - Manager: Personas con subalternos a su cargo, además de sus responsabilidades regulares.
- **Autenticación de usuarios:** Al abrir la aplicación CalendarPro, se solicita al usuario que ingrese su nombre de usuario y contraseña para iniciar sesión en el sistema.
- **Cierre de sesión:** Los usuarios tienen la opción de cerrar sesión en cualquier momento, lo que los llevará de vuelta a la pantalla de inicio de sesión.
- **Tipos de reservaciones:** La aplicación permite generar diferentes tipos de reservaciones, cada una con características específicas:
  - Reunión: Una persona, como organizadora, invita a varias personas a un encuentro sincrónico, incluyendo una lista de asistentes y un lugar de reunión.
  - Cita: Una persona bloquea su calendario por un evento personal, sin incluir detalles como el sitio de reunión ni la participación de otras personas.
  - Cubículo: Una persona reserva un cubículo de la oficina por un tiempo determinado, sin bloquear el calendario y validando la disponibilidad del cubículo.
  - Actividad: Varias personas organizan un evento en una zona común de la oficina, donde todos los participantes son considerados organizadores.
  - Evento diario: Permite a una persona registrar eventos que abarcan todo un día, como períodos de vacaciones.

## Uso de la aplicación

Una vez iniciada la sesión en CalendarPro, los usuarios pueden acceder a un menú que les permite ver y manipular su propio calendario, así como el de otras personas. La relación entre usuarios y calendarios es importante debido a los diferentes niveles de acceso que tiene cada persona. A grandes rasgos, la aplicación permite a los usuarios:

- Ver su calendario de eventos aceptados.
- Ver y aceptar o rechazar invitaciones de eventos de otras personas.
- Crear una nueva reservación en su propio calendario, especificando el tipo de reservación. Si la reservación involucra a otras personas, se guardará también en sus calendarios.
- Cancelar una reservación o su participación. Si el usuario es el organizador o el único participante, el evento se cancela para todas las personas involucradas y se elimina de sus calendarios.
- Modificar una reservación en su calendario, siempre  y cuando sea el organizador o la única persona involucrada. Los cambios realizados deben notificarse a todas las personas involucradas en el evento.
- Ver el calendario de otras personas. Los usuarios pueden ver el calendario de otros usuarios, con diferentes niveles de acceso:
  - Subalternos: Pueden ver todos los detalles de las actividades en el calendario.
  - No subalternos: Solo pueden ver la disponibilidad de la persona sin acceder a los detalles específicos.

El sistema almacena la información de los usuarios en un archivo, incluyendo sus datos personales y configuraciones de calendario. Idealmente, los calendarios también se almacenan para cargar los datos al iniciar el programa. En caso de no disponer de datos previos, se asume que todos los calendarios están vacíos al inicio.

## Autor del Proyecto

- Henoc Rojas Carrillo, C26764
- Ignacio Redondo Alfaro, C06420