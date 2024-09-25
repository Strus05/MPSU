# Авторы:
[Астафьев Илья](https://github.com/astafa98), 
[Никитин Даниил](https://github.com/ferizAMDlove), 
[Ульянчик Руслан](https://github.com/Strus05)
# Содержание
* [Работа с Atmel Studio](#работа-с-atmel-studio)
* [Моделирование в Proteus 8](#моделирование-в-proteus-8)
* [Работа с fritzink](#работа-с-fritzink)
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

       
  <p align="center"><img src="https://github.com/user-attachments/assets/88663457-3789-480a-8469-6b5a86cd8920" width="300" height="300"></p>    
  

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
