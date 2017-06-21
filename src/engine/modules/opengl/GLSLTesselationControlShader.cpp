#include "GLSLTesselationControlShader.h"

#include "GL/glew.h"

namespace engine {
namespace modules {
    namespace opengl {

        GLSLTesselationControlShader::GLSLTesselationControlShader(const std::string& sourceCode, GLSL_SHADER_VERSION version, GLSL_OPENGL_MODE mode)
            : GLSLShader(sourceCode, version, mode)
        {
        }

        void GLSLTesselationControlShader::init()
        {
            type = GLSL_SHADER_TYPE(GL_TESS_CONTROL_SHADER);
            GLSLShader::init();
        }
    }
}
}
