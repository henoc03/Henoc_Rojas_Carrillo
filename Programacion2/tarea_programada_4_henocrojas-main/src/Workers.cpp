#include "Workers.h"

Workers::Workers()
{
    this->counter = 0;

}

Workers::~Workers()
{
}

void Workers::menu() {
    int option;
    do{
        cout<<"\n          Employ-e        "<<endl
            <<"    1> New Employee        "<<endl
            <<"    2> Add relation"<<endl
            <<"    3> See relation   "<<endl
            <<"    4> Delete relation   "<<endl
            <<"    5> Delete Employee"<<endl
            <<"    6> Return"<<endl
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
            this->setRelations();
            break;
        case 5:
            this->popAl();
            break;    
        case 6:
            break;
        default: 
            std::cout << "Enter a valid option" << std::endl;
            break;
        } 
    }while (option != 6); 

}
void Workers::setRelations() {
    
    cout<<endl<<endl;;
    this->imprimirTrabajadores();
    int user1;
    int user2;

    cout<<"Relate (enter the employee number) >> ";
    cin >>user1;
    cin.ignore();
    cout<<"with (enter the employee number) >> ";
    cin >>user2;
    cin.ignore();
    this->matrizRelacion.setRelation(this->workers[user1-1], this->workers[user2-1], 0);
    this->matrizRelacion.setRelation(this->workers[user2-1], this->workers[user1-1], 0);
}

void Workers::pushBack() {
    string name;
    cout<<"\n     New Employee    "<<endl
        <<"Name >> ";
    getline(cin, name);
    Employee* newEmployee = new Employee(name);

    this->matrizRelacion += (newEmployee);
    this->workers += (newEmployee);

    ++this->counter;

    
}

void Workers::createRelations() {
    
    cout<<endl<<endl;;
    this->imprimirTrabajadores();
    int user1;
    int user2;
    cout<<"Relate (enter the user number) >> ";
    cin >>user1;
    cin.ignore();
    cout<<"with (enter the user number) >> ";
    cin >>user2;
    cin.ignore();
    this->matrizRelacion.relationBetween(this->workers[user1-1], this->workers[user2-1]);
    this->matrizRelacion.relationBetween(this->workers[user2-1], this->workers[user1-1]);
}

void Workers::seeRelations() {
    this->imprimirTrabajadores();
    cout <<"======================"<<endl;
    int user1;
    int user2;
    cout<<"Relation between >> ";
    cin >>user1;
    cin.ignore();
    cout<<"and >> ";
    cin >>user2;
    cin.ignore();
    if (this->matrizRelacion.viewRelation(this->workers[user1-1], this->workers[user2-1]) == 1){
        cout<<"They work together ";
    }else{
        cout<<"They don't work together ";
    }

}

void Workers::imprimirTrabajadores()
{
    for (int i = 0; i < this->counter; ++i) {
        cout<<"======================="<<endl;
        cout<<"      Employee no: "<<i+1<<endl;
        cout<<"Name: "<<(this->workers[i])<<endl;
    }
}

void Workers::popAl() {
    cout<<endl<<endl;
    this->imprimirTrabajadores();

    int user;
    cout<<"Employee number to delete >> ";
    cin >>user;
    cin.ignore();

    this->matrizRelacion -= (this->workers[user-1]);
    this->workers -= (user-1);

    --this->counter;
}
