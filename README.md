Yamato Sumobot
==============

A [sumo bot](http://en.wikipedia.org/wiki/Robot-sumo) based on the STM32F0 Discovery board.


## Hardware List

 * [STM32F0 Discovery](http://www.st.com/web/catalog/tools/FM116/SC959/SS1532/PF253215) [datasheet](http://www.st.com/web/en/resource/technical/document/datasheet/DM00039193.pdf)
 * SN754410 H-Bridge Driver [datasheet](http://www.ti.com/lit/ds/symlink/sn754410.pdf)
 * ULN2003 Transistor Array [datasheet](http://www.ti.com/lit/ds/symlink/uln2003a.pdf)
 * 850mAh LiPO battery
 * 5v 3A switching voltage regulator (RC UBEC)
 * 2 x 5v DC motor and gearbox with wheels
 * 4 x TSAL7400 Infrared 5mm LEDs [datasheet](http://www.taydaelectronics.com/datasheets/A-1544.pdf)
 * 4 x TSOP4838 38kHz Infrared Receiver [datasheet](http://www.taydaelectronics.com/datasheets/A-1551.pdf)
 * 2 x CdS LDR Photoresistor
 * Some sort of chassis, like the [BoboBot](http://www.thingiverse.com/thing:41854)

### Pinout

#### STM32F0DISCOVERY

| Map         | Pad  |     | Pad   | Map            |
| ----------- | ---- | --- | ----- | -------------- |
| 3v          | 3v   |     | 5v    | UBEC           |
|             | GND  |     | GND   | UBEC           |
|             | VBAT |     | PB9   | IR LED 7       |
| IR RX 3     | PC13 |     | PB8   | IR LED 6       |
| IR RX 4     | PC14 |     | VDD   |                |
|             | PC15 |     | BOOT0 |                |
|             | PF0  |     | PB7   | IR LED 5       |
|             | PF1  |     | PB6   | IR LED 4       |
|             | GND  |     | PB5   | IR LED 3       |
|             | NRST |     | PB4   | IR LED 2       |
| Photocell 1 | PC0  |     | PB3   | IR LED 1       |
| Photocell 2 | PC1  |     | PD2   |                |
|             | PC2  |     | PC12  | IR RX 2        |
|             | PC3  |     | PC11  | IR RX 1        |
|             | PA0  |     | PC10  |                |
|             | PA1  |     | PA15  |                |
|             | PA2  |     | PA14  |                |
|             | PA3  |     | PF7   |                |
|             | PF4  |     | PF6   |                |
|             | PF5  |     | PA13  |                |
|             | PA4  |     | PA12  |                |
|             | PA5  |     | PA11  | Sonar trigger  |
|             | PA6  |     | PA10  | Serial RX      |
|             | PA7  |     | PA9   | Serial TX      |
|             | PC4  |     | PA8   | Sonar echo     |
|             | PC5  |     | PC9   | Onboard LED G  |
| Motor A EN  | PB0  |     | PC8   | Onboard LED B  |
| Motor B EN  | PB1  |     | PC7   | Motor B1       |
| Motor A1    | PB2  |     | PC6   | Motor A2       |
|             | PB10 |     | PB15  | Motor B2       |
|             | PB11 |     | PB14  |                |
|             | PB12 |     | PB13  |                |
|             | GND  |     | GND   |                |




## Software

 * [ChibiOS](http://www.chibios.org/dokuwiki/doku.php) Real-time operating system
 * [STLINK](https://github.com/texane/stlink)


I use OS X. It should be almost identical to Linux.


### ChibiOS

```bash
cd ~/OpenSource 
git clone git@github.com:mabl/ChibiOS.git
```


### STLINK

```bash
cd ~/OpenSource
sudo port install libusb  # sudo apt-get install libusb
git clone https://github.com/texane/stlink.git
cd stlink
./autogen.sh
./configure
LIBRARY_PATH=/opt/local/lib C_INCLUDE_PATH=/opt/local/include make CONFIG_USE_LIBSG=0  
sudo make install
```


### Yamato

```bash
cd ~/OpenSource
git clone git@github.com:mattwilliamson/yamato.git
cd yamato
make
make load  # Installs onto Discovery board
```

```bash
make debug
(gdb) target remote localhost:4242
(gdb) load
(gdb) continue
...
```


*Note: on my setup, the flash will fail the first time. Press the reset button and run `make load` again. Reset again for the MCU to start running.*


## Motors

**SN75441ONE**

#### Quad-half h-bridge driver

           .----------. .----------.
           |          |_|          |
           |                       | 
    PB0   =| 1,2EN   1  16   VCC1  |=  5V
           |                       |
    PB2   =| 1A      2  15   4A    |=  PC7
           |                       |
    M1A   =| 1Y      3  14   4Y    |=  M2A
           |                       |
    GND   =| GND     4  13   GND   |=  GND
           |                       |
    GND   =| GND     5  12   GND   |=  GND
           |                       |
    M1B   =| 2Y      6  11   3Y    |=  M2B
           |                       |
    PC6   =| 2A      7  10   3A    |=  PB15
           |                       |
    5V    =| VCC2    8  9    3,4EN |=  PB1
           |                       | 
           '-----------------------'

`M1A` and `M1B` are leads to the left motor.
`M2A` and `M2B` are leads to the right motor.


#### Left Motor

Set [PWM](http://en.wikipedia.org/wiki/Pulse-width_modulation) load on `PB0` to control speed. Digital `HIGH` will be 100% speed.


| PB0 | PB2  | PC6 | MOTOR 1  |
| --- | ---- | --- | -------- |
| 0   | 0    | 0   | stop     |
| 0   | 1    | 1   | stop     |
| 1   | 1    | 0   | forward  |
| 1   | 0    | 1   | backward |
| 0   | 1    | 0   | coast    |
| 0   | 0    | 1   | coast    |


#### Right Motor

Set [PWM](http://en.wikipedia.org/wiki/Pulse-width_modulation) load on `PB1` to control speed. Digital `HIGH` will be 100% speed.


| PB1 | PB15 | PC7 | MOTOR 2  |
| --- | ---- | --- | -------- |
| 0   | 0    | 0   | stop     |
| 0   | 1    | 1   | stop     |
| 1   | 1    | 0   | forward  |
| 1   | 0    | 1   | backward |
| 0   | 1    | 0   | coast    |
| 0   | 0    | 1   | coast    |



## Sonar

I'm using the `SRF-05` ultrasonic rangefinder. The protocol is as follows:

1. Write the `trig` pin for a minimum of 10 microseconds
1. Write the `trig` pin low
1. The `echo` pin changes to high when it starts measuring
1. The `echo` pin goes low when it stops measuring
1. Divide the duration the `echo` pin was high in microseconds by **58** to get the range in centimeters

Yamato uses ChibiOS's [ICU Driver](http://chibios.sourceforge.net/html/group___i_c_u.html) on `TIM1` to measure the pulse width.

`PA11` is mapped to `trig`

`PA8` is mapped to `echo`


## IR Proximity Detection

IR Proximity detection is pretty simple. Blink an IR LED at 38kHz and a 38kHz IR receiver's output pin will go low. Combining direction of the LED and the receiver allows us to get better accuracy of where the detected object is. 

Consider this simplified example. 

 * Two receivers and one LED
 * Receiver 1 is pointed at -45 degrees
 * Receiver 2 is pointed at 45 degrees
 * IR LED is pointed at 0 degrees
 * Only receiver 1 goes low 

The object detected is probably somewhere closer to -22.5 degrees, than 0 degrees, since we average the direction of the LED and the receiver. We can elaborate further by taking into account that the receiver can detect close to 180 degrees and the spreadof the IR beam, when enclosed with an LED holder is about 22 degrees.


### Driving LEDs

The IR LEDs can use a large amount of current. More than the GPIOs can provide. We can use an `ULN2003` darlington transistor array to drive them straight from the UBEC switching power supply. 


**ULN2003A**

#### Darlington Transistor Array

           .----------. .----------.
           |          |_|          |
           |                       | 
    PC0   =| 1B      1  16   1C    |=  IR LED 1 GND
           |                       |
    PC1   =| 2B      2  15   2C    |=  IR LED 2 GND
           |                       |
    PC2   =| 3B      3  14   3C    |=  IR LED 3 GND
           |                       |
    PC3   =| 4B      4  13   4C    |=  IR LED 4 GND
           |                       |
    PC4   =| 5B      5  12   5C    |=  IR LED 5 GND
           |                       |
    PC5   =| 6B      6  11   6C    |=  IR LED 6 GND
           |                       |
    PC8   =| 7B      7  10   7C    |=  IR LED 7 GND
           |                       |
    GND   =| GND     8  9    8C    |=  N/C
           |                       | 
           '-----------------------'



## Line Detection

To detect the white line around the outside of the ring, two CdS [Photoresistor](http://en.wikipedia.org/wiki/Photoresistor) cells are used. The voltage across the cells are read using the [ADC](http://en.wikipedia.org/wiki/Analog-to-digital_converter)1 peripheral. a 10k ohm pull-down resistor is connected to the IO pad and `GND` to even out the reading range. 

A yellow 5mm LED with a 330 ohm resistor inline is used to illuminate the area the Photoresistors are pointed at to reduce the effect of ambient light changes. The cell seems to perform best when as close to the surface as possible.

                            
                                            5v   / \
                                                  |
                                  CdS             |
                                                  |
    PC0 -----------------+--------([])------------' 
                         |
                         Z
                         Z   330 ohm
                         Z
                         |
                       _____
                        ---    GND
                         '




### Analog reading ranges

| Color | Low   | High |
| ----- | ----- | ---- |
| White | 640   | 1500 |
| Black | 550   | 640  |


