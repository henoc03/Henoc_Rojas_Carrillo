#include "Cart.h"
class Game
{
private:
    class tableRow
    {
        public:
        int counter;
        bool taken;
        Cart* rowCarts;
        tableRow();
        ~tableRow();

    };
    class Player
    {
        public:
            bool outOfthisRound;
            char* name;
            Cart** playerMazo;
            int score;
            Player(char*,int);
            ~Player();
            //void insertCart(Cart*);
            int getScore(int);
    };

    Cart* Deck;
    tableRow** deckRows;
    Player** players;
    int playersAmount;
    int colorsAmount;
    int* colorsCodes;
public:
    void strcpy(char*, char*);
    void turn();
    bool onePlayerLeftInTheRound();
    void shuffle();
    void takeRow(int, int);
    bool verifyFulledRows();
    void takeAndPutCart(Cart*);
    void showCartRows();
    void playersScores();
    void showResumeCard(Cart*);
    void showPlayersCarts();
    void showCard(Cart*);
    void addCard(int);
    void addFinalCard();
    void addSpecials();
    void playersNewRound();
    void createDeck(int colors);
    Game();
    Game(int, int);
    ~Game();
};


