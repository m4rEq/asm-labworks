#include <stdio.h>

/*
	Signed multiplication 
*/

int main() {

	//First part
	short int result;	//16bit
	char a_b, b_b;		//8bit

	printf("-128..127\n");
	printf("Enter a(sign 8bit): ");
	scanf("%hhd", &a_b);

	printf("Enter b(sign 8bit): ");
	scanf("%hhd", &b_b);

	__asm {
		mov al, a_b;	
		mov bl, b_b;	

		imul bl;

		mov result, ax;
	}

	printf("%d\n\n", result);

	//Second part
	short int dx_part;	//16bit
	short int ax_part;	//16bit

	int res;			//32bit

	short int a_w, b_w;//16bit

	printf("Multiply max(16bit * 16bit) = 16bit:16bit\n");
	printf("-32_768..32_767\n");
	printf("Enter a(sign 16bit): ");
	scanf("%hd", &a_w);

	printf("Enter b(sign 16bit): ");
	scanf("%hd", &b_w);

	__asm {
		mov ax, a_w;
		mov bx, b_w;
		mov dx, 0;

		imul bx;

		mov dx_part, dx;
		mov ax_part, ax;
	}

	res = dx_part;
	res <<= 16;
	res += ax_part;
	
	printf("Result = %d\n", res);

	return 0;
}