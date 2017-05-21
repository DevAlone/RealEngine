#ifndef UNABLETODETERMINEWORKERTYPE_H
#define UNABLETODETERMINEWORKERTYPE_H

#include <exception>
#include <string>

#include "engine/workers/workers.h"

namespace engine {
/* forward declarations */
enum class WORKER_TYPE;
/* /forward declarations */

namespace exceptions {
    class UnableToDetermineWorkerType : public std::logic_error {
    public:
        UnableToDetermineWorkerType(WORKER_TYPE type, const std::string& message = "");
    };
}
}

#endif // UNABLETODETERMINEWORKERTYPE_H
