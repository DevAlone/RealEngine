#include "UnableToDetermineWorkerType.h"

namespace engine {
namespace exceptions {
    UnableToDetermineWorkerType::UnableToDetermineWorkerType(WORKER_TYPE type, const std::string& message)
        : logic_error(message)
    {
    }
}
}
