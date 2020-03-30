# monsieurluge's CRKBD layout

## Design goals

 - qwerty, colemak dhm and gaming dedicated layouts
 - increase the accessibility to the main coding symbols
 - do not use any of the 4 main fingers to WRITE IN UPPERCASE (use the thumb instead): one tap on the spacebar for a space character, hold for the SHIFT modifier

## Permanent layers

 - qwerty
 - colemak DHm
 - gaming

## Temporary layers

 - symbols
 - numbers and function keys
 - navigation cluster

## Build

### Firmware

`bin/qmk compile --keyboard crkbd/rev1 --keymap monsieurluge`

### Flash

Sometimes the Ubuntu _ModemManager_ service can cause issues. Stop it before flashing the microcontroler.

```
bin/qmk flash --keyboard crkbd/rev1 --keymap monsieurluge
```

or

```
sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:crkbd_rev1_monsieurluge.hex
```
