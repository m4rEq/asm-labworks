// lab2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
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
		//��������� ���� � ����� � �� � ���������� ��������. ��������� - � ������� �����.
		finit;//������������� ������������
		fld m; //�������� ������������� ����� �� ������
		fmul z;// �������� ������� ����� �� z
		fstp t1;//����������� � ������� ����� (m*z)
		fld mm;
		fdiv c;
		fstp t2;
		fld sm;
		fadd t1;
		fadd t2;
		fstp asmsm;// �� ������� ����� � ���������� � �����������
		fld asmsm;
		fdiv f;
		fst asmfoot;
		fld asmfoot;
		fdiv d;
		fst asminch;
		//fmul f;
		//fst t3;
		//fld asmsm;
		//fsub t3;//���������
		//fst t4;
		//fld t4;
		//fdiv inch;
		//fst asminch;// �������� ��������

	}
	cout << "Assembler: " << endl;
	cout << "foot = " << asmfoot << endl;
	cout << "inch = " << asminch << endl;
	system("pause");
	
    return 0;
}

