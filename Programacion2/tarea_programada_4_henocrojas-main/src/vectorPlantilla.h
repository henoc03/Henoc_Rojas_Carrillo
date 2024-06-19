#ifndef VectorPlantilla_H
#define VectorPlantilla_H

template<class T>
class VectorPlantilla {
private:
    
    class Node {
        public:
            Node* next;
            Node* prev;
            T* object;
            Node(T*);
            ~Node();
    };

    int lenght;
    Node* head;
    Node* tail;
public:
    VectorPlantilla();
    ~VectorPlantilla();
    void pushBack(T*);
    void pop(int);
    T* operator[] (int);
    void operator+= (T*);
    void operator-= (int);
};


#endif