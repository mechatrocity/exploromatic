#include "BH1750FVI.h"


bh1750fvi::bh1750fvi(uint8_t addr, uint8_t acq_mode)
  : i2c_peripheral(addr), acq_mode_(acq_mode)
{
  change_mode(acq_mode_);
}

bh1750fvi::~bh1750fvi()
{
  send_command(POWER_OFF);
}

uint16_t bh1750fvi::get_data()
{
  uint16_t response = 0x0000;
  switch(acq_mode_)
  {
    // For one-shot mode, got to turn device on and request data
    case ONE_TIME_H_MODE:
    case ONE_TIME_H_MODE2:
    case ONE_TIME_L_MODE:
    {
      send_command(POWER_ON);
      // DON'T BREAK, 'get' functionality continued below
    }
    // For continuous mode, ping device to read the latest value
    case CONTINUOUS_H_MODE:
    case CONTINUOUS_H_MODE2:
    case CONTINUOUS_L_MODE:
    {
      // FIXME
      break;
    }
    default:
    {
      // TODO
      break;
    }
  }
  return response;
}

void bh1750fvi::change_mode(uint8_t acq_mode)
{
  //send_command(POWER_OFF);
  acq_mode_ = acq_mode;

  // TODO: send command to start continuous mode?
  switch(acq_mode_)
  {
    case CONTINUOUS_H_MODE:
    case CONTINUOUS_H_MODE2:
    case CONTINUOUS_L_MODE:
    {
      send_command(POWER_ON);
      break;
    }
    default:
    {
      // TODO: throw
      break;
    }
  }
}

void bh1750fvi::send_command(uint8_t cmd)
{
  // FIXME
}

// TODO: What 'read' functionality is there other than get_data() ??
void read_command(uint8_t acq_mode)
{
  uint16_t message = 0x0000;
  // FIXME: address should be handled by I2C peripheral, not this class
  message = (read >> 8) | (acq_mode);
}
