#include "GLSLShader.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <string>

namespace engine {
namespace modules {
    namespace opengl {
        GLSLShader::GLSLShader(const std::string& sourceCode, GLSL_SHADER_VERSION version, GLSL_SHADER_TYPE type)
            : type(type)
            , version(version)
        {
            this->sourceCode = std::string("#version ") + std::to_string(static_cast<int>(version)) + " ";
            switch (type) {
            case GLSL_SHADER_TYPE::CORE:
                this->sourceCode += "core\n";
                break;
            default:
                throw std::exception();
                // TODO: //
                break;
            }
            this->sourceCode = sourceCode;
        }

        GLSLShader::~GLSLShader()
        {
            if (_isInitialized && !_isCleaned)
                clean();
        }

        void GLSLShader::init()
        {
            _isCleaned = false;
            _isInitialized = true;
        }

        void GLSLShader::compile()
        {
            if (!_isInitialized)
                // TODO: make special exception type
                throw std::exception();

            glCompileShader(id);
            int isSuccess;
            char infoLog[512];
            glGetShaderiv(id, GL_COMPILE_STATUS, &isSuccess);
            if (!isSuccess) {
                glGetShaderInfoLog(id, 512, nullptr, infoLog);
                //std::cerr << "error compiling shader 1" << infoLog << std::endl;
                // TODO: make exceptions
                throw std::exception();
            }

            _isCompiled = true;
        }

        void GLSLShader::clean()
        {
            glDeleteShader(id);
            _isInitialized = false;
            _isCleaned = true;
        }

        bool GLSLShader::isInitialized() const
        {
            return _isInitialized;
        }

        bool GLSLShader::isCompiled() const
        {
            return _isCompiled;
        }

        int GLSLShader::getId() const
        {
            return id;
        }
    }
}
}
