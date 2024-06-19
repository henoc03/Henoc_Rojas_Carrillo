#ifndef CONTRIBUTOR_H
#define CONTRIBUTOR_H
#include "Employee.h"

class Contributor:public Employee{

    private:
        Contributor* nextContributor;

    public:
        Contributor(string, string, string);
        ~Contributor();
        void viewOtherCalendar(Employee*);
        Contributor* getNextContributor();
        void setNextContributor(Contributor*);

    protected:


};

#endif