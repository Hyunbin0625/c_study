#include "stdafx.h"

void Arrays()
{
//	Array();
//	Matrix();
	String();
}

void Array()
{
	/*
	배열
	다수의 동일한 자료형, 메모리상에서 연속된다.
	배열의 이름이 시작점의 주소

	arr [ 배열의 길이(원소의 개수) ]

	배열의 길이 = 배열의 원소의 개수

	방 한칸 = 원소(자료형)

	접근방법 첫번째 원소, 두번째 원소 ...
	[] 인덱스를 사용해, arr[2] 배열의 3번째 원소

	0 ~ 길이 -1, 인덱스 원소 범위

	int arr[5];
	arr[0]	arr[1]	arr[2]	arr[3]	arr[4]
	4Byte | 4Byte | 4Byte | 4Byte | 4Byte
	arr은 시작점의 주소값을 가지고 있다.
	*/

	int arr[5];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	printf("===== 배열 1 원소 =====\n");
	printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

	printf("\n===== 배열 1 원소의 주소값 =====\n");
	printf("%p %p %p %p %p %p\n\n", arr, &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);	// arr과 arr[0]의 주소가 같다.

	int arr2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// 중괄호를 사용해 한번에 초기화할 수 있다.

	// 배열의 메모리 크기(40) = 배열 원소 1개의 크기 * 배열 길이
	// 배열 길이 = 배열의 메모리 크기(40) / 배열 원소 1개의 크기
	// const : 변수를 상수화, sizeof() : 크기를 바이트 단위로 반환
	const int size2 = sizeof(arr2) / sizeof(arr2[0]);	// const를 사용하는 이유 사이즈는 변하지 않기 때문, arr[0] = int

	printf("===== 배열 2 원소 =====\n");
	for (int i = 0; i < size2; ++i)
	{
		printf("%d ", arr2[i]);
	}

	int arr3[5] = { 1, 2, 3 };	// 나머지 명시되지 않은 값은 0으로 초기화된다.

	const int size3 = sizeof(arr3) / sizeof(arr3[0]);

	printf("\n\n===== 배열 3 원소 =====\n");
	for (int i = 0; i < size3; ++i)
		printf("%d, ", arr3[i]);

	int arr4[] = { 1, 2, 3 };	// 배열 길이를 명시하지 않은 경우 초기화한 만큼 컴파일러가 배열의 길이를 잡는다.
	// 초기화값을 반드시 하나이상 지정해주어야한다.

	const int size4 = sizeof(arr4) / sizeof(arr4[0]);

	printf("\n\n===== 배열 3 원소 =====\n");
	for (int i = 0; i < size4; ++i)
		printf("%d, ", arr4[i]);
}

