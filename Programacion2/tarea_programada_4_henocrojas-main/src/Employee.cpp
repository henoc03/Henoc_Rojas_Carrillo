#include "Employee.h"

Employee::Employee(string name_n) {
        this->name = name_n;

}

Employee::~Employee() {

}

bool Employee::operator==(const Employee& otro) {

        if (this->name == otro.name) {
                return true;
        } else {
                return false;
        }
}

string Employee::getName(){
        return this->name;
}

std::ostream& operator<<(std::ostream& salida, const Employee* obj)
{
    salida << obj->name << endl;
    return salida;
}