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


#include "GLSLProgram.h"

namespace engine {
namespace modules {
    namespace opengl {
        GLSLProgram::GLSLProgram()
        {
        }

        GLSLProgram::~GLSLProgram()
        {
            if (_isCreated)
                glDeleteProgram(id);
        }

        void GLSLProgram::init()
        {
            //  TODO: может стоит убрать init методы здесь и в шейдерах
            id = glCreateProgram();
            _isCreated = true;
        }

        void GLSLProgram::attachShader(std::shared_ptr<GLSLShader> shader)
        {
            shaders.push_back(shader);
            glAttachShader(id, shader->getId());
        }

        void GLSLProgram::link()
        {
            glLinkProgram(id);

            GLint isSuccess;
            char infoLog[512];
            glGetProgramiv(id, GL_LINK_STATUS, &isSuccess);
            if (!isSuccess) {
                glGetProgramInfoLog(id, 512, nullptr, infoLog);
                throw exceptions::UnableToLinkGLSLProgram(this, infoLog);
            }
        }

        int GLSLProgram::getId() const
        {
            return id;
        }
    }
}
}