void Matrix()
{
	// 인덱스 연산자를 하나 더붙여 2차원 배열을 선언할 수 있다.
	// 2차원 배열은 1차원 배열 한개를 원소값으로 갖는다.
	// [행][열]
	/*
		열  열
	행	[] []
	행	[] []

	메모리 상에서는
	[]	[]	[]	[]
	0,0 0,1 1,0 1,1

	matrix = matrix[0] = 전체의 시작점의 주소

	컴퓨터는 2차원 배열 matrix의 시작점의 주소만 기억하고 있으며,
	matrix[0][1]일때, 시작 주소에서 4byte 이동해 값을 찾는다.
	*/

	int matrix[2][2];
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	matrix[1][1] = 4;

	printf("===== 2차원 배열 1 원소 =====\n");
	printf("%d, %d\n%d, %d\n\n", matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]);


	int matrix2[2][2] =
	{
		{ 1 , 2 },		// 0행, 직접 지정
		{ 3 , 4 }		// 1행
	};

	int matrix3[2][2] = { 1, 2, 3, 4 };	// 순서대로 지정
	// row-major(c,cpp 등)
	// 행부터 채워진다.

	// col-major(Fortran s-Plus 등)
	// 열부터 채워진다.

	int matrix4[2][2] =
	{
		{ 1 },
		{ 3 }
	};

	int matrix5[2][2] = { 1,2 };

	int row2 = sizeof(matrix2) / sizeof(matrix2[0]);	// 2차원 배열의 사이즈를 행 한개의 사이즈로 나눈다. 16 / 8 = 2(열의 사이즈)
	int col2 = sizeof(matrix2[0]) / sizeof(matrix2[0][0]);	// 행 한개의 사이즈를 원소 한개의 사이즈로 나눈다. 8 / 4 = 2(행의 사이즈)

	printf("===== 2차원 배열 2 원소 =====\n");
	for (int i = 0; i < row2; ++i)
	{
		for (int j = 0; j < col2; ++j)
			printf("%d, ", matrix2[i][j]);

		printf("\n");
	}

	int row3 = sizeof(matrix3) / sizeof(matrix3[0]);	// 2차원 배열의 사이즈를 행 한개의 사이즈로 나눈다. 16 / 8 = 2(열의 사이즈)
	int col3 = sizeof(matrix3[0]) / sizeof(matrix3[0][0]);	// 행 한개의 사이즈를 원소 한개의 사이즈로 나눈다. 8 / 4 = 2(행의 사이즈)

	printf("===== 2차원 배열 3 원소 =====\n");
	for (int i = 0; i < row3; ++i)
	{
		for (int j = 0; j < col3; ++j)
			printf("%d, ", matrix3[i][j]);

		printf("\n");
	}

	int row4 = sizeof(matrix4) / sizeof(matrix4[0]);	// 2차원 배열의 사이즈를 행 한개의 사이즈로 나눈다. 16 / 8 = 2(열의 사이즈)
	int col4 = sizeof(matrix4[0]) / sizeof(matrix4[0][0]);	// 행 한개의 사이즈를 원소 한개의 사이즈로 나눈다. 8 / 4 = 2(행의 사이즈)

	printf("===== 2차원 배열 4 원소 =====\n");
	for (int i = 0; i < row4; ++i)
	{
		for (int j = 0; j < col4; ++j)
			printf("%d, ", matrix4[i][j]);

		printf("\n");
	}

	int row5 = sizeof(matrix5) / sizeof(matrix5[0]);	// 2차원 배열의 사이즈를 행 한개의 사이즈로 나눈다. 16 / 8 = 2(열의 사이즈)
	int col5 = sizeof(matrix5[0]) / sizeof(matrix5[0][0]);	// 행 한개의 사이즈를 원소 한개의 사이즈로 나눈다. 8 / 4 = 2(행의 사이즈)

	printf("===== 2차원 배열 5 원소 =====\n");
	for (int i = 0; i < row5; ++i)
	{
		for (int j = 0; j < col5; ++j)
			printf("%d, ", matrix5[i][j]);

		printf("\n");
	}
}

/*
	메모리 구조를 알아야하는 이유
	c언어는 개발자에게 제약이 없다.(메모리 직접접근 등), 하드웨어에 가까운 언어
	c / c++ : 객체지향, 퍼포먼스(실행속도)
	java, pytion : 사용자 편의성
	배열, 함수, 포인터, 동적할당 : 메모리 구조를 이해하면 쉽다.
	*/

	/*
	x86(32비트)
	high 0xffffffff = 4,294,967,295(byte) = 4GB까지 인식가능하다.
	가상메모리에 올려두고 실제 물리메모리에는 운영체제가 알아서 배치한다.

	x64비트 16헥사바이트까지 사용가능하다.

	가상메모리 영역
	Stack : 하나씩 쌓인다 <- 스택 프레임(main함수같은) <- 함수에 묶인 {}는 하나의 스코프(영역), 스택프레임의 크기는 컴파일타임에 결정된다.
	Heap
	Data
	cod : 함수, 클래스(c++)

	low	0x00000000
	*/

