#pragma once

#include "exceptions/includes.h"
#include "forwards.h"
#include "includes.h"

#include <memory>
#include <vector>

namespace engine {
namespace modules {
    namespace opengl {
        class GLSLProgram {
        public:
            GLSLProgram();
            ~GLSLProgram();
            void init();
            void attachShader(std::shared_ptr<GLSLShader> shader);
            void link();

            int getId() const;

        private:
            int id;
            bool _isCreated = false;
            std::vector<std::shared_ptr<GLSLShader>> shaders;
        };
    }
}
}
