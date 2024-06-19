#include "Event.h"

Event::Event(string* newName, string* newDate, string* newStart, string* newEnd)
{
    this->name = newName;
    this->date = newDate;
    this->startTime = newStart;
    this->endTime = newEnd;

}

Event::~Event()
{
    delete this->name;
    delete this->date;
    delete this->startTime;
    delete this->endTime;

}

string Event::getName(){

    return *name;

}

string Event::getDate(){

    return *date;

}

string Event::getStart(){

    return *startTime;

}

string Event::getEnd(){

    return *endTime;

}

void Event::printMainData()
{
    cout << "                [ " << *(this->name) << " ]" << endl;
    cout << "            >> Hora de inicio: " << *(this->startTime) << endl;
    cout << "            >> Hora de final: " << *(this->endTime) << endl;
    cout << "            >> Fecha: " << *(this->date) << endl<<endl;
} 

void Event::editEvent(string name_n, string date_n, string start_n, string end_n)
{
    this->name = new string(name_n);
    this->date = new string(date_n);
    this->startTime = new string(start_n);
    this->endTime = new string(end_n);
}