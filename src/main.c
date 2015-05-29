#include <pebble.h>
#include "watchface.h"

void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time(tick_time);
}

void init(void){
  show_watchface();
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

void deinit(void){
  hide_watchface();
  tick_timer_service_unsubscribe();
}

int main(void){
  init();
  app_event_loop();
  deinit();
}