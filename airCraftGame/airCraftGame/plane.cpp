#include"common.h"

//void cursorPos(int x, int y);

void AirCraft::mv_up(){
	if (x > 1)x--;
}
void AirCraft::mv_down(){
	if (x < 15)x++;
}
void AirCraft::mv_left(){
	if (y > 2)y--;
}
void AirCraft::mv_right(){
	if (y < 39)y++;
}

void AirCraft::draw_my_plane(){
	cursorPos(x,y-1);//
	cout << "pHq";
	//cursorPos(x , y - 2);
	//cout << "H-H";
}

void AirCraft::destroy_my_plane(){
	cursorPos(x, y - 1);
	cout << "   ";
}