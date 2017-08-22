#include <stdio.h>

/*
	Fourth and Fifth tasks:
		sum two vectors
		sub two vectors
*/

struct vec {
	int x, y;
};

int main() {

	int a1, a2, b1, b2;  //32 bit
	int res_x, res_y; 	 //32 bit

	struct vec vec1;
	struct vec vec2;

	printf("=== Sum two vectors ===\n");
	printf("Enter a1(sign 32bit): ");
	scanf("%d", &a1);

	printf("Enter a2(sign 32bit): ");
	scanf("%d", &a2);	

	printf("Enter b1(sign 32bit): ");
	scanf("%d", &b1);

	printf("Enter b2(sign 32bit): ");
	scanf("%d", &b2);

	vec1.x = a1;
	vec1.y = a2;

	vec2.x = b1;
	vec2.y = b2;

	__asm {
		mov eax, vec1.x;
		mov ebx, vec1.y;

		mov ecx, vec2.x;
		mov edx, vec2.y;

		add eax, ecx;
		add ebx, edx;

		mov res_x, eax;
		mov res_y, ebx;
	}

	printf(
		"vec1{%d, %d} + vec2{%d, %d} = vec{%d, %d}\n\n",
		a1, a2, b1, b2, res_x, res_y
	);

	printf("=== Sub two vectors ===\n");
	printf("Enter a1(sign 32bit): ");
	scanf("%d", &a1);

	printf("Enter a2(sign 32bit): ");
	scanf("%d", &a2);	

	printf("Enter b1(sign 32bit): ");
	scanf("%d", &b1);

	printf("Enter b2(sign 32bit): ");
	scanf("%d", &b2);

	vec1.x = a1;
	vec1.y = a2;

	vec2.x = b1;
	vec2.y = b2;

	__asm {
		mov eax, vec1.x;
		mov ebx, vec1.y;

		mov ecx, vec2.x;
		mov edx, vec2.y;

		sub eax, ecx;
		sub ebx, edx;

		mov res_x, eax;
		mov res_y, ebx;
	}

	printf(
		"vec1{%d, %d} - vec2{%d, %d} = vec{%d, %d}\n",
		a1, a2, b1, b2, res_x, res_y
	);


	return 0;
}