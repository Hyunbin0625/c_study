#include "stdafx.h"
#include "Base.h"

int Func(int x)
{
	return x;
}

void Base()
{
	printf("Hello world\n");

	int a = Func(10);
	printf("%d\n", a);
}

