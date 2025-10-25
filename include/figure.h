#pragma once

#include <iostream>

#include "point.h"

class Figure {
    friend std::ostream& operator<<(std::ostream& out, const Figure& figure);
    friend std::istream& operator>>(std::istream& in, Figure& figure);

   public:
    virtual Point gcenter() const = 0;
    virtual double area() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual Figure* clone() const = 0;

    operator double() const;
    virtual ~Figure() = default;
};
