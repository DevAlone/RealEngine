#pragma once

#include "GLSLShader.h"

#include <string>

namespace engine {
namespace modules {
    namespace opengl {
        class GLSLTesselationControlShader : public GLSLShader {
        public:
            GLSLTesselationControlShader(const std::string& sourceCode, GLSL_SHADER_VERSION version, GLSL_OPENGL_MODE mode = GLSL_OPENGL_MODE::CORE);

            virtual void init();

            virtual void compile()
            {
                // TODO: remove it
                GLSLShader::compile();
            }
        };
    }
}
}
