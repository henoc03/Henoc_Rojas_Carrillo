#include "DailyEvent.h"

DailyEvent::DailyEvent(string* newName, string* newDate):Event(newName, newDate, new string("00:00"), new string("23:59")){

    this->next = nullptr;

}

DailyEvent::~DailyEvent(){

    delete this->name;
    delete this->startTime;
    delete this->endTime;
    delete this->date;

}

void DailyEvent::print(){
    cout << "                      [Evento diario]"<<endl;
    cout << "                <<<< " << *name << " >>>>" << endl;
    cout << "            >> Fecha: "<< *date <<endl;
    

} 

void DailyEvent::setNext(DailyEvent* newCubicle){

    this->next = newCubicle;

}
        

DailyEvent* DailyEvent::getNext(){

    return this->next;

}