#pragma once
#include "Norm.h"


class Vector3D: public Norm {
    double x1, x2, x3;

public:
    Vector3D(double a, double b, double c) {args = new double[2]; args[0] = a; args[1] = b; args[2] = c;};
    Vector3D() {args = new double[3]; args[0] = 0; args[1] = 0; args[2] = 0;};

    double getx1() const {return args[0];}
    double getx2() const {return args[1];}
    double getx3() const {return args[2];}
    void setx1(double a) {args[0] = a;}
    void setx2(double a) {args[1] = a;}
    void setx3(double a) {args[2] = a;}

    virtual double norm();
    virtual double modulus();

    virtual void print();
};

