#pragma once

#include "figure.h"

class Pentagon : public Figure {
   private:
    Point pts[5];

   public:
    Pentagon();
    Pentagon(const Point (&arr)[5]);

    // Конструкторы копирования/перемещения
    Pentagon(const Pentagon&) = default;
    Pentagon(Pentagon&&) = default;

    // Операции присваивания и сравнения
    Pentagon& operator=(const Pentagon&) = default;
    Pentagon& operator=(Pentagon&&) = default;
    bool operator==(const Pentagon& other) const;
    Point gcenter() const override;
    double area() const override;

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Figure* clone() const override;
};
