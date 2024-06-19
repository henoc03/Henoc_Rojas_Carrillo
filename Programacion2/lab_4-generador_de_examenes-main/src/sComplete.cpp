#include "sComplete.h"
#include <fstream>
#include <iostream>
using namespace std;


sComplete::sComplete()
{
}

sComplete::~sComplete()
{

}

int sComplete::generarNumeroAleatorio()
{
    int random = rand() % 20; 
    if(noRepetir [random] == 1)
    {
        noRepetir [random] = 0;
        return random;
    }
    generarNumeroAleatorio(); 
    //return 0;
}

sComplete::sComplete(int num_Pregunta)
{
    read ();
    for (int i = 0; i < num_Pregunta; i++)
    {
        int random = generarNumeroAleatorio();
        cout << endl << enunciados[random] <<endl;
        cin>>resRecibida;
        if(revisar(resRecibida, random)){
            puntos = puntos + 2;
        }
    }

}


void sComplete::read(){
        ifstream file("BancoPreguntas/Complete.txt");

    if (file.fail())
    {
        std::cerr << "Error al abrir el archivo" << std::endl;
    }
    else
    {
        for (int i = 0; i < numPreguntas; ++i)
        {
            std::getline(file, enunciados[i]);
            std::getline(file, respuestas[i]);
            noRepetir [i] = 1;
            file.ignore();
        }
    }  
    file.close(); 
}

bool sComplete::revisar(string resRecibida, int random)
{
    return (resRecibida == respuestas[random]);
}