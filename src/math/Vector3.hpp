#pragma once

namespace math {

template <typename T>
class Vector<T, 3> : public BaseVector<T, 3> {
public:
    Vector()
        : BaseVector<T, 3>()
    {
    }

    Vector(const typename BaseVector<T, 3>::DataArray& value)
        : BaseVector<T, 3>(value)
    {
    }

    T getX() const noexcept
    {
        return BaseVector<T, 3>::data[0];
    }
    T getY() const noexcept
    {
        return BaseVector<T, 3>::data[1];
    }
    T getZ() const noexcept
    {
        return BaseVector<T, 3>::data[2];
    }
    void setX(T value) noexcept
    {
        BaseVector<T, 3>::data[0] = value;
    }
    void setY(T value) noexcept
    {
        BaseVector<T, 3>::data[1] = value;
    }
    void setZ(T value) noexcept
    {
        BaseVector<T, 3>::data[2] = value;
    }
    T& refX() noexcept
    {
        return BaseVector<T, 3>::data[0];
    }
    T& refY() noexcept
    {
        return BaseVector<T, 3>::data[1];
    }
    T& refZ() noexcept
    {
        return BaseVector<T, 3>::data[2];
    }
};

template <typename T>
using Vector3 = Vector<T, 3>;

using Vector3F = Vector3<float>;
using Vector3D = Vector3<double>;
using Vector3I = Vector3<int>;
}
