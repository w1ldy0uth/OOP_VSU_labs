#include "pair.h"

Pair::Pair(const Pair& obj)
{
    a = obj.a;
    b = obj.b;
}

Pair Pair::operator+(const Pair& obj)
{
    Pair res;
    res.a = a + obj.a;
    res.b = b + obj.b;
    return res;
}

Pair Pair::operator-(const Pair& obj)
{
    Pair res;
    res.a = a - obj.a;
    res.b = b - obj.b;
    return res;
}

Pair Pair::operator*(int val)
{
    Pair res;
    res.a = a * val;
    res.b = b * val;
    return res;
}

Pair& Pair::operator=(const Pair& obj)
{
    if (this == &obj) return *this;
    a = obj.a;
    b = obj.b;
    return *this;
}

int Pair::getA()
{
    return a;
}

int Pair::getB()
{
    return b;
}

std::ostream& operator<<(std::ostream& out, Pair obj)
{
    out << "( " << obj.a << ", " << obj.b << " )\n";
    return out;
}
