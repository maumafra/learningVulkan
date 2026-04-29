cmake_minimum_required(VERSION 4.0.0)

project(engine VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# v Turn this on to not use SDL as a dll
#option(BUILD_SHARED_LIBS OFF)
# v Or turn this on to use SDL as a dll
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# later change this to use only vulkan-headers (https://github.com/KhronosGroup/vulkan-headers)
# so it is not needed to have the Vulkan SDK installed
find_package(Vulkan REQUIRED)

add_library(engine_common STATIC
    src/modules/common/Module.cpp
    src/modules/common/Module.hpp
)

set(MODULES
    engine_common
)

set(VENDOR
    SDL3::SDL3
    Vulkan::Vulkan
)

include_directories(
    BEFORE
    vendor/
    src/
)

add_subdirectory(vendor/SDL3-3.4.4)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/engine.cpp)
target_link_libraries(${PROJECT_NAME} ${VENDOR} ${MODULES})