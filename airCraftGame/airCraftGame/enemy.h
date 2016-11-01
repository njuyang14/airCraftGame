#ifndef _ENEMY_H_
#define _ENEMY_H_

#include<list>
#include<iostream>
using namespace std;
#include"plane.h"
#include"bullet.h"

class Enemy:public AirCraft{
public:
	list<EnemyBullet> bullet_array;
	Enemy(){}
	Enemy(int px, int py){ x = px; y = py; }
	//shoot bullet
	void shooting();
	bool hit_plane(int myx, int myy);
	void is_hit(AirCraft myPlane);
	int all_bullet_move(int px,int py);//px py 是myplane现在位置,返回游戏运行状态

	void clear_all_bullet();
	void draw_my_plane();
	void destroy_my_plane();
};

#endif