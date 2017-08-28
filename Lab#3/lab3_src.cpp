
/*
	Программа по заданному году и номеру месяца
	определяет количество дней и в году и в этом 
	месяце
*/

#include <iostream>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

int main() {
	map<string, int> year;
	string months[12] = {
		"jan", "feb", "mar", "apr", 
		"may", "jun", "jul", "aug",
		"sep", "oct", "nov", "dec"
	};
	
	int jan = 31, feb = 28, mar = 31, apr = 30,
		may = 31, jun = 30, jul = 31, aug = 31,
		sep = 30, oct = 31, nov = 30, dec = 31;

	
	int days[12] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};
	
	for (int i = 0; i < 5; i++) {
		year[months[i]] = days[i];
	}

	int y;
	int m;

	do {
		cout << "Enter year: ";
		cin >> y;
		cout << "Enter month: ";
		cin >> m;
		if (3000 > y && y > 0 && 12 >= m && m > 0)
			break;
		cout << "Bad date!" << endl;
	} while (true);


	int modul = 0;
	int num_days_in_year = 0;
	int num_days_in_month = 0;

	__asm {
		; check year for leap (multiplicity 400)
		MOV EAX, y
		MOV EDX, 0
		MOV EBX, 400
		DIV EBX
		MOV modul, edx
		CMP modul, 0
		JE loop_year

		; check year for leap (multiplicity 4)
		MOV EAX, y
		MOV EDX, 0
		MOV EBX, 4
		DIV EBX
		MOV modul, EDX
		CMP modul, 0
		JNE unloop_year

		; check year for leap (multiplicity 100)
		MOV EAX, y
		MOV EDX, 0
		MOV EBX, 100
		DIV EBX
		MOV modul, EDX
		CMP modul, 0
		JNE loop_year

		; if year is not leap
		unloop_year:
			MOV num_days_in_year, 365
			JMP end_1
		; if year is leap
		loop_year:
			MOV num_days_in_year, 366
			JMP end_1

		end_1:
			; check month
			CMP m, 1
			JE jan_l
			
			CMP m, 2
			JE feb_l
			
			CMP m, 3
			JE mar_l
			
			CMP m, 4
			JE apr_l

			CMP m, 5
			JE may_l 

			CMP m, 6
			JE jun_l

			CMP m, 7
			JE jul_l

			CMP m, 8
			JE aug_l

			CMP m, 9
			JE sep_l

			CMP m, 10
			JE oct_l

			CMP m, 11
			JE nov_l

			CMP m, 12
			JE dec_l

		jan_l:
			MOV EAX, jan
			MOV num_days_in_month, EAX
			JMP end_2

		feb_l:
			MOV EAX, feb
			MOV num_days_in_month, EAX
			CMP num_days_in_year, 365
			JE end_2
			INC num_days_in_month
			JMP end_2

		mar_l:
			MOV EAX, mar
			MOV num_days_in_month, EAX
			JMP end_2

		apr_l:
			MOV EAX, apr
			MOV num_days_in_month, EAX
			JMP end_2

		may_l:
			MOV EAX, may
			MOV num_days_in_month, EAX
			JMP end_2

		jun_l:
			MOV EAX, jun
			MOV num_days_in_month, EAX
			JMP end_2

		jul_l:
			MOV EAX, jul
			MOV num_days_in_month, EAX
			JMP end_2

		aug_l:
			MOV EAX, aug
			MOV num_days_in_month, EAX
			JMP end_2

		sep_l:
			MOV EAX, sep
			MOV num_days_in_month, EAX 
			JMP end_2

		oct_l:
			MOV EAX, oct
			MOV num_days_in_month, EAX
			JMP end_2

		nov_l:
			MOV EAX, nov
			MOV num_days_in_month, EAX
			JMP end_2

		dec_l:
			MOV EAX, dec
			MOV num_days_in_month, EAX
			JMP end_2

		end_2:
	}

	cout << "ASM days in year: " << num_days_in_year << endl;
	cout << "ASM days in month: " << num_days_in_month << endl;

	system("pause");

	return 0;
}