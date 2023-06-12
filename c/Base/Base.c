#include "stdafx.h"
#include "Base.h"

void C01()
{
	Base();
}

void Func(int x);

void Base()
{
	printf("Hello world\n");		// 콘솔창에 Hello world 문장 출력

	int a = 0;						// 정수형을 저장하는 변수, 선언 및 0으로 초기화
	printf("숫자를 입력하시오.\n: ");	// 출력 함수

	scanf("%d", &a);				// 입력 함수

	Func(a);						// 입력 받은 숫자를 인자값으로 Func 함수 호출
}

void Func(int x)
{
	printf("\n입력된 숫자 : %d\n", x);		// 입력받은 숫자를 콘솔창에 출력
	return x;							// 반환형이 void이지만 void 형태로 반환이 가능하다.
}