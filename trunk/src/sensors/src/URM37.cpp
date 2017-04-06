#include "URM37.h"

static constexpr uint16_t ERROR = 0xFFFF;


urm37::urm37(char* device)
  : uart_peripheral(device), mode_()
{
}


urm37::~urm37()
{
  // TODO: anything to 'properly' turn it off?  Change mode perhaps?
}


uint16_t urm37::read_measurment(measurment_type type) const
{
  // uart_peripheral::write: type 0x00 0x00 type

  // uart_peripheral::read : type [HIGH] [LOW] [SUM]

  // Sanity check sum
  //calc_checksum(DATA);
}


uint16_t urm37::get_dist() const
{
  // uart_peripheral::read : 0x22 High(distance) Low(distance) [SUM]
  // NOTE: error response is 0x22 0xFF 0xFF [SUM]
  return read_measurment(measurment_type::distance);
}


int16_t urm37::get_temp() const
{
  // uart_peripheral::read : 0x11 High(temperature) Low(temperature) [SUM]
  const uint16_t data = read_measurment(measurment_type::temperature);
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
  int16_t response;
  if (ERROR == data)
  {
    response = ERROR;
  }
  else
  {
    // Determine sign
    if (0xF000 & data)  response = -1;
    else                response = 1;
    // Get data
    response *= (data & 0x0FFFF);
  }
  return response;
}


bool urm37::change_mode(control_mode mode)
{
}


bool urm37::change_threshold(uint16_t threshold) const
{
}


uint8_t urm37::read_eeprom(uint8_t address) const
{
  // uart_peripheral::write: 0x33 [addr] 0x00 [SUM]
  // uart_peripheral::read : 0x33 [addr] [data] [SUM]
}


bool urm37::write_eeprom(uint8_t address, uint8_t data)
{
  // uart_peripheral::write: 0x44 [addr] [data] [SUM]
  // uart_peripheral::read : 0x44 [addr] [data] [SUM]
}


uint8_t urm37::calc_checksum(uint8_t data[3]) const
{
  // Sum=Low 8 bit of the sum of (type + data0 + data1)
  return 0xFF & (data[0]+data[1]+data[2]);
}


uint8_t urm37::calc_checksum(measurment_type type, uint16_t data) const
{
  // Sum=Low 8 bit of the sum of (type + data0 + data1)
  // FIXME
}
