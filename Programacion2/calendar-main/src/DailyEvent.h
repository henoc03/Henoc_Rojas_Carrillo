#ifndef DAILYEVENT_H
#define DAILYEVENT_H

#include "Event.h"

class DailyEvent : public Event{
    private:
        DailyEvent* next;

    public:
        DailyEvent(string*, string*);
        ~DailyEvent();
        void print() override;
        void setNext(DailyEvent*);
        DailyEvent* getNext();

};

#endif 
