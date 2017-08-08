#pragma once

#include "MathException.hpp"
#include "RangeException.hpp"

#include <initializer_list>
#include <type_traits>

namespace math {
template <typename T, size_t D>
class BaseVector {
    static_assert(std::is_arithmetic<T>::value, "Vector can only contains built-in arithmetic types");

public:
    using DataArray = T[D];

    BaseVector()
    {
    }
    BaseVector(const BaseVector<T, D>& other)
    {
        std::copy(other.data, other.data + D, this->data);
    }
    BaseVector(const BaseVector<T, D>&& other)
    {
        std::copy(other.data, other.data + D, this->data);
    }
    BaseVector& operator=(const BaseVector<T, D>& other)
    {
        std::copy(other.data, other.data + D, this->data);
        return *this;
    }
    BaseVector& operator=(const BaseVector<T, D>&& other)
    {
        std::copy(other.data, other.data + D, this->data);
        return *this;
    }

    BaseVector(const DataArray& data)
    {
        std::copy(data, data + D, this->data);
    }
    BaseVector(std::initializer_list<T> list)
    {
        if (list.size() != D)
            throw MathException("Size of initializer list must be equal to size of vector");

        std::copy(list.begin(), list.end(), this->data);
    }
    BaseVector(const T& value)
    {
        std::fill(data, data + D, value);
    }

    virtual ~BaseVector()
    {
    }

    inline const DataArray& getData() const noexcept
    {
        return data;
    }
    inline void setData(const DataArray& data)
    {
        std::copy(data, data + D, this->data);
    }
    inline const T& operator[](size_t index) const noexcept
    {
        return data[index];
    }
    inline const T& at(size_t index) const
    {
        if (index >= D)
            throw RangeException("index is out of range");

        return data[index];
    }

protected:
    T data[D];
};
}
