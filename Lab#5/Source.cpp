#include <iostream>
#include <string>
#include<cmath>
#include <limits.h>

using namespace std;
/*��� ���������� ������������� ������ A[N] .���� ������������� � ������������� .�������� ������ �� �����, ������� 
�� ������ ������ ���������.
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

		;������� ������������ �������
		cycl:
			cmp ebx, mas[esi]; ���������� ����������� ������������ ������� � ��������� �������

			jl newmaxelem; ���� ������������ ������, �� ������ ����� ������������ �������

			jmp endcycl
			
			newmaxelem:
			
			mov ebx, mas[esi]

				endcycl :
				add esi, 4
			loop cycl

				mov maxElem, ebx


				mov ecx, n
				mov esi, 0

				;�������� �� ���� �� ��������, ������� ������ �� ������ �������������
		cycl2 :
			mov eax, mas[esi]; �������� �������
			;���� �� �������������, ������ ��� ����
			cmp eax, _0
			jg elementpositive
			neg eax
		
			elementpositive:
				cmp maxElem, eax; ���������� ��� � ������������
				jl replace; ���� �� ������, �� ������ ��� �� ����

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