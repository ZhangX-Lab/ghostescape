cmake_minimum_required(VERSION 3.22)

project(GhostEscape VERSION 0.1.0 LANGUAGES C CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(TARGET ${PROJECT_NAME}-${CMAKE_SYSTEM_NAME})

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

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/externals/glm" EXCLUDE_FROM_ALL)
# # 查找 SDL3 包
# find_package(SDL3 REQUIRED)

# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/SDL3/include")
# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/SDL3_image/include")
# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/SDL3_mixer/include")
# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/SDL3_ttf/include")
# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/externals/glm/glm")
# # 添加可执行文件
# 添加可执行文件
add_executable(${TARGET} 
                src/core/game.cpp
                src/core/asset_store.cpp
                src/core/object.cpp
                src/core/object_world.cpp
                src/core/object_affiliate.cpp
                src/core/scene.cpp
                src/core/actor.cpp
                src/screen/ui_mouse.cpp
                src/screen/hud_stats.cpp
                src/screen/hud_skill.cpp
                src/screen/hud_text.cpp
                src/screen/hud_button.cpp
                src/raw/stats.cpp
                src/raw/weapon.cpp
                src/raw/timer.cpp
                src/raw/bg_star.cpp
                src/world/effect.cpp
                src/world/spell.cpp
                src/affiliate/sprite.cpp
                src/affiliate/sprite_anim.cpp
                src/affiliate/collider.cpp
                src/affiliate/affiliate_bar.cpp
                src/affiliate/text_label.cpp
                src/spawner.cpp
                src/player.cpp
                src/enemy.cpp
                src/weapon_thunder.cpp
                src/main.cpp
                src/scene_title.cpp
                src/scene_main.cpp
                )

# 链接 SDL3 库
target_link_libraries(${TARGET}  PRIVATE 
                        SDL3::SDL3 
                        SDL3_image::SDL3_image 
                        SDL3_mixer::SDL3_mixer 
                        SDL3_ttf::SDL3_ttf
                        glm::glm
                    )