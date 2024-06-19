#ifndef MEETING_H
#define MEETING_H

#include "Event.h"

class Meeting : public Event{
    private:
        string* guests;
        string* place;
        string* organizer;
        Meeting* next;
    
    public:
        Meeting(string*, string*, string*, string*, string*, string*, string*);
        ~Meeting();
        void print() override;
        string getOrganizer();
        void setNext(Meeting*);
        Meeting* getNext();
        string getPlace();
        string* getGuests();

};

#endif 