#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "sum.h"

int main( void )
{
	int a;
	int b;
	int result;
	int status;

	a = 10;
	b = 1;

	// использование scanf
	status = 1;
	do {
		fflush(stdin);
		status = scanf("%d", &a);
	} while (!status);
	
	__asm					// начало ASM кода
	{
		mov  eax, a			// Поместить а в EAX
		push eax			// Положить EAX в стек
		mov  eax, b			// Поместить b в EAX
		push eax            // Положить EAX в стек
		call sum			// вызвать ф-цию sum

		mov result, eax		// сохранить результат в result
		pop  ebx			// очистить стек с помощью ebx 
		pop  ebx
		pop  ebx
	} // end of ASM code

	printf("%d\n", result);

	return 0;
}
