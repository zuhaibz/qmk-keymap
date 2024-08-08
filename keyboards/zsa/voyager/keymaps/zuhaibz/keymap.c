// Copyright 2024 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file keymap.c
 * @brief Pascal's keymap for the ZSA Voyager.
 *
 * This file defines what keycode is performed by each key position. See also
 * getreuer.c for definitions of macros, etc. used in my keymap.
 */

#include QMK_KEYBOARD_H

#include "voyager.h"
#include "layout.h"
#include "zuhaibz.c"

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     [0] = LAYOUT(
//         KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
//         CW_TOGG, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
//         SFT_T(KC_BSPC),KC_A, KC_S, KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RSFT_T(KC_QUOT),
//         KC_LGUI, ALT_T(KC_Z),KC_X, KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMMA,KC_DOT,  RALT_T(KC_SLSH), KC_RCTL,
//                                 LT(1,KC_ENT), CTL_T(KC_TAB),           SFT_T(KC_BSPC), LT(2,KC_SPC)
//     ),
//     [1] = LAYOUT(
//         KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//         KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_7,    KC_8,    KC_9,    KC_MINS, KC_SLSH, KC_F12,
//         _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                      KC_4,    KC_5,    KC_6,    KC_PLUS, KC_ASTR, KC_BSPC,
//         _______, _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,                      KC_1,    KC_2,    KC_3,    KC_DOT,  KC_EQL,  KC_ENT,
//                                                      _______, _______,    _______, KC_0
//     ),
//     [2] = LAYOUT(
//         RGB_TOG, QK_KB,   RGB_MOD, RGB_M_P, RGB_VAD, RGB_VAI,                      _______, _______, _______, _______, _______, QK_BOOT,
//         _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,                      KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
//         _______, KC_MPRV, KC_MNXT, KC_MSTP, KC_MPLY, _______,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
//         _______, _______, _______, _______, _______, _______,                      _______, C(S(KC_TAB)), C(KC_TAB), _______, _______, _______,
//                                                      _______, _______,    _______, _______
//     ),
// };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_LR(  // Base layer.
    KC_GRV,     G(KC_TAB),   SELLINE,    KC_DOWN,   KC_UP,      KC_BTN1,
    KC_TAB,     KC_Q,        KC_W,       KC_E,      FUN_R,      KC_T,
    KC_BSPC,    HOME_A,      HOME_S,     HOME_D,    HOME_F,     KC_G,
    WIN_MINUS,  HOME_Z,      KC_X,       KC_C,      NUM_V,      KC_B,
                                                    LGUI_UNDS,  WIN_ENT,

    KC_HOME, KC_LEFT, KC_RGHT , KC_END , KC_DEL , KC_MPLY,
    KC_B, MAGIC  , KC_U   , KC_O   , KC_Q   , KC_SLSH,
    KC_F, HOME_N , HOME_E , HOME_A , HOME_I , KC_QUOT,
    KC_Z, KC_H   , KC_COMM, KC_DOT , HOME_SC, KC_ENT ,
    QK_REP , KC_ESC
  ),

  [SYM] = LAYOUT_LR(  // Symbol layer.
    _______, C(KC_Z), C(KC_V), C(KC_A), C(KC_C), C(KC_X),
    TMUXESC, MO(FUN), KC_LABK, KC_RABK, KC_BSLS, KC_GRV ,
    _______, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH,
    _______, _______, KC_SLSH, KC_ASTR, KC_CIRC, USRNAME,
                                                 _______, _______,

                      C(KC_PGUP), KC_PGDN, KC_PGUP, C(KC_PGDN),  _______, KC_MUTE,
                      KC_AMPR, ARROW  , KC_LBRC, KC_RBRC, SRCHSEL, _______,
                      KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_PERC, _______,
                      KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, _______, _______,
             _______, _______
  ),

  [NUM] = LAYOUT_LR(  // Number layer.
    _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,
    _______, KC_LGUI, XXXXXXX, KC_LCTL, XXXXXXX, XXXXXXX,
                                                 TO(BASE), _______,

                      _______, _______, _______, _______, _______, _______,
                      KC_TAB , KC_8   , KC_9   , KC_4   , KC_PLUS, KC_SLSH,
                      KC_COLN, KC_1   , KC_2   , KC_3   , KC_MINS, KC_ASTR,
                      KC_COMM, KC_7   , KC_6   , KC_5   , KC_DOT , _______,
             KC_0   , LLOCK
  ),

  [WIN] = LAYOUT_LR(  // Window management layer.
    RGB_TOG, RGB_DEF, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,
    XXXXXXX, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 XXXXXXX, G(KC_SPC),

                      XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,
                      G(KC_TAB), G(KC_8), G(KC_9), G(KC_4), XXXXXXX, XXXXXXX,
                      G(S(KC_LEFT)), G(KC_1), G(KC_2), G(KC_3), G(S(KC_RGHT)), XXXXXXX,
                      XXXXXXX, G(KC_7), G(KC_6), G(KC_5), KC_VOLD , KC_VOLU,
             QK_REP , XXXXXXX
  ),

  [FUN] = LAYOUT_LR(  // Funky fun layer.
    _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,
    _______, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                 TO(BASE), _______,

                      _______, _______, _______, _______, _______, QK_BOOT,
                      XXXXXXX, KC_F8  , KC_F9  , KC_F4  , KC_F10 , XXXXXXX,
                      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F11 , XXXXXXX,
                      XXXXXXX, KC_F7  , KC_F6  , KC_F5  , KC_F12 , _______,
             XXXXXXX, LLOCK
  ),
};


