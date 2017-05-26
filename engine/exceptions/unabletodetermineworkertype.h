#ifndef UNABLETODETERMINEWORKERTYPE_H
#define UNABLETODETERMINEWORKERTYPE_H

#include <exception>
#include <string>

#include "../engine.i"

namespace engine {

namespace exceptions {
    class UnableToDetermineWorkerType : public std::logic_error {
    public:
        UnableToDetermineWorkerType(WORKER_TYPE type, const std::string& message = "");
    };
}
}

#endif // UNABLETODETERMINEWORKERTYPE_H
