cmake_minimum_required(VERSION 2.8)

project(benchmark)

include(FindSkia.cmake)
include(FindPangoCairo.cmake)

include_directories(${SKIA_INCLUDE_DIRS} ${PANGO_CAIRO_INCLUDES})

add_executable(benchmark benchmark.cpp)

target_link_libraries(benchmark ${SKIA_LIBRARIES} ${PANGO_CAIRO_LIBRARIES})
