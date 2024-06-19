#include "Romance.h"

Romance::Romance()
{
    this->counter = 0;

}

Romance::~Romance()
{
}

void Romance::menu() {

    int option;
    do{
        cout<<"\n          Flirty <3         "<<endl
            <<"    1> Register a new account"<<endl
            <<"    2> Log in"<<endl
            <<"    3> Return"<<endl
            <<"    >>> ";

        cin >>option;

        cin.ignore();
        bool aux;
        switch (option)
        {
        case 1:
            this->pushBack();
            break;
        case 2: 
            aux = false;
            cout<<"Username >> ";
            getline(cin, username);
            cout<<"Password >> ";
            getline(cin, password);
            for (int i = 0; i < counter; i++)
            {
                if (username == usuarios[i]->getUsername() && password == usuarios[i]->getPassword())
                {
                    menu2(i);
                    aux = true;
                    break;
                }
            }
            if (!aux){
                cout<<"\n Unregistered user";
            }
            break;
        case 3: 
            break;

        default: 
            std::cout << "Enter a valid option" << std::endl;
            break;
        }
    }while (option != 3);

}

void Romance::menu2(int user){

    int option;
    do{

        cout<<"\n          Welcome: "<< usuarios[user]->getName()<<endl;
        this->ImprimirUsuarios(user);
        cout<<"    1> Follow"<<endl
            <<"    2> Unfollow    "<<endl
            <<"    3> See relation    "<<endl
            <<"    4> Delete this account"<<endl
            <<"    5> Return"<<endl
            <<"    >>> ";

        cin >>option;
        cin.ignore();
        switch (option)
        {
        case 1: 
            this->createRelations(user);
            break;
        case 2: 
            this->setRelations(user);
            break;
        case 3: 
            this->seeRelations(user);
            break;
        case 4:
            this->popAl(user);
            break;
        case 5:
            break;
        default: 
            std::cout << "Enter a valid option" << std::endl;
            break;
        }  
    }while (option != 5 && option !=4);
}

void Romance::pushBack() {


    cout<<"     New user    "<<endl
        <<"Name >> ";
    getline(cin, name);
    cout<<"Username >> ";
    getline(cin, username);
    cout<<"Password >> ";
    getline(cin, password);
    Users* newUser = new Users(name, username, password);
    this->matrizRelacion += (newUser);
    this->usuarios += (newUser);
    ++this->counter;
}

void Romance::createRelations(int user) {
    
    int user2;
    cout<<"Which person you want to follow>> ";
    cin >>user2;
    cin.ignore();
    this->matrizRelacion.relationBetween(this->usuarios[user], this->usuarios[user2-1]);

}
void Romance::setRelations(int user) {
    
    int user2;
    cout<<"Which person you want to unfollow>> ";
    cin >>user2;
    cin.ignore();
    this->matrizRelacion.setRelation(this->usuarios[user], this->usuarios[user2-1], 0);

}

void Romance::seeRelations(int user) {
    cout <<"======================"<<endl;
    int user2;
    cout<<"Who you want to see your relationship with>> ";
    cin >>user2;
    cin.ignore();
    if(this->matrizRelacion.viewRelation(this->usuarios[user], this->usuarios[user2-1]) == 1 && this->matrizRelacion.viewRelation(this->usuarios[user2-1], this->usuarios[user]) == 0){
        cout <<"\nYou follow " <<  usuarios[user2-1]->getUsername() << " but it doesn't follow you back\n";
    }else if(this->matrizRelacion.viewRelation(this->usuarios[user], this->usuarios[user2-1]) == 0 && this->matrizRelacion.viewRelation(this->usuarios[user2-1], this->usuarios[user]) == 1){
        cout <<"\nYou don't follow "<< usuarios[user2-1]->getUsername()  <<" but it does follow you\n";
    }else if (this->matrizRelacion.viewRelation(this->usuarios[user], this->usuarios[user2-1]) == 1 && this->matrizRelacion.viewRelation(this->usuarios[user2-1], this->usuarios[user]) == 1){
        cout <<"\nBoth are followed by what there is match <3\n";
    } else{
        cout <<"\nBoth do not follow each other\n";
    }

}

void Romance::ImprimirUsuarios(int user)
{
    for (int i = 0; i < this->counter; ++i) {
        if (i == user){
            continue;
        }
        cout<<"======================="<<endl;
        cout<<"      User ["<<i+1<<"]"<<endl;
        cout<<(this->usuarios[i])<<endl;
    }
}

void Romance::popAl(int user) {

    this->matrizRelacion -= (this->usuarios[user]);
    this->usuarios -= (user);
    --this->counter;
}