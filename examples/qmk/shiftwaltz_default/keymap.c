#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(
        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P, 
        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN, 
        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                           KC_N,           KC_M,           LCTL_T(KC_COMM),LALT_T(KC_DOT), LGUI_T(KC_SLSH), 
                                        LCTL_T(KC_ESC), LSFT_T(KC_SPC), LT(2,KC_TAB),                   LT(1,KC_ENT),   RSFT_T(KC_BSPC),LT(3,KC_RALT)),
    [1] = LAYOUT_split_3x5_3(
        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0, 
        KC_GRV,         KC_MINS,        S(KC_MINS),     KC_EQL,         KC_LBRC,                        KC_RBRC,        S(KC_QUOT),     KC_QUOT,        KC_BSLS,        KC_SCLN, 
        KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        KC_CAPS,                        KC_RCTL,        KC_RSFT,        KC_TRNS,        KC_TRNS,        KC_TRNS, 
                                        KC_LCTL,        KC_TRNS,        KC_TAB,                         KC_TRNS,        KC_TRNS,        KC_TRNS),
    [2] = LAYOUT_split_3x5_3(
        KC_BSPC,        KC_HOME,        KC_UP,          KC_END,         KC_PGUP,                        MS_WHLU,        MS_WHLL,        MS_UP,          MS_WHLR,        MS_ACL0, 
        KC_DEL,         KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_PGDN,                        MS_WHLD,        MS_LEFT,        MS_DOWN,        MS_RGHT,        MS_ACL1, 
        C(KC_Z),        C(KC_X),        C(KC_C),        C(KC_V),        C(KC_Y),                        KC_APP,         KC_RSFT,        KC_LCTL,        KC_LALT,        KC_LGUI, 
                                        KC_TRNS,        KC_TRNS,        KC_TRNS,                        MS_BTN2,        MS_BTN1,        MS_BTN3),
    [3] = LAYOUT_split_3x5_3(
        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10, 
        RM_NEXT,        RM_VALU,        RM_SATU,        RM_HUEU,        RM_TOGG,                        KC_PSCR,        KC_SCRL,        KC_BRK,         KC_F11,         KC_F12,  
        KC_LGUI,        KC_LALT,        KC_LCTL,        KC_LSFT,        KC_NO,                          KC_NO,          KC_RSFT,        KC_LCTL,        KC_LALT,        KC_RGUI, 
                                        QK_BOOT,        KC_TRNS,        QK_RBT,                         KC_TRNS,        KC_TRNS,        KC_TRNS),
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1,KC_ENT):
            return true;
        case LCTL_T(KC_ESC):
            return true;
        default:
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPC):
            return true;
        case RSFT_T(KC_BSPC):
            return true;
        default:
            return false;
    }
}

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x5_3(
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
                  'L', 'L', 'L',  'R', 'R', 'R'
    );