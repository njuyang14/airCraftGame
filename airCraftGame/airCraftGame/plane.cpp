#include"common.h"

//void cursorPos(int x, int y);

void AirCraft::mv_up(){
	
}
void AirCraft::mv_down(){}
void AirCraft::mv_left(){
	if (y > 2)y--;
}
void AirCraft::mv_right(){
	if (y < 32)y++;
}

void AirCraft::draw_my_plane(int xp,int yp){
	cursorPos(x,y-1);//
	cout << "x|x";
}