cmake_minimum_required(VERSION 2.8)

project(cairo_pango_test)

include(FindPangoCairo.cmake)

include_directories(${PANGO_CAIRO_INCLUDES})

add_executable(list_font list_font.c)
add_executable(cairo_pango_test hello.c)

target_link_libraries(list_font ${PANGO_CAIRO_LIBRARIES})
target_link_libraries(cairo_pango_test ${PANGO_CAIRO_LIBRARIES})
