#pragma once

void ﻿UserDefinedTypes();


typedef struct Player	// typedef으로 별명을 지어줄 수 있다.
{
	int id;
	int level;
	int hp;
	int atk;
} Player;		// 별명

void Structure();
void PrintPlayer(Player player);	// 자료형이므로 매개변수로도 사용가능하다.
Player LevelUp(Player player);


typedef union Data
{
	int integerNum;
	float fltNum;
	double dblNum;
} Data;

void Union();


enum Color
{
	COLOR_BLACK,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE
};

typedef enum ItemType
{
	ITEMTYPE_NONE = -1,
	ITEMTYPE_GOLD,
	ITEMTYPE_WEAPON,
	ITEMTYPE_ARMOR,
	ITEMTYPE_MAXVALUE
} ItemType;

void Enumeration();