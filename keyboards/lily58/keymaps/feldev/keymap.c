/*
* Voir muuko render_anim()
*
*/
#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

enum custom_keycodes {
  STRIPE = SAFE_RANGE,
};

enum layer_number {
  _QWERTY = 0,
  _CODE,
  _MOUSE,
  _FKEYS,
  TODO,
  _ARROWS,
  _NUMPAD,
  _ACCENT,
  _MACROS,
  template,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT( \
  KC_ESC,       KC_1,         KC_2,         KC_3,        KC_4,        KC_5,                             KC_6,       KC_7,         KC_8,            KC_9,           KC_0,            KC_CAPSLOCK, \
  KC_TAB,       KC_Q,         KC_W,         KC_E,        KC_R,        KC_T,                             KC_Y,       KC_U,         KC_I,            KC_O,           KC_P,            KC_MINS, \
  KC_TAB,       LT(8,KC_A),   LT(7,KC_S),   LT(6,KC_D),  LT(3,KC_F),  KC_G,                             KC_H,       KC_J,         LT(1,KC_K),      LT(2,KC_L),     KC_SCLN,         KC_ENT, \
  KC_LSFT,      LCTL_T(KC_Z), LALT_T(KC_X), LGUI_T(KC_C),LSFT_T(KC_V),KC_B,  TG(6),    LCA(LGUI(KC_S)), KC_N,       LSFT_T(KC_M), LGUI_T(KC_COMM), LALT_T(KC_DOT), LCTL_T(KC_SLSH), KC_BSPC, \
                                  KC_ENT,        KC_LALT,      KC_LGUI,    KC_SPC,          KC_RSFT,     MO(5),     TG(5),      KC_RGUI \
  ),

  [_CODE] = LAYOUT( \
  KC_TRNS,       KC_TRNS,         KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                         KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS, \
  KC_F1,         KC_EXLM,         KC_EQL,       LALT(KC_9),   LALT(KC_0),   KC_LALT,                         KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_F11,       KC_F12, \
  LALT(KC_GRV),  LALT(KC_COMM),   LALT(KC_DOT), KC_LPRN,      KC_RPRN,      KC_LALT,                         KC_CIRC,      KC_MINS,      KC_ASTR,      KC_UNDS,      KC_LALT,      KC_TILD, \
  LALT(KC_GRV),  KC_NONUS_BSLASH, KC_MINS,      LALT(KC_7),   LALT(KC_8),   KC_AMPR,  KC_TRNS,     KC_TRNS,  KC_NO,        KC_UNDS,      KC_PLUS,      KC_TRNS,      KC_TRNS,      KC_PIPE,\
                            LALT(KC_RBRACKET),      KC_TRNS,      KC_TRNS,          KC_TRNS,         KC_TRNS,      MO(3),      KC_TRNS,      KC_TRNS \
  ),

	[_MOUSE] = LAYOUT( \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS, \
  KC_GRV,       KC_1,         KC_2,         KC_MS_U,      KC_4,         KC_5,                             KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         KC_TRNS, \
  KC_F1,        KC_F2,        KC_MS_L,      KC_MS_D,      KC_MS_R,      KC_F6,                            KC_ACL2,      KC_ACL1,      KC_ACL0,      KC_NO,        KC_RGHT,      KC_TRNS, \
  KC_F7,        KC_F8,        KC_F9,        KC_F10,       KC_F11,       KC_F12, KC_TRNS,        KC_TRNS,  KC_PLUS,      KC_MINS,      KC_EQL,       KC_TRNS,      KC_RBRC,      KC_BSLS, \
                                KC_TRNS,      KC_TRNS,      MO(3),        KC_BTN2,                KC_BTN1,      KC_TRNS,      KC_TRNS,      KC_TRNS \
  ),

  [_FKEYS] = LAYOUT( \
  KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_F10,      KC_F11,       KC_F12,      KC_F13,      KC_F17, \
  KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_F7,       KC_F8,        KC_F9,       KC_F14,      KC_F18, \
  KC_TRNS,      LGUI(KC_EQL), RCS(KC_TAB),  LCTL(KC_TAB), KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_F4,       KC_F5,        KC_F6,       KC_F15,      KC_F19, \
  KC_TRNS,      KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,      KC_F1,       KC_F2,        KC_F3,       KC_F16,      KC_F20, \
                                KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS \
  ),

	[TODO] = LAYOUT(\
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
                                KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS \
  ),

	[_ARROWS] = LAYOUT(\
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_TRNS,     KC_UP,        KC_TRNS,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_LALT,      KC_LGUI,      KC_RSFT,      KC_TRNS,                          KC_TRNS,      KC_LEFT,     KC_DOWN,      KC_RGHT,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
                                KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS \
  ),

	[_NUMPAD] = LAYOUT(\
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                           KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                           KC_PERC,      KC_7,        KC_8,         KC_9,         KC_PPLS,      KC_BSLS, \
  KC_TRNS,      KC_TRNS,      KC_LALT,      KC_TRNS,      KC_RSFT,      KC_TRNS,                           KC_PAST,      KC_4,        KC_5,         KC_6,         KC_PMNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_EQL,       KC_1,        KC_2,         KC_3,         KC_PSLS,      KC_TRNS, \
                                KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                 KC_TRNS,      KC_DOT,      KC_0,      KC_DOT \
  ),

 [_ACCENT] = LAYOUT(\
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_TRNS,     KC_TRNS,        KC_TRNS,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_QUOTE,     KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_GRV,      LSFT(KC_LBRC),  KC_LBRC,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_BSLS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_TRNS,     KC_TRNS,        KC_TRNS,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_RBRC,      KC_TRNS,      KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,      KC_TRNS,     KC_TRNS,        KC_TRNS,       KC_TRNS,      KC_TRNS, \
                                KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS \
  ),

  [_MACROS] = LAYOUT(\
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      STRIPE,      KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
                                KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS \
  ),

 [template] = LAYOUT(\
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                          KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,       KC_TRNS,      KC_TRNS, \
                                KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,                KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS \
  ),

  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("La base, mon chum.\n"), false);
            break;
        case _CODE:
            oled_write_P(PSTR("CODE\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Une souris verte\n"), false);
            break;
        case _FKEYS:
            oled_write_P(PSTR("FUNCTION KEYS\n"), false);
            break;
        case TODO:
            oled_write_P(PSTR("TODO\n"), false);
            break;
        case _ARROWS:
            oled_write_P(PSTR("LES FLECHES\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("NUMPAD\n"), false);
            break;
        case _ACCENT:
            oled_write_P(PSTR("ACCENT\n"), false);
            break;
        case _MACROS:
            oled_write_P(PSTR("MACROS (les poissons)\n"), false);
            break;
        case template:
            oled_write_P(PSTR("template\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJUST (Loud Larry)\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // If you want to change the display of OLED, you need to change here
      // oled_write_ln(read_layer_state(), false);
      // oled_write_ln(read_keylog(), false);
      // oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE
    

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
// #ifdef OLED_DRIVER_ENABLE
//     set_keylog(keycode, record);
// #endif
//     // set_timelog();
//   }
//   return true;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case STRIPE:
      if (record->event.pressed) {
        SEND_STRING("4242424242424242");
      }
      break;
  }
  return true;
}



/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
/*
[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,\
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, \
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
                             _______, _______, _______, _______, _______,  _______, _______, _______\
),
*/

