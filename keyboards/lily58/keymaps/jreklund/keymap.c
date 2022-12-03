// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
//
// Copyright 2022 Johan Eklund

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_number {
  _QWERTY,
  _COLEMAK = 0,
  _CODE,
  _NAV,
  _MOUSE,
  _SYM,
  _NUM,
  _FUN,
};

// Tap Dance
enum {
  KC_RABK_LABK, // ><
  KC_LBRC_RBRC, // []
  KC_LPRN_RPRN, // ()
  KC_LCBR_RCBR, // {}
  KC_QUOT_DQUO, // '"
  KC_MINS_UNDS, // -_
  KC_SLSH_BSLS, // /\ 
  KC_GRV_TILD, // `~
  KC_SCLN_COLN, // ;:
  KC_DLR_PLUS, // $+
  KC_COMM_HASH, // ,#
  KC_DOT_PERC, // .%
  KC_PHP, // <?php?>
};

// Macros
enum custom_keycodes {
  KC_DOCB = SAFE_RANGE,
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

// Modifiers - Code
#define MOD_F LSA(KC_F)
#define MOD_GRV RCS(KC_GRV)

// Mod-Tap - Num
#define MTN_PSLS LSFT_T(KC_PSLS)
#define MTN_PAST LCTL_T(KC_PAST)
#define MTN_PMNS LALT_T(KC_PMNS)
#define MTN_PPLS LGUI_T(KC_PPLS)
#define MTN_DOT ALGR_T(KC_DOT)

// Layers
#define L_QWE DF(_QWERTY)
#define L_COL DF(_COLEMAK)

#define L_COD LT(_CODE, KC_ESC)
#define L_NAV LT(_NAV, KC_SPC)
#define L_MUS LT(_MOUSE, KC_TAB)

#define L_SYM LT(_SYM, KC_ENT)
#define L_NUM LT(_NUM, KC_BSPC)
#define L_FUN LT(_FUN, KC_DEL)

// Tap Dance
#define TD_ABK TD(KC_RABK_LABK)
#define TD_BRC TD(KC_LBRC_RBRC)
#define TD_PRN TD(KC_LPRN_RPRN)
#define TD_CBR TD(KC_LCBR_RCBR)
#define TD_QUO TD(KC_QUOT_DQUO)
#define TD_DSH TD(KC_MINS_UNDS)
#define TD_SLS TD(KC_SLSH_BSLS)
#define TD_GRV TD(KC_GRV_TILD)
#define TD_CLN TD(KC_SCLN_COLN)
#define TD_DLR TD(KC_DLR_PLUS)
#define TD_COM TD(KC_COMM_HASH)
#define TD_DOT TD(KC_DOT_PERC)
#define TD_PHP TD(KC_PHP)

// Swedish
#define RALT_W RALT(KC_W)
#define RALT_A RALT(KC_A)
#define RALT_O RALT(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .-----------------------------------------.                    .-----------------------------------------.
 * |L_COL |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   Å  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LSFT |   A  |   S  |   D  |   F  |   G  |-------.    .-------|   H  |   J  |   K  |   L  |   '  |   Ä  |
 * |------+-LGUI-+-LALT-+-LCTL-+-LSFT-+------|       |    |       |------+-LSFT-+-LCTL-+-LALT-+-LGUI-+------|
 * | LCTL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |   Ö  |
 * '---------------RALT----------------------/       /    \       \----------------------RALT---------------'
 *                   |      | ESC  | SPC  | /  TAB  /      \  ENT  \  | BSPC | DEL  |      |
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '---------MIS---NAV-''--MUS--'          '--SYM--''-NUM----FUN---------'
 */

[_QWERTY] = LAYOUT(
  L_COL,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                     KC_6,   KC_7,   KC_8,     KC_9,     KC_0,      KC_NO,
  KC_NO,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,      RALT_W,
  KC_LSFT,  MTQ_A,  MTQ_S,  MTQ_D,  MTQ_F,  KC_G,                     KC_H,   MTQ_J,  MTQ_K,    MTQ_L,    MTQ_QUOT,  RALT_A,
  KC_LCTL,  KC_Z,   MTQ_X,  KC_C,   KC_V,   KC_B,   KC_NO,    KC_NO,  KC_N,   KC_M,   KC_COMM,  MTQ_DOT,  KC_SLSH,   RALT_O,
                            KC_NO,  L_COD,  L_NAV,  L_MUS,    L_SYM,  L_NUM,  L_FUN,  KC_NO
),

/* COLEMAK-DH
 * .-----------------------------------------.                    .-----------------------------------------.
 * |L_QWE |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   '  |   Å  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LSFT |   A  |   R  |   S  |   T  |   G  |-------.    .-------|   M  |   N  |   E  |   I  |   O  |   Ä  |
 * |------+-LGUI-+-LALT-+-LCTL-+-LSFT-+------|       |    |       |------+-LSFT-+-LCTL-+-LALT-+-LGUI-+------|
 * | LCTL |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |   Ö  |
 * '---------------RALT----------------------/       /    \       \----------------------RALT---------------'
 *                   |      | ESC  | SPC  | /  TAB  /      \  ENT  \  | BSPC | DEL  |      |
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '---------MIS---NAV-''--MUS--'          '--SYM--''-NUM----FUN---------'
 */

[_COLEMAK] = LAYOUT(
  L_QWE,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                     KC_6,   KC_7,   KC_8,     KC_9,     KC_0,     KC_NO,
  KC_NO,    KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                     KC_J,   KC_L,   KC_U,     KC_Y,     KC_QUOT,  RALT_W,
  KC_LSFT,  MTC_A,  MTC_R,  MTC_S,  MTC_T,  KC_G,                     KC_M,   MTC_N,  MTC_E,    MTC_I,    MTC_O,    RALT_A,
  KC_LCTL,  KC_Z,   MTC_X,  KC_C,   KC_D,   KC_V,   KC_NO,    KC_NO,  KC_K,   KC_H,   KC_COMM,  MTC_DOT,  KC_SLSH,  RALT_O,
                            KC_NO,  L_COD,  L_NAV,  L_MUS,    L_SYM,  L_NUM,  L_FUN,  KC_NO
),

/* CODE
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | TERM | PHP  | FIX  |      |                    |      |   &  |   |  |   !  |   '  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+---"--+------|
 * |      |   *  |   @  |   >  |   =  |   ^  |-------.    .-------|   [  |   (  |   ;  |   $  |   -  |      |
 * |------+------+------+---<--+------+------|       |    |       |---]--+---)--+---:--+---+--+---_--+------|
 * |      |   `  |      |      | DOCB |      |-------|    |-------|      |   {  |   ,  |   .  |   /  |      |
 * '----------~------------------------------/       /    \       \----------}------#------%------\---------'
 *                   |      |      |      | /       /      \  ENT  \  | BSPC | SPC  |      |
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '-------------------''-------'          '-------''--------------------'
 */

[_CODE] = LAYOUT(
  KC_NO,  KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,                       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,
  KC_NO,  KC_NO,    MOD_GRV,  TD_PHP,  MOD_F,    KC_NO,                       KC_NO,    KC_AMPR,  KC_PIPE,  KC_EXLM,  TD_QUO,  KC_NO,
  KC_NO,  KC_ASTR,  KC_AT,    TD_ABK,  KC_EQL,   KC_CIRC,                     TD_BRC,   TD_PRN,   TD_CLN,   TD_DLR,   TD_DSH,  KC_NO,
  KC_NO,  TD_GRV,   KC_NO,    KC_NO,   KC_DOCB,  KC_NO,    KC_NO,    KC_NO,   KC_NO,    TD_CBR,   TD_COM,   TD_DOT,   TD_SLS,  KC_NO,
                              KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_ENT,  KC_BSPC,  KC_SPC,   KC_NO
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
 * |------+------+------+------+------+------|       |    |       |------+-LSFT-+-LCTL-+-LALT-+-LGUI-+------|
 * |      |   `  |   1  |   2  |   3  |  \   |-------|    |-------|      |      |   ,  |   .  |      |      |
 * '-----------------------------------------/       /    \       \----------------------RALT---------------'
 *                   |      |   .  |  0   | /   -   /      \       \  |      |      |      |
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '-------------------''-------'          '-------''--------------------'
 */

[_NUM] = LAYOUT(
  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,   KC_NO,                        KC_NO,  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
  KC_NO,  KC_LBRC,  KC_7,   KC_8,   KC_9,    KC_RBRC,                      KC_NO,  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,
  KC_NO,  KC_SCLN,  KC_4,   KC_5,   KC_6,    KC_EQL,                       KC_NO,  MTN_PSLS,  MTN_PAST,  MTN_PMNS,  MTN_PPLS,  KC_NO,
  KC_NO,  KC_GRV,   KC_1,   KC_2,   KC_3,    KC_BSLS,  KC_NO,      KC_NO,  KC_NO,  KC_NO,     KC_COMM,   MTN_DOT,   KC_NO,     KC_NO,
                            KC_NO,  KC_DOT,  KC_0,     KC_MINS,    KC_NO,  KC_NO,  KC_NO,     KC_NO
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_DOCB:
      if (record->event.pressed) {
        SEND_STRING_DELAY("/**\n", 50);
      }
      break;
  }

  return true;
};

void td_php(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      SEND_STRING("<?php");
      reset_tap_dance(state);
      break;
    case 2:
      SEND_STRING("?>");
      reset_tap_dance(state);
      break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [KC_RABK_LABK] = ACTION_TAP_DANCE_DOUBLE(KC_RABK, KC_LABK),
  [KC_LBRC_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  [KC_LPRN_RPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [KC_LCBR_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [KC_QUOT_DQUO] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
  [KC_MINS_UNDS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
  [KC_SLSH_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
  [KC_GRV_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),
  [KC_SCLN_COLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
  [KC_DLR_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_DLR, KC_PLUS),
  [KC_COMM_HASH] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_HASH),
  [KC_DOT_PERC] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_PERC),
  [KC_PHP] = ACTION_TAP_DANCE_FN(td_php),
};
