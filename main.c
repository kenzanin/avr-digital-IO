/**
 * kenzanin AVR Pin Input Output Driver
 * license LGPLv3
 * Copy-left kenzanin[at]gmail[dot]com
 */

#include <avr/io.h>
#include <stdarg.h>
#include "digital_io/digital_io.h"

int main(void)
{
    port_output_hi(PORTB,4,0,1,2,3);
    port_output_lo(PORTB,4,4,5,6,7);
    port_input_hi(PORTC,4,0,1,2,3);
    port_input_lo(PORTC,4,0,1,2,3);

    port_write_hi(PORTB,4,4,5,6,7);
    port_write_lo(PORTB,4,0,1,2,3);

    while(1)
    {

    }
    return 0;
}
