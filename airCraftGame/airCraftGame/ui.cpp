#include"common.h"
#include <cstdio>

//get Handle of cursor position
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

const RECT Border = { 0, 0, 16 * 70, 16 * 18 * 2 };//矩形位置，尺寸
const POINT Origin = { 16 * 40, 16 * 0 };//绘图原点
HDC hDC(GetDC(GetConsoleWindow()));// 绘图设备

void cursorPos(int x,int y){
	COORD pos = { y, x };
	SetConsoleCursorPosition(hOut, pos);
}

void cursorHide(){
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(hOut, &cursor);
	cursor.bVisible = false;
	SetConsoleCursorInfo(hOut, &cursor);
}

void setColor(unsigned int color){
	//color为0时颜色恢复默认
	SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | color);
}

void setBackColor(unsigned int color){
	SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | color);
}

void DrawBorder(void)
{
	HPEN hPen(CreatePen(PS_SOLID, 1, RGB(0, 255, 0)));
	HBRUSH hBrush(CreateSolidBrush(RGB(0, 0, 0)));
	SelectObject(hDC, hPen);
	SelectObject(hDC, hBrush);
	Rectangle(hDC, Border.left, Border.top, Border.right, Border.bottom);
	MoveToEx(hDC, Origin.x, Origin.y, NULL);
	LineTo(hDC, Border.right - 16*30, Border.bottom);
	DeleteObject(hPen);
	DeleteObject(hBrush);
}

void Control::draw_wall(){
	system("cls");
	//draw tips in the right console
	setColor(FOREGROUND_GREEN);
	DrawBorder();
	cursorPos(5, 55);
	cout << "Welcome!";
	cursorPos(6, 48);
	cout << "press enter to start!";
	setColor(0);
}

void Control::draw_menu(){
	cursorPos(3, 0);
	cout << "                              War of Aircraft!" << endl;
	cout << "Press Enter to start game!" << endl;
}