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
