/* Copyright 2018 'mechmerlin'
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

#define MY_HSV_PURPLEx 282u,255u,62u
#define MY_HSV_PURPLE (uint8_t)202,(uint8_t)255,(uint8_t)250

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Home|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgUp|
   * |----------------------------------------------------------------|
   * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt | fn     |win| space    |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[0] = LAYOUT_65_ansi_split_sp(
  KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_ESC,  \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
  KC_LCTL, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT, KC_PGUP,  \
  KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,           KC_UP, KC_PGDN,  \
  MO(2), KC_LGUI, KC_LALT,    MO(1),        KC_LGUI,        KC_SPC,  KC_RALT, MO(2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT          ),

  /* Keymap Fn Layer
   * ,----------------------------------------------------------------.
   * |~ `|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |PSc|SLk|Pau|Up |   |     |    |
   * |----------------------------------------------------------------|
   * |      |Lef|Dow|Rig|   |   |   |   |Hom|PUp|Lef|Rig|        |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |End|PDn|Dow|      |PUp|    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |Hom|PDn|End |
   * `----------------------------------------------------------------'
   */
[1] = LAYOUT_65_ansi_split_sp(
   KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,          KC_DEL,KC_MUTE, \
   KC_MPLY,KC_MNXT,  KC_UP,_______,_______,_______,_______,_______,KC_INS, _______, KC_PSCR, KC_UP,_______,     _______,KC_END,   \
   _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,_______,_______,_______, KC_VOLU, \
   _______,_______,_______,_______,_______,_______,_______,_______, KC_END,KC_PGDN,KC_DOWN,_______,KC_PGUP,KC_VOLD, \
   _______,  _______,  _______,_______,            _______, _______,  _______,_______,_______,KC_HOME,KC_PGDN, KC_END),

  /* Keymap Fn Layer --- this seems like the defacto standard
   * ,----------------------------------------------------------------.
   * |~ `|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |PSc|SLk|Pau|Up |   |     |    |
   * |----------------------------------------------------------------|
   * |      |Lef|Dow|Rig|   |   |   |   |Hom|PUp|Lef|Rig|        |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |End|PDn|Dow|      |PUp|    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |Hom|PDn|End |
   * `----------------------------------------------------------------'
   */
[2] = LAYOUT_65_ansi_split_sp(
   KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,          KC_DEL,KC_INS, \
   _______,_______,  KC_UP,_______,_______,_______,_______,_______,KC_PSCR,KC_SLCK,KC_PAUS,  KC_UP,_______,     _______,_______,   \
   _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,_______,_______,KC_HOME,KC_PGUP,KC_LEFT,KC_RGHT,            _______,_______, \
   _______,_______,_______,_______,_______,_______,_______,_______, KC_END,KC_PGDN,KC_DOWN,       _______,KC_PGUP,_______, \
   _______,  _______,  _______,_______,            _______, _______,  _______,_______,_______,KC_HOME,KC_PGDN, KC_END),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}


void matrix_scan_user(void) {
    /* uint8_t layer = biton32(layer_state); */
   

    /* switch(layer) */
    /* { */
        /* default: */
            /* led_default_layer(); */
            /* break; */
    /* } */
    /* rgblight_sethsv_range(HSV_PURPLE, 0, RGBLED_NUM-1); */
    /* rgblight_sethsv_noeeprom(HSV_PURPLE); */
}


void led_set_user(uint8_t usb_led) {

}

/* // Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore! */
/* const rgblight_segment_t PROGMEM led_layer1[] = RGBLIGHT_LAYER_SEGMENTS( */
    /* {1, 20, HSV_PURPLE},       // Light 4 LEDs, starting with LED 6 */
/* ); */

/* // Now define the array of layers. Later layers take precedence */
/* const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST( */
    /* my_default, */
/* ); */

void keyboard_post_init_user(void) {
    // Enable the LED layers
    /* rgblight_layers = my_rgb_layers; */
    rgblight_sethsv_noeeprom(MY_HSV_PURPLE);
}
