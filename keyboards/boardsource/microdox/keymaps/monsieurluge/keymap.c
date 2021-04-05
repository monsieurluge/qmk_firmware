#include QMK_KEYBOARD_H

// layers ----------------------------------------------------------------------

#define LY_MAIN 0
#define LY_FN1  1
#define LY_FN2  2
#define LY_FN3  3

// special key shortcuts -------------------------------------------------------

#define CUT     LCTL(KC_X)
#define COPY    LCTL(KC_C)
#define PASTE   LCTL(KC_V)
#define UNDO    LCTL(KC_Z)
#define SP_CTTB CTL_T(KC_TAB)        // tab or left control when held
#define SP_CTEN CTL_T(KC_ENT)        // enter or left control when held
#define SP_SPSH MT(MOD_LSFT, KC_SPC) // space or left shift when held
#define SP_LY01 MO(LY_FN1)
#define SP_LY02 MO(LY_FN2)
#define SP_LY03 MO(LY_FN3)

// layouts ---------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* colemak mod DHm
     *             ┌─────┐                                      ┌─────┐
     *       ┌─────┤  F  ├─────┐                          ┌─────┤  U  ├─────┐
     * ┌─────┤  W  ├─────┤  P  ├─────┐              ┌─────┤  L  ├─────┤  Y  ├─────┐
     * │  Q  ├─────┤  S  ├─────┤  B  │              │  J  ├─────┤  E  ├─────┤  ;  │
     * ├─────┤  R  ├─────┤  T  ├─────┤              ├─────┤  N  ├─────┤  I  ├─────┤
     * │  A  ├─────┤  C  ├─────┤  G  │              │  M  ├─────┤  ,  ├─────┤  O  │
     * ├─────┤  X  ├─────┤  D  ├─────┤              ├─────┤  H  ├─────┤  .  ├─────┤
     * │  Z  ├─────┘     └─────┤  V  │              │  K  ├─────┘     └─────┤  /  │
     * └─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┘
     *                │ fn3 │┌─────┐┌─────┐    ┌─────┐┌─────┐│ctrl │
     *                └─────┘│ fn1 ││shift│    │space││ fn2 │└─────┘
     *                       └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_MAIN] = LAYOUT_split_3x5_3( \
    KC_Q, KC_W, KC_F,    KC_P,    KC_B,    KC_J,   KC_L,    KC_U,    KC_Y,   KC_SCLN, \
    KC_A, KC_R, KC_S,    KC_T,    KC_G,    KC_M,   KC_N,    KC_E,    KC_I,   KC_O, \
    KC_Z, KC_X, KC_C,    KC_D,    KC_V,    KC_K,   KC_H,    KC_COMM, KC_DOT, KC_SLSH, \
                SP_LY03, SP_LY01, KC_LSFT, KC_SPC, SP_LY02, KC_LCTRL \
    ),

    /* fn1 - symbols
     *             ┌─────┐                                      ┌─────┐
     *       ┌─────┤  #  ├─────┐                          ┌─────┤  *  ├─────┐
     * ┌─────┤  @  ├─────┤  $  ├─────┐              ┌─────┤  &  ├─────┤  (  ├─────┐
     * │  !  ├─────┤  +  ├─────┤  %  │              │  ^  ├─────┤  -  ├─────┤  )  │
     * ├─────┤  =  ├─────┤  {  ├─────┤              ├─────┤  }  ├─────┤  _  ├─────┤
     * │  '  ├─────┤copy ├─────┤  "  │              │  |  ├─────┤  €  ├─────┤  `  │
     * ├─────┤ cut ├─────┤  [  ├─────┤              ├─────┤  ]  ├─────┤     ├─────┤
     * │undo ├─────┘     └─────┤paste│              │     ├─────┘     └─────┤  \  │
     * └─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┘
     *                │     │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                └─────┘│     ││     │    │     ││     │└─────┘
     *                       └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN1] = LAYOUT_split_3x5_3( \
    KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN, \
    KC_QUOT, KC_EQUAL, KC_PLUS, KC_LCBR, KC_DQT,  KC_PIPE, KC_RCBR, KC_MINS,    KC_UNDS, KC_GRV, \
    UNDO,    CUT,      COPY,    KC_LBRC, PASTE,   XXXXXXX, KC_RBRC, RALT(KC_5), XXXXXXX, KC_BSLS, \
                       _______, _______, _______, _______, _______, _______ \
    ),

    /* fn2 - navigation and function keys
     *             ┌─────┐                                      ┌─────┐
     *       ┌─────┤ F4  ├─────┐                          ┌─────┤ F9  ├─────┐
     * ┌─────┤ F3  ├─────┤ F5  ├─────┐              ┌─────┤ F8  ├─────┤ F10 ├─────┬─────┐
     * │ F2  ├─────┤     ├─────┤ F6  │              │ F7  ├─────┤down ├─────┤ F11 │ F12 │
     * ├─────┤     ├─────┤ctrl ├─────┤              ├─────┤left ├─────┤ up  ├─────┼─────┤
     * │     ├─────┤     ├─────┤     │              │home ├─────┤pgdwn├─────┤right│     │
     * ├─────┤     ├─────┤     ├─────┤              ├─────┤ end ├─────┤pgup ├─────┼─────┤
     * │     ├─────┘     └─────┤ptscr│              │     ├─────┘     └─────┤     │     │
     * └─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                │     │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                └─────┘│     ││     │    │     ││     │└─────┘
     *                       └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN2] = LAYOUT_split_3x5_3( \
    KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTRL, XXXXXXX,    KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_PSCREEN, XXXXXXX, KC_END,  KC_PGDN, KC_PGUP, XXXXXXX, \
                      _______, _______,  _______,    _______, _______, _______ \
    ),

    /* fn3 - numbers and media
     *             ┌─────┐                                      ┌─────┐
     *       ┌─────┤     ├─────┐                          ┌─────┤  8  ├─────┐
     * ┌─────┤     ├─────┤     ├─────┐              ┌─────┤  7  ├─────┤  9  ├─────┐
     * │     ├─────┤prev ├─────┤     │              │     ├─────┤  5  ├─────┤  -  │
     * ├─────┤play ├─────┤next ├─────┤              ├─────┤  4  ├─────┤  6  ├─────┤
     * │     ├─────┤vol- ├─────┤     │              │     ├─────┤  2  ├─────┤  .  │
     * ├─────┤mute ├─────┤vol+ ├─────┤              ├─────┤  1  ├─────┤  3  ├─────┤
     * │     ├─────┘     └─────┤     │              │     ├─────┘     └─────┤  0  │
     * └─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┘
     *                │     │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                └─────┘│     ││     │    │  0  ││     │└─────┘
     *                       └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN3] = LAYOUT_split_3x5_3( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,   KC_9, KC_MINS, \
    XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, KC_4,    KC_5,   KC_6, KC_DOT, \
    XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_1,    KC_2,   KC_3, KC_0, \
                      _______, _______, _______, KC_0 ,   _______, _______ \
    )
};

// misc ------------------------------------------------------------------------

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void matrix_init_user(void) {
    persistent_default_layer_set(1UL<<LY_MAIN); // set the default
}
