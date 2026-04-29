
#include "Module.hpp"

namespace engine {

    Module::Module(
        ModuleDef moduleDef, 
        const char *name
    ) 
    : moduleDef(moduleDef)
    , name(name) {
        ModuleRegistry::registerInstance(this);
    }

    Module::~Module() {
        ModuleRegistry::deleteInstance(this);
    }

    ModuleDef Module::getModule() const {
        return moduleDef;
    }

    const char *Module::getName() const {
        return name.c_str();
    }
}