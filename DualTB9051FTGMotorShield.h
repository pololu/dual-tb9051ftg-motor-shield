#pragma once

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || \
    defined(__AVR_ATmega328PB__) || defined (__AVR_ATmega32U4__)
  #define DUALTB9051FTGMOTORSHIELD_TIMER1_AVAILABLE
#endif

#include <Arduino.h>

class DualTB9051FTGMotorShield
{
  public:
    // CONSTRUCTORS
    // Default pin selection.
    DualTB9051FTGMotorShield();
    // User-defined pin selection.
    DualTB9051FTGMotorShield(unsigned char M1EN,
                             unsigned char M1DIR,
                             unsigned char M1PWM,
                             unsigned char M1DIAG,
                             unsigned char M1OCM,
                             unsigned char M2EN,
                             unsigned char M2DIR,
                             unsigned char M2PWM,
                             unsigned char M2DIAG,
                             unsigned char M2OCM);

    // PUBLIC METHODS
    void init(); // Initialize pins and timer1 if applicable.
    void setM1Speed(int speed); // Set speed for M1.
    void setM2Speed(int speed); // Set speed for M2.
    void setSpeeds(int m1Speed, int m2Speed); // Set speed for both M1 and M2.
    unsigned char getM1Fault(); // Get fault reading from M1.
    unsigned char getM2Fault(); // Get fault reading from M2.
    void flipM1(boolean flip); // Flip the direction of the speed for M1.
    void flipM2(boolean flip); // Flip the direction of the speed for M2.
    void enableM1Driver(); // Enable the driver for M1.
    void enableM2Driver(); // Enable the driver for M2.
    void enableDrivers(); // Enables the drivers for both M1 and M2.
    void disableM1Driver(); // Disable the driver for M1.
    void disableM2Driver(); // Disable the driver for M2.
    void disableDrivers(); // Disable the drivers for both M1 and M2.
    unsigned int getM1CurrentMilliamps(); // Get current reading for M1.
    unsigned int getM2CurrentMilliamps(); // Get current reading for M2.

  private:
    unsigned char _M1PWM;
    static const unsigned char _M1PWM_TIMER1_PIN = 9;
    unsigned char _M2PWM;
    static const unsigned char _M2PWM_TIMER1_PIN = 10;
    unsigned char _M1EN;
    unsigned char _M2EN;
    unsigned char _M1DIR;
    unsigned char _M2DIR;
    unsigned char _M1DIAG;
    unsigned char _M2DIAG;
    unsigned char _M1OCM;
    unsigned char _M2OCM;
    boolean _flipM1;
    boolean _flipM2;
};
