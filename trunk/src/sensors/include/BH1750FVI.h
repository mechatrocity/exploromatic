#include "i2c_peripheral.h"

class bh1750fvi : public i2c_peripheral
{
public:
  static const enum
  { // 7-bit I2C addresses
    H = 0x5C, // 0b1011100
    L = 0x23  // 0b0100011
  } _addresses;
  static const enum
  {
    write = 0,
    read  = 1
  } _addrss_suffix;
  static const enum
  {
    POWER_OFF = 0b00000000,
    POWER_ON  = 0b00000001,
    RESET     = 0b00000111
  } _commands;
  static const enum
  {
    CONTINUOUS_H_MODE  = 0b00010000,
    CONTINUOUS_H_MODE2 = 0b00010001,
    CONTINUOUS_L_MODE  = 0b00010011,
    ONE_TIME_H_MODE    = 0b00100000,
    ONE_TIME_H_MODE2   = 0b00100001,
    ONE_TIME_L_MODE    = 0b00100011
  } _modes;

  bh1750fvi(uint8_t address, uint8_t acq_mode = CONTINUOUS_H_MODE2);
  ~bh1750fvi();
  void      change_mode(uint8_t acq_mode);

  uint16_t  get_data();

private:
  void send_command(uint8_t cmd);

  uint8_t acq_mode_;
};
