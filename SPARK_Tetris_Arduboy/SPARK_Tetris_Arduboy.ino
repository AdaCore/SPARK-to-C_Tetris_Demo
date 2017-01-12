/*----------------------------------------------------------------------------
--                                                                          --
--                             GNAT EXAMPLE                                 --
--                                                                          --
--                      Copyright (C) 2017, AdaCore                         --
--                                                                          --
-- GNAT is free software;  you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 3,  or (at your option) any later ver- --
-- sion.  GNAT is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.                                     --
--                                                                          --
-- As a special exception under Section 7 of GPL version 3, you are granted --
-- additional permissions described in the GCC Runtime Library Exception,   --
-- version 3.1, as published by the Free Software Foundation.               --
--                                                                          --
-- You should have received a copy of the GNU General Public License and    --
-- a copy of the GCC Runtime Library Exception along with this program;     --
-- see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see    --
-- <http://www.gnu.org/licenses/>.                                          --
--                                                                          --
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
----------------------------------------------------------------------------*/

#include "Arduboy.h"
#include "interface.h"

#define FRAMERATE 15

// make an instance of arduboy used for many functions
Arduboy arduboy;

void setup() {

  // initiate arduboy instance
  arduboy.beginNoLogo();        // beginNoLogo() saves 350 bytes of program space
}

interfaces__unsigned_32 score_save = 0;
interfaces__unsigned_32 level_save = 0;

#ifdef __cplusplus
extern "C" {
#endif

//  Ada functions translated to C that we will call
extern void tetris_functional___elabs();
extern void _ada_main_tetris(void);

//  Declaration of "game interface" functions that will be called by the tetris code

void delay_ms(interfaces__unsigned_32 ms);
void display_score(interfaces__unsigned_32 score, interfaces__unsigned_32 level);
integer button_right_pressed(void);
integer button_turn_pressed(void);
integer button_left_pressed(void);
integer button_down_pressed(void);
void clear_screen(void);
void game_over(void);
void update_screen(void);
void set_screen_pixel(integer x, integer y);
extern void __gnat_last_chance_handler (char *msg, int line);

#ifdef __cplusplus
}
#endif

//  This function is called when an exception is raised in the Ada code
extern void __gnat_last_chance_handler (char *msg, int line) {
  arduboy.clear();
  arduboy.setCursor(0, 0);
  arduboy.print("last chance...");
  arduboy.display();  
  while (1) {
    arduboy.setRGBled(0, 0, 255);
    delay(50);
    arduboy.setRGBled(0, 0, 0);
    delay(50);
  }
}

void delay_ms(interfaces__unsigned_32 ms) {
  delay(ms);
}

//  We just save score and level to use the value during screen update
void display_score(interfaces__unsigned_32 score, interfaces__unsigned_32 level) {
  score_save = score;
  level_save = level;
}

integer button_right_pressed(void) {
  return arduboy.pressed(RIGHT_BUTTON);
}

integer button_turn_pressed(void) {
  return arduboy.pressed(UP_BUTTON) || arduboy.pressed(B_BUTTON);
}

integer button_left_pressed(void) {
  return arduboy.pressed(LEFT_BUTTON);
}

integer button_down_pressed(void){
  return arduboy.pressed(DOWN_BUTTON) || arduboy.pressed(A_BUTTON);
}

void clear_screen(void) {
  arduboy.clear();
}

void game_over(void) {
  arduboy.clear();
  arduboy.setCursor(5, 20);
  arduboy.print("GAME");
  arduboy.setCursor(5, 35);
  arduboy.print("OVER");
  update_screen();
}

void update_screen(void) {
  //  Print title
  arduboy.setCursor(54, 30);
  arduboy.print("SPARK-to-C");
  arduboy.setCursor(50, 40);
  arduboy.print("TETRIS DEMO");

  //  Print score
  arduboy.setCursor(54, 0);
  arduboy.print("Score:");
  arduboy.print(score_save);

  //  Print level
  arduboy.setCursor(54, 10);
  arduboy.print("Level:");
  arduboy.print(level_save);

  //  Show everything
  arduboy.display();

  //  restart from scratch
  arduboy.clear();
}

void set_screen_pixel(integer x, integer y) {
  arduboy.drawPixel(x, y, WHITE);
}

void loop() {
  tetris_functional___elabs();
  _ada_main_tetris();
}

