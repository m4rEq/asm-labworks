#include <iostream>
#include <cstdio>
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
		if (3000 > y && y > 0 && 12 => m && m > 0)
			break;
		cout << "Bad date!" << endl;
	} while (true);

	/* C++ code
	if (y % 400 == 0) {
		is_leap = ;
	}
	*/

	int mod = 0;
	int num_days_in_year = 0;

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
		MOV EDX
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



	}

	system("pause");

	return 0;
}