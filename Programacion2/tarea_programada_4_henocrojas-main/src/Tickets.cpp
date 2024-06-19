#include "Tickets.h"

Tickets::Tickets()
{
    this->counter = 0;

}

Tickets::~Tickets()
{
}

void Tickets::menu() {
    int option;
    do{
        cout<<"\n          Train Fare        "<<endl
            <<"    1> Add Station        "<<endl
            <<"    2> Change or add train fare"<<endl
            <<"    3> See fare   "<<endl
            <<"    4> Delete Station"<<endl
            <<"    5> Return"<<endl
            <<"    >>> ";

        cin >>option;
        cin.ignore();

        switch (option)
        {
        case 1:
            this->pushBack();
            break;
        case 2: 
            this->createRelations();
            break;
        case 3: 
            this->seeRelations();
            break;
        case 4:
            this->popAl();
            break;    
        case 5:
            break;
        default: 
            std::cout << "Enter a valid option" << std::endl;
            break;
        } 
    }while (option != 5); 

}

void Tickets::pushBack() {
    string name;
    cout<<"     New Station    "<<endl
        <<"Name >> ";
    getline(cin, name);
    Stations* newStations = new Stations(name);
    this->matrizRelacion += (newStations);
    this->estaciones += (newStations);
    ++this->counter;
}

void Tickets::createRelations() {
    
    cout<<endl<<endl;;
    this->imprimirEstaciones();
    int user1;
    int user2;
    int fare;
    cout<<"Relate (enter the user number) >> ";
    cin >>user1;
    cin.ignore();
    cout<<"with (enter the user number) >> ";
    cin >>user2;
    cin.ignore();
    cout<<"Enter the cost of the ticket >> ";
    cin >>fare;
    cin.ignore();
    this->matrizRelacion.setRelation(this->estaciones[user1-1], this->estaciones[user2-1], fare);
}

void Tickets::seeRelations() {
    this->imprimirEstaciones();
    cout <<"======================"<<endl;
    int user1;
    int user2;
    cout<<"Relation between >> ";
    cin >>user1;
    cin.ignore();
    cout<<"and >> ";
    cin >>user2;
    cin.ignore();
    cout <<"Relation: "<<this->matrizRelacion.viewRelation(this->estaciones[user1-1], this->estaciones[user2-1]);

}

void Tickets::imprimirEstaciones()
{
    for (int i = 0; i < this->counter; ++i) {
        cout<<"======================="<<endl;
        cout<<"      Station no: "<<i+1<<endl;
        cout<<"Station: "<<(this->estaciones[i])<<endl;
    }
}
void Tickets::popAl() {
    cout<<endl<<endl;
    this->imprimirEstaciones();

    int estacion;
    cout<<"Station number to delete >> ";
    cin >>estacion;
    cin.ignore();

    this->matrizRelacion -= (this->estaciones[estacion-1]);
    this->estaciones -= (estacion-1);

    --this->counter;
}
