//
//  Vec4 2.hpp
//  mesh-render
//
//  Created by Robert Tessler on 11/3/2026.
//
#include "vec4.h"
#include <iostream>
#include <iomanip>
#include "matrix.h"

using namespace std;

Vec4::Vec4(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
  this->w = 1;
}
    
Vec4 Vec4::dot(Vec4 v) {
    return Vec4(x * v.x, y * v.y, z * v.z);
}
    
Vec4 Vec4::cross(Vec4 v) {
    return Vec4(y * v.z - z * v.y,
                z * v.x - x * v.z,
                x * v.y - y * v.x);
}

double Vec4::mag() {
    return sqrt( x*x + y*y + z*z);
}

Vec4 Vec4::unit() {
    double m = mag();
    return Vec4(x/m, y/m, z/m);
}

void Vec4::print() {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << x << " " << y << " " << z << endl;
}

Vec4 Vec4::operator+ (const double d) {
    return Vec4(x+d, y+d, z+d);
}
Vec4 Vec4::operator- (const double d) {
    return Vec4(x-d, y-d, z-d);
}
Vec4 Vec4::operator* (const double d) {
    return Vec4(x*d, y*d, z*d);
}
double& Vec4::operator [](const int i) {
    switch (i) {
        case 0: return x; break;
        case 1: return y; break;
        case 2: return z; break;
        case 3: return w; break;
        default:
            throw(std::format("error Vec4::operator [] index: %d out of range", i));
    }
}
Vec4 Vec4::operator* (const Matrix2D &m) {
    if (m.nCols != 4)
        throw("error Vec4::operator: matrix does not have 4 rows");
    Vec4 v;
    for (int i = 0; i < 4; i++) {
        double val = (*this)[i];
        for (int j = 0; j < 4; j++) {
            v[i] = val * m.data[i * 4 + j];
        }
    }
    return v;
}

