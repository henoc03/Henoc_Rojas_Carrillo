#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "Event.h"

class Activity : public Event{
    private:
        string* guests;
        string* place;
        Activity* next;
        
    public:
        Activity(string*, string*, string*, string*, string*, string*);
        ~Activity();
        void print() override;
        void setNext(Activity*);
        Activity* getNext();
        string getPlace();
        string* getGuests();

};

#endif 