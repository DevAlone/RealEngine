#pragma once

#include "BaseVector.hpp"

#include <algorithm>
#include <initializer_list>

#include <iostream>

namespace math {

template <typename T, size_t D>
class Vector final : public BaseVector<T, D> {
public:
    //    template <typename... Args>
    //    Vector(Args... args)
    //        : BaseVector<T, D>(args...)
    //    {
    //    }
    Vector() {}
    Vector(const Vector<T, D>& other)
        : BaseVector<T, D>(other)
    {
    }
    Vector(const Vector<T, D>&& other)
        : BaseVector<T, D>(other)
    {
    }
    Vector& operator=(const Vector<T, D>& other)
    {
        BaseVector<T, D>::operator=(other);
        return *this;
    }
    Vector& operator=(const Vector<T, D>&& other)
    {
        BaseVector<T, D>::operator=(other);
        return *this;
    }

    Vector(const typename BaseVector<T, D>::DataArray& value)
        : BaseVector<T, D>(value)
    {
    }

    Vector(std::initializer_list<T> list)
        : BaseVector<T, D>(list)
    {
    }

    Vector(const T& value)
        : BaseVector<T, D>(value)
    {
    }

    // TODO: implementation of general vector methods

    // unary
    Vector<T, D>& operator+();
    Vector<T, D> operator-() &;
    Vector<T, D>& operator-() &&;
    // binary
    template <typename FT, size_t FD>
    friend Vector<FT, FD> operator+(const Vector<FT, FD>& left, const Vector<FT, FD>& right);
    template <typename FT, size_t FD>
    friend Vector<FT, FD>&& operator+(const Vector<FT, FD>& left, Vector<FT, FD>&& right);
    template <typename FT, size_t FD>
    friend Vector<FT, FD>&& operator+(Vector<FT, FD>&& left, const Vector<FT, FD>& right);

    //    Vector<T, D> operator+(const Vector<T, D>& right);
    //    Vector<T, D> operator+(const Vector<T, D>& right) const&;
    //    Vector<T, D>& operator+(Vector<T, D>&& right) const&;
    //    Vector<T, D>&& operator+(const Vector<T, D>& right) &&;
};
//unary
template <typename T, size_t D>
Vector<T, D>& Vector<T, D>::operator+()
{
    return *this;
}
template <typename T, size_t D>
Vector<T, D> Vector<T, D>::operator-() &
{
    Vector<T, D> result = *this;
    for (auto& value : result.data)
        value = -value;

    return result;
}
template <typename T, size_t D>
Vector<T, D>& Vector<T, D>::operator-() &&
{
    for (size_t i = 0; i < D; ++i)
        BaseVector<T, D>::data[i] = -BaseVector<T, D>::data[i];

    return *this;
}

// binary
//template <typename T, size_t D>
//Vector<T, D> Vector<T, D>::operator+(const Vector<T, D>& right) const&
//{
//    Vector<T, D> result;

//    for (size_t i = 0; i < D; ++i)
//        result.data[i] = BaseVector<T, D>::data[i] + right.data[i];

//    return result;
//}

template <typename T, size_t D>
Vector<T, D> operator+(const Vector<T, D>& left, const Vector<T, D>& right)
{
    std::cout << "operator+(&, &)" << std::endl;
    Vector<T, D> result;

    for (size_t i = 0; i < D; ++i)
        result.data[i] = left.data[i] + right.data[i];

    return result;
}

template <typename T, size_t D>
Vector<T, D>&& operator+(const Vector<T, D>& left, Vector<T, D>&& right)
{
    std::cout << "operator+(&, &&)" << std::endl;
    for (size_t i = 0; i < D; ++i)
        right.data[i] += left.data[i];

    return std::move(right);
}

template <typename T, size_t D>
Vector<T, D>&& operator+(Vector<T, D>&& left, const Vector<T, D>& right)
{
    std::cout << "operator+(&&, &)" << std::endl;
    for (size_t i = 0; i < D; ++i)
        left.data[i] += right.data[i];

    return std::move(left);
}
}
