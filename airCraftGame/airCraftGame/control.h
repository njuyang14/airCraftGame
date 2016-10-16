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
	list<Enemy> enemy_array;
public:
	int getStatus(){ return status; }
	void setStatus(int stat){ status = stat; }
	void wait_press_enter();
	void init_my_plane(AirCraft myPlane);
	void press_key(AirCraft myPlane);//player control
	void appear_enemy_plane();
	void all_enemy_move(AirCraft myPlane);

	//graphic design
	void draw_menu();
	void draw_wall();
};


#endif
