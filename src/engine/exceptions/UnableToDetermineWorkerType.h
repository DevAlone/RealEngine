#pragma once

#include "engine/forwards.h"

#include <exception>
#include <stdexcept>
#include <string>

namespace engine {
namespace exceptions {
    class UnableToDetermineWorkerType : public std::logic_error {
    public:
        UnableToDetermineWorkerType(Worker* worker, const std::string& message = "");

    private:
        Worker* worker;
    };
}
}
