#ifndef PREGUNTA_H
#define PREGUNTA_H
#include <string>
#include <iostream>
using namespace std;

class Pregunta
{
public:

    int puntos = 0;

protected:
    string respuestaRecibida;
    const int numPreguntas = 20;
    string enunciados[20];
    string respuestas[20];
    int noRepetir [20];
    string resRecibida;
    

public:
    Pregunta()
    {
    }
    virtual void read()
    {
    }
    virtual int generarNumeroAleatorio()
    {
        return 0;
    }
    virtual  bool revisar(string, int)
    {
        return false;
    }
    virtual ~Pregunta()
    {
    }
};

#endif // PREGUNTA_H
