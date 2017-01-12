#include "tetris_functional.h"

void tetris_functional__include_piece_in_board(void) {
  switch (tetris_functional__cur_piece.s) {
    case tetris_functional__o: {
      tetris_functional__cur_board[tetris_functional__cur_piece.y - 1][tetris_functional__cur_piece.x - 1] = tetris_functional__cur_piece.s;
      tetris_functional__cur_board[tetris_functional__cur_piece.y + 1 - 1][tetris_functional__cur_piece.x - 1] = tetris_functional__cur_piece.s;
      tetris_functional__cur_board[tetris_functional__cur_piece.y - 1][tetris_functional__cur_piece.x + 1 - 1] = tetris_functional__cur_piece.s;
      tetris_functional__cur_board[tetris_functional__cur_piece.y + 1 - 1][tetris_functional__cur_piece.x + 1 - 1] = tetris_functional__cur_piece.s; }
      break;
    case tetris_functional__i: {
      {

        tetris_functional__i_delta y;

        for (y = 0; y <= 3; y++) {
          {

            tetris_functional__i_delta x;

            for (x = 0; x <= 3; x++) {
              if (tetris_functional__possible_i_shapes[tetris_functional__cur_piece.d][y][x]) {
                tetris_functional__cur_board[tetris_functional__cur_piece.y + y - 1][tetris_functional__cur_piece.x + x
                  - 1] = tetris_functional__cur_piece.s;
              }
            }
          }
        }
      } }
      break;
    default: {
      {

        tetris_functional__three_delta y;

        for (y = 0; y <= 2; y++) {
          {

            tetris_functional__three_delta x;

            for (x = 0; x <= 2; x++) {
              if (tetris_functional__possible_three_shapes[tetris_functional__cur_piece.s - 3][tetris_functional__cur_piece.d][y][x]
                ) {
                tetris_functional__cur_board[tetris_functional__cur_piece.y + y - 1][tetris_functional__cur_piece.x + x
                  - 1] = tetris_functional__cur_piece.s;
              }
            }
          }
        }
      } }
      break;
  }
  tetris_functional__cur_state = tetris_functional__board_before_clean;
  return;
}
void tetris_functional__delete_complete_lines(natural *number_of_complete_lines) {
  tetris_functional__line empty_line;
  {
    typedef integer tetris_functional__delete_complete_lines__T25b;
    tetris_functional__delete_complete_lines__T25b J23b;

    for (J23b = 1; J23b <= 10; J23b++) {
      empty_line[J23b - 1] = tetris_functional__empty;
    }
  }
  {
    tetris_functional__y_coord to_line = 20;
    boolean has_complete_lines = false;
    (*number_of_complete_lines) = 0;
    {

      tetris_functional__y_coord del_line;

      for (del_line = 1; del_line <= 20; del_line++) {
        if (tetris_functional__is_complete_line(tetris_functional__cur_board[del_line - 1])) {
          memcpy(tetris_functional__cur_board[del_line - 1], empty_line, sizeof(tetris_functional__line));
          has_complete_lines = true;
          (*number_of_complete_lines)++;
          to_line = del_line;
        }
      }
    }
    if (has_complete_lines) {
      const integer R39b = to_line - 1;
      {
        typedef integer tetris_functional__delete_complete_lines__T40b;
        tetris_functional__delete_complete_lines__T40b from_line;

        for (from_line = R39b; from_line >= 1; from_line--) {
          if (!tetris_functional__is_empty_line(tetris_functional__cur_board[from_line - 1])) {
            memcpy(tetris_functional__cur_board[to_line - 1], tetris_functional__cur_board[from_line - 1], sizeof(tetris_functional__line));
            memcpy(tetris_functional__cur_board[from_line - 1], empty_line, sizeof(tetris_functional__line));
            to_line--;
          }
        }
      }
    }
    tetris_functional__cur_state = tetris_functional__board_after_clean;
    return;

  }}
tetris_functional__piece tetris_functional__move(const tetris_functional__piece p, tetris_functional__action a) {
  {}
  switch (a) {
    case tetris_functional__move_left: {
      tetris_functional__piece T44b = p;
      T44b.x = p.x - 1;
      return (T44b); }
      break;
    case tetris_functional__move_right: {
      tetris_functional__piece T46b = p;
      T46b.x = p.x + 1;
      return (T46b); }
      break;
    case tetris_functional__move_down: {
      tetris_functional__piece T48b = p;
      T48b.y = p.y + 1;
      return (T48b); }
      break;
    default: {
      tetris_functional__piece T50b = p;
      T50b.d = tetris_functional__turn_direction(p.d, a);
      return (T50b); }
      break;
  }
}
void tetris_functional__do_action(tetris_functional__action a, boolean *success) {
  tetris_functional__piece candidate;
  if (tetris_functional__move_is_possible(tetris_functional__cur_piece, a)) {
    candidate = tetris_functional__move(tetris_functional__cur_piece, a);
    if (tetris_functional__no_overlap(tetris_functional__cur_board, candidate)) {
      tetris_functional__cur_piece = candidate;
      (*success) = true;
      return;
    }
  }
  (*success) = false;
  return;
}

