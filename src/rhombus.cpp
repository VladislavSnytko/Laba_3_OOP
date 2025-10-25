#include "../include/rhombus.h"

#include <cmath>


Rhombus::Rhombus() {
    for (int i = 0; i < 4; ++i) pts[i] = Point();
}
Rhombus::Rhombus(const Point (&arr)[4]) {
    for (int i = 0; i < 4; ++i) pts[i] = arr[i];
}

Point Rhombus::gcenter() const {
    int sx = 0, sy = 0;
    for (int i = 0; i < 4; ++i) {
        sx += pts[i].x;
        sy += pts[i].y;
    }
    return Point(sx / 4, sy / 4);
}

double Rhombus::area() const {
    long long acc = 0;
    for (int i = 0; i < 4; ++i) {
        int j = (i + 1) % 4;
        acc += static_cast<long long>(pts[i].x) * pts[j].y -
               static_cast<long long>(pts[j].x) * pts[i].y;
    }
    return std::abs(static_cast<double>(acc) / 2.0);
}

void Rhombus::print(std::ostream& os) const {
    os << "rhombus: ";
    for (int i = 0; i < 4; ++i)
        os << "(" << pts[i].x << ", " << pts[i].y << ") ";
}

void Rhombus::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) is >> pts[i].x >> pts[i].y;
}
bool Rhombus::operator==(const Rhombus& other) const {  
    for (int i = 0; i < 4; ++i) {
        if (!(pts[i] == other.pts[i])) return false;
    }
    return true;
}
Figure* Rhombus::clone() const { return new Rhombus(*this); }
