#ifndef SMULTIPLE_H
#define SMULTIPLE_H

#include "Pregunta.h"
#include <string>
using namespace std;

class sMultiple : public Pregunta
{
public:
    sMultiple(int);
    sMultiple();
    bool revisar(string, int) override;
    void read() override;
    int generarNumeroAleatorio() override;
    ~sMultiple() override;

    //void revisarPregunta() override;
};

#endif // SMULTIPLE_H
