#include "stdafx.h"

void C08()
{
//	Structure();
//	Union();
	Enumeration();
}

void Structure()
{
	/*
	C 사용자 정의 자료형
	사용자가 직접 정의하는 자료형
	자료형들을 조합해서 원하는 입맛에 맞쳐 정의

	﻿Structure(구조체)
	구조체의 특징
	하나 혹은 여러 멤버를 모아서 하나의 자료형을 정의

	구조체 정의
	struct 구조체 이름
	{
		구조체의 멤버 변수 1;
		구조체의 멤버 변수 2;
		구조체의 멤버 변수 3;
		구조체의 멤버 변수 4;
	};
﻿
	구조체의 크기
	멤버 변수 중 가장 큰 변수의 크기 * 갯수
	
	바이트 패딩(Data Padding)
	가장큰 자료형의 크기로 가져오며, 작은 자료형일 경우 아무것도 없는 더미를 채워서 가져온다. 2Byte 2Byte(더미) 4Byte

	﻿사용자 편의를 위한 개념이며, 내부적으로는 독립된 변수들을 사용하는 것과 같다.
	*/

	printf("Player 구조체 크기 : %zd\n\n", sizeof(Player));

	// 멤버 전근 연산자를 사용한 초기화
	Player player1;
	player1.id = 1;				// . : 멤버 접근 연산자, player1의 멤버변수에 접근해 값을 대입할 수 있다.
	player1.level = 1;
	player1.hp = 20;
	player1.atk = 5;

	// 중괄호를 사용한 초기화
	Player player2 = { 2, 3, 60, 15 };	// 선언한 순서로 초기화된다.

	printf("===== 각 플레이어 초기 정보(변수) =====\n");
	PrintPlayer(player1);
	PrintPlayer(player2);

	// 배열로 관리할 수 있다.
	Player players[] =
	{
		player1,
		player2,
		{ 3, 2, 40, 10 },
		{ 4, 1, 20, 5 }
	};
	const int numPlayers = sizeof(players) / sizeof(players[0]);	// 플레이어가 몇개인지 알 수 있다.

	printf("\n===== 각 플레이어 초기 정보(배열) =====\n");
	for (int i = 0; i < numPlayers; ++i)
		PrintPlayer(players[i]);

	system("cls");
	/*
	레벨업 프로그램
	선택된 플레이어(1~4)는 레벨이 1 오르고 hp가 20 오르고 atk이 5 오른다.
	레벨업 완료 후 레벨업 결과 출력
	*/
	while (true)
	{
		int element = 0;
		printf("===== LevelUp 프로그램 =====\n\n");
		printf("LevelUp 대상 플레이어 선택 (1 ~ 4) : ");
		scanf("%d", &element);			// ﻿player의 id를 입력시

		if (element == 0)
		{
			printf("프로그램을 종료합니다.\n");
			break;
		}
		else if (element >= 1 && element <= 4)
			players[element - 1] = LevelUp(players[element - 1]);	// levelUp함수를 호출
		else
		{
			printf("잘못된 값을 입력했습니다. 다시 입력해주세요.\n\n");
			system("pause");
			continue;
		}

		printf("\n===== LevelUp 결과 =====\n");
		for (int i = 0; i < numPlayers; ++i)	// ﻿player 배열 원소 갯수만큼 반복
			PrintPlayer(players[i]);			// PrintPlayer 함수를 호출

		printf("\n");
		system("pause");	// ﻿sysyem을 사용해 프로그램 중단
		system("cls");		// 초기화
	}
}

void PrintPlayer(Player player)	// player들의 정보를 콘솔창에 출력
{
	printf("플레이어 %d 정보 [ Level : %d, HP : %d, ATK : %d ]\n", player.id, player.level, player.hp, player.atk);
}

Player LevelUp(Player player)
{
	player.level += 1;	// level, hp, atk을 증가
	player.hp += 20;
	player.atk += 5;

	return player;	// 증가한 값 반환
}

void Union()
{
	/*
	﻿Union(공용체)
	공용체의 특징
	모든 멤버 변수들이 하나의 메모리 공간을 공유
	마지막에 할당된 값만 기억

	﻿공용체 정의
	union 공용체 이름
	{
		공용체의 멤버 변수 1;
		공용체의 멤버 변수 2;
		공용체의 멤버 변수 3;
		공용체의 멤버 변수 4;
	};
	﻿
	공용체의 크기
	맴버 변수 중 가장 큰 변수의 크기
	
	메모리의 효율성을 높이는 장점이 있지만,
	저장된 값이 보호 받을 수 없다는 단점, 메모리 관리에 신경써야 한다.
	*/
	printf("공용체의 크기 : %zd\n", sizeof(Data));

	Data data;
	data.integerNum = 123456789;	// ﻿data의 integerNum에 값을 저장했을 경우

	printf("===== Int 할당 결과 =====\n");
	printf("Int : %d\n", data.integerNum);	// Int의 값이 재대로 출력
	printf("Float : %f\n", data.fltNum);	// 나머지는 쓰레기값 출력
	printf("Double : %f\n", data.dblNum);

	data.fltNum = 3.14f;

	printf("===== Float 할당 결과 =====\n");
	printf("Int : %d\n", data.integerNum);
	printf("Float : %f\n", data.fltNum);	// ﻿Float의 값이 재대로 출력
	printf("Double : %f\n", data.dblNum);	// 나머지는 쓰레기값 출력

	data.dblNum = 3.141592;

	printf("===== Double 할당 결과 =====\n");
	printf("Int : %d\n", data.integerNum);	// 나머지는 쓰레기값 출력
	printf("Float : %f\n", data.fltNum);
	printf("Double : %f\n", data.dblNum);	// ﻿Double의 값이 재대로 출력
}

void Enumeration()
{
	/*
	﻿﻿enumeration(열거형)
	열거형의 특징
	서로 연관된 상수들의 집합을 이루는 자료형
	상수에 이름을 붙여, 코드의 가독성을 높인다.
﻿
	enum 열거형 이름
	{
		상수 이름 1,
		상수 이름 2,
		상수 이름 3,
		상수 이름 4
	};
	﻿
	열거형의 크기
	기본적으로 4byte 크기를 가지며, 값에 따라 8byte 크기로 변경된다.

	﻿상수를 사용하는 것보다 가독성이 좋다.
	*/
	enum Color color = COLOR_BLACK;	// typedef을 안사용한 경우

	ItemType itemType = ITEMTYPE_WEAPON;	// 해당 열거형 형태로 선언한 후 ITEMTYPE_WEAPON(1)으로 초기화

	printf("\n===== 열거형 상수 비교 결과 =====\n");
	printf("ItemType == NONE : %d\n", itemType == ITEMTYPE_NONE);			// 1 != -1
	printf("ItemType == GOLD : %d\n", itemType == ITEMTYPE_GOLD);			// 1 != 0
	printf("ItemType == WEAPON : %d\n", itemType == ITEMTYPE_WEAPON);		// 1 == 1
	printf("ItemType == ARMOR : %d\n", itemType == ITEMTYPE_ARMOR);			// 1 != 2
	printf("ItemType == MAXVALUE : %d\n", itemType == ITEMTYPE_MAXVALUE);	// 1 != 3
}