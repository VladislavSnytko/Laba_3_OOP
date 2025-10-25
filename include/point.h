#pragma once
#include <iostream>
struct Point { // у struct — public, у class — private по умолчанию
    int x{0};
    int y{0};
    friend std::istream& operator>>(std::istream&, Point&);
    friend std::ostream& operator<<(std::ostream&, const Point&);
    Point();
    Point(int, int);
    friend bool operator==(const Point&, const Point&);
    friend bool operator!=(const Point&, const Point&);
};