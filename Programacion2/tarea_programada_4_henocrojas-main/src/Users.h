#ifndef USERS_H
#define USERS_H

#include <string>
#include <iostream>
using namespace std;

class Users
{
private:
    string name;
    string username;
    string password;
public:
    string getName();
    string getUsername();
    string getPassword();

    Users(string, string, string);
    ~Users();
    bool operator==(const Users& otro);
    friend std::ostream& operator<<(std::ostream& os, const Users* obj);
};

#endif 