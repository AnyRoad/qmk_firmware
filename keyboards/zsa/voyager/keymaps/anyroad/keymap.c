#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_SEARCH,
  ST_MACRO_GOOGLE,
  ST_MACRO_GOLINK,
  ST_MACRO_DICT,
  ST_MACRO_CUR_INTELLIJ,
  ST_MACRO_IN_NEW_TAB,
  MAC_MISSION_CONTROL,
  DRAG_SCROLL,
  TOGGLE_SCROLL,
  NAVIGATOR_INC_CPI,
  NAVIGATOR_DEC_CPI,
  NAVIGATOR_TURBO,
  NAVIGATOR_AIM
};



#define DUAL_FUNC_0 LT(15, KC_F8)
#define DUAL_FUNC_1 LT(10, KC_F10)
#define DUAL_FUNC_2 LT(9, KC_V)
#define DUAL_FUNC_3 LT(14, KC_9)
#define DUAL_FUNC_4 LT(8, KC_R)
#define DUAL_FUNC_5 LT(15, KC_F15)
#define DUAL_FUNC_6 LT(12, KC_W)
#define DUAL_FUNC_7 LT(3, KC_Y)
#define DUAL_FUNC_8 LT(7, KC_1)
#define DUAL_FUNC_9 LT(3, KC_F1)
#define DUAL_FUNC_10 LT(7, KC_8)
#define DUAL_FUNC_11 LT(2, KC_M)

enum LAYERS {
    MAIN,
    NUM_FUNC,
    NAVIGATION,
    SYMBOLS,
    INTELLIJ,
    EXTRAS,
    CONTROLS,
    MOUSE
};

