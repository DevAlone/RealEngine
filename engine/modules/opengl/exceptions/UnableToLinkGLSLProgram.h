#pragma once

#include "engine/modules/opengl/forwards.h"

#include <exception>
#include <stdexcept>
#include <string>

namespace engine {
namespace modules {
    namespace opengl {
        namespace exceptions {
            class UnableToLinkGLSLProgram : public std::logic_error {
            public:
                UnableToLinkGLSLProgram(const GLSLProgram* const program, const std::string& message);

                const GLSLProgram* const program;
            };
        }
    }
}
}
