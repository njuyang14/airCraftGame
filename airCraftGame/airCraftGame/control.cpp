#include"common.h"
#include<stdlib.h>
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

void Control::init_my_plane(){
	myPlane = AirCraft(14, 20);
	myPlane.draw_my_plane();
}

void Control::press_key(){
	clock_t my_bullet_start = clock();
	clock_t enemy_appear = clock();
	clock_t enemy_move = clock();

	int num = 0;
	while (status ==START){
		if (clock() - enemy_appear >= 2000/*&&num==0*/ ){//敌机2秒出现一只
			enemy_appear = clock();
			appear_enemy_plane();
			num = 1;
		}

		if ((clock() - my_bullet_start) >= 1000){//我方秒发射一枚子弹
			my_bullet_start = clock();
			myPlane.shooting();		
		}

		if (clock() - enemy_move >= 1000){//敌方秒移动一次
			enemy_move = clock();
			all_enemy_move();
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
			case VK_BOMB:{

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

void Control::appear_enemy_plane(){
	int y = 1+rand() % 39;
	Enemy enemy = Enemy(1,y);
	enemy_array.push_back(enemy);
}

void Control::all_enemy_move(){
	list<Enemy>::iterator it;
	for (it = enemy_array.begin(); it != enemy_array.end();){
		it->destroy_my_plane();
		it->mv_down();
		//
		bool temp = myPlane.remove_one_bullet(it->getx(),it->gety());
		if (temp){//is hit
			list<Enemy>::iterator it2=it;
			it->destroy_my_plane();
			//it->clear_all_bullet();
			it++;
			enemy_array.erase(it2);
		}
		else{//is not hit
			if ((myPlane.getx() == it->getx() && myPlane.gety() == it->gety()) || it->hit_plane(myPlane.getx(), myPlane.gety())){//my aircraft crash enemy
				//my plane is hit by enemy
				myPlane.destroy_my_plane();
				myPlane.clear_all_bullet();
				status = NEXT;
				it++;
			}
			else{
				if (it->getx() != 15){
					it->draw_my_plane();
					it++;
				}
				else{
					list<Enemy>::iterator it1 = it;
					it++;
					enemy_array.erase(it1);
				}
			}
		}
	}
}