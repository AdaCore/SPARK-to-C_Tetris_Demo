#ifndef STANDARD_H
#define STANDARD_H


#ifdef __vxworks
#include "vxWorks.h"
#include "version.h" /* for _WRS_VXWORKS_MAJOR and _WRS_VXWORKS_MINOR */
#endif

/* stdint.h is only guaranteed to be there starting with C99 */
#if __STDC_VERSION__ >= 199901L
#include <stdint.h>   /* for [u]int*_t */
#endif

#include <string.h>  /* for memcpy(), memcmp() */
#include <math.h>    /* for fabs*(), isfinite(), powl() and for Ada.Numerics */

#ifndef __USE_ISOC99
#define __USE_ISOC99 /* for enabling llabs() */
#endif
#include <stdlib.h>  /* for *abs(), malloc() */

#if __STDC_VERSION__ >= 199901L
#include <stdbool.h>

#define GNAT_INLINE inline
typedef bool boolean;

#else

#define GNAT_INLINE
typedef unsigned char boolean;

#ifndef false
#define false 0
#endif

#ifndef true
#define true 1
#endif
#endif

#ifdef INT8_MIN  /* stdint.h supported */
typedef uint8_t unsigned_8;
typedef uint16_t unsigned_16;
typedef uint32_t unsigned_32;
typedef uint64_t unsigned_64;

typedef int8_t integer_8;
typedef int16_t integer_16;
typedef int32_t integer_32;
typedef int64_t integer_64;

typedef intptr_t integer_ptr_t;
#else
typedef unsigned char unsigned_8;
typedef unsigned short unsigned_16;
typedef unsigned unsigned_32;
typedef unsigned long long unsigned_64;

typedef signed char integer_8;
typedef short integer_16;
typedef int integer_32;
typedef long long integer_64;

typedef long integer_ptr_t;
#endif

typedef int integer;

typedef int natural;
typedef int positive;

typedef signed char short_short_integer;
typedef short short_integer;
typedef long long_integer;
typedef long long long_long_integer;
typedef long long universal_integer;

typedef float short_float;
typedef double long_float;
typedef long double long_long_float;
typedef long double universal_real;

typedef unsigned char character;
typedef unsigned_16 wide_character;
typedef unsigned_32 wide_wide_character;

typedef character *access_character;
typedef character *string;
typedef wide_character *wide_string;
typedef wide_wide_character *wide_wide_string;

typedef integer_32 duration;

typedef void *_void_ptr;
extern void __gnat_last_chance_handler (const _void_ptr msg, integer line);

/* Fat pointer of unidimensional unconstrained arrays */
typedef struct {
  void *all;
  integer_ptr_t first;
  integer_ptr_t last;
} _fatptr_UNCarray;

static GNAT_INLINE _fatptr_UNCarray
_fatptr_UNCarray_CONS (void *all, integer_ptr_t first, integer_ptr_t last)
{
  _fatptr_UNCarray fatptr;
  fatptr.all   = all;
  fatptr.first = first;
  fatptr.last  = last;
  return fatptr;
}

#endif /* STANDARD_H */

#ifndef TETRIS_FUNCTIONAL_ADS
#define TETRIS_FUNCTIONAL_ADS
typedef integer_8 tetris_functional__cell;
enum {tetris_functional__empty=0, tetris_functional__i=1, tetris_functional__o=2, tetris_functional__j=3, tetris_functional__l=
  4, tetris_functional__s=5, tetris_functional__t=6, tetris_functional__z=7};
