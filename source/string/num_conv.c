
#include "lib/string/num_conv.h"

uint8_t bcd_to_bin(
    uint8_t                     data)
{
    uint8_t                     ret;
    
    ret = data & 0xfu;
    ret = (uint8_t)(ret + ((data >> 4u) * 10u));

    return (ret);
}

uint8_t bcd_from_bin(
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
        case '0': return (0u);
        case '1': return (1u);
        case '2': return (2u);
        case '3': return (3u);
        case '4': return (4u);
        case '5': return (5u);
        case '6': return (6u);
        case '7': return (7u);
        case '8': return (8u);
		case '9': return (9u);
		case 'a': return (10u);
		case 'b': return (11u);
		case 'c': return (12u);
		case 'd': return (13u);
		case 'e': return (14u);
		case 'f': return (15u);
		default : return ((uint32_t)-1);
	}
}



char ascii_hex_from_bin(uint32_t bin)
{
    bin &= 0x0fu;

    switch (bin) {
		case 0: return ('0');
		case 1: return ('1');
		case 2: return ('2');
		case 3: return ('3');
		case 4: return ('4');
		case 5: return ('5');
		case 6: return ('6');
		case 7: return ('7');
		case 8: return ('8');
		case 9: return ('9');
		case 10: return ('a');
        case 11: return ('b');
        case 12: return ('c');
		case 13: return ('d');
		case 14: return ('e');
		case 15: return ('f');
		default: return (0);
	}
}
