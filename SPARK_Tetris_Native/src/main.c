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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

extern void tetris_functional___elabs();
extern void _ada_main_tetris(void);

void __gnat_last_chance_handler (void)
{
  printf("Last chance handler...");
  exit(1);
}

#define SCREEN_X 128
#define SCREEN_Y 64
#define SCREEN_LEN (SCREEN_X * SCREEN_Y)

char screen[SCREEN_LEN];

uint32_t score_save = 0;
uint32_t level_save = 0;

void game_over(void)
{
  printf("GAME OVER!\n");
}

void clear_screen(void)
{

  for (int i = 0; i < SCREEN_LEN; i++) {
    screen[i] = 0;
  }
}

void update_screen(void)
{
  printf("\e[1;1H\e[2J");
  for (int x = 0; x < SCREEN_X; x++) {
    for (int y = 0; y < SCREEN_Y; y++) {
      printf("\e[1;1H\e[%d;%dH", x, y + 1);
      printf(screen[x * SCREEN_Y + y] ? "#" : " ");
    }
  }
  printf("Score:%d Level:%d\n", score_save, level_save);
  clear_screen();
}

void set_screen_pixel(uint32_t x, uint32_t y)
{
  screen[x * SCREEN_Y + y] = 1;
}

void display_score(uint32_t score, uint32_t level) {
  score_save = score;
  level_save = level;
}

void delay_ms(uint32_t ms)
{
  usleep(ms * 1000);
}

uint32_t button_right_pressed(void)
{
  return 0;
}

uint32_t button_turn_pressed(void)
{
  return 0;
}

uint32_t button_left_pressed(void)
{
  return 0;
}

uint32_t button_down_pressed(void)
{
  return 0;
}

void main(void) {
  tetris_functional___elabs();
  _ada_main_tetris();
}
