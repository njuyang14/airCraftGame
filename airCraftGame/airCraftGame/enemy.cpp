#include"common.h"

void Enemy::shooting(){
}

void Enemy::destroy_my_plane(){
	cursorPos(x, y);
	cout << " ";
}

void Enemy::draw_my_plane(){
	cursorPos(x, y);
	cout << "V";
}

bool Enemy::hit_plane(int myx,int myy){
	return false;
}

void Enemy::is_hit(AirCraft myPlane){
	myPlane.remove_one_bullet(x,y);
}

void Enemy::clear_all_bullet(){
	/*list<EnemyBullet>::iterator it;
	for (it = bullet_array.begin(); it != bullet_array.end();){
		list<EnemyBullet>::iterator it1 = it;
		it->destroy_my_bullet();
		it++;
		bullet_array.erase(it1);
	}*/
}