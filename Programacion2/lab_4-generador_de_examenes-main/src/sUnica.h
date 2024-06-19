
#ifndef SUNICA_H
#define SUNICA_H

#include "Pregunta.h"
#include <string>
using namespace std;

class sUnica : public Pregunta
{
public:
    sUnica(int);
    sUnica();
    bool revisar(string, int) override;
    void read() override;
    int generarNumeroAleatorio() override;
    ~sUnica() override;

    //void revisarPregunta() override;
};

#endif // sUnica_H