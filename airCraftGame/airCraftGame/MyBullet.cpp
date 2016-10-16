#include "common.h"

//my aircraft's bullet
MyBullet::MyBullet(int x,int y){
	mid[0] = x;//from aircraft head
	mid[1] = y;
}

void MyBullet::draw_my_bullet(){
	cursorPos(mid[0],mid[1]);
	cout << "^";
}

void MyBullet::destroy_my_bullet(){
	cursorPos(mid[0], mid[1]);
	cout << " ";
}

bool MyBullet::is_bullet_in_screen(){
	if (mid[0]==15||mid[0] == 1 || mid[1] == 1 || mid[1] == 40)return false;
	else
		return true;
}

//Enemy's bullet

void EnemyBullet::draw_my_bullet(){
	cursorPos(mid[0], mid[1]);
	cout << "v";
}