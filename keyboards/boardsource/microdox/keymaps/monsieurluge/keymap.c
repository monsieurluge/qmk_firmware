#include QMK_KEYBOARD_H

// layers ----------------------------------------------------------------------

#define LY_MAIN 0
#define LY_FN1  1

// special key shortcuts -------------------------------------------------------

#define SP_LY01 MO(LY_FN1)

// layouts ---------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* qwerty-like gaming layout
     *             ┌─────┐                                      ┌─────┐
     *       ┌─────┤  W  ├─────┐                          ┌─────┤     ├─────┐
     * ┌─────┤  Q  ├─────┤  E  ├─────┐              ┌─────┤     ├─────┤     ├─────┐
     * │ esc ├─────┤  S  ├─────┤  R  │              │     ├─────┤     ├─────┤     │
     * ├─────┤  A  ├─────┤  D  ├─────┤              ├─────┤     ├─────┤     ├─────┤
     * │ tab ├─────┤  X  ├─────┤  F  │              │     ├─────┤     ├─────┤     │
     * ├─────┤  Z  ├─────┤  C  ├─────┤              ├─────┤     ├─────┤     ├─────┤
     * │shift├─────┘     └─────┤  V  │              │     ├─────┘     └─────┤     │
     * └─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┘
     *                │ fn1 │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                └─────┘│ctrl ││space│    │     ││     │└─────┘
     *                       └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_MAIN] = LAYOUT_split_3x5_3( \
        KC_ESC,  KC_Q, KC_W, KC_E,     KC_R,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        KC_TAB,  KC_A, KC_S, KC_D,     KC_F,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        KC_LSFT, KC_Z, KC_X, KC_C,     KC_V,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                    SP_LY01, KC_LCTRL, KC_SPC, XXXXXXX, XXXXXXX, XXXXXXX \
    ),

    /* fn1 - shortcuts
     *             ┌─────┐                                      ┌─────┐
     *       ┌─────┤     ├─────┐                          ┌─────┤     ├─────┐
     * ┌─────┤     ├─────┤     ├─────┐              ┌─────┤     ├─────┤     ├─────┐
     * │     ├─────┤     ├─────┤     │              │     ├─────┤     ├─────┤     │
     * ├─────┤     ├─────┤     ├─────┤              ├─────┤     ├─────┤     ├─────┤
     * │     ├─────┤     ├─────┤     │              │     ├─────┤     ├─────┤     │
     * ├─────┤ F5  ├─────┤ F9  ├─────┤              ├─────┤     ├─────┤     ├─────┤
     * │ gui ├─────┘     └─────┤ F12 │              │     ├─────┘     └─────┤     │
     * └─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┘
     *                │     │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                └─────┘│     ││pscr │    │     ││     │└─────┘
     *                       └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN1] = LAYOUT_split_3x5_3( \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        KC_LGUI, KC_F5,   XXXXXXX, KC_F9,   KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                          _______, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX \
    ),
};

// misc ------------------------------------------------------------------------

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void matrix_init_user(void) {
    persistent_default_layer_set(1UL<<LY_MAIN); // set the default
}
