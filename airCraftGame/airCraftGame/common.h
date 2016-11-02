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
int mouse_event();

/**/
enum object{
	MY_PLANE = 0,
	PLANE_WING,
	MY_BULLET,
	ENEMY,
	ENEMY_BULLET,
	NOTHING
};

#define VK_return 13
#define VK_escape 27
#define VK_up 119
#define VK_down 115
#define VK_left 97
#define VK_right 100
#define VK_bomb 98
#define VK_shoot 32
#define VK_restart 114

#endif