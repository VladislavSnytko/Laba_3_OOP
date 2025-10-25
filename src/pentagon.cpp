#include "../include/pentagon.h"

#include <cmath>


Pentagon::Pentagon() {
    for (int i = 0; i < 5; ++i) pts[i] = Point();
}
Pentagon::Pentagon(const Point (&arr)[5]) {
    for (int i = 0; i < 5; ++i) pts[i] = arr[i];
}

Point Pentagon::gcenter() const {
    long long sx = 0, sy = 0;
    for (int i = 0; i < 5; ++i) {
        sx += pts[i].x;
        sy += pts[i].y;
    }
    return Point(static_cast<int>(sx / 5), static_cast<int>(sy / 5));
}

double Pentagon::area() const {
    long long acc = 0;
    for (int i = 0; i < 5; ++i) {
        int j = (i + 1) % 5;
        acc += static_cast<long long>(pts[i].x) * pts[j].y -
               static_cast<long long>(pts[j].x) * pts[i].y;
    }
    return std::abs(static_cast<double>(acc) / 2.0);
}

void Pentagon::print(std::ostream& os) const {
    os << "pentagon: ";
    for (int i = 0; i < 5; ++i)
        os << "(" << pts[i].x << ", " << pts[i].y << ") ";
}

void Pentagon::read(std::istream& is) {
    for (int i = 0; i < 5; ++i) is >> pts[i].x >> pts[i].y;
}
bool Pentagon::operator==(const Pentagon& other) const {
    for (int i = 0; i < 5; ++i) {
        if (!(pts[i] == other.pts[i])) return false;
    }
    return true;
}

Figure* Pentagon::clone() const { return new Pentagon(*this); }
