#include "i2c_peripheral.h"

class bh1750fvi : public i2c_peripheral
{
public:
  static const enum {
    H = 0x5C, // 0b1011100
    L = 0x23  // 0b0100011
  } addresses;

  static const enum {
    write = 0,
    read  = 1
  } address_suffix;

  static const enum {
    // Device control
    POWER_OFF = 0b00000000,
    POWER_ON  = 0b00000001,
    RESET     = 0b00000111,
    // Acquisition mode
    CONTINUOUS_H_MODE  = 0b00010000,
    CONTINUOUS_H_MODE2 = 0b00010001,
    CONTINUOUS_L_MODE  = 0b00010011,
    ONE_TIME_H_MODE    = 0b00100000,
    ONE_TIME_H_MODE2   = 0b00100001,
    ONE_TIME_L_MODE    = 0b00100011
  } commands;

  bh1750fvi(uint8_t address, uint16_t acq_mode);
  ~bh1750fvi();

  uint16_t get_data();
  void change_mode(uint16_t mode);

private:
  void send_command(uint16_t cmd);

  uint16_t mode;
}
