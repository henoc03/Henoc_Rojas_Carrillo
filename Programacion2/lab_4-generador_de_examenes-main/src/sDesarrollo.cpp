#include "sDesarrollo.h"
#include <fstream>
#include <iostream>
using namespace std;

sDesarrollo::sDesarrollo()
{
}

sDesarrollo::~sDesarrollo()
{

}

int sDesarrollo::generarNumeroAleatorio()
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

sDesarrollo::sDesarrollo(int num_Pregunta)
{
    read ();
    cin.ignore();
    for (int i = 0; i < num_Pregunta; i++)
    {
        int random = this->generarNumeroAleatorio();
        cout << endl << enunciados[random] <<endl;
        getline(cin, resRecibida);
        this->saveRespuestas(i);
    }
    cout <<"Las respuestas de desarrollo seran evaluadas luego por un profesor"
        <<endl;
}


void sDesarrollo::read(){
    ifstream file("BancoPreguntas/Desarrollo.txt");

    if (file.fail())
    {
        std::cerr << "Error al abrir el archivo" << std::endl;
    }
    else
    {
        for (int i = 0; i < numPreguntas; ++i)
        {
            std::getline(file, enunciados[i]);
            noRepetir [i] = 1;
            file.ignore();
        }
    }
    file.close();
}

void sDesarrollo::saveRespuestas(int numRespuesta)
{
    ofstream file("BancoPreguntas/DesarrolloRespuestas.txt", ios::app);
    if (file.fail())
    {
        std::cerr << "Error al abrir el archivo" << std::endl;
    }
    else
    {
        file <<"Pregunta "<<numRespuesta + 1<<": "<<resRecibida<<endl;
        file <<endl;
    }



}