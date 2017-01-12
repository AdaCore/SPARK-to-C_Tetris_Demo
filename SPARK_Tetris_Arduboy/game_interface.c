#include "game_interface.h"

extern void clear_screen(void);
extern void update_screen(void);
extern void game_over(void);
extern void set_screen_pixel(integer x, integer y);
extern void delay_ms(interfaces__unsigned_32 ms);
extern void display_score(interfaces__unsigned_32 score, interfaces__unsigned_32 level);
extern integer button_right_pressed(void);
extern integer button_turn_pressed(void);
extern integer button_left_pressed(void);
extern integer button_down_pressed(void);
void game_interface__clear_screen(void) {
  clear_screen();
  return;
}
void game_interface__update_screen(void) {
  update_screen();
  return;
}
void game_interface__set_screen_pixel(integer x, integer y) {
  set_screen_pixel(x, y);
  return;
}
void game_interface__display_score(interfaces__unsigned_32 score, interfaces__unsigned_32 level) {
  display_score(score, level);
  return;
}
void game_interface__delay_ms(interfaces__unsigned_32 ms) {
  delay_ms(ms);
  return;
}
void game_interface__game_over(void) {
  game_over();
  return;
}
integer game_interface__button_right_pressed(void) {
  return (button_right_pressed());
}
integer game_interface__button_turn_pressed(void) {
  return (button_turn_pressed());
}
integer game_interface__button_left_pressed(void) {
  return (button_left_pressed());
}
integer game_interface__button_down_pressed(void) {
  return (button_down_pressed());
}

