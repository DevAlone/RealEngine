#pragma once

#include <algorithm>
#include <type_traits>

namespace math {

template <typename T, unsigned D>
class Vector final {
    static_assert(std::is_arithmetic<T>::value, "Vector can only contains built-in arithmetic types");

public:
    using DataArray = T[D];

    Vector()
    {
        for (unsigned i = 0; i < D; i++)
            data[i] = T();
    }
    Vector(const DataArray& value) //const T (&data)[D])
    {
        //        for (unsigned i = 0; i < D; i++)
        //            this->data[i] = data[i];
        std::copy(value, value + D, data);
    }
    inline const DataArray& getData() const
    {
        return data;
    }
    inline void setData(const DataArray& value)
    {
        std::copy(value, value + D, data);
    }
    inline T& operator[](unsigned index)
    {
        return data[index];
    }

private:
    T data[D];
};
}
