#include "sUnica.h"
#include <fstream>
#include <iostream>
using namespace std;
sUnica::sUnica()
{
}

sUnica::~sUnica()
{

}

int sUnica::generarNumeroAleatorio()
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

sUnica::sUnica(int num_Pregunta)
{
    read ();
    for (int i = 0; i < num_Pregunta; i++)
    {
        int random = generarNumeroAleatorio();
        cout << endl << enunciados[random] <<endl;
        cin>>resRecibida;
        if(revisar(resRecibida, random)){
            puntos++;
        }
    }


}

void sUnica::read(){
    ifstream file("BancoPreguntas/SeleccionUnica.txt");

    if (file.fail())
    {
        std::cerr << "Error al abrir el archivo" << std::endl;
    }
    else
    {
        for (int i = 0; i < numPreguntas; ++i)
        {
            string tempTexto;
            string tempLinea;
            for (int j = 0; j < 5; ++j)
            {
                getline(file, tempLinea);
                tempTexto = tempTexto + tempLinea + "\n"; 
            }
            noRepetir[i] = 1;
            enunciados[i] = tempTexto;
            getline(file, respuestas[i]);
            file.ignore();
        }
    } 
    file.close();  
}

bool sUnica::revisar(string resRecibida, int random)
{
    return (resRecibida == respuestas[random]);
}




