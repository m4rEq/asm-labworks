


#include <iostream>
#include <cstdlib>


using namespace std;

//int main(int argv, char ** argc) {

int main() {

	const double cm_to_inch = 2.54;
	const double hand_to_foot = 3;
	const double inches_to_foot = 12;
	const double cm_to_foot = 30.48;

	const double cm_to_m = 100;
	const double mm_to_cm = 10;


	double mm;
	double cm;
	double m;

	cout << "Enter m: ";
	cin >> m;

	cout << "Enter cm: ";
	cin >> cm;

	cout << "Enter mm: ";
	cin >> mm;

	double all_to_cm = m*100 + cm + mm / 10;

	double foot = all_to_cm / cm_to_foot;
	double inches = foot * inches_to_foot;


	cout << "A piece of length "
		<< m << " meter " 
		<< cm << " centimeter "
		<< mm << " and millimeter = " << endl
		<< foot << " footage" << endl 
		<< inches << " inches." << endl;

	cout << "=====================" << endl;


	double tmp1 = 0;
	double tmp2 = 0;
	double asm_foot = 0;
	double asm_inches = 0;


	__asm {
		FINIT; // fpu initialize
		FLD m;
		FMUL cm_to_m;
		FSTP tmp1;
		
		FLD mm;
		FDIV mm_to_cm;
		FSTP tmp2;

		FLD cm;
		FADD tmp1;
		FADD tmp2;
		FDIV cm_to_foot;

		FST asm_foot;

		FMUL inches_to_foot;
		FSTP asm_inches;

	} 

	cout << "ASM footage: " << asm_foot << endl;
	cout << "ASM inches: " << asm_inches << endl;

	system("pause");


	return 0;
}