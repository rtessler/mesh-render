//
//  matrix.cpp
//  mesh-render
//
//  Created by Robert Tessler on 10/3/2026.
//
#include "matrix.h"
#include <iostream>
#include <iomanip>
#include "vec4.h"

using namespace std;
    
Matrix2D::Matrix2D() {
    nRows = nCols = 4;      // 4x4 by default
    data = new double[nRows * nCols];
    for (auto i = 0; i < nRows * nCols; i++)
        data[i] = 0.0;
}

Matrix2D::Matrix2D(const Matrix2D& m) {
    nRows = m.nRows;
    nCols = m.nCols;
    data = new double[nRows * nCols];
    for (auto i = 0; i < nRows * nCols; i++)
        data[i] = m.data[i];
}

Matrix2D::Matrix2D(int nRows, int nCols) {
    this->nRows = nRows;
    this->nCols = nCols;
    this->data = new double[nRows * nCols];
}

Matrix2D::Matrix2D(int nRows, int nCols, double *inputData): Matrix2D(nRows, nCols) {
    for (int i = 0; i < nRows * nCols; i++)
        data[i] = inputData[i];
}

Matrix2D::~Matrix2D() {
    if (data != nullptr)
        delete [] data;
}

Matrix2D Matrix2D::operator+ (const Matrix2D &m) {
    if (nRows != m.nRows )
        throw  "Error: Matrix2D operator+ a.nRows != b.nRows";
    if (nCols != m.nCols)
        throw  "Error: Matrix2D operator+ a.nCols != b.nCols";
    
    Matrix2D q(nRows, nCols);
    for (auto i = 0; i < nRows * nCols; i++)
        q.data[i] = data[i] + m.data[i];
    return q;
}

Matrix2D Matrix2D::operator- (const Matrix2D &m) {
    if (nRows != m.nRows )
        throw  "Error: Matrix2D operator+ a.nRows != b.nRows";
    if (nCols != m.nCols)
        throw  "Error: Matrix2D operator+ a.nCols != b.nCols";
    
    Matrix2D q(nRows, nCols);
    for (auto i = 0; i < nRows * nCols; i++)
        q.data[i] = data[i] - m.data[i];
    return q;
}

Matrix2D Matrix2D::operator* (const Matrix2D &m) {
    // the number of columns in the first matrix to equal the number of rows in the second
    
    if (nCols != m.nRows)
        throw "Error: Matrix2D operator* a.nCols != b.nRows";

    Matrix2D res(nRows, nCols);
    
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            for (int k = 0; k < nRows; k++) {
                res.data[i * 4 + j] += data[i * 4 + k] * m.data[k * 4 + j];
            }
        }
    }
    
    return res;
}

Matrix2D Matrix2D::operator + (double d) {
    Matrix2D q(*this);
    for (auto i = 0; i < nRows * nCols; i++)
        q.data[i] += d;
    return q;
}

Matrix2D Matrix2D::operator - (double d) {
    Matrix2D q(*this);
    for (auto i = 0; i < nRows * nCols; i++)
        q.data[i] -= d;
    return q;
}

Matrix2D Matrix2D::operator * (double d) {
    Matrix2D q(*this);
    for (auto i = 0; i < nRows * nCols; i++)
        q.data[i] *= d;
    return q;
}

bool Matrix2D::operator == (const Matrix2D &m) const {
    if (nRows * nCols != m.nRows * m.nCols)
        throw "Error: Matrix2D operator == unequal number of elements";
    
    for (auto i = 0; i < nRows * nCols; i++) {
        if (data[i] != m.data[i])
            return false;
    }
    return true;
}

void Matrix2D::print() {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    
    for (auto i = 0; i < nRows; i++) {
        for (auto j = 0; j < nCols; j++) {
            cout << data[i*4 + j] << " ";
        }
        cout << endl;
    }
}

Vec4 Matrix2D::operator* (Vec4 &v) {
    if (nCols != 4)
        throw("error Matrix2D::operator: matrix does not have 4 rows");
    Vec4 tmp;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            tmp[i] += data[i * 4 + j] * v[j];
    }
    return tmp;
}

