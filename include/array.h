#pragma once

#include <iostream>
#include <stdexcept>
#include "../include/figure.h"

class ArrayFigures {
private:
    Figure** data{nullptr};
    size_t size{0};
    size_t capacity{0};

    void resize(size_t newCap);

public:
    ArrayFigures();
    ArrayFigures(size_t capacity);
    ArrayFigures(const ArrayFigures& other);
    ArrayFigures(ArrayFigures&& other) noexcept;
    ArrayFigures(std::initializer_list<Figure*> list);
    ~ArrayFigures();

    ArrayFigures& operator=(const ArrayFigures& other);
    ArrayFigures& operator=(ArrayFigures&& other) noexcept;

    Figure*& operator[](size_t idx);
    const Figure* operator[](size_t idx) const;

    void push(Figure* figure);
    void remove(size_t ind);

    size_t getSize() const;
    size_t getCap() const;
    bool isEmpty() const;

    double totalArea() const;
};