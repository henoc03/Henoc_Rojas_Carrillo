#include "Users.h"

Users::Users(string name_n, string ID_n, string password_n) {
        this->name = name_n;
        this->username = ID_n;
        this->password = password_n;
}

Users::~Users() {

}

bool Users::operator==(const Users& otro) {

        if (this->username == otro.username) {
                return true;
        } else {
                return false;
        }
}

string Users::getName(){
        return this->name;
}

string Users :: getUsername() {
        return this->username;
}

string Users::getPassword(){
        return this->password;
}
std::ostream& operator<<(std::ostream& salida, const Users* obj)
{
    salida <<"Name: "<< obj->name << endl <<"Username:"<< obj->username << endl;
    return salida;
}