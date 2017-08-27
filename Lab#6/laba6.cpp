#include <iostream>
#include <string>
#include<cmath>
#include <limits.h>
/*fdfdsfsdfdf*/
//dfdfdsfds
using namespace std;
int main()
{
	int X[20] = { 1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1 };
	int Y[20] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1 };
	int r = 0;
	int result = 0;

	__asm {

		lea edx, Y; беру адреса массивов
		lea ebx, X
		mov eax, 0; в eax будет наша сумма
		push edx; кладу их в стек
		push ebx
		mov ecx, 15
		push ecx
		call Procedure; вызываю процедуру

		jmp endprog

		Procedure :
		; mov ecx, 20; указываю число итераций
			mov esi, 0; инициализирую счетчик цикла
			push ebp
			mov ebp, esp; пролог
			mov ecx, [ebp + 8]
			mov ebx, [ebp + 12]; беру адреса массивов из стека
			mov edx, [ebp + 16]

			lp:
		push ebx
			push edx
			mov ebx, [ebx + esi]; получаю элементы массивов
			mov edx, [edx + esi]
			push ebx
			imul ebx, edx; перемножаю их
			cmp ebx, 0; сравниваю их произведение с нулем
			pop ebx
			jg mulgreater0; если произведение больше нуля

			imul edx, edx; иначе
			add eax, edx
			jmp enditer

			mulgreater0 :
		imul ebx, ebx
			add eax, ebx
			enditer :
		add esi, 4
			pop edx
			pop ebx
			loop lp
			pop ebp; эпилогш
			ret 8

			endprog:
		mov result, eax

	}

	cout << result << endl;
	system("pause");
	return 0;
}