typedef character tetris_functional__TcellSS[12];
const tetris_functional__TcellSS tetris_functional__cellS = "EMPTYIOJLSTZ";
typedef integer_8 tetris_functional__TcellNT[9];
const tetris_functional__TcellNT tetris_functional__cellN = {1, 6, 7, 8, 9, 10, 11, 12, 13};
typedef tetris_functional__cell tetris_functional__shape;
typedef integer tetris_functional__x_coord;
typedef integer tetris_functional__y_coord;
typedef tetris_functional__cell tetris_functional__line[10];
typedef tetris_functional__line tetris_functional__board[20];
tetris_functional__board tetris_functional__cur_board;
typedef integer tetris_functional__px_coord;
typedef integer tetris_functional__py_coord;
typedef integer_8 tetris_functional__direction;
enum {tetris_functional__north=0, tetris_functional__east=1, tetris_functional__south=2, tetris_functional__west=3};
typedef struct _tetris_functional__piece {
  tetris_functional__shape s;
  tetris_functional__direction d;
  tetris_functional__px_coord x;
  tetris_functional__py_coord y;
} tetris_functional__piece;
typedef character tetris_functional__TdirectionSS[18];
const tetris_functional__TdirectionSS tetris_functional__directionS = "NORTHEASTSOUTHWEST";
typedef integer_8 tetris_functional__TdirectionNT[5];
const tetris_functional__TdirectionNT tetris_functional__directionN = {1, 6, 10, 15, 19};
tetris_functional__piece tetris_functional__cur_piece;
typedef integer_8 tetris_functional__state;
enum {tetris_functional__piece_falling=0, tetris_functional__piece_blocked=1, tetris_functional__board_before_clean=
  2, tetris_functional__board_after_clean=3};
typedef character tetris_functional__TstateSS[61];
const tetris_functional__TstateSS tetris_functional__stateS =
  "PIECE_FALLINGPIECE_BLOCKEDBOARD_BEFORE_CLEANBOARD_AFTER_CLEAN";
typedef integer_8 tetris_functional__TstateNT[5];
const tetris_functional__TstateNT tetris_functional__stateN = {1, 14, 27, 45, 62};
tetris_functional__state tetris_functional__cur_state;
typedef integer tetris_functional__i_delta;
typedef boolean tetris_functional__oriented_i_shape[4][4];
typedef integer tetris_functional__three_delta;
typedef boolean tetris_functional__oriented_three_shape[3][3];
typedef tetris_functional__oriented_i_shape tetris_functional__T35s[4];
tetris_functional__T35s tetris_functional__possible_i_shapes;
typedef tetris_functional__oriented_three_shape tetris_functional__T98s[5][4];
tetris_functional__T98s tetris_functional__possible_three_shapes;
extern boolean tetris_functional__is_empty(tetris_functional__board b, integer y, integer x);
extern boolean tetris_functional__is_complete_line(tetris_functional__line l);
extern boolean tetris_functional__is_empty_line(tetris_functional__line l);
extern boolean tetris_functional__no_complete_lines(tetris_functional__board b);
extern boolean tetris_functional__no_overlap(tetris_functional__board b, const tetris_functional__piece p);
extern boolean tetris_functional__valid_configuration(void);
typedef integer_8 tetris_functional__action;
enum {tetris_functional__move_left=0, tetris_functional__move_right=1, tetris_functional__move_down=2, tetris_functional__turn_counter_clockwise=
  3, tetris_functional__turn_clockwise=4};
typedef character tetris_functional__TactionSS[64];
const tetris_functional__TactionSS tetris_functional__actionS =
  "MOVE_LEFTMOVE_RIGHTMOVE_DOWNTURN_COUNTER_CLOCKWISETURN_CLOCKWISE";
