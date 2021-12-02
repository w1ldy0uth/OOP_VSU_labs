#include "money.h"

Money Money::operator/(int val)
{
    Money res;
    int t =a * 100 + b;
    t /= val;
    res.a = t / 100;
    res.b = t%100;
    return res;
}

int Money::operator/(const Money& obj)
{
    return (a*100+b)/(obj.a*100+obj.b);
}

void Money::norm()
{
    if (b >= 100)
    {
        a = a + b / 100;
        b = b % 100;
    }
    if (b < 0)
    {
        b += 100;
        a -= 1;
    }
}

std::ostream& operator<<(std::ostream& out, Money obj)
{
    out <<  obj.a << " руб. " << obj.b << " коп.\n";
    return out;
}
