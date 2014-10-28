#!/usr/bin/env python
import mapnik

# Create a Map
m = mapnik.Map(600, 300)
m.background = mapnik.Color('steelblue')

# Create a Style
# create the Styles which determines how the data is rendered
s = mapnik.Style()
r = mapnik.Rule()

polygon_symbolizer = mapnik.PolygonSymbolizer(mapnik.Color('#f2eff9'))
r.symbols.append(polygon_symbolizer)

line_symbolizer = mapnik.LineSymbolizer(mapnik.Color('rgb(50%,50%,50%)'), 0.1)
r.symbols.append(line_symbolizer)

s.rules.append(r)

# add the Style to Map
m.append_style('My Style', s)

# Create a Datasource
ds = mapnik.Shapefile(file='ne_110m_admin_0_countries.shp')
# ds.envelope()

# Create a Layer
layer = mapnik.Layer('world')
layer.datasource = ds
layer.styles.append('My Style')

# Prepare the Map for rendering
m.layers.append(layer)
m.zoom_all()

# Render the Map
mapnik.render_to_file(m, 'world.png', 'png')
print "render image to 'world.png'"
