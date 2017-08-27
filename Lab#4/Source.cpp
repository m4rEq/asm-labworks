#include <iostream>
#include <string>
#include<cmath>
#include<limits.h>

using namespace std;
string str(string);


/*По заданному вещественному числу х 
вычислить значение sqrt(х)  по следующей итерационной 
формуле: yi+1=0,5(yi+x/yi), y0=x. 
Итерации прекратить при |yi+1-yi|<2*10-5*/
int main()
{
	float xDIVy = 0;
	
	/*int y [5] = { 5, 4, 3, 2, 1 };
	int x [5] = { 1, 2 , 3, 4, 5 };
	int element=0;
	__asm {
		lea ebx, x
		mov eax, [ebx+16]
		mov element, eax
		//if (cin >> xx&&xx >= 0&&xx<FLT_MAX)
		//cin.clear();
		//while (cin.get() != '\n');
	}
	*/

	
	double xx;
	float x, y;
	float _05 = 0.5;
	float result,ynext,deltaY=1;
	float accuracy = 0.00002;
	
	while (true) {
		cout << "Enter X: ";
		cin >> xx;
		if (xx >= 0&&xx<=81) {
			break;
		}
		cout << "Incorrect value" << endl;
	}
	x = (float)xx;
	y = x;
	if (x == 0) {
		cout << y << endl;
		system("pause");
		return 0;
	}

	
	
		/*
	while (abs(deltaY) > accuracy) {
		double ynext = 0.5*(y + x / y);
		deltaY = ynext - y;
		y = ynext;
	};
	result = y;*/
	__asm {
		
		
		;начало цикла
		while_begin:
		; находим следующий y
			fld x
			fdiv y
			fadd y
			fmul _05
			fstp ynext
			mov eax, ynext
			fld ynext
			fsub y
			; находим deltaY
			mov y, eax
			fabs
			fstp deltaY
			fld deltaY
			; сравниваем deltaY с accuracy
			fcom accuracy
			fstsw ax
			and ax, 0700h
			cmp ah, 1h
			; если deltaY меньше accuracy, выходим из цикла
		je while_end
			; иначе, новая итерация
		jmp while_begin
			
		while_end:
			mov result, eax
		 



	}
	cout<<"Result: " << y << endl;
	system("pause");
	return 0;
}