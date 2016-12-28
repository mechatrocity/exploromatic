#include "LS20031.h"


LS20031::LS20031()
{
}


LS20031::~LS20031()
{
}


void LS20031::LS20031_RMC (void)
{
	//char message[30]  = {'$','P','S','R','F','1','0','0',',','1',','};
	char message[] = {"$PMTK314,0,1,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1*00"};

	calc_checksum(message);
	send(message);
}


void LS20031::LS20031_reset (void)
{
	//char message[30]  = {'$','P','S','R','F','1','0','0',',','1',','};
	char message[] = {"$PMTK314,-1*04"};

	//calc_checksum(message);	//is there a need?
	send(message);
}


//$PSRF104,<Lat>,<Lon>,<Alt>,<ClkOffset>,<TimeOfWeek>,<WeekNo>,<ChannelCount>,<ResetCfg>*CKSUM<CR><LF>
void LS20031::warmstart_LLA(uint8_t hour, uint8_t minute, uint8_t week)
{//						  1   2   3   4   5   6   7   8   9   10  11
	char message[69]  = {'$','P','S','R','F','1','0','4',',',
                       '4','3','2','8','.','2','5','0','4',',',	  // <Lat>
                       '-','8','0','3','2','.','5','1','3','9',',', // <Long>
						 '1','6','0',',',	'0'};					  // <Alt>, <ClkOffset>
	uint8_t index        = 35; //set to location of ending comma

/*
  char  time_msg[5] = {'0','0','0','0','0'},
        week_msg[5] = {'0','0','0','0','0'};

	switch(hour)
	{
		case 1200:
			baud_rate[0] = '1';	baud_rate[1] = '2';
			break;

		case 2400:
			baud_rate[0] = '2';	baud_rate[1] = '4';
			break;

		case 4800:
			baud_rate[0] = '4';	baud_rate[1] = '8';
			break;

		case 9600:
			baud_rate[0] = '9';	baud_rate[1] = '6';
			break;

		case 19200:
			baud_rate[0] = '1';
			baud_rate[1] = '9';
			baud_rate[2] = '2';
			index        = 16 ;
			break;

		case 38400:
			baud_rate[0] = '3';
			baud_rate[1] = '8';
			baud_rate[2] = '4';
			index        = 16 ;
			break;
	}

	for(int i = 11; i < index; i++)
		message[i] = baud_rate[i - 11];	//fill in numeric value
	message[index++] = ',';

//  update data bits (GPS only accepts 7 or 8 for NMEA)
	message[index++] = data_bits + 48;
	message[index++] = ',';
*/

//  <ChannelCount>
	message[index++] = '1';
	message[index++] = '2';
	message[index++] = ',';

/*  Reset Config bit mask (UBYTE):
	0x01 = Data Valid warm/hot starts =1
	0x02 = clear ephemeris warm start =1
	0x04 = clear memory. Cold start   =1  */
	message[index++] = '3';

	message[index++] = '*';
	calc_checksum(message);

	send(message);
}
