#include QMK_KEYBOARD_H
#include <stdio.h>

// layers ----------------------------------------------------------------------

#define LY_BASE 0
#define LY_FN1  1
#define LY_FN2  2
#define LY_FN3  3

// special key shortcuts -------------------------------------------------------

#define CTSP___ CTL_T(KC_SPC)        // space or left control when held
#define HOME___ LGUI(KC_LEFT)        // "home" behaviour on Mac
#define END____ LGUI(KC_RGHT)        // "end" behaviour on Mac
#define LY01___ MO(LY_FN1)
#define LY02___ MO(LY_FN2)
#define LY03___ MO(LY_FN3)

// layouts ---------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* qwerty
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  E  ├─────┐                          ┌─────┤  I  ├─────┐
     * ┌─────┬─────┤  W  ├─────┤  R  ├─────┐              ┌─────┤  U  ├─────┤  O  ├─────┬─────┐
     * │ esc │  Q  ├─────┤  D  ├─────┤  T  │              │  Y  ├─────┤  K  ├─────┤  P  │ bsp │
     * ├─────┼─────┤  S  ├─────┤  F  ├─────┤              ├─────┤  J  ├─────┤  L  ├─────┼─────┤
     * │ tab │  A  ├─────┤  C  ├─────┤  G  │              │  H  ├─────┤  ,  ├─────┤  ;  │enter│
     * ├─────┼─────┤  X  ├─────┤  V  ├─────┤              ├─────┤  M  ├─────┤  .  ├─────┼─────┤
     * │shift│  Z  ├─────┘     └─────┤  B  │              │  N  ├─────┘     └─────┤  /  │shift│
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ gui │┌─────┐┌─────┐    ┌─────┐┌─────┐│ gui │
     *                      └─────┘│ fn3 ││ fn1 │    │sp/ct││ fn2 │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_BASE] = LAYOUT_split_3x6_3(
        KC_ESC,    KC_Q, KC_W, KC_E,  KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_TAB,    KC_A, KC_S, KC_D,  KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT,
        KC_LSHIFT, KC_Z, KC_X, KC_C,  KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_LSHIFT,
                             KC_LGUI, LY03___, LY01___, CTSP___, LY02___, KC_RGUI
    ),

    /* fn1 - symbols
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  #  ├─────┐                          ┌─────┤  *  ├─────┐
     * ┌─────┬─────┤  @  ├─────┤  $  ├─────┐              ┌─────┤  &  ├─────┤  (  ├─────┬─────┐
     * │  ~  │  !  ├─────┤  +  ├─────┤  %  │              │  ^  ├─────┤  -  ├─────┤  )  │ del │
     * ├─────┼─────┤  =  ├─────┤  {  ├─────┤              ├─────┤  }  ├─────┤  _  ├─────┼─────┤
     * │     │  '  ├─────┤     ├─────┤  "  │              │  |  ├─────┤  €  ├─────┤  `  │     │
     * ├─────┼─────┤     ├─────┤  [  ├─────┤              ├─────┤  ]  ├─────┤     ├─────┼─────┤
     * │     │     ├─────┘     └─────┤ctrl │              │     ├─────┘     └─────┤  \  │     │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │     │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                      └─────┘│     ││     │    │     ││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN1] = LAYOUT_split_3x6_3(
        KC_TILD, KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
        _______, KC_QUOT, KC_EQUAL, KC_PLUS, KC_LCBR, KC_DQT,   KC_PIPE, KC_RCBR, KC_MINS,    KC_UNDS, KC_GRV,  _______,
        _______, XXXXXXX, XXXXXXX,  XXXXXXX, KC_LBRC, KC_LCTRL, XXXXXXX, KC_RBRC, RALT(KC_5), XXXXXXX, KC_BSLS, _______,
                                    _______, _______, _______,  _______, _______, _______
    ),

    /* fn2 - navigation and function keys
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤ F4  ├─────┐                          ┌─────┤ F9  ├─────┐
     * ┌─────┬─────┤ F3  ├─────┤ F5  ├─────┐              ┌─────┤ F8  ├─────┤ F10 ├─────┬─────┐
     * │ F1  │ F2  ├─────┤shift├─────┤ F6  │              │ F7  ├─────┤down ├─────┤ F11 │ F12 │
     * ├─────┼─────┤     ├─────┤ctrl ├─────┤              ├─────┤left ├─────┤ up  ├─────┼─────┤
     * │     │     ├─────┤     ├─────┤     │              │     ├─────┤pgdwn├─────┤right│     │
     * ├─────┼─────┤     ├─────┤     ├─────┤              ├─────┤home ├─────┤pgup ├─────┼─────┤
     * │     │     ├─────┘     └─────┤     │              │     ├─────┘     └─────┤ end │     │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ alt │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                      └─────┘│     ││     │    │     ││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN2] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, XXXXXXX, XXXXXXX, KC_LSHIFT, KC_LCTRL, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, HOME___, KC_PGDN, KC_PGUP, END____, _______,
                                   KC_LALT,   _______,  _______, _______, _______, _______
    ),

    /* fn3 - numbers and media
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤     ├─────┐                          ┌─────┤  8  ├─────┐
     * ┌─────┬─────┤     ├─────┤     ├─────┐              ┌─────┤  7  ├─────┤  9  ├─────┬─────┐
     * │     │     ├─────┤prev ├─────┤     │              │     ├─────┤  5  ├─────┤  -  │     │
     * ├─────┼─────┤play ├─────┤next ├─────┤              ├─────┤  4  ├─────┤  6  ├─────┼─────┤
     * │     │     ├─────┤vol- ├─────┤     │              │     ├─────┤  2  ├─────┤  0  │     │
     * ├─────┼─────┤     ├─────┤vol+ ├─────┤              ├─────┤  1  ├─────┤  3  ├─────┼─────┤
     * │     │     ├─────┘     └─────┤     │              │     ├─────┘     └─────┤  .  │     │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │     │┌─────┐┌─────┐    ┌─────┐┌─────┐│ alt │
     *                      └─────┘│     ││     │    │  0  ││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN3] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,   KC_9, KC_MINS, _______,
        _______, XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, KC_4,    KC_5,   KC_6, KC_0,    _______,
        _______, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_1,    KC_2,   KC_3, KC_DOT,  _______,
                                   _______, _______, _______, KC_0 ,   _______, KC_RALT
    )
};

// screen ----------------------------------------------------------------------

#ifdef OLED_ENABLE
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
      if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
      }
      return rotation;
    }

    void oled_render_layer_state(void) {
        // does not work as expected but the result is fun
        oled_write_ln_P(PSTR("(╯°□°)╯︵ ┻━┻"), false);
    }

    void oled_task_user(void) {
        if (is_keyboard_master()) {
            oled_render_layer_state();
        }
    }
#endif
