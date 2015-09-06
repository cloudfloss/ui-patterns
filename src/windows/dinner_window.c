/**
 * Example implementation of the dialog choice UI pattern.
 */

#include "dinner_window.h"

static Window *s_main_window;
static TextLayer *s_label_layer;
static BitmapLayer *s_icon_layer;
static ActionBarLayer *s_action_bar_layer;

static GBitmap *s_icon_bitmap, *s_tick_bitmap, *s_cross_bitmap;

static void window_load(Window *window) {
    Layer *window_layer = window_get_root_layer(window);
    GRect bounds = layer_get_bounds(window_layer);

    s_icon_bitmap = gbitmap_create_with_resource(RESOURCE_ID_STEAK_BLACK);
    GRect bitmap_bounds = gbitmap_get_bounds(s_icon_bitmap);

    s_icon_layer = bitmap_layer_create(GRect((bounds.size.w / 2) - (bitmap_bounds.size.w / 2) - (ACTION_BAR_WIDTH / 2), 10, bitmap_bounds.size.w, bitmap_bounds.size.h));
    bitmap_layer_set_bitmap(s_icon_layer, s_icon_bitmap);
    bitmap_layer_set_compositing_mode(s_icon_layer, GCompOpSet);
    layer_add_child(window_layer, bitmap_layer_get_layer(s_icon_layer));

    s_label_layer = text_layer_create(GRect(10, 10 + bitmap_bounds.size.h + 5, 124 - ACTION_BAR_WIDTH, bounds.size.h - (10 + bitmap_bounds.size.h + 15)));
    text_layer_set_text(s_label_layer, DINNER_WINDOW_MESSAGE);
    text_layer_set_background_color(s_label_layer, GColorClear);
    text_layer_set_text_alignment(s_label_layer, GTextAlignmentCenter);
    text_layer_set_font(s_label_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
    text_layer_set_text_color(s_label_layer, GColorWhite);
    layer_add_child(window_layer, text_layer_get_layer(s_label_layer));

    s_tick_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TICK_WHITE);
    s_cross_bitmap = gbitmap_create_with_resource(RESOURCE_ID_CROSS);

    s_action_bar_layer = action_bar_layer_create();
    action_bar_layer_set_icon(s_action_bar_layer, BUTTON_ID_UP, s_tick_bitmap);
    action_bar_layer_set_icon(s_action_bar_layer, BUTTON_ID_DOWN, s_cross_bitmap);
    action_bar_layer_add_to_window(s_action_bar_layer, window);
}

static void window_unload(Window *window) {
    text_layer_destroy(s_label_layer);
    action_bar_layer_destroy(s_action_bar_layer);
    bitmap_layer_destroy(s_icon_layer);

    gbitmap_destroy(s_icon_bitmap);
    gbitmap_destroy(s_tick_bitmap);
    gbitmap_destroy(s_cross_bitmap);

    window_destroy(window);
    s_main_window = NULL;
}

void dinner_window_push() {
    if(!s_main_window) {
        s_main_window = window_create();
        window_set_background_color(s_main_window, GColorBlack);
        window_set_window_handlers(s_main_window, (WindowHandlers) {
                .load = window_load,
                .unload = window_unload,
        });
    }
    window_stack_push(s_main_window, true);
}
