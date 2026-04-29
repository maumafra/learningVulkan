#pragma once

#include <string>

namespace engine {

enum ModuleDef {
    DATA,
    ECS,
    GRAPHICS,
    WINDOW,
    TIME,
    EVENT,
    KEYBOARD,
    MOUSE,
    PHYSICS,
    AUDIO,
    MODULES_SIZE
};

class Module {
public:
    Module(ModuleDef module, const char *name);
    ~Module();

    ModuleDef getModule() const;

    const char *getName() const;

private:
    ModuleDef moduleDef;
    std::string name;
};

class ModuleRegistry {
public:
    inline static Module *moduleRegistry[MODULES_SIZE] = {};

    template <typename T>
    static T *getInstance(ModuleDef module) {
        return (T*) moduleRegistry[module];
    };

    static void registerInstance(Module *instance) {
        if (instance == nullptr) {
            return;
        }
        moduleRegistry[instance->getModule()] = instance;
    };

    static void deleteInstance(Module *instance) {
        if (instance == nullptr) {
            return;
        }
        moduleRegistry[instance->getModule()] = nullptr;
    };
};

}