#include <pebble.h>

#include "T3Window.h"

Window *my_window;
TextLayer *text_layer;
T3Window * myT3Window;

const char MY_KEYBOARD_LAYOUT[] =
    "abc\0"  "def\0"  "ghi\0"
    "jkl\0"  "mno\0"  "pqr\0"
    "stu\0"  "vwx\0"  "yz ";
const char * myKeyboardSet[] = {MY_KEYBOARD_LAYOUT};

void myCloseHandler(const char * text) {
    // Do something
}

void handle_init(void) {
  myT3Window = t3window_create(
    myKeyboardSet, 2,
    myKeyboardSet, 1,
    myKeyboardSet, 2,
    (T3CloseHandler)myCloseHandler);
  
  t3window_show(myT3Window, true);
  
  //my_window = window_create();

  //text_layer = text_layer_create(GRect(0, 0, 144, 20));
  //window_stack_push(my_window, true);
}

void handle_deinit(void) {
  t3window_destroy(myT3Window);
  //text_layer_destroy(text_layer);
  //window_destroy(my_window);
}

int main(void) {
  handle_init();
  app_event_loop();
  handle_deinit();
}
