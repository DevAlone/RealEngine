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

#include "forwards.h"

#include <memory>

namespace engine {

template <typename T>
class ModuleUniquePtr {
    template <typename U>
    friend class ModuleUniquePtr;
    friend class Core;

public:
    ModuleUniquePtr(T* module)
        : module(module)
    {
    }

    ModuleUniquePtr(ModuleUniquePtr& obj) = delete;
    ModuleUniquePtr(ModuleUniquePtr<T>&& obj)
    {
        module = obj.module;
        obj.module = nullptr;
    }
    template <typename U>
    ModuleUniquePtr(ModuleUniquePtr<U>&& obj)
    {
        module = obj.module;
        obj.module = nullptr;
    }

    ModuleUniquePtr operator=(const ModuleUniquePtr& obj) = delete;
    ModuleUniquePtr operator=(const ModuleUniquePtr&& obj) = delete;

    virtual ~ModuleUniquePtr()
    {
        if (module)
            delete module;
    }

    T* get() const
    {
        return module;
    }

    bool isValid() const
    {
        return module != nullptr;
    }
    operator bool() const
    {
        return isValid();
    }
    T* operator->()
    {
        return module;
    }
    T& operator*()
    {
        return *module;
    }

private:
    T* module;
};
}