typedef integer_8 tetris_functional__TactionNT[6];
const tetris_functional__TactionNT tetris_functional__actionN = {1, 10, 20, 29, 51, 65};
typedef tetris_functional__action tetris_functional__turn_action;
extern tetris_functional__direction tetris_functional__turn_direction(tetris_functional__direction d, tetris_functional__turn_action t);
extern boolean tetris_functional__move_is_possible(const tetris_functional__piece p, tetris_functional__action a);
extern tetris_functional__piece tetris_functional__move(const tetris_functional__piece p, tetris_functional__action a);
extern void tetris_functional__do_action(tetris_functional__action a, boolean *success);
extern void tetris_functional__include_piece_in_board(void);
extern void tetris_functional__delete_complete_lines(natural *number_of_complete_lines);
boolean tetris_functional__is_empty(tetris_functional__board b, integer y, integer x) {
  return (((x >= 1 && x <= 10) && (y >= 1 && y <= 20)) && ((b)[y - 1][x - 1] == tetris_functional__empty));
}
boolean tetris_functional__is_complete_line(tetris_functional__line l) {
  return (({
    boolean T125s = true;
    {

      tetris_functional__x_coord x;

      for (x = 1; x <= 10; x++) {
        if (!((l)[x - 1] != tetris_functional__empty)) {
          T125s = false;
          break;
        }
      }
    };
    T125s; }));
}
boolean tetris_functional__is_empty_line(tetris_functional__line l) {
  return (({
    boolean T129s = true;
    {

      tetris_functional__x_coord x;

      for (x = 1; x <= 10; x++) {
        if (!((l)[x - 1] == tetris_functional__empty)) {
          T129s = false;
          break;
        }
      }
    };
    T129s; }));
}
boolean tetris_functional__no_complete_lines(tetris_functional__board b) {
  return (({
    boolean T133s = true;
    {

      tetris_functional__y_coord y;

      for (y = 1; y <= 20; y++) {
        if (!(!tetris_functional__is_complete_line((b)[y - 1]))) {
          T133s = false;
          break;
        }
      }
    };
    T133s; }));
}
boolean tetris_functional__no_overlap(tetris_functional__board b, const tetris_functional__piece p) {
  switch (p.s) {
    case tetris_functional__o:
      return (((tetris_functional__is_empty(b, p.y, p.x) && tetris_functional__is_empty(b, p.y, p.x + 1)) && tetris_functional__is_empty(b, p.y +
        1, p.x)) && tetris_functional__is_empty(b, p.y + 1, p.x + 1));
      break;
    case tetris_functional__i:
      return (({
        boolean T140s = true;
        {

          tetris_functional__i_delta y;

          for (y = 0; y <= 3; y++) {
            if (!({
              boolean T143s = true;
              {

                tetris_functional__i_delta x;

                for (x = 0; x <= 3; x++) {
                  if (!((tetris_functional__possible_i_shapes[p.d][y][x]) ? tetris_functional__is_empty(b, p.y + y, p.x + x) : true)
                    ) {
                    T143s = false;
                    break;
                  }
                }
              };
              T143s; })) {
              T140s = false;
              break;
            }
          }
        };
        T140s; }));
      break;
    default:
      return (({
        boolean T145s = true;
        {

          tetris_functional__three_delta y;

          for (y = 0; y <= 2; y++) {
            if (!({
              boolean T148s = true;
              {

                tetris_functional__three_delta x;

                for (x = 0; x <= 2; x++) {
                  if (!((tetris_functional__possible_three_shapes[p.s - 3][p.d][y][x]) ? tetris_functional__is_empty(b, p.y + y, p.x + x) : true)
                    ) {
                    T148s = false;
                    break;
                  }
                }
              };
              T148s; })) {
              T145s = false;
              break;
            }
          }
        };
        T145s; }));
      break;
  }
}
boolean tetris_functional__valid_configuration(void) {
  switch (tetris_functional__cur_state) {
    case tetris_functional__piece_falling:
    case tetris_functional__piece_blocked:
      return (tetris_functional__no_overlap(tetris_functional__cur_board, tetris_functional__cur_piece));
      break;
    case tetris_functional__board_before_clean:
      return (true);
      break;
    default:
      return (tetris_functional__no_complete_lines(tetris_functional__cur_board));
      break;
  }
}
tetris_functional__direction tetris_functional__turn_direction(tetris_functional__direction d, tetris_functional__turn_action t) {
  if (t == tetris_functional__turn_counter_clockwise) {
    return ((d == tetris_functional__north) ? tetris_functional__west : (d - 1));
  }
  else {
    return ((d == tetris_functional__west) ? tetris_functional__north : (d + 1));
  }
}
boolean tetris_functional__move_is_possible(const tetris_functional__piece p, tetris_functional__action a) {
  switch (a) {
    case tetris_functional__move_left:
      return ((p.x - 1) >= -1 && (p.x - 1) <= 9);
      break;
    case tetris_functional__move_right:
      return ((p.x + 1) >= -1 && (p.x + 1) <= 9);
      break;
    case tetris_functional__move_down:
      return ((p.y + 1) >= -1 && (p.y + 1) <= 19);
      break;
    default:
      return (true);
      break;
  }
}
extern void tetris_functional___elabs();
void tetris_functional___elabs() {
  tetris_functional__possible_i_shapes[0][0][0] = false;
  tetris_functional__possible_i_shapes[0][0][1] = false;
  tetris_functional__possible_i_shapes[0][0][2] = false;
  tetris_functional__possible_i_shapes[0][0][3] = false;
  tetris_functional__possible_i_shapes[0][1][0] = true;
  tetris_functional__possible_i_shapes[0][1][1] = true;
  tetris_functional__possible_i_shapes[0][1][2] = true;
  tetris_functional__possible_i_shapes[0][1][3] = true;
  tetris_functional__possible_i_shapes[0][2][0] = false;
  tetris_functional__possible_i_shapes[0][2][1] = false;
  tetris_functional__possible_i_shapes[0][2][2] = false;
  tetris_functional__possible_i_shapes[0][2][3] = false;
  tetris_functional__possible_i_shapes[0][3][0] = false;
  tetris_functional__possible_i_shapes[0][3][1] = false;
  tetris_functional__possible_i_shapes[0][3][2] = false;
  tetris_functional__possible_i_shapes[0][3][3] = false;
  tetris_functional__possible_i_shapes[1][0][0] = false;
  tetris_functional__possible_i_shapes[1][0][1] = false;
  tetris_functional__possible_i_shapes[1][0][2] = true;
  tetris_functional__possible_i_shapes[1][0][3] = false;
  tetris_functional__possible_i_shapes[1][1][0] = false;
  tetris_functional__possible_i_shapes[1][1][1] = false;
  tetris_functional__possible_i_shapes[1][1][2] = true;
  tetris_functional__possible_i_shapes[1][1][3] = false;
  tetris_functional__possible_i_shapes[1][2][0] = false;
  tetris_functional__possible_i_shapes[1][2][1] = false;
  tetris_functional__possible_i_shapes[1][2][2] = true;
  tetris_functional__possible_i_shapes[1][2][3] = false;
  tetris_functional__possible_i_shapes[1][3][0] = false;
  tetris_functional__possible_i_shapes[1][3][1] = false;
  tetris_functional__possible_i_shapes[1][3][2] = true;
  tetris_functional__possible_i_shapes[1][3][3] = false;
  tetris_functional__possible_i_shapes[2][0][0] = false;
  tetris_functional__possible_i_shapes[2][0][1] = false;
  tetris_functional__possible_i_shapes[2][0][2] = false;
  tetris_functional__possible_i_shapes[2][0][3] = false;
  tetris_functional__possible_i_shapes[2][1][0] = false;
  tetris_functional__possible_i_shapes[2][1][1] = false;
  tetris_functional__possible_i_shapes[2][1][2] = false;
  tetris_functional__possible_i_shapes[2][1][3] = false;
  tetris_functional__possible_i_shapes[2][2][0] = true;
  tetris_functional__possible_i_shapes[2][2][1] = true;
  tetris_functional__possible_i_shapes[2][2][2] = true;
  tetris_functional__possible_i_shapes[2][2][3] = true;
  tetris_functional__possible_i_shapes[2][3][0] = false;
  tetris_functional__possible_i_shapes[2][3][1] = false;
  tetris_functional__possible_i_shapes[2][3][2] = false;
  tetris_functional__possible_i_shapes[2][3][3] = false;
  tetris_functional__possible_i_shapes[3][0][0] = false;
  tetris_functional__possible_i_shapes[3][0][1] = true;
  tetris_functional__possible_i_shapes[3][0][2] = false;
  tetris_functional__possible_i_shapes[3][0][3] = false;
  tetris_functional__possible_i_shapes[3][1][0] = false;
  tetris_functional__possible_i_shapes[3][1][1] = true;
  tetris_functional__possible_i_shapes[3][1][2] = false;
  tetris_functional__possible_i_shapes[3][1][3] = false;
  tetris_functional__possible_i_shapes[3][2][0] = false;
  tetris_functional__possible_i_shapes[3][2][1] = true;
  tetris_functional__possible_i_shapes[3][2][2] = false;
  tetris_functional__possible_i_shapes[3][2][3] = false;
  tetris_functional__possible_i_shapes[3][3][0] = false;
  tetris_functional__possible_i_shapes[3][3][1] = true;
  tetris_functional__possible_i_shapes[3][3][2] = false;
  tetris_functional__possible_i_shapes[3][3][3] = false;
  tetris_functional__possible_three_shapes[0][0][0][0] = true;
  tetris_functional__possible_three_shapes[0][0][0][1] = false;
  tetris_functional__possible_three_shapes[0][0][0][2] = false;
  tetris_functional__possible_three_shapes[0][0][1][0] = true;
  tetris_functional__possible_three_shapes[0][0][1][1] = true;
  tetris_functional__possible_three_shapes[0][0][1][2] = true;
  tetris_functional__possible_three_shapes[0][0][2][0] = false;
  tetris_functional__possible_three_shapes[0][0][2][1] = false;
  tetris_functional__possible_three_shapes[0][0][2][2] = false;
  tetris_functional__possible_three_shapes[0][1][0][0] = false;
  tetris_functional__possible_three_shapes[0][1][0][1] = true;
  tetris_functional__possible_three_shapes[0][1][0][2] = true;
  tetris_functional__possible_three_shapes[0][1][1][0] = false;
  tetris_functional__possible_three_shapes[0][1][1][1] = true;
  tetris_functional__possible_three_shapes[0][1][1][2] = false;
  tetris_functional__possible_three_shapes[0][1][2][0] = false;
  tetris_functional__possible_three_shapes[0][1][2][1] = true;
  tetris_functional__possible_three_shapes[0][1][2][2] = false;
  tetris_functional__possible_three_shapes[0][2][0][0] = false;
  tetris_functional__possible_three_shapes[0][2][0][1] = false;
  tetris_functional__possible_three_shapes[0][2][0][2] = false;
  tetris_functional__possible_three_shapes[0][2][1][0] = true;
  tetris_functional__possible_three_shapes[0][2][1][1] = true;
  tetris_functional__possible_three_shapes[0][2][1][2] = true;
  tetris_functional__possible_three_shapes[0][2][2][0] = false;
  tetris_functional__possible_three_shapes[0][2][2][1] = false;
  tetris_functional__possible_three_shapes[0][2][2][2] = true;
  tetris_functional__possible_three_shapes[0][3][0][0] = false;
  tetris_functional__possible_three_shapes[0][3][0][1] = true;
  tetris_functional__possible_three_shapes[0][3][0][2] = false;
  tetris_functional__possible_three_shapes[0][3][1][0] = false;
  tetris_functional__possible_three_shapes[0][3][1][1] = true;
  tetris_functional__possible_three_shapes[0][3][1][2] = false;
  tetris_functional__possible_three_shapes[0][3][2][0] = true;
  tetris_functional__possible_three_shapes[0][3][2][1] = true;
  tetris_functional__possible_three_shapes[0][3][2][2] = false;
  tetris_functional__possible_three_shapes[1][0][0][0] = false;
  tetris_functional__possible_three_shapes[1][0][0][1] = false;
  tetris_functional__possible_three_shapes[1][0][0][2] = true;
  tetris_functional__possible_three_shapes[1][0][1][0] = true;
  tetris_functional__possible_three_shapes[1][0][1][1] = true;
  tetris_functional__possible_three_shapes[1][0][1][2] = true;
  tetris_functional__possible_three_shapes[1][0][2][0] = false;
  tetris_functional__possible_three_shapes[1][0][2][1] = false;
  tetris_functional__possible_three_shapes[1][0][2][2] = false;
  tetris_functional__possible_three_shapes[1][1][0][0] = false;
  tetris_functional__possible_three_shapes[1][1][0][1] = true;
  tetris_functional__possible_three_shapes[1][1][0][2] = false;
  tetris_functional__possible_three_shapes[1][1][1][0] = false;
  tetris_functional__possible_three_shapes[1][1][1][1] = true;
  tetris_functional__possible_three_shapes[1][1][1][2] = false;
  tetris_functional__possible_three_shapes[1][1][2][0] = false;
  tetris_functional__possible_three_shapes[1][1][2][1] = true;
  tetris_functional__possible_three_shapes[1][1][2][2] = true;
  tetris_functional__possible_three_shapes[1][2][0][0] = false;
  tetris_functional__possible_three_shapes[1][2][0][1] = false;
  tetris_functional__possible_three_shapes[1][2][0][2] = false;
  tetris_functional__possible_three_shapes[1][2][1][0] = true;
  tetris_functional__possible_three_shapes[1][2][1][1] = true;
  tetris_functional__possible_three_shapes[1][2][1][2] = true;
  tetris_functional__possible_three_shapes[1][2][2][0] = true;
  tetris_functional__possible_three_shapes[1][2][2][1] = false;
  tetris_functional__possible_three_shapes[1][2][2][2] = false;
  tetris_functional__possible_three_shapes[1][3][0][0] = true;
  tetris_functional__possible_three_shapes[1][3][0][1] = true;
  tetris_functional__possible_three_shapes[1][3][0][2] = false;
  tetris_functional__possible_three_shapes[1][3][1][0] = false;
  tetris_functional__possible_three_shapes[1][3][1][1] = true;
  tetris_functional__possible_three_shapes[1][3][1][2] = false;
  tetris_functional__possible_three_shapes[1][3][2][0] = false;
  tetris_functional__possible_three_shapes[1][3][2][1] = true;
  tetris_functional__possible_three_shapes[1][3][2][2] = false;
  tetris_functional__possible_three_shapes[2][0][0][0] = false;
  tetris_functional__possible_three_shapes[2][0][0][1] = true;
  tetris_functional__possible_three_shapes[2][0][0][2] = true;
  tetris_functional__possible_three_shapes[2][0][1][0] = true;
  tetris_functional__possible_three_shapes[2][0][1][1] = true;
  tetris_functional__possible_three_shapes[2][0][1][2] = false;
  tetris_functional__possible_three_shapes[2][0][2][0] = false;
  tetris_functional__possible_three_shapes[2][0][2][1] = false;
  tetris_functional__possible_three_shapes[2][0][2][2] = false;
  tetris_functional__possible_three_shapes[2][1][0][0] = false;
  tetris_functional__possible_three_shapes[2][1][0][1] = true;
  tetris_functional__possible_three_shapes[2][1][0][2] = false;
  tetris_functional__possible_three_shapes[2][1][1][0] = false;
  tetris_functional__possible_three_shapes[2][1][1][1] = true;
  tetris_functional__possible_three_shapes[2][1][1][2] = true;
  tetris_functional__possible_three_shapes[2][1][2][0] = false;
  tetris_functional__possible_three_shapes[2][1][2][1] = false;
  tetris_functional__possible_three_shapes[2][1][2][2] = true;
  tetris_functional__possible_three_shapes[2][2][0][0] = false;
  tetris_functional__possible_three_shapes[2][2][0][1] = false;
  tetris_functional__possible_three_shapes[2][2][0][2] = false;
  tetris_functional__possible_three_shapes[2][2][1][0] = false;
  tetris_functional__possible_three_shapes[2][2][1][1] = true;
  tetris_functional__possible_three_shapes[2][2][1][2] = true;
  tetris_functional__possible_three_shapes[2][2][2][0] = true;
  tetris_functional__possible_three_shapes[2][2][2][1] = true;
  tetris_functional__possible_three_shapes[2][2][2][2] = false;
  tetris_functional__possible_three_shapes[2][3][0][0] = true;
  tetris_functional__possible_three_shapes[2][3][0][1] = false;
  tetris_functional__possible_three_shapes[2][3][0][2] = false;
  tetris_functional__possible_three_shapes[2][3][1][0] = true;
  tetris_functional__possible_three_shapes[2][3][1][1] = true;
  tetris_functional__possible_three_shapes[2][3][1][2] = false;
  tetris_functional__possible_three_shapes[2][3][2][0] = false;
  tetris_functional__possible_three_shapes[2][3][2][1] = true;
  tetris_functional__possible_three_shapes[2][3][2][2] = false;
  tetris_functional__possible_three_shapes[3][0][0][0] = false;
  tetris_functional__possible_three_shapes[3][0][0][1] = true;
  tetris_functional__possible_three_shapes[3][0][0][2] = false;
  tetris_functional__possible_three_shapes[3][0][1][0] = true;
  tetris_functional__possible_three_shapes[3][0][1][1] = true;
  tetris_functional__possible_three_shapes[3][0][1][2] = true;
  tetris_functional__possible_three_shapes[3][0][2][0] = false;
  tetris_functional__possible_three_shapes[3][0][2][1] = false;
  tetris_functional__possible_three_shapes[3][0][2][2] = false;
  tetris_functional__possible_three_shapes[3][1][0][0] = false;
  tetris_functional__possible_three_shapes[3][1][0][1] = true;
  tetris_functional__possible_three_shapes[3][1][0][2] = false;
  tetris_functional__possible_three_shapes[3][1][1][0] = false;
  tetris_functional__possible_three_shapes[3][1][1][1] = true;
  tetris_functional__possible_three_shapes[3][1][1][2] = true;
  tetris_functional__possible_three_shapes[3][1][2][0] = false;
  tetris_functional__possible_three_shapes[3][1][2][1] = true;
  tetris_functional__possible_three_shapes[3][1][2][2] = false;
  tetris_functional__possible_three_shapes[3][2][0][0] = false;
  tetris_functional__possible_three_shapes[3][2][0][1] = false;
  tetris_functional__possible_three_shapes[3][2][0][2] = false;
  tetris_functional__possible_three_shapes[3][2][1][0] = true;
  tetris_functional__possible_three_shapes[3][2][1][1] = true;
  tetris_functional__possible_three_shapes[3][2][1][2] = true;
  tetris_functional__possible_three_shapes[3][2][2][0] = false;
  tetris_functional__possible_three_shapes[3][2][2][1] = true;
  tetris_functional__possible_three_shapes[3][2][2][2] = false;
  tetris_functional__possible_three_shapes[3][3][0][0] = false;
  tetris_functional__possible_three_shapes[3][3][0][1] = true;
  tetris_functional__possible_three_shapes[3][3][0][2] = false;
  tetris_functional__possible_three_shapes[3][3][1][0] = true;
  tetris_functional__possible_three_shapes[3][3][1][1] = true;
  tetris_functional__possible_three_shapes[3][3][1][2] = false;
  tetris_functional__possible_three_shapes[3][3][2][0] = false;
  tetris_functional__possible_three_shapes[3][3][2][1] = true;
  tetris_functional__possible_three_shapes[3][3][2][2] = false;
  tetris_functional__possible_three_shapes[4][0][0][0] = true;
  tetris_functional__possible_three_shapes[4][0][0][1] = true;
  tetris_functional__possible_three_shapes[4][0][0][2] = false;
  tetris_functional__possible_three_shapes[4][0][1][0] = false;
  tetris_functional__possible_three_shapes[4][0][1][1] = true;
  tetris_functional__possible_three_shapes[4][0][1][2] = true;
  tetris_functional__possible_three_shapes[4][0][2][0] = false;
  tetris_functional__possible_three_shapes[4][0][2][1] = false;
  tetris_functional__possible_three_shapes[4][0][2][2] = false;
  tetris_functional__possible_three_shapes[4][1][0][0] = false;
  tetris_functional__possible_three_shapes[4][1][0][1] = false;
  tetris_functional__possible_three_shapes[4][1][0][2] = true;
  tetris_functional__possible_three_shapes[4][1][1][0] = false;
  tetris_functional__possible_three_shapes[4][1][1][1] = true;
  tetris_functional__possible_three_shapes[4][1][1][2] = true;
  tetris_functional__possible_three_shapes[4][1][2][0] = false;
  tetris_functional__possible_three_shapes[4][1][2][1] = true;
  tetris_functional__possible_three_shapes[4][1][2][2] = false;
  tetris_functional__possible_three_shapes[4][2][0][0] = false;
  tetris_functional__possible_three_shapes[4][2][0][1] = false;
  tetris_functional__possible_three_shapes[4][2][0][2] = false;
  tetris_functional__possible_three_shapes[4][2][1][0] = true;
  tetris_functional__possible_three_shapes[4][2][1][1] = true;
  tetris_functional__possible_three_shapes[4][2][1][2] = false;
  tetris_functional__possible_three_shapes[4][2][2][0] = false;
  tetris_functional__possible_three_shapes[4][2][2][1] = true;
  tetris_functional__possible_three_shapes[4][2][2][2] = true;
  tetris_functional__possible_three_shapes[4][3][0][0] = false;
  tetris_functional__possible_three_shapes[4][3][0][1] = true;
  tetris_functional__possible_three_shapes[4][3][0][2] = false;
  tetris_functional__possible_three_shapes[4][3][1][0] = true;
  tetris_functional__possible_three_shapes[4][3][1][1] = true;
  tetris_functional__possible_three_shapes[4][3][1][2] = false;
  tetris_functional__possible_three_shapes[4][3][2][0] = true;
  tetris_functional__possible_three_shapes[4][3][2][1] = false;
  tetris_functional__possible_three_shapes[4][3][2][2] = false;
}
#endif /* TETRIS_FUNCTIONAL_ADS */
