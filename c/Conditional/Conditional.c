#include "stdafx.h"
#include "Conditional.h"

void Conditional()
{
//  If();
    Switch();
}
/*﻿
c언어에서 0은 false(거짓)로
0이 아닌 나머지 값은 모두 true(참)로 인식한다.﻿
*/

void If()
{
    int num1 = 0;   // 숫자를 받을 정수형 변수
    int num2 = 0;   // 숫자를 받을 정수형 변수

    char oper = '\0';   // 산술 연산자를 받을 문자형 변수

    printf("수식 입력 (+, -, *, /) : ");      // 출력 함수
    scanf("%d %c %d", &num1, &oper, &num2); // 입력 함수

    if (oper == '+')    // ﻿조건식의 결과에 따라 실행문이 실행된다. 조건식이 true일 경우 실행, false일 경우 실행하지 않는다.
    {
        printf("%d + %d = %d\n", num1, num2, num1 + num2);  // 산술 연산자를 사용해 콘솔창에서 입력받은 두 수의 합을 출력
    }
    else if (oper == '-')   // ﻿앞 if문이 false일 경우 다음 else if문이 실행되며, else if문에도 조건식이 있기 때문에 조건식에 따라 실행문이 실행된다.
    {
        printf("%d - %d = %d\n", num1, num2, num1 - num2);  // 산술 연산자를 사용해 콘솔창에서 입력받은 두 수끼리 뺀값을 출력
    }
    else if (oper == '*')
    {
        printf("%d * %d = %d\n", num1, num2, num1 * num2);  // 산술 연산자를 사용해 콘솔창에서 입력받은 두 수를 곱한 값을 출력
    }
    else if (oper == '/')
    {
        printf("%d / %d = %f\n", num1, num2, num1 / (float)num2);  // 산술 연산자를 사용해 콘솔창에서 입력받은 두 수끼리 나눈값을 출력
    }
    else            // ﻿앞 if문 또는 else if문이 false일 경우 else문이 실행된다.
    {
        printf("잘못된 수식을 입력했습니다.\n");    // 변수 oper이 산술 연산자를 담고 있지 않은 경우
    }
}

void Switch()
{
    int num1 = 0;   // 숫자를 받을 정수형 변수
    int num2 = 0;   // 숫자를 받을 정수형 변수

    char oper = '\0';   // 산술 연산자를 받을 문자형 변수

    printf("수식 입력 (+, -, *, /) : ");      // 출력 함수
    scanf("%d %c %d", &num1, &oper, &num2); // 입력 함수

    switch (oper)   // 정수, 문자, 열거형(사실상 정수형만)
    {
    case '+':   // + == (int)43
    {
        int a = 10; // case 안에서 선언할때 중괄호로 묶어야한다.
        printf("%d + %d = %d\n", num1, num2, num1 + num2);
        break;  // 다음 case를 실행하지 못하기 위해서(switch문, 반복문)
    }
    case '-':   // - == (int)45
        printf("%d - %d = %d\n", num1, num2, num1 - num2);
        break;
    case '*':   // * == (int)42
        printf("%d * %d = %d\n", num1, num2, num1 * num2);
        break;
    case '/':   // * == (int)47
        printf("%d / %d = %f\n", num1, num2, (float)num1 / (float)num2);
        break;
    default:    // 모든 case가 거짓일때 출력
        printf("잘못된 수식을 입력했습니다.\n");
        break;
    }
}