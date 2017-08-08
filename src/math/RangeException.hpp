#pragma once

#include "MathException.hpp"
namespace math {
class RangeException : public MathException {
public:
    RangeException(const std::string& message)
        : MathException(message)
    {
    }
};
}
