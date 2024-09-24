#include <avr/io.h>

int main(void)
{
	DDRC |= (1<<PC7);
	while(1)
	{
		if ((PINB & (1<<PB5)) || (PINB & (1<<PB6)) || (PINB & (1<<PB7))) // PINB || 0b11100000
		{
			PORTC |= (1<<PC7);
		}
		else
		{
			PORTC &= ~(1<<PC7);
		}
	}
}