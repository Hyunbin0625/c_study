#include "stdafx.h"
#include "Base.h"

void Func(int x)
{
	printf("\n�Էµ� ���� : %d\n", x);
	return x;
}

void Base()
{
	printf("Hello world\n");

	int a = 0;
	printf("���ڸ� �Է��Ͻÿ�.\n: ");

	scanf("%d", &a);

	Func(a);
}