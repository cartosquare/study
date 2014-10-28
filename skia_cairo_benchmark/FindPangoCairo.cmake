set(PANGO_CAIRO_INCLUDES
/usr/local/include/pango-1.0
/usr/local/include/glib-2.0
/usr/local/lib/glib-2.0/include
/usr/local/include/cairo
  )

set(PANGO_CAIRO_LIBRARIES
  cairo pango-1.0
  pangocairo-1.0
  gobject-2.0
  glib-2.0
  )

message(STATUS "PANGO_cairo_includes:${PANGO_CAIRO_INCLUDES}")
message(STATUS "PANGO_cairo_libraries:${PANGO_CAIRO_LIBRARIES}")
