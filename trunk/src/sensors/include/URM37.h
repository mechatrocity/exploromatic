#include "uart_peripheral.h"

class urm37 : public uart_peripheral
{
public:
  typedef enum control_mode
  {
    autonomous  = 0xAA,
    pwm_passive = 0xBB
  };

  urm37(); // TODO: specify serial port
  ~urm37();

  uint16_t get_dist();
  uint16_t get_temp();

  bool change_mode(control_mode mode);
  bool change_threshold(uint16_t threshold);

  uint8_t read_eeprom(uint8_t address);
  bool write_eeprom(uint8_t address, uint8_t data);

private:
  uint8_t calc_checksum(uint8_t data[3]);
};
