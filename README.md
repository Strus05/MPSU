Авторы:
[Астафьев Илья](https://github.com/astafa98), 
[Никитин Даниил](https://github.com/ferizAMDlove), 
[Ульянчик Руслан](https://github.com/Strus05)

* [Работа с Atmel Studio](#работа-с-atmel-studio)
* [Моделирование в Proteus 8](#моделирование-в-proteus-8)
* [Работа с fritzink](#работа-с-fritzink)
## Работа с Atmel Studio

* **Цель работы:** Создать логический элемент 3ИЛИ
* **Программирование микроконтроллера:** Реализуем функцию вывода сигнала на вывод PC7 порта PORTC микроконтроллера ATmega16U4 при наличии определённого состояния на входах PB5, PB6 и PB7 порта PINB.
  
Строка `DDRC |= (1<<PC7);`Устанавливает  вывод PC7 в режим выхода.  
Условие `if ((PINB & (1<<PB5)) || (PINB & (1<<PB6)) || (PINB & (1<<PB7)))` проверяет состояние входов PB5, PB6 и PB7, и если  
 хотя бы один из них установлен в 1, то выполняется код `PORTC |= (1<<PC7);`  
Код `PORTC |= (1<<PC7);` Устанавливает вывод PC7 в 1, если соблюдается условие if. В противном случае `PORTC &= ~(1<<PC7);` устанавливает вывод в 0.   

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
	DDRC |= (1<<PC7);  
    while(1)
    {
		if ((PINB & (1<<PB5)) || (PINB & (1<<PB6)) || (PINB & (1<<PB7))) // PINB || 0b11100000)
		{
			PORTC |= (1<<PC7);
		}
		else
		{
			PORTC &= ~(1<<PC7);
		}
    }
}
```
Для компиляции программы нажимаем F7, либо Build > Build Solution, полученые после компиляции файлы будут находиться в папке LR1/Output Files нашего проекта


## Моделирование в Proteus 8

* **Создание модели:**
1. Добавляем на схему:
   
***Микроконтроллер ATmega16U4***  

       
  <img src="https://github.com/user-attachments/assets/88663457-3789-480a-8469-6b5a86cd8920" width="300" height="300">    
  

***3 кнопки***   


  <img src="https://github.com/user-attachments/assets/b48f0f41-6eb4-4967-9e2a-45e1472342c9" width="150" height="100">  
   

***4 резистора***     

	
  <img src="https://github.com/user-attachments/assets/d4ed3653-6d9d-4c98-8111-b00427422c14" width="150" height="100">  
 

 ***1 светодиод***  

  
  <img src="https://github.com/user-attachments/assets/853dd9b5-4a77-46bf-bf02-e15aac52a8b6" width="150" height="100">  

   2. Соединяем кнопки с источником тока и подключаем каждую кнопку отдельно ко входам PB5, PB6 и PB7.  
   3. Светодиод подключаем анодом через резистор R1 к выходу PC7 и катодом к "земле"; Связываем кномки через подтягивающие резисторы с "землей";  
   
   <img src="https://github.com/user-attachments/assets/5817cdca-6e3b-4e9d-aa03-00a63829ce25" width="600" height="400">  

4. Загружаем в микроконтроллер файл программы в расширении .hex
   
<img src="https://github.com/user-attachments/assets/b960ff7a-b44f-41e0-bc7a-e572e1183aca" width="400" height="400">  

* **Симуляция:**
  Запустим симуляцию:  
  !["Демонстрация работы"](https://github.com/Strus05/MPSU/blob/main/presentation.gif)  
  
* **Анализ результатов:** 
* Реализуется алгоритм 3ИЛИ, в соотвествии с таблицей истинности: при вводе сигнала высокого уровня на любой из входов PB5, PB6, PB7 на выходе PC7 генерируется сигнал высокого уровня
  ## Работа с fritzink
Микроконтроллер ATmega16U4 используется на плате Arduino MICRO, рассмотрим её распиновку

<img src=https://github.com/Strus05/MPSU/blob/main/Pinout/Pinout_micro.png>

Из распиновки видим, что под PC7 в Arduino MICRO подразумевается вывод DP13 (Digital Port 13), а под PB5, PB6, PB7 выводы D9, D10, D11 соответственно.

* Собираем схему:

<img src="https://github.com/Strus05/MPSU/blob/main/Fritzing/LR1_МП.png">
