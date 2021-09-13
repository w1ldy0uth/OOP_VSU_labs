#include "rational.h"
#include <iostream>
#include <numeric>
#include <string>

void Rational::reduce(Rational fraction) {
    int divisor = std::gcd(fraction.numerator, fraction.denominator);
    fraction.numerator /= divisor;
    fraction.denominator /= divisor;
}

Rational::Rational (int numerator_value, int denominator_value) {
    numerator = numerator_value;
    if (denominator_value == 0) {
        std::cerr << "WARNING: denominator cannot be 0. Set 1 as a default denominator value\n";
        denominator = 1;
    }
    else {
        if (denominator_value < 0) {
            numerator *= -1;
            denominator = -denominator_value;
        }
        else
            denominator = denominator_value;
    int divisor = std::gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    }

}

int Rational::get_numerator() const { // геттер числителя
    return numerator;
}
void Rational::set_numerator(int value) { // сеттер числителя
    numerator = value;
}

int Rational::get_denominator() const { // геттер знаменателя
    return denominator;
}
void Rational::set_denominator(int value) { // сеттер знаменателя
    denominator = value;
}

std::string Rational::toString() const { // метод для вывода информации о дроби в натуральном виде
    std::string info = std::to_string(numerator) + "/" + std::to_string(denominator);
    return info;
}

Rational Rational::sum(Rational fraction) const { // метод сложения двух рациональных дробей
    int frac_num = numerator;
    int frac_den = denominator;

    //ad + bc, bd
    frac_num = frac_num * fraction.denominator + frac_den * fraction.numerator;
    frac_den *= fraction.denominator;

    Rational res(frac_num, frac_den);
    reduce(res);
    return res;
}
Rational Rational::sub(Rational fraction) const { // метод сложения двух рациональных дробей
    int frac_num = numerator;
    int frac_den = denominator;

    //ad - bc, bd
    frac_num = frac_num * fraction.denominator - frac_den * fraction.numerator;
    frac_den *= fraction.denominator;

    Rational res(frac_num, frac_den);
    reduce(res);
    return res;
}
Rational Rational::mul(Rational fraction) const { // метод сложения двух рациональных дробей
    int frac_num = numerator;
    int frac_den = denominator;

    //ac, bd
    frac_num *= fraction.numerator;
    frac_den *= fraction.denominator;

    Rational res(frac_num, frac_den);
    reduce(res);
    return res;
}
Rational Rational::div(Rational fraction) const { // метод сложения двух рациональных дробей
    int frac_num = numerator;
    int frac_den = denominator;

    //ad, bc
    frac_num *= fraction.denominator;
    frac_den *= fraction.numerator;

    Rational res(frac_num, frac_den);
    reduce(res);
    return res;
}

bool Rational::equal(Rational fraction) const {
    int lcn = std::lcm(denominator, fraction.denominator); // приведение к общему множителю и сравнение числителей
    if (numerator * (lcn / denominator) == fraction.numerator * (lcn / fraction.denominator))
        return true;
    return false;
}

bool Rational::greater(Rational fraction) const {
    if ((denominator == fraction.denominator && numerator > fraction.numerator) || (numerator == fraction.numerator && denominator < fraction.denominator))
        return true;
    else if (numerator != fraction.numerator && denominator != fraction.denominator) {
        int lcn = std::lcm(denominator, fraction.denominator); // приведение к общему множителю и сравнение числителей
        if (numerator * (lcn / denominator) > fraction.numerator * (lcn / fraction.denominator))
            return true;
    }
    return false;
}

bool Rational::less(Rational fraction) const {
    if ((denominator == fraction.denominator && numerator < fraction.numerator) || (numerator == fraction.numerator && denominator > fraction.denominator))
        return true;
    else if (numerator != fraction.numerator && denominator != fraction.denominator) {
        int lcn = std::lcm(denominator, fraction.denominator); // приведение к общему множителю и сравнение числителей
        if (numerator * (lcn / denominator) < fraction.numerator * (lcn / fraction.denominator))
            return true;
    }
    return false;
}