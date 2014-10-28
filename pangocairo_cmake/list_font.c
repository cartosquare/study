#include <glib.h>
#include <pango/pangocairo.h>

int main() {
        PangoFontFamily** families;
        int n_families;

        PangoFontMap* fontmap = pango_cairo_font_map_get_default();
        pango_font_map_list_families(fontmap, &families, &n_families);
        printf("There are %d families\n", n_families);

        for (int i = 0; i < n_families; ++i) {
                PangoFontFamily* family = families[i];
                const char* family_name = pango_font_family_get_name(family);
                printf("Family %d: %s\n", i, family_name);
        }
        g_free(families);

        return 0;
}
