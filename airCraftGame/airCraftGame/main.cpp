#include"common.h"

int main(){
	system("mode con cols=80 lines=20");	
	cursorHide();
	while (1){
		Control myGame;
		myGame.draw_wall();
		myGame.wait_press_enter();
		while (1){
			if (myGame.getStatus() == START ){
				myGame.init_my_plane();
				myGame.press_key();
			}
			else if (myGame.getStatus() == NEXT){
				myGame.setStatus(START);
			}
			else{
				break;
			}
		}
		if (myGame.getStatus() == EXIT)
			break;
	}
	return 0;
}