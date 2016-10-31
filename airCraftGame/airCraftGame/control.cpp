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
	clock_t enemy_shoot = clock();
	clock_t enemy_bullet_move = clock();

	int num = 0;
	while (status ==START){
		if (clock() - enemy_appear >= 3000/*&&num==0*/ ){//�л�3�����һֻ
			enemy_appear = clock();
			appear_enemy_plane();
			num = 1;
		}

		/*all enemy do shooting*/
		if (clock() - enemy_shoot >= 2000){
			enemy_shoot = clock();
			all_enemy_shoot();
		}

		if (clock() - enemy_bullet_move >= 700){
			enemy_bullet_move = clock();
			all_enemy_bullet_move();
		}

		if ((clock() - my_bullet_start) >= 400){//�ҷ��뷢��һö�ӵ�
			my_bullet_start = clock();
			myPlane.shooting();		
		}

		if (clock() - enemy_move >= 2500){//�з����ƶ�һ��
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
			it->clear_all_bullet();//����õл������ӵ�
			list<Enemy>::iterator it2=it;
			it->destroy_my_plane();
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

void Control::all_enemy_shoot(){
	list<Enemy>::iterator it = enemy_array.begin();
	for (; it != enemy_array.end(); it++){
		it->shooting();
	}
}

void Control::all_enemy_bullet_move(){
	list<Enemy>::iterator it = enemy_array.begin();
	for (; it != enemy_array.end(); it++){
		it->all_bullet_move();
	}
}