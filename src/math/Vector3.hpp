#pragma once

#include <cstdint>
#include <initializer_list>

namespace math {

template <typename T>
class Vector<T, 3> : public BaseVector<T, 3> {
public:
    template <typename... Args>
    Vector(Args... args)
        : BaseVector<T, 3>(args...)
    {
    }

    Vector(const typename BaseVector<T, 3>::DataArray& value)
        : BaseVector<T, 3>(value)
    {
    }

    Vector(std::initializer_list<T> list)
        : BaseVector<T, 3>(list)
    {
    }

    T getX() const noexcept;
    T getY() const noexcept;
    T getZ() const noexcept;

    void setX(T value) noexcept;
    void setY(T value) noexcept;
    void setZ(T value) noexcept;

    T& refX() noexcept;
    T& refY() noexcept;
    T& refZ() noexcept;
};

template <typename T>
using Vector3 = Vector<T, 3>;

using Vector3F = Vector3<float>;
using Vector3D = Vector3<double>;
using Vector3I = Vector3<int>;
using Vector3L = Vector3<long>;
using Vector3LL = Vector3<long long>;

using Vector3I8 = Vector3<int8_t>;
using Vector3I16 = Vector3<int16_t>;
using Vector3I32 = Vector3<int32_t>;
using Vector3I64 = Vector3<int64_t>;

template <typename T>
T Vector<T, 3>::getX() const noexcept
{
    return BaseVector<T, 3>::data[0];
}
template <typename T>
T Vector<T, 3>::getY() const noexcept
{
    return BaseVector<T, 3>::data[1];
}
template <typename T>
T Vector<T, 3>::getZ() const noexcept
{
    return BaseVector<T, 3>::data[2];
}

template <typename T>
void Vector<T, 3>::setX(T value) noexcept
{
    BaseVector<T, 3>::data[0] = value;
}
template <typename T>
void Vector<T, 3>::setY(T value) noexcept
{
    BaseVector<T, 3>::data[1] = value;
}
template <typename T>
void Vector<T, 3>::setZ(T value) noexcept
{
    BaseVector<T, 3>::data[2] = value;
}

template <typename T>
T& Vector<T, 3>::refX() noexcept
{
    return BaseVector<T, 3>::data[0];
}
template <typename T>
T& Vector<T, 3>::refY() noexcept
{
    return BaseVector<T, 3>::data[1];
}
template <typename T>
T& Vector<T, 3>::refZ() noexcept
{
    return BaseVector<T, 3>::data[2];
}
}
