#include <cassert> // для проверки равенства знаменателя нулю
#include <iostream>
#include <numeric> // для НОД и НОК
#include <string>

using namespace std;

class Rational {
    // класс для работы с рациональными дробями вида "числитель/знаменатель"
    private:
        int numerator; // числитель
        int denominator; // знаменатель

        void reduce() { // приватный метод для сокращения дроби
            // функция находит НОД числителя и знаменателя и делит их на найденный НОД
            int divisor = gcd(numerator, denominator);
            numerator /= divisor;
            denominator /= divisor;
        }

    public:
        explicit Rational (int numerator_value=1, int denominator_value=1) { // конструктор класса
            assert(denominator != 0); // проверка на равенство знаменателя нулю (так низзя)
            numerator = numerator_value;
            denominator = denominator_value;
        }

        [[nodiscard]] int get_numerator() const { // геттер числителя
            return numerator;
        }
        void set_numerator(int value) { // сеттер числителя
            numerator = value;
        }

        [[nodiscard]] int get_denominator() const { // геттер знаменателя
            return denominator;
        }
        void set_denominator(int value) { // сеттер знаменателя
            // запихнуть ассерт на проверку нуля???
            denominator = value;
        }

        [[nodiscard]] string toString() const { // метод для вывода информации о дроби в натуральном виде
            string info = to_string(numerator) + "/" + to_string(denominator);
            return info;
        }

        void sum(Rational fraction) { // метод сложения двух рациональных дробей
            int frac_num = fraction.get_numerator();
            int frac_den = fraction.get_denominator();

            //ad + bc, bd
            numerator = numerator * frac_den + denominator * frac_num;
            denominator *= frac_den;

            reduce();
        }

        void sub(Rational fraction) { // метод вычитания двух рациональных дробей
            int frac_num = fraction.get_numerator();
            int frac_den = fraction.get_denominator();

            // ad - bc, bd
            numerator = numerator * frac_den - denominator * frac_num;
            denominator *= frac_den;

            reduce();
        }

        void mul(Rational fraction) { // метод умножения двух рациональных дробей
            int frac_num = fraction.get_numerator();
            int frac_den = fraction.get_denominator();

            // ac, bd
            numerator *= frac_num;
            denominator *= frac_den;

            reduce();
        }

        void div(Rational fraction) { // метод деления двух рациональных дробей
            int frac_num = fraction.get_numerator();
            int frac_den = fraction.get_denominator();

            // ad, bc
            numerator *= frac_den;
            denominator *= frac_num;

            reduce();
        }

        [[nodiscard]] bool equal(Rational fraction) const { // метод проверки равенства двух рациональных дробей
            int frac_num = fraction.get_numerator();
            int frac_den = fraction.get_denominator();

            if (numerator / denominator == frac_num / frac_den)
                return true;
            return false;
        }

        [[nodiscard]] bool greater(Rational fraction) const { // метод проверки, больше ли данная рациональная дробь, чем другая
            int frac_num = fraction.get_numerator();
            int frac_den = fraction.get_denominator();

            if ((denominator == frac_den && numerator > frac_num) || (numerator == frac_num && denominator < frac_den))
                return true;
            else if (numerator != frac_num && denominator != frac_den) {
                int lcn = lcm(denominator, frac_den); // приведение к общему множителю и сравнение числителей
                if (numerator * (lcn / denominator) > frac_num * (lcn / frac_den))
                    return true;
            }
            return false;
        }

        [[nodiscard]] bool less(Rational fraction) const { // метод проверки, меньше ли данная рациональная дробь, чем другая
            if (!greater(fraction) && !equal(fraction))
                return true;
            return false;
        }
};

int main() {
    // создание экземпляров двух дробей и вывод их на экран
    Rational frac1(2, 3);
    Rational frac2(3, 4);
    cout << frac1.toString() << " " << frac2.toString() << "\n";

    // проверка сеттеров
    frac2.set_numerator(4);
    frac2.set_denominator(6);
    cout << frac2.toString() << "\n\n";

    // проверка методов арифметики
    frac1.sum(frac2);
    cout << frac1.toString() << "\n";
    frac1.sub(frac2);
    cout << frac1.toString() << "\n";
    frac1.mul(frac2);
    cout << frac1.toString() << "\n";
    frac1.div(frac2);
    cout << frac1.toString() << "\n\n";

    // проверка методов сравнений
    cout << frac1.equal(frac2) << "\n";
    cout << frac1.greater(frac2) << "\n";
    cout << frac1.less(frac2) << "\n";

    return 0;
}