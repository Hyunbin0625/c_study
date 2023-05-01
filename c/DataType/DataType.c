#include "stdafx.h"
#include <limits.h>
#include <float.h>
#include "DataType.h"

void DataType()
{
	DataSize();
//	DataRange();
}

void DataSize()
{
	char ch;	// ����
	ch = 'A';	// ������ �ʱ�ȭ
	// ������ ����� ���ÿ� �ʱ�ȭ
//	char ch1 = 'A';

	// ���, �����Ϸ�, �÷���(x64, x86), �������� ��ġ(Byte)�� �ƴϴ�
	// short <= int <= long <= long long, ������ �ʴ� ����
	/*
	const(sonstant : ���Ѿ���) Ű����
	������ ���ȭ
	������ �� ���Եȴ�.
	*/
	short shortNum = 10;		// 2Byte
	const int integerNum = 20;	// 4Byte ������
	long longNum = 30;			// 4Byte
	long long longLongNum = 40;	// 8Byte
	//	integerNum = 40;

	float fltNum = 0.1f;	// 4Byte �Ǽ���
	double dblNum = 10.2;		// 8Byte
	// �Ǽ� �ڿ� f�� ������ �ٸ� �ڷ����� double, ���´ٸ� float

	// ���� ������, ���Ĺ���
	// -> ���� ����
	printf("===== ������(������) ��� =====\n");
	printf("Char (%llu) : %c\n\n", sizeof(ch), ch);	// ���� ch�� char�� ����Ǿ��� ������ ũ��� 1(Byte)�� char�� ����.
	// %llu �� sizeof(ch)�� �����ȴ�. �޸� �ϳ��� �ڿ� ���� �Ѱ�
	// ll : longlong, u : unsigned -> ��ȣ�� ���� 8Byte
	// signed -> ��ȣ�� �ִ�
	// unsigned -> ��ȣ�� ����
	// sizeof(�ڷ���, ����) -> �ڷ��� Ȥ�� ������ ũ�⸦ ��Ÿ����.(Byte ����)
	// %c�� character�� ���·� ���, character�� ������ �Ǵ� �������̹Ƿ� ���������ε� ����� �����ϴ�.
	// %d -> decimal -> 10���� ������(��ȣ�� �ִ�)

	printf("\n===== ������ ��� =====\n");
	printf("Short (%llu) : %d\n", sizeof(shortNum), shortNum);
	printf("Int (%llu) : %d\n", sizeof(integerNum), integerNum);
	printf("Long (%llu) : %ld\n", sizeof(longNum), longNum);
	printf("Long Long (%llu) : %lld\n\n", sizeof(longLongNum), longLongNum);

	printf("===== �Ǽ��� ��� =====\n");
	printf("Float (%llu) : %.15f\n", sizeof(fltNum), fltNum);
	printf("Double (%llu) : %lf\n\n", sizeof(dblNum), dblNum);
	// %�� f���̿� .���ڸ� ������ ���ڸ�ŭ �Ҽ����� ��µȴ�.
}

void DataRange()
{
	printf("char�� ���� : %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("unsigned char�� ���� : %u ~ %u\n", 0U, UCHAR_MAX);

	printf("short�� ���� : %d ~ %d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short�� ���� : %u ~ %u\n", 0U, USHRT_MAX);

	printf("int�� ���� : %d ~ %d\n", INT_MIN, INT_MAX);
	printf("unsigned int�� ���� : %u ~ %u\n", 0U, UINT_MAX);

	printf("long�� ���� : %d ~ %d\n", LONG_MIN, LONG_MAX);
	printf("unsigned long�� ���� : %u ~ %lu\n", 0U, ULONG_MAX);

	printf("long long�� ���� : %lld ~ %lld\n", LLONG_MIN, LLONG_MAX);
	printf("unsigned long long�� ���� : %u ~ %llu\n", 0U, ULLONG_MAX);

	printf("float�� ���� : %f ~ %f ~ %f\n", -FLT_MAX, FLT_MIN, FLT_MAX);			// FLT_MIN �ִ��� 0�� ����� ��(0�� �ƴϴ�)
	printf("double�� ���� : %lf ~ %lf ~ %lf\n\n", -DBL_MAX, DBL_MIN, DBL_MAX);	// DBL_MIN �ִ��� 0�� ����� ��(0�� �ƴϴ�)
}
