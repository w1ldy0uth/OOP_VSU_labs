#include "Vector3D.h"

double Vector3D::norm() {
    return std::max(std::max(std::abs(args[0]), std::abs(args[1])), std::abs(args[2]));
}

double Vector3D::modulus() {
    return std::sqrt(args[0] * args[0] + args[1] * args[1] + args[2] * args[2]);
}

void Vector3D::print() {
    std::cout << "(" << args[0] << ", " << args[1] << ", " << args[2] << ")";
}
