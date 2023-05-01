#include "stdafx.h"
#include "Base.h"

void Func(int x)
{
	printf("\n입력된 숫자 : %d\n", x);
	return x;
}

void Base()
{
	printf("Hello world\n");

	int a = 0;
	printf("숫자를 입력하시오.\n: ");

	scanf("%d", &a);

	Func(a);
}