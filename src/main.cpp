#include <iostream>

#include "../include/array.h"
#include "../include/pentagon.h"
#include "../include/rhombus.h"
#include "../include/trapezoid.h"


int main() {
    ArrayFigures arr;

    std::cout << "Enter 4 points x y for Trapezoid:\n";
    Trapezoid t;
    std::cin >> t;
    arr.push(new Trapezoid(t));
    std::cout << t << "\n";
    Point ct = t.gcenter();
    std::cout << "center: (" << ct.x << ", " << ct.y
              << ") area: " << double(t) << "\n\n";

    std::cout << "Enter 4 points x y for Rhombus:\n";
    Rhombus r;
    std::cin >> r;
    arr.push(new Rhombus(r));
    std::cout << r << "\n";
    Point cr = r.gcenter();
    std::cout << "center: (" << cr.x << ", " << cr.y << ") area: " << r
              << "\n\n";

    std::cout << "Enter 5 points x y for Pentagon:\n";
    Pentagon p;
    std::cin >> p;
    arr.push(new Pentagon(p));
    std::cout << p << "\n";
    Point cp = p.gcenter();
    std::cout << "center: (" << cp.x << ", " << cp.y
              << ") area: " << static_cast<double>(p) << "\n\n";

    std::cout << "total area: " << arr.totalArea() << "\n";
    return 0;
}
/*
0 0 
4 0 
3 2 
1 2

0 0 
2 0 
2 2 
0 2

0 0 
2 0 
3 1 
1 3 
-1 1
*/