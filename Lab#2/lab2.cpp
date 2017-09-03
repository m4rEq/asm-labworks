#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<limits.h>

/*
	По сторонам треугольника, найти центр описанной окружности

*/

using namespace std;

void main()
{
	float x1 = 0, y1 = 9, x2 = 9, y2 = 18, x3 = 9, y3 = 0; //координаты вершин треугольника
	float x4 = 0, y4 = 0, x5 = 0, y5 = 0; //координаты середин двух сторон 
	float a1 = 0, b1 = 0, c1 = 0, a2 = 0, b2 = 0, c2 = 0; //коэффициенты двух уравнений прямых
	float xo = 0, yo = 0; //координаты центра и радиус окружности
	float d = 2, temp;
	float lOp, rOp, leftOp, rightOp;

	cout << "Enter x1: ";
	cin >> x1;
	cout << endl;
	cout << "Enter y1: ";
	cin >> y1;
	cout << endl;
	cout << "Enter x2: ";
	cin >> x2;
	cout << endl;
	cout << "Enter y2: ";
	cin >> y2;
	cout << endl;
	cout << "Enter x3: ";
	cin >> x3;
	cout << endl;
	cout << "Enter y3: ";
	cin >> y3;
	cout << endl;

	if ((x1 - x3)*(y2 - y3) - (x2 - x3)*(y1 - y3) == 0) {
		cout << "Error" << endl;
		getch();
		getch();
		return;
	}
	//середины сторон
	/*
		x4 = (x1 + x2) / 2;
		y4 = (y1 + y2) / 2;
		x5 = (x1 + x3) / 2;
		y5 = (y1 + y3) / 2;

		//кооффициенты 2х прямых, перпендикулярных сторонам и проходящих через их середины

		a1  = x2 - x1;
		b1  = y2 - y1;
		c1  = x4*(x2 - x1) + y4*(y2 - y1);
		a2  = x3 - x1;
		b2  = y3 - y1;
		c2  = x5*(x3 - x1) + y5*(y3 - y1);
	*/

	//координаты центра = точка пересечения прямых
	/*
		xo = (c1*b2 - c2*b1) / (a1*b2 - a2*b1);
		yo = (a1*c2 - a2*c1) / (a1*b2 - a2*b1);
	*/

	__asm {
		; finit
		; находим x4
		fld x1
		fadd x2
		fdiv d
		fstp x4
		; находим y4
		fld y1
		fadd y2
		fdiv d
		fstp y4
		; находим x5
		fld x1
		fadd x3
		fdiv d
		fstp x5
		; находим y5
		fld y1
		fadd y3
		fdiv d
		fstp y5
		; находим a1
		fld x2
		fsub x1
		fstp a1
		; находим b1
		fld y2
		fsub y1
		fstp b1
		; находим c1
		fld x2
		fsub x1
		fmul x4
		fstp temp
		fld y2
		fsub y1
		fmul y4
		fadd temp
		fstp c1
		; находим a2
		fld x3
		fsub x1
		fstp a2
		; находим b2
		fld y3
		fsub y1
		fstp b2
		; находим c2
		fld x3
		fsub x1
		fmul x5
		fstp temp
		fld y3
		fsub y1
		fmul y5
		fadd temp
		fstp c2
		; находим xo
		fld c2
		fmul b1
		fstp rOp
		fld c1
		fmul b2
		fstp lOp
		fld lOp
		fsub rOp
		fstp leftOp
		; ----
		fld a2
		fmul b1
		fstp rOp
		fld b2
		fmul a1
		fstp lOp
		fld lOp
		fsub rOp
		fstp rightOp
		fld leftOp
		fdiv rightOp
		fstp xo
		; находим yo
		fld a2
		fmul c1
		fstp rOp
		fld a1
		fmul c2
		fstp lOp
		fld lOp
		fsub rOp
		fstp leftOp
		; ----
		fld a2
		fmul b1
		fstp rOp
		fld b2
		fmul a1
		fstp lOp
		fld lOp
		fsub rOp
		fstp rightOp
		fld leftOp
		fdiv rightOp
		fstp yo
		fwait
	}

	cout << xo << " " << yo << endl;
	getch();
}