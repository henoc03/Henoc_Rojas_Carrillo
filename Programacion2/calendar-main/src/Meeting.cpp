 #include "Meeting.h"

Meeting::Meeting(string* newName, string* newDate, string* newStart, string* newEnd, string* place, string* guests, string* organizer):Event(newName, newDate, newStart, newEnd){

    this->guests = guests;
    this->place = place;
    this->organizer = organizer;
    this->next = nullptr;

}

Meeting::~Meeting(){

    delete this->name;
    delete this->startTime;
    delete this->endTime;
    delete this->guests;
    delete this->date;
    delete this->place;
    delete this->organizer;

}

string Meeting::getOrganizer(){

    return *(this->organizer);

}

string Meeting::getPlace(){

    return *(this->place);

}

string* Meeting::getGuests(){

    return this->guests;

}

void Meeting::print(){
    cout << "                      [Reunion]"<<endl;
    cout << "                <<<< " << *name << " >>>>" << endl;
    cout << "            >> " << *place << endl;
    cout << "            >> " << *startTime << endl;
    cout << "            >> " << *endTime << endl;
    cout << "            >> Organizador: " << *organizer << endl;
    cout << "            >>Fecha: "<< *date <<endl;
} 

void Meeting::setNext(Meeting* newCubicle){

    this->next = newCubicle;

}
        

Meeting* Meeting::getNext(){

    return this->next;

}