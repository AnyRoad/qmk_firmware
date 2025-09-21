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


enum tap_dance_codes {
  DC_BRACETS,
  DC_COPY_OR_NO_FORMAT,
  DC_QUOTE_ALT,
  DC_PIPE_CTRL,
  DC_UNDS_ALT,
  DC_QUEST_CTRL,
  DC_VOL_DOWN_MUTE,
  DC_VOL_UP_MUTE,
  DC_COMMIT_PUSH,
  DC_FIND_CLASS_FILE,
  DC_G_DRAG_SCROLL
};

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
    KC_ESCAPE,      LT(MOUSE, KC_A), KC_S,           MT(MOD_LALT, KC_D),MT(MOD_LGUI, KC_F), TD(DC_G_DRAG_SCROLL),                             KC_H,           MT(MOD_RGUI, KC_J),MT(MOD_RALT, KC_K),KC_L,     KC_SCLN,        LGUI(KC_SPACE), 
    KC_LEFT_SHIFT,  MT(MOD_LCTL, KC_Z),KC_X,         KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         MT(MOD_RCTL, KC_SLASH),KC_RIGHT_SHIFT, 
    KC_NO,          KC_NO,           KC_NO,          KC_MS_BTN1, MO(NAVIGATION), KC_NO,                                          KC_NO,          LGUI(KC_SPACE), KC_LCTL,       KC_NO,          KC_NO,          KC_NO,        
                                                    MT(MOD_LGUI, KC_BSPC),LT(INTELLIJ, KC_ENTER),                                    LT(NUM_FUNC, KC_TAB),  LT(SYMBOLS, KC_SPACE)
  ),
  [NUM_FUNC] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    QK_LLCK,        KC_1,           KC_2,           MT(MOD_LALT, KC_3),MT(MOD_LGUI, KC_4),           KC_5,                          KC_6,           MT(MOD_RGUI, KC_7),MT(MOD_RALT, KC_8),           KC_9,           KC_0,           KC_F12,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,                                                            KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [NAVIGATION] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_NO,  KC_NO,     KC_NO,       KC_NO,     ST_MACRO_IN_NEW_TAB,                                 LGUI(KC_LEFT),  KC_END,         KC_HOME,        LGUI(KC_RIGHT), KC_NO,          KC_F12,         
    QK_LLCK,        LGUI(KC_A),     KC_NO,     ST_MACRO_DICT,     ST_MACRO_SEARCH,      ST_MACRO_GOOGLE,                                    KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,     KC_TRANSPARENT, 
    KC_TRANSPARENT, LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     TD(DC_COPY_OR_NO_FORMAT),    KC_TRNS,                                  LALT(KC_LEFT),  KC_PGDN,        KC_PAGE_UP,     LALT(KC_RIGHT), KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRNS,        KC_TRNS,        KC_TRNS,          KC_TRNS,          KC_TRNS,                                          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,         KC_TRNS,         
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [SYMBOLS] = LAYOUT_voyager(
    KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_F12,         
    QK_LLCK,        KC_GRAVE,       KC_QUOTE,       TD(DC_QUOTE_ALT),    KC_PLUS,        KC_LBRC,                                        KC_RBRC,        KC_MINUS,       TD(DC_UNDS_ALT),    KC_EQUAL,       KC_COLN,        KC_DQUO,        
    KC_TRANSPARENT, TD(DC_PIPE_CTRL), KC_BSLS,        KC_SLASH,       KC_TRANSPARENT, KC_LCBR,                                        KC_RCBR,        KC_TRANSPARENT, KC_LABK,        KC_RABK,        TD(DC_QUEST_CTRL),    KC_TRANSPARENT, 
    KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,                                          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,         KC_TRNS,         
                                                    MT(MOD_LGUI, KC_DELETE),KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [INTELLIJ] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS, LALT(LCTL(KC_V)),LALT(KC_F12),   LCTL(LSFT(KC_R)),LGUI(LCTL(LSFT(KC_LEFT))),                                LGUI(LCTL(LSFT(KC_RIGHT))),LALT(LCTL(LSFT(KC_V))),LALT(KC_F7),    LALT(LCTL(LSFT(KC_O))),LALT(LCTL(LSFT(KC_P))),LGUI(KC_F12),   
    QK_LLCK, KC_TRNS, LALT(LSFT(KC_UP)),ST_MACRO_CUR_INTELLIJ,     LCTL(LSFT(KC_F)),LALT(LGUI(KC_LEFT)),                          LALT(LGUI(KC_RIGHT)),  LCTL(LSFT(KC_J)),  TD(DC_COMMIT_PUSH),   LALT(LGUI(KC_L)),  KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRNS, LGUI(LALT(KC_LBRC)), LALT(LSFT(KC_DOWN)),LALT(LGUI(KC_C)),LALT(LGUI(KC_V)),LALT(LGUI(KC_N)),                                TD(DC_FIND_CLASS_FILE),   LALT(LGUI(KC_M)),LALT(LCTL(LSFT(KC_COMMA))),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
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
    KC_TRNS,       KC_TRNS,            KC_TRNS,            TD(DC_VOL_DOWN_MUTE),        LALT(LGUI(KC_F)),   LALT(LCTL(KC_LEFT)),            LALT(LCTL(KC_RIGHT)), KC_TRNS,         TD(DC_VOL_UP_MUTE),        KC_TRNS,            KC_TRNS,            KC_TRNS,           
    KC_TRNS,       LALT(LGUI(KC_X)),   KC_TRNS,            KC_TRNS,            KC_TRNS,            LCTL(KC_LEFT),                  LCTL(KC_RIGHT),     MAC_MISSION_CONTROL, KC_TRNS,          KC_TRNS,            KC_TRNS,            KC_TRNS,
    KC_TRNS, KC_TRNS,          KC_TRNS,            KC_TRNS,                   KC_TRNS,              KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
                                                                              KC_TRNS, KC_TRNS,                                      KC_TRNS, KC_TRNS
  ),
  [MOUSE] = LAYOUT_voyager(
    NAVIGATOR_DEC_CPI,NAVIGATOR_INC_CPI,KC_TRNS, KC_LGUI, KC_BTN1, KC_BTN2,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRNS, QK_LLCK, KC_TRNS, KC_LALT, KC_LGUI,     DRAG_SCROLL,                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRNS, KC_TRNS, LGUI(KC_X),     LGUI(KC_C),     TD(DC_COPY_OR_NO_FORMAT),     TOGGLE_SCROLL,                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_LLCK,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRNS, KC_TRNS,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


const uint16_t PROGMEM combo0[] = { KC_LEFT_SHIFT, KC_RIGHT_SHIFT, COMBO_END};
const uint16_t PROGMEM combon_g_h_mouse[] = {KC_R, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, CW_TOGG),
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
        case TD(DC_BRACETS):
            return TAPPING_TERM + 50;
        case TD(DC_COPY_OR_NO_FORMAT):
            return TAPPING_TERM + 50;
        case TD(DC_QUOTE_ALT):
            return TAPPING_TERM + 50;
        case TD(DC_PIPE_CTRL):
            return TAPPING_TERM + 50;
        case MT(MOD_LGUI, KC_DELETE):
            return TAPPING_TERM + 50;
        case TD(DC_QUEST_CTRL):
            return TAPPING_TERM + 50;
        case TD(DC_G_DRAG_SCROLL):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
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

/*
***********************************
         Tap Dances
***********************************
*/

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


void tap_dance_tap_hold_drag_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
//#ifndef PERMISSIVE_HOLD
            && !state->interrupted
//#endif
        ) {
            set_scrolling = true;
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_drag_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        set_scrolling = false;
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_DRAG_TAP_HOLD(tap) \
    { .fn = {NULL, tap_dance_tap_hold_drag_finished, tap_dance_tap_hold_drag_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, KC_TRANSPARENT, 0}), }


