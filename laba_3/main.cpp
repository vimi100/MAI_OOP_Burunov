#include <iostream>
#include <string>
#include "Vector.h"

#include "point.h"
#include "Figure.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"

using namespace std;


int main(){
    Trapezoid tr;
    Point p(-1,-1), p2(-2,-3), p3(-4,-3), p6(-5,-1);
    Point p4;
    p4 = p6;
    Point p10(3.0,2.0);
    Trapezoid tr2(p,p2,p3,p4);
    tr = tr2;

    cout << "tr.center() 1  " << tr.center() << endl;

    return 0;
}