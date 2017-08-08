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

    // implementation of general vector methods

    // unary
    Vector<T, D>& operator+() const;
    Vector<T, D> operator-() const&;
    Vector<T, D>& operator-() &&;
    // binary
    Vector<T, D>& operator+=(const Vector<T, D>& right);
    Vector<T, D>& operator-=(const Vector<T, D>& right);

    Vector<T, D>& operator*=(const T& right);
    Vector<T, D>& operator/=(const T& right);

    template <typename FT, size_t FD>
    friend Vector<FT, FD> operator+(const Vector<FT, FD>& left, const Vector<FT, FD>& right);

    template <typename FT, size_t FD>
    friend Vector<FT, FD> operator-(const Vector<FT, FD>& left, const Vector<FT, FD>& right);

    template <typename FT, size_t FD>
    friend Vector<FT, FD> operator*(const Vector<FT, FD>& left, const FT& right);

    template <typename FT, size_t FD>
    friend Vector<FT, FD> operator*(const FT& left, const Vector<FT, FD>& right);

    template <typename FT, size_t FD>
    friend Vector<FT, FD> operator/(const Vector<FT, FD>& left, const FT& right);

    template <typename FT, size_t FD>
    friend Vector<FT, FD> operator/(const FT& left, const Vector<FT, FD>& right);
};
//unary
template <typename T, size_t D>
Vector<T, D>& Vector<T, D>::operator+() const
{
    return *this;
}
template <typename T, size_t D>
Vector<T, D> Vector<T, D>::operator-() const&
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
template <typename T, size_t D>
Vector<T, D>& Vector<T, D>::operator+=(const Vector<T, D>& right)
{
    for (size_t i = 0; i < D; ++i)
        BaseVector<T, D>::data[i] += right.data[i];

    return *this;
}

template <typename T, size_t D>
Vector<T, D>& Vector<T, D>::operator-=(const Vector<T, D>& right)
{
    for (size_t i = 0; i < D; ++i)
        BaseVector<T, D>::data[i] -= right.data[i];

    return *this;
}

template <typename T, size_t D>
Vector<T, D>& Vector<T, D>::operator*=(const T& right)
{
    for (size_t i = 0; i < D; ++i)
        BaseVector<T, D>::data[i] *= right;

    return *this;
}

template <typename T, size_t D>
Vector<T, D>& Vector<T, D>::operator/=(const T& right)
{
    for (size_t i = 0; i < D; ++i)
        BaseVector<T, D>::data[i] /= right;

    return *this;
}

template <typename T, size_t D>
Vector<T, D> operator+(const Vector<T, D>& left, const Vector<T, D>& right)
{
    Vector<T, D> result;

    for (size_t i = 0; i < D; ++i)
        result.data[i] = left.data[i] + right.data[i];

    return result;
}

template <typename T, size_t D>
Vector<T, D> operator-(const Vector<T, D>& left, const Vector<T, D>& right)
{
    Vector<T, D> result;

    for (size_t i = 0; i < D; ++i)
        result.data[i] = left.data[i] - right.data[i];

    return result;
}

template <typename FT, size_t FD>
Vector<FT, FD> operator*(const Vector<FT, FD>& left, const FT& right)
{
    Vector<FT, FD> result;

    for (size_t i = 0; i < FD; ++i)
        result.data[i] = left.data[i] * right;

    return result;
}

template <typename FT, size_t FD>
Vector<FT, FD> operator*(const FT& left, const Vector<FT, FD>& right)
{
    return operator*(right, left);
}

template <typename FT, size_t FD>
Vector<FT, FD> operator/(const Vector<FT, FD>& left, const FT& right)
{
    Vector<FT, FD> result;

    for (size_t i = 0; i < FD; ++i)
        result.data[i] = left.data[i] / right;

    return result;
}

template <typename FT, size_t FD>
Vector<FT, FD> operator/(const FT& left, const Vector<FT, FD>& right)
{
    return operator*(right, left);
}
}
