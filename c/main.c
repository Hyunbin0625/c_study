#include "stdafx.h"


int globalVal = 30;	// 전역 변수를 남발을 하면, Data 영역과 이름을 다 차지하므로 여러문제가 생길 수 있다, 정말로 필요한 경우 사용

// 프로그램 실행 시, 운영체제에 의해서 처음 호출되는 함수(메인 함수)
int main()
{
//	Base();	// 메인 함수에서 Base 함수를 호출해 콘솔창 출력
//	DataType();
//	Operator();
//	Conditional();
//	Loop();
//	Arrays();
//	Functions();
	﻿UserDefinedTypes();

	return 0;	// 프로그램이 잘 종료되었는지 check하기 위해(잘 종료 되었다면 0출력)
}