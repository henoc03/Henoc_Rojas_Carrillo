#ifndef SCOMPLETE_H
#define SCOMPLETE_H

#include "Pregunta.h"
#include <string>
using namespace std;

class sComplete : public Pregunta
{
public:
    sComplete(int);
    sComplete();
    bool revisar(string, int) override;
    void read() override;
    int generarNumeroAleatorio() override;
    ~sComplete() override;

    //void revisarPregunta() override;
};

#endif // SCOMPLETE_H
