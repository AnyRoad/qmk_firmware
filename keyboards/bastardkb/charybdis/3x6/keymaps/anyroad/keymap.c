/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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
#include "achordion.h"

enum custom_keycodes {
  ST_MACRO_SEARCH = SAFE_RANGE,
  ST_MACRO_GOOGLE,
  ST_MACRO_GOLINK,
  ST_MACRO_DICT,
  ST_MACRO_CUR_INTELLIJ,
  ST_MACRO_IN_NEW_TAB,
  MAC_MISSION_CONTROL,
  TOGGLE_AUTO_MOUSE,
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
  DC_G_DRAG_SCROLL,
  DC_BTN1_BTN2
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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [MAIN] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
       KC_PRTSCR,          KC_Q,              KC_W,               KC_E,                KC_R,               KC_T,                     KC_Y,               KC_U,              KC_I,              KC_O,                KC_P,                TD(DC_BRACETS),
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       KC_ESC,             KC_A,              KC_S,               MT(MOD_LALT, KC_D),  MT(MOD_LGUI, KC_F), TD(DC_G_DRAG_SCROLL),     KC_H,               MT(MOD_RGUI, KC_J), MT(MOD_RALT, KC_K), KC_L,              KC_SCLN,             LGUI(KC_SPACE),
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       KC_LSFT,            MT(MOD_LCTL, KC_Z), KC_X,              KC_C,                KC_V,               KC_B,                     KC_N,               KC_M,              LT(MOUSE,KC_COMM), KC_DOT,              MT(MOD_RCTL, KC_SLASH), KC_RSFT,
  // ╰──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╯
                                                                  TT(NAVIGATION),   MT(MOD_LGUI, KC_BSPC),LT(INTELLIJ,KC_ENTER),     LT(NUM_FUNC,KC_TAB),   LT(SYMBOLS,KC_SPACE)
  //                            ╰───────────────────────────────────────────────────────────────────────────────────────────────╯ ╰──────────────────────────────────────────────╯
  ),

  [NUM_FUNC] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
       KC_TRNS,            KC_F1,              KC_F2,             KC_F3,             KC_F4,              KC_F5,                     KC_F6,             KC_F7,             KC_F8,               KC_F9,                 KC_F10,             KC_F11,           
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       QK_LLCK,            KC_1,               KC_2,              MT(MOD_LALT, KC_3), MT(MOD_LGUI, KC_4), KC_5,                     KC_6,             MT(MOD_LGUI, KC_7), MT(MOD_LALT, KC_8),  KC_9,                  KC_0,               KC_F12,           
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       KC_TRNS,            KC_LCTL,            KC_NO,             KC_NO,              KC_NO,             KC_NO,                     QK_BOOT,           KC_NO,             KC_NO,               KC_NO,                 KC_RCTL,            KC_TRNS,           
  // ╰──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╯
                                                                  KC_TRNS,            KC_TRNS,          KC_TRNS,                    KC_TRNS,           KC_TRNS
  //                            ╰───────────────────────────────────────────────────────────────────────────────────────────────╯ ╰──────────────────────────────────────────────╯
  ), 

  [NAVIGATION] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
       KC_TRNS,            KC_NO,             KC_NO,              KC_NO,             KC_NO,                ST_MACRO_IN_NEW_TAB,      LGUI(KC_LEFT),      KC_END,            KC_HOME,           LGUI(KC_RIGHT),        KC_NO,              KC_NO,
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       QK_LLCK,            LGUI(KC_A),        KC_NO,              ST_MACRO_DICT,     ST_MACRO_SEARCH,      ST_MACRO_GOOGLE,          KC_LEFT,            KC_DOWN,           KC_UP,             KC_RIGHT,              KC_NO,              KC_NO,
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       KC_TRNS,            LGUI(KC_Z),        LGUI(KC_X),         LGUI(KC_C),        TD(DC_COPY_OR_NO_FORMAT),          QK_BOOT,     LALT(KC_LEFT),      KC_PGDN,           KC_PAGE_UP,        LALT(KC_RIGHT),        KC_NO,              KC_NO,
  // ╰──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╯
                                                                  KC_TRNS,            KC_TRNS,             KC_TRNS,                  KC_TRNS,            KC_TRNS
  //                            ╰───────────────────────────────────────────────────────────────────────────────────────────────╯ ╰──────────────────────────────────────────────╯
  ),  

  [SYMBOLS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
       KC_TRNS,            KC_EXLM,           KC_AT,              KC_HASH,             KC_DLR,             KC_PERC,                   KC_CIRC,           KC_AMPR,            KC_ASTR,           KC_LPRN,              KC_RPRN,        KC_NO,
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       KC_TRNS,            KC_GRAVE,          KC_QUOTE,           TD(DC_QUOTE_ALT),    KC_PLUS,            KC_LBRC,                   KC_RBRC,           KC_MINUS,           TD(DC_UNDS_ALT),       KC_EQUAL,             KC_COLN,        KC_DQUO,           
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       KC_TRNS,            TD(DC_PIPE_CTRL),       KC_BSLS,        KC_SLASH,            KC_TRANSPARENT,     KC_LCBR,                   KC_RCBR,           KC_TRANSPARENT,     KC_LABK,           KC_RABK,              TD(DC_QUEST_CTRL),    XXXXXXX,           
  // ╰──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╯
                                                                   KC_TRNS,            MT(MOD_LGUI, KC_DELETE), KC_TRNS,              KC_TRNS,            KC_TRNS
  //                            ╰───────────────────────────────────────────────────────────────────────────────────────────────╯ ╰──────────────────────────────────────────────╯
  ),


  [INTELLIJ] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
       KC_TRNS,        KC_TRNS,            LALT(LCTL(KC_V)),   LALT(KC_F12),       LCTL(LSFT(KC_R)),   LGUI(LCTL(LSFT(KC_LEFT))),    LGUI(LCTL(LSFT(KC_RIGHT))),    LALT(LCTL(LSFT(KC_V))),   LALT(KC_F7),    LALT(LCTL(LSFT(KC_O))),   LALT(LCTL(LSFT(KC_P))),   LGUI(KC_F12),           
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       KC_TRNS,        KC_TRNS,            LALT(LSFT(KC_UP)),  ST_MACRO_CUR_INTELLIJ, LCTL(LSFT(KC_F)),LALT(LGUI(KC_LEFT)),          LALT(LGUI(KC_RIGHT)),          LCTL(LSFT(KC_J)),         TD(DC_COMMIT_PUSH),   LALT(LGUI(KC_L)),         KC_TRNS,                  KC_TRNS,           
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       KC_TRNS,        LGUI(LALT(KC_LBRC)),LALT(LSFT(KC_DOWN)),LALT(LGUI(KC_C)),   LALT(LGUI(KC_V)),   LALT(LGUI(KC_N)),             TD(DC_FIND_CLASS_FILE),                  LALT(LGUI(KC_M)),         LALT(LCTL(LSFT(KC_COMMA))),            KC_TRNS,            KC_TRNS,            KC_TRNS,           
  // ╰──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╯
                                                                   KC_TRNS,            KC_TRNS,            KC_TRNS,                  KC_TRNS,            KC_TRNS
  //                            ╰───────────────────────────────────────────────────────────────────────────────────────────────╯ ╰──────────────────────────────────────────────╯
  ), 

  [EXTRAS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
       KC_TRNS,            KC_TRNS,            KC_TRNS,            KC_TRNS,            KC_TRNS,            HYPR(KC_T),                HYPR(KC_Y),         HYPR(KC_U),         HYPR(KC_I),         HYPR(KC_O),         KC_TRNS,            KC_TRNS,           
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       KC_TRNS,            KC_TRNS,            HYPR(KC_S),         KC_TRNS,            HYPR(KC_F),         HYPR(KC_G),                HYPR(KC_H),         HYPR(KC_J),            KC_TRNS,            KC_TRNS,            KC_TRNS,            KC_TRNS,           
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       KC_TRNS,            KC_TRNS,            KC_TRNS,            HYPR(KC_C),         HYPR(KC_V),         HYPR(KC_B),                KC_TRNS,            KC_TRNS,            KC_TRNS,            KC_TRNS,            KC_TRNS,            KC_TRNS,           
  // ╰──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╯
                                                                   KC_TRNS,            KC_TRNS,            KC_TRNS,                   KC_TRNS,            KC_TRNS
  //                            ╰───────────────────────────────────────────────────────────────────────────────────────────────╯ ╰──────────────────────────────────────────────╯
  ), 

  [CONTROLS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╮
       KC_TRNS,       LGUI(LCTL(KC_Q)),   KC_TRNS,            KC_BRIGHTNESS_DOWN, LGUI(LCTL(LSFT(KC_4))), LALT(LGUI(LCTL(KC_LEFT))),  LALT(LGUI(LCTL(KC_RIGHT))), KC_TRNS,   KC_BRIGHTNESS_UP,   KC_TRNS,            KC_TRNS,            KC_TRNS,           
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       KC_TRNS,       KC_TRNS,            KC_TRNS,            TD(DC_VOL_DOWN_MUTE),        LALT(LGUI(KC_F)),   LALT(LCTL(KC_LEFT)),            LALT(LCTL(KC_RIGHT)), KC_TRNS,         TD(DC_VOL_UP_MUTE),        KC_TRNS,            KC_TRNS,            KC_TRNS,           
  // ├──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       KC_TRNS,       LALT(LGUI(KC_X)),   KC_TRNS,            KC_TRNS,            KC_TRNS,            LCTL(KC_LEFT),                  LCTL(KC_RIGHT),     MAC_MISSION_CONTROL, KC_TRNS,          KC_TRNS,            KC_TRNS,            KC_TRNS,           
  // ╰──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╯
                                                                   KC_TRNS,            KC_TRNS,            KC_TRNS,                   KC_TRNS,            KC_TRNS
  //                            ╰───────────────────────────────────────────────────────────────────────────────────────────────╯ ╰──────────────────────────────────────────────╯
  ), 

  [MOUSE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_BOOT, TOGGLE_AUTO_MOUSE, KC_NO, KC_NO, DPI_RMOD, S_D_RMOD,       S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX,  XXXXXXX, QK_BOOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, TG(MOUSE), KC_NO, KC_LALT, KC_LGUI, DRGSCRL,      DRG_TOG, KC_RGUI, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, KC_LCTL, LGUI(KC_X), LGUI(KC_C), TD(DC_COPY_OR_NO_FORMAT), SNIPING,    LGUI(KC_BTN1), TD(DC_BTN1_BTN2), XXXXXXX, DRGSCRL, KC_RCTL, KC_RSFT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                 KC_BTN2,  MT(MOD_LGUI, KC_BSPC), KC_ENTER,     LGUI(KC_PMNS), LGUI(KC_PPLS)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on
const uint16_t PROGMEM combo_two_shifts[] = {KC_LEFT_SHIFT, KC_RIGHT_SHIFT, COMBO_END};
const uint16_t PROGMEM combon_g_h_mouse[] = {KC_R, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_two_shifts, CW_TOGG),
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
        case LT(MOUSE, KC_COMM):
            return TAPPING_TERM - 30;
        default:
            return TAPPING_TERM;
    }
}

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
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            charybdis_set_pointer_dragscroll_enabled(true);
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
        charybdis_set_pointer_dragscroll_enabled(false);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_DRAG_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_drag_finished, tap_dance_tap_hold_drag_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


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
    [DC_BTN1_BTN2] = ACTION_TAP_DANCE_TAP_HOLD(KC_BTN1, KC_BTN2),
    [DC_G_DRAG_SCROLL] = ACTION_TAP_DANCE_DRAG_TAP_HOLD(KC_G, DRAGSCROLL_MODE),
};

