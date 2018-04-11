#include <math.h>
#include<stdio.h>
#include <time.h>
#include <stdint.h>
#include <string.h>
#include<stdlib.h>
#include<iostream>
#include "Header.h"
using namespace std;

void generateDate(dates *t)
{
	t->day = 1 + rand() % 30;
	t->month = 1 + rand() % 11;
	t->year = 2017 + rand() % 2;
}
void generateName(char *name)
{
	strcpy(name, "Number #");
	int a = 1 + rand() % 30;
	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}

void sortTovar(Tovar* a, int r)
{
	Tovar temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if ((a + j - 1)->price > (a + j)->price)
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

			}
		}
		printf("# %d \t %s \t %d.%d.%d\t %d \t %d\n", i + 1, (a + i)->name, (a + i)->date->day, (a + i)->date->month, (a + i)->date->year, (a + i)->qnt, (a + i)->price);
	}
}

void chooseTovar(Tovar *a, int r)
{
	for (int i = 0; i < r; i++)
	{
		if (((a + i)->date->year <= 2017) && ((a + i)->date->month < 6))
		{
			printf("# %d \t %s \t %d.%d.%d\t %d \t %d\n", i + 1, (a + i)->name, (a + i)->date->day, (a + i)->date->month, (a + i)->date->year, (a + i)->qnt, (a + i)->price);
		}
	}
}

void generateStart(char *name)
{
	strcpy(name, "Start #");
	int a = 1 + rand() % 30;
	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}
void generateEnd(char *name)
{
	strcpy(name, "End #");
	int a = 1 + rand() % 30;
	char t[3];
	itoa(a, t, 10);

	strcat(name, t);
}

void maxLength(MARSHRUT *a, int r)
{
	int maxLen = 10, ind;
	for (int i = 0; i < r; i++)
	{
		if (a[i].length > maxLen)
		{
			maxLen = a[i].length;
			ind = i;
		}
	}
	printf("Маршрут с с максимальной длиной: # %d\t%s\t%s\t%d\n", a[ind].num, a[ind].startName, a[ind].endName, a[ind].length);
}

void SortBus(MARSHRUT *a, int r)
{
	MARSHRUT temp;
	for (int i = 0; i < r; i++)
	{
		for (int j = r - 1; j > i; j--)
		{
			if ((a + j - 1)->num > (a + j)->num)
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;

			}
		}
		printf("# %d\t%s\t%s\t%d\n", (a + i)->num, (a + i)->startName, (a + i)->endName, (a + i)->length);

	}
}

void chooseBus(MARSHRUT *a, int r)
{
	char name[15];
	int i;
	printf("Введите название пункта: ");
	fgets(name, 10, stdin);
	/*cin.get();*/
	for (i=0;i<r;i++)
	{
		/* НЕ ПОНИМАЮ ПОЧЕМУ УСЛОВИЕ НЕ ОТРАБАТЫВАЕТ(((*/
		if ((a[i].endName == name) || (a [i].startName == name))
		{
			printf("маршруты, которые начинаются или заканчиваются в пункте %s:\n # %d\t%s\t%s\t%d\n", name, (a + i)->num, (a + i)->startName, (a + i)->endName, (a + i)->length);
		}
	}
}

void CreatName(char *a)
{
	char lName[10][9] = { "Иванов", "Петров","Сидоров","Абрамов ","Бирюков ","Воронов ","Громов ","Дроздов ","Ершов ","Игнатов " };
	char name[10][5] = { "В.В.","C.K.","M.К.","C.П.","A.M.","O.P.","K.И.","В.Ф.","Т.Л.","A.C." };

	int rnd =1+ rand() % 9;
	strcat(a, lName[rnd]);
	strcat(a, " ");
	rnd = 1+rand() % 9;
	strcat(a, name[rnd]);
}

void generateAbonDates(dates *date)
{
	date->day = 1 + rand() % 30;
	date->month = 1 + rand() % 11;
	date->year = 1995 + rand() % 23;
}

void generatePhone(number *phone)
{

	phone->n1 = 10 + rand() % 89;
	phone->n2 = 10 + rand() % 89;
	phone->n3 = 10 + rand() % 89;
	
}