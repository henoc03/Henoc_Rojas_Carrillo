#include "MatrizPlantilla.h"
#include "Users.h"
#include "Employee.h"
#include "Stations.h"

template<class T>
void MatrizPlantilla<T>::setRelation(T* colObject, T* rowObject, int ent ) {

    Node* auxCols = this->head;
    while (auxCols)
    {
        if (*auxCols->object == *colObject) {
            Node* auxRows = auxCols;
            while (auxRows)
            {
                if(*auxRows->object == *rowObject) 
                {
                    auxRows->relation = ent;
                    break;
                } else {
                    auxRows = auxRows->nextRow;
                }
            }
            break;
        } else {
            auxCols = auxCols->nextCol;
        }
    }
}



template<class T>
MatrizPlantilla<T>::MatrizPlantilla()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->rowsAndCols = 0;
}

template<class T>
MatrizPlantilla<T>::~MatrizPlantilla()
{
    Node* aux;
    while(this->head)
    {
        aux = this->head->nextCol;
        delete this->head;
        this->head = aux;
    }
}
//==========================================================
template<class T>
MatrizPlantilla<T>::Node::Node(T* newObject_n)
{
    this->object = newObject_n;
    this->nextCol = nullptr;
    this->nextRow = nullptr;
    this->prev = nullptr;
    this->relation = 0;
}

template<class T>
MatrizPlantilla<T>::Node::~Node()
{
    delete this->object;
}

//==========================================================

//                METODOS
template<class T>
void MatrizPlantilla<T>::pushBack(T* newObject_n)
{
    ++this->rowsAndCols;

    //AGREGAR COLUMNAS
    if (this->head == nullptr)
    {
        this->head = new Node(newObject_n);
        //this->tail = this->head;
        this->head->nextCol = this->tail;
    } else {
        if(this->tail == nullptr) {
            this->tail = new Node(newObject_n);
            this->head->nextCol = this->tail;
            this->tail->prev = this->head;
        } else {
            this->tail->nextCol = new Node(newObject_n);
            Node* aux = this->tail->nextCol;
            aux->prev = this->tail;
            this->tail = aux;
        }
        
    }

    //Agregar fila a las columnas antiguas.
    Node* auxCols = this->head;
    while (auxCols != this->tail || auxCols == this->head)
    {
        Node* auxRows = auxCols;
        while(true)
        {
            if (auxRows->nextRow == nullptr)
            {
                auxRows->nextRow = new Node(newObject_n);
                auxRows->nextRow->prev = auxRows;
                break;
            } else{
                auxRows = auxRows->nextRow;
            }
        }
        auxCols = auxCols->nextCol;
    }


    //Copiar los elementos a tail
    if(this->head != this->tail && this->tail != nullptr) {
        Node* auxRowsPrev = this->tail->prev;
        Node* auxRowsTail = this->tail;
        while (auxRowsPrev->nextRow)
        {
            auxRowsTail->nextRow = new Node(auxRowsPrev->nextRow->object);

            // Node* aux = auxRowsTail->nextRow;
            // aux->prev = auxRowsTail;
            auxRowsTail->nextRow->prev = auxRowsTail;
            auxRowsPrev = auxRowsPrev->nextRow;
            auxRowsTail = auxRowsTail->nextRow;

        }
    }
    
    
}


template<class T>
void MatrizPlantilla<T>::popBack() {
    --this->rowsAndCols;
    //Elimina la ultima columna de los elementos
    this->tail = this->tail->prev;
    this->tail->nextCol = nullptr;
    

    //Resta un elemento a las filas de cada columna.
    Node* auxCols = this->head;
    while (auxCols)
    {
        Node* auxRows = auxCols;
        while(auxRows)
        {
            //auxRows = auxRows->nextRow;
            if (auxRows->nextRow == nullptr)
            {
                //Node* auxToDelete = auxRows;
                Node* auxPrev = auxRows->prev;
                auxPrev->nextRow = nullptr;
                //delete auxToDelete;
                break;
            } else{
                auxRows = auxRows->nextRow;
            }
        }
        auxCols = auxCols->nextCol;
    }

}

