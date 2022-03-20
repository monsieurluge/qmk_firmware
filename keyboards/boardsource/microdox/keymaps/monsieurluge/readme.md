# monsieurluge's Microdox layout

Design goals:

 - only one half
 - qwerty-like gaming layout
 - shortcuts layer

## Build

### Firmware

`bin/qmk compile --keyboard boardsource/microdox --keymap monsieurluge`

or

`sudo util/docker_build.sh boardsource/microdox:monsieurluge`

### Flash

```
bin/qmk flash --keyboard boardsource/microdox --keymap monsieurluge
```

or

```
sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:boardsource_microdox_monsieurluge.hex
```
