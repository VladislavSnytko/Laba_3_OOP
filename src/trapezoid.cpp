#include "../include/trapezoid.h"

#include <cmath>

Trapezoid::Trapezoid() {
    for (int i = 0; i < 4; ++i) pts[i] = Point();
}

Trapezoid::Trapezoid(const Point (&arr)[4]) {
    for (int i = 0; i < 4; ++i) this->pts[i] = arr[i];
}

Point Trapezoid::gcenter() const {
    int sx = 0, sy = 0;
    for (int i = 0; i < 4; ++i) {
        sx += pts[i].x;
        sy += pts[i].y;
    }
    return Point(sx / 4, sy / 4);
}

double Trapezoid::area() const {
    long long acc = 0;
    for (int i = 0; i < 4; ++i) {
        int j = (i + 1) % 4;
        acc += static_cast<long long>(pts[i].x) * pts[j].y -
               static_cast<long long>(pts[j].x) * pts[i].y;
    }
    return std::abs(static_cast<double>(acc) / 2.0);
}

void Trapezoid::print(std::ostream& os) const {
    os << "trapezoid: ";
    for (int i = 0; i < 4; ++i) {
        os << "(" << pts[i].x << ", " << pts[i].y << ") ";
    }
}

void Trapezoid::read(std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        is >> pts[i].x >> pts[i].y;
    }
}

bool Trapezoid::operator==(const Trapezoid& other) const {
    for (int i = 0; i < 4; ++i) {
        if (!(pts[i] == other.pts[i])) return false;
    }
    return true;
}

Figure* Trapezoid::clone() const { return new Trapezoid(*this); }
