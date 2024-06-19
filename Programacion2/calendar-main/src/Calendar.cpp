#include "Calendar.h"

Cubicle* Calendar::getCubicleHead(){

    return this->cubicles;

}

Meeting* Calendar::getMeetingsHead(){

    return this->meetings;

}

DailyEvent* Calendar::getDailyEventHead(){

    return this->dailyEvents;

}

Appointment* Calendar::getAppointmentHead(){

    return this->appointments;

}

Activity* Calendar::getActivitiesHead(){

    return this->activities;

}

Calendar::Calendar(){

    this->appointments = nullptr;
    this->cubicles = nullptr;
    this->dailyEvents = nullptr;
    this->meetings = nullptr;
    this->activities = nullptr;

}

void Calendar::addCubicle(Cubicle* newEvent){

    if(this->cubicles){
        Cubicle* actual = this->cubicles;
        while(actual->getNext()){
            actual = actual->getNext();
        }
        actual->setNextCubicle(newEvent);
    }
    else{
        this->cubicles = newEvent;
    }

}

void Calendar::addMeeting(Meeting* newEvent){

    if(this->meetings){
        Meeting* actual = this->meetings;
        while(actual->getNext()){
            actual = actual->getNext();
        }
        actual->setNext(newEvent);
    }
    else{
        this->meetings = newEvent;
    }

}

void Calendar::addAppointment(Appointment* newEvent){

    if(this->appointments){
        Appointment* actual = this->appointments;
        while(actual->getNext()){
            actual = actual->getNext();
        }
        actual->setNext(newEvent);
    }
    else{
        this->appointments = newEvent;
    }

}

void Calendar::addActivity(Activity* newEvent){

    if(this->activities){
        Activity* actual = this->activities;
        while(actual->getNext()){
            actual = actual->getNext();
        }
        actual->setNext(newEvent);
    }
    else{
        this->activities = newEvent;
    }

}

void Calendar::addDailyEvent(DailyEvent* newEvent){

    if(this->dailyEvents){
        DailyEvent* actual = this->dailyEvents;
        while(actual->getNext()){
            actual = actual->getNext();
        }
        actual->setNext(newEvent);
    }
    else{
        this->dailyEvents = newEvent;
    }

}