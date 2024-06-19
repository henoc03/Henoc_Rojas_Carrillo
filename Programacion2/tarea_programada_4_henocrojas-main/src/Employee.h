#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

class Employee
{
private:
    string name;

public:
    string getName();

    Employee(string);
    ~Employee();
    bool operator==(const Employee& otro);
    friend std::ostream& operator<<(std::ostream& os, const Employee* obj);
};

#endif 