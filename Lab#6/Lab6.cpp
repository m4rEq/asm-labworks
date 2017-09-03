#include <iostream>
#include <string>
#include <cmath>

using namespace std;
/*
	���� ������  ���������� �����.
	����� ����� ������ ��������� �
	������ �������� �����.
*/
int main()
{
	char str[100] = "sds s sfdsdsd";// "22 1 333 55555 7777777 22";
									//cout <<  << endl;
									//char s = (char)127;

	int lengthStr = strlen(str) + 1;

	int lengthLongestWord = -1;
	int lengthShortestWord = 1000000;
	int lengthCurrentWord = 0;

	__asm {
		; //������ � ecx ����� ��������
		mov ecx, lengthStr
		; //����� esi ����� �������� ������ � ��������� �������
		mov esi, 0
		; //������ �����
		cycl :
			; //��������� ������� ������
			; //���� �� ����� ������� ��� ����� ������ ������,
			; //��������� � ����� newWord
			cmp str[esi], ' '
			je newWord
			cmp str[esi], '\0'
			je newWord

			jmp endIterWithoutNewWord


			newWord :
				; //���������� ������ �� ����������� �����
				; //������ �������� �����
				mov eax, lengthLongestWord
				cmp lengthCurrentWord, eax
				jg newLongestWord
				; //���������� ������ �� ����������� �����
				; //������ ��������� �����
				mov eax, lengthShortestWord
				cmp lengthCurrentWord, eax
				jl newShortestWord

				jmp endIterWithNewWord

				; //�������������� ����� ������� �����
			newLongestWord :
				mov eax, lengthCurrentWord
				mov lengthLongestWord, eax
				mov lengthCurrentWord, 0
				jmp endIterWithNewWord
				; //�������������� ����� �������� �����
			
			newShortestWord :
				mov eax, lengthCurrentWord
				mov lengthShortestWord, eax
				mov lengthCurrentWord, 0
				jmp endIterWithNewWord
				; //����� �������� ��� ������
			
			endIterWithoutNewWord :
				inc esi
				inc lengthCurrentWord
				jmp enditer
				;// ����� �������� � ����� ������
			
			endIterWithNewWord :
				mov lengthCurrentWord, 0

			inc esi
			jmp enditer

			enditer :
		loop cycl



	}

	cout << "Amount sign of longes word in string: " << lengthLongestWord << endl;
	cout << "Amount sign of shorter word in string: " << lengthShortestWord << endl;
	system("pause");
	return 0;
}