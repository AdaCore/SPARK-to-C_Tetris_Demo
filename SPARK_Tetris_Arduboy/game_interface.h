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
