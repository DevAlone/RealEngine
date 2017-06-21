#include "GLSLTesselationEvaluationShader.h"

#include "GL/glew.h"

namespace engine {
namespace modules {
    namespace opengl {

        GLSLTesselationEvaluationShader::GLSLTesselationEvaluationShader(const std::string& sourceCode, GLSL_SHADER_VERSION version, GLSL_OPENGL_MODE mode)
            : GLSLShader(sourceCode, version, mode)
        {
        }

        void GLSLTesselationEvaluationShader::init()
        {
            type = GLSL_SHADER_TYPE(GL_TESS_EVALUATION_SHADER);
            GLSLShader::init();
        }
    }
}
}
