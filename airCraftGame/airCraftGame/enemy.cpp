#include"common.h"

void Enemy::shooting(){
	EnemyBullet blt = EnemyBullet(x+1, y);
	bullet_array.push_back(blt);
}

int Enemy::all_bullet_move(int px,int py){
	//px py是myPlane位置
	list<EnemyBullet>::iterator it = bullet_array.begin();
	int stat = START;
	for (; it != bullet_array.end();){
		if (it->is_bullet_in_screen()){
			int *t = it->get_mid();
			if (t[0] != x)it->destroy_my_bullet();

			if ((t[0] == px&&(t[1]==py||t[1]==py-1|| t[1]==py+1))/*||(t[0]>px&&t[1]==py)*/){//判断敌机子弹是否撞上myplane
				list<EnemyBullet>::iterator it2 = it;
				it++;
				it2->destroy_my_bullet();
				bullet_array.erase(it2);
				stat = NEXT;
			}
			else{
				it->bullet_move();
				it->draw_my_bullet();
				it++;
			}
		}
		else{
			it->destroy_my_bullet();
			list<EnemyBullet>::iterator it_delete = it;
			it++;//防止断链
			bullet_array.erase(it_delete);
		}
	}
	return stat;
}

void Enemy::destroy_my_plane(){
	cursorPos(x, y);
	cout << " ";
}

void Enemy::draw_my_plane(){
	cursorPos(x, y);
	setColor(FOREGROUND_RED);
	cout << "V";
	setColor(0);
}

bool Enemy::hit_plane(int myx,int myy){
	return false;
}

void Enemy::is_hit(AirCraft myPlane){
	myPlane.remove_one_bullet(x,y);
	clear_all_bullet();
}

void Enemy::clear_all_bullet(){
	list<EnemyBullet>::iterator it;
	for (it = bullet_array.begin(); it != bullet_array.end();){
		list<EnemyBullet>::iterator it1 = it;
		it1->destroy_my_bullet();
		it++;
		bullet_array.erase(it1);
	}
}