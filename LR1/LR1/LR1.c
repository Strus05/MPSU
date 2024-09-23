#include <avr/io.h>

int main(void)
{
	DDRC |= (1<<PC7);
	while(1)
	{
		if ((PINB & (1<<PB0)) || (PINB & (1<<PB1)) || (PINB & (1<<PB2))) // PINB || 0b00000111)
		{
			PORTC |= (1<<PC7);
		}
		else
		{
			PORTC &= ~(1<<PC7);
		}
	}
}