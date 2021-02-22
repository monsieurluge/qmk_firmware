# monsieurluge's Gherkin layout

## Build

### Firmware

`bin/qmk compile --keyboard 40percentclub/gherkin --keymap monsieurluge`

### Flash

Sometimes the Ubuntu _ModemManager_ service can cause issues. Stop it before flashing the microcontroler.

```
bin/qmk flash --keyboard 40percentclub/gherkin --keymap monsieurluge
```

or

```
sudo avrdude -p atmega32u4 -P /dev/ttyACM0 -c avr109 -U flash:w:40percentclub_gherkin_monsieurluge.hex
```
