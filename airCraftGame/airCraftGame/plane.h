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
	int life;
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


/*特殊物体，补给品，继承AirCraft类*/
class Bomb:public AirCraft{
public:
	Bomb(){}
	Bomb(int px, int py){ x = px; y = py; }
	~Bomb(){
		destroy_my_plane();
	}
	bool receive_bomb(int px,int py);
	void bomb_move(){ x++; }
	void draw_my_plane();
	void destroy_my_plane();
};

class Life:public AirCraft{
public:
	Life(){}
	Life(int px, int py){ x = px; y = py; }
	~Life(){
		destroy_my_plane();
	}
	bool receive_life(int px, int py);
	void life_move(){ x++; }
	void draw_my_plane();
	void destroy_my_plane();
};

#endif