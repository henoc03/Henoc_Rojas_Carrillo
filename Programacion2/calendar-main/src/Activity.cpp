#include "Activity.h"

Activity::Activity(string* newName, string* newDate, string* newStart, string* newEnd, string* placeN, string* guestsN):Event(newName, newDate, newStart, newEnd){

    this->guests = guestsN;
    this->place = placeN; 
    this->next = nullptr;

}

Activity::~Activity(){

    delete this->name;
    delete this->startTime;
    delete this->endTime;
    delete this->guests;
    delete this->date;
    delete this->place;

}

void Activity::print(){

    cout << "                           [Actividad]"<<endl;
    cout << "                   <<<< " << *name << " >>>>" << endl;
    cout << "                   >> " << *place << endl;
    cout << "                   >> " << *startTime << " - " << *endTime << endl;
    cout << "                   >> " << *date << endl;

} 

void Activity::setNext(Activity* newCubicle){

    this->next = newCubicle;

}
        

Activity* Activity::getNext(){

    return this->next;

}

string Activity::getPlace(){

    return *(this->place);

}

string* Activity::getGuests(){

    return this->guests;

}