template<class T>
void MatrizPlantilla<T>::relationBetween(T* colObject, T* rowObject) {

    Node* auxCols = this->head;
    while (auxCols)
    {
        if (*auxCols->object == *colObject) {
            Node* auxRows = auxCols;
            while (auxRows)
            {
                if(*auxRows->object == *rowObject) 
                {
                    ++auxRows->relation;
                    break;
                } else {
                    auxRows = auxRows->nextRow;
                }
            }
            break;
        } else {
            auxCols = auxCols->nextCol;
        }
    }
    
}

template<class T>
int MatrizPlantilla<T>::viewRelation(T* colObject, T* rowObject) {
    Node* auxCols = this->head;
    while (auxCols)
    {
        if (*auxCols->object == *colObject) {
            Node* auxRows = auxCols;
            while (auxRows)
            {
                if(*auxRows->object == *rowObject) 
                {
                    return auxRows->relation;
                    break;
                } else {
                    auxRows = auxRows->nextRow;
                }
            }
            break;
        } else {
            auxCols = auxCols->nextCol;
        }
    }
    return 0;
}

template<class T>
void MatrizPlantilla<T>::popAll(T* eleToDelete) {
    //===============================================================
    //Elimina la columna donde es igual al argumento enviado
    Node* auxCols = this->head;
    while(auxCols) {
        if (auxCols->object == eleToDelete) {
            if(auxCols == this->head) {
                if (this->head->nextCol == this->tail) {
                    this->head = auxCols->nextCol;
                    delete auxCols;
                    this->tail = nullptr;
                    --this->rowsAndCols;
                    break;
                } else {
                    if (this->head->nextCol){
                        this->head = auxCols->nextCol;
                        delete auxCols;
                        --this->rowsAndCols;
                        break;
                    } else {
                        delete this->head;
                        this->head = nullptr;
                        --this->rowsAndCols;
                        break;
                    }
                }
                
            } else {
                if(auxCols == this->tail) {
                    if (this->tail->prev == this->head) {
                        this->head->nextCol = nullptr;
                        this->tail = nullptr;
                        delete auxCols;
                        --this->rowsAndCols;
                        break;
                    } else {
                        this->tail = auxCols->prev;
                        this->tail->nextCol = nullptr;
                        delete auxCols;
                        --this->rowsAndCols;
                        break;
                    }
                    
                } else {
                    auxCols->prev->nextCol = auxCols->nextCol;
                    auxCols->nextCol->prev = auxCols->prev;
                    delete auxCols;
                    --this->rowsAndCols;
                    break;
                }
            }
        } else {
            auxCols = auxCols->nextCol;
        }
    }
    //================================================================
    // Elimina cada ojeto igual de las filas de cada columna
    auxCols = this->head;
    while(auxCols) {
        Node* auxRows = auxCols->nextRow;
        while (auxRows) {
            if (auxRows->object == eleToDelete) {
                if (auxRows->nextRow == nullptr) {
                    Node* auxToDelete = auxRows;
                    Node* auxPrev = auxRows->prev;
                    auxPrev->nextRow = nullptr;
                    delete auxToDelete;
                    break;

                } else {
                    auxRows->prev->nextRow = auxRows->nextRow;
                    auxRows->nextRow->prev = auxRows->prev;
                    break;
                }
                
            } else {
                auxRows = auxRows->nextRow;
            }
        }
        auxCols = auxCols->nextCol;
    }
    
}

template <class T>
void MatrizPlantilla<T>::operator+= (T* otro) {
    this->pushBack(otro);
}
template <class T>
void MatrizPlantilla<T>::operator-= (T* otro) {
    this->popAll(otro);
}

template class MatrizPlantilla<Users>;
template class MatrizPlantilla<Employee>;
template class MatrizPlantilla<Stations>;
