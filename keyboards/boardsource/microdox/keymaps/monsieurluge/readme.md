# monsieurluge's Microdox layout

## Build

### Firmware

`bin/qmk compile --keyboard boardsource/microdox --keymap monsieurluge`

or

`sudo util/docker_build.sh boardsource/microdox:monsieurluge`

### Flash

Sometimes the Ubuntu _ModemManager_ service can cause issues. Stop it before flashing the microcontroler.

```
bin/qmk flash --keyboard boardsource/microdox --keymap monsieurluge
```

or

```
sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:boardsource_microdox_monsieurluge.hex
```
