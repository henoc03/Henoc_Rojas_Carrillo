#include "Game.h"
class Controller
{
private:
    Game* round;
    int playersAmount;
    int colorsAmount;

public:

    Controller();
    ~Controller();
    void StartNewGame();
    void Menu();
    void CreatePlayers();
    void CreateColors();
};

