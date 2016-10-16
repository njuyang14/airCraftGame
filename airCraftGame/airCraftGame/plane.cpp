#include"common.h"

//void cursorPos(int x, int y);

void AirCraft::mv_up(){
	if (x > 1)x--;
}
void AirCraft::mv_down(){
	if (x < 15)x++;
}
void AirCraft::mv_left(){
	if (y > 2)y--;
}
void AirCraft::mv_right(){
	if (y < 39)y++;
}

void AirCraft::draw_my_plane(){
	cursorPos(x,y-1);
	cout << "pHq";
}

void AirCraft::destroy_my_plane(){
	cursorPos(x, y - 1);
	cout << "   ";
}

void AirCraft::shooting(){
	MyBullet blt = MyBullet(x, y);
	bullet_array.push_back(blt);

	//reflash the screen for bullet
	list<MyBullet>::iterator bullet_iterator;
	for (bullet_iterator = bullet_array.begin();bullet_iterator != bullet_array.end();){
		if (bullet_iterator->is_bullet_in_screen()){
			int *t = bullet_iterator->get_mid();
			if (t[0]!=x)bullet_iterator->destroy_my_bullet();
			bullet_iterator->bullet_move();
			bullet_iterator->draw_my_bullet();
			bullet_iterator++;
		}
		else{
			bullet_iterator->destroy_my_bullet();
			list<MyBullet>::iterator it_delete = bullet_iterator;
			bullet_iterator++;//防止断链
			bullet_array.erase(it_delete);
		}
	}
}

void AirCraft::clear_all_bullet(){
	list<MyBullet>::iterator it;
	for (it = bullet_array.begin(); it != bullet_array.end();){
		list<MyBullet>::iterator it1=it;
		it->destroy_my_bullet();
		it++;
		bullet_array.erase(it1);
	}
}