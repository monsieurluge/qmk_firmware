#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
    #include "lufa.h"
    #include "split_util.h"
#endif
#ifdef SSD1306OLED
    #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

extern uint8_t is_master;

// custom keycodes -------------------------------------------------------------

enum custom_keycodes {
    COLMAK = SAFE_RANGE,
    QWERTY,
    GAMING,
    FN1,
    FN2,
    FN3
};

// layers ----------------------------------------------------------------------

#define LY_CLMK 0
#define LY_QWER 1
#define LY_GAME 2
#define LY_FN1  3
#define LY_FN2  4
#define LY_FN3  5

// special key shortcuts -------------------------------------------------------

#define SP_CTEN CTL_T(KC_ENT)        // enter or left control when held
#define SP_CTTB CTL_T(KC_TAB)        // tab or left control when held
#define SP_SPSH MT(MOD_LSFT, KC_SPC) // space or left shift when held

// layouts ---------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* colemak mod DHm
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  F  ├─────┐                          ┌─────┤  U  ├─────┐
     * ┌─────┬─────┤  W  ├─────┤  P  ├─────┐              ┌─────┤  L  ├─────┤  Y  ├─────┬─────┐
     * │ esc │  Q  ├─────┤  S  ├─────┤  B  │              │  J  ├─────┤  E  ├─────┤  ;  │ bsp │
     * ├─────┼─────┤  R  ├─────┤  T  ├─────┤              ├─────┤  N  ├─────┤  I  ├─────┼─────┤
     * │tb/ct│  A  ├─────┤  C  ├─────┤  G  │              │  M  ├─────┤  ,  ├─────┤  O  │en/ct│
     * ├─────┼─────┤  X  ├─────┤  D  ├─────┤              ├─────┤  H  ├─────┤  .  ├─────┼─────┤
     * │shift│  Z  ├─────┘     └─────┤  V  │              │  K  ├─────┘     └─────┤  /  │ralt │
     * └─────┴─────┘        ┌─────┐  └─────┼─────┐  ┌─────┼─────┘  ┌─────┐        └─────┴─────┘
     *                      │ gui │┌─────┐ │ fn1 │  │sp/sh│ ┌─────┐│ alt │
     *                      └─────┘│ fn3 ││     │    │     ││ fn2 │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_CLMK] = LAYOUT( \
    KC_ESC,  KC_Q, KC_W, KC_F,    KC_P, KC_B,        KC_J,    KC_L, KC_U,    KC_Y,   KC_SCLN, KC_BSPC, \
    SP_CTTB, KC_A, KC_R, KC_S,    KC_T, KC_G,        KC_M,    KC_N, KC_E,    KC_I,   KC_O,    SP_CTEN, \
    KC_LSFT, KC_Z, KC_X, KC_C,    KC_D, KC_V,        KC_K,    KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RALT, \
                         KC_LGUI, FN3,  FN1,         SP_SPSH, FN2,  KC_LALT \
    ),

    /* qwerty
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  E  ├─────┐                          ┌─────┤  I  ├─────┐
     * ┌─────┬─────┤  W  ├─────┤  R  ├─────┐              ┌─────┤  U  ├─────┤  O  ├─────┬─────┐
     * │ esc │  Q  ├─────┤  D  ├─────┤  T  │              │  Y  ├─────┤  K  ├─────┤  P  │ bsp │
     * ├─────┼─────┤  S  ├─────┤  F  ├─────┤              ├─────┤  J  ├─────┤  L  ├─────┼─────┤
     * │tb/ct│  A  ├─────┤  C  ├─────┤  G  │              │  H  ├─────┤  ,  ├─────┤  ;  │en/ct│
     * ├─────┼─────┤  X  ├─────┤  V  ├─────┤              ├─────┤  M  ├─────┤  .  ├─────┼─────┤
     * │shift│  Z  ├─────┘     └─────┤  B  │              │  N  ├─────┘     └─────┤  /  │ralt │
     * └─────┴─────┘        ┌─────┐  └─────┼─────┐  ┌─────┼─────┘  ┌─────┐        └─────┴─────┘
     *                      │ gui │┌─────┐ │ fn1 │  │sp/sh│ ┌─────┐│ alt │
     *                      └─────┘│ fn3 ││     │    │     ││ fn2 │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_QWER] = LAYOUT( \
    KC_ESC,  KC_Q, KC_W, KC_E,    KC_R, KC_T,        KC_Y,    KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC, \
    SP_CTTB, KC_A, KC_S, KC_D,    KC_F, KC_G,        KC_H,    KC_J, KC_K,    KC_L,   KC_SCLN, SP_CTEN, \
    KC_LSFT, KC_Z, KC_X, KC_C,    KC_V, KC_B,        KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RALT, \
                         KC_LGUI, FN3,  FN1,         SP_SPSH, FN2,  KC_LALT \
    ),

    /* qwerty gaming
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  E  ├─────┐                          ┌─────┤  I  ├─────┐
     * ┌─────┬─────┤  W  ├─────┤  R  ├─────┐              ┌─────┤  U  ├─────┤  O  ├─────┬─────┐
     * │ esc │  Q  ├─────┤  D  ├─────┤  T  │              │  Y  ├─────┤  K  ├─────┤  P  │ bsp │
     * ├─────┼─────┤  S  ├─────┤  F  ├─────┤              ├─────┤  J  ├─────┤  L  ├─────┼─────┤
     * │tb/ct│  A  ├─────┤  C  ├─────┤  G  │              │  H  ├─────┤  ,  ├─────┤  ;  │en/ct│
     * ├─────┼─────┤  X  ├─────┤  V  ├─────┤              ├─────┤  M  ├─────┤  .  ├─────┼─────┤
     * │shift│  Z  ├─────┘     └─────┤  B  │              │  N  ├─────┘     └─────┤  /  │ fn3 │
     * └─────┴─────┘        ┌─────┐  └─────┼─────┐  ┌─────┼─────┘  ┌─────┐        └─────┴─────┘
     *                      │ alt │┌─────┐ │ fn1 │  │sp/sh│ ┌─────┐│ gui │
     *                      └─────┘│space││     │    │     ││ fn2 │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_GAME] = LAYOUT( \
    KC_ESC,  KC_Q, KC_W, KC_E,    KC_R,   KC_T,        KC_Y,    KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC, \
    SP_CTTB, KC_A, KC_S, KC_D,    KC_F,   KC_G,        KC_H,    KC_J, KC_K,    KC_L,   KC_SCLN, SP_CTEN, \
    KC_LSFT, KC_Z, KC_X, KC_C,    KC_V,   KC_B,        KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, FN3, \
                         KC_LALT, KC_SPC, FN1,         SP_SPSH, FN2,  KC_LGUI \
    ),

    /* fn1 - symbols
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  #  ├─────┐                          ┌─────┤  *  ├─────┐
     * ┌─────┬─────┤  @  ├─────┤  $  ├─────┐              ┌─────┤  &  ├─────┤  (  ├─────┬─────┐
     * │  ~  │  !  ├─────┤  +  ├─────┤  %  │              │  ^  ├─────┤  -  ├─────┤  )  │ del │
     * ├─────┼─────┤  =  ├─────┤  {  ├─────┤              ├─────┤  }  ├─────┤  _  ├─────┼─────┤
     * │     │     ├─────┤     ├─────┤     │              │     ├─────┤     ├─────┤  \  │     │
     * ├─────┼─────┤     ├─────┤  [  ├─────┤              ├─────┤  ]  ├─────┤     ├─────┼─────┤
     * │     │     ├─────┘     └─────┤     │              │     ├─────┘     └─────┤  |  │     │
     * └─────┴─────┘        ┌─────┐  └─────┼─────┐  ┌─────┼─────┘  ┌─────┐        └─────┴─────┘
     *                      │     │┌─────┐ │▒▒▒▒▒│  │  '  │ ┌─────┐│  "  │
     *                      └─────┘│     ││     │    │     ││  `  │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN1] = LAYOUT( \
    KC_TILD, KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC,        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
    _______, XXXXXXX, KC_EQUAL, KC_PLUS, KC_LCBR, XXXXXXX,        XXXXXXX, KC_RCBR, KC_MINS, KC_UNDS, KC_BSLS, _______, \
    _______, XXXXXXX, XXXXXXX,  XXXXXXX, KC_LBRC, XXXXXXX,        XXXXXXX, KC_RBRC, XXXXXXX, XXXXXXX, KC_PIPE, _______, \
                                _______, _______, _______,        KC_QUOT, KC_GRAVE, KC_DQT \
    ),

    /* fn2 - navigation & functions
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤ F4  ├─────┐                          ┌─────┤ F9  ├─────┐
     * ┌─────┬─────┤ F3  ├─────┤ F5  ├─────┐              ┌─────┤ F8  ├─────┤ F10 ├─────┬─────┐
     * │ F1  │ F2  ├─────┤     ├─────┤ F6  │              │ F7  ├─────┤down ├─────┤ F11 │ F12 │
     * ├─────┼─────┤     ├─────┤     ├─────┤              ├─────┤left ├─────┤ up  ├─────┼─────┤
     * │     │     ├─────┤     ├─────┤     │              │home ├─────┤pgdwn├─────┤right│ end │
     * ├─────┼─────┤     ├─────┤     ├─────┤              ├─────┤     ├─────┤pgup ├─────┼─────┤
     * │     │     ├─────┘     └─────┤     │              │     ├─────┘     └─────┤     │     │
     * └─────┴─────┘        ┌─────┐  └─────┼─────┐  ┌─────┼─────┘  ┌─────┐        └─────┴─────┘
     *                      │     │┌─────┐ │     │  │     │ ┌─────┐│     │
     *                      └─────┘│     ││     │    │     ││▒▒▒▒▒│└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN2] = LAYOUT( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, _______, \
                               _______, _______, _______,        _______, _______, _______ \
    ),

    /* fn3 - numbers & media
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤     ├─────┐                          ┌─────┤  8  ├─────┐
     * ┌─────┬─────┤     ├─────┤     ├─────┐              ┌─────┤  7  ├─────┤  9  ├─────┬─────┐
     * │reset│     ├─────┤     ├─────┤colmk│              │     ├─────┤  5  ├─────┤     │ptscr│
     * ├─────┼─────┤     ├─────┤     ├─────┤              ├─────┤  4  ├─────┤  6  ├─────┼─────┤
     * │     │     ├─────┤     ├─────┤qwert│              │     ├─────┤  2  ├─────┤  .  │     │
     * ├─────┼─────┤     ├─────┤     ├─────┤              ├─────┤  1  ├─────┤  3  ├─────┼─────┤
     * │     │     ├─────┘     └─────┤game │              │     ├─────┘     └─────┤     │     │
     * └─────┴─────┘        ┌─────┐  └─────┼─────┐  ┌─────┼─────┘  ┌─────┐        └─────┴─────┘
     *                      │     │┌─────┐ │     │  │  0  │ ┌─────┐│     │
     *                      └─────┘│▒▒▒▒▒││     │    │     ││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [LY_FN3] = LAYOUT( \
    RESET,   _______, _______, _______, _______, COLMAK,         XXXXXXX, KC_7,    KC_8,   KC_9, XXXXXXX, KC_PSCREEN, \
    _______, _______, _______, _______, _______, QWERTY,         XXXXXXX, KC_4,    KC_5,   KC_6, KC_DOT,  _______, \
    _______, _______, _______, _______, _______, GAMING,         XXXXXXX, KC_1,    KC_2,   KC_3, XXXXXXX, _______, \
                               _______, _______, _______,        KC_0 ,   _______, _______ \
    )
};

// misc ------------------------------------------------------------------------

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void matrix_init_user(void) {
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb()); // turns on the display
    #endif
}

// SSD1306 OLED update loop ----------------------------------------------------

#ifdef SSD1306OLED
    const char *read_default_layer_state(void);
    const char *read_layer_state(void);
    const char *read_logo(void);

    void matrix_scan_user(void) {
       iota_gfx_task();
    }

    void matrix_render_user(struct CharacterMatrix *matrix) {
        if (is_master) {
            matrix_write_ln(matrix, read_default_layer_state());
            matrix_write_ln(matrix, read_layer_state());
        } else {
            matrix_write(matrix, read_logo());
        }
    }

    void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
        if (memcmp(dest->display, source->display, sizeof(dest->display))) {
            memcpy(dest->display, source->display, sizeof(dest->display));
            dest->dirty = true;
        }
    }

    void iota_gfx_task_user(void) {
        struct CharacterMatrix matrix;
        matrix_clear(&matrix);
        matrix_render_user(&matrix);
        matrix_update(&display, &matrix);
    }
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLMAK:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<LY_CLMK);
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<LY_QWER);
            }
            return false;
        case GAMING:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<LY_GAME);
            }
            return false;
        case FN1:
            if (record->event.pressed) {
                layer_on(LY_FN1);
            } else {
                layer_off(LY_FN1);
            }
            return false;
        case FN2:
            if (record->event.pressed) {
                layer_on(LY_FN2);
            } else {
                layer_off(LY_FN2);
            }
            return false;
        case FN3:
            if (record->event.pressed) {
                layer_on(LY_FN3);
            } else {
                layer_off(LY_FN3);
            }
            return false;
        default:
            return true;
    }
}
