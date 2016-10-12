#include"plane.h"
#include"enemy.h"

#define EXIT 0
#define START 1

class Control{
private:
	int status;
public:
	int getStatus(){ return status; }
	void setStatus(int stat){ status = stat; }
	void wait_press_enter();
	void init_my_plane(AirCraft myPlane);
	void appear_enemy_plane();

	//graphic design
	void draw_menu();
	void draw_enemy_plane();
	void draw_wall();
};

