#include "Complex.h"
#include "Vector3D.h"
#include <iostream>

int main() {
    Norm* comp = new Complex(4, 3);
    Norm* vec = new Vector3D(3, 4, 5);

    std::cout << "Norm and modulus of ";
    vec->print();
    std::cout << "\n";
    std::cout << vec->norm() << " " << vec->modulus() << "\n";

    std::cout << "Norm and modulus of ";
    comp->print();
    std::cout << "\n";
    std::cout << comp->norm() << " " << comp->modulus() << "\n";

    delete comp;
    delete vec;
    return 0;
}
