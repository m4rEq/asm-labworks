int result = 0;

__asm {

	mov eax, 3;   //��������� � eax
	mov ebx, eax; //ebx � eax
	mov eax, 4;   //����� ��������� � eax
	
	add eax, ebx; // eax = eax + ebx 
	sub eax, ebx; // eax = eax - ebx
	
	inc eax; 	  //eax = eax + 1
	dec eax;	  //eax = eax - 1
	
	
}