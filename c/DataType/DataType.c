#include "stdafx.h"
#include <limits.h>
#include <float.h>
#include "DataType.h"

void DataType()
{
//	DataSize();
//	DataRange();
	DataFlow();
}

void DataSize()
{
	char ch;	// 선언
	ch = 'A';	// 변수의 초기화
	// 변수의 선언과 동시에 초기화
//	char ch = 'A';

	short shortNum = 10;		// 2Byte
	int integerNum = 20;		// 4Byte 정수형
	long longNum = 30;			// 4Byte
	long long longLongNum = 40;	// 8Byte

	float fltNum = 0.1f;		// 4Byte 실수형, float형은 실수 뒤에 f를 붙여서 표현
	double dblNum = 10.2;		// 8Byte

	// 언어, 컴파일러, 플랫폼(x64, x86), 절대적인 수치(Byte)가 아니다
	// short <= int <= long <= long long, 변하지 않는 공식

	// 형식 지정자, 서식문자
	printf("===== 문자형(정수형) 출력 =====\n");
	printf("Char (%llu) : %c\n\n", sizeof(ch), ch);
	// %llu 와 sizeof(ch)이 대응된다. 콤마 하나당 뒤에 변수 한개
	// ll : longlong, u : unsigned -> 부호가 없는 8Byte
	// signed -> 부호가 있는
	// unsigned -> 부호가 없는
	// sizeof(자료형, 변수) -> 자료형 또는 변수의 크기를 나타낸다.(Byte 단위)
	// %c는 character로 형태로 출력, 문자형 또는 정수형을 출력할 수 있다.
	// %d(decimal, 소수 또는 십진법) 10진수 정수형(부호가 있는)
	/*
	﻿형식 지정자
	%c : 문자 표현, char
	%s : 문자열 표현, char*﻿

	%hd : 10진수 정수(2Byte) 표현, short형과 대응
	%d : 10진수 정수(4Byte) 표현, int형과 대응
	%ld : 10진수 정수(8Byte) 표현, long형과 대응
	%lld : 10진수 정수(8Byte) 표현, long long형과 대응
	%u : 부호없는 10진수(4Byte) 표현, unsigned int형과 대응
	%lu : 부호없는 10진수(8Byte) 표현, unsigned long형과 대응
	%llu : 부호없는 10진수(8Byte) 표현, unsigned long long형과 대응
	%o : 8진수 표현, int형과 대응
	%x : 16진수 표현, int형과 대응
	
	%f : 실수형(4Byte) 표현, float형과 대응
	%lf : 실수형(8Byte) 표현, double형과 대응

	%p : 주소값 표현, void*형과 대응	
	*/
	printf("\n===== 정수형 출력 =====\n");
	printf("Short (%llu) : %hd\n", sizeof(shortNum), shortNum);
	printf("Int (%llu) : %d\n", sizeof(integerNum), integerNum);
	printf("Long (%llu) : %ld\n", sizeof(longNum), longNum);
	printf("Long Long (%llu) : %lld\n\n", sizeof(longLongNum), longLongNum);

	printf("===== 실수형 출력 =====\n");
	printf("Float (%llu) : %.15f\n", sizeof(fltNum), fltNum);
	printf("Double (%llu) : %lf\n\n", sizeof(dblNum), dblNum);
	// %와 f사이에 .숫자를 넣으면 숫자만큼 소수점이 출력된다.

	/*
	const(constant : 변한없는) 키워드
	변수의 상수화
	수정할 수 없게된다.
	*/
	const int num = 2;
//	num = 3;	// 오류, '식이 수정할 수 있는 lvalue여야 합니다.'

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

	printf("float의 범위 : %f ~ %f ~ %f\n", -FLT_MAX, FLT_MIN, FLT_MAX);			// FLT_MIN : 0에 가까운 수(0이 아니다)
	printf("double의 범위 : %lf ~ %lf ~ %lf\n\n", -DBL_MAX, DBL_MIN, DBL_MAX);	// DBL_MIN : 0에 가까운 수(0이 아니다)
}

void DataFlow()
{
	/*
	언더플로우(underflow)
	메모리 공간의 최소보다 작은값을 입력할 경우, 최대값이되는 현상
	*/
	char num = -129;
	printf("UnderFlow : %d\n\n", num);

	/*
	오버플로우(overflow)
	메모리 공간의 최대보다 큰값을 입력할 경우, 최소값이되는 현상﻿
	*/
	char num1 = 128;
	printf("OverFlow : %d", num1);
}
