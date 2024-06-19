#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>

using namespace std;    

class Event{
    private:

    protected:
        string* name;
        string* date;
        string* startTime;
        string* endTime;

    public:
        Event(string*, string*, string*, string*);
        ~Event();
        string getName();
        string getDate();
        string getStart();
        string getEnd();
        void printMainData();
        virtual void print() = 0;
        void editEvent(string, string, string, string);
        
};

#endif 
