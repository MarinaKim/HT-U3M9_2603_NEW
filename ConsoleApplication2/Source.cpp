#include<stdio.h>
#include <locale.h>
#include<iostream>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include<stdlib.h>
#include "Header.h"

#define size 20
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n;

	do
	{
		printf("Введите номер задания: ");
		scanf("%d", &n);
		cin.get();
		switch (n) {
			/*1.	Описать структуру с именем NOTE1, содержащую поля:
			a.	Name – фамилия и инициалы
			b.	TELE – номер телефона
			c.	DATE – дата рождения (год, месяц, число)

			Написать программу, выполняющую:
			•	ввод с клавиатуры данных в массив BLOCK, состоящий из 9 элементов типа NOTE1, записи должны быть упорядочены
			по инициалам;
			•	+вывод на экран информации о людях, чьи дни рождения приходятся на месяц, значение которого введено с клавиатуры;
			если такого человека нет – выдать сообщение.
			*/
		case 1: {
			int count = 5 + rand() % 5;
			NOTE1*people = NULL;
			people = (NOTE1*)malloc(count * sizeof(NOTE1));
			if (people != 0)
			{
				for (int i = 0; i < count; i++)
				{
					(people + i)->name = (char*)malloc(12 * sizeof(char));
					generateName((people + i)->name);

					(people + i)->phone = (number*)malloc(8 * sizeof(number));
					generatePhone((people + i)->phone);

					(people + i)->age = (dates*)malloc(10 * sizeof(dates));
					generateDate((people + i)->age);

					printf("%s\t%2d-%2d-%2d\t%2d.%2d.%4d\n", (people + i)->name,
						(people + i)->phone->n1, (people + i)->phone->n2, (people + i)->phone->n3,
						(people + i)->age->day, (people + i)->age->month, (people + i)->age->year);
				}

				Birthday(people, count);
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}

		}break;

			/*2.	Описать структуру с именем TOVAR, содержащую поля:
			a.	название товара;
			b.	количество единиц товара;
			c.	стоимость товара;
			d.	дата поступления товара в виде структуры (год, месяц, день).

			Написать функции:
			•	+создания массива SPISOK не более чем из 10 записей (структур) данных о товарах (ввод данных с клавиатуры);
			•	+вычисления средней стоимости товара;
			•	+расположения записей по возрастанию стоимости товаров;
			•	+вывода сведений о товарах, поступивших более 10 месяцев назад.

			Все необходимые данные для функций должны передаваться в качестве их параметров. Использование глобальных параметров не допускается. Создать проект, который демонстрирует работу всех функций
			*/
		case 2: {
			int count = 5 + rand() % 5;
			Tovar *products = NULL;
			int sum = 0, k, k1;
			products = (Tovar*)malloc(count * sizeof(Tovar));
			if (products != 0)
			{
				for (int i = 0; i < count; i++)
				{
					(products + i)->name = (char*)malloc(12 * sizeof(char));
					generateName((products + i)->name);

					products[i].qnt = 1 + rand() % 10;

					(products + i)->price = 10 + rand() % 1000;
					sum += (products + i)->price;

					(products + i)->date = (dates*)malloc(12 * sizeof(dates));
					generateDate((products + i)->date);

					printf("# %d \t %s \t %d.%d.%d\t %d \t %d\n", i + 1, (products + i)->name, (products + i)->date->day, (products + i)->date->month, (products + i)->date->year, (products + i)->qnt, (products + i)->price);
				}
				printf("--------------------------------------------------------------------------\n");
				printf("После сортировки:\n");
				sortTovar(products, count);
				printf("\nсредняя стоимость товаров: %d\n", sum / count);

				printf("--------------------------------------------------------------------------\n");
				printf("товар, поступивший более 10 месяцев назад:\n");
				chooseTovar(products, count);
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}
		}break;

			/*3.	Описать структуру с именем MARSHRUT, содержащую поля:
			a.	номер маршрута;
			b.	начальный пункт маршрута;
			c.	конечный пункт маршрута;
			d.	длина маршрута.
			Написать функции:
			•	+создания массива не более чем из 10 записей (структур) сведений о маршрутах (ввод данных с клавиатуры);
			•	+определения маршрута с максимальной длиной;
			•	+расположения записей по возрастанию номеров маршрутов;
			•	вывода сведений о маршрутах, которые начинаются или заканчиваются в пункте, название которого вводится
			с клавиатуры.

			Все необходимые данные для функций должны передаваться в качестве их параметров. Использование глобальных
			параметров не допускается. Создать проект, который демонстрирует работу всех функций.
			*/
		case 3: {
			int count = 5 + rand() % 5;

			MARSHRUT *bus;
			bus = (MARSHRUT*)malloc(count * sizeof(MARSHRUT));
			if (bus != 0)
			{
				for (int i = 0; i < count; i++)
				{
					(bus + i)->num = 1 + rand() % 10;

					(bus + i)->startName = (char*)malloc(12 * sizeof(char));
					generateStart((bus + i)->startName);

					(bus + i)->endName = (char*)malloc(12 * sizeof(char));
					generateEnd((bus + i)->endName);

					(bus + i)->length = 1000 + rand() % 5000;

					printf("# %d\t%s\t%s\t%d\n", (bus + i)->num, (bus + i)->startName, (bus + i)->endName, (bus + i)->length);
				}
				printf("--------------------------------------------------------------------------\n");
				printf("После сортировки:\n");
				SortBus(bus, count);
				maxLength(bus, count);

				printf("--------------------------------------------------------------------------\n");
				chooseBus(bus, count);
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}
		}break;

			/*4.	Описать структуру с именем ABON, содержащую поля:
			a.	фамилия и инициалы абонента;
			b.	номер телефона;
			c.	дата подключения телефона в виде структуры (год, месяц, день);
			d.	начисленная сумма оплаты;
			e.	сумма на счету абонента
			Написать функции:
			•	+создания массива не более чем из 12 записей (структур) данных об абонентах (ввод данных с клавиатуры);
			•	расположения записей по алфавиту (с учетом инициалов для абонентов с одинаковыми фамилиями;
			•	+добавить 20 гр. на счета абонентов, которых подключили более 10 лет назад;
			•	+вывода сведений об абонентах, у которых сумма на счету отрицательная после вычета начислений;
			•	вывода сведений об абоненте, номер телефона которого вводится с клавиатуры

			Все необходимые данные для функций должны передаваться в качестве их параметров. Использование глобальных параметров не допускается. Создать проект, который демонстрирует работу всех функций.
			*/
		case 4: {
			int count = 5 + rand() % 5;
			ABON *abonent = NULL;
			abonent = (ABON*)malloc(count * sizeof(ABON));
			if (abonent != 0)
			{
				for (int i = 0; i < count; i++)
				{
					(abonent + i)->name = (char*)malloc(12 * sizeof(char));
					generateName((abonent + i)->name);
					/*CreatName((abonent + i)->name);*/

					(abonent + i)->phone = (number*)malloc(12 * sizeof(number));
					generatePhone((abonent + i)->phone);

					(abonent + i)->dateAbon = (dates*)malloc(8 * sizeof(dates));
					generateAbonDates((abonent + i)->dateAbon);

					(abonent + i)->bill = 1000 + rand() % 5000;

					(abonent + i)->sumAbon = 1000 + rand() % 5000;

					printf("%s\t%2d-%2d-%2d\t%2d.%2d.%4d\t%d\t%d\n", (abonent + i)->name,
						(abonent + i)->phone->n1, (abonent + i)->phone->n2, (abonent + i)->phone->n3,
						(abonent + i)->dateAbon->day, (abonent + i)->dateAbon->month, (abonent + i)->dateAbon->year,
						(abonent + i)->bill, (abonent + i)->sumAbon);
				}
				printf("-----------------------------------------------------------------------\n");
				printf("добавить 20 гр. на счета абонентов, которых подключили более 10 лет назад:\n");
				abonTenYears(abonent, count);
				printf("-----------------------------------------------------------------------\n");
				printf("вывода сведений об абонентах, у которых сумма на счету отрицательная после вычета начислений:\n");
				NegativeBallance(abonent, count);
				printf("-----------------------------------------------------------------------\n");
				printf("вывода сведений об абоненте, номер телефона которого вводится с клавиатуры:\n");
				/*ChooseAbon(abonent, count);*/ // НЕ ЧИТАЕТ УСЛОВИЕ((( НЕ МОГУ РАЗОБРАТЬСЯ((
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}
		}break;
		}
	} while (n > 0);
}