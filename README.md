# Лабораторные работы:
[Лабораторная работа №1. Порты ввода/вывода. Изучение режимов работы портов ввода/вывода](https://github.com/Strus05/MPSU/releases/tag/LR1(Proteus%2BAtmel%2BFritzing%2BPinout))

[Лабораторная работа №2. Программирование таймеров](https://github.com/Strus05/MPSU/releases/tag/LR2)

# Авторы:
[Астафьев Илья](https://github.com/astafa98), 
[Никитин Даниил](https://github.com/ferizAMDlove), 
[Ульянчик Руслан](https://github.com/Strus05)
# Содержание
* [Работа с Atmel Studio](#работа-с-atmel-studio)
* [Моделирование в Proteus 8](#моделирование-в-proteus-8)
* [Работа с fritzink](#работа-с-fritzink)
* [Работа с таймерами](#работа-с-таймерами)
# Работа с Atmel Studio

* **Цель работы:** Создать логический элемент 3ИЛИ
* **Программирование микроконтроллера:** Реализуем функцию вывода сигнала на вывод `PC0` порта PORTC микроконтроллера ATmega328P при наличии определённого состояния на входах `PB0`, `PB1` и `PB2` порта `PINB`.
  
Строка `DDRC |= (1<<PC0);`Устанавливает  вывод `PC0` в режим выхода.  
Условие `if ((PINB & (1<<PB0)) || (PINB & (1<<PB1)) || (PINB & (1<<PB2)))` проверяет состояние входов `PB0`, `PB1` и `PB2`, и если  
 хотя бы один из них установлен в 1, то выполняется код `PORTC |= (1<<PC0);`  
Код `PORTC |= (1<<PC0);` Устанавливает вывод `PC0` в 1, если соблюдается условие if. В противном случае `PORTC &= ~(1<<PC0);` устанавливает вывод в 0.  

Таблица истинности 3ИЛИ: 
 
|PB5|PB6|PB7|PC7|
|---|---|---|---|
|0|0|0|0|
|0|0|1|1|
|0|1|0|1|
|1|0|0|1|
|0|1|1|1|
|1|0|1|1|
|1|1|0|1|
|1|1|1|1|

Полный код выглядит так:
 ```
#include <avr/io.h>

int main(void)
{
	DDRC |= (1<<PC0);  
    while(1)
    {
		if ((PINB & (1<<PB0)) || (PINB & (1<<PB1)) || (PINB & (1<<PB2))) // PINB || 0b00000111)
		{
			PORTC |= (1<<PC0);
		}
		else
		{
			PORTC &= ~(1<<PC0);
		}
    }
}
```
Для компиляции программы нажимаем F7, либо Build > Build Solution, полученые после компиляции файлы будут находиться в папке LR1/Output Files нашего проекта


# Моделирование в Proteus 8

* **Создание модели:**
1. Добавляем на схему:
   
  <p align="center"><b>Микроконтроллер ATmega328P</b></p>

       
  <p align="center"><img src="https://github.com/user-attachments/assets/b684bf26-8e01-4382-84a1-c5be93d0a71e" width="300" height="300"></p>    
  

  <p align="center"><b>3 кнопки</b></p>


  <p align="center"><img src="https://github.com/user-attachments/assets/b48f0f41-6eb4-4967-9e2a-45e1472342c9" width="150" height="100"></p>   
   

  <p align="center"><b>4 резистора</b></p> 

	
  <p align="center"><img src="https://github.com/user-attachments/assets/d4ed3653-6d9d-4c98-8111-b00427422c14" width="150" height="100"></p>   
 

  <p align="center"><b>1 светодиод </b></p>

  
  <p align="center"><img src="https://github.com/user-attachments/assets/853dd9b5-4a77-46bf-bf02-e15aac52a8b6" width="150" height="100"></p>   

   2. Соединяем кнопки с источником тока и подключаем каждую кнопку отдельно ко входам `PB0`, `PB1` и `PB2`.  
   3. Светодиод подключаем анодом через резистор R1 к выходу `PC0` и катодом к "земле"; Связываем кнопки через подтягивающие резисторы с "землей";  
 

   <p align="center"><img src="https://github.com/user-attachments/assets/6b27329a-ca2c-4e94-b961-29c7534db4a1" width="700" height="400"></p>   

4. Загружаем в микроконтроллер файл программы в расширении .hex
   
<p align="center"><img src="https://github.com/user-attachments/assets/b960ff7a-b44f-41e0-bc7a-e572e1183aca" width="400" height="400"></p>     

* **Симуляция:**
  Запустим симуляцию:  
!["Демонстрация работы"](https://github.com/Strus05/MPSU/blob/main/show.gif) 
  
* **Анализ результатов:** 
    - Реализуется алгоритм 3ИЛИ, в соотвествии с таблицей истинности: при вводе сигнала высокого уровня на любой из входов `PB0`, `PB1`, `PB2` на выходе `PC0` генерируется сигнал высокого уровня
# Работа с fritzink
Микроконтроллер ATmega328P используется на плате Arduino NANO, рассмотрим её распиновку:

<p align="center"><img src="https://github.com/user-attachments/assets/7350c675-203d-4579-ae7e-a646ded7ba88" width="400" height"400"></p>   

Из распиновки видим, что под `PC0` в Arduino NANO подразумевается вывод ``A0`` (Analog Pin 0), а под `PB0`, `PB1`, `PB2` выводы `D8`, `D9`, `D10` (Digital Pin 8, 9, 10) соответственно.



* Собираем схему:

<p align="center"><img src="https://github.com/user-attachments/assets/e3abbb15-0f13-4534-b044-4e3905ce2aee" width="400" height"400"></p>  

<p align="center"><img src="https://github.com/user-attachments/assets/966facb3-ef93-41df-bf9c-387f717b727a" width="400" height"400"></p>  

<p align="center"><img src="https://github.com/user-attachments/assets/000b7ef6-4f06-481e-823d-4ee03287d817" width="400" height"400"></p>

# Работа с таймерами

* **Цель работы:** Изучить режимы работы таймера ATMEGA328P

**Задачи:**
1. Напишем программу, в которой при нажатии на кнопку, микроконтроллер формирует выдержку времени и зажигает зеленый светодиод с заданным периодом (0,1с и 1с)
2. Напишем программу, в которой вывод PB5 при инициализации таймера 0 запрограммирован для выдачи сигнала с заданной частотой (1Гц)
3. Напишем программу, в которой порт ввода PC0 подключен к потенциометру который регулирует напряжение на нём от 0 до +5В. Сигнал с порта PC0 обрабатывается с помощью АЦП и преобразуется в скважность ШИМ сигнала для порта вывода PB1 которым управляем частотой вращения двигателя.

**Код программы в Atmel Studio**
```
#include <avr/io.h>
#include <avr/interrupt.h>
int scet = 0;
char otschet1s = 0;
char otschet1Gz = 0;

void timer2_init() {
	TCCR2B |= (1 << CS02) | (1 << CS01) | (1 << CS00);		//Задаём прескейлинг 1024. sT = 0,001024 c
	OCR2A = 98;		// OCR2A*sT = период работы диода. Здесь 0,1с
	OCR2B = 244;	// 0,25с
}

void timer0_init() {
	TCCR0A |= (1 << WGM01);    // Режим CTC
	OCR0A = 98;    // Значение при котором сбрасывается таймер (при 1МГц чипе, для 1с OCR1A = 977)
	TCCR0B |= (1 << CS02) | (0 << CS01) | (1 << CS00);		//Задаём прескейлинг 1024
}

void pwm_init_1() {
	TCCR1B |= (1 << WGM12);						// Режим FastPWM 10-bit
	TCCR1A |= (1 << WGM11) | (1 << WGM10);
	TCCR1A |= (1 << COM1A1);	// Clear OC1A/OC1B on compare match
	TCCR1B |= (0 << CS12) | (1 << CS11) | (1 << CS10);		//Задаём прескейлинг 1024
}
void setup_adc() {
	ADMUX |= (1 << REFS0); // Voltage Reference - AVCC
	ADCSRA |= (1 << ADEN); // ADC Enable
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // ADC Prescaler Selections 128
}
uint16_t read_adc() {
	ADMUX &= 0xF0; // Выбрать канал ADC0
	ADCSRA |= (1 << ADSC); // начало преобразования
	while (ADCSRA & (1 << ADSC)); // When the conversion is complete, ADSC returns to zero
	return ADC;			//Результат работы АЦП
}


int main(void)
{
	DDRB |= (1 << PB5);
	DDRB |= (1 << PB4);
    DDRB |= (1 << PB1);
    DDRB |= (1 << PB3);
	DDRC |= (0 << PC0);
	DDRC |= (0 << PC1) | (0 << PC2);
	setup_adc();
    pwm_init_1();
	timer0_init();
	timer2_init();
	while(1)
	{
		if((TIFR2 & (1 << OCF2A)) & (PINC & (1 << PC1)))		// OCF2A устанавливается 1 при достижении таймером OCR2A 
		{
			PORTB ^= (1 << PB3);
			TIFR2 |= (1 << OCF2A);	// Сбрасываем флаг OCF2A
			TCNT2 = 0;				// Сбрасываем таймер2
		}
		else if((TIFR2 & (1 << OCF2B)) & (PINC & (1 << PC2)))		// OCF2B устанавливается 1 при достижении таймером OCR2B 
		{
			TIFR2 |= (1 << OCF2B);
			TCNT2 = 0;				
			otschet1s++;			// Для достижения 1с отсчитываем 4 раза по 0,25с
			if(otschet1s == 4)
			{
				otschet1s = 0;
				PORTB ^= (1 << PB3);
			}
		}
		if(TIFR0 & (1 << OCF0A))	// OCF0A устанавливается 1 при достижении таймером OCR0A 
		{
			TIFR0 |= (1 << OCF0A);
			otschet1Gz++;
			if(otschet1Gz==10)		// Для достижения нужной частоты otschet1Gz == 1/(0.1f)
			{
				otschet1Gz = 0;
				PORTB ^= (1 << PB5);
			}
		}
        OCR1A = read_adc(); // Прочитать значение с ADC
	}
}
```
**Демонстрация работы схемы в Proteus**

![Видео](https://github.com/user-attachments/assets/2af97a59-dcda-4d8c-9f52-24e5ffe974c4)

Сигнал ШИМ при выкрученым на 75% потенциометром (75% скважность)

![image](https://github.com/user-attachments/assets/03aa30e7-e5e6-4587-a788-c1bb3db724aa)


