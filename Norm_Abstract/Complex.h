#pragma once
#include "Norm.h"

class Complex: public Norm {
public:
    Complex(double a, double b) {args = new double[2]; args[0] = a; args[1] = b;};
    Complex() {args = new double[2]; args[0] = 0; args[1] = 0;};

    double getReal() const {return args[0];}
    double getIm() const {return args[1];}
    void setReal(double a) {args[0] = a;}
    void setIm(double a) {args[1] = a;}

    virtual double norm();
    virtual double modulus();

    virtual void print();
};
