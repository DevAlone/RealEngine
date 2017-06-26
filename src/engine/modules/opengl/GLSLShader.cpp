/*
Copyright 2017 Sergey Zakharov
	
Licensed under the Apache License, Version 2.0 (the License);
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0
   
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an AS IS BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/


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
