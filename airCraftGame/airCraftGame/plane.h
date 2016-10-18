#ifndef _PLANE_H_
#define _PLANE_H_

#include<list>
#include<iostream>
using namespace std;
#include"bullet.h"

class AirCraft{
protected:
	//position of airCraft
	int x;
	int y;
	list<MyBullet> bullet_array;//save my bullet on display
public:

	AirCraft(){}

	AirCraft(int x_pos, int y_pos){
		x = x_pos;
		y = y_pos;
	}


	//get and set
	int getx(){ return x; }
	int gety(){ return y; }
	void setx(int x_pos){ x = x_pos; }
	void sety(int y_pos){ y = y_pos; }

	//move action
	void mv_up();
	void mv_down();
	void mv_left();
	void mv_right();

	//shoot bullet
	void shooting();
	void clear_all_bullet();
	bool remove_one_bullet(int enemy_x,int enemy_y);

	void draw_my_plane();
	void destroy_my_plane();
};



#endif