## Работа с Atmel Studio

* **Цель работы:** Создать логический элемент 3ИЛИ
* **Программирование микроконтроллера:** Реализуем функцию вывода сигнала на вывод PC7 порта PORTC микроконтроллера ATmega16U4 при наличии определённого состояния на входах PB0, PB1 и PB2 порта PINB.
  
Строка `DDRC |= (1<<PC7);`Устанавливает  вывод PC7 в режим выхода.  
Условие `if ((PINB & (1<<PB0)) || (PINB & (1<<PB1)) || (PINB & (1<<PB2)))` проверяет состояние входов PB0, PB1 и PB2, и если  
 хотя бы один из них установлен в 1, то выполняется код `PORTC |= (1<<PC7);`  
Код `PORTC |= (1<<PC7);` Устанавливает вывод PC7 в 1, если соблюдается условие if. В противном случае `PORTC &= ~(1<<PC7);` устанавливает вывод в 0.   
Полный код выглядит так:
 ```
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
```
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

   2. Соединяем кнопки с источником тока и подключаем каждую кнопку отдельно ко входам PB0, PB1 и PB2.  
   3. Светодиод подключаем через резистор к PC7 и "земле"; Связываем оставшиеся резисторы с выходами кнопок и "землей";  
   
   <img src="https://github.com/user-attachments/assets/5817cdca-6e3b-4e9d-aa03-00a63829ce25" width="600" height="400">  

4. Загружаем в микроконтроллер файл программы в расширении .gex
   
<img src="https://github.com/user-attachments/assets/b960ff7a-b44f-41e0-bc7a-e572e1183aca" width="400" height="400">  

* **Симуляция:**
  Запустим симуляцию:  
  !["Демонстрация работы"](https://github.com/Strus05/MPSU/blob/main/presentation.gif)  
  
* **Анализ результатов:** Обсудите, какие выводы вы сделали на основе полученных результатов.
* 
