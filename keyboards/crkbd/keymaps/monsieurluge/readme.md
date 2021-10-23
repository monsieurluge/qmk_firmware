# monsieurluge's CRKBD layout

Design goals

 - colemak dhm base layout
 - gaming layer mask
 - increase the accessibility to the main coding symbols
 - move the shift key to the thumb cluster in order to avoid moving the pinkies to write in uppercase -> less pain

# Temporary layers

 - symbols
 - numbers and function keys
 - navigation cluster and media

# Setup

Prerequisites:

 - Docker
 - make
 - avrdude

Then, run this command: `sudo make git-submodule`

# Build

## Firmware

`sudo util/docker_build.sh crkbd:monsieurluge`

## Flash

Sometimes the Ubuntu _ModemManager_ service can cause issues. Stop it before flashing the microcontroler.

```bash
bin/qmk flash --keyboard crkbd/rev1 --keymap monsieurluge
```

or

```bash
sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:crkbd_rev1_monsieurluge.hex
```
