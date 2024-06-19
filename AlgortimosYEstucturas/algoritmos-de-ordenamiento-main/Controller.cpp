#include "Controller.h"
Controller::Controller() {

}

void Controller::ShuffleArrays(int* Array, int n){
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < n; ++i) {
                       //% (2 * RAND_MAX + 1) - RAND_MAX
        Array[i] = rand();
    }
}

void Controller::Menu() {
    system("cls");
    cout<< "                    Menu                  "<<endl
        << "   Seleccione el algortimo que desee medir"<<endl
        << "               1. Selection Sort          "<<endl
        << "               2. Insertion Sort          "<<endl
        << "               3. Merge Sort              "<<endl
        << "               4. Radix Sort              "<<endl
        << "               5. Quick Sort              "<<endl
        << "               6. Heap Sort               "<<endl
        << "               7. Close program           "<<endl
        << "               >> ";
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
        system("cls");
        this->testSelecction();
        Menu();
        break;
    case 2:
        system("cls");
        this->testInsertion();
        Menu();
        break;
    case 3:
        system("cls");
        this->testMergeSort();
        Menu();
    case 4:
        system("cls");
        this->testRadixSort();
        Menu();
    case 5:
        this->testQuickSort();
        Menu();
    case 6:
        this->testHeapSort();
        Menu();
    case 7:
        break;
    default:
        Menu();
        break;
    }
}

