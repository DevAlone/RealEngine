#include "UnableToCompileGLSLShader.h"

namespace engine {
namespace modules {
    namespace opengl {
        namespace exceptions {

            UnableToCompileGLSLShader::UnableToCompileGLSLShader(const GLSLShader* const shader, const std::string& message)
                : std::logic_error(message)
                , shader(shader)
            {
            }
        }
    }
}
}
