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
		printf("������� ����� �������: ");
		scanf("%d", &n);
		cin.get();
		switch (n) {
			/*1.	������� ��������� � ������ NOTE1, ���������� ����:
			a.	Name � ������� � ��������
			b.	TELE � ����� ��������
			c.	DATE � ���� �������� (���, �����, �����)

			�������� ���������, �����������:
			�	���� � ���������� ������ � ������ BLOCK, ��������� �� 9 ��������� ���� NOTE1, ������ ������ ���� �����������
			�� ���������;
			�	+����� �� ����� ���������� � �����, ��� ��� �������� ���������� �� �����, �������� �������� ������� � ����������;
			���� ������ �������� ��� � ������ ���������.
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

			/*2.	������� ��������� � ������ TOVAR, ���������� ����:
			a.	�������� ������;
			b.	���������� ������ ������;
			c.	��������� ������;
			d.	���� ����������� ������ � ���� ��������� (���, �����, ����).

			�������� �������:
			�	+�������� ������� SPISOK �� ����� ��� �� 10 ������� (��������) ������ � ������� (���� ������ � ����������);
			�	+���������� ������� ��������� ������;
			�	+������������ ������� �� ����������� ��������� �������;
			�	+������ �������� � �������, ����������� ����� 10 ������� �����.

			��� ����������� ������ ��� ������� ������ ������������ � �������� �� ����������. ������������� ���������� ���������� �� �����������. ������� ������, ������� ������������� ������ ���� �������
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
				printf("����� ����������:\n");
				sortTovar(products, count);
				printf("\n������� ��������� �������: %d\n", sum / count);

				printf("--------------------------------------------------------------------------\n");
				printf("�����, ����������� ����� 10 ������� �����:\n");
				chooseTovar(products, count);
			}
			else
			{
				printf("error\n");
				EXIT_FAILURE;
			}
		}break;

			/*3.	������� ��������� � ������ MARSHRUT, ���������� ����:
			a.	����� ��������;
			b.	��������� ����� ��������;
			c.	�������� ����� ��������;
			d.	����� ��������.
			�������� �������:
			�	+�������� ������� �� ����� ��� �� 10 ������� (��������) �������� � ��������� (���� ������ � ����������);
			�	+����������� �������� � ������������ ������;
			�	+������������ ������� �� ����������� ������� ���������;
			�	������ �������� � ���������, ������� ���������� ��� ������������� � ������, �������� �������� ��������
			� ����������.

			��� ����������� ������ ��� ������� ������ ������������ � �������� �� ����������. ������������� ����������
			���������� �� �����������. ������� ������, ������� ������������� ������ ���� �������.
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
				printf("����� ����������:\n");
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

			/*4.	������� ��������� � ������ ABON, ���������� ����:
			a.	������� � �������� ��������;
			b.	����� ��������;
			c.	���� ����������� �������� � ���� ��������� (���, �����, ����);
			d.	����������� ����� ������;
			e.	����� �� ����� ��������
			�������� �������:
			�	+�������� ������� �� ����� ��� �� 12 ������� (��������) ������ �� ��������� (���� ������ � ����������);
			�	������������ ������� �� �������� (� ������ ��������� ��� ��������� � ����������� ���������;
			�	+�������� 20 ��. �� ����� ���������, ������� ���������� ����� 10 ��� �����;
			�	+������ �������� �� ���������, � ������� ����� �� ����� ������������� ����� ������ ����������;
			�	������ �������� �� ��������, ����� �������� �������� �������� � ����������

			��� ����������� ������ ��� ������� ������ ������������ � �������� �� ����������. ������������� ���������� ���������� �� �����������. ������� ������, ������� ������������� ������ ���� �������.
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
				printf("�������� 20 ��. �� ����� ���������, ������� ���������� ����� 10 ��� �����:\n");
				abonTenYears(abonent, count);
				printf("-----------------------------------------------------------------------\n");
				printf("������ �������� �� ���������, � ������� ����� �� ����� ������������� ����� ������ ����������:\n");
				NegativeBallance(abonent, count);
				printf("-----------------------------------------------------------------------\n");
				printf("������ �������� �� ��������, ����� �������� �������� �������� � ����������:\n");
				/*ChooseAbon(abonent, count);*/ // �� ������ �������((( �� ���� �����������((
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