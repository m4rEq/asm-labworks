#include <stdio.h>

int main() {
	
	unsigned short int a_w;	//16bit
	unsigned char b_b;		//8bit

	unsigned char al_part_b, ah_part_b; //8bit 

	printf("0..65_535\n");
	printf("Enter a(unsigned 16bit): ");
	scanf("%hd", &a_w);

	printf("0..255\n");
	printf("Enter b(unsigned 8bit): ");
	scanf("%hhd", &b_b);

	__asm {
		mov ax, a_w;
		mov cl, b_b;

		div cl;

		mov al_part_b, al;
		mov ah_part_b, ah;
	}

	printf("Celoe = %u\n", al_part_b);
	printf("Ostatok = %u\n", ah_part_b);

	return 0;
}