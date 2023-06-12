#include "stdafx.h"
#include <limits.h>
#include <float.h>

void C02()
{
//	DataSize();
//	DataRange();
	DataFlow();
}

void DataSize()
{
	/*
	Data : 자료
	프로그램의 자료
	DataType : 자료형(태)
	컴퓨터에게 데이터를 해석하는 방법을 알려주는 것.
	컴퓨터
	데이터를 연산하고 저장하는 기계 장치
	연산 -> CPU(중앙처리장치) : 똑똑이들 소수정예, 쿼드코어 -> 머리 4개, 성능이 좋다.
		-> GPU(그래픽처리장치) : 덜똑똑이들 머리가 많다.

	GPU가 나오게된 배경
	수많은 픽셀과 FPS로 많은 연산이 필요하기 때문이다.

	저장 -> SSD, HDD : 보조기억장치(반영구적)

	RAM(Random Access Memory) : 주기억장치(휘발성)
		임의 접근 기억 장치

	램공간
		1Byte -> 8bit
		1bit 0또는 1
		1Byte 크기 2^8 = 256
	*/

	/*
	코딩 컨벤션(관례)
	표기법
	카멜 표기법(camelCase) -> dataSize, integerNum
	첫번째 단어 제외, 단어의 앞 글자를 대문자로 쓴다.
	파스칼 표기법(PascalCase) -> DataSize, IntegerNum, 파스칼 언어가 나올때 표기법으로 사용했었다.
	첫번째 단어 포함, 단어의 앞 글자를 대문자로 쓴다.
	스네이크 표기법(snake_case) -> data_size, int_num
	단어 사이사이에 언더스코어를 넣는다.

	헝가리안 표기법 -> fnDataSize, int, nNum
	MS 개발자가 처음 고안한 표기법이지만 자료형이 바뀌면 변수이름을 다 바꿔야하기 때문에 Ms공식입장도 추천하지 않는다.

	예.
	변수 이름 -> 카멜
	함수 이름, 클래스 이름, 파일 -> 파스칼
	매크로 -> 대문자 스네이크, #define SAFE_DELETE

	중요. 일관성있게 표기해야한다.
	*/

	/*
	변수의 선언
	변할 수 있는 자료
	자료형 + 변수이름;
	*/
	// 문자형(정수형)은 1Byte, 한글은 2Byte

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
	// limits 헤더를 포함시켜 자료형의 범위를 쉽게 사용할 수 있다.
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
	메모리 공간의 최소보다 작은값을 입력할 경우, 최댓값이되는 현상
	*/
	char num = -129;
	printf("UnderFlow : %d\n\n", num);

	/*
	오버플로우(overflow)
	메모리 공간의 최대보다 큰값을 입력할 경우, 최솟값이되는 현상﻿
	*/
	char num1 = 128;
	printf("OverFlow : %d", num1);
}
