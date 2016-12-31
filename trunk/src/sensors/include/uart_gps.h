#ifndef GPS_H_
#define GPS_H_


typedef struct
{
  uint32_t time; 		  //max value = 235959000
  uint16_t speed;
  uint16_t course;	  //max value = 35999   **NOTE, comes in 4 OR 5 digits...
  uint32_t latitude;
  uint32_t longitude;
  //uint16_t pos_fix;
  //uint16_t sats_used;
  //uint16_t HDOP;
  //uint16_t altitude;
}_GPS_package;


class _GPS
{
public:
  typedef enum {GGA = 0, GLL, GSA, GSV, RMC, VTG, ALL} NMEA_types;
  typedef enum {time = 0, speed, course, latitude, longitude, pos_fix, sats_used, HDOP, altitude} data_types;

  _GPS(void);
  ~_GPS(void){}

  void          parse         (void);
  unsigned long get           (data_types);
  void          set_param     (long, byte, boolean, byte);
  void          request       (NMEA_types, byte, byte, boolean);
  void          calc_checksum (char *);
  void          send          (char *);

inline void send (char *ptr, byte length)
{
  for(int i = 0; i < length; ++i, ++ptr)
  {
    write(*ptr);
  }
}
inline   void  query        (NMEA_types x)                     {request(x,1,0,false);}
inline   void  stop_feed    (NMEA_types x)                     {request(x,0,0,false);}
inline   void  start_feed   (NMEA_types x, byte y, boolean z)  {request(x,0,y,z);    }

private:
  inline void    send         (void)  {send(buffer_out, 25);	  }
  inline void    calc_checksum(void)  {calc_checksum(buffer_out);}

  char          buffer_out[25], *pbuffer_out;
};

#endif /* GPS_H_ */
