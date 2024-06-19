#ifndef STATIONS_H
#define STATIONS_H

#include <string>
#include <iostream>
using namespace std;

class Stations
{
private:
    string name;

public:
    string getName();

    Stations(string);
    ~Stations();
    bool operator==(const Stations& otro);
    friend std::ostream& operator<<(std::ostream& os, const Stations* obj);
};

#endif 