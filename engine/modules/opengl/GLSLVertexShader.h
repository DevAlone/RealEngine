#pragma once

#include "GLSLShader.h"

#include <string>

namespace engine {
namespace modules {
    namespace opengl {
        class GLSLVertexShader : public GLSLShader {
        public:
            GLSLVertexShader(const std::string& sourceCode, GLSL_SHADER_VERSION version, GLSL_SHADER_TYPE type = GLSL_SHADER_TYPE::CORE);

            virtual void init();
        };
    }
}
}
