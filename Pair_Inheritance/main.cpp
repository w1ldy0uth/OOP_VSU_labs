#include "money.h"
#include <iostream>

int main() {
    Money a(35, 60);
    Money b(15,80);
    Pair* p = new Money;
    *p = a + b;
    std::cout << "*Pair: " << *p;
    Money* q = dynamic_cast<Money*>(p);
    std::cout << "*Money: " << *q << "\n";
    return 0;
}
