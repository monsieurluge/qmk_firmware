#include QMK_KEYBOARD_H
#include <stdio.h>

// layers ----------------------------------------------------------------------

#define LY_CLMK 0
#define LY_GAME 1
#define LY_EDIT 2
#define LY_FN1  3
#define LY_FN2  4
#define LY_FN3  5

// special key shortcuts -------------------------------------------------------

#define CUT____ LCTL(KC_X)
#define COPY___ LCTL(KC_C)
#define PASTE__ LCTL(KC_V)
#define UNDO___ LCTL(KC_Z)
#define BACK___ LALT(KC_LEFT)        // browser "back" shortcut
#define FORWARD LALT(KC_RIGHT)       // browser "forward" shortcut
#define GAME___ TG(LY_GAME)          // toggles the "gaming" layer
#define EDIT___ TG(LY_EDIT)          // toggles the "edit" layer
#define CTTB___ CTL_T(KC_TAB)        // tab or left control when held
#define CTEN___ CTL_T(KC_ENT)        // enter or left control when held
#define SPSH___ MT(MOD_LSFT, KC_SPC) // space or left shift when held
#define CTSP___ CTL_T(KC_SPC)        // space or left control when held
#define LY01___ MO(LY_FN1)
#define LY02___ MO(LY_FN2)
#define LY03___ MO(LY_FN3)

