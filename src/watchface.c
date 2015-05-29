#include <pebble.h>
#include "watchface.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_icon;
static GFont s_res_gothic_28_bold;
static BitmapLayer *s_bitmaplayer_1;
static TextLayer *s_textlayer_1;
char *time_text;

#define MAX_SIZE 6

void update_time(struct tm *tick_time){
  strftime(time_text, MAX_SIZE, "%H:%M", tick_time);
  text_layer_set_text(s_textlayer_1, time_text);
}

static void initialise_ui(void) {
  s_window = window_create();
  time_text = malloc(MAX_SIZE);
  s_res_icon = gbitmap_create_with_resource(RESOURCE_ID_ICON);
  
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif
  
  s_res_icon = gbitmap_create_with_resource(RESOURCE_ID_ICON);
  s_res_gothic_28_bold = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(20, 5, 104, 120));
  bitmap_layer_set_bitmap(s_bitmaplayer_1, s_res_icon);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_1);
  //bitmap_layer_set_compositing_mode(s_bitmaplayer_1, GCompOpSet);
  
  // s_textlayer_1
  s_textlayer_1 = text_layer_create(GRect(20, 128, 100, 40));
  text_layer_set_text(s_textlayer_1, time_text);
  text_layer_set_font(s_textlayer_1, s_res_gothic_28_bold);
  text_layer_set_text_alignment(s_textlayer_1, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_textlayer_1);
}

static void destroy_ui(void) {
  free(time_text);
  window_destroy(s_window);
  bitmap_layer_destroy(s_bitmaplayer_1);
  text_layer_destroy(s_textlayer_1);
  gbitmap_destroy(s_res_icon);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_watchface(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_watchface(void) {
  window_stack_remove(s_window, true);
}
