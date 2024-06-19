#include "Stations.h"

Stations::Stations(string name_n) {
        this->name = name_n;

}

Stations::~Stations() {

}

bool Stations::operator==(const Stations& otro) {

        if (this->name == otro.name) {
                return true;
        } else {
                return false;
        }
}

string Stations::getName(){
        return this->name;
}

std::ostream& operator<<(std::ostream& salida, const Stations* obj)
{
    salida << obj->name << endl;
    return salida;
}