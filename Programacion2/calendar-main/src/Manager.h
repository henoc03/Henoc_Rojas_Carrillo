#ifndef MANAGER_H
#define MANAGER_H
#include "Contributor.h"

class Manager : public Employee{

    private:
        Contributor* subordinates;
        Manager* nextManager;
    
    public:
        Manager(string, string, string);
        ~Manager();
        void viewOtherCalendar(Employee*);
        Contributor* searchSubordinate(string);
        void addSubordinate(Contributor*);
        Manager* getNextManager();
        void setNextManager(Manager*);
        void viewSubordinates();

    protected:


};

#endif 