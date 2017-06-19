#include "GLSLShader.h"
#include "exceptions/includes.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <string>

namespace engine {
namespace modules {
    namespace opengl {
        GLSLShader::GLSLShader(const std::string& sourceCode, GLSL_SHADER_VERSION version, GLSL_OPENGL_MODE mode)
            : version(version)
            , mode(mode)
        {
            this->sourceCode = std::string("#version ") + std::to_string(static_cast<int>(version)) + " ";
            switch (mode) {
            case GLSL_OPENGL_MODE::CORE:
                this->sourceCode += "core\n";
                break;
            default:
                throw std::exception();
                // TODO: //
                break;
            }
            this->sourceCode += sourceCode;
            int a;
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

            id = glCreateShader(int(type));
            // TODO: todo
            char* shaderCodeArray = new char[sourceCode.size() + 1];
            std::copy(sourceCode.begin(), sourceCode.end(), shaderCodeArray);
            shaderCodeArray[sourceCode.size()] = '\0';

            glShaderSource(id, 1, &shaderCodeArray, nullptr);

            delete[] shaderCodeArray;
        }

        void GLSLShader::compile()
        {
            if (!_isInitialized)
                throw exceptions::UnableToCompileGLSLShader(this, "Shader is not initialized");

            glCompileShader(id);
            int isSuccess;
            char infoLog[512];
            glGetShaderiv(id, GL_COMPILE_STATUS, &isSuccess);
            if (!isSuccess) {
                glGetShaderInfoLog(id, 512, nullptr, infoLog);
                throw exceptions::UnableToCompileGLSLShader(this, infoLog);
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
