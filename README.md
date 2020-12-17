# Arduino library for the Pololu Dual TB9051FTG Motor Driver Shield

Version: 2.0.0 <br>
Release date: 2019-02-05 <br>
[www.pololu.com](https://www.pololu.com/)

## Summary

This is a library for an
[Arduino-compatible controller](https://www.pololu.com/arduino) that
interfaces with the Pololu
[Dual TB9051FTG Motor Driver Shield](https://www.pololu.com/catalog/product/2520). It
makes it simple to drive two brushed, DC motors.

## Getting started

### Hardware

The
[Dual TB9051FTG Motor Driver Shield](https://www.pololu.com/catalog/product/2520)
can be purchased on Pololu's website. Before continuing, careful
reading of the product page as well as the
[motor shield user's guide](https://www.pololu.com/docs/0J78) is
recommended.

### Software

If you are using version 1.6.2 or later of the
[Arduino software (IDE)](https://www.arduino.cc/en/Main/Software), you can use
the Library Manager to install this library:

1. In the Arduino IDE, open the "Sketch" menu, select "Include Library", then
   "Manage Libraries...".
2. Search for "DualTB9051FTGMotorShield".
3. Click the DualTB9051FTGMotorShield entry in the list.
4. Click "Install".

If this does not work, you can manually install the library:

1. Download the
   [latest release archive from GitHub](https://github.com/pololu/dual-tb9051ftg-motor-shield/releases)
   and decompress it.
2. Rename the folder "dual-tb9051ftg-motor-shield-xxxx" to "DualTB9051FTGMotorShield".
3. Drag the "DualTB9051FTGMotorShield" folder into the "libraries" directory inside your
   Arduino sketchbook directory. You can view your sketchbook location by
   opening the "File" menu and selecting "Preferences" in the Arduino IDE. If
   there is not already a "libraries" folder in that location, you should make
   the folder yourself.
4. After installing the library, restart the Arduino IDE.

## Example program

An example sketch is available that shows how to use the library.  You
can access it from the Arduino IDE by opening the "File" menu,
selecting "Examples", and then selecting "DualTB9051FTGMotorShield".  If
you cannot find these examples, the library was probably installed
incorrectly and you should retry the installation instructions above.


### Demo

The demo ramps motor 1 from stopped to full speed forward, ramps down
to full speed reverse, and back to stopped. Then, it does the same
with the other motor. Both motor's current readings are sent over
serial and can be seen with the serial monitor. If a fault is
detected, a message is sent over serial.

## Documentation

- `DualTB9051FTGMotorShield()` <br> Default constructor, selects the
  default pins as connected by the motor shield.
- `DualTB9051FTGMotorShield(unsigned char M1EN, unsigned char M1DIR,
  unsigned char M1PWM, unsigned char M1DIAG, unsigned char M1OCM,
  unsigned char M2EN, unsigned char M2DIR, unsigned char M2PWM,
  unsigned char M2DIAG, unsigned char M2OCM)` <br>
  Alternate constructor for shield connections remapped by user. If M1PWM
  and M2PWM are remapped, it will try to use analogWrite instead of timer1.
- `void init()` <br> Initialize pinModes and timer1 if applicable.
- `void setM1Speed(int speed)` <br> Set speed and direction for
  motor 1. Speed should be between -400 and 400. 400 corresponds to
  motor current flowing from M1A to M1B. -400 corresponds to motor
  current flowing from M1B to M1A.
- `void setM2Speed(int speed)` <br> Set speed and direction for
  motor 2. Speed should be between -400 and 400. 400 corresponds to
  motor current flowing from M2A to M2B. -400 corresponds to motor
  current flowing from M2B to M2A.
- `void setSpeeds(int m1Speed, int m2Speed)` <br> Set speed and
  direction for motor 1 and 2.
- `unsigned char getM1Fault()` <br> Returns 1 if there is a fault on motor
  driver 1, 0 if no fault.
- `unsigned char getM2Fault()` <br> Returns 1 if there is a fault on motor
  driver 2, 0 if no fault.
- `void flipM1(bool flip)` <br> Flip the direction meaning of the speed
  passed to the setSpeeds function for motor 1. The default direction
  corresponds to flipM1(false) having been called.
- `void flipM2(bool flip)` <br> Flip the direction meaning of the speed
  passed to the setSpeeds function for motor 2. The default direction
  corresponds to flipM2(false) having been called.
- `void enableM1Driver()` <br> Enables the driver for motor 1.
- `void enableM2Driver()` <br> Enables the driver for motor 2.
- `void enableDrivers()` <br> Enables the drivers for motor 1 and
  motor 2.
- `void disableM1Driver()` <br> Disables the driver for motor 1.
- `void disableM2Driver()` <br> Disables the driver for motor 2.
- `void disableDrivers()` <br> Disables the drivers for motor 1 and
  motor 2.
- `unsigned int getM1CurrentMilliamps()` <br> Returns current reading
  from motor 1 in milliamps.
- `unsigned int getM2CurrentMilliamps()` <br> Returns current reading
  from motor 2 in milliamps.

## Version history

* 2.0.0 (2019-02-05): Fixed the way the sign of the `speed` value sets the motor
  direction (positive numbers actually produce motor current from A to B and
  light the green LED now, like on our other motor shields). Note that this
  change will reverse the direction of any motors previously controlled using an
  older version of this library.
* 1.0.0 (2018-07-16): Original release.
