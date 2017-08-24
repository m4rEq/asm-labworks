// lab2.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;
const double z = 100;
const  double c = 10;
const double d = 2.54;
const double f=30.48;


int main()
{
	double sm0;
	double asmsm;
	double t1, t2;

	double foot;
	double inch;
	double sm;
	double m;
	double mm;
	double asmfoot;
	double asminch;
	double t3, t4;
	cout << "Enter m, sm and mm: \n";
	cin >> m >> sm >> mm;
	sm0 = m*z + sm + mm / c;
	foot = sm0 / f;
	//inch =(sm0 - foot*f) / d;
	inch = foot / d;
	cout << " foot = " << foot << endl;
	cout << " inch = " << inch << endl;

	_asm {
		//переводим футы и дюймы в см и складываем значения. результат - в вершину стека.
		finit;//инициализация сопроцессора
		fld m; //загрузка вещественного числа из памяти
		fmul z;// умножаем вершину стека на z
		fstp t1;//перемещение в регистр стека (m*z)
		fld mm;
		fdiv c;
		fstp t2;
		fld sm;
		fadd t1;
		fadd t2;
		fstp asmsm;// из вершины стека в переменную с извлечением
		fld asmsm;
		fdiv f;
		fst asmfoot;
		fld asmfoot;
		fdiv d;
		fst asminch;
		//fmul f;
		//fst t3;
		//fld asmsm;
		//fsub t3;//вычитание
		//fst t4;
		//fld t4;
		//fdiv inch;
		//fst asminch;// копирует значение

	}
	cout << "Assembler: " << endl;
	cout << "foot = " << asmfoot << endl;
	cout << "inch = " << asminch << endl;
	system("pause");
	
    return 0;
}

