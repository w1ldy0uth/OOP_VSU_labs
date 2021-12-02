#include <fstream>

class Pair {
protected:
    int a, b;

public:
    Pair() :a(0), b(0){};
    Pair(int _a, int _b) :a(_a), b(_b) {};
    Pair(const Pair& obj);
    Pair operator +(const Pair& obj);
    Pair operator -(const Pair& obj);
    Pair operator *(int val);
    Pair& operator =(const Pair& obj);
    int getA();
    int getB();

    virtual void print() {};

    friend std::ostream& operator << (std::ostream& out, Pair obj);
};
