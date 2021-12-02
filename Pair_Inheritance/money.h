#include "pair.h"

class Money: public Pair {
    void norm();

public:
    Money(int rub, int cop):Pair(rub, cop){norm();};
    Money()=default;
    Money(const Money& obj):Pair(obj){norm();};

    Money operator/(int val);
    int operator/(const Money& obj);

    void print(){};

    friend std::ostream& operator << (std::ostream& out, Money obj);
};
