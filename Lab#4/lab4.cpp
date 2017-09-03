#include <iostream>
#include <string>
#include<cmath>
#include <limits.h>

/*
Если скалярное произведение больше нуля, вывести
модуль вектора X иначе вывести модель вектора Y
*/

using namespace std;

int asmScalProd(int[], int[], int);
int scalProd(int[], int[], int);


int main()
{
	int X[20] = { 1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1 };
	int Y[20] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1 };

	int Iter = 20;


	if (asmScalProd(X, Y, 15) > 0) {
		cout << "Res: " << asmScalProd(X, X, 20) << endl;
	}
	else {
		cout << "Res: " << asmScalProd(Y, Y, 20) << endl;
	}

	system("pause");
	return 0;
}

int scalProd(int X[], int Y[], int N) {
	int result = 0;

	for (int i = 0; i < N; i++) {
		result += X[i] * Y[i];
	}

	return result;
}

int asmScalProd(int X[], int Y[], int N) {

	int result;


	__asm {
		XOR EAX, EAX
		MOV result, EAX
		MOV ECX, N
		MOV EBX, X
		MOV EDX, Y
		XOR ESI, ESI


		mul_loop:
			PUSH EBX
			PUSH EDX

			MOV EBX, [EBX + ESI]
			MOV EDX, [EDX + ESI]
			IMUL EBX, EDX
			ADD EAX, EBX

			POP EDX
			POP EBX
			ADD ESI, 4
			loop mul_loop

		MOV result, EAX
	}

	return result;
}