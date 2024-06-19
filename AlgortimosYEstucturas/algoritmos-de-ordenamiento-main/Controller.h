#ifndef Controller_h
#define Cotroller_h
#include "Ordenador.h"
//Libreries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

class Controller {
private:
    int* A = new int[50000];
    int* B = new int[100000];
    int* C = new int[200000];
    Ordenador* Algoritmos = new Ordenador;
public:
    Controller();
    ~Controller();
    void ShuffleArrays(int*, int);
    void testSelecction();
    void testInsertion();
    void testMergeSort();
    void testHeapSort();
    void testRadixSort();
    void testQuickSort();
    void printArray(int* A, int n) {
        for (int i = 0; i < n; ++i) {
            cout <<A[i]<<", ";
        }
        cout <<endl;
    }
    void Menu();
};
#endif