tap_dance_action_t tap_dance_actions[] = {
    [DC_BRACETS] = ACTION_TAP_DANCE_TAP_HOLD(KC_LBRC, KC_RBRC),
    [DC_COPY_OR_NO_FORMAT] = ACTION_TAP_DANCE_TAP_HOLD(LGUI(KC_V), LALT(LGUI(LSFT(KC_V)))),
    [DC_QUOTE_ALT] = ACTION_TAP_DANCE_TAP_HOLD(KC_DQUO, KC_LEFT_ALT),
    [DC_PIPE_CTRL] = ACTION_TAP_DANCE_TAP_HOLD(KC_PIPE, KC_LEFT_CTRL),
    [DC_UNDS_ALT] = ACTION_TAP_DANCE_TAP_HOLD(KC_UNDS, KC_RIGHT_ALT),
    [DC_QUEST_CTRL] = ACTION_TAP_DANCE_TAP_HOLD(KC_QUES, KC_RIGHT_CTRL),
    [DC_VOL_DOWN_MUTE] = ACTION_TAP_DANCE_TAP_HOLD(KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE),
    [DC_VOL_UP_MUTE] = ACTION_TAP_DANCE_TAP_HOLD(KC_AUDIO_VOL_UP, KC_AUDIO_MUTE),
    [DC_COMMIT_PUSH] = ACTION_TAP_DANCE_TAP_HOLD(LGUI(KC_K), LGUI(LSFT(KC_K))),
    [DC_FIND_CLASS_FILE] = ACTION_TAP_DANCE_TAP_HOLD(LGUI(KC_N), LGUI(LSFT(KC_N))),
    [DC_G_DRAG_SCROLL] = ACTION_TAP_DANCE_DRAG_TAP_HOLD(KC_G),
};


/*
***********************************
         Tap Dances end
***********************************
*/


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  tap_dance_action_t *action;
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
    break;
    case TD(DC_BRACETS): 
    case TD(DC_COPY_OR_NO_FORMAT): 
    case TD(DC_QUOTE_ALT): 
    case TD(DC_PIPE_CTRL): 
    case TD(DC_UNDS_ALT): 
    case TD(DC_QUEST_CTRL): 
    case TD(DC_VOL_DOWN_MUTE): 
    case TD(DC_VOL_UP_MUTE): 
    case TD(DC_COMMIT_PUSH): 
    case TD(DC_FIND_CLASS_FILE): 
    case TD(DC_G_DRAG_SCROLL): 
     action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
     if (!record->event.pressed && action->state.count && !action->state.finished) {
          tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
          tap_code16(tap_hold->tap);
     }
     break;
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

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        // case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_MINUS:
        case KC_EQUAL:
        case KC_SLSH:
            return true;
    }
    return false;
}

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 
  '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', 
  '*', '*', '*', '*'
);


bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
        case LCTL_T(KC_Z):
            if (other_keycode == KC_C || other_keycode == KC_R) {
                return true;
            }
            break;

        case RCTL_T(KC_SLSH):
            if (other_keycode == KC_Y) {
                return true;
            }
            break;
    }
    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}
