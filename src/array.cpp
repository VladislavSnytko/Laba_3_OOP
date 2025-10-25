#include "../include/array.h"

#include <algorithm>
#include <initializer_list>
#include <utility>

void ArrayFigures::resize(size_t newCap) {
    if (newCap == capacity) return;
    // если уменьшаем ёмкость, удалим лишние элементы, чтобы не протекли
    if (newCap < size) {
        for (size_t i = newCap; i < size; ++i) {
            delete data[i];
        }
        size = newCap;
    }
    Figure** newData = newCap ? new Figure*[newCap]() : nullptr;
    for (size_t i = 0; i < size; ++i) newData[i] = data[i];
    delete[] data;
    data = newData;
    capacity = newCap;
}

ArrayFigures::ArrayFigures() : data(nullptr), size(0), capacity(0) {}

ArrayFigures::ArrayFigures(size_t cap) : data(nullptr), size(0), capacity(0) {
    if (cap) {
        data = new Figure*[cap]();
        capacity = cap;
    }
}

ArrayFigures::ArrayFigures(const ArrayFigures& other)
    : data(nullptr), size(0), capacity(0) {
    if (other.size) {
        data = new Figure*[other.size]();
        capacity = other.size;
        size = other.size;
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i] ? other.data[i]->clone() : nullptr;
        }
    }
}

ArrayFigures::ArrayFigures(ArrayFigures&& other) noexcept
    : data(other.data), size(other.size), capacity(other.capacity) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

ArrayFigures::ArrayFigures(std::initializer_list<Figure*> list)
    : data(nullptr), size(0), capacity(0) {
    if (!list.size()) return;
    capacity = list.size();
    data = new Figure*[capacity]();
    for (auto* f : list) {
        push(f);  // берём владение над указателями из списка
    }
}

ArrayFigures::~ArrayFigures() {
    for (size_t i = 0; i < size; ++i) delete data[i];
    delete[] data;
}

ArrayFigures& ArrayFigures::operator=(const ArrayFigures& other) {
    if (this == &other) return *this;
    // простая реализация: сначала очистим текущие ресурсы
    for (size_t i = 0; i < size; ++i) delete data[i];
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;

    if (other.size) {
        data = new Figure*[other.size]();
        capacity = other.size;
        size = other.size;
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i] ? other.data[i]->clone() : nullptr;
        }
    }
    return *this;
}

ArrayFigures& ArrayFigures::operator=(ArrayFigures&& other) noexcept {
    if (this == &other) return *this;
    for (size_t i = 0; i < size; ++i) delete data[i];
    delete[] data;

    data = other.data;
    size = other.size;
    capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
    return *this;
}

Figure*& ArrayFigures::operator[](size_t ind) {
    if (ind >= size) throw std::out_of_range("index out of range");
    return data[ind];
}

const Figure* ArrayFigures::operator[](size_t ind) const {
    if (ind >= size) throw std::out_of_range("index out of range");
    return data[ind];
}

void ArrayFigures::push(Figure* figure) {
    if (size >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = figure;  // берём владение
}

void ArrayFigures::remove(size_t ind) {
    if (ind >= size) throw std::out_of_range("index out of range");
    delete data[ind];
    for (size_t i = ind + 1; i < size; ++i) data[i - 1] = data[i];
    --size;
    data[size] = nullptr;
}

size_t ArrayFigures::getSize() const { return size; }

size_t ArrayFigures::getCap() const { return capacity; }

bool ArrayFigures::isEmpty() const { return size == 0; }

double ArrayFigures::totalArea() const {
    double res = 0.0;
    for (size_t i = 0; i < size; ++i) {
        if (data[i]) res += static_cast<double>(*data[i]);
    }
    return res;
}
