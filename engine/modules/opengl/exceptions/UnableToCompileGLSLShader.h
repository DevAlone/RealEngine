#pragma once

#include "engine/modules/opengl/forwards.h"

#include <exception>
#include <stdexcept>
#include <string>

namespace engine {
namespace modules {
    namespace opengl {
        namespace exceptions {
            class UnableToCompileGLSLShader : public std::logic_error {
            public:
                UnableToCompileGLSLShader(const GLSLShader* const shader, const std::string& message);

                const GLSLShader* const shader;
            };
        }
    }
}
}
