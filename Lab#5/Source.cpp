#include <iostream>
#include <string>
#include<cmath>
#include <limits.h>

using namespace std;
/*Дан одномерный целочисленный массив A[N] .есть положительные и отрицательные .Заменить нулями те числа, которые 
по модулю больше максимума.
.*/
int main()
{
    const int n = 7;
	int mas[n] = { 1,-5, 6, -10, 2, -15, 1 };
	int masStart[n];
	memcpy(masStart, mas, sizeof(mas));
	int maxElem = -999;
	int _0 = 0;
	int _1 = 1;


	__asm {

		mov ecx, n
		mov esi, 0
		mov ebx, INT_MIN

		;находим максимальный элемент
		cycl:
			cmp ebx, mas[esi]; сравниваем действующий максимальный элемент с элементом массива

			jl newmaxelem; если максимальный меньше, то задаем новый максимальный элемент

			jmp endcycl
			
			newmaxelem:
			
			mov ebx, mas[esi]

				endcycl :
				add esi, 4
			loop cycl

				mov maxElem, ebx


				mov ecx, n
				mov esi, 0

				;заменяем на нули те элементы, которые больше по модулю максимального
		cycl2 :
			mov eax, mas[esi]; получаем элемент
			;если он отрицательный, меняем его знак
			cmp eax, _0
			jg elementpositive
			neg eax
		
			elementpositive:
				cmp maxElem, eax; сравниваем его с максимальным
				jl replace; если он больше, то меняем его на ноль

			jmp endcycl2

			replace :
				mov mas[esi], 0 

			endcycl2 :
			add esi, 4
		loop cycl2
					
	}
	cout <<"Max element: "<< maxElem << endl;
	for (int i = 0; i < n; i++)
	{
		cout << masStart[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	
	system("pause");
	return 0;
}