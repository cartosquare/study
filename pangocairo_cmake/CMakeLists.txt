cmake_minimum_required(VERSION 2.8)

project(cairo_pango_test)

include_directories(
/usr/local/include/pango-1.0
/usr/local/include/glib-2.0
/usr/local/lib/glib-2.0/include
/usr/local/include/cairo
  )

add_executable(cairo_pango_test hello.c)
target_link_libraries(cairo_pango_test cairo pango-1.0 pangocairo-1.0 gobject-2.0 glib-2.0)