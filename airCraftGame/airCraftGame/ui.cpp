#include"common.h"
#include<windows.h>

//get Handle of cursor position
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

void cursorPos(int x,int y){
	COORD pos = { y, x };
	SetConsoleCursorPosition(hOut, pos);
}

void Control::draw_wall(){
	system("cls");
	for (int i = 0; i < 70; i++)
		cout << "-";
	cout << endl;

	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 70; j++){
			if (j == 0 || j == 69||j==45)cout << "|";
			else
				cout << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 70; i++)
		cout << "-";

	//draw tips in the right console
	cursorPos(5, 55);
	cout << "Welcome!";
	cursorPos(6, 50);
	cout << "press Enter to start!";
}

void Control::draw_menu(){
	cursorPos(3, 0);
	cout << "                              War of Aircraft!" << endl;
	cout << "Press Enter to start game!" << endl;
}