// House_.cpp: 定义控制台应用程序的入口点。
//

/*
* File: house.c
* -------------
* This program draws a simple frame house.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "graphics.h"
#include "conio.h"

#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

/*
* Constants
* ---------
* The following constants control the sizes of the
* various elements in the display.
*/

#define HouseHeight         200
#define HouseWidth          160
#define AtticHeight         120
#define Window              40
#define DoorWidth           40
#define DoorHeight          160
#define ChinmeyWidth             25

/* Function prototypes */

void DrawHouse(double x, double y);
void DrawOutline(double x, double y);
void DrawWindows(double x, double y);
void DrawDoor(double x, double y);
void DrawBox(double x, double y, double width, double height);
void DrawTriangle(double x, double y, double base, double height);
void DrawChimney(double x, double y, double width, double leftheight, double rightheight);

/* Main program */

void main()
{
	double cx, cy;

	initgraph(960,480);//初始化界面
	setbkcolor(0xFFFFFF);//设置背景颜色
	setlinecolor(0);//设置画笔颜色
	cleardevice();
	MOUSEMSG m;
	DrawHouse(360,400);
	while (true) {
		m = GetMouseMsg();
		switch (m.uMsg) {
		case WM_MOUSEMOVE:
			if (m.mkLButton)
				putpixel(m.x, m.y,BLACK);
		}
	}
	_getch();
}



void DrawHouse(double x, double y)
{
	DrawOutline(x, y);
	DrawDoor(x + 85, y);
	DrawWindows(x+30, y-120);
}


void DrawOutline(double x, double y)//画轮廊
{
	DrawBox(x, y, HouseWidth, HouseHeight);
	DrawTriangle(x, y - HouseHeight, HouseWidth, AtticHeight);
	double lefthigh=AtticHeight*2/3;//烟囱左边的高度
	double righthigh = lefthigh - 25 * AtticHeight * 2 / HouseWidth;//烟囱右边的高度
	double dy = 215;//设置坐标偏移量
	double dx = 10;//同上
	DrawChimney(x + dx, y - dy, ChinmeyWidth,lefthigh,righthigh);//画烟囱
}



void DrawDoor(double x, double y)//画门
{
	DrawBox(x, y, DoorWidth, DoorHeight);
}

void DrawWindows(double x, double y)//画窗户
{
	DrawBox(x, y, Window, Window);
}

void DrawBox(double x, double y, double width, double height)//向上画矩形
{
	moveto(x, y);
	linerel(0, -height);
	linerel(width, 0);
	linerel(0, height);
	linerel(-width, 0);
}


void DrawTriangle(double x, double y, double base, double height)//向上画三角形
{
	moveto(x, y);
	linerel(base, 0);
	linerel(-base / 2, -height);
	linerel(-base / 2, height);
}


void DrawChimney(double x, double y, double width, double leftheight,double rightheight) {//画烟囱
	moveto(x, y);
	linerel(0,-leftheight);
	linerel(width, 0);
	linerel(0, rightheight);
	DrawBox(x - width / 3, y - leftheight, 5 * width / 3, leftheight / 8);
}

