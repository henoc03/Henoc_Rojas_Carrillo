#include "VectorPlantilla.h"
#include "Users.h"
#include "Employee.h"
#include "Stations.h"
//========================================================
//               CONSTRUCTORES Y DESTRUCTORES
template<class T>
VectorPlantilla<T>::VectorPlantilla() {
    this->head = nullptr;
    this->tail = nullptr;
    this->lenght = 0;
}

template<class T>
VectorPlantilla<T>::~VectorPlantilla() {
    Node* aux = this->head;
    while (aux)
    {
        this->head = this->head->next;
        delete aux;
        aux = head;
    }
    
}

template<class T>
VectorPlantilla<T>::Node::Node(T* object_n) {
    this->object = object_n;
    this->next = nullptr;
    this->prev = nullptr;
}

template<class T>
VectorPlantilla<T>::Node::~Node() {
    delete this->object;
    this->next = nullptr;
    this->prev = nullptr;
}
//=====================================================
//                      METODOS

template<class T>
void VectorPlantilla<T>::pushBack(T* newEle) {
    if (this->head == nullptr) {
        this->head = new Node(newEle);
        ++this->lenght;
    } else {
        if (this->tail == nullptr) {
            this->tail = new Node(newEle);
            this->tail->prev = this->head;
            this->head->next = this->tail;
            ++this->lenght;
        } else {
            this->tail->next = new Node(newEle);
            this->tail->next->prev = this->tail;
            this->tail = this->tail->next;
            ++this->lenght;
        }
    }
}

template<class T>
void VectorPlantilla<T>::pop(int indexDele) {
    if(indexDele < this->lenght && indexDele >= 0) {
        Node* aux = this->head;
            
        for (int i = 0; i < indexDele; i++) {
            aux = aux->next;
        }

        if (aux == this->head) {
            this->head = this->head->next;
            delete aux;
            --this->lenght;
        } else {
            if (aux == this->tail)  {
                this->tail = this->tail->prev;
                if (this->tail == this->head){
                    this->tail = nullptr;
                    this->head->next = nullptr;
                } else {
                    this->tail->next = nullptr;
                }
                
                delete aux;
                --this->lenght;
            } else {
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                delete aux;
                --this->lenght;
            }
        }
    }
}

template<class T>
T* VectorPlantilla<T>::operator [] (int index) {
    if(index < this->lenght && index >= 0) {
        Node* aux = this->head;
            
        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }

        return aux->object;
    } else {
        return nullptr;
    }

}

template <class T>
void VectorPlantilla<T>::operator+= (T* otro) {
    this->pushBack(otro);
}

template <class T>
void VectorPlantilla<T>::operator-= (int otro) {
    this->pop(otro);
}


template class VectorPlantilla<Employee>;
template class VectorPlantilla<Users>;
template class VectorPlantilla<Stations>;
