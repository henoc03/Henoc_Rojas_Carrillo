#include "Controller.h"
#include <iostream>
using namespace std;
Controller::Controller()
{
    playersAmount = 0;
    colorsAmount = 0;
}

Controller::~Controller()
{
}

void Controller::Menu()
{
    int option = 0;

        cout << "=========================================" <<endl
            << "                 Menu                    " <<endl
            << "             1< Set colors               " <<endl
            << "             2< Set players              " <<endl
            << "             3< Start game               " << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            Controller::CreateColors();
            break;
        case 2:
            Controller::CreatePlayers(); 
            break;
        case 3:
            if((this->playersAmount != 0) & (this->colorsAmount != 0))
            {
                Controller::StartNewGame();
            }
            else
            {
                cout <<"Before starting the game, define" <<endl 
                     <<"the players and colors amount."<<endl;
                Controller::Menu();
            }
            
            break;
        default:
            cout << "Invalid option" << endl;
            this->Menu();
            break;
        }

}

void Controller::CreateColors()
{
    cout << "Colors amount \n->";
    cin >> this->colorsAmount;

    system("cls");
    Controller::Menu();
}

void Controller::CreatePlayers()
{
    cout << "Players amount \n->";
    cin >> this->playersAmount;

    system("cls");
    Controller::Menu();
}

void Controller::StartNewGame()
{
    this->round = new Game(this->playersAmount, this->colorsAmount);
    this->round->createDeck(this->colorsAmount);
    this->round->shuffle();
    this->round->addFinalCard();
    this->round->turn();
    


}