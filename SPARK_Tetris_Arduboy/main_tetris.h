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

#ifndef INTERFAC_ADS
#define INTERFAC_ADS
typedef unsigned_32 interfaces__unsigned_32;

#endif /* INTERFAC_ADS */

#ifndef TETRIS_FUNCTIONAL_ADS
#define TETRIS_FUNCTIONAL_ADS
typedef integer_8 tetris_functional__cell;
enum {tetris_functional__empty=0, tetris_functional__i=1, tetris_functional__o=2, tetris_functional__j=3, tetris_functional__l=
  4, tetris_functional__s=5, tetris_functional__t=6, tetris_functional__z=7};
typedef character tetris_functional__TcellSS[12];
extern const tetris_functional__TcellSS tetris_functional__cellS;
typedef integer_8 tetris_functional__TcellNT[9];
extern const tetris_functional__TcellNT tetris_functional__cellN;
typedef tetris_functional__cell tetris_functional__shape;
typedef integer tetris_functional__x_coord;
typedef integer tetris_functional__y_coord;
typedef tetris_functional__cell tetris_functional__line[10];
typedef tetris_functional__line tetris_functional__board[20];
extern tetris_functional__board tetris_functional__cur_board;
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
extern const tetris_functional__TdirectionSS tetris_functional__directionS;
typedef integer_8 tetris_functional__TdirectionNT[5];
extern const tetris_functional__TdirectionNT tetris_functional__directionN;
extern tetris_functional__piece tetris_functional__cur_piece;
typedef integer_8 tetris_functional__state;
enum {tetris_functional__piece_falling=0, tetris_functional__piece_blocked=1, tetris_functional__board_before_clean=
  2, tetris_functional__board_after_clean=3};
typedef character tetris_functional__TstateSS[61];
extern const tetris_functional__TstateSS tetris_functional__stateS;
typedef integer_8 tetris_functional__TstateNT[5];
extern const tetris_functional__TstateNT tetris_functional__stateN;
extern tetris_functional__state tetris_functional__cur_state;
typedef integer tetris_functional__i_delta;
typedef boolean tetris_functional__oriented_i_shape[4][4];
typedef integer tetris_functional__three_delta;
typedef boolean tetris_functional__oriented_three_shape[3][3];
typedef tetris_functional__oriented_i_shape tetris_functional__T35s[4];
extern tetris_functional__T35s tetris_functional__possible_i_shapes;
typedef tetris_functional__oriented_three_shape tetris_functional__T98s[5][4];
extern tetris_functional__T98s tetris_functional__possible_three_shapes;
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
extern const tetris_functional__TactionSS tetris_functional__actionS;
typedef integer_8 tetris_functional__TactionNT[6];
extern const tetris_functional__TactionNT tetris_functional__actionN;
typedef tetris_functional__action tetris_functional__turn_action;
extern tetris_functional__direction tetris_functional__turn_direction(tetris_functional__direction d, tetris_functional__turn_action t);
extern boolean tetris_functional__move_is_possible(const tetris_functional__piece p, tetris_functional__action a);
extern tetris_functional__piece tetris_functional__move(const tetris_functional__piece p, tetris_functional__action a);
extern void tetris_functional__do_action(tetris_functional__action a, boolean *success);
extern void tetris_functional__include_piece_in_board(void);
extern void tetris_functional__delete_complete_lines(natural *number_of_complete_lines);
#endif /* TETRIS_FUNCTIONAL_ADS */

#ifndef GAME_INTERFACE_ADS
#define GAME_INTERFACE_ADS
extern void game_interface__clear_screen(void);
extern void game_interface__update_screen(void);
extern void game_interface__set_screen_pixel(integer x, integer y);
extern void game_interface__display_score(interfaces__unsigned_32 score, interfaces__unsigned_32 level);
extern void game_interface__game_over(void);
extern void game_interface__delay_ms(interfaces__unsigned_32 ms);
extern integer game_interface__button_right_pressed(void);
extern integer game_interface__button_turn_pressed(void);
extern integer game_interface__button_left_pressed(void);
extern integer game_interface__button_down_pressed(void);
#endif /* GAME_INTERFACE_ADS */

#ifndef MAIN_TETRIS_ADS
#define MAIN_TETRIS_ADS
extern void _ada_main_tetris(void);
#endif /* MAIN_TETRIS_ADS */

#ifndef SYSTEM_ADS
#define SYSTEM_ADS
typedef integer_8 system__name;
enum {system__system_name_gnat=0};
typedef character system__TnameSS[16];
extern const system__TnameSS system__nameS;
typedef integer_8 system__TnameNT[2];
extern const system__TnameNT system__nameN;
extern const system__name system__system_name;
typedef void* system__address;
extern const system__address system__null_address;
typedef integer_8 system__bit_order;
enum {system__high_order_first=0, system__low_order_first=1};
typedef character system__Tbit_orderSS[31];
extern const system__Tbit_orderSS system__bit_orderS;
typedef integer_8 system__Tbit_orderNT[3];
extern const system__Tbit_orderNT system__bit_orderN;
extern const system__bit_order system__default_bit_order;
extern const positive system__max_priority;
extern const positive system__max_interrupt_priority;
typedef integer system__priority;
extern const system__priority system__default_priority;
extern const boolean system__backend_divide_checks;
extern const boolean system__backend_overflow_checks;
extern const boolean system__command_line_args;
extern const boolean system__configurable_run_time;
extern const boolean system__denorm;
extern const boolean system__duration_32_bits;
extern const boolean system__exit_status_supported;
extern const boolean system__fractional_fixed_ops;
extern const boolean system__frontend_layout;
extern const boolean system__machine_overflows;
extern const boolean system__machine_rounds;
extern const boolean system__preallocated_stacks;
extern const boolean system__signed_zeros;
extern const boolean system__stack_check_default;
extern const boolean system__stack_check_probes;
extern const boolean system__stack_check_limits;
extern const boolean system__support_aggregates;
extern const boolean system__support_composite_assign;
extern const boolean system__support_composite_compare;
extern const boolean system__support_long_shifts;
extern const boolean system__always_compatible_rep;
extern const boolean system__suppress_standard_library;
extern const boolean system__use_ada_main_program_name;
extern const boolean system__frontend_exceptions;
extern const boolean system__zcx_by_default;
#endif /* SYSTEM_ADS */
