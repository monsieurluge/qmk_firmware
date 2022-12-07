#include QMK_KEYBOARD_H

// layers ----------------------------------------------------------------------

#define LY_BASE 0
#define LY_FN1  1
#define LY_FN2  2
#define LY_FN3  3

// special key shortcuts -------------------------------------------------------

#define CTSP___ CTL_T(KC_SPC)        // space or left control when held
#define HOME___ LGUI(KC_LEFT)        // "home" behaviour on Mac
#define END____ LGUI(KC_RGHT)        // "end" behaviour on Mac
#define LY01___ MO(LY_FN1)           // temporary layer 1
#define LY02___ MO(LY_FN2)           // temporary layer 2
#define LY03___ MO(LY_FN3)           // temporary layer 3

// layouts ---------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* qwerty
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │ esc │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │ bsp │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │ tab │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │enter│
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │shift│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │shift│
     * ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │ alt │ fn3 │ fn1 │ space/ctl │ fn2 │ gui │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
     */

    [LY_BASE] = LAYOUT_planck_grid( \
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    XXXXXXX, XXXXXXX, KC_LALT, LY03___, LY01___, CTSP___, CTSP___, LY02___, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX \
    ),

    /* fn1 - symbols
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │  ~  │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  (  │  )  │ del │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │  '  │  =  │  +  │  {  │  "  │  |  │  }  │  -  │  _  │  `  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │  [  │     │     │  ]  │     │     │  \  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │           │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
     */
    [LY_FN1] = LAYOUT_planck_grid( \
    KC_TILD, KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
    _______, KC_QUOT, KC_EQUAL, KC_PLUS, KC_LCBR, KC_DQT,  KC_PIPE, KC_RCBR, KC_MINS, KC_UNDS, KC_GRV,  _______, \
    _______, XXXXXXX, XXXXXXX,  XXXXXXX, KC_LBRC, XXXXXXX, XXXXXXX, KC_RBRC, XXXXXXX, XXXXXXX, KC_BSLS, _______, \
    _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    /* fn2 - navigation and function keys
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │shift│ctrl │     │     │left │down │ up  │right│     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │     │     │home │pgdwn│pgup │ end │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │     │     │           │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
     */
    [LY_FN2] = LAYOUT_planck_grid( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    _______, XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTRL, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, HOME___, KC_PGDN, KC_PGUP, END____, _______, \
    _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______ \
    ),

    /* fn3 - numbers and media
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │     │     │     │     │     │     │     │  7  │  8  │  9  │  -  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │play │prev │next │     │  0  │  4  │  5  │  6  │  .  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │     │     │     │vol- │vol+ │     │     │  1  │  2  │  3  │  :  │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┼─────┼─────┼─────┼─────┤
     * │RESET│     │     │     │     │     0     │     │     │     │     │     │
     * └─────┴─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┴─────┴─────┘
     */
    [LY_FN3] = LAYOUT_planck_grid( \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_MINS,       _______, \
    _______, XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, KC_0,    KC_4,    KC_5,    KC_6,    KC_DOT,        _______, \
    _______, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    RSFT(KC_SCLN), _______, \
    RESET,   _______, _______, _______, _______, KC_0,    KC_0,    _______, _______, _______, _______,       _______ \
    )
};

// misc ------------------------------------------------------------------------

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void matrix_init_user(void) {
    persistent_default_layer_set(1UL<<LY_BASE);
}
