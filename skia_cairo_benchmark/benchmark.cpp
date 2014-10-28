// standard header
#include <iostream>

// Skia
#include "SkBitmap.h"
#include "SkPaint.h"
#include "SkCanvas.h"
#include "SkTypeface.h"
#include "SkImageEncoder.h"

// pangocairo
#include "pango/pangocairo.h"

// cairo

// Image size
#define WIDTH 256
#define HEIGHT 256

// pango font define
#define FONT "Weibei TC,Normal,14px"

// Text to draw
const char* text = "中非德国";

// file to save
char* filename = "cairo_vs_skia.png";

// cairo objects
cairo_t* cr;
cairo_surface_t* surface;

// skia object
SkBitmap bitmap;

// Drawing methos
void cairo_draw();
void skia_draw();
void cairo_surface_to_skia_bitmap(cairo_surface_t* surface, SkBitmap& bitmap);

// Saving to png
void save_skia_bitmap();

int main(int argc, char **argv) {
    // Specify saving file name
    if (argc != 2) {
        std::cout << ("Usage: skiasimple OUTPUT_FILENAME\n");
        return 1;
    }
    filename = argv[1];

    // drawing
    cairo_draw();
   // cairo_surface_write_to_png (surface, "test_cairo.png");
    
    cairo_surface_to_skia_bitmap(surface, bitmap);
    
    skia_draw();
    
    // saving
    save_skia_bitmap();

    cairo_destroy (cr);
    cairo_surface_destroy (surface);
    
    return 0;
}

void cairo_draw() {
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
    cr = cairo_create(surface);

    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
    cairo_paint(cr);

    cairo_font_options_t* font_options = cairo_font_options_create();
    cairo_font_options_set_antialias(font_options, CAIRO_ANTIALIAS_BEST);
    cairo_font_options_set_hint_style(font_options, CAIRO_HINT_STYLE_SLIGHT);

    // draw text
    PangoFontMap* font_map;
    PangoContext* pango_context;
    PangoLayout* layout;
    PangoFontDescription* desc;
    int width, height;

    // get default font map
    font_map = pango_cairo_font_map_get_default();
    // create pango context
    pango_context = pango_font_map_create_context(font_map);
    
    cairo_translate(cr, WIDTH / 2, HEIGHT / 2);
    layout = pango_cairo_create_layout(cr);
    pango_cairo_context_set_font_options(pango_context, font_options);
    
    pango_layout_set_text(layout, text, -1);
    desc = pango_font_description_from_string(FONT);
    pango_layout_set_font_description(layout, desc);
    pango_font_description_free(desc);

    cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
    pango_cairo_update_layout(cr, layout);
    pango_layout_get_size(layout, &width, &height);
    cairo_move_to(cr, -((double)width / PANGO_SCALE) / 2, -50 - ((double)height / PANGO_SCALE) / 2);
    
    
    pango_cairo_show_layout(cr, layout);

    g_object_unref(layout);

}

void skia_draw() {
    // Canvas
    SkCanvas canvas(bitmap);

    // Paint
    SkPaint paint;
    paint.setAntiAlias(true);
    paint.setSubpixelText(false);
    paint.setHinting(SkPaint::kFull_Hinting);
    SkTypeface *typeface = SkTypeface::CreateFromName("Harrington", SkTypeface::kNormal);
    paint.setTypeface(typeface);
    paint.setTextSize(14);
    paint.setStyle(SkPaint::kFill_Style);
    paint.setColor(SK_ColorWHITE);

    // Rasterize text
    paint.setTextEncoding (SkPaint::kUTF8_TextEncoding);
    int n_glyphs = paint.textToGlyphs (text, strlen(text), NULL);
    uint16_t* glyphs = new uint16_t[n_glyphs];
    paint.textToGlyphs(text, strlen(text), glyphs);
    paint.setTextEncoding(SkPaint::kGlyphID_TextEncoding);
    paint.setTextAlign(SkPaint::kCenter_Align);
    
    // Draw
    canvas.drawText(glyphs, n_glyphs * sizeof(uint16_t), WIDTH / 2, HEIGHT / 2 + 50, paint);
}

void save_skia_bitmap() {
    SkImageEncoder* image_encoder = CreatePNGImageEncoder();
    bool status = image_encoder->encodeFile(filename, bitmap, 100);
    if (status)
        std::cout << "Skia render file saved\n";
    else
        std::cout << "Error!\n";
}

void cairo_surface_to_skia_bitmap(cairo_surface_t* surface, SkBitmap& bitmap) {
    int width = cairo_image_surface_get_width(surface);
    int height = cairo_image_surface_get_height(surface);
    unsigned char* data = cairo_image_surface_get_data(surface);
    
    SkImageInfo image_info = SkImageInfo::MakeN32Premul(width, height);
    bitmap.allocPixels(image_info);
    bitmap.setPixels(data);
}
