// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
//
// Copyright 2022 Johan Eklund

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_number {
  _QWERTY = 0,
  _COLEMAK,
  _MISC,
  _NAV,
  _MOUSE,
  _SYM,
  _NUM,
  _FUN,
};

// Mod-Tap - Qwerty
#define MTQ_A LGUI_T(KC_A)
#define MTQ_S LALT_T(KC_S)
#define MTQ_D LCTL_T(KC_D)
#define MTQ_F LSFT_T(KC_F)
#define MTQ_X ALGR_T(KC_X)

#define MTQ_J LSFT_T(KC_J)
#define MTQ_K LCTL_T(KC_K)
#define MTQ_L ALT_T(KC_L)
#define MTQ_QUOT LGUI_T(KC_QUOT)
#define MTQ_DOT ALGR_T(KC_DOT)

// Mod-Tap - Colemak-DH
#define MTC_A LGUI_T(KC_A)
#define MTC_R LALT_T(KC_R)
#define MTC_S LCTL_T(KC_S)
#define MTC_T LSFT_T(KC_T)
#define MTC_X ALGR_T(KC_X)

#define MTC_N LSFT_T(KC_N)
#define MTC_E LCTL_T(KC_E)
#define MTC_I LALT_T(KC_I)
#define MTC_O LGUI_T(KC_O)
#define MTC_DOT ALGR_T(KC_DOT)

// Layers
#define L_QWE DF(_QWERTY)
#define L_COL DF(_COLEMAK)

#define L_MIS LT(_MISC, KC_ESC)
#define L_NAV LT(_NAV, KC_SPC)
#define L_MUS LT(_MOUSE, KC_TAB)

#define L_SYM LT(_SYM, KC_ENT)
#define L_NUM LT(_NUM, KC_BSPC)
#define L_FUN LT(_FUN, KC_DEL)

// Misc
#define RALT_W RALT(KC_W)
#define RALT_A RALT(KC_A)
#define RALT_O RALT(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .-----------------------------------------.                    .-----------------------------------------.
 * |L_COL |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |-------.    .-------|   H  |   J  |   K  |   L  |   '  |      |
 * |------+-LGUI-+-LALT-+-LCTL-+-LSFT-+------|       |    |       |------+-LSFT-+-LCTL-+-LALT-+-LGUI-+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * '---------------RALT----------------------/       /    \       \----------------------RALT---------------'
 *                   |      | ESC  | SPC  | /  TAB  /      \  ENT  \  | BSPC | DEL  |      |
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '---------MIS---NAV-''--MUS--'          '--SYM--''-NUM----FUN---------'
 */

[_QWERTY] = LAYOUT(
  L_COL,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                    KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,     KC_NO,
  KC_NO,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,      KC_NO,
  KC_NO,  MTQ_A,  MTQ_S,  MTQ_D,  MTQ_F,  KC_G,                     KC_H,   MTQ_J,  MTQ_K,    MTQ_L,    MTQ_QUOT,  KC_NO,
  KC_NO,  KC_Z,   MTQ_X,  KC_C,   KC_V,   KC_B,   KC_NO,    KC_NO,  KC_N,   KC_M,   KC_COMM,  MTQ_DOT,  KC_SLSH,   KC_NO,
                          KC_NO,  L_MIS,  L_NAV,  L_MUS,    L_SYM,  L_NUM,  L_FUN,  KC_NO
),

/* COLEMAK-DH
 * .-----------------------------------------.                    .-----------------------------------------.
 * |L_QWE |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   '  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   R  |   S  |   T  |   G  |-------.    .-------|   M  |   N  |   E  |   I  |   O  |      |
 * |------+-LGUI-+-LALT-+-LCTL-+-LSFT-+------|       |    |       |------+-LSFT-+-LCTL-+-LALT-+-LGUI-+------|
 * |      |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |      |
 * '---------------RALT----------------------/       /    \       \----------------------RALT---------------'
 *                   |      | ESC  | SPC  | /  TAB  /      \  ENT  \  | BSPC | DEL  |      |
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '---------MIS---NAV-''--MUS--'          '--SYM--''-NUM----FUN---------'
 */

[_COLEMAK] = LAYOUT(
  L_QWE,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                    KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,  KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                     KC_J,   KC_L,   KC_U,     KC_Y,     KC_QUOT,  KC_NO,
  KC_NO,  MTC_A,  MTC_R,  MTC_S,  MTC_T,  KC_G,                     KC_M,   MTC_N,  MTC_E,    MTC_I,    MTC_O,    KC_NO,
  KC_NO,  KC_Z,   MTC_X,  KC_C,   KC_D,   KC_V,   KC_NO,    KC_NO,  KC_K,   KC_H,   KC_COMM,  MTC_DOT,  KC_SLSH,  KC_NO,
                          KC_NO,  L_MIS,  L_NAV,  L_MUS,    L_SYM,  L_NUM,  L_FUN,  KC_NO
),

/* MISC
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      | LSFT |      |-------.    .-------|      |   Å  |   Ä  |   Ö  |      |      |
 * |------+------+------+------+------+------|       |    |       |------+--(W)-+--(A)-+--(O)-+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * '-----------------------------------------/       /    \       \-----------------------------------------'
 *                   |      |      |      | /       /      \       \  |      |      |      |
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '-------------------''-------'          '-------''--------------------'
 */

[_MISC] = LAYOUT(
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,                    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,                    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_LSFT,  KC_NO,                    KC_NO,  RALT_W,  RALT_A,  RALT_O,  KC_NO,  KC_NO,
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
                          KC_NO,  KC_NO,    KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,   KC_NO
),

