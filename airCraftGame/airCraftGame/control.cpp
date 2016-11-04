#include"common.h"
#include<stdlib.h>

int world[16][40];

void Control::wait_press_enter(){
	int kbval = _getch();
	while (1){
		if (kbval == 13){ 
			status = START; 
			for (int i = 1; i < 15; i++){
				for (int j = 0; j < 39; j++){
					world[i][j] = NOTHING;
				}
			}
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
	bomb.destroy_my_plane();
	hp.destroy_my_plane();
	if (life == 0){
		do_bomb();//重置画面
		score = 0;
		cursorPos(9,63);//清空上一局分数
		cout << "     ";
		life = 3;
	}
	myPlane.life = life;//当前生命
	myPlane.draw_my_plane();
}

void Control::press_key(){
	clock_t my_bullet_start = clock();
	clock_t enemy_appear = clock();
	clock_t enemy_move = clock();
	clock_t enemy_shoot = clock();
	clock_t enemy_bullet_move = clock();
	clock_t bomb_time = clock();
	clock_t bomb_move_time = clock();
	clock_t life_time = clock();
	clock_t life_move_time = clock();
	clock_t easy_hard = clock();

	int num = 0;
	bool bomb_appear = false;
	bool life_appear = false;
	int speed_all = 500;

	if (myPlane.life == 0)status = NEXT;//生命减为0

	while (status ==START){

		if (clock() - easy_hard >= 15000){
			easy_hard = clock();
			if (speed_all > 300)speed_all -= 100;//游戏难度控制
		}

		if (clock() - bomb_time >= 20000&&bomb_appear==false){//20秒产生一个炸弹
			bomb_time = clock();
			bomb = Bomb(1, (2 + rand() % 38));
			bomb_appear = true;
		}

		if (clock() - life_time >= 15000 && life_appear == false){//15秒产生一个医疗包
			life_time = clock();
			hp = Life(1, (2 + rand() % 38));
			life_appear = true;
		}

		if (clock() - enemy_appear >= 2200+speed_all ){//敌机2.5秒出现一只
			enemy_appear = clock();
			appear_enemy_plane();
			num = 1;

			/*all enemy do shooting*/
			if (clock() - enemy_shoot >= 2500+speed_all){//敌机射击
				enemy_shoot = clock();
				all_enemy_shoot();
			}
		}

		if (clock() - enemy_bullet_move >= speed_all+100){//敌机子弹移动
			enemy_bullet_move = clock();
			all_enemy_bullet_move();
		}

		if ((clock() - my_bullet_start) >= 500){//我方秒发射一枚子弹
			my_bullet_start = clock();
			myPlane.shooting();		
		}

		if (clock() - enemy_move >= 1700+speed_all){//敌方秒移动一次
			enemy_move = clock();
			all_enemy_move();
		}

		if (clock() - bomb_move_time >= 500 && bomb_appear){//炸弹包移动
			bomb_move_time = clock();
			bomb_appear = bomb_move();
		}

		if (clock() - life_move_time >= 500 && life_appear){//医疗包移动
			life_move_time = clock();
			life_appear = life_move();
		}

		if (_kbhit()){
			int kbval = _getch();//get keyboard value
			myPlane.destroy_my_plane();
			switch (kbval){
			case VK_up:{
				myPlane.mv_up();
				break; }
			case VK_left:{
				myPlane.mv_left();
				break;
			}
			case VK_down:{
				myPlane.mv_down(); break;
			}
			case VK_right:{
				myPlane.mv_right(); break;
			}
			case VK_bomb:{
				if (bomb_count != 0){
					do_bomb();
					bomb_count--;
				}
				break;
			}
			case VK_escape:{
				status = EXIT;
				break;//escape
			}
			case VK_restart:{
				status = NEXT;
				myPlane.life = 0;
				life = 0;
				break;
			}
			}
			myPlane.draw_my_plane();
		}
		printScore();
		life = myPlane.life;
		
	}
}

int Control::printScore(){
	cursorPos(9, 63);
	setColor(FOREGROUND_GREEN);
	cout<<score;
	cursorPos(10,63);
	setColor(FOREGROUND_BLUE | FOREGROUND_RED);
	cout << myPlane.life;
	cursorPos(11,63);
	setColor(FOREGROUND_GREEN | FOREGROUND_RED);
	cout << bomb_count;
	setColor(0);
	return score;
}

bool Control::bomb_move(){
	/*炸弹移动，并判断飞机是否接到该炸弹*/
	if (bomb.getx() != 15){
		if (bomb.receive_bomb(myPlane.getx(), myPlane.gety())){
			bomb_count++;
			bomb.destroy_my_plane();
			return false;
		}
		else{
			bomb.destroy_my_plane();
			bomb.bomb_move();
			bomb.draw_my_plane();
			return true;
		}
	}
	else{
		bomb.destroy_my_plane();
		return false;
	}
}

bool Control::life_move(){
	/*炸弹移动，并判断飞机是否接到该炸弹*/
	if (hp.getx() != 15){
		if (hp.receive_life(myPlane.getx(), myPlane.gety())){
			myPlane.life++;
			hp.destroy_my_plane();
			return false;
		}
		else{
			hp.destroy_my_plane();
			hp.life_move();
			hp.draw_my_plane();
			return true;
		}
	}
	else{
		hp.destroy_my_plane();
		return false;
	}
}

void Control::appear_enemy_plane(){
	int y = 2+rand() % 38;
	Enemy enemy = Enemy(1,y);
	enemy_array.push_back(enemy);
}

void Control::all_enemy_move(){
	list<Enemy>::iterator it;
	for (it = enemy_array.begin(); it != enemy_array.end();){
		it->destroy_my_plane();
		it->mv_down();
		
		bool temp = myPlane.remove_one_bullet(it->getx(),it->gety());
		if (temp){//is hit	
			list<Enemy>::iterator it2=it;
			it2->clear_all_bullet();//清除该敌机所有子弹
			it2->destroy_my_plane();
			it++;
			enemy_array.erase(it2);
			score++;
		}
		else{//is not hit
			if ((myPlane.getx() == it->getx() && (myPlane.gety() + 1 == it->gety() || myPlane.gety() - 1 == it->gety() || myPlane.gety() == it->gety())) || it->hit_plane(myPlane.getx(), myPlane.gety())){//my aircraft crash enemy
				//my plane is hit by enemy
				myPlane.destroy_my_plane();
				myPlane.clear_all_bullet();
				status = NEXT;
				it++;
				myPlane.life--;
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
		if (it->all_bullet_move(myPlane.getx(), myPlane.gety()) == NEXT){
			myPlane.life--;
			myPlane.destroy_my_plane();
			myPlane.clear_all_bullet();
			status = NEXT;
		}
	}
}

void Control::do_bomb(){
	list<Enemy>::iterator it = enemy_array.begin();
	for (; it != enemy_array.end(); ){
		it->clear_all_bullet();
		list<Enemy>::iterator it2 = it;
		it++;
		it2->destroy_my_plane();
		enemy_array.erase(it2);
	}
}