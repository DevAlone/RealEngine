#pragma once

#include <string>

namespace math {
class MathException {
public:
    MathException(const std::string& message)
        : message(message)
    {
    }

private:
    std::string message;
};
}
