#include <pebble.h>

#include "T3Window.h"

Window *my_window;
TextLayer *text_layer;
T3Window * myT3Window;

const char * keyboardSet1[] = {T3_LAYOUT_LOWERCASE, T3_LAYOUT_UPPERCASE};
const char * keyboardSet2[] = {T3_LAYOUT_NUMBERS};
const char * keyboardSet3[] = {T3_LAYOUT_PUNC, T3_LAYOUT_BRACKETS};

void myCloseHandler(const char * text) {
    // Do something
}

void handle_init(void) {
  myT3Window = t3window_create(
    keyboardSet1, 2,
    keyboardSet2, 1,
    keyboardSet3, 2,
    (T3CloseHandler)myCloseHandler);
  T3_SET_THEME_BLUE(myT3Window);
  
  t3window_show(myT3Window, true);
  
}

void handle_deinit(void) {
  t3window_destroy(myT3Window);
}

int main(void) {
  handle_init();
  app_event_loop();
  handle_deinit();
}
