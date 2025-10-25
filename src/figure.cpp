#include "../include/figure.h"

std::ostream& operator<<(std::ostream& out, const Figure& figure) {
    figure.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, Figure& figure) {
    figure.read(in);
    return in;
}

Figure::operator double() const { return area(); } // оператор неявного преобразования
// Прикол в том, что area() виртуальная функция, и ее реализация будет зависеть от конкретного типа фигуры
// this->area()
