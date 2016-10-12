#include"common.h"

void Control::wait_press_enter(){
	int kbval = _getch();
	while (1){
		if (kbval == 13){ 
			status = START; 
			break;
		}
		else if (kbval == 27){
			status = EXIT;
			break;
		}
		kbval = _getch();
	}
}

void Control::init_my_plane(AirCraft myPlane){
	myPlane.draw_my_plane(15,20);
}