void Controller::testSelecction() {
    cout<<"              SELECTION SORT             "<<endl;
    cout<<"  Seleccione el tamanio del array a medir"<<endl
        <<"          1. 50000 " <<endl
        <<"          2. 100000 " <<endl
        <<"          3. 200000 " <<endl
        <<"          4. Salir "<<endl
        <<"          >> ";
    int option;
    cin >>option;
    switch (option)
    {
    case 1:{
        ShuffleArrays(A, 50000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->seleccion(A, 50000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 50000; ++j) {
            if (A[j] < A[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<"Desordenado"<<endl;
        }

        this->testSelecction();
    }
        
        break;
    case 2: {
        ShuffleArrays(B, 100000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->seleccion(B, 100000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 100000; ++j) {
            if (B[j] < B[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<"Desordenado"<<endl;
        }


        this->testSelecction();
    }
        break;
    case 3: {
        ShuffleArrays(C, 200000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->seleccion(C, 200000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 200000; ++j) {
            if (C[j] < C[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<" Desordenado"<<endl;
        }

        this->testSelecction();
    }
        
        break;

    case 4:
        break;

    default:
        this->testSelecction();
        break;
    }
}

void Controller::testInsertion() {
    cout<<"               INSERTION SORT                 "<<endl;
    cout<<"  Seleccione el tamanio del array a medir: "<<endl
        <<"          1. 50000 " <<endl
        <<"          2. 100000 " <<endl
        <<"          3. 200000 " <<endl
        <<"          4. Salir "<<endl
        <<"          >> ";
    int option;
    cin >>option;
    switch (option)
    {
    case 1:{
        ShuffleArrays(A, 50000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->insercion(A, 50000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 50000; ++j) {
            if (A[j] < A[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<"Desordenado"<<endl;
        }

        this->testInsertion();
    }
        
        break;
    case 2: {
        ShuffleArrays(B, 100000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->insercion(B, 100000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 100000; ++j) {
            if (B[j] < B[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<"Desordenado"<<endl;
        }


        this->testInsertion();
    }
        break;
    case 3: {
        ShuffleArrays(C, 200000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->insercion(C, 200000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 200000; ++j) {
            if (C[j] < C[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<" Desordenado"<<endl;
        }

        this->testInsertion();
    }
        
        break;

    case 4:
        break;
    default:
        this->testInsertion();
        break;
    }
}

void Controller::testMergeSort() {
    cout<<"                MERGE SORT                 "<<endl;
    cout<<"  Seleccione el tamanio del array a medir: "<<endl
        <<"          1. 50000 " <<endl
        <<"          2. 100000 " <<endl
        <<"          3. 200000 " <<endl
        <<"          4. Salir "<<endl
        <<"          >> ";
    int option;
    cin >>option;

    switch (option) {
    case 1:{

        ShuffleArrays(A, 50000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->mergesort(A, 50000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 50000; ++j) {
            if (A[j] < A[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<"Desordenado"<<endl;
        }

        this->testMergeSort();
    }
        
        break;
    case 2: {
        ShuffleArrays(B, 100000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->mergesort(B, 100000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 100000; ++j) {
            if (B[j] < B[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<"Desordenado"<<endl;
        }


        this->testMergeSort();
    }
        break;
    case 3: {
        ShuffleArrays(C, 200000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->mergesort(C, 200000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 200000; ++j) {
            if (C[j] < C[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<" Desordenado"<<endl;
        }

        this->testMergeSort();
    }
        
        break;

    case 4:
        break;
    default:
        this->testMergeSort();
        break;
    }
}

void Controller::testRadixSort() {
    cout<<"              RADIX SORT             "<<endl;
    cout<<"  Seleccione el tamanio del array a medir"<<endl
        <<"          1. 50000 " <<endl
        <<"          2. 100000 " <<endl
        <<"          3. 200000 " <<endl
        <<"          4. Salir "<<endl
        <<"          >> ";
    int option;
    cin >>option;
    switch (option)
    {
    case 1:{
        ShuffleArrays(A, 50000);


        //this->printArray(A, 50000);
        
        
        auto start = chrono::high_resolution_clock::now();
        Algoritmos->radixsort(A, 50000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 50000; ++j) {
            if (A[j] < A[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<"Desordenado"<<endl;
        }
        

        //this->printArray(A, 50000);
        //cin.ignore();


        this->testRadixSort();
    }
        
        break;
    case 2: {
        ShuffleArrays(B, 100000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->radixsort(B, 100000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 100000; ++j) {
            if (B[j] < B[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<"Desordenado"<<endl;
        }


        this->testRadixSort();
    }
        break;
    case 3: {
        ShuffleArrays(C, 200000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->radixsort(C, 200000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 200000; ++j) {
            if (C[j] < C[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<" Desordenado"<<endl;
        }

        this->testRadixSort();
    }
        
        break;

    case 4:
        break;

    default:
        this->testRadixSort();
        break;
    }
}

void Controller::testQuickSort() {
    cout<<"              QUICK SORT             "<<endl;
    cout<<"  Seleccione el tamanio del array a medir"<<endl
        <<"          1. 50000 " <<endl
        <<"          2. 100000 " <<endl
        <<"          3. 200000 " <<endl
        <<"          4. Salir "<<endl
        <<"          >> ";
    int option;
    cin >>option;
    switch (option)
    {
    case 1:{
        ShuffleArrays(A, 50000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->quicksort(A, 50000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 50000; ++j) {
            if (A[j] < A[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<"Desordenado"<<endl;
        }

        this->testQuickSort();
    }
        
        break;
    case 2: {
        ShuffleArrays(B, 100000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->quicksort(B, 100000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 100000; ++j) {
            if (B[j] < B[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<"Desordenado"<<endl;
        }


        this->testQuickSort();
    }
        break;
    case 3: {
        ShuffleArrays(C, 200000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->quicksort(C, 200000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 200000; ++j) {
            if (C[j] < C[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<" Desordenado"<<endl;
        }

        this->testQuickSort();
    }
        
        break;

    case 4:
        break;

    default:
        this->testQuickSort();
        break;
    }
}

void Controller::testHeapSort() {
    cout<<"              HEAP SORT             "<<endl;
    cout<<"  Seleccione el tamanio del array a medir"<<endl
        <<"          1. 50000 " <<endl
        <<"          2. 100000 " <<endl
        <<"          3. 200000 " <<endl
        <<"          4. Salir "<<endl
        <<"          >> ";
    int option;
    cin >>option;
    switch (option)
    {
    case 1:{
        ShuffleArrays(A, 50000);
    
        auto start = chrono::high_resolution_clock::now();
        Algoritmos->heapsort(A, 50000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 50000; ++j) {
            if (A[j] < A[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<"Desordenado"<<endl;
        }
       
        this->testHeapSort();
    }
        
        break;
    case 2: {
        ShuffleArrays(B, 100000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->heapsort(B, 100000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 100000; ++j) {
            if (B[j] < B[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<"Desordenado"<<endl;
        }


        this->testHeapSort();
    }
        break;
    case 3: {
        ShuffleArrays(C, 200000);

        auto start = chrono::high_resolution_clock::now();
        Algoritmos->heapsort(C, 200000);
        auto final = chrono::high_resolution_clock::now();
        auto total = chrono::duration_cast<chrono::milliseconds>(final-start);

        bool confirmacion = true;
        for (int j = 1; j < 200000; ++j) {
            if (C[j] < C[j-1]){
                confirmacion = false;
            }
        }
        if (confirmacion){
            cout<<"============================================================="<<endl
                <<" Ordenado"<<endl
                <<" Tiempo de ordenamiento: "<<total.count() <<" ms"<<endl
                <<"============================================================="<<endl;
        }else {
            cout <<" Desordenado"<<endl;
        }

        this->testHeapSort();
    }
        
        break;

    case 4:
        break;

    default:
        this->testHeapSort();
        break;
    }
}

Controller::~Controller(){
    delete[] A;
    delete[] B;
    delete[] C;
}
