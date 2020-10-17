# monsieurluge's CRKBD layout

## Design goals

 - colemak dhm and gaming dedicated layouts
 - increase the accessibility to the main coding symbols
 - do not use any of the 4 main fingers to WRITE IN UPPERCASE, use the thumb instead

## Permanent layers

 - colemak DHm
 - gaming "layer mask"

## Temporary layers

 - symbols
 - numbers and function keys
 - navigation cluster and media

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
