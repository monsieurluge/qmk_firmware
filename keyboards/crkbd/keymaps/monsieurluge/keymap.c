#include QMK_KEYBOARD_H
#include <stdio.h>

// layers ----------------------------------------------------------------------

#define LY_BASE 0
#define LY_GAME 1
#define LY_FN1  2
#define LY_FN2  3
#define LY_FN3  4

// special key shortcuts -------------------------------------------------------

#define CTSP___ CTL_T(KC_SPC)        // space or left control when held
#define FN3SP__ LT(LY_FN3, KC_SPC)   // space or fn3 when held
#define HOME___ LGUI(KC_LEFT)        // "home" behaviour on Mac
#define END____ LGUI(KC_RGHT)        // "end" behaviour on Mac
#define GUIALT_ TD(TD_GUI_ALT)       // tap dance: GUI then ALT
#define GAME___ TG(LY_GAME)          // toggles the GAMING layer
#define LY01___ MO(LY_FN1)
#define LY02___ MO(LY_FN2)
#define LY03___ MO(LY_FN3)

// tap dance -------------------------------------------------------------------

enum {
    TD_GUI_ALT = 0,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_GUI_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_RGUI, KC_RALT),
};

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
     * │shift│  Z  ├─────┘     └─────┤  B  │              │  N  ├─────┘     └─────┤  /  │ alt │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ fn3 │┌─────┐┌─────┐    ┌─────┐┌─────┐│ gui │
     *                      └─────┘│ fn1 ││shift│    │sp/ct││ fn2 │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_BASE] = LAYOUT_split_3x6_3(
        KC_ESC,    KC_Q, KC_W, KC_E,  KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_TAB,    KC_A, KC_S, KC_D,  KC_F,    KC_G,      KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT,
        KC_LSHIFT, KC_Z, KC_X, KC_C,  KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RALT,
                             LY03___, LY01___, KC_LSHIFT, CTSP___, LY02___, KC_RGUI
    ),

    /* gaming layer
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  E  ├─────┐                          ┌─────┤  I  ├─────┐
     * ┌─────┬─────┤  W  ├─────┤  R  ├─────┐              ┌─────┤  U  ├─────┤  O  ├─────┬─────┐
     * │ esc │  Q  ├─────┤  D  ├─────┤  T  │              │  Y  ├─────┤  K  ├─────┤  P  │ bsp │
     * ├─────┼─────┤  S  ├─────┤  F  ├─────┤              ├─────┤  J  ├─────┤  L  ├─────┼─────┤
     * │ tab │  A  ├─────┤  C  ├─────┤  G  │              │  H  ├─────┤  ,  ├─────┤  ;  │enter│
     * ├─────┼─────┤  X  ├─────┤  V  ├─────┤              ├─────┤  M  ├─────┤  .  ├─────┼─────┤
     * │shift│  Z  ├─────┘     └─────┤  B  │              │  N  ├─────┘     └─────┤  /  │shift│
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ ctl │┌─────┐┌─────┐    ┌─────┐┌─────┐│ gui │
     *                      └─────┘│space││ fn1 │    │sp/f3││ fn2 │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_GAME] = LAYOUT_split_3x6_3(
        KC_ESC,    KC_Q, KC_W, KC_E,  KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_TAB,    KC_A, KC_S, KC_D,  KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT,
        KC_LSHIFT, KC_Z, KC_X, KC_C,  KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSHIFT,
                             KC_LCTL, KC_SPC, LY01___, FN3SP__, LY02___, KC_RGUI
    ),

    /* fn1 - symbols
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  #  ├─────┐                          ┌─────┤  *  ├─────┐
     * ┌─────┬─────┤  @  ├─────┤  $  ├─────┐              ┌─────┤  &  ├─────┤  (  ├─────┬─────┐
     * │     │  !  ├─────┤  +  ├─────┤  %  │              │  ^  ├─────┤  -  ├─────┤  )  │     │
     * ├─────┼─────┤  =  ├─────┤  {  ├─────┤              ├─────┤  }  ├─────┤  _  ├─────┼─────┤
     * │     │  '  ├─────┤  ~  ├─────┤  "  │              │  |  ├─────┤  €  ├─────┤  `  │     │
     * ├─────┼─────┤     ├─────┤  [  ├─────┤              ├─────┤  ]  ├─────┤     ├─────┼─────┤
     * │ alt │     ├─────┘     └─────┤     │              │     ├─────┘     └─────┤  \  │     │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │     │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                      └─────┘│     ││     │    │     ││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN1] = LAYOUT_split_3x6_3(
        _______, KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN, _______,
        _______, KC_QUOT, KC_EQUAL, KC_PLUS, KC_LCBR, KC_DQT,  KC_PIPE, KC_RCBR, KC_MINS,    KC_UNDS, KC_GRV,  _______,
        KC_RALT, XXXXXXX, XXXXXXX,  KC_TILD, KC_LBRC, XXXXXXX, XXXXXXX, KC_RBRC, RALT(KC_5), XXXXXXX, KC_BSLS, _______,
                                    _______, _______, _______, _______, _______, _______
    ),

    /* fn2 - navigation and function keys
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤     ├─────┐                          ┌─────┤     ├─────┐
     * ┌─────┬─────┤     ├─────┤     ├─────┐              ┌─────┤ bsp ├─────┤     ├─────┬─────┐
     * │     │     ├─────┤shift├─────┤     │              │     ├─────┤down ├─────┤ del │     │
     * ├─────┼─────┤     ├─────┤ctrl ├─────┤              ├─────┤left ├─────┤ up  ├─────┼─────┤
     * │     │     ├─────┤     ├─────┤     │              │     ├─────┤pgdwn├─────┤right│     │
     * ├─────┼─────┤     ├─────┤     ├─────┤              ├─────┤home ├─────┤pgup ├─────┼─────┤
     * │     │     ├─────┘     └─────┤GAME │              │     ├─────┘     └─────┤ end │     │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │     │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                      └─────┘│     ││     │    │     ││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN2] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX, XXXXXXX, KC_DEL,  _______,
        _______, XXXXXXX, XXXXXXX, KC_LSHIFT, KC_LCTRL, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  GAME___, XXXXXXX, HOME___, KC_PGDN, KC_PGUP, END____, _______,
                                   _______,   _______,  _______, _______, _______, _______
    ),

    /* fn3 - numbers and media
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤     ├─────┐                          ┌─────┤  8  ├─────┐
     * ┌─────┬─────┤     ├─────┤     ├─────┐              ┌─────┤  7  ├─────┤  9  ├─────┬─────┐
     * │     │     ├─────┤prev ├─────┤     │              │     ├─────┤  5  ├─────┤     │     │
     * ├─────┼─────┤play ├─────┤next ├─────┤              ├─────┤  4  ├─────┤  6  ├─────┼─────┤
     * │     │     ├─────┤vol- ├─────┤     │              │     ├─────┤  2  ├─────┤  .  │     │
     * ├─────┼─────┤     ├─────┤vol+ ├─────┤              ├─────┤  1  ├─────┤  3  ├─────┼─────┤
     * │     │     ├─────┘     └─────┤     │              │     ├─────┘     └─────┤     │     │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │     │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                      └─────┘│     ││     │    │  0  ││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN3] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,   KC_9, _______, _______,
        _______, XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, KC_4,    KC_5,   KC_6, KC_DOT,  _______,
        _______, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_1,    KC_2,   KC_3, XXXXXXX, _______,
                                   _______, _______, _______, KC_0 ,   _______, _______
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

    #define LS_BASE 0
    #define LS_GAME 2

    void oled_render_layer_state(void) {
        switch (layer_state) {
            case LS_BASE:
                oled_write_ln_P(PSTR("stay focused!"), false);
                break;
            case LS_GAME:
                oled_write_ln_P(PSTR("let's play!"), false);
                break;
            default:
                // display nothing when a temporary layer is active
                break;
        }
    }

    void oled_task_user(void) {
        if (is_keyboard_master()) {
            oled_render_layer_state();
        }
    }
#endif
