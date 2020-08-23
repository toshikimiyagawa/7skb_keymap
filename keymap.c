#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _CAPS 3
#define _FN 4
#define _ADJUST 16
#define _LOWERCAPS 17

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  CAPS,
  ADJUST,
  LOWERCAPS,
  KVM_NXT,
  KVM_PRV,
  KVM_1,
  KVM_2,
  KVM_3,
  KVM_4,
};

#define LO_SPC LT(_LOWER, KC_SPC)
#define RA_ENT LT(_RAISE, KC_ENT)
#define WIN_V LGUI(KC_V)
#define L_DESC LGUI(LCTL(KC_LEFT))
#define R_DESC LGUI(LCTL(KC_RGHT))
#define P_TOYS LGUI(LALT(KC_SPC))
#define M_TASK LGUI(KC_TAB)
#define M_CAPS MO(_CAPS)
#define M_FN MO(_FN)
#define CTL_F13 CTL_T(KC_F13)
#define SFT_F14 SFT_T(KC_F14)
#define SFT_TAB LSFT(KC_TAB)
#define CTL_ENT LCTL(KC_ENT)
#define SFT_ENT LSFT(KC_ENT)
#define ALT_ENT LALT(KC_ENT)
#define CTL_SPC LCTL(KC_SPC)
#define SFT_SPC LSFT(KC_SPC)
#define ALT_SPC LALT(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
     KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,  KC_EQL, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LSFT, M_FN,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               KC_LALT, KC_F13, LOWER,  KC_SPC,               KC_ENT,  RAISE,          KC_F14, KC_LGUI
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_LOWER] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      XXXXXXX, KVM_1,  KVM_2,   KVM_3,   KVM_4,   XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_ENT, KC_ESC, KC_PGUP, KC_UP,   KC_PGDN,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_CAPS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,     XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, KC_BSPC, KC_DEL, WIN_V, XXXXXXX,      XXXXXXX, L_DESC,  M_TASK,  R_DESC, XXXXXXX, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, _______,          _______, _______ 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
  XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  XXXXXXX,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,KC_RPRN, KC_UNDS,   XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE,     KC_BSLS, XXXXXXX, XXXXXXX,   XXXXXXX,   KC_PLUS, KC_EQL, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, KC_LGUI, KC_LCTL, _______,              _______, _______,          _______, _______ 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_ADJUST] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,     XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, _______, _______,              _______, _______,          XXXXXXX, XXXXXXX 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_CAPS] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_END, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_TAB, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, KC_HOME, XXXXXXX, KC_DEL, KC_RGHT,  KC_ESC,     KC_BSPC, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT,     KC_DOWN, KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, KC_F13, KC_SPC,              KC_ENT, KC_F14,          XXXXXXX, XXXXXXX 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_FN] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_INS,   KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
     KC_CAPS, _______, _______, _______, _______, _______,     _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, _______, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______,KC_END, KC_PGDN, KC_DOWN, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              _______, _______,          KC_STOP, KC_APP 
          //`---------------------------------------------|   |--------------------------------------------'
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
      layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case KVM_PRV:
      if (record->event.pressed) {
        register_code(KC_SLCK);
        unregister_code(KC_SLCK);
        register_code(KC_SLCK);
        unregister_code(KC_SLCK);
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      }
      return false;
      break;
    case KVM_NXT:
      if (record->event.pressed) {
        register_code(KC_SLCK);
        unregister_code(KC_SLCK);
        register_code(KC_SLCK);
        unregister_code(KC_SLCK);
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      }
      return false;
      break;
    case KVM_1:
      if (record->event.pressed) {
        register_code(KC_SLCK);
        unregister_code(KC_SLCK);
        register_code(KC_SLCK);
        unregister_code(KC_SLCK);
        register_code(KC_1);
        unregister_code(KC_1);
      }
      return false;
      break;
    case KVM_2:
      if (record->event.pressed) {
        register_code(KC_SLCK);
        unregister_code(KC_SLCK);
        register_code(KC_SLCK);
        unregister_code(KC_SLCK);
        register_code(KC_2);
        unregister_code(KC_2);
      }
      return false;
      break;
    case KVM_3:
      if (record->event.pressed) {
        register_code(KC_SLCK);
        unregister_code(KC_SLCK);
        register_code(KC_SLCK);
        unregister_code(KC_SLCK);
        register_code(KC_3);
        unregister_code(KC_3);
      }
      return false;
      break;
    case KVM_4:
      if (record->event.pressed) {
        register_code(KC_SLCK);
        unregister_code(KC_SLCK);
        register_code(KC_SLCK);
        unregister_code(KC_SLCK);
        register_code(KC_4);
        unregister_code(KC_4);
      }
      return false;
      break;
  }
  return true;
}
void keyboard_post_init_user(void) {
  #ifdef CONSOLE_ENABLE
  // Customise these values to desired behaviour
  debug_enable=true;
  // debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
  #endif 
}