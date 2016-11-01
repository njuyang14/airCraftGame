#ifndef _COMMON_H_
#define _COMMON_H_

#include"control.h"
#include<conio.h>
#include<time.h>
#include<windows.h>

extern int world[16][40];

void cursorPos(int x, int y);
void cursorHide();
void setColor(unsigned int color);
void setBackColor(unsigned int color);

/**/
enum object{
	MY_PLANE = 0,
	PLANE_WING,
	MY_BULLET,
	ENEMY,
	ENEMY_BULLET,
	NOTHING
};

#define VK_RETURN 13
#define VK_ESCAPE 27
#define VK_UP 119
#define VK_DOWN 115
#define VK_LEFT 97
#define VK_RIGHT 100
#define VK_BOMB 98
#define VK_SHOOT 32

#endif