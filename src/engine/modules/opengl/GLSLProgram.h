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
