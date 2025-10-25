#pragma once

#include "figure.h"

class Rhombus : public Figure {
   private:
    Point pts[4];

   public:
    Rhombus();
    Rhombus(const Point (&arr)[4]);

    
    // Конструкторы копирования/перемещения
    Rhombus(const Rhombus&) = default;
    Rhombus(Rhombus&&) = default;

    // Операции присваивания и сравнения
    Rhombus& operator=(const Rhombus&) = default;
    Rhombus& operator=(Rhombus&&) = default;
    bool operator==(const Rhombus& other) const;

    Point gcenter() const override;
    double area() const override;

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Figure* clone() const override;
};
