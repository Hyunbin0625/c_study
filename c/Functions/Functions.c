#include "stdafx.h"

void Functions()
{
//  Function();
//  Random();
//  staticGlobal();
    RecuresiveFunction();
}

void Function()
{
    /*
    f(Function)라는 기능에 x를 넣어 y가 출력﻿되는 형태
    int(반환형) GetSumVal(함수 이름)(int(매개변수 자료형)a(매개변수 이름), int b(매개변수))
     
    프로그래밍의 함수 핵심
    분리시켜 그룹화를 할수 있는 기능, 함수를 호출해 코드를 재사용
    
    void -> 공허(비어있다, 없다)
    
    입력, 출력이 있는 함수
    int func1(int a, int b);
    
    입력이 있고, 출력이 없는
    void func2(int a, int b);
    
    입력이 없고, 출력이 있는
    int func3(void);
    
    입력이 없고 출력이 없는 함수
    void func4(void);
    
    ﻿비주얼 스튜디오에서 함수의 선언과 정의
    .h, 헤더파일에 함수를 선언
    .c, 소스파일에 함수를 정의
    
    선언
    반환형 함수이름(매개변수1, 매개변수2, ...);
    
    정의
    반환형 함수이름(매개변수1, 매개변수2, ...)
    {
        함수 몸체
    }
    또는
    반환형 함수이름(매개변수1, 매개변수2, ...) { 함수 몸체 }
    */

    int val1 = 0;
    int val2 = 0;

    char oper = '\0';

    printf("수식 입력 (+, -, *, /) : ");
    scanf("%d %c %d", &val1, &oper, &val2);
    switch (oper)
    {
    case '+':
    {
        int result = GetSumValue(val1, val2);   // val1, val2를 매개변수로 갖는 함수 GetSumVaue()를 호출한다.
        printf("%d + %d = %d\n", val1, val2, result);
        break;
    }
    case '-':
        printf("%d - %d = %d\n", val1, val2, GetSubValue(val1, val2));
        break;
    case '*':
        printf("%d * %d = %d\n", val1, val2, GetMulValue(val1, val2));
        break;
    case '/':
        printf("%d / %d = %f\n", val1, val2, GetDivValue(val1, val2));
        break;
    default:
        printf("잘못된 수식을 입력했습니다.\n");
        break;
    }
}
// 스택프레임에는 매개변수도 쌓인다.
int GetSumValue(int num1, int num2) // 매개변수에는 값이 복사되어 저장된다. val1 != num1
{
    return num1 + num2;
}

int GetSubValue(int num1, int num2)
{
    return num1 - num2;
}

int GetMulValue(int num1, int num2)
{
    return num1 * num2;
}

float GetDivValue(int num1, int num2)   // 반환형 신경쓰기!
{
    return (float)num1 / (float)num2;
}

void Random()
{
    // 시드값을 바꿔 완벽하지 않지만 유사난수를 생성한다.
    // time 함수는 매개변수로 들어온 시간값으로부터 현재까지 흐른시간을 초단위로 8바이트 정수형으로 반환
    // ﻿time() 함수를 사용하기 위해서 time.h 라이브러리를 포함해야 한다.
    srand((unsigned int)time(NULL));   // NULL 포인터 '아무의미 없는'의 주소, unsigned int로 명시적 형변환
    int arr[30] = { 0 };

    for (int i = 0; i < 30; ++i)
    {   
        // ﻿srand(), rand() 함수를 사용하기 위해 stdlib.h 라이브러리를 포함해야 한다.
        arr[i] = rand() % 100;  // 100으로 나눈 나머지는 0~99 사이의 숫자만 나온다. 1 ~ 100의 범위를 얻고 싶다면 +1을 해주면 된다.
        printf("%d\n", arr[i]); 
    }
    /*
    ﻿rand() 함수는 랜덤한 숫자를 반환한다.
    0~32767, seed에 따라 어떤 순서대로 숫자가 나올지 결정되어 있다.

    같은 수로 고정되어있는 경우 계속 같은 순서와 수가 출력된다.
    */
}

// ﻿링커 단계 전 컴파일러가 다른 파일에 선언된 전역 변수가 있는지 모르기 때문에 사용하면 오류가 뜬다.
extern int globalVal;           // ﻿extern 키워드 : 외부에 있는 변수를 보증한다. 링커 단계에서 컴파일러가 존재를 알게 되고 접근할 수 있다.
static int staticGlobalVal = 0; // 정적 전역 변수 : 한개의 컴파일 단위, 해당 소스 헤더에서만 사용 가능하다. 다른 파일에서 접근할 수 없다.

void staticGlobal()
{
    int value = 0;
    staticGlobalVal = 20;

    do
    {
        printf("정수 입력 : ");
        scanf("%d", &value);

        IncreaseValue(value);
    } while (value != 0);
}

void IncreaseValue(int val)
{
    int num = 0;


    // 정적 지역 변수
    // Data 영역에 선언되며, 프로그램의 라이프사이클과 동일하다.
    // 접근에 대해서는 지역 변수와 같지만, 스택프레임이 사라지지만 데이터 영역에 선언되었으므로 값이 유지된다.
    static int staticNum = 0;

    num += val;
    staticNum += val;
    globalVal += val;
    staticGlobalVal += val;

    system("cls");  // stdlib.h 에 포함된 함수, 콘솔창 전체를 지워준다. 커맨드 문자열이 필요하다.
    //   system("pause");    // 일시 정지

    printf("===== 누적 결과 =====\n");
    printf("일반 지역 변수 : %d\n", num);
    printf("정적 지역 변수 : %d\n", staticNum);
    printf("일반 전역 변수 : %d\n", globalVal);
    printf("정적 전역 변수 : %d\n", staticGlobalVal);
}

/*﻿
    재귀함수 : 자기 자신의 함수를 호출, 스택 공간에 계속 쌓인다.
    반드시 꼬리재귀를 만들어서 탈출할 수 있도록해야한다.
    스택공간이 넘칠경우 스택 오버플로우가 발생한다.
    비주얼 스튜디오 가상 메모리 공간의 스택 영역의 크기는 1MB﻿
*/
void RecuresiveFunction()
{
    int value = 0;

    printf("정수 입력 : ");
    scanf("%d", &value);

    printf("%d! = %d\n", value, GetFactorial(value));
}

int GetFactorial(int val)   // 특정 상황에서 사용하면 생산성을 높일 수 있다.
{
    if (val != 0)
    {
        return  val * GetFactorial(val - 1);
    }
}
