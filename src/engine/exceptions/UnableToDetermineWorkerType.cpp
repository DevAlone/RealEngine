#include "UnableToDetermineWorkerType.h"

namespace engine {
namespace exceptions {
    UnableToDetermineWorkerType::UnableToDetermineWorkerType(Worker* worker, const std::string& message)
        : logic_error(message)
        , worker(worker)
    {
    }
}
}
