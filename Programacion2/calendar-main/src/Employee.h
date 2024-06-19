#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Meeting.h"
#include "Appointment.h"
#include "Cubicle.h"
#include "Activity.h"
#include "DailyEvent.h"
#include <string>
using namespace std;

class Employee{

    private:

    protected:
        class Reservation{
            private:
                Event* event;
                Reservation* next;
            
            public:
                Reservation(Event*);
                ~Reservation();
                Event* getEvent();
                Reservation* getNext();
                void setNext(Event*);
                void setEvent(Event* event_n);

        };
        string name;
        string id;
        string job;
        Reservation* invitations;
        Reservation* events;

    public:
        Employee(string, string, string);
        ~Employee();
        void viewCalendar();
        void viewEvents();
        void viewDisponibility();
        void viewInvitations();
        void createEvent(Event*);
        void cancelEvent();
        virtual void viewOtherCalendar(Employee*) = 0;
        string getName();
        string getId();
        string getJob();
        void addInvitation(Event*);
        Event* modifyEventReturn(string);
        bool compareEventsTimes(string, string, string);
        int* divideData(string, char);
        void sortEvents();
        bool isEventRecent(Event*, Event*);
};

#endif 
