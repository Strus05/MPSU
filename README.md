## Работа с Atmel Studio

* **Цель работы:** Создать логический элемент 3ИЛИ
* **Программирование микроконтроллера:** Реализуем функцию вывода сигнала на вывод PC7 порта PORTC микроконтроллера ATmega16U4 при наличии определённого состояния на входах PB0, PB1 и PB2 порта PINB.
Строка `DDRC |= (1<<PC7);`Устанавливает  вывод PC7 в режим выхода.  
Условие `if ((PINB & (1<<PB0)) || (PINB & (1<<PB1)) || (PINB & (1<<PB2)))` проверяет состояние входов PB0, PB1 и PB2, и если  
 хотя бы один из них установлен в 1, то выполняется код `PORTC |= (1<<PC7);`  
Код `PORTC |= (1<<PC7);` Устанавливает вывод PC7 в 1, если соблюдается условие if. В противном случае `PORTC &= ~(1<<PC7);` устанавливает вывод в 0.   
Полный код выглядит так:
 ```
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

* **Создание модели:** Расскажите о том, как вы создали модель вашей схемы в Proteus.
* **Симуляция:** Опишите результаты симуляции вашей модели, включая полученные графики и данные.
* **Анализ результатов:** Обсудите, какие выводы вы сделали на основе полученных результатов.
* 
!["Демонстрация работы"](https://github.com/Strus05/MPSU/blob/main/presentation.gif) 
