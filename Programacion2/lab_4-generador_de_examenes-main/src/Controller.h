#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Pregunta.h"

class Controller
{
private:
    Pregunta* Examen;

public:
    int cantidadPreguntas;
    int cantidadPuntos;
    int totalPuntos = 0;
    string nombre;
    Controller();
    ~Controller();
    void hacerPreguntas();
    void imprimir();

};

#endif // CONTROLLER_H
