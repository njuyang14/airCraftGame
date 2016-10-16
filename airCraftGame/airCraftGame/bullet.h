#ifndef _BULLET_H_
#define _BULLET_H_

class MyBullet{
protected:
	int mid[2];//save position of bullet
public:
	MyBullet(){}
	MyBullet(int x, int y);//x and y is aircraft's position
	int* get_mid(){ return mid; }
	void set_mid(int x, int y){ mid[0] = x; mid[1] = y; }
	void bullet_move(){ mid[0]--; }
	bool is_bullet_in_screen();

	//void delete_bullet(list<MyBullet>::iterator it);
	void draw_my_bullet();
	void destroy_my_bullet();
};

class EnemyBullet:public MyBullet{
public:
	void bullet_move(){ mid[0]++; }
	void draw_my_bullet();
};

#endif