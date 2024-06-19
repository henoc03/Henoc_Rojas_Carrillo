#ifndef SVERDADEROFALSO_H
#define SVERDADEROFALSO_H

#include "Pregunta.h"
#include <string>
using namespace std;

class sVerdaderoFalso : public Pregunta
{
public:
    sVerdaderoFalso(int);
    sVerdaderoFalso();
    bool revisar(string, int) override;
    void read() override;
    int generarNumeroAleatorio() override;
    ~sVerdaderoFalso() override;

    //void revisarPregunta() override;
};

#endif // SVERDADEROFALSO_H
