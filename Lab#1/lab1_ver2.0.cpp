// ConsoleApplication1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"


int main()
{

	unsigned short m1, m2;
	short m3, m4;
	int ra, rb, rc, a, b, n;
	unsigned int ua, ub, c, d;

	struct vector
	{
		int a, b;
	} v1, v2, v3, v4;

	bool flag = false;
	while (!flag)
	{
		system("cls");
		printf("������� ����� �������:\r\n");
		printf("1 - �������� � ��������� �����\r\n");
		printf("2 - �������� � ��������� ��������\r\n");
		printf("3 - ����������� ���������\r\n");
		printf("4 - �������� ���������\r\n");
		printf("5 - ����������� �������\r\n");
		printf("6 - �������� �������\r\n");
		printf("0 - �����\r\n");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			system("cls");
			printf("������� 3 �����\r\n");
			scanf_s("%d %d %d", &ra, &rb, &rc);
			_asm
			{
				//���������� ���������
				mov eax, ra;
				mov ebx, rb;
				mov ecx, rc;
				//������� 2
				mov edx, eax;
				add edx, ebx;
				add edx, ecx;
				mov a, edx;
				//������� 3
				mov edx, eax;
				add edx, ebx;
				sub edx, ecx;
				mov b, edx;
				//mov ecx, 0fffh;
			}
			printf("��������� ��������: %d\r\n��������� ���������: %d\r\n", a, b);
			system("pause");
			break;
		case 2:
			system("cls");
			printf("������� 2 �������\r\n");
			scanf_s("%d %d %d %d", &v1.a, &v1.b, &v2.a, &v2.b);
			_asm
			{
				//������� 4
				mov edx, v1.a;
				add edx, v2.a;
				mov v3.a, edx;
				mov edx, v1.b;
				add edx, v2.b;
				mov v3.b, edx;
				//������� 5
				mov edx, v1.a;
				sub edx, v2.a;
				mov v4.a, edx;
				mov edx, v1.b;
				sub edx, v2.b;
				mov v4.b, edx;
			}
			printf("����� ��������: (%d, %d)\r\n", v3.a, v3.b);
			printf("�������� ��������: (%d, %d)\r\n", v4.a, v4.b);
			system("pause");
			break;
		case 3:
			system("cls");
			printf("������� 2 ����������� ���������\r\n");
			scanf_s("%hu %hu", &m1, &m2);
			_asm {
				//������� 6
				//����������� ���������
				//mov edx, 0; //�������� ������� �����
				mov eax, 0;
				mov ax, m1;
				mov bx, m2;
				mul bx; //dx:ax = ax*bx
				shl edx, 16; //���������� ������� �����
				add eax, edx;
				mov c, eax;
			}
			printf("���������: %u\r\n", c);
			system("pause");
			break;
		case 4:
			system("cls");
			printf("������� 2 �������� ���������\r\n");
			scanf_s("%hd %hd", &m3, &m4);
			_asm {
				//�������� ���������
				//mov edx, 0; //�������� ������� �����
				mov eax, 0;
				mov ax, m3;
				mov bx, m4;
				imul bx; //dx:ax = ax*bx
				shl edx, 16; //���������� ������� �����
				add eax, edx;
				mov a, eax;
			}
			printf("���������: %d\r\n", a);
			system("pause");
			break;
		case 5:
			system("cls");
			printf("������� ����������� ������� � ��������\r\n");
			scanf_s("%u %u", &ua, &ub);
			_asm {
				//����������� �������
				mov edx, 0; //���������� eax �� edx:eax
				mov eax, ua;
				mov ebx, ub;
				div ebx; //eax = eax/ebx, edx = eax%ebx
				mov c, eax;
				mov d, edx;
			}
			printf("�������: %u, �������: %u\r\n", c, d);
			system("pause");
			break;
		case 6:
			system("cls");
			printf("������� �������� ������� � ��������\r\n");
			scanf_s("%d %d", &ra, &rb);
			_asm {
				//�������� �������
				mov eax, ra;
				cdq; //���������� eax �� edx:eax
				mov ebx, rb;
				idiv ebx; //eax = eax/ebx, edx = eax%ebx
				mov a, eax;
				mov b, edx;
			}
			printf("�������: %d, �������: %d\r\n", a, b);
			system("pause");
			break;
		case 0:
			flag = true;
			break;
		default:
			break;
		}
	}
    return 0;
}

