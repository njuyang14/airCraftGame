#include"common.h"
#include <cstdio>

//get Handle of cursor position
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

const RECT Border = { 0, 0, 16 * 70, 16 * 18 * 2 };//矩形位置，尺寸
const RECT rect1 = { 47 * 16, 16 * 1 * 2, 50 * 16, 16 * 2 * 2+8 };
const RECT rect2 = { 47 * 16, 16 * 3 * 2+2, 50 * 16, 16 * 4 * 2+10 };
const RECT rect3 = { 42 * 16, 16 * 3 * 2+2, 45 * 16, 16 * 4 * 2+10 };
const RECT rect4 = { 52 * 16, 16 * 3 * 2+2, 55 * 16, 16 * 4 * 2+10 };
const RECT rect5 = { 57 * 16, 16 * 1 * 2, 60 * 16, 16 * 2 * 2 + 8 };
const RECT rect6 = { 63 * 16, 16 * 1 * 2, 66 * 16, 16 * 2 * 2 + 8 };
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

	//矩形框
	Rectangle(hDC, Border.left, Border.top, Border.right, Border.bottom);
	Rectangle(hDC, rect1.left, rect1.top, rect1.right, rect1.bottom);
	Rectangle(hDC, rect2.left, rect2.top, rect2.right, rect2.bottom);
	Rectangle(hDC, rect3.left, rect3.top, rect3.right, rect3.bottom);
	Rectangle(hDC, rect4.left, rect4.top, rect4.right, rect4.bottom);
	Rectangle(hDC, rect5.left, rect5.top, rect5.right, rect5.bottom);
	Rectangle(hDC, rect6.left, rect6.top, rect6.right, rect6.bottom);

	//分界线
	MoveToEx(hDC, Origin.x, Origin.y, NULL);
	LineTo(hDC, Border.right - 16*30, Border.bottom);
	//tips

	DeleteObject(hPen);
	DeleteObject(hBrush);
}

int mouse_event(){
	//CONSOLE_SCREEN_BUFFER_INFO bInfo;
	INPUT_RECORD mouseRec;
	DWORD res;

	ReadConsoleInput(hIn, &mouseRec, 1, &res);
	if (mouseRec.EventType == MOUSE_EVENT){
		if (mouseRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED){
			return 1;
		}
	}
	return 0;
}

void Control::draw_wall(){
	system("cls");
	//draw tips in the right console
	setColor(FOREGROUND_GREEN);
	DrawBorder();
	/*显示操作按键*/
	cursorPos(1,51);
	cout << "W";
	cursorPos(3,51);
	cout << "S";
	cursorPos(3,46);
	cout << "A";
	cursorPos(3,56);
	cout << "D";
	cursorPos(1,62);
	cout << "B";
	cursorPos(1,68);
	cout << "R";
	cursorPos(3,61);
	cout << "bomb";
	cursorPos(3,66);
	cout << "restart";

	cursorPos(7, 52);
	cout << "飞机大战v1.0";
	cursorPos(8, 50);
	cout << "请按回车开始游戏！";
	cursorPos(9, 53);
	cout << "当前得分：";
	cursorPos(10,53);
	setColor(FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "剩余生命：";
	cursorPos(11,53);
	setColor(FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "剩余炸弹：";
	setColor(FOREGROUND_GREEN);
	cursorPos(13, 53);
	cout << "祝君好运！";
	setColor(0);
}

void Control::draw_menu(){
	cursorPos(3, 0);
	cout << "                              War of Aircraft!" << endl;
	cout << "Press Enter to start game!" << endl;
}