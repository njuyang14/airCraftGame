#include"common.h"

int main(){
	//system("mode con cols=70 lines=20");	
	while (1){
		Control myGame;
		AirCraft myPlane(15,23);
		myGame.draw_wall();
		myGame.wait_press_enter();
		if (myGame.getStatus() == EXIT)
			break;
		else{
			myGame.init_my_plane(myPlane);
		}
		//getchar();
	}
	
	return 0;
}