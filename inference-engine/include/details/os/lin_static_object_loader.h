// Copyright (C) 2018-2019 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

/**
 * @brief Static loader. This allows us to merge libmyriadPlugin.so into inference engine.
 * @file lin_shared_object_loader.h
 */
#pragma once

#include <dlfcn.h>
#include <cstring>
#include "../../ie_api.h"
#include "../ie_exception.hpp"
#include "../../ie_common.h"
#ifndef MYRIAD
extern "C" void STATIC_myriad_CreatePluginEngine();
#endif

namespace InferenceEngine {
namespace details {

/**
 * @brief This class is a static wrapper for MYRIAD, the one that we use.
 */
class SharedObjectLoader {
private:
    //void *shared_object = nullptr;

public:
    /**
     * @brief Loads a library with the name specified. The library is loaded according to
     *        the POSIX rules for dlopen
     * @param pluginName Full or relative path to the library
     */
    explicit SharedObjectLoader(const char* pluginName) {
        //shared_object = dlopen(pluginName, RTLD_LAZY);

        //if (shared_object == nullptr)
        //    THROW_IE_EXCEPTION << "Cannot load library '" << pluginName << "': " << dlerror();
    }
    ~SharedObjectLoader() noexcept(false) {
        //if (0 != dlclose(shared_object)) {
        //    THROW_IE_EXCEPTION << "dlclose failed: " << dlerror();
        //}
    }

    /**
     * @brief Searches for a function symbol in the loaded module
     * @param symbolName Name of the function to find
     * @return A pointer to the function if found
     * @throws InferenceEngineException if the function is not found
     */
    void *get_symbol(const char* symbolName) const {
        #ifndef MYRIAD
        //void * procAddr = nullptr;
        //procAddr = dlsym(shared_object, symbolName);
        //if (procAddr == nullptr)
        //    THROW_IE_EXCEPTION << "dlSym cannot locate method '" << symbolName << "': " << dlerror();
        //return procAddr;
        if(strcmp(symbolName, "CreatePluginEngine")==0){
            return (void*)&STATIC_myriad_CreatePluginEngine;
        }else{
            THROW_IE_EXCEPTION << "Unknown static symbol: "<<symbolName;
            
        }
        #endif
        return 0;
    }
};

}  // namespace details
}  // namespace InferenceEngine
