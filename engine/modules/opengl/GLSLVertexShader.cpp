#include "GLSLVertexShader.h"

#include "GL/glew.h"

namespace engine {
namespace modules {
    namespace opengl {

        GLSLVertexShader::GLSLVertexShader(const std::string& sourceCode, GLSL_SHADER_VERSION version, GLSL_SHADER_TYPE type)
            : GLSLShader(sourceCode, version, type)
        {
        }

        void GLSLVertexShader::init()
        {
            GLSLShader::init();
            id = glCreateShader(GL_VERTEX_SHADER);

            char* shaderCodeArray = new char[sourceCode.size() + 1];
            std::copy(sourceCode.begin(), sourceCode.end(), shaderCodeArray);
            shaderCodeArray[sourceCode.size()] = '\0';

            glShaderSource(id, 1, &shaderCodeArray, nullptr);

            delete[] shaderCodeArray;
        }
    }
}
}
