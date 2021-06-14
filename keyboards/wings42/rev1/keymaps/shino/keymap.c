/* Copyright 2021 yfuku
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_number {
    _FINCOL = 0,
    _SYMBOL,
    _S_SYMB,
    _EXTRA,
};

enum custom_keycodes {
  FINCOL = SAFE_RANGE,
  SYMBOL_ON,
  SYMBOL_OFF,
  S_SYMB,
  EXTRA_ON,
  EXTRA_OFF
};

// common
#define KC_     KC_TRNS

// IME
#define KC_EN   KC_LANG2        // En
#define KC_JA   KC_LANG1        // Ja
#define KC_sf_l LSFT(KC_LEFT)   // Shorten
#define KC_sf_r LSFT(KC_RGHT)   // Widen

// Launcher
#define KC_LP   KC_F2
#define KC_LS   KC_F3

// Left thumbs
#define KC_LPgu LGUI_T(KC_LP)
#define KC_LPal LALT_T(KC_LP)
#define KC_LSct LCTL_T(KC_LS)
#define KC_JAex LT(_S_SYMB, KC_JA)

// Right thumbs
#define KC_SPsy LT(_SYMBOL, KC_SPC)
#define KC_MIss LT(_S_SYMB, KC_MINUS)
#define KC_ENex LT(_S_SYMB, KC_EN)

// with shift
#define KC_A_sf LSFT_T(KC_A)
#define KC_R_sf LSFT_T(KC_R)

/* // Toggle layers */
/* #define KC_ex   EXTRA_ON */
/* #define KC_exx  EXTRA_OFF */
/* #define KC_sy   SYMBOL_ON */
/* #define KC_syx  SYMBOL_OFF */
/* #define KC__ss  TG(_S_SYMB) */


// misc
#define KC_RSET RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_FINCOL] = LAYOUT_kc(
  //,------+------+------+------+------+------.   ,------+------+------+------+------+------.
      VOLU ,  Q   ,  D   ,  Y   ,  C   , MPLY ,     RGHT ,  B   ,  N   ,  P   ,  F   ,  UP  ,
  //|------+------+------+------+------+------|   |------+------+------+------+------+------|
      VOLD , A_sf ,  O   ,  E   ,  I   ,  U   ,      G   ,  M   ,  S   ,  T   , R_sf , ENT  ,
  //|------+------+------+------+------+------|   |------+------+------+------+------+------|
      WBAK ,  V   ,  X   ,  W   ,  Z   , DEL  ,     LEFT ,  H   ,  J   ,  K   ,  L   , DOWN ,
  //`------+------+------+------+------+------'   `------+------+------+------+------+------'
                           ENex , LSct , LPal ,     MIss , SPsy , JAex
  //                     `------+------+------'   `------+------+------'
  ),

  [_SYMBOL] = LAYOUT_kc( \
  //,------+------+------+------+------+------.   ,------+------+------+------+------+------.
           ,  0   ,  7   ,  8   ,  9   ,      ,          , LPRN , RPRN , LBRC , RBRC ,      ,
  //|------+------+------+------+------+------|   |------+------+------+------+------+------|
           ,  0   ,  4   ,  5   ,  6   , TILD ,     PLUS , EQL  , COMM , DOT  , SLSH ,      ,
  //|------+------+------+------+------+------|   |------+------+------+------+------+------|
           ,  0   ,  1   ,  2   ,  3   ,      ,          ,      ,      ,      ,      ,      ,
  //`------+------+------+------+------+------'   `------+------+------+------+------+------'
                                ,      ,      ,          ,      ,
  //                     `------+------+------'   `------+------+------'
  ),

  [_S_SYMB] = LAYOUT_kc( \
  //,------+------+------+------+------+------.   ,------+------+------+------+------+------.
           , sf_l , AMPR , ASTR , sf_r ,      ,          , QUOT , DQUO , LCBR , RCBR , RSET ,
  //|------+------+------+------+------+------|   |------+------+------+------+------+------|
           , PIPE , DLR  , PERC , CIRC ,      ,     GRV  , COLN ,  LT  ,  GT  , QUES ,      ,
  //|------+------+------+------+------+------|   |------+------+------+------+------+------|
           , BSLS , EXLM ,  AT  , HASH ,      ,          , SCLN ,      ,      ,      ,      ,
  //`------+------+------+------+------+------'   `------+------+------+------+------+------'
                                ,      ,      ,          ,      ,
  //                     `------+------+------'   `------+------+------'
  ),

  [_EXTRA] = LAYOUT_kc( \
  //,------+------+------+------+------+------.   ,------+------+------+------+------+------.
           ,      ,      ,      ,      ,      ,          , WH_L , WH_D , WH_U , WH_R ,      ,
  //|------+------+------+------+------+------|   |------+------+------+------+------+------|
           ,      ,      ,      ,      ,      ,          , MS_L , MS_D , MS_U , MS_R ,      ,
  //|------+------+------+------+------+------|   |------+------+------+------+------+------|
           ,      ,      ,      ,      ,      ,          , LEFT , DOWN ,  UP  , RGHT ,      ,
  //`------+------+------+------+------+------'   `------+------+------+------+------+------'
                                ,      ,      ,          , BTN1 , BTN2
  //                     `------+------+------'   `------+------+------'
  ),
};
