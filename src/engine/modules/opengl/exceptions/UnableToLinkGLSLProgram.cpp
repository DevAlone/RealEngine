#include "UnableToLinkGLSLProgram.h"

namespace engine {
namespace modules {
    namespace opengl {
        namespace exceptions {

            UnableToLinkGLSLProgram::UnableToLinkGLSLProgram(const GLSLProgram* const shader, const std::string& message)
                : std::logic_error(message)
                , program(program)
            {
            }
        }
    }
}
}
