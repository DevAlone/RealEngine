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

#include "ModuleUniquePtr.hpp"
#include "forwards.h"

#include <memory>

namespace engine {

template <typename T>
class ModuleUniquePtrHelper {
    friend class Core;
    friend class ModuleWeakPtr<T>;

    template <typename U>
    friend class ModuleUniquePtrHelper;

public:
    ModuleUniquePtrHelper(const ModuleUniquePtrHelper& obj) = delete;
    ModuleUniquePtrHelper operator=(const T& obj) = delete;
    ModuleUniquePtrHelper operator=(const T&& obj) = delete;

    virtual ~ModuleUniquePtrHelper()
    {
    }

    ModuleUniquePtrHelper()
        : moduleUniquePtr(nullptr)
    {
    }
    ModuleUniquePtrHelper(ModuleUniquePtr<T>* moduleUniquePtr)
        : moduleUniquePtr(moduleUniquePtr)
    {
    }
    template <typename U>
    ModuleUniquePtrHelper(ModuleUniquePtrHelper<U>&& obj)
        : moduleUniquePtr(obj.moduleUniquePtr)
    {
    }
    //    template <typename U>
    //    ModuleUniquePtrHelper(ModuleUniquePtr<U>* moduleUniquePtr)
    //        : moduleUniquePtr(moduleUniquePtr)
    //    {
    //    }

private:
    ModuleUniquePtr<T>* moduleUniquePtr;
    bool isValid() const
    {
        return moduleUniquePtr != nullptr && moduleUniquePtr->isValid();
    }
};
}
