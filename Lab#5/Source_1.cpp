#include <iostream>
#include <string>
#include<cmath>

using namespace std;
/*Дана строка  содержащая текст. 
Найти длину самого короткого и самого длинного слова.*/
int main()
{
	char str[100] = "sds s sfdsdsd";// "22 1 333 55555 7777777 22";
	//cout <<  << endl;
	//char s = (char)127;

	int lengthStr = strlen(str)+1;
	
	int lengthLongestWord = -1;
	int lengthShortestWord = 1000000;
	int lengthCurrentWord = 0;

	__asm{
		; заношу в ecx число итераций
		mov ecx, lengthStr
		; через esi будем получать доступ к элементам массива
		mov esi, 0
		;начало цикла
		cycl:
		; проверяем текущий символ
			; если он равен пробелу или знаку начала строки,
			; переходим к метке newWord
			cmp str[esi], ' '
			je newWord
			cmp str[esi], '\0'
			je newWord

			jmp enditerwithoutnewword
			
			
			newWord :
				; определяем длинее ли проверяемое слово
				; самого длинного слова
				mov eax, lengthLongestWord
				cmp lengthCurrentWord, eax
				jg newLongestWord
				; определяем короче ли проверяемое слово
				; самого короткого слова
				mov eax, lengthShortestWord
				cmp lengthCurrentWord, eax
				jl newShortestWord

				jmp enditerwithnewword

				; переопределяем самое длинное слово
				newLongestWord :
					mov eax, lengthCurrentWord
					mov lengthLongestWord, eax
					mov lengthCurrentWord, 0
					jmp enditerwithnewword
				; переопределяем самое короткое слово
				newShortestWord :
					mov eax, lengthCurrentWord
						mov lengthShortestWord, eax
						mov lengthCurrentWord, 0
						jmp enditerwithnewword
			;конец итерации без словом
			enditerwithoutnewword :
				inc esi
				inc lengthCurrentWord
				jmp enditer
			; конец итерации с новым словом
			enditerwithnewword:		
				mov lengthCurrentWord, 0

				inc esi
				jmp enditer
			
			enditer:
		loop cycl
			
			
		
	}
	
	cout << lengthLongestWord << endl;
	cout << lengthShortestWord << endl;
	system("pause");
	return 0;
}