#define KC_TRANSPARENT KC_TRNS
#define KC_PRTSCR LGUI(LCTL(LSFT(KC_4)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAIN] = LAYOUT_voyager(
    KC_PRTSCR,      KC_Q,            KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           QK_LEAD,    
    KC_ESCAPE,      LT(MOUSE, KC_A), KC_S,           MT(MOD_LALT, KC_D),MT(MOD_LGUI, KC_F), DUAL_FUNC_0,                             KC_H,           MT(MOD_RGUI, KC_J),MT(MOD_RALT, KC_K),KC_L,     KC_SCLN,        LGUI(KC_SPACE), 
    KC_LEFT_SHIFT,  MT(MOD_LCTL, KC_Z),KC_X,         KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         MT(MOD_RCTL, KC_SLASH),KC_RIGHT_SHIFT, 
    KC_NO,          KC_NO,           KC_NO,          KC_NO,          TT(NAVIGATION), KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,        CW_TOGG,        
                                                    MT(MOD_LGUI, KC_BSPC),LT(INTELLIJ, KC_ENTER),                                    LT(NUM_FUNC, KC_TAB),  LT(SYMBOLS, KC_SPACE)
  ),
  [NUM_FUNC] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    QK_LLCK,        KC_1,           KC_2,           MT(MOD_LALT, KC_3),MT(MOD_LGUI, KC_4),           KC_5,                          KC_6,           MT(MOD_RGUI, KC_7),MT(MOD_RALT, KC_8),           KC_9,           KC_0,           KC_F12,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,                                                     KC_TRNS,  KC_TRNS,        KC_TRNS,     KC_TRNS, KC_TRNS,          KC_TRNS, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [NAVIGATION] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_NO,  KC_NO,     KC_NO,       KC_NO,     ST_MACRO_IN_NEW_TAB,                                 LGUI(KC_LEFT),  KC_END,         KC_HOME,        LGUI(KC_RIGHT), KC_NO,          KC_F12,         
    KC_TRANSPARENT, LGUI(KC_A),     KC_NO,     ST_MACRO_DICT,     ST_MACRO_SEARCH,      ST_MACRO_GOOGLE,                                    KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,     KC_TRANSPARENT, 
    KC_TRANSPARENT, LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     DUAL_FUNC_1,    KC_TRNS,                                  LALT(KC_LEFT),  KC_PGDN,        KC_PAGE_UP,     LALT(KC_RIGHT), KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRNS,        KC_TRNS,        KC_TRNS,          KC_TRNS,          KC_TRNS,                                          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,         KC_TRNS,         
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [SYMBOLS] = LAYOUT_voyager(
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_F12,         
    QK_LLCK,        KC_GRAVE,       KC_QUOTE,       DUAL_FUNC_2,    KC_PLUS,        KC_LBRC,                                        KC_RBRC,        KC_MINUS,       DUAL_FUNC_4,    KC_EQUAL,       KC_COLN,        KC_DQUO,        
    KC_TRANSPARENT, DUAL_FUNC_3,    KC_BSLS,        KC_SLASH,       KC_TRANSPARENT, KC_LCBR,                                        KC_RCBR,        KC_TRANSPARENT, KC_LABK,        KC_RABK,        DUAL_FUNC_5,    KC_TRANSPARENT, 
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,         KC_TRNS,         
                                                    MT(MOD_LGUI, KC_DELETE),KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [INTELLIJ] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, LALT(LCTL(KC_V)),LALT(KC_F12),   LCTL(LSFT(KC_R)),LGUI(LCTL(LSFT(KC_LEFT))),                                LGUI(LCTL(LSFT(KC_RIGHT))),LALT(LCTL(LSFT(KC_V))),LALT(KC_F7),    LALT(LCTL(LSFT(KC_O))),LALT(LCTL(LSFT(KC_P))),LGUI(KC_F12),   
    QK_LLCK, KC_TRNS, LALT(LSFT(KC_UP)),ST_MACRO_CUR_INTELLIJ,     LCTL(LSFT(KC_F)),LALT(LGUI(KC_LEFT)),                                LALT(LGUI(KC_RIGHT)),LCTL(LSFT(KC_J)),DUAL_FUNC_10,   LALT(LGUI(KC_L)),KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRNS, KC_TRNS, LALT(LSFT(KC_DOWN)),LALT(LGUI(KC_C)),LALT(LGUI(KC_V)),LALT(LGUI(KC_N)),                                DUAL_FUNC_11,   LALT(LGUI(KC_M)),LALT(LCTL(LSFT(KC_COMMA))),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,                                          KC_TRNS,    KC_TRNS,          KC_TRNS,          KC_TRNS,    KC_TRNS,   KC_TRNS, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [EXTRAS] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HYPR(KC_T),                                 HYPR(KC_Y), HYPR(KC_U), HYPR(KC_I), HYPR(KC_O), KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, HYPR(KC_S), KC_TRANSPARENT, HYPR(KC_F), HYPR(KC_G),                            HYPR(KC_H), HYPR(KC_J), HYPR(KC_K), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, HYPR(KC_C), HYPR(KC_V), HYPR(KC_B),                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [CONTROLS] = LAYOUT_voyager(
    KC_TRNS,       LGUI(LCTL(KC_Q)),   KC_TRNS,            KC_BRIGHTNESS_DOWN, LGUI(LCTL(LSFT(KC_4))), LALT(LGUI(LCTL(KC_LEFT))),  LALT(LGUI(LCTL(KC_RIGHT))), KC_TRNS,   KC_BRIGHTNESS_UP,   KC_TRNS,            KC_TRNS,            KC_TRNS,
    KC_TRNS,       KC_TRNS,            KC_TRNS,            DUAL_FUNC_6,        LALT(LGUI(KC_F)),   LALT(LCTL(KC_LEFT)),            LALT(LCTL(KC_RIGHT)), KC_TRNS,         DUAL_FUNC_7,        KC_TRNS,            KC_TRNS,            KC_TRNS,           
    KC_TRNS,       LALT(LGUI(KC_X)),   KC_TRNS,            KC_TRNS,            KC_TRNS,            LCTL(KC_LEFT),                  LCTL(KC_RIGHT),     MAC_MISSION_CONTROL, KC_TRNS,          KC_TRNS,            KC_TRNS,            KC_TRNS,
    KC_TRNS, KC_TRNS,          KC_TRNS,            KC_TRNS,                   KC_TRNS,              KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                                                              KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS
  ),
  [MOUSE] = LAYOUT_voyager(
    NAVIGATOR_DEC_CPI,NAVIGATOR_INC_CPI,KC_TRNS, KC_LGUI, KC_BTN1, KC_BTN2,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRNS, QK_LLCK, KC_TRNS, KC_LALT, KC_LGUI,     DRAG_SCROLL,                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRNS, KC_TRNS, LGUI(KC_X),     LGUI(KC_C),     DUAL_FUNC_1,     TOGGLE_SCROLL,                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_LLCK,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRNS, KC_TRNS,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


const uint16_t PROGMEM combo0[] = { KC_LEFT_SHIFT, KC_RIGHT_SHIFT, COMBO_END};
const uint16_t PROGMEM combon_g_h_mouse[] = {KC_R, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_CAPS),
    COMBO(combon_g_h_mouse, TG(MOUSE)),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ESCAPE:
            return TAPPING_TERM + 50;
        case MT(MOD_LGUI, KC_F):
            return TAPPING_TERM + 50;
        case MT(MOD_LCTL, KC_Z):
            return TAPPING_TERM + 50;
        case MT(MOD_LGUI, KC_BSPC):
            return TAPPING_TERM + 50;
        case DUAL_FUNC_0:
            return TAPPING_TERM + 50;
        case DUAL_FUNC_1:
            return TAPPING_TERM + 50;
        case DUAL_FUNC_2:
            return TAPPING_TERM + 50;
        case DUAL_FUNC_3:
            return TAPPING_TERM + 50;
        case MT(MOD_LGUI, KC_DELETE):
            return TAPPING_TERM + 50;
        case DUAL_FUNC_5:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case TT(NAVIGATION):
        case MT(MOD_LGUI, KC_BSPC):
            // immediately select the hold action when another key is tapped
            return true;
        default:
            return false;
    }
}


extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [1] = { {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233}, {61,241,233} },

    [2] = { {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255}, {169,255,255} },

    [3] = { {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210}, {0,233,210} },

    [4] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [5] = { {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127}, {127,127,127} },
    
    [6] = { {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0}, {0,127,0} },
};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 3:
        set_layer_color(3);
        break;
      case 4:
        set_layer_color(4);
        break;
      case 5:
        set_layer_color(5);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}

extern bool set_scrolling;
extern bool navigator_turbo;
extern bool navigator_aim;
void pointing_device_init_user(void) {
    // set_auto_mouse_enable(true);
}

bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case NAVIGATOR_INC_CPI ... NAVIGATOR_AIM:
    case DRAG_SCROLL:
    case TOGGLE_SCROLL:
      return true;
  }
  return is_mouse_record_user(keycode, record);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QK_MODS ... QK_MODS_MAX: 
    // Mouse keys with modifiers work inconsistently across operating systems, this makes sure that modifiers are always
    // applied to the mouse key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
    if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;
    case ST_MACRO_SEARCH:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_C)) SS_DELAY(100) SS_LGUI(SS_TAP(X_F)) SS_DELAY(100) SS_LGUI(SS_TAP(X_A)) SS_DELAY(100) SS_LGUI(SS_TAP(X_V)) SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_GOOGLE:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_C)) SS_LALT(SS_LGUI(SS_TAP(X_ENTER))) SS_DELAY(100) SS_TAP(X_G) SS_DELAY(400) SS_TAP(X_TAB) SS_DELAY(500) SS_LGUI(SS_TAP(X_V)) SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_GOLINK:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_ENTER))) SS_DELAY(100) SS_TAP(X_G) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_SPACE));
    }
    break;
    case ST_MACRO_DICT:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_C)) SS_LALT(SS_LGUI(SS_TAP(X_ENTER))) SS_DELAY(100) SS_TAP(X_N) SS_TAP(X_D) SS_DELAY(300) SS_TAP(X_TAB) SS_DELAY(300) SS_LGUI(SS_TAP(X_V)) SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_CUR_INTELLIJ:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_F1)) SS_DELAY(100) SS_TAP(X_1));
    }
    break;
    case ST_MACRO_IN_NEW_TAB:
    if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_C)) SS_DELAY(100) SS_LGUI(SS_TAP(X_T)) SS_DELAY(200) SS_LGUI(SS_TAP(X_V))  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case MAC_MISSION_CONTROL:
      HCS(0x29F);

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_G);
        } else {
          unregister_code16(KC_G);
        }
      } else {
        if (record->event.pressed) {
          set_scrolling = true;
        } else {
          set_scrolling = false;
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LGUI(KC_V));
        } else {
          unregister_code16(LGUI(KC_V));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LALT(LGUI(LSFT(KC_V))));
        } else {
          unregister_code16(LALT(LGUI(LSFT(KC_V))));
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DQUO);
        } else {
          unregister_code16(KC_DQUO);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_PIPE);
        } else {
          unregister_code16(KC_PIPE);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_UNDS);
        } else {
          unregister_code16(KC_UNDS);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_ALT);
        } else {
          unregister_code16(KC_RIGHT_ALT);
        }  
      }  
      return false;
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_QUES);
        } else {
          unregister_code16(KC_QUES);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_6:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_AUDIO_VOL_DOWN);
        } else {
          unregister_code16(KC_AUDIO_VOL_DOWN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_AUDIO_MUTE);
        } else {
          unregister_code16(KC_AUDIO_MUTE);
        }  
      }  
      return false;
    case DUAL_FUNC_7:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_AUDIO_VOL_UP);
        } else {
          unregister_code16(KC_AUDIO_VOL_UP);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_AUDIO_MUTE);
        } else {
          unregister_code16(KC_AUDIO_MUTE);
        }  
      }  
      return false;
    case DUAL_FUNC_8:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_F6);
        } else {
          unregister_code16(KC_F6);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_F6));
        } else {
          unregister_code16(LSFT(KC_F6));
        }  
      }  
      return false;
    case DUAL_FUNC_9:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_F9);
        } else {
          unregister_code16(KC_F9);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_F9));
        } else {
          unregister_code16(LSFT(KC_F9));
        }  
      }  
      return false;
    case DUAL_FUNC_10:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LGUI(KC_K));
        } else {
          unregister_code16(LGUI(KC_K));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LGUI(LSFT(KC_K)));
        } else {
          unregister_code16(LGUI(LSFT(KC_K)));
        }  
      }  
      return false;
    case DUAL_FUNC_11:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LGUI(KC_N));
        } else {
          unregister_code16(LGUI(KC_N));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LGUI(LSFT(KC_N)));
        } else {
          unregister_code16(LGUI(LSFT(KC_N)));
        }  
      }  
      return false;
    case DRAG_SCROLL:
      if (record->event.pressed) {
        set_scrolling = true;
      } else {
        set_scrolling = false;
      }
      return false;
    case TOGGLE_SCROLL:
      if (record->event.pressed) {
        set_scrolling = !set_scrolling;
      }
      return false;
    break;
  case NAVIGATOR_TURBO:
    if (record->event.pressed) {
      navigator_turbo = true;
    } else {
      navigator_turbo = false;
    }
    return false;
  case NAVIGATOR_AIM:
    if (record->event.pressed) {
      navigator_aim = true;
    } else {
      navigator_aim = false;
    }
    return false;
  case NAVIGATOR_INC_CPI:
    if (record->event.pressed) {
        pointing_device_set_cpi(1);
    }
    return false;
  case NAVIGATOR_DEC_CPI:
    if (record->event.pressed) {
        pointing_device_set_cpi(0);
    }
    return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


//**************** tri-state layer *********************//
// 
layer_state_t layer_state_set_user(layer_state_t state) {
   //dprintf("layer_state_set_user: state before changes=%d \n", state);
   state = update_tri_layer_state(state, NUM_FUNC, INTELLIJ, EXTRAS);
   //dprintf("layer_state_set_user: state after EXTRAS=%d \n", state);
   state = update_tri_layer_state(state, SYMBOLS, INTELLIJ, CONTROLS);
   //dprintf("layer_state_set_user: final state=%d \n", state);
   // enableAchordion = IS_LAYER_ON(MOUSE);
   return state;
}

//**************** LEADER *********************//
//
void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_A, KC_A)) {
        SEND_STRING("alikov.andrei");
    }
}