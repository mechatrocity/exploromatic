#include "BH1750FVI.h"


<<<<<<< HEAD
bh1750fvi::bh1750fvi(uint8_t addr, uint8_t acq_mode)
  : i2c_peripheral(addr), acq_mode_(acq_mode)
{
  change_mode(acq_mode_);
=======
bh1750fvi::bh1750fvi(uint8_t addr, uint16_t acq_mode)
  : i2c_peripheral(address), mode(acq_mode)
{
  change_mode(mode);
>>>>>>> ceb0bf925644814d620a53c3880457945f245f05
}

bh1750fvi::~bh1750fvi()
{
<<<<<<< HEAD
=======
  send_command(RESET);
>>>>>>> ceb0bf925644814d620a53c3880457945f245f05
  send_command(POWER_OFF);
}

uint16_t bh1750fvi::get_data()
{
<<<<<<< HEAD
  uint16_t response = 0x0000;
  switch(acq_mode_)
  {
=======
  switch(mode)
  {
    // For continuous mode, we just need to read the latest value
    // from the device
    case CONTINUOUS_H_MODE:
    case CONTINUOUS_H_MODE2:
    case CONTINUOUS_L_MODE:
    {
      // TODO
      break;
    }

>>>>>>> ceb0bf925644814d620a53c3880457945f245f05
    // For one-shot mode, got to turn device on and request data
    case ONE_TIME_H_MODE:
    case ONE_TIME_H_MODE2:
    case ONE_TIME_L_MODE:
    {
      send_command(POWER_ON);
<<<<<<< HEAD
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
  send_command(POWER_OFF);

  acq_mode_ = acq_mode;
  switch(acq_mode_)
=======
      send_command(mode);
      // TODO: wait...
      // TODO: read in I2C data
      break;
    }

    default:
    {
      // TODO: throw
      break;
    }
  }
}

void bh1750fvi::change_mode(uint16_t acq_mode)
{
  mode = acq_mode;

  send_command(POWER_OFF);
  switch(mode)
>>>>>>> ceb0bf925644814d620a53c3880457945f245f05
  {
    case CONTINUOUS_H_MODE:
    case CONTINUOUS_H_MODE2:
    case CONTINUOUS_L_MODE:
    {
      send_command(POWER_ON);
      // TODO: send command to start continuous mode
      break;
    }
<<<<<<< HEAD
=======

>>>>>>> ceb0bf925644814d620a53c3880457945f245f05
    case ONE_TIME_H_MODE:
    case ONE_TIME_H_MODE2:
    case ONE_TIME_L_MODE:
    {
      break;
    }
<<<<<<< HEAD
=======

>>>>>>> ceb0bf925644814d620a53c3880457945f245f05
    default:
    {
      // TODO: throw
      break;
    }
  }
}

<<<<<<< HEAD
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
=======
void bh1750fvi::send_command()
{
  // FIXME: is this necessary if we inherit from i2c_peripheral ?
  //        Remember, need to suffix address with '0' for write commands
>>>>>>> ceb0bf925644814d620a53c3880457945f245f05
}
