#pragma once

#include "engine/forwards.h"

#include <exception>
#include <stdexcept>
#include <string>

namespace engine {

namespace exceptions {
    class UnableToDetermineWorkerType : public std::logic_error {
    public:
        UnableToDetermineWorkerType(WORKER_TYPE type, const std::string& message = "");
    };
}
}

