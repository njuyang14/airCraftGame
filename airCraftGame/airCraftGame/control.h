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
	int score;
	int life;
	int bomb_count;
	Bomb bomb;
	Life hp;
public:
	Control(){
		score = 0;
		life = 3;
		bomb_count = 1;
	}
	int printScore();
	int getStatus(){ return status; }
	void setStatus(int stat){ status = stat; }
	void wait_press_enter();
	void init_my_plane();
	void press_key();//player control
	void appear_enemy_plane();
	void all_enemy_move();
	void all_enemy_shoot();
	void all_enemy_bullet_move();
	void do_bomb();
	bool bomb_move();
	bool life_move();

	//graphic design
	void draw_menu();
	void draw_wall();
};


#endif
