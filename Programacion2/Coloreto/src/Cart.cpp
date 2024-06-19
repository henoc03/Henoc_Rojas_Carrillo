#include "Cart.h"

Cart::Cart(int color_n, bool extraPoints_n, bool multicolor_n, bool finalCart_n)
{
    this->Color = color_n;
    this->extra2PointsCart = extraPoints_n;
    this->multicolorCart = multicolor_n;
    this->finalCart = finalCart_n;
    this->next = nullptr;
}

Cart::~Cart()
{
}

int Cart::getColor(){
    return this->Color;
}

bool Cart::getAdd2(){
    return this->extra2PointsCart;
}

bool Cart::getMulticolor(){
    return this->multicolorCart;
}

bool Cart::getFinal(){
    return this->finalCart;
}

Cart* Cart::getNext(){
    return this->next;
}

//Set next to a card
void Cart::setNext(Cart* nextCard){
    this->next = nextCard;
}