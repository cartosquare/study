#include <iostream>
#include "SkBitmap.h"
#include "SkPaint.h"
#include "SkCanvas.h"
#include "SkTypeface.h"
#include "SkImageEncoder.h"

#define WIDTH 256
#define HEIGHT 256
const char* text = "中非德国";

int main(int argc, char **argv) {
    // Specify saving file name
    if (argc != 2) {
        std::cout << ("Usage: skiasimple OUTPUT_FILENAME\n");
        return 1;
    }
    char* filename = argv[1];
    
    // Create bitmap
    SkBitmap bitmap;
    SkImageInfo image_info = SkImageInfo::MakeN32Premul(WIDTH, HEIGHT);
    bitmap.allocPixels(image_info);
    
    // Canvas
    SkCanvas canvas(bitmap);
    canvas.clear(SK_ColorBLACK);
    
    // Paint
    SkPaint paint;
    paint.setAntiAlias(true);
    paint.setSubpixelText(true);
    paint.setHinting(SkPaint::kSlight_Hinting);
    SkTypeface *typeface = SkTypeface::CreateFromName("微软雅黑", SkTypeface::kNormal);
    paint.setTypeface(typeface);
    paint.setTextSize(20);
    paint.setStyle (SkPaint::kFill_Style);
    paint.setColor(SK_ColorWHITE);
    
    // Rasterize text
    paint.setTextEncoding (SkPaint::kUTF8_TextEncoding);
    int n_glyphs = paint.textToGlyphs (text, strlen(text), NULL);
    uint16_t* glyphs = new uint16_t[n_glyphs];
    paint.textToGlyphs (text, strlen(text), glyphs);
    paint.setTextEncoding (SkPaint::kGlyphID_TextEncoding);
    
    // Draw
    canvas.drawText(glyphs, n_glyphs * sizeof(uint16_t), 100, 100, paint);

    // Save
    SkImageEncoder* image_encoder = CreatePNGImageEncoder();
    bool status = image_encoder->encodeFile(filename, bitmap, 100);
    
//    bool status = SkImageEncoder::EncodeFile(filename, bitmap, SkImageEncoder::kPNG_Type, 100);
    
    if (status)
        std::cout << "Skia render file saved\n";
    else
        std::cout << "Error!\n";
    
    return 0;
}
