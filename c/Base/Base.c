#include "stdafx.h"
#include "Base.h"

void C01()
{
	Base();
}

void Func(int x);

void Base()
{
	printf("Hello world\n");		// �ܼ�â�� Hello world ���� ���

	int a = 0;						// �������� �����ϴ� ����, ���� �� 0���� �ʱ�ȭ
	printf("���ڸ� �Է��Ͻÿ�.\n: ");	// ��� �Լ�

	scanf("%d", &a);				// �Է� �Լ�

	Func(a);						// �Է� ���� ���ڸ� ���ڰ����� Func �Լ� ȣ��
}

void Func(int x)
{
	printf("\n�Էµ� ���� : %d\n", x);		// �Է¹��� ���ڸ� �ܼ�â�� ���
	return x;							// ��ȯ���� void������ void ���·� ��ȯ�� �����ϴ�.
}