#include "stdafx.h"

void C09()
{
//	Pointer();
//	InitializeArray();
	PointerToPointer();
}

void Pointer()
{
	/*
	Pointer
	변수나 함수의 주소값을 저장하는 변수
	x64 : 8byte, x86 : 4byte

	선언 방법
	자료형 뒤에 포인터 연산자(*)를 붙여 선언한다.
	자료형* 변수 이름;

	변수 앞에 & 참조 연산자를 사용해 포인터에 주소값을 저장할 수 있다.
	
	간접 참조
	포인터 변수 앞에 * 포인터 연산자를 붙여 주소를 통해 실제 값에 접근
	*/

	int integerNum = 0;
	float fltNum = 0.0f;
	double dblNum = 0.0f;

	int* integerPtr;
	float* fltPtr;
	double* dblPtr;

	integerPtr = &integerNum;
	fltPtr = &fltNum;
	dblPtr = &dblNum;

	*integerPtr = 10;	// 어떤 주소를 통해서 값에 접근할 수 있다. 변수 앞에 * : 간접 참조, 선언할때 붙이면 int* 포인터 변수
	*fltPtr = 3.14f;
	*dblPtr = 3.141592;

	printf("===== 포인터 간접참조 결과 =====\n");
	printf("Int : %d, %p, Int* : %p\n", integerNum, &integerNum, integerPtr);
	printf("Float : %f, %p, Float* : %p\n", fltNum, &fltNum, fltPtr);
	printf("Double : %lf, %p, Double* : %p\n", dblNum, &dblNum, dblPtr);

	void* ptr = &integerNum;	// ﻿어떤 자료형으로 담을지 모를 경우 void pointer 형태로 선언한 후
	*(int*)ptr = 20;	// ﻿void인 ptr을 명시적 형변환으로 int* 형으로 변환 후 담을 수 있다.

	printf("\n===== void 포인터 간접참조 결과 =====\n");
	printf("Int : %d, %p, Void* : %p\n", integerNum, &integerNum, ptr);

	int num1 = 0;
	int num2 = 0;

	printf("\n정수 2개 입력 : ");
	scanf("%d %d", &num1, &num2);

	printf("\n===== 값 교환 전 ======\n");
	printf("num1 : %d, num2 : %d\n", num1, num2);

	//	Swap(num1, num2);
	SwapByPtr(&num1, &num2);

	printf("\n===== 값 교환 후 ======\n");
	printf("num1 : %d, num2 : %d\n", num1, num2);

	int min = 0, max = 0;

	GetMinMaxValue(num1, num2, &min, &max);
	printf("최솟값 : %d\n", min);
	printf("최댓값 : %d\n\n", max);

	/*
	포인터 변수 상수화
	const에 가까운 것이 상수화가 된다고 생각하면 쉽다.
	
	자료형 상수화
	포인터 변수를 통해 값을 변경하는 것은 불가능하다.
	직접 접근해 값을 변경할 수 있다. 또한 주소를 변경할 수 있다.
	자료형 앞 const﻿
	*/
	const int* constPtr1 = &num1;
	//	*constPtr1 = 10;

	/*
	포인터 상수화
	포인터를 상수화하기 때문에 다른 주소로 변경할 수 없다.
	데이터를 바꾸는 것은 가능하다.
	자료형 뒤 const﻿
	*/
	int* const constPtr2 = &num2;
	//	constPtr2 = &num1;

	/*
	완전한 상수화
	﻿역참조 연산자를 이용해 값을 수정할 수 없고, 자기가 자긴 주소값도 변경할 수도 없다.
	*/
	const int* const constPtr3 = &num1;
	//	constPtr3 = 10;
	//	constPtr3 = &num1;
}

/*
﻿call by value 방식으로 만들 경우 함수 내부에서는 변경되지만, 외부에서는 그대로이다.
*/
void Swap(int a, int b)	// call by Value, 값에 의한 호출
{
	int temp = a;
	a = b;
	b = temp;
}

