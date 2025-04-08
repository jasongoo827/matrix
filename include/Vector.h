#pragma once

#include <iostream>
#include <cstddef>
#include <initializer_list>
#include <algorithm>

namespace la
{
template <typename K, std::size_t N>
struct Vector
{
    K data[N];

    Vector() = default;
    Vector(const Vector &other) = default;
    Vector(Vector &&other) = default;

    Vector(std::initializer_list<K> lst)
    {
        std::copy(lst.begin(), lst.end(), data);
    }

    Vector &operator=(std::initializer_list<K> lst)
    {
        std::copy(lst.begin(), lst.end(), data);
        return *this;
    }

    Vector &operator=(const Vector &other) = default;
    Vector &operator=(Vector &&other) = default;

    K &operator[](std::size_t index) { return data[index]; }
    const K &operator[](std::size_t index) const { return data[index]; }

    std::size_t size() const { return N; }

    void add(const Vector &other)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            data[i] += other[i];
        }
    }

    void sub(const Vector &other)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            data[i] -= other[i];
        }
    }

    void scl(const K &scalar)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            data[i] *= scalar;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector &v)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            os << v.data[i] << " ";
        }
        return os;
    }
};
}

