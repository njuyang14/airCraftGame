#ifndef _CONTROL_H_
#define _CONTROL_H_

#include"plane.h"
#include"enemy.h"

#define EXIT 0
#define START 1
#define NEXT 2

class Control{
private:
	int status;
	AirCraft myPlane;
	list<Enemy> enemy_array;
public:
	int getStatus(){ return status; }
	void setStatus(int stat){ status = stat; }
	void wait_press_enter();
	void init_my_plane();
	void press_key();//player control
	void appear_enemy_plane();
	void all_enemy_move();
	void all_enemy_shoot();
	void all_enemy_bullet_move();

	//graphic design
	void draw_menu();
	void draw_wall();
};


#endif
