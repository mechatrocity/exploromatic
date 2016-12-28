#include "URM37.h"

// NOTE:  Sum=Low 8 bit of the sum of (command + data0 + data1)

urm37::urm37()
{

}

urm37::~urm37()
{

}

uint16_t urm37::get_dist()
{
  // write: 0x22 0x00 0x00 0x22
  // read : 0x22 High(distance) Low(distance) [SUM]
  // NOTE: error response is 0x22 0xFF 0xFF [SUM]
}

uint16_t urm37::get_temp()
{
  // write: 0x11 0x00 0x00 0x11
  // read : 0x11 High(temperature) Low(temperature) [SUM]

  /* NOTE:
  If the temperature is above 0, the first four bits of
  High will be all 0.
  If the temperature is below 0, the first four bits of High
  will be all 1.
  The last 4 bits of High together with the Low bits
  stands for 12bits temperature. The resolution is 0.1.
  When the reading is invalid, it returns
  0x11+0xFF+0xFF+SUM
  */
}


bool urm37::change_mode(control_mode mode)
{

}

bool urm37::change_threshold(uint16_t threshold)
{

}

uint8_t urm37::read_eeprom(uint8_t address)
{
  // write: 0x33 [addr] 0x00 [SUM]
  // read : 0x33 [addr] [data] [SUM]
}

bool urm37::write_eeprom(uint8_t address, uint8_t data)
{
  // write: 0x44 [addr] [data] [SUM]
  // read : 0x44 [addr] [data] [SUM]
}

uint8_t urm37::calc_checksum(uint8_t data[3])
{
  return 0xFF & (data[0]+data[1]+data[2]);
}