bool enableAchordion = true;
bool auto_mouse_tg_off = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  tap_dance_action_t *action;
  if (enableAchordion) {
     if (!process_achordion(keycode, record)) { return false; }
  }
  switch (keycode) {
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
    case TD(DC_BTN1_BTN2): 
    case TD(DC_G_DRAG_SCROLL): 
     action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
     if (!record->event.pressed && action->state.count && !action->state.finished) {
          tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
          tap_code16(tap_hold->tap);
     }
     break;
    case TOGGLE_AUTO_MOUSE:
        if (record->event.pressed) {
            auto_mouse_tg_off = !get_auto_mouse_enable();
            auto_mouse_layer_off();
            set_auto_mouse_enable(auto_mouse_tg_off);
        }
        return false;
        break;
  }
  return true;
}

// static uint16_t auto_pointer_layer_timer = 0;

void matrix_scan_user(void) {
    if (enableAchordion) {
        achordion_task();
    }
//   if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
//         auto_pointer_layer_timer = 0;
//         layer_off(MOUSE);
//     }
}

// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
//         if (auto_pointer_layer_timer == 0) {
//             layer_on(MOUSE);
//         }
//         auto_pointer_layer_timer = timer_read();
//     }
//     return mouse_report;
// }

//**************** tri-state layer *********************//
// 
layer_state_t layer_state_set_user(layer_state_t state) {
   //dprintf("layer_state_set_user: state before changes=%d \n", state);
   state = update_tri_layer_state(state, NUM_FUNC, INTELLIJ, EXTRAS);
   //dprintf("layer_state_set_user: state after EXTRAS=%d \n", state);
   state = update_tri_layer_state(state, SYMBOLS, INTELLIJ, CONTROLS);
   //dprintf("layer_state_set_user: final state=%d \n", state);
   enableAchordion = IS_LAYER_ON(MOUSE);
   return state;
}

void pointing_device_init_user(void) {
    set_auto_mouse_layer(MOUSE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    // set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case POINTER_DEFAULT_DPI_REVERSE:
            return true;
        case POINTER_SNIPING_DPI_FORWARD:
            return true;
        case POINTER_SNIPING_DPI_REVERSE:
            return true;
        case SNIPING_MODE:
            return true;
        case SNIPING_MODE_TOGGLE:
            return true;
        case DRAGSCROLL_MODE:
            return true;
        case DRAGSCROLL_MODE_TOGGLE:
            return true;
        default:
            return false;
    }
    return false;
}

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

//**************** LEADER *********************//
//
void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_A, KC_A)) {
        SEND_STRING("alikov.andrei");
    }
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}