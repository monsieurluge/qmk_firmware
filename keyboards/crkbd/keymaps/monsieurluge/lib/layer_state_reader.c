#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

#define L_NONE 0
#define L_FN1  8
#define L_FN2  16
#define L_FN3  32

char layer_state_str[24];

const char *read_layer_state(void) {
    switch (layer_state) {
        case L_NONE:
            snprintf(layer_state_str, sizeof(layer_state_str), " ");
            break;
        case L_FN1:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> symbols");
            break;
        case L_FN2:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> nav. cluster");
            break;
        case L_FN3:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> numbers");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> unknown (%ld)", layer_state);
            break;
    }

    return layer_state_str;
}
