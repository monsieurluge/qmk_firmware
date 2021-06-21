# monsieurluge's Planck layout

## Design goals

 - increase the accessibility to the main coding symbols
 - do not use any of the 4 main fingers to WRITE IN UPPERCASE, use the thumb instead

## Permanent layers

 - colemak DHm

## Temporary layers

 - symbols
 - numbers and function keys
 - navigation cluster and media

## Setup

 - install Docker, make, avrdude
 - run this command: `sudo make git-submodule`

## Build

### Firmware

`sudo util/docker_build.sh planck/rev4:monsieurluge`

### Flash

Sometimes the Ubuntu _ModemManager_ service can cause issues. Stop it before flashing the microcontroler.

```
bin/qmk flash --keyboard planck/rev1 --keymap monsieurluge
```
Coucou les gens
