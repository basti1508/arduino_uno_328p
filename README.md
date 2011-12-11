This is a playground of the development of examples targeted at the [Arduino Uno (ATmega328P)] (http://www.arduino.cc/en/Main/arduinoBoardUno)  
to be used with the AVR-GCC toolchain.

## Sources

* __blink_led_hw__ shows an example in the veins of __blink_led_sw__ to let the User LED  
  on the Arduino Uno blink once per second. Although using a timer-based delay which is  
  accomplished via an compare match event of __TIMER1__.

* __blink_led_sw__ shows an example to let the User LED on the Arduino Uno blink once per  
  second. The needed delay is accomplished via a software delay provided by `_delay_ms()`  
  function.

* __hw_uart__ shows an interrupt controlled UART example using circular buffers as described  
  by Atmel Application Note [AVR306: Using the AVR UART in C] (http://www.atmel.com/atmel/acrobat/doc1451.pdf)

* __sw_uart__ shows an example of polled UART for basic input and output operation.  

* __sw_i2c__ implements an example application of Software TWI (I2C) Master Mode using a  
  Dallas Maxim __DS1631__ temperature sensor as slave device. The measured temperature  
  is sent to UART. For details regarding the DS1631 see [DS1631 Datasheet] (http://datasheets.maxim-ic.com/en/ds/DS1631-DS1731.pdf)  
  See __DS1631 Temperature Sensor__ under Schematics on how to hookup the DS1631 to  
  the Arduino.

## Schematics

### Board

<pre>
,-----------------------------------------------------------------------.
|                    GND                                         TX RX  |
|                 [ ][ ][ ][ ][ ][ ][ ][ ]     [ ][ ][ ][ ][ ][ ][ ][ ] |
|                AREF   PB5            PB0     PD7                  PD0 |
|                                                                       |
|                                                                       |
|                                                                       |
|                                                                       |
|                                                                       |
|                                                                       |
|                                                                       |
|                                                                       |
|                                                                       |
|                                                              +-----+  |
|                                                              |[] []|  |
|                                                              |[] []|  |
|                                                              |[] []|  |
|                                                              +-ISP-+  |
|                                                                       |
|                             GND GND                          SDA SCL  |
|                 [ ] [ ] [ ] [ ] [ ] [ ]          [ ] [ ] [ ] [ ] [ ]  |
|                 RST 3V3 5V          Vin          PC0             PC5  |
`-----------------------------------------------------------------------'
</pre>

### DS1631 Temperature Sensor
<pre>
   .--------------=4k7=-----------.
   | .------------=4k7=---------. |
   | |                          | |
   | |    ,____  ____.          | |
   | '-1--|SDA `' VCC|--8----------- 3V3
   '---2--|SCL     A0|--7----.
       3--|Tout    A1|--6----|
       4--|GND     A2|--5----|
          `----------'       |
             DS1631         GND

(Device Address is set to 0x90, see Control Byte)
._____________________________________.
| 1 | 0 | 0 | 1 | A2 | A1 | A0 | R/_W |
'-------------------------------------'
</pre>

### Serial
A simple and cheap way to hookup the serial of the Arduino Uno Board is to use a USB to Serial  
cable like the Nokia CA-42. This cable is based on Prolific's PL-2303 chip and already  
provides a TTL converter.

<pre>
GND TX  RX
[ ] [ ] [ ]
 |   |   |
 |   |   |
 |   |   |                    ,------------.
 |   |   +----------[whi]----|             |
 |   +--------------[grn]----|             |
 +------------------[blu]----|             |
                             `-------------'
                               Nokia CA-42
</pre>
