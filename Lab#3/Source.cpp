#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<limits.h>

using namespace std;
/*****************
Cоставить программу , которая по заданному году y и номеру месяца m
определяет количество дней в году и в этом месяце
*****************/
void main()
{
	int y = 0;		//год
	int m = 0;		//мес¤ц
	int numDaysInYear = 0;
	int numDaysInMonth = 0;

	int nFebruary = 2;
    int* nMonth = new int[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int jan = 31, feb=28, mar=31, apr=30, may=31, jun=30, jul=31, aug= 31, sep=30,
		oct=31, nov=30, dec=31;

	int leapYear = 366;
	int unleapYear = 365;
	int _400=400;
	int _4 = 4;
	int _2 = 2;
	int _100 = 100;
	int modul = 0;

	// вносим номер года и мес¤ца 
	do {
		system("cls");
		cout << "Enter year" << endl;
		cin >> y;
		cout << "Enter month" << endl;
		cin >> m;
		if (y < 2050 && y>1582 && m <= 12 && m > 0)
			break;
		cout << "Error" << endl;
		getch();
	} while (true);

	/*if (y%_400 == 0) {
		numDaysInYear = leapYear;
	}
	else if (y%_4 == 0) 
		if (!y % 100 == 0)
			numDaysInYear = leapYear;
		else
			numDaysInYear = unleapYear;
	else
		numDaysInYear = unleapYear;

	if (numDaysInYear == unleapYear)
		numDaysInMonth = nMonth[m - 1];
	else
		if (m==2)
			numDaysInMonth = nMonth[m - 1] + 1;
		else 
			numDaysInMonth = nMonth[m - 1];

	cout << "Days in year: " << numDaysInYear << endl;
	cout << "Days in month: " << numDaysInMonth << endl;
	*/	

	__asm {
		; провверяем год на кратность 400
		mov eax, y
		mov edx, 0
		mov ebx, 400
		div ebx
		mov modul, edx
		cmp modul, 0
		je loopyear

		; провверяем на кратность 4
		mov eax, y
		mov edx, 0
		mov ebx, 4
		div ebx
		mov modul, edx
		cmp modul, 0
		jne unloopyear

		; провверяем на кратность 100
		mov eax, y
		mov edx, 0
		mov ebx, 100
		div ebx
		mov modul, edx
		cmp modul, 0
		jne loopyear

		;если год не високосный
		unloopyear:
		mov numDaysInYear, 365
			jmp end1
			;если год високосный
		loopyear:
			mov numDaysInYear, 366
			jmp end1

		end1:

			; проверяем номер мес¤ца и по менеру заносим необходимое значение
			cmp m, 1
			je janm
			cmp m, 2
			je febm
			cmp m, 3
			je marm
			cmp m, 4
			je aprm
			cmp m, 5
			je maym
			cmp m, 6
			je junm
			cmp m, 7
			je julm
			cmp m, 8
			je augm
			cmp m, 9
			je sepm
			cmp m, 10
			je octm
			cmp m, 11
			je novm
			cmp m, 12
			je decm

			;заносим значеие в переменную мес¤ц и выходим из вставки
			janm:
				mov eax, jan
				mov numDaysInMonth, eax
				jmp end2
			febm :
				mov eax, feb
				mov numDaysInMonth, eax
				cmp numDaysInYear, 365
				je end2
				inc numDaysInMonth
				jmp end2
			marm :
				mov eax, mar
				mov numDaysInMonth, eax
				jmp end2
			aprm :
				mov eax, apr
				mov numDaysInMonth, eax
				jmp end2
			maym :
				mov eax, may
				mov numDaysInMonth, eax
				jmp end2
			junm :
				mov eax, jun
				mov numDaysInMonth, eax
				jmp end2
			julm :
				mov eax, jul
				mov numDaysInMonth, eax
				jmp end2
			augm :
				mov eax, aug
				mov numDaysInMonth, eax
				jmp end2
			sepm :
				mov eax, sep
				mov numDaysInMonth, eax
				jmp end2
			octm :
				mov eax, oct
				mov numDaysInMonth, eax
				jmp end2
			novm :
				mov eax, nov
					mov numDaysInMonth, eax
					jmp end2
			decm :
				mov eax, dec
					mov numDaysInMonth, eax
					jmp end2

			end2:
	}

	cout << "Days in year: " << numDaysInYear << endl;
	cout << "Days in month: " << numDaysInMonth << endl;

	getch();
}