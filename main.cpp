//
//  main.cpp
//  mesh-render
//
//  Created by Robert Tessler on 10/3/2026.
//

#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "vec4.h"
#include <cassert>

using namespace std;

void test() {
    double ad[] = {5,7,9,10, 2,7,3,9, 8,10,2,3, 3,3,4,8};
    double bd[] = {3,10,12,18, 12,1,4,9, 9,10,12,2, 3,12,4,10};
    Matrix2D a = Matrix2D(4,4, ad);
    Matrix2D b = Matrix2D(4,4, bd);
    Matrix2D c = a*b;
    c.print();
    
    double d[] = {
        210.00, 267.00, 236.00, 271.00,
        144.00, 165.00, 124.00, 195.00,
        171.00, 146.00, 172.00, 268.00,
        105.00, 169.00, 128.00, 169.00};
    Matrix2D answer = Matrix2D(4,4, d);
    
    assert(c == answer) ;
}

int main(int argc, const char * argv[]) {
//    Vec4 v;
//    
//    v[0] = 2;
//    v[1] = 3;
//    
//    v.print();
    test();
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
