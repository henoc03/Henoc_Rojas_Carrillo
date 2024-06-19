#ifndef MATRIZ_H
#define MATRIZ_H

template<class T>
class MatrizPlantilla
{
private:
    int rowsAndCols;
    class Node
    {
        public:
            Node* nextCol;
            Node* nextRow;
            Node* prev;
            T* object;
            int relation;
            Node(T*);
            ~Node();
            

    };

    Node* head;
    Node*tail;
public:
    MatrizPlantilla();
    ~MatrizPlantilla();
    /*Crea una nueva colunma T del nuevo objeto, le copia las filas  y luego a cada columna le agrega
    una fila nueva del objeto creado
    */
    void pushBack(T*);
    /*saca una columna y luego le quita la ultima fila a cada 
    uno de los restantes para volver a dejarla cuadrada*/
    void popBack();
    /*Recibe el primer T que va a ser el elemento al que se le da la relacion
    y el segundo elemento que sera con el que se relacione
    es decir, accede a la columna T1 y busca al nodo con T2 para establecer una relacion,
    recordando siempre que esta relacion es un entero, o sea, le suma uno al entero.
    En el caso de los likes se pueden acupmular, en el caso de 
    */    
    void relationBetween(T*, T*);
    void setRelation(T*, T*, int);   
    int viewRelation(T*, T*);
    void popAll(T*);
    void operator+= (T*);
    void operator-= (T*);
};

#endif 
