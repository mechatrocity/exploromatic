#include "uart_gps.h"

class LS20031 : public _GPS
{
public:
  LS20031();
  ~LS20031();

  void  LS20031_RMC   ();
  void  LS20031_reset ();
  void  warmstart_LLA(uint8_t, uint8_t, uint8_t);
};
