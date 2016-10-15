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
	myPlane.draw_my_plane();
}

void Control::press_key(AirCraft myPlane){
	clock_t my_bullet_start = clock();
	while (status != EXIT){
		
		if ((clock() - my_bullet_start) >= 300){
			my_bullet_start = clock();
			myPlane.shooting();
		}
		

		if (_kbhit()){
			//myPlane.shooting();
			int kbval = _getch();//get keyboard value
			myPlane.destroy_my_plane();
			switch (kbval){
			case VK_UP:{
				myPlane.mv_up();
				break; }
			case VK_LEFT:{
				myPlane.mv_left();
				break;
			}
			case VK_DOWN:{
				myPlane.mv_down(); break;
			}
			case VK_RIGHT:{
				myPlane.mv_right(); break;
			}
			case VK_ESCAPE:{
				status = EXIT;
				break;//restart
			}
			}
			myPlane.draw_my_plane();
		}
	}
}