/*﻿
주소를 받아와 int Pointer에 저장해 값을 바꾸는 경우
역참조 연산자를 사용해 해당 메모리의 값을 바꾼다. 따라서 외부에서도 변경된다.
*/
void SwapByPtr(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*﻿
두 값과 작은 값과 큰 값을 담을 변수의 주소를 받아와
삼항 연산자를 사용해, 작은(큰) 값을 구한 후 역참조 연산자를 사용해 min(max)에 저장﻿
*/
void GetMinMaxValue(int a, int b, int* min, int* max)
{
	*min = (a <= b) ? a : b;
	*max = (a >= b) ? a : b;
}

void InitializeArray()
{
	/*
	배열 포인터(Pointer to Array)
	배열의 시작주소값을 저장할 수 있는 포인터
	
	배열 포인터는 시작점의 주소이며,
	간접 참조로 시작점의 주소에 자료형 크기만큼 더해 각각의 원소방의 값에 접근할 수 있다.
	
	포인터 배열(Array of Pointer)
	주소값들을 저장하는 배열
	
	배열 또한 포인터에 배열의 주소를 담을 수 있다.	
	*/
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[5] = { 1,2,3,4,5 };

	const int size1 = sizeof(arr1) / sizeof(arr1[0]);
	const int size2 = sizeof(arr2) / sizeof(arr2[0]);

	printf("===== 배열 1 원소 (%lld) =====\n", sizeof(arr1));	// 배열의 size는 전체 길이
	for (int i = 0; i < size1; ++i)
		printf("%d, ", arr1[i]);

	//	arr1 = arr2;
	int* const ptr1 = arr2;

	printf("\n\n===== 배열 2 원소 (%lld) =====\n", sizeof(*ptr1));	// 역참조 연산자를 사용해 배열의 크기
	for (int i = 0; i < size2; ++i)
		printf("%d, ", *(ptr1 + i));	// ﻿시작점의 주소에서 한 원소의 크기는 배열의 자료형 크기이며,
	// ﻿시작점의 주소에 배열의 자료형 크기만큼 더하며, 간접참조 연산자를 사용해 값에 접근할 수 있다.

	int arr3[5] = { 0 };
	const int size3 = sizeof(arr3) / sizeof(arr3[0]);

	InitArrayByPtr(arr3, size3);	// arr3을 넣어 시작점의 주소값을 넘긴다.

	printf("\n\n===== 포인터를 통한 배열 초기화 결과 =====\n");
	for (int i = 0; i < size3; ++i)
		printf("%d, ", arr3[i]);
}

/*﻿
int arr[] 와 int* arr는 같다.
둘다 주소값을 받는 매개변수이다.
﻿
출력 결과를 보면 arr[]은 포인터가 아닌 것 같지만, 주소값을 가지고 있다.
하지만 매개변수 배열은 컴파일러가 번역할때 포인터로 변경해서 사용한다.
따라서 매개변수 배열은 포인터이다.

﻿입력받은 배열의 포인터와 사이즈를 가지고 for문을 사용해 배열의 원소들을 초기화하는 함수
*/
void InitArrayByPtr(int arr[], int size)	// 주소값 저장
{
	printf("\n\narr의 주소 : %p", arr);
	printf("\narr의 사이즈 : %lld", sizeof(arr));	// 주소값

	for (int i = 0; i < size; ++i)
		arr[i] = i + 1;
}

void PointerToPointer()
{
	/*
	이중 포인터(Double Pointer)
	포인터의 주소값을 저장하는 포인터
﻿
	포인터 변수도 스택프레임에 저장되며, 메모리 주소가 있다.
	또다른 포인터가 주소를 저장할 수 있다.

	선언 방법
	변수 뒤 포인터 연산자를 두번 붙이면 된다.
	*/
	int num1 = 0;
	int num2 = 0;

	int* ptr = &num1;
	int** ptrToPtr = &ptr;
	//	int*** ptrToPtrToPtr = ptrToPtr;	// 거의 대부분 이중포인터에서 끝난다.

	// *ptr = 10;
	**ptrToPtr = 10;	// 간접참조 한번은 &num1, 두번은 num1의 값인 0에 접근

	// ptr = &num2; 와 같다.
	// ﻿간접참조 한번은 담긴 포인터의 주소
	*ptrToPtr = &num2;		// ptr에 접근해 num2의 주소값 대입
	// ﻿두번은 담긴 포인터가 가진 주소에 접근
	**ptrToPtr = 20;		// num2에 접근해 20 대입

	printf("===== 이중 포인터 간접 참조 결과 =====\n");
	printf("num1 : %d, %p\n", num1, &num1);
	printf("num2 : %d, %p\n", num2, &num2);
	printf("int* : %p, %p int** : %p, %p\n", ptr, &ptr, ptrToPtr, &ptrToPtr);

	int* ptr1 = &num1;
	int* ptr2 = &num2;

	printf("\n===== 포인터 교환 전 =====\n");
	printf("ptr1 : %p, %d, ptr2 : %p, %d\n", ptr1, *ptr1, ptr2, *ptr2);

	//	SwapPointer(ptr1, ptr2);				//	주소값을 넘겨줄뿐 반환이 없으며, 주소값으로 접근해 값을 수정하지 않았으므로 변수의 값은 그대로이다.
	SwapByPointerToPointer(&ptr1, &ptr2);	//	ptr의 주소값을 매개변수로 넘기며, ptr의 주소값에 간접참조로 ptr에 저장된 주소값을 Swap, 변수 num의 값은 그대로이다.

	printf("\n===== 포인터 교환 후 =====\n");
	printf("ptr1 : %p, %d, ptr2 : %p, %d\n", ptr1, *ptr1, ptr2, *ptr2);

	printf("\n===== 포인터 교환 후 변수 출력 =====\n");
	printf("num1 : %d, num2 : %d\n", num1, num2);
}

// ﻿포인터로 받아오는 경우
void SwapPointer(int* ptr1, int* ptr2)
{
	int* temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

// ﻿이중 포인터로 받아오는 경우
void SwapByPointerToPointer(int** ptrToPtr1, int** ptrToPtr2)
{
	int* temp = *ptrToPtr1;
	*ptrToPtr1 = *ptrToPtr2;
	*ptrToPtr2 = temp;
}
/*﻿
	포인터의 주소값을 매개변수로 받아오며,
	이중포인터에 저장된 주소값을 temp을 사용해 바꿔준다.
	받아온 주소값 안에 주소는 변경되어 외부에서 변경되어 있다.
	변수 num의 값은 그대로이다.
*/