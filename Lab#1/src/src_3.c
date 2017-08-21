#include <stdio.h>

/*
	Unsigned multiplication:
		For 8bit  * 8bit
		For 16bit * 16 bit
*/

int main() {

	//First part
	unsigned short int result; 	//16bit
	unsigned char a_b, b_b;		//8bit For al, bl 

	printf("=== Multiply max(8bit * 8bit) = 16bit ===\n");
	printf("0..255\n");
	printf("Enter a(unsign 8bit): ");
	scanf("%hhd", &a_b);

	printf("Enter b(unsign 8bit): ");
	scanf("%hhd", &b_b);

	__asm {
		mov al, a_b;	
		mov bl, b_b;	

		mul bl;

		mov result, ax;
	}

	printf("Result = %d\n\n", result);

	//Second part
	unsigned short int dx_part;	//16bit
	unsigned short int ax_part;	//16bit

	unsigned int res;			//32bit

	unsigned short int a_w, b_w;//16bit

	printf("Multiply max(16bit * 16bit) = 16bit:16bit\n");
	printf("0..65_535\n");
	printf("Enter a(unsign 16bit): ");
	scanf("%hd", &a_w);

	printf("Enter b(unsign 16bit): ");
	scanf("%hd", &b_w);

	__asm {
		mov ax, a_w;
		mov bx, b_w;

		mul bx;

		mov dx_part, dx;
		mov ax_part, ax;
	}

	res = dx_part;
	res <<= 16;
	res += ax_part;
	
	printf("Result = %u\n", res);
	
	return 0;
}