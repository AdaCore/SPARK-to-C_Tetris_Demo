#include "main_tetris.h"

typedef struct _AREC1T {
  system__address level_nbr;
  system__address speed_up;
  system__address score;
  system__address next_piece;
  system__address rnd;
} AREC1T;
typedef struct _AREC1T *AREC1PT;
static interfaces__unsigned_32 main_tetris__fall_period(AREC1PT AREC2F);
static void main_tetris__draw_board(boolean with_piece, AREC1PT AREC3F);
static void main_tetris__draw_board__draw_block(natural x, natural y);
static void main_tetris__draw_board__draw_piece(const tetris_functional__piece p, natural offset_x, natural offset_y);
static tetris_functional__piece main_tetris__random_piece(AREC1PT AREC6F);
static tetris_functional__piece main_tetris__random_piece(AREC1PT AREC6F) {
  (*((interfaces__unsigned_32 *)AREC6F->rnd)) = ((*((interfaces__unsigned_32 *)AREC6F->rnd)) * 1103515245U) + 12345U;
  {
    tetris_functional__piece A7b;
    A7b.s = (tetris_functional__shape)(tetris_functional__cell)1U + (((*((interfaces__unsigned_32 *)AREC6F->rnd)) /
      65536U) % 7U);
    A7b.d = tetris_functional__north;
    A7b.x = 5;
    A7b.y = 1;
    return (A7b);

  }}
