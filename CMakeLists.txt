cmake_minimum_required(VERSION 3.22)

project(SDLExample)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# Use vendored libs
set(SDLTTF_VENDORED ON)

# 添加子目录中的 SDL
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/externals/SDL3" EXCLUDE_FROM_ALL)

# This assumes the SDL_image source is available in vendored/SDL_image
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/externals/SDL3_image" EXCLUDE_FROM_ALL)

# This assumes the SDL_ttf source is available in vendored/SDL3_mixer
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/externals/SDL3_mixer" EXCLUDE_FROM_ALL)

# This assumes the SDL_ttf source is available in vendored/SDL_ttf
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/externals/SDL3_ttf" EXCLUDE_FROM_ALL)

# # 查找 SDL3 包
# find_package(SDL3 REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/SDL3/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/SDL3_image/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/SDL3_mixer/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/SDL3_ttf/include")
# 添加可执行文件
add_executable(SDLExample main.cpp )

# 链接 SDL3 库
target_link_libraries(SDLExample PRIVATE SDL3::SDL3 SDL3_image::SDL3_image SDL3_mixer::SDL3_mixer SDL3_ttf::SDL3_ttf)