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

#include "ModuleUniquePtrHelper.hpp"
#include "forwards.h"

#include <memory>

namespace engine {

template <typename T>
class ModuleWeakPtr {
    friend class Core;

public:
    T* get() const
    {
        return helper->moduleUniquePtr->get();
    }
    T* operator->() const
    {
        return helper->moduleUniquePtr->get();
    }
    T& operator*() const
    {
        return *helper->moduleUniquePtr->get();
    }

    bool isValid() const
    {
        return helper->isValid();
    }
    operator bool() const
    {
        return isValid();
    }

private:
    ModuleWeakPtr(ModuleUniquePtrHelper<T>& helper)
        : helper(helper)
    {
    }
    //    template <typename U>
    //    ModuleWeakPtr(ModuleUniquePtrHelper<U>& helper)
    //        : helper(helper)
    //    {
    //    }
    ModuleUniquePtrHelper<T>& helper;
};
}
