#include "GLSLVertexShader.h"

#include "GL/glew.h"

namespace engine {
namespace modules {
    namespace opengl {

        GLSLVertexShader::GLSLVertexShader(const std::string& sourceCode, GLSL_SHADER_VERSION version, GLSL_OPENGL_MODE mode)
            : GLSLShader(sourceCode, version, mode)
        {
        }

        void GLSLVertexShader::init()
        {
            type = GLSL_SHADER_TYPE(GL_VERTEX_SHADER);
            GLSLShader::init();
        }
    }
}
}
