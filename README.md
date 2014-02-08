Yamato Sumobot
==============

A [sumo bot](http://en.wikipedia.org/wiki/Robot-sumo) based on the STM32F0 Discovery board.


Hardware
--------

 * [STM32F0 Discovery](http://www.st.com/web/catalog/tools/FM116/SC959/SS1532/PF253215) [datasheet](http://www.st.com/web/en/resource/technical/document/datasheet/DM00039193.pdf)
 * SN754410 H-Bridge Driver [datasheet](http://www.ti.com/lit/ds/symlink/sn754410.pdf)
 * ULN2003 Transistor Array [datasheet](http://www.ti.com/lit/ds/symlink/uln2003a.pdf)
 * 850mAh LiPO battery
 * 5v 3A switching voltage regulator
 * 2 x 5v DC motor and gearbox with wheels
 * 4 x TSAL7400 Infrared 5mm LEDs [datasheet](http://www.taydaelectronics.com/datasheets/A-1544.pdf)
 * 4 x TSOP4838 38kHz Infrared Receiver [datasheet](http://www.taydaelectronics.com/datasheets/A-1551.pdf)
 * 2 x CdS LDR Photoresistor
 * Some sort of chassis, like the [BoboBot](http://www.thingiverse.com/thing:41854)



Software
--------

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


*Note: on my setup, the flash will fail the first time. Press the reset button and run `make load` again. Reset again for the MCU to start running.*


Motors
------

**SN75441ONE**

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


#### Rght Motor

Set [PWM](http://en.wikipedia.org/wiki/Pulse-width_modulation) load on `PB1` to control speed. Digital `HIGH` will be 100% speed.


| PB1 | PB15 | PC7 | MOTOR 2  |
| --- | ---- | --- | -------- |
| 0   | 0    | 0   | stop     |
| 0   | 1    | 1   | stop     |
| 1   | 1    | 0   | forward  |
| 1   | 0    | 1   | backward |
| 0   | 1    | 0   | coast    |
| 0   | 0    | 1   | coast    |