#pragma once

#include <algorithm>
#include <exception>
#include <stdexcept>
#include <type_traits>

namespace math {

template <typename T, unsigned D>
class BaseVector {
    static_assert(std::is_arithmetic<T>::value, "Vector can only contains built-in arithmetic types");

public:
    using DataArray = T[D];

    BaseVector()
    {
        for (unsigned i = 0; i < D; i++)
            data[i] = T();
    }
    virtual ~BaseVector()
    {
    }
    BaseVector(const DataArray& value) //const T (&data)[D])
    {
        //        for (unsigned i = 0; i < D; i++)
        //            this->data[i] = data[i];
        std::copy(value, value + D, data);
    }
    inline const DataArray& getData() const noexcept
    {
        return data;
    }
    inline void setData(const DataArray& value)
    {
        std::copy(value, value + D, data);
    }
    inline T& operator[](unsigned index) noexcept
    {
        return data[index];
    }
    inline T& at(unsigned index)
    {
        if (index >= D)
            throw std::out_of_range("index is out of range");

        return data[index];
    }

protected:
    T data[D];
};

template <typename T, unsigned D>
class Vector final : public BaseVector<T, D> {
public:
    Vector()
        : BaseVector<T, D>()
    {
    }

    Vector(const typename BaseVector<T, D>::DataArray& value)
        : BaseVector<T, D>(value)
    {
    }

    // TODO: implementation of general vector methods
};
}
