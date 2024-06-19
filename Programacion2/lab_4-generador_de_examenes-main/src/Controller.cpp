#include "Controller.h"
#include "Pregunta.h"
#include "sVerdaderoFalso.h"
#include "sUnica.h"
#include "sMultiple.h"
#include "sComplete.h"
#include "sDesarrollo.h"

#include <iostream>
#include <string>

using namespace std;

Controller::Controller()
{
    // Solicitar información al usuario
    cout << "--Bienvenido al sistema generador de examenes de biologia de" 
    " tercero de secundaria--" << endl;
    cout << "\n\nPor favor, ingrese su nombre: ";
    getline(cin, nombre);

    cout << endl << "Ingrese la cantidad de preguntas para el examen: ";
    cin >> cantidadPreguntas;

    cout << "\nIngrese la cantidad minima de puntos para el examen: ";
    cin >> cantidadPuntos;

    cin.ignore(); // Limpiar el buffer de entrada

    hacerPreguntas();
    imprimir();
}

void Controller::hacerPreguntas() {
    int cantidadPreguntasPorTipo = cantidadPuntos / 6;
    int preguntasFaltantes = cantidadPreguntas - (cantidadPreguntasPorTipo * 4);
    int puntosComplete = cantidadPreguntasPorTipo;
    if (preguntasFaltantes > 0) {
        puntosComplete = puntosComplete + preguntasFaltantes; // Agregar una pregunta extra a puntosUnica si hay preguntas restantes
    }
    // Crear las preguntas y calcular los puntos totales
    cout << "\nI parte.\nEscriba la letra de la respuesta correcta en mayuscula" << endl;
    Pregunta* pregunta = new sUnica(cantidadPreguntasPorTipo);
    totalPuntos += pregunta->puntos;
    delete pregunta;

    cout << "\nII parte.\nEscriba la letra de la respuesta correcta en mayuscula. Si son varias letras, escribalas separadas por una coma" << endl;
    pregunta = new sMultiple(cantidadPreguntasPorTipo);
    totalPuntos += pregunta->puntos;
    delete pregunta;

    cout << "\nIII parte.\nEscriba Verdadero o Falso según corresponda" << endl;
    pregunta = new sVerdaderoFalso(cantidadPreguntasPorTipo);
    totalPuntos += pregunta->puntos;
    delete pregunta;

    cout << "\nIV parte.\nEscriba la respuesta correcta, recuerde usar mayusculas" << endl;
    pregunta = new sComplete(puntosComplete);
    totalPuntos += pregunta->puntos;
    delete pregunta;

    cout << "\n+++Puntos extra sobre el puntaje final(5)+++" << endl;
    cout << "\nV parte.\nJustifique ampliamente su respuesta" << endl;
    pregunta = new sDesarrollo(1);
    delete pregunta;

    cantidadPuntos = cantidadPreguntasPorTipo * 5 + puntosComplete;
}


void Controller::imprimir()
{
    float nota = static_cast<float>(totalPuntos) / cantidadPuntos * 100;

    // Mostrar los resultados
    cout << endl;
    cout << "Estimado/a " << nombre << "," << endl;
    cout << "Has obtenido " << totalPuntos << " puntos en el examen de "
        << cantidadPuntos << " posibles" << endl;
    cout << "Tu nota equivalente es: " << nota << endl;

    cout << "\nPresiona una letra o número cualquiera para salir> ";
    string ignorar;
    cin >> ignorar;
}


Controller::~Controller()
{
}
