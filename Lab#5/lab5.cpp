

/*
ƒан одномерный целочисленый массив,
состо¤щий из положительных и
отрицательных элементов. «аменить нул¤ми
те числа, которые по модулю больше максимума.
*/

#include <iostream>
#include <cstdlib>

using namespace std;


int main() {

	const int N = 10;
	int arr[N] = { -23, 8, 5, -1, -11, 7, 1, 3, 2, 0 };
	int arr_show_first[N];

	memcpy(arr_show_first, arr, sizeof(arr));

	int max_elem = 0;

	int tmp = 0;
	int tmp2 = 1;

	__asm {
		MOV ECX, N
		MOV ESI, 0
		MOV EBX, arr[ESI]

		max_search_loop:
			ADD ESI, 4
			CMP EBX, arr[ESI];// EBX < arr[ESI] ? new_max : through
			JL new_max
			JMP through_max_search_loop

			new_max :
				MOV EBX, arr[ESI]

			through_max_search_loop :
				loop max_search_loop

		MOV max_elem, EBX
		MOV ECX, N
		MOV ESI, 0

		;// ƒелаем модуль максимального числа
		CMP EBX, 0
		JL xchg_num_sign
		JMP zero_insert_loop

		xchg_num_sign :
			NEG EBX

		;// ¬ставл¤ем нули, где числа по модулю больше максимального
		zero_insert_loop:
			MOV EAX, arr[ESI]
			CMP EAX, 0
			JL xchg_num_sign_in_loop	;// < ?
			JMP through_sign_check

			;// ƒелаем модуль из текущего числа
			xchg_num_sign_in_loop:
				NEG EAX
			;// —равниваем положительные части числе
			through_sign_check:
				CMP max_elem, EAX
				JL insert_zero	;// < ?
				JMP through_zero_insert_loop
			;// ¬ставл¤ем ноль подход¤щее место
			insert_zero:
				MOV arr[ESI], 0

			through_zero_insert_loop :
				ADD ESI, 4
				loop zero_insert_loop

		dbg_fin : NOP
	}


	cout << "max elem: " << max_elem << endl;

	for (int i = 0; i < N; i++) {
		cout << arr_show_first[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");

	return 0;
}