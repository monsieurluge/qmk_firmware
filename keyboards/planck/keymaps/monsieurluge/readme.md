# monsieurluge's Planck layout

# Design goals

 - increase the accessibility to the main coding symbols
 - reduce the pain to write uppercase letters by moving the shift key to the thumb cluster

# Permanent layers

 - colemak DHm

# Temporary layers

 - **fn1** symbols
 - **fn2** navigation cluster and media
 - **fn3** numbers and function keys

# Setup

Prerequisites:

 - Docker
 - make
 - avrdude

Then, run this command: `sudo make git-submodule`

Check the "newbs getting started" document to setup the qmk environment.

# Build

## Firmware

```bash
sudo util/docker_build.sh planck/rev4:monsieurluge
```

## Flash

```bash
qmk flash --keyboard planck/rev4 --keymap monsieurluge
```