void String()
{
	/*
	문자 배열와 문자열의 차이
	char
	[a] [b] [c] [d]
	
	string
	[a] [b] [c] [d] [\0]
	마지막에 null문자가 붙는다.
	문자열을 선언, 초기화할때 사용할 문자열 + 1
	
	문자열을 사용하기 위해 string.h를 포함해야 한다.
	*/

	//	char string[5] = { 'A', 'B', 'C', 'D', '\0' };
	//	"abcd"에 마우스를 올려보면 [5]로 자동으로 널문자가 붙는다.

	char string[100] = { 'A', 'B', 'C', 'D', '\0' };
	char string2[100] = "abcd";

	printf("===== 문자열 =====\n");
	printf("문자열 1 : %s\n", string);
	printf("문자열 2 : %s\n\n", string2);

	// ﻿string 기능(함수)
	strcpy(string, "Hello");	//	Destination에 Source로 복사, string에 Hello를 복사
	strcat(string2, "World");	//	concatenate 이어진, Destination에 Source를 이어붙인다.

	printf("===== 문자얄 함수 결과 =====\n");
	printf("문자열 1 (%zd) : %s\n", strlen(string), string);	// strlen : 문자열의 길이를 알려주는 함수, 널문자를 제외한 실제 문자만 포함
	printf("문자열 2 (%zd) : %s\n\n", strlen(string2), string2);

	printf("문자열 1, 2 비교 : %d\n\n", strcmp(string, string2));	// strcmp : 문자열 비교, 처음 문자가 다를때 아스키코드표로 비교, 소문자가 더 뒤에 있기 때문에 H가 크다. 작을땐 -1, 같을때 0, 클때 1

	printf("문자열 1의 T 문자 포함 여부 : %d\n", strchr(string, 'T') != NULL);	// 문자열에서 특정 문자(정수)가 포함되어 있다면, 포함된 곳 위치의 메모리 주소값(char*)를 반환한다.(대, 소문자 구분해야한다.) 못찾았을 경우 Null 포인터의 주소값(0번지 주소)을 반환
	printf("문자열 2의 문자열 포함 여부 : %d\n\n", strstr(string2, "World") != NULL);	// 문자열에서 특정 문자열이 포함되어 있다면, 포함된 곳 첫번째 위치의 메모리 주소를 반환.﻿ 못찾았을 경우 Null 포인터의 주소값(0번지 주소)을 반환

	printf("문자열 1 반전 : %s\n", _strrev(string));	// 문자열 전체를 반전한다.
	printf("문자열 1 소문자로 변환 : %s\n", _strlwr(string));	// 문자열 전체를 소문자로 변환한다.
	printf("문자열 2 대문자로 변환 : %s\n\n", _strupr(string2));	// 문자열 전체를 대문자로 변환한다.

	// 입출력
	/*
	printf, scanf는 기본적으로 표준 입출력 스트림을 사용
	표준 입력 스트림 stdin, 표준 출력 스트림 stdout
	버퍼는 중간에 값을 저장하는 임시 공간, stream : (특정한 방향으로) 흐름
	*/
	printf("문자열 1 입력 : ");
// scanf를 사용시, 띄어쓰기가 있다면 공백전까지만 가지고 온다. 버퍼에는 남아있기 때문에 다음 입력을 받을때 버퍼에 남아있는 값으로 입력된다. 배열 크기 이상을 입력할 경우도 또한 같다.
//	scanf("");	// 문자열을 받아오는 데 특화되어 있지 않다.
//	scanf("%[^\n]s", string);	// %[^\n]s를 사용해, 개행전까지 다 받아올 수 있다.

	fgets(string, sizeof(string), stdin);	// file get string, ﻿표준 입력 스트림 stdin으로 문자열에 입력
	string[strlen(string) - 1] = '\0';	// file get string을 사용할 때, 입력한 후 엔터(개행)까지 입력받기 때문에, -1을 해 개행 앞으로 이동 후 널문자로 대입, ﻿입력에서의 엔터는 입력 종료라는 뜻이다.

	printf("문자열 2 입력 : ");
	gets_s(string2, sizeof(string2), stdin);	// get string, 맨 끝에 알아서 널문자로 넣어준다. 개행문자도 가지고 오지만, 널문자로 바꿔준다.
//	scanf("%s", string2);

	fputs("\n====== 문자열 입력 결과 =====\n", stdout);		// file put string, 표준 출력 스트림 stdout으로 ﻿콘솔창에 출력
	printf("문자열 1 : %s\n", string);
	printf("문자열 2 : %s\n", string2);

// gets, gest_s보다 fgets를 더 많이 사용하며,
// get_s, scanf_s는 안전하지만 호환성이 좋지않다.

	// 사용 예.
	char name[50] = { '\0' };
	
	printf("이름은? ");
	fgets(name, sizeof(name), stdin);
}