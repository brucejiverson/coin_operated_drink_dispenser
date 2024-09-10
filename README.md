# coin_operated_drink_dispenser

# Dev notes
https://docs.arduino.cc/learn/electronics/stepper-motors/
- Has good diagrams incl. battery for motor and some code

**Micro controller selection**
Raspberry pi
- a little harder to set up and program
- enables lots of future functionality

Arduino
- Easier to set up. Cheaper. Selected for desired development speed.

**Power Requirements**
Sensors and arduino will be negligible compared to 


**First steps**
- figure out the motor electrical interface, ie driver + power
- find out if I have a sensor and if not get some. Also: how thick are the dubloons?
- systems diagram

  How topower with a 9V batter https://www.instructables.com/Powering-Arduino-with-a-Battery/
  Probably want more power than this due to the LEDs

**LEDs**
  https://howtomechatronics.com/tutorials/arduino/how-to-control-ws2812b-individually-addressable-leds-using-arduino/#h-arduino-and-ws2812b-leds-examples
  I put this power supply into my cart

**Speakers**
From here: https://forum.arduino.cc/t/what-component-can-play-an-audio-message/444846/2
You can either use a small 8Ohm-speaker and a resistor or capacitor, or a piezo speaker.
Short audio messages in low-quality audio can be included in your sketch within a PROGMEM data array and played directly from program flash memory to speaker. Longer sounds can be played from a SD card.
An UNO provides 32 KB of flash memory, let's assume the program is 4 KB in size, then you have 28KB left for sound data.
"speech quality" sound data could be included in 8-bit PCM 4000Hz audio format, this would use 4KB of program size for each second of audo, or 28 KB audio data for seven seconds.
