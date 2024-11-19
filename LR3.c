#include <avr/io.h>
#include <avr/interrupt.h>
volatile char n=0;
//������ ������, ������ �������� �������� ����� ������������� �� ���������� �����, � �������� �������� ����� ������� �� ������ PB (������ PB0-PB6 ������������� ABCDEFG ����������)
uint8_t digit_codes[] = {
	0b00111111, // 0
	0b00000110, // 1
	0b01011011, // 2
	0b01001111, // 3
	0b01100110, // 4
	0b01101101, // 5
	0b01111101, // 6
	0b00000111, // 7
	0b01111111, // 8
	0b01101111  // 9
};
// ��� ������������ ���������� (�������� ����� �� PD2) port B ����� ������ �� ���������
ISR(INT0_vect)
{
	PORTB=digit_codes[n];

}

int main(void)
{
	DDRB=0xff;		// ����� B ����� �������� �� ������ ����������
	EICRA|=(1<<ISC00) | (1<<ISC01); //���������� INT0 ����� ����������� �� ��������� ������
	EIMSK|=(1<<INT0); //���������� ���������� INT0
	unsigned char i;
	sei(); //���������� ����������
	while(1)
	{
		for(i=0;i<10;i++)
		{
			n = i;
		}
	}
}
