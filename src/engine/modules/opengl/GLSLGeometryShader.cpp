#include "GLSLGeometryShader.h"

#include "GL/glew.h"

namespace engine {
namespace modules {
    namespace opengl {

        GLSLGeometryShader::GLSLGeometryShader(const std::string& sourceCode, GLSL_SHADER_VERSION version, GLSL_OPENGL_MODE mode)
            : GLSLShader(sourceCode, version, mode)
        {
        }

        void GLSLGeometryShader::init()
        {
            type = GLSL_SHADER_TYPE(GL_GEOMETRY_SHADER);
            GLSLShader::init();
        }
    }
}
}
