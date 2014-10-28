cmake_minimum_required(VERSION 2.8)

project(skia_test)

include(FindSkia.cmake)

include_directories(${SKIA_INCLUDE_DIRS})

add_executable(skia_test hello.cpp)

target_link_libraries(skia_test ${SKIA_LIBRARIES})

#"-framework CoreFoundation" "-framework CoreGraphics" "-framework OpenGL" 