#pragma once

#include "figure.h"

class Trapezoid : public Figure {
   public:
    Trapezoid();
    Trapezoid(const Point (&arr)[4]);

    // Конструкторы копирования/перемещения
    Trapezoid(const Trapezoid&) = default;
    Trapezoid(Trapezoid&&) = default;

    // Операции присваивания и сравнения
    Trapezoid& operator=(const Trapezoid&) = default;
    Trapezoid& operator=(Trapezoid&&) = default;
    bool operator==(const Trapezoid& other) const;

    Point gcenter() const override;
    double area() const override;

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Figure* clone() const override;

   private:
    Point pts[4];
};
