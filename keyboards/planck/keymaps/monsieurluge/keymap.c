#include QMK_KEYBOARD_H

// layers ----------------------------------------------------------------------

#define LY_CLMK 0
#define LY_GAME 1
#define LY_FN1  2
#define LY_FN2  3
#define LY_FN3  4

// special key shortcuts -------------------------------------------------------

#define SP_EURO RALT(KC_5)
#define BACK___ LALT(KC_LEFT)        // browser "back" shortcut
#define CTSP___ CTL_T(KC_SPC)        // space or left control when held
#define SP_LY01 MO(LY_FN1)
#define SP_LY02 MO(LY_FN2)
#define SP_LY03 MO(LY_FN3)
#define TOGG___ TG(LY_GAME)          // toggles the permanent layer

// layouts ---------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* colemak mod DHm
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │ esc │  Q  │  W  │  F  │  P  │  B  │  J  │  L  │  U  │  Y  │  ;  │ bsp │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │ tab │  A  │  R  │  S  │  T  │  G  │  M  │  N  │  E  │  I  │  O  │enter│
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │shift│  Z  │  X  │  C  │  D  │  V  │  K  │  H  │  ,  │  .  │  /  │shift│
     * ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
     * │ fn3 │     │ gui │ fn3 │ fn1 │ space/ctl │ fn2 │ alt │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
     */

    [LY_CLMK] = LAYOUT_planck_grid( \
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
    KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    SP_LY03, XXXXXXX, KC_LGUI, SP_LY03, SP_LY01, CTSP___, CTSP___, SP_LY02, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX \
    ),

    /* qwerty gaming layout
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │ esc │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ bsp │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │ tab │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  M  │enter│
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │shift│  Z  │  X  │  C  │  V  │  D  │  B  │  N  │  ,  │  .  │  /  │shift│
     * ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
     * │ fn3 │     │ fn1 │ctrl │space│ space/ctl │ fn2 │ alt │     │     │ gui │
     * └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
     */

    [LY_GAME] = LAYOUT_planck_grid( \
    KC_ESC,  KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_TAB,  KC_A,    KC_S,    KC_D,     KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_M,    KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,   KC_D,    KC_B,    KC_N,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    SP_LY03, XXXXXXX, SP_LY01, KC_LCTRL, KC_SPC, CTSP___, CTSP___, SP_LY02, KC_LALT, XXXXXXX, XXXXXXX, KC_LGUI \
    ),

    /* fn1 - symbols
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │  ~  │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  (  │  )  │ del │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │  '  │  =  │  +  │  {  │  "  │  |  │  }  │  -  │  _  │  `  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │  [  │  /  │  \  │  ]  │  €  │     │  \  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │menu │     │     │           │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
     */
    [LY_FN1] = LAYOUT_planck_grid( \
    KC_TILD, KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
    _______, KC_QUOT, KC_EQUAL, KC_PLUS, KC_LCBR, KC_DQT,  KC_PIPE, KC_RCBR, KC_MINS, KC_UNDS, KC_GRV,  _______, \
    _______, XXXXXXX, XXXXXXX,  XXXXXXX, KC_LBRC, KC_SLSH, KC_BSLS, KC_RBRC, SP_EURO, XXXXXXX, KC_BSLS, _______, \
    _______, _______, KC_APP,   _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    /* fn2 - navigation and function keys
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │shift│ctrl │     │home │left │down │ up  │right│     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │ptscr│     │back │ end │pgdwn│pgup │     │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │           │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
     */
    [LY_FN2] = LAYOUT_planck_grid( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    _______, XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTRL, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,  XXXXXXX, BACK___, KC_END,  KC_PGDN, KC_PGUP, XXXXXXX, _______, \
    _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______ \
    ),

    /* fn3 - numbers and media
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │TOGGL│     │     │     │     │     │     │  7  │  8  │  9  │  -  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │play │prev │next │     │     │  4  │  5  │  6  │  .  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │vol- │vol+ │     │     │  1  │  2  │  3  │  /  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
     * │RESET│     │     │     │     │     0     │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
     */
    [LY_FN3] = LAYOUT_planck_grid( \
    TOGG___, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_MINS, _______, \
    _______, XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_DOT,  _______, \
    _______, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_SLSH, _______, \
    RESET,   _______, _______, _______, _______, KC_0,    KC_0,    _______, _______, _______, _______, _______ \
    )
};

// misc ------------------------------------------------------------------------

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void matrix_init_user(void) {
    persistent_default_layer_set(1UL<<LY_CLMK);
}
