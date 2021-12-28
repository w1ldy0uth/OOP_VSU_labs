#include "Complex.h"

double Complex::norm() {
    return std::pow(args[0], 2) + std::pow(args[1], 2);
}

double Complex::modulus() {
    return std::sqrt(std::pow(args[0], 2) + std::pow(args[1], 2));
}

void Complex::print() {
    std::cout << args[0];
    if (args[1] < 0)
        std::cout << " - " << std::abs(args[1]);
    else
        std::cout << " + " << args[1];
    std::cout << "i";
}