/* NAV
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | REDO | PSTE | COPY | CUT  | UNDO |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LGUI | LALT | LCTL | LSFT |      |-------.    .-------| CAPS | LEFT | DOWN | UP   | RGHT |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      | ALGR |      |      |      |-------|    |-------| INS  | HOME | PGDN | PGUP | END  |      |
 * '-----------------------------------------/       /    \       \-----------------------------------------'
 *                   |      |      |      | /       /      \  ENT  \  | BSPC | DEL  |      |
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '-------------------''-------'          '-------''--------------------'
 */

[_NAV] = LAYOUT(
  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                     C(KC_Y),  C(KC_V),  C(KC_C),  C(KC_X),  C(KC_Z),  KC_NO,
  KC_NO,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,                     KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_NO,
  KC_NO,  KC_NO,    KC_ALGR,  KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_NO,   KC_INS,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_NO,
                              KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_ENT,  KC_BSPC,  KC_DEL,   KC_NO
),

/* MOUSE
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | REDO | PSTE | COPY | CUT  | UNDO |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LGUI | LALT | LCTL | LSFT |      |-------.    .-------|      | CurL | CurD | CurU | CurR |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      | ALGR |      |      |      |-------|    |-------|      | ScrL | ScrD | ScrU | ScrR |      |
 * '-----------------------------------------/       /    \       \-----------------------------------------'
 *                   |      |      |      | /       /      \  MUS1 \  | MUS3 | MUS2 |      |
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '-------------------''-------'          '-------''--------------------'
 */

[_MOUSE] = LAYOUT(
  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                      C(KC_Y),  C(KC_V),  C(KC_C),  C(KC_X),  C(KC_Z),  KC_NO,
  KC_NO,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,                      KC_NO,    KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_NO,
  KC_NO,  KC_NO,    KC_ALGR,  KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  KC_NO,
                              KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_BTN1,  KC_BTN3,  KC_BTN2,  KC_NO
),

/* SYM
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   {  |   &  |   *  |   (  |   }  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   :  |   $  |   %  |   ^  |   +  |-------.    .-------|      | LSFT | LCTL | LALT | LGUI |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   ~  |   !  |   @  |   #  |   |  |-------|    |-------|      |      |      | ALGR |      |      |
 * '-----------------------------------------/       /    \       \-----------------------------------------'
 *                   |      |   (  |   )  | /   _   /      \       \  |      |      |      |
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '-------------------''-------'          '-------''--------------------'
 */

[_SYM] = LAYOUT(
  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_NO,                        KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,  KC_LCBR,  KC_AMPR,  KC_ASTR,  KC_LPRN,    KC_RCBR,                      KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,  KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,    KC_PLUS,                      KC_NO,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_NO,
  KC_NO,  KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,    KC_PIPE,  KC_NO,      KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_ALGR,  KC_NO,    KC_NO,
                              KC_NO,    KC_LPRN,    KC_RPRN,  KC_UNDS,    KC_NO,  KC_NO,  KC_NO,    KC_NO
),

/* NUM
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   [  |   7  |   8  |   9  |  ]   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ;  |   4  |   5  |   6  |  =   |-------.    .-------|      |   /  |   *  |   -  |   +  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   `  |   1  |   2  |   3  |  \   |-------|    |-------|      |      |   ,  |   .  |      |      |
 * '-----------------------------------------/       /    \       \-----------------------------------------'
 *                   |      |   .  |  0   | /   -   /      \       \  |      |      |      |
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '-------------------''-------'          '-------''--------------------'
 */

[_NUM] = LAYOUT(
  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,   KC_NO,                        KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,  KC_LBRC,  KC_7,   KC_8,   KC_9,    KC_RBRC,                      KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,  KC_SCLN,  KC_4,   KC_5,   KC_6,    KC_EQL,                       KC_NO,  KC_PSLS,  KC_PAST,  KC_PMNS,  KC_PPLS,  KC_NO,
  KC_NO,  KC_GRV,   KC_1,   KC_2,   KC_3,    KC_BSLS,  KC_NO,      KC_NO,  KC_NO,  KC_NO,    KC_COMM,  KC_DOT,   KC_NO,    KC_NO,
                            KC_NO,  KC_DOT,  KC_0,     KC_MINS,    KC_NO,  KC_NO,  KC_NO,    KC_NO
),

/* FUN
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F12 |  F7  |  F8  |  F9  | PSCR |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F11 |  F4  |  F5  |  F6  | SLCK |-------.    .-------|      | LSFT | LCTL | LALT | LGUI |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  F10 |  F1  |  F2  |  F3  | PAUS |-------|    |-------|      |      |      | ALGR |      |      |
 * '-----------------------------------------/       /    \       \-----------------------------------------'
 *                   |      | APP  | SPC  | /  TAB  /      \       \  |      |      |      |
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '-------------------''-------'          '-------''--------------------'
 */

[_FUN] = LAYOUT(
  KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,   KC_NO,                       KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,  KC_F12,  KC_F7,  KC_F8,  KC_F9,   KC_PSCR,                     KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,  KC_F11,  KC_F4,  KC_F5,  KC_F6,   KC_SLCK,                     KC_NO,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_NO,
  KC_NO,  KC_F10,  KC_F1,  KC_F2,  KC_F3,   KC_PAUS,  KC_NO,     KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_ALGR,  KC_NO,    KC_NO,
                           KC_NO,  KC_APP,  KC_SPC,   KC_TAB,    KC_NO,  KC_NO,  KC_NO,    KC_NO
)

};
