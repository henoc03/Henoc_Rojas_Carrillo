#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "Event.h"

class Appointment : public Event{
    private:
        Appointment* next;
        
    public:
        Appointment(string*, string*, string*, string*);
        ~Appointment();
        void print() override;
        void setNext(Appointment*);
        Appointment* getNext();

};

#endif
