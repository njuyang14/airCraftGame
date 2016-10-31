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
	void all_bullet_move();

	void clear_all_bullet();
	void draw_my_plane();
	void destroy_my_plane();
};

#endif