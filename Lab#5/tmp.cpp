#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

	int a = -10;
	int res = 0;

	__asm {
		MOV EAX, 50
		MOV res, EAX
	}

	cout << res << endl;

	return 0;
}