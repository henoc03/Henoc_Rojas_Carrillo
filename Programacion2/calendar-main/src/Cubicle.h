#ifndef CUBICLE_H
#define CUBICLE_H

#include "Event.h"

class Cubicle : public Event{
    private:
        int* cubicleNumber;
        Cubicle* next;

    public:
        Cubicle(string*, string*, string*, string*, int*);
        ~Cubicle();
        void print() override;
        void setNextCubicle(Cubicle*);
        Cubicle* getNext();
        int getNumber();

};

#endif 
