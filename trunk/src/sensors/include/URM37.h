#include "uart_peripheral.h"

class urm37 : public uart_peripheral
{
public:
  enum class control_mode : std::uint8_t
  {
    autonomous  = 0xAA,
    pwm_passive = 0xBB,
  };

  enum class measurment_type : std::uint8_t
  {
    temperature = 0x11,
    distance    = 0x22,
  };

  explicit urm37(char* device);
  virtual ~urm37();

  uint16_t get_dist() const;
  uint16_t get_temp() const;

  bool change_mode(control_mode mode);
  bool change_threshold(uint16_t threshold) const;

private:
  uint8_t  calc_checksum(uint8_t data[3]) const;
  uint8_t  calc_checksum(measurment_type type, uint16_t data) const;
  uint8_t  read_eeprom(uint8_t address) const;
  uint16_t read_measurment(measurment_type type) const;
  bool     write_eeprom(uint8_t address, uint8_t data);

  control_mode mode_;
};
