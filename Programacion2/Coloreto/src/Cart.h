class Cart
{
private:
    int Color;
    bool extra2PointsCart;
    bool multicolorCart;
    bool finalCart;
    Cart* next;
public:
    void setNext(Cart*);
    Cart* getNext();
    int getColor();
    bool getAdd2();
    bool getMulticolor();
    bool getFinal();
    Cart(int, bool, bool, bool);
    ~Cart();
};

