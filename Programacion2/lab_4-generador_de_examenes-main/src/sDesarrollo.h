#ifndef SDESARROLLO_H
#define SDESARROLLO_H

#include "Pregunta.h"
#include <string>
using namespace std;

class sDesarrollo : public Pregunta
{
public:
    sDesarrollo(int);
    sDesarrollo();
    void saveRespuestas(int);
    //bool revisar(string, int);
    void read() override;
    int generarNumeroAleatorio() override;
    ~sDesarrollo() override;

    //void revisarPregunta() override;
};

#endif // SDESARROLLO_H