static void main_tetris__draw_board__draw_piece(const tetris_functional__piece p, natural offset_x, natural offset_y) {
  switch (p.s) {
    case tetris_functional__o: {
      main_tetris__draw_board__draw_block(p.x + offset_x, p.y + offset_y);
      main_tetris__draw_board__draw_block(p.x + offset_x, (p.y + 1) + offset_y);
      main_tetris__draw_board__draw_block((p.x + 1) + offset_x, p.y + offset_y);
      main_tetris__draw_board__draw_block((p.x + 1) + offset_x, (p.y + 1) + offset_y); }
      break;
    case tetris_functional__i:
      {

        tetris_functional__i_delta y;

        for (y = 0; y <= 3; y++) {
          {

            tetris_functional__i_delta x;

            for (x = 0; x <= 3; x++) {
              if (tetris_functional__possible_i_shapes[p.d][y][x]) {
                main_tetris__draw_board__draw_block((p.x + x) + offset_x, (p.y + y) + offset_y);
              }
            }
          }
        }
      }
      break;
    default:
      {

        tetris_functional__three_delta y;

        for (y = 0; y <= 2; y++) {
          {

            tetris_functional__three_delta x;

            for (x = 0; x <= 2; x++) {
              if (tetris_functional__possible_three_shapes[p.s - 3][p.d][y][x]) {
                main_tetris__draw_board__draw_block((p.x + x) + offset_x, (p.y + y) + offset_y);
              }
            }
          }
        }
      }
      break;
  }
  return;
}
static void main_tetris__draw_board__draw_block(natural x, natural y) {
  const natural x_pos = 3 * (x - 1);
  const natural y_pos = 3 * (y - 1);
  {
    typedef integer main_tetris__draw_board__draw_block__T2b;
    main_tetris__draw_board__draw_block__T2b i;

    for (i = 1; i <= 3; i++) {
      {
        typedef integer main_tetris__draw_board__draw_block__T3b;
        main_tetris__draw_board__draw_block__T3b j;

        for (j = 1; j <= 3; j++) {
          game_interface__set_screen_pixel(((x_pos + i) - 1) + 1, (y_pos + j) - 1);
        }
      }
    }
  }
  return;
}
static void main_tetris__draw_board(boolean with_piece, AREC1PT AREC3F) {
  game_interface__display_score((interfaces__unsigned_32)(*((natural *)AREC3F->score)), (interfaces__unsigned_32)(*((natural *)AREC3F->level_nbr)));
  {
    typedef integer main_tetris__draw_board__T4b;
    main_tetris__draw_board__T4b y;

    for (y = 0; y <= 60; y++) {
      game_interface__set_screen_pixel(0, y);
      game_interface__set_screen_pixel(31, y);
    }
  }
  {
    typedef integer main_tetris__draw_board__T5b;
    main_tetris__draw_board__T5b x;

    for (x = 1; x <= 30; x++) {
      game_interface__set_screen_pixel(x, 60);
    }
  }
  {

    tetris_functional__y_coord y;

    for (y = 1; y <= 20; y++) {
      {

        tetris_functional__x_coord x;

        for (x = 1; x <= 10; x++) {
          if (tetris_functional__cur_board[y - 1][x - 1] != tetris_functional__empty) {
            main_tetris__draw_board__draw_block(x, y);
          }
        }
      }
    }
  }
  if (with_piece) {
    main_tetris__draw_board__draw_piece(tetris_functional__cur_piece, 0, 0);
  }
  main_tetris__draw_board__draw_piece((*((tetris_functional__piece *)AREC3F->next_piece)), 7, 1);
  game_interface__update_screen();
  return;
}
static interfaces__unsigned_32 main_tetris__fall_period(AREC1PT AREC2F) {
  const interfaces__unsigned_32 interval = (11U - ((interfaces__unsigned_32)(*((natural *)AREC2F->level_nbr)) % 11U)) *
    10U;
  return (((*((boolean *)AREC2F->speed_up))) ? (interval / 3U) : interval);
}
void _ada_main_tetris(void) {
  AREC1T AREC1;
  const AREC1PT AREC1P = &AREC1;
  boolean speed_up = false;
  AREC1.speed_up = (system__address)&speed_up;
  {
    natural level_nbr = 0;
    AREC1.level_nbr = (system__address)&level_nbr;
    {
      natural score = 0;
      AREC1.score = (system__address)&score;
      {
        natural line_counter = 0;
        natural nbr_of_complete_lines;
        tetris_functional__piece next_piece;
        AREC1.next_piece = (system__address)&next_piece;
        {
          interfaces__unsigned_32 rnd = 137U;
          AREC1.rnd = (system__address)&rnd;
          {
            boolean success;
            next_piece = main_tetris__random_piece(AREC1P);
            while (true) {
              {
                typedef integer _ada_main_tetris__T12b;
                _ada_main_tetris__T12b J10b;

                for (J10b = 1; J10b <= 20; J10b++) {
                  {
                    typedef integer _ada_main_tetris__T17b;
                    _ada_main_tetris__T17b J15b;

                    for (J15b = 1; J15b <= 10; J15b++) {
                      tetris_functional__cur_board[J10b - 1][J15b - 1] = tetris_functional__empty;
                    }
                  }
                }
              }
              game_interface__clear_screen();
              game_interface__update_screen();
              while (true) {
                tetris_functional__cur_piece = next_piece;
                next_piece = main_tetris__random_piece(AREC1P);
                tetris_functional__cur_state = tetris_functional__piece_falling;
                if (!tetris_functional__valid_configuration()) {
                  goto piece;
                }
                speed_up = false;
                while (true) {
                  {
                    typedef integer _ada_main_tetris__T18b;
                    _ada_main_tetris__T18b j;

                    for (j = 1; j <= 2; j++) {
                      if (game_interface__button_right_pressed() != 0) {
                        tetris_functional__do_action(tetris_functional__move_right, &success);
                      }
                      else if (game_interface__button_turn_pressed() != 0) {
                        tetris_functional__do_action(tetris_functional__turn_clockwise, &success);
                      }
                      else if (game_interface__button_left_pressed() != 0) {
                        tetris_functional__do_action(tetris_functional__move_left, &success);
                      }
                      else if (game_interface__button_down_pressed() != 0) {
                        speed_up = true;
                      }
                      main_tetris__draw_board(true, AREC1P);
                      game_interface__delay_ms(main_tetris__fall_period(AREC1P));
                    }
                  }
                  tetris_functional__do_action(tetris_functional__move_down, &success);
                  if (!success) {
                    goto fall;
                  }
                  main_tetris__draw_board(true, AREC1P);
                }
                fall: ;
                tetris_functional__cur_state = tetris_functional__piece_blocked;
                tetris_functional__include_piece_in_board();
                tetris_functional__delete_complete_lines(&nbr_of_complete_lines);
                switch (nbr_of_complete_lines) {
                  case 1:
                    score = score + (4 * (level_nbr + 1));
                    break;
                  case 2:
                    score = score + (10 * (level_nbr + 1));
                    break;
                  case 3:
                    score = score + (30 * (level_nbr + 1));
                    break;
                  case 4:
                    score = score + (120 * (level_nbr + 1));
                    break;
                  default: /* No statement */
                    break;
                }
                line_counter = line_counter + nbr_of_complete_lines;
                if ((line_counter >= 10) && (level_nbr < 10)) {
                  level_nbr++;
                  line_counter -= 10;
                }
                game_interface__delay_ms(main_tetris__fall_period(AREC1P));
              }
              piece: ;
              game_interface__game_over();
              {
                boolean toggle = true;

                while (true) {
                  if ((((game_interface__button_right_pressed() != 0) | (game_interface__button_turn_pressed() != 0)) | (game_interface__button_left_pressed() !=
                    0)) | (game_interface__button_down_pressed() != 0)) {
                    break;
                  }
                  rnd++;
                  game_interface__delay_ms(500U);
                  toggle = !toggle;
                }
              }
              game_interface__delay_ms(1000U);
              score = 0;
              level_nbr = 0;
              line_counter = 0;
            }
            game: ;
            return;

          }
        }
      }
    }
  }}
