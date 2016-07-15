
#include "lib/string/num_conv.h"

uint8_t bcd_to_bin(
    uint8_t                     data)
{
    uint8_t                     ret;
    
    ret = data & 0xfu;
    ret = (uint8_t)(ret + ((data >> 4u) * 10u));

    return (ret);
}

uint8_t bcd_from_bcd(
    uint8_t                     data)
{
    uint8_t                     ret;

    ret = ((data / 10) & 0xfu) << 4;
    ret = (uint8_t)(ret | ((data % 10) & 0xfu) << 0);

    return (ret);
}



uint32_t ascii_hex_to_bin(char hex)
{
	switch (hex) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return ((unsigned)hex - '0');
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
			return ((unsigned)hex - 'a' + 10);
		default : return (0);
	}
}



char ascii_hex_from_bin(uint32_t bin)
{
	switch (0x0fu & bin) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			return ((char)((0x0fu & bin) + '0'));
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			return ((char)((0x0fu & bin) + 'A'));
		default:
			return (0);
	}
}
