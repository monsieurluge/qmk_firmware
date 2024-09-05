# monsieurluge's CRKBD layout

Design goals:

 - increase the accessibility to the main coding symbols
 - reduce the pain to write uppercase letters by moving the shift key to the thumb cluster (temporarily not the case)

# Temporary layers

 - **fn1** symbols
 - **fn2** navigation cluster and media
 - **fn3** numbers and function keys

# Setup

Prerequisites:

 - Docker
 - make

Then, run this command: `sudo make git-submodule`

## on MacOS

Install these packages via _HomeBrew_:

- qmk
- avrdude
- avr-gcc

# Build

## Firmware

`sudo util/docker_build.sh crkbd:monsieurluge`

Or on MacOS:

`qmk compile -kb crkbd -km monsieurluge`

## Flash

Sometimes the Ubuntu _ModemManager_ service can cause issues. Stop it before flashing the microcontroler.

```bash
bin/qmk flash --keyboard crkbd/rev1 --keymap monsieurluge
```

or

```bash
sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:crkbd_rev1_monsieurluge.hex
```

# Flash

## on MacOS

Run the command:

```bash
qmk flash --keyboard crkbd/rev1 --keymap monsieurluge
```

Or use the _QMK Toolbox_.
