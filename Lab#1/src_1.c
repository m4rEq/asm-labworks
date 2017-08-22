#include <stdio.h>

/*
	Second and Third tasks:
		sum eax, ebx, ecx
		sum eax, ebx and substract the sum and ecx
*/

int main() {

	int result = 0;

	int a, b, c, d;  //32 bit


	printf("=== Sum: (EAX + EBX + ECX) -> EDX ===\n");
	
	printf("Enter a(32bit): ");
	scanf("%d", &a);

	printf("Enter b(32bit): ");
	scanf("%d", &b);	

	printf("Enter c(32bit): ");
	scanf("%d", &c);

	__asm {

		mov eax, a;
		mov ebx, b;
		mov ecx, c;

		add edx, eax;
		add edx, ebx;
		add edx, ecx;

		mov result, edx;
	}

	printf("%d\n", result);

	printf("=== (EAX + EBX) - ECX -> EDX ===\n");
	printf("Enter a(32bit): ");
	scanf("%d", &a);

	printf("Enter b(32bit): ");
	scanf("%d", &b);	

	printf("Enter c(32bit): ");
	scanf("%d", &c);
	printf("%d", c);

	__asm {

		mov eax, a;
		mov ebx, b;
		mov ecx, c;

		add edx, eax;
		add edx, ebx;
		sub edx, ecx;

		mov result, edx;
	}

	printf("%d\n", result);

	return 0;
}