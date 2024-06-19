#include "Cubicle.h"

Cubicle::Cubicle(string* newName, string* newDate, string* newStart, string* newEnd, int* cubicleNumber_n):Event(newName, newDate, newStart, newEnd){

    this->cubicleNumber = cubicleNumber_n;
    this->next = nullptr;

}

Cubicle::~Cubicle(){

    delete this->name;
    delete this->startTime;
    delete this->endTime;
    delete this->date;
    delete this->cubicleNumber;

}

void Cubicle::print() {

    cout << "                      [Cubiculo]"<<endl;
    cout << "                <<<< " << *name << " >>>>" << endl;
    cout << "            >> Cubiculo: " << *cubicleNumber << endl;
    cout << "            >> " << *startTime << endl;
    cout << "            >> " << *endTime << endl;
    cout << "            >>Fecha: "<< *date <<endl;

} 

void Cubicle::setNextCubicle(Cubicle* newCubicle){

    this->next = newCubicle;

}
        

Cubicle* Cubicle::getNext(){

    return this->next;

}

int Cubicle::getNumber(){

    return *(this->cubicleNumber);

}