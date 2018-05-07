
#include "ergo42.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,------------------------------------------------.   ,------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |  [   |   |  ]   |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Alt  |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   K  |   L  |   ;  |  :   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |   Z  |   X  |   C  |   V  |   B  |  {   |   |  }   |   N  |   M  |   ,  |   .  |   /  |  \   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |PrtSc | GUI  |=>SYMB|  \   |
 * |      |      |      |      |~SYMB |RCtrl |Shift |   |Space |~META |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[BASE] = KEYMAP( \
  KC_ESC,   KC_Q,    KC_W,   KC_E,    KC_R,             KC_T,          KC_LBRC,       KC_RBRC,    KC_Y,             KC_U,    KC_I,     KC_O,     KC_P,     KC_MINS, \
  KC_LALT,  KC_A,    KC_S,   KC_D,    KC_F,             KC_G,          S(KC_9),       S(KC_0),    KC_H,             KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,   KC_C,    KC_V,             KC_B,          S(KC_LBRC),    S(KC_RBRC), KC_N,             KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_BSLS, \
  KC_LCTRL, KC_LGUI, KC_APP, KC_PSCR, LT(SYMB, KC_ESC), RCTL_T(KC_SPC), SFT_T(KC_TAB), KC_BSPC,    LT(META, KC_ENT), KC_DELT, KC_PSCR,  KC_RGUI, TG(SYMB), KC_JYEN \
),

/* META
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |  [   |   |  ]   |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Alt  |  F1  |      |Muhen | Henk |      |  (   |   |  )   | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |  F2  |  F3  |  F4  |  F5  |  F6  |  {   |   |  }   |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |Reset | GUI  |=>SYMB|  \   |
 * |      |      |      |      |~SYMB |RCtrl |Shift |   |Space |~META |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[META] = KEYMAP( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,  KC_0,    KC_MINS, \
  _______, KC_F1,   XXXXXXX, KC_MHEN, KC_HENK, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, \
  _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, _______, _______, _______ \
),

/* SYMB
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   !  |   "  |   #  |   $  |   %  |   &  |  [   |   |  ]   |   '  |   (  |   )  |   ~  |   =  |  ~   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Alt  |      |      |      |      |      |  (   |   |  )   |      |      |      |      |   +  |  *   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |      |      |      |      |      |  {   |   |  }   |      |      |   <  |   >  |   ?  |  \   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |   |Back  |Enter/| Del  |PrtSc | GUI  |=>SYMB|  \   |
 * |      |      |      |      |~SYMB |RCtrl |Shift |   |Space |~META |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[SYMB] = KEYMAP( \
  S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), _______, _______, S(KC_7), S(KC_8), S(KC_9),    S(KC_0),   S(KC_MINS), S(KC_EQL), \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,   S(KC_SCLN), S(KC_QUOT), \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_RO), \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______ \
)

};

