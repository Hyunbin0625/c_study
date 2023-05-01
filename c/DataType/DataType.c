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
	char ch;	// 선언
	ch = 'A';	// 변수의 초기화
	// 변수의 선언과 동시에 초기화
//	char ch1 = 'A';

	// 언어, 컴파일러, 플레폼(x64, x86), 절대적인 수치(Byte)가 아니다
	// short <= int <= long <= long long, 변하지 않는 공식
	/*
	const(sonstant : 변한없는) 키워드
	변수의 상수화
	수정할 수 없게된다.
	*/
	short shortNum = 10;		// 2Byte
	const int integerNum = 20;	// 4Byte 정수형
	long longNum = 30;			// 4Byte
	long long longLongNum = 40;	// 8Byte
	//	integerNum = 40;

	float fltNum = 0.1f;	// 4Byte 실수형
	double dblNum = 10.2;		// 8Byte
	// 실수 뒤에 f를 안적는 다면 자료형은 double, 적는다면 float

	// 형식 지정자, 서식문자
	// -> 조사 과제
	printf("===== 문자형(정수형) 출력 =====\n");
	printf("Char (%llu) : %c\n\n", sizeof(ch), ch);	// 변수 ch는 char로 선언되었기 때문에 크기는 1(Byte)로 char와 같다.
	// %llu 와 sizeof(ch)이 대응된다. 콤마 하나당 뒤에 변수 한개
	// ll : longlong, u : unsigned -> 부호가 없는 8Byte
	// signed -> 부호가 있는
	// unsigned -> 부호가 없는
	// sizeof(자료형, 변수) -> 자료형 혹은 변수의 크기를 나타낸다.(Byte 단위)
	// %c는 character로 형태로 출력, character는 문자형 또는 정수형이므로 정수형으로도 출력이 가능하다.
	// %d -> decimal -> 10진수 정수형(부호가 있는)

	printf("\n===== 정수형 출력 =====\n");
	printf("Short (%llu) : %d\n", sizeof(shortNum), shortNum);
	printf("Int (%llu) : %d\n", sizeof(integerNum), integerNum);
	printf("Long (%llu) : %ld\n", sizeof(longNum), longNum);
	printf("Long Long (%llu) : %lld\n\n", sizeof(longLongNum), longLongNum);

	printf("===== 실수형 출력 =====\n");
	printf("Float (%llu) : %.15f\n", sizeof(fltNum), fltNum);
	printf("Double (%llu) : %lf\n\n", sizeof(dblNum), dblNum);
	// %와 f사이에 .숫자를 넣으면 숫자만큼 소수점이 출력된다.
}

void DataRange()
{
	printf("char의 범위 : %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("unsigned char의 범위 : %u ~ %u\n", 0U, UCHAR_MAX);

	printf("short의 범위 : %d ~ %d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short의 범위 : %u ~ %u\n", 0U, USHRT_MAX);

	printf("int의 범위 : %d ~ %d\n", INT_MIN, INT_MAX);
	printf("unsigned int의 범위 : %u ~ %u\n", 0U, UINT_MAX);

	printf("long의 범위 : %d ~ %d\n", LONG_MIN, LONG_MAX);
	printf("unsigned long의 범위 : %u ~ %lu\n", 0U, ULONG_MAX);

	printf("long long의 범위 : %lld ~ %lld\n", LLONG_MIN, LLONG_MAX);
	printf("unsigned long long의 범위 : %u ~ %llu\n", 0U, ULLONG_MAX);

	printf("float의 범위 : %f ~ %f ~ %f\n", -FLT_MAX, FLT_MIN, FLT_MAX);			// FLT_MIN 최대한 0에 가까운 수(0이 아니다)
	printf("double의 범위 : %lf ~ %lf ~ %lf\n\n", -DBL_MAX, DBL_MIN, DBL_MAX);	// DBL_MIN 최대한 0에 가까운 수(0이 아니다)
}
