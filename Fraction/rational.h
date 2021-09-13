#include <string>

class Rational {
    int numerator; // числитель
    int denominator; // знаменатель
    static void reduce(Rational);

public:
    explicit Rational(int numerator_value=1, int denominator_value=1);

    [[nodiscard]] int get_numerator() const;
    void set_numerator(int);

    [[nodiscard]] int get_denominator() const;
    void set_denominator(int);

    [[nodiscard]] std::string toString() const;

    [[nodiscard]] Rational sum(Rational) const;
    [[nodiscard]] Rational sub(Rational) const;
    [[nodiscard]] Rational mul(Rational) const;
    [[nodiscard]] Rational div(Rational) const;

    [[nodiscard]] bool equal(Rational) const;
    [[nodiscard]] bool greater(Rational) const;
    [[nodiscard]] bool less(Rational) const;
};
