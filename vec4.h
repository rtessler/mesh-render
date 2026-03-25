//
//  Vec4.hpp
//  mesh-render
//
//  Created by Robert Tessler on 11/3/2026.
//
#pragma once
class Matrix2D;

class Vec4 {
  public:
    double x, y, z, w;
    
    Vec4(double xx=0, double yy=0, double zz=0);
    Vec4 dot(Vec4 v);
    Vec4 cross(Vec4 v);
    double mag();
    Vec4 unit();
    void print();
    
    Vec4 operator+ (const double d);
    Vec4 operator- (const double d);
    Vec4 operator* (const double d);
    double& operator [](const int i);
    Vec4 operator* (const Matrix2D &m);
};
