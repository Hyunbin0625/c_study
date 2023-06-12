#include "stdafx.h"

void C03()
{
	Operator();
}

void Operator()
{
	int num1 = 8;
	int num2 = 6;

	//	printf("정수 (2개) 입력 : ");		// 디버그 콘솔창에 출력
	//	// & -> 앰퍼샌드, 주소연산자, &변수이름 = 해당 변수가 저장된 곳의ㅁㅁㅁ 시작점의 주소 반환
	//	scanf("%d %d", &num1, &num2);	// 디버그 콘솔창에서 입력

	printf("%d %d\n", num1, num2);

	printf("\n===== 산술 연산자 결과 =====\n");
	printf("%d + %d = %d\n", num1, num2, num1 + num2);			// 더하기
	printf("%d - %d = %d\n", num1, num2, num1 - num2);			// 빼기
	printf("%d * %d = %d\n", num1, num2, num1 * num2);			// 곱하기
	printf("%d / %d = %f\n", num1, num2, num1 / (float)num2);	// 나누기
	printf("%d %% %d = %d\n\n", num1, num2, num1 % num2);		// 나머지

	printf("===== 비교 연산자 결과 =====\n");
	printf("%d == %d = %d\n", num1, num2, num1 == num2);	// 같다.
	printf("%d != %d = %d\n", num1, num2, num1 != num2);	// 같지 않다.
	printf("%d < %d = %d\n", num1, num2, num1 < num2);		// 작다.
	printf("%d > %d = %d\n", num1, num2, num1 > num2);		// 크다.
	printf("%d <= %d = %d\n", num1, num2, num1 <= num2);	// 작거나 같다.
	printf("%d >= %d = %d\n\n", num1, num2, num1 >= num2);	// 크거나 같다.

	printf("===== 대입 연산자 결과 =====\n");
	printf("%d = %d", num1 = 8, num2 = 6); num1 = num2;		// ﻿좌측 변수에 우측 변수를 대입
	printf(", %d\n", num1);
	printf("%d += %d", num1 = 8, num2 = 6); num1 += num2;	// ﻿좌측 변수와 우측 변수의 합을 좌측 변수에 할당
	printf(", %d\n", num1);
	printf("%d -= %d", num1 = 8, num2 = 6); num1 -= num2;	// ﻿좌측 변수에 우측 변수를 뺀 후, 좌측 변수에 할당
	printf(", %d\n", num1);
	printf("%d *= %d", num1 = 8, num2 = 6); num1 *= num2;	// ﻿좌측 변수에 우측 변수를 곱한 후, 좌측 변수에 할당
	printf(", %d\n", num1);
	printf("%d /= %d", num1 = 8, num2 = 6); num1 /= num2;	// ﻿좌측 변수에 우측 변수를 나눈 후, 좌측 변수에 할당
	printf(", %d\n", num1);
	printf("%d %%= %d", num1 = 8, num2 = 6); num1 %= num2;	// ﻿좌측 변수에 우측 변수를 나눈 후, 나머지값을 좌측 변수에 할당
	printf(", %d\n", num1);
	printf("%d <<= %d", num1 = 8, num2 = 6); num1 <<= num2;	// ﻿좌측 변수의 비트를 우측 변수만큼 좌측으로 이동한 후, 좌측 변수에 할당
	printf(", %d\n", num1);
	printf("%d >>= %d", num1 = 8, num2 = 6); num1 >>= num2;	// ﻿좌측 변수의 비트를 우측 변수만큼 우측으로 이동한 후, 좌측 변수에 할당
	printf(", %d\n", num1);
	printf("%d &= %d", num1 = 8, num2 = 6); num1 &= num2;	// ﻿좌측 변수와 우측 변수의 논리식이 모두 참이면 좌측 변수에 true를 할당, 그 외에는 false을 할당
	printf(", %d\n", num1);
	printf("%d |= %d", num1 = 8, num2 = 6); num1 |= num2;	// ﻿좌측 변수와 우측 변수의 논리식이 하나라도 참이면 좌측 변수에 true를 할당, 그 외에는 false을 할당
	printf(", %d\n", num1);
	printf("%d ^= %d", num1 = 8, num2 = 6); num1 ^= num2;	// ﻿좌측 변수와 우측 변수의 논리식이 서로 다르면 좌측 변수에 true를 할당, 그 외에는 false을 할당
	printf(", %d\n\n", num1);

	printf("===== 논리 연산자 결과 =====\n");
	printf("%d && %d = %d\n", num1, num2, num1 && num2);	// ﻿논리식이 모두 참이면 1을 반환(AND 연산)
	printf("%d || %d = %d\n", num1, num2, num1 || num2);	// ﻿논리식이 모두 참이면 1을 반환(OR 연산)
	printf("!%d = %d\n\n", num1, !num1);					// ﻿논리식이 모두 참이면 1을 반환(NOT 연산)

	printf("===== 비트 연산자 결과 =====\n");
	printf("%d & %d = %d\n", num1, num2, num1 & num2);	// 대응되는 비트가 모두 참이면 1을 반환
	printf("%d | %d = %d\n", num1, num2, num1 | num2);	// 대응되는 비트 중 하나라도 참이면 1을 반환
	printf("%d ^ %d = %d\n", num1, num2, num1 ^ num2);	// 대응되는 비트가 서로 다르면 1을 반환
	printf("~%d = %d\n", num1, ~num1);	// 비트가 1이면 0, 0이면 1로 반전
	printf("%d << 2 = %d\n", num1, num1 << 2);	// 지정한 수만큼 비트들을 좌측으로 이동하며 0을 채운다.(﻿부호 비트 유지)
	printf("%d >> 2 = %d\n\n", num2, num2 >> 2);	// 지정한 수만큼 비트들을 우측으로 이동하며 0을 채운다.(﻿부호 비트 유지)

	printf("===== 증감 연산자 결과 =====\n");
	printf("++%d, --%d\n", ++num1, --num2);			// 값이 참조되기 전에 증가, 감소
	printf("%d++, %d--\n", num1++, num2--);			// 값이 참조된 후, 증가, 감소
	printf("증감 연산 후 : %d, %d\n\n", num1, num2);

	printf("===== 조건 연산자 결과 =====\n");
	printf("(%d < %d) ? : = %d\n\n", num1, num2, (num1 < num2) ? num1 : num2);	// 조건식이 참이라면 뒤에 있는 첫번째 피연산자 반환, 거짓일면 두번째 피연산자 반환
}