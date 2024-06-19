#include "Appointment.h"

Appointment::Appointment(string* newName, string* newDate, string* newStart, string* newEnd):Event(newName, newDate, newStart, newEnd){

    this->next = nullptr;

}

Appointment::~Appointment(){

    delete this->name;
    delete this->startTime;
    delete this->endTime;
    delete this->date;

} 

void Appointment::print()
{
    cout << "                      [Cita]"<<endl;
    cout << "                <<<< " << *name << " >>>>" << endl;
    cout << "            >> " << *startTime << endl;
    cout << "            >> " << *endTime << endl;
    cout << "            >> Fecha: "<< *date <<endl;
}

void Appointment::setNext(Appointment* newCubicle){

    this->next = newCubicle;

}
        

Appointment* Appointment::getNext(){

    return this->next;

}