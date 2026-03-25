//
//  matrix.h
//  mesh-render
//
//  Created by Robert Tessler on 10/3/2026.
//
#pragma once
class Vec4;

class Matrix2D {
public:
    double *data;
    int nRows, nCols;
    
    Matrix2D();
    Matrix2D(const Matrix2D& m);
    Matrix2D(int nRows, int nCols);
    Matrix2D(int nRows, int nCols, double *inputData);
    ~Matrix2D();
    Matrix2D operator+ (const Matrix2D &m);
    Matrix2D operator- (const Matrix2D &m);
    Matrix2D operator* (const Matrix2D &m);
    
    Matrix2D operator+ (const double d);
    Matrix2D operator- (const double d);
    Matrix2D operator* (const double d);
    
    Vec4 operator* (Vec4 &m);
    
    bool operator == (const Matrix2D &m) const;
    void print();
};
