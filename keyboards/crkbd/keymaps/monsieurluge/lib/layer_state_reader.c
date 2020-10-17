#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

#define L_NONE 0
#define L_GAME 2
#define L_FN1  4
#define L_FN1B 6
#define L_FN2  8
#define L_FN2B 10
#define L_FN3  16
#define L_FN3B 18

char layer_state_str[24];

const char *read_layer_state(void) {
    switch (layer_state) {
        case L_NONE:
            snprintf(layer_state_str, sizeof(layer_state_str), " ");
            break;
        case L_GAME:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> gaming");
            break;
        case L_FN1:
        case L_FN1B:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> symbols");
            break;
        case L_FN2:
        case L_FN2B:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> navigation");
            break;
        case L_FN3:
        case L_FN3B:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> numbers and media");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> unknown (%ld)", layer_state);
            break;
    }

    return layer_state_str;
}
