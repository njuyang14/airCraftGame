#include"common.h"

void Enemy::shooting(){
	EnemyBullet blt = EnemyBullet(x+1, y);
	bullet_array.push_back(blt);
}

void Enemy::all_bullet_move(){
	list<EnemyBullet>::iterator it = bullet_array.begin();
	for (; it != bullet_array.end();){
		if (it->is_bullet_in_screen()){
			int *t = it->get_mid();
			if (t[0] != x)it->destroy_my_bullet();
			it->bullet_move();
			it->draw_my_bullet();
			it++;
		}
		else{
			it->destroy_my_bullet();
			list<EnemyBullet>::iterator it_delete = it;
			it++;//∑¿÷π∂œ¡¥
			bullet_array.erase(it_delete);
		}
	}
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
		it->destroy_my_bullet();
		it++;
		bullet_array.erase(it1);
	}
}