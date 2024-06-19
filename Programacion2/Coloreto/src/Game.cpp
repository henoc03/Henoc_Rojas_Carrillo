#include "Game.h"
#include <iostream>
#include <random>
#include <windows.h>
using namespace std;
Game::Game()
{
}

Game::Game(int players_n, int colors_n) 
{
    this->playersAmount = players_n;
    this->colorsAmount = colors_n;
    this->deckRows = new tableRow* [this->playersAmount];
    for (int i = 0; i < this->playersAmount; ++i)
    {
        deckRows[i] = new tableRow();
        deckRows[i]->taken = false;
    }
    this->players = new Player*[this->playersAmount];
    cin.ignore();
    for (int i = 0; i < playersAmount; i++)
    {
        char* name_n = new char[50];
        cout <<"Player ["<<i+1<<"] name > ";
        cin.getline(name_n,50);

        this->players[i] = new Player(name_n, this->colorsAmount);
    }
    this->Deck = nullptr;

    int colors[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    this->colorsCodes = colors;

}

Game::Player::Player(char* name_n, int colors)
{
    Game gameInstance;
    this->name = new char[50];
    this->score = 0;
    this->outOfthisRound = false;
    gameInstance.strcpy(this->name, name_n);
    this->playerMazo = new Cart*[colors + 2];
    for (int i = 0; i < colors +2; i++)
    {
        //new Cart(0, false, false, false);
        playerMazo[i] = NULL;
    }
    this->score = 0;
}

Game::Player::~Player()
{
    
}

Game::~Game()
{
}

void Game::turn()
{

    Cart* currentCart = this->Deck;

    while(currentCart)
    {
        this->playersNewRound();
        while (this->onePlayerLeftInTheRound())
        {
            for (int i = 0; i < playersAmount; i++)
            {
                if(currentCart == nullptr)
                {
                    break;
                }
                if (!(this->players[i]->outOfthisRound))
                {
                    if(!(this->verifyFulledRows()))
                    {
                        system("cls");
                        cout<< "===================================" <<endl
                            << "It's the turn of ["<<players[i]->name<<"]"<<endl
                            << "===================================" <<endl
                            << "             Row cards             " <<endl;
                        this->showCartRows();
                        cout<< "-----------------------------------" <<endl
                            << "           Players deck            " <<endl;
                        this->showPlayersCarts();
                        cout<< "===================================" <<endl;
                        int option = 0;
                        cout<< "              Options              "<<endl
                            << "  1. Take and put cart "<<endl
                            << "  2. Take a row        "<<endl
                            << "> ";
                        cin >>option;

                        switch (option)
                        {
                            case 1:
                                {
                                Cart* aux = currentCart;
                                currentCart = currentCart->getNext();
                                this->takeAndPutCart(aux);
                                }
                                break;
                            case 2: 
                            {
                                int rowTaken = 0;
                                cout <<"Choose a row to take it > ";
                                cin >>rowTaken;
                                if (this->deckRows[rowTaken-1]->counter != 0)
                                {
                                    if (!(this->deckRows[rowTaken-1]->taken))
                                    {
                                        this->takeRow(i, rowTaken);
                                        this->deckRows[rowTaken-1]->taken = true; 
                                        this->players[i]->outOfthisRound = true;
                                    }
                                    else
                                    {
                                        char ignore;
                                        cout <<"The row is alredy taken, pleace choose another"<< endl;
                                        cout<<"-----------------------------------------------"<< endl
                                            << "[Tap any letter or number to continue]"<<endl;
                                        cin >> ignore;
                                        --i;
                                    }
                                    
                                }
                                else
                                {
                                    {
                                        --i;
                                    cout <<"This row it's empty, pleace choose" <<endl
                                        <<"another one or take a card of the deck."<<endl;
                                    char ignore;
                                    cout<<"----------------------------------------"<< endl
                                        << "[Tap any letter or number to continue]"<<endl;
                                    cin >> ignore;
                                    }
                                }
                                
                            }
                                
                                break;

                            default:
                                cout << "Invalid option, try again"<<endl;
                                --i;
                            break;
                        }
                    }
                    else
                    {
                        system("cls");
                        int rowTaken = 0;
                        cout<< "===================================" <<endl
                            << "It's the turn of ["<<players[i]->name<<"]"<<endl
                            << "===================================" <<endl
                            << "             Row cards             " <<endl;
                        this->showCartRows();
                        cout<< "-----------------------------------" <<endl
                            << "           Players deck            " <<endl;
                        this->showPlayersCarts();
                        cout<< "===================================" <<endl
                            << "Choose a row to take it > ";
                        cin >>rowTaken;
                        if (!(this->deckRows[rowTaken-1]->taken))
                        {
                            this->takeRow(i, rowTaken);
                            this->deckRows[rowTaken-1]->taken = true; 
                            this->players[i]->outOfthisRound = true;
                        }
                        else
                        {
                        char ignore;
                        cout <<"The row is alredy taken, pleace choose another"<< endl;
                        cout<<"-----------------------------------------------"<< endl
                            << "[Tap any letter or number to continue]"<<endl;
                        cin >> ignore;
                        --i;
                        }
                    }

                }
                
            }
        
            if (currentCart == nullptr)
            {
                break;
            }
        }
    }
    system("cls");
    this->playersScores();
}

void Game::takeRow(int playerNumber, int rowTaken)
{

    while(deckRows[rowTaken-1]->counter != 0)
    {   
        if ((deckRows[rowTaken -1]->rowCarts->getColor()) == 0 &&  deckRows[rowTaken - 1]->rowCarts->getAdd2())
        {
            //Creating a copy of cart_n
            
            int color = this->deckRows[rowTaken-1]->rowCarts->getColor();
            bool extraPoints = this->deckRows[rowTaken-1]->rowCarts->getAdd2();
            bool Multicolor = this->deckRows[rowTaken-1]->rowCarts->getMulticolor();
            bool finalCart = this->deckRows[rowTaken-1]->rowCarts->getFinal();
            Cart* copyCart = new Cart(color, extraPoints, Multicolor, finalCart);

            Cart* currentPlayerCart = this->players[playerNumber]->playerMazo[0];
            while (true)
            {
                if (this->players[playerNumber]->playerMazo[0] == nullptr)
                {
                    this->players[playerNumber]->playerMazo[0] = copyCart;
                    Cart* aux = deckRows[rowTaken - 1]->rowCarts;
                    deckRows[rowTaken - 1]->rowCarts = deckRows[rowTaken - 1]->rowCarts->getNext();
                    (deckRows[rowTaken - 1]->counter) --;
                    delete aux;
                    break;
                } 
                else
                {
                    if (currentPlayerCart->getNext() == nullptr)
                    {
                        currentPlayerCart->setNext(copyCart);
                        Cart* aux = deckRows[rowTaken - 1]->rowCarts;
                        deckRows[rowTaken - 1]->rowCarts = deckRows[rowTaken - 1]->rowCarts->getNext();
                        (deckRows[rowTaken - 1]->counter) --;
                        delete aux;
                        break;
                    }
                    else
                    {
                        currentPlayerCart = currentPlayerCart->getNext();

                    }
                }

                
                
            }
            
        }
        else
        {
            if ((deckRows[rowTaken -1]->rowCarts->getColor()) == 0 &&  deckRows[rowTaken - 1]->rowCarts->getMulticolor())
            {
                int color = this->deckRows[rowTaken-1]->rowCarts->getColor();
                bool extraPoints = this->deckRows[rowTaken-1]->rowCarts->getAdd2();
                bool Multicolor = this->deckRows[rowTaken-1]->rowCarts->getMulticolor();
                bool finalCart = this->deckRows[rowTaken-1]->rowCarts->getFinal();
                Cart* copyCart = new Cart(color, extraPoints, Multicolor, finalCart);

                Cart* currentPlayerCart = this->players[playerNumber]->playerMazo[1];
                while (true)
                {
                    if (this->players[playerNumber]->playerMazo[1] == nullptr)
                    {
                        this->players[playerNumber]->playerMazo[1] = copyCart;
                        Cart* aux = deckRows[rowTaken - 1]->rowCarts;
                        deckRows[rowTaken - 1]->rowCarts = deckRows[rowTaken - 1]->rowCarts->getNext();
                        (deckRows[rowTaken - 1]->counter) --;
                        delete aux;
                        break;
                    } 
                    else
                    {
                        if (currentPlayerCart->getNext() == nullptr)
                        {
                            currentPlayerCart->setNext(copyCart);
                            Cart* aux = deckRows[rowTaken - 1]->rowCarts;
                            deckRows[rowTaken - 1]->rowCarts = deckRows[rowTaken - 1]->rowCarts->getNext();
                            (deckRows[rowTaken - 1]->counter) --;
                            delete aux;
                            break;
                        }
                        else
                        {
                            currentPlayerCart = currentPlayerCart->getNext();

                        }
                    }

                    
                    
                }
            
            } 
            else
            {
                if ((deckRows[rowTaken -1]->rowCarts->getColor()) != 0)
                {
                    int color = this->deckRows[rowTaken-1]->rowCarts->getColor();
                    bool extraPoints = this->deckRows[rowTaken-1]->rowCarts->getAdd2();
                    bool Multicolor = this->deckRows[rowTaken-1]->rowCarts->getMulticolor();
                    bool finalCart = this->deckRows[rowTaken-1]->rowCarts->getFinal();
                    Cart* copyCart = new Cart(color, extraPoints, Multicolor, finalCart);

                    int colorNumber =  (deckRows[rowTaken -1]->rowCarts->getColor()) + 1;
                    Cart* currentPlayerCart = this->players[playerNumber]->playerMazo[colorNumber];
                    while (true)
                    {
                        if (this->players[playerNumber]->playerMazo[colorNumber] == nullptr)
                        {
                            this->players[playerNumber]->playerMazo[colorNumber] = copyCart;
                            Cart* aux = deckRows[rowTaken - 1]->rowCarts;
                            deckRows[rowTaken - 1]->rowCarts = deckRows[rowTaken - 1]->rowCarts->getNext();
                            (deckRows[rowTaken - 1]->counter) --;
                            delete aux;
                            break;
                        } 
                        else
                        {
                            if (currentPlayerCart->getNext() == nullptr)
                            {
                                currentPlayerCart->setNext(copyCart);
                                Cart* aux = deckRows[rowTaken - 1]->rowCarts;
                                deckRows[rowTaken - 1]->rowCarts = deckRows[rowTaken - 1]->rowCarts->getNext();
                                (deckRows[rowTaken - 1]->counter) --;
                                delete aux;
                                break;
                            }
                            else
                            {
                                currentPlayerCart = currentPlayerCart->getNext();

                            }
                        }
                    }
                }
            }
        }
    }
}

void Game::takeAndPutCart(Cart* cart_n)
{
    // Tiene que eliminar la carta cabeza y poner a currenteCart apuntando a currentCart.next.
    // Ademas debe poder cargar el currentCart en la fila de la meza que el usuario elija.
    this->showCard(cart_n);
    //Cart* copy = new Cart(cart_n->getColor,false,false,false)

    if (!(cart_n->getFinal()))
    {
        int rowChoosed;
        cout << "Choose a row to put the cart > ";
        cin >> rowChoosed;
        if((this->deckRows[rowChoosed-1]->counter) == 3)
        {
            cout <<"This row is fulled, pleace select another"<<endl;
            this->takeAndPutCart(cart_n);

        }
        else
        {
            if (!(this->deckRows[rowChoosed-1]->taken))
            {
                    //Creating a copy of cart_n
                int color = cart_n->getColor();
                bool extraPoints = cart_n->getAdd2();
                bool Multicolor = cart_n->getMulticolor();
                bool finalCart = cart_n->getFinal();


                Cart* copyCart = new Cart(color, extraPoints, Multicolor, finalCart);

                Cart* currentRowCart = this->deckRows[rowChoosed-1]->rowCarts;

                while (true)
                {
                    if (this->deckRows[rowChoosed-1]->rowCarts == nullptr)
                    {
                        //put the cart in the row;
                        this->deckRows[rowChoosed-1]->rowCarts = copyCart;
                        //increase the element counter
                        (this->deckRows[rowChoosed-1]->counter) ++;
                        //delete head(cart_n) from principal Deck
                        delete (cart_n);
                        break;
                    }
                    else
                    {
                        if (currentRowCart->getNext() == nullptr &&  this->deckRows[rowChoosed-1]->counter < 3)
                        {
                            //put the cart in the row;
                            currentRowCart->setNext(copyCart);
                            //increase the element counter
                            (this->deckRows[rowChoosed-1]->counter) ++;
                            //delete head(cart_n) from principal Deck
                            delete (cart_n);
                            break;
                        }
                        else
                        {
                            if (currentRowCart->getNext() != nullptr)
                            {
                                currentRowCart = currentRowCart->getNext();
                            
                            }
                            
                            
                        }
                    }
                    
                }
            }
            else
            {
                char ignore;
                cout <<"This row is alredy taken, please choose another"<< endl;
                cout<<"--------------------------------"<< endl
                    << "[Tap any letter or number to continue]"<<endl;
                cin >> ignore;
                this->takeAndPutCart(cart_n);
            }
            
        }
        
    }
    else
    {
        char ignore;
        cout <<"The game is coming to an end"<< endl;
        cout<<"--------------------------------"<< endl
            << "[Tap any letter or number to continue]"<<endl;
        cin >> ignore;
    }
   

}

void Game::showPlayersCarts()
{
    for(int player = 0; player < this->playersAmount ; player++){
        cout << this->players[player]->name << " -> ";

        for(int index = 0; index < this->colorsAmount+2; index++){

            if(this->players[player]->playerMazo[index]){
                Cart* aux = this->players[player]->playerMazo[index];
                while(aux){
                    showResumeCard(aux);
                    aux = aux->getNext();
                }
            }

        }

        cout << endl;
    }
}



void Game::showCartRows()
{
    for(int row = 0; row < this->playersAmount; row++){

        cout << "Row " << row + 1 << " -> ";
        if(this->deckRows[row]->rowCarts){

            Cart* aux = this->deckRows[row]->rowCarts;
            while(aux){
                showResumeCard(aux);
                aux = aux->getNext();
            }
        }
        cout << endl;
    }
}


// Show cards on players deck and rows deck
void Game::showResumeCard(Cart* card)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if(card->getColor() != 0){
        SetConsoleTextAttribute(hConsole, card->getColor());
        //cout << card->getColor();
        cout << "X";
        SetConsoleTextAttribute(hConsole, 15);
        cout << "  ";
    }
    else{
        if(card->getAdd2()){
            cout << "+2  ";
        }
        else if(card->getMulticolor()){
            SetConsoleTextAttribute(hConsole, 1);
            cout << "M";
            SetConsoleTextAttribute(hConsole, 10);
            cout << "U";
            SetConsoleTextAttribute(hConsole, 6);
            cout << "L  ";
            SetConsoleTextAttribute(hConsole, 15);
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
}




// Show a card from deck
// Show a card from deck
void Game::showCard(Cart* card)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Check if the card has a color
    if(card->getColor() != 0){
        SetConsoleTextAttribute(hConsole, card->getColor());
        cout <<  "  +---+ "
            << "\n  |   |"
            << "\n  |   |"
            << "\n  +---+" << endl;
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        if(card->getAdd2()){
            SetConsoleTextAttribute(hConsole, 7);
            cout <<  "  +---+ "
                << "\n  | + |"
                << "\n  | 2 |"
                << "\n  +---+" << endl;
        }
        else if(card->getMulticolor()){
            SetConsoleTextAttribute(hConsole, 1);
            cout << "  +---+ " << endl;
            SetConsoleTextAttribute(hConsole, 4);
            cout << "  |   |" << endl;
            SetConsoleTextAttribute(hConsole, 6);
            cout << "  |   |" << endl;
            SetConsoleTextAttribute(hConsole, 10);
            cout << "  +---+" << endl;
        }
        else if(card->getFinal()){
            SetConsoleTextAttribute(hConsole, 7);
            cout <<  "  +---+ "
                << "\n  | E |"
                << "\n  | N |"
                << "\n  | D |"
                << "\n  +---+" << endl;
        }

        SetConsoleTextAttribute(hConsole, 15);
    }

    SetConsoleTextAttribute(hConsole, 15);
}

bool Game::verifyFulledRows()
{
    bool returnable = false;
    for (int i = 0; i < this->playersAmount; ++i)
    {
        //When counter = 0, the deckRow is empty or is already taken
        if(this->deckRows[i]->taken == false)
        {
            //counter = 3, it means the deckRow is full
            if (this->deckRows[i]->counter == 3)
            {
                returnable = true;
            }
            else
            {
                returnable = false;
            break;
            }
        }
        
    }
    return returnable;

}

Game::tableRow::tableRow()
{
    this->counter = 0;
    this->rowCarts = nullptr;
    this->taken = false;
}

//Build deck according to colors quantity
void Game::createDeck(int colors){

    //Create 9 cards of each color
    for(int color = 0; color < colors; color++){
        for(int i = 0; i < 9; i++){
            addCard(color+1);
        }
    }
    addSpecials();
}

//Add a card to deck
void Game::addCard(int color){

    //Check if deck has a head
    if(this->Deck){
        Cart* aux = this->Deck;

        //Search for a null
        while(aux->getNext()){
            aux = aux->getNext();
        }

        aux->setNext(new Cart(color, false, false, false));
    }
    
    //Create a head if deck doesn't has one
    else{ 
        this->Deck = new Cart(color, false, false, false);
    }
}

//Add special cards to deck
void Game::addSpecials(){
    if(this->Deck){
        Cart* aux = this->Deck;

        //Search for a null
        while(aux->getNext()){
            aux = aux->getNext();
        }

        //Add +2 cards to deck
        for(int index = 0; index < 10; index++){
            Cart* card = new Cart(0, true, false, false);
            aux->setNext(card);
            aux = aux->getNext();
        }

        //Add multicolor cards to deck
        for(int index = 0; index < 3; index++){
            Cart* card = new Cart(0, false, true, false);
            aux->setNext(card);
            aux = aux->getNext();
        }

    }
}

void Game::addFinalCard()
{
    int position = this->playersAmount * 3;
    

    int deckSize = 0;
    Cart* aux = this->Deck;

    // Count cards on deck
    while(aux) {
        deckSize++;
        aux = aux->getNext();
    }

    position = deckSize - position;
    int counter = 0;

    aux = this->Deck;

    //Look for position on deck
    while(aux) {
        counter++;
        if (counter == position){
                Cart* card = new Cart(0, false, false, true); // Create final card
                Cart* auxNext = aux->getNext();
                aux->setNext(card);
                aux = aux->getNext();
                aux->setNext(auxNext);
                break;
        }
        aux = aux->getNext();
    }
}



bool Game::onePlayerLeftInTheRound()
{
    bool leftPInRound = false; 

    for (int i = 0; i < this->playersAmount; ++i)
    {
        if (this->players[i]->outOfthisRound == false)
        {
            leftPInRound = true;
            break;
        }
        else
        {
            leftPInRound = false;
        }
    }

    return leftPInRound;
}

void Game::playersNewRound()
{
    for (int i = 0; i < this->playersAmount; ++i)
    {
        this->players[i]->outOfthisRound = false;
    }

    for (int i = 0; i < this->playersAmount; ++i)
    {
        this->deckRows[i]->taken = false;
    }
}

void Game::strcpy(char* newChar, char* originChar)
{
    int charsAmo = 0;
    for (int i = 0; originChar[i] != '\0'; ++i)
    {
        charsAmo++;
    }

    for (int i = 0; i <= charsAmo+1; ++i)
    {
        newChar[i] = originChar[i];
    }
}

void Game::shuffle()
{
    int deckSize = 0;
    Cart* aux = this->Deck;

    //Counts the number of cards
    while(aux) {
        deckSize++;
        aux = aux->getNext();
    }

    // Create an array to store in the pointers of the cards
    Cart** cards = new Cart*[deckSize];

    aux = this->Deck;

    //Fill the array with the cards
    for(int i = 0; i < deckSize; i++) {
        cards[i] = aux;
        aux = aux->getNext();
    }

    //Does the shuffle
    random_device rd;
    mt19937 gen(rd());

    for (int i = deckSize - 1; i > 0; i--) {
        uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);

        if (i != j) {
            Cart* tmp = cards[i];
            cards[i] = cards[j];
            cards[j] = tmp;
        }
    }



    //Fill the deck with the already shuffled cards
    this->Deck = cards[0]; //The deck will have the first card of the shuffled
    aux = this->Deck;

    for (int i = 1; i < deckSize; i++) {
        aux->setNext(cards[i]);
        aux->getNext()->setNext(nullptr);
        aux = aux->getNext();
    }

    


}


void Game::playersScores()
{
    cout << "   <<<    FINAL SCORES    >>>" << endl;

    for(int player = 0; player < this->playersAmount; player++){
        cout << this->players[player]->name << "   ---->   " << this->players[player]->getScore(this->colorsAmount) << endl;
    }
}

int Game::Player::getScore(int colors)
{
    int colorsPoints[colors]; // Cantidad de cartas de cada color
    int maxColors[] = {-1,-1,-1}; // Almacena las posiciones de colorsPoints de los colores mayores 
    int colorPoints = 0;
    int index=0;

    // Inicia en 2, ya que los primeros 2 espacios son cartas especiales
    for(int card = 2; card < colors+2; card++){

        colorPoints = 0; // Reiniciar puntos para cada color

        if(this->playerMazo[card]){

            Cart* aux = this->playerMazo[card];
            while(aux){
                colorPoints++;
                aux = aux->getNext();
            }

        }

        colorsPoints[index] = colorPoints;
        index++;
    }

    // Buscar los 3 colores con mas cartas
    for(index = 0; index < colors; index++){
        if(maxColors[0] == -1 || colorsPoints[index] > colorsPoints[maxColors[0]]){
            maxColors[2] = maxColors[1];
            maxColors[1] = maxColors[0];
            maxColors[0] = index;
        }
        else if(maxColors[1] == -1 || colorsPoints[index] > colorsPoints[maxColors[1]]){
            maxColors[2] = maxColors[1];
            maxColors[1] = index;
        }
        else if(maxColors[2] == -1 || colorsPoints[index] > colorsPoints[maxColors[2]]){
            maxColors[2] = index;
        }
    }

    // Sumar Cartas +2
    if (this->playerMazo[0]){
        Cart* aux = this->playerMazo[0];
        while(aux){
            this->score += 2;
            aux = aux->getNext();
        }
    }

    // Sumar cartas Multicolor
    int multicolorCards = 0;

    if (this->playerMazo[1]){

        Cart* aux = this->playerMazo[1];

        while(aux){
            multicolorCards++;
            aux = aux->getNext();
        }

    }

    for(int i = 0; i < 3; i++){

        if(maxColors[i] != -1){
            
            while(multicolorCards > 0 && colorsPoints[maxColors[i]] < 6){
                colorsPoints[maxColors[i]]++;
                multicolorCards--;
            }

        }
    }

    // Contar puntos
    int points;
    for(int color = 0; color < colors; color++){

        switch(colorsPoints[color]){
            case 0:
                points = 0;
                break;
            
            case 1:
                points = 1;
                break;
            
            case 2:
                points = 3;
                break;

            case 3:
                points = 6;
                break;

            case 4:
                points = 10;
                break;

            case 5:
                points = 15;
                break;

            default: // 6 o mas cartas del mismo color
                points = 21;
                break;
        }
        
        if(color == maxColors[0] || color == maxColors[1] || color == maxColors[2]){
            this->score += points;
        }
        else{
            this->score -= points;
        }
    }

    return this->score;
}

