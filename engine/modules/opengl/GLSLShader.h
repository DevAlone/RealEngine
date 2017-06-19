#pragma once

#include <string>

namespace engine {
namespace modules {
    namespace opengl {
        enum class GLSL_SHADER_VERSION : int {
            GL_330 = 330,
            GL_440 = 440
        };
        enum class GLSL_OPENGL_MODE {
            CORE
        };
        enum class GLSL_SHADER_TYPE : int {
            VERTEX,
            FRAGMENT
        };

        class GLSLShader {
        public:
            GLSLShader(const std::string& sourceCode, GLSL_SHADER_VERSION version, GLSL_OPENGL_MODE mode = GLSL_OPENGL_MODE::CORE);
            ~GLSLShader();

            virtual void init();
            virtual void compile();
            virtual void clean();

            bool isInitialized() const;

            bool isCompiled() const;

            int getId() const;

        protected:
            std::string sourceCode;
            GLSL_OPENGL_MODE mode;
            GLSL_SHADER_TYPE type;
            GLSL_SHADER_VERSION version;
            bool _isInitialized = false;
            bool _isCompiled = false;
            bool _isCleaned = true;
            int id; // TODO: maybe change to GL* type
        };
    }
}
}
