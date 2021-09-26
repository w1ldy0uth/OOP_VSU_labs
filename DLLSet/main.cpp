#include "set.h"
#include <iostream>
#include <random>

int main() {
    Set set;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 256);
    for(int i=0; i<10; ++i) {
        int toadd = dist(gen);
        std::cout << toadd << "\n";
        set.add(toadd);
        set.print();
        std::cout << set.getPosByData(toadd) << "\n";
    }
    return 0;
}
