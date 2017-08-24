


#include <iostream>
#include <cstdlib>


using namespace std;

//int main(int argv, char ** argc) {

int main() {

	const double cm_to_inch = 2.54;
	const double hand_to_foot = 3;
	const double inches_to_foot = 12;
	const double cm_to_foot = 30.48;


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
	//double inches = foot / inches_to_foot;
	double inches = foot * inches_to_foot;

	cout << "A piece of length "
		<< m << " meter " 
		<< cm << " centimeter "
		<< mm << " and millimeter = " << endl
		<< foot << " footage" << endl 
		<< inches << " inches." << endl;

	cout << "=====================" << endl;

	__asm {
		
	} 

	system("pause");


	return 0;
}