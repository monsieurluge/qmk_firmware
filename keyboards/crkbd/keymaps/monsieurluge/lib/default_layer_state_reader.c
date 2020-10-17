#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

#define LS_COLMAK 1
#define LS_GAMING 2

char default_layer_state_str[24];

const char *read_default_layer_state(void) {
    switch (default_layer_state) {
        case LS_COLMAK:
            snprintf(default_layer_state_str, sizeof(default_layer_state_str), "COLEMAK DHm");
            break;
        default:
            snprintf(default_layer_state_str, sizeof(default_layer_state_str), "UNKNOWN (%ld)", default_layer_state);
            break;
    }

    return default_layer_state_str;
}
