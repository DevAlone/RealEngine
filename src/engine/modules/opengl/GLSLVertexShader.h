#pragma once

#include "GLSLShader.h"

#include <string>

namespace engine {
namespace modules {
    namespace opengl {
        class GLSLVertexShader : public GLSLShader {
        public:
            GLSLVertexShader(const std::string& sourceCode, GLSL_SHADER_VERSION version, GLSL_OPENGL_MODE mode = GLSL_OPENGL_MODE::CORE);

            virtual void init();
        };
    }
}
}