// layouts ---------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* colemak mod DHm
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  F  ├─────┐                          ┌─────┤  U  ├─────┐
     * ┌─────┬─────┤  W  ├─────┤  P  ├─────┐              ┌─────┤  L  ├─────┤  Y  ├─────┬─────┐
     * │ esc │  Q  ├─────┤  S  ├─────┤  B  │              │  J  ├─────┤  E  ├─────┤  ;  │ bsp │
     * ├─────┼─────┤  R  ├─────┤  T  ├─────┤              ├─────┤  N  ├─────┤  I  ├─────┼─────┤
     * │ tab │  A  ├─────┤  C  ├─────┤  G  │              │  M  ├─────┤  ,  ├─────┤  O  │enter│
     * ├─────┼─────┤  X  ├─────┤  D  ├─────┤              ├─────┤  H  ├─────┤  .  ├─────┼─────┤
     * │ gui │  Z  ├─────┘     └─────┤  V  │              │  K  ├─────┘     └─────┤  /  │ alt │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ fn3 │┌─────┐┌─────┐    ┌─────┐┌─────┐│ctrl │
     *                      └─────┘│ fn1 ││shift│    │space││ fn2 │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */

    [LY_CLMK] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q, KC_W, KC_F,    KC_P,    KC_B,    KC_J,   KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_BSPC,
        KC_TAB,  KC_A, KC_R, KC_S,    KC_T,    KC_G,    KC_M,   KC_N,    KC_E,    KC_I,   KC_O,    KC_ENT,
        KC_LGUI, KC_Z, KC_X, KC_C,    KC_D,    KC_V,    KC_K,   KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_LALT,
                             LY03___, LY01___, KC_LSFT, KC_SPC, LY02___, KC_LCTRL
    ),

    /* gaming "layer mask"
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤     ├─────┐                          ┌─────┤     ├─────┐
     * ┌─────┬─────┤     ├─────┤     ├─────┐              ┌─────┤     ├─────┤     ├─────┬─────┐
     * │ esc │     ├─────┤     ├─────┤     │              │     ├─────┤     ├─────┤     │ bsp │
     * ├─────┼─────┤     ├─────┤     ├─────┤              ├─────┤     ├─────┤     ├─────┼─────┤
     * │ tab │     ├─────┤     ├─────┤     │              │     ├─────┤     ├─────┤     │enter│
     * ├─────┼─────┤     ├─────┤     ├─────┤              ├─────┤     ├─────┤     ├─────┼─────┤
     * │shift│     ├─────┘     └─────┤     │              │     ├─────┘     └─────┤     │ gui │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ctrl │┌─────┐┌─────┐    ┌─────┐┌─────┐│ fn3 │
     *                      └─────┘│space││ fn1 │    │space││ fn2 │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_GAME] = LAYOUT_split_3x6_3(
        KC_ESC,  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, KC_BSPC,
        KC_TAB,  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, KC_ENT,
        KC_LSFT, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, KC_LGUI,
                                   KC_LCTRL, KC_SPC,  LY01___, KC_SPC,  LY02___, LY03___
    ),

    /* editing "layer mask"
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤ --- ├─────┐                          ┌─────┤     ├─────┐
     * ┌─────┬─────┤ --- ├─────┤ --- ├─────┐              ┌─────┤     ├─────┤     ├─────┬─────┐
     * │ --- │ --- ├─────┤ --- ├─────┤ --- │              │     ├─────┤     ├─────┤     │     │
     * ├─────┼─────┤ --- ├─────┤ --- ├─────┤              ├─────┤     ├─────┤     ├─────┼─────┤
     * │ --- │ --- ├─────┤copy ├─────┤ --- │              │     ├─────┤     ├─────┤     │     │
     * ├─────┼─────┤ cut ├─────┤ --- ├─────┤              ├─────┤     ├─────┤     ├─────┼─────┤
     * │ --- │undo ├─────┘     └─────┤paste│              │     ├─────┘     └─────┤     │     │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ fn3 │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                      └─────┘│ctrl ││shift│    │     ││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_EDIT] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, _______, _______, _______, _______, _______, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, _______, _______, _______, _______, _______, _______,
        XXXXXXX, UNDO___, CUT____, COPY___, XXXXXXX,  PASTE__, _______, _______, _______, _______, _______, _______,
                                   _______, KC_LCTRL, _______, _______, _______, _______
    ),

    /* fn1 - symbols
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  #  ├─────┐                          ┌─────┤  *  ├─────┐
     * ┌─────┬─────┤  @  ├─────┤  $  ├─────┐              ┌─────┤  &  ├─────┤  (  ├─────┬─────┐
     * │  ~  │  !  ├─────┤  +  ├─────┤  %  │              │  ^  ├─────┤  -  ├─────┤  )  │ del │
     * ├─────┼─────┤  =  ├─────┤  {  ├─────┤              ├─────┤  }  ├─────┤  _  ├─────┼─────┤
     * │     │  '  ├─────┤     ├─────┤  "  │              │  |  ├─────┤  €  ├─────┤  `  │     │
     * ├─────┼─────┤     ├─────┤  [  ├─────┤              ├─────┤  ]  ├─────┤     ├─────┼─────┤
     * │menu │     ├─────┘     └─────┤ctrl │              │     ├─────┘     └─────┤  \  │     │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │     │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                      └─────┘│     ││     │    │     ││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN1] = LAYOUT_split_3x6_3(
        KC_TILD, KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
        _______, KC_QUOT, KC_EQUAL, KC_PLUS, KC_LCBR, KC_DQT,   KC_PIPE, KC_RCBR, KC_MINS,    KC_UNDS, KC_GRV,  _______,
        KC_APP,  _______, _______,  _______, KC_LBRC, KC_LCTRL, XXXXXXX, KC_RBRC, RALT(KC_5), XXXXXXX, KC_BSLS, _______,
                                    _______, _______, _______,  _______, _______, _______
    ),

    /* fn2 - navigation and function keys
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤ F4  ├─────┐                          ┌─────┤ F9  ├─────┐
     * ┌─────┬─────┤ F3  ├─────┤ F5  ├─────┐              ┌─────┤ F8  ├─────┤ F10 ├─────┬─────┐
     * │ F1  │ F2  ├─────┤     ├─────┤ F6  │              │ F7  ├─────┤down ├─────┤ F11 │ F12 │
     * ├─────┼─────┤     ├─────┤ctrl ├─────┤              ├─────┤left ├─────┤ up  ├─────┼─────┤
     * │     │     ├─────┤     ├─────┤     │              │home ├─────┤pgdwn├─────┤right│     │
     * ├─────┼─────┤     ├─────┤     ├─────┤              ├─────┤ end ├─────┤pgup ├─────┼─────┤
     * │     │     ├─────┘     └─────┤ptscr│              │back ├─────┘     └─────┤     │     │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │     │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                      └─────┘│     ││     │    │     ││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN2] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTRL, XXXXXXX,    KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_PSCREEN, BACK___, KC_END,  KC_PGDN, KC_PGUP, XXXXXXX, _______,
                                   _______, _______,  _______,    _______, _______, _______
    ),

    /* fn3 - numbers and media
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤     ├─────┐                          ┌─────┤  8  ├─────┐
     * ┌─────┬─────┤     ├─────┤     ├─────┐              ┌─────┤  7  ├─────┤  9  ├─────┬─────┐
     * │     │     ├─────┤prev ├─────┤game │              │     ├─────┤  5  ├─────┤  -  │     │
     * ├─────┼─────┤play ├─────┤next ├─────┤              ├─────┤  4  ├─────┤  6  ├─────┼─────┤
     * │     │     ├─────┤vol- ├─────┤edit │              │     ├─────┤  2  ├─────┤  .  │     │
     * ├─────┼─────┤     ├─────┤vol+ ├─────┤              ├─────┤  1  ├─────┤  3  ├─────┼─────┤
     * │     │     ├─────┘     └─────┤     │              │     ├─────┘     └─────┤  0  │     │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │     │┌─────┐┌─────┐    ┌─────┐┌─────┐│     │
     *                      └─────┘│     ││     │    │  0  ││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN3] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAME___, XXXXXXX, KC_7,    KC_8,   KC_9, KC_MINS, _______,
        _______, XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, EDIT___, XXXXXXX, KC_4,    KC_5,   KC_6, KC_DOT,  _______,
        _______, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_1,    KC_2,   KC_3, KC_0,    _______,
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
    #define LS_EDIT 4

    void oled_render_layer_state(void) {
        switch (layer_state) {
            case LS_BASE:
                oled_write_ln_P(PSTR("__BASE"), false);
                break;
            case LS_GAME:
                oled_write_ln_P(PSTR("__GAME"), false);
                break;
            case LS_EDIT:
                oled_write_ln_P(PSTR("__EDIT"), false);
                break;
            default:
                oled_write_ln_P(PSTR("__TEMPORARY"), false);
                break;
        }
    }

    void oled_task_user(void) {
        if (is_keyboard_master()) {
            oled_render_layer_state();
        }
    }
#endif
