#include "GLSLFragmentShader.h"

#include "GL/glew.h"

namespace engine {
namespace modules {
    namespace opengl {

        GLSLFragmentShader::GLSLFragmentShader(const std::string& sourceCode, GLSL_SHADER_VERSION version, GLSL_OPENGL_MODE mode)
            : GLSLShader(sourceCode, version, mode)
        {
        }

        void GLSLFragmentShader::init()
        {
            type = GLSL_SHADER_TYPE(GL_FRAGMENT_SHADER);
            GLSLShader::init();
        }
    }
}
}
