#include "Workers.h"
#include "Tickets.h"
#include "Romance.h"
using namespace std;
int main()
{
        int option;
        do{
        cout<<"                 WELCOME          "<<endl
            <<"    What application do you want to use?  "<<endl<<endl
            <<"         1> FLirty             "<<endl
            <<"         2> Train              "<<endl
            <<"         3> Employ-E           "<<endl
            <<"         4> Exit               "<<endl
            <<"         >>> ";

        cin >> option;
        cin.ignore();
        cout <<"\n\n";

        Workers workers;
        Romance romance;
        Tickets tickets;

        switch (option)
        {
        case 1:
            romance.menu();
            break;

        case 2:
            tickets.menu();
            break;
        case 3:
            workers.menu();
            break;
        case 4: 
            break;
        default: 
            std::cout << "Enter a valid option" << std::endl;
            break;
        }
    }while (option != 4);

    return 0;
}