#pragma once
#include <cmath>
#include <iostream>

class Norm {
protected:
    double* args = nullptr;
public:
    virtual ~Norm() = default;

    virtual double norm() = 0;
    virtual double modulus() = 0;

    virtual void print() = 0;
};

