#include<list>
#include<iostream>
using namespace std;

class MyBullet;

class AirCraft{
private:
	//position of airCraft
	int x;
	int y;
	
public:
	list<MyBullet> bullet_array;//save my bullet on display

	AirCraft(int x_pos, int y_pos){
		x = x_pos;
		y = y_pos;
	}


	//get and set
	int getx(){ return x; }
	int gety(){ return y; }
	void setx(int x_pos){ x = x_pos; }
	void sety(int y_pos){ y = y_pos; }

	//move action
	void mv_up();
	void mv_down();
	void mv_left();
	void mv_right();

	//shoot bullet
	void shooting();

	void draw_my_plane();
	void destroy_my_plane();
};

class MyBullet{
protected:
	//int left[2];
	int mid[2];
	//int right[2];
public:
	MyBullet(){}
	MyBullet(int x,int y);//x and y is aircraft's position
	int* get_mid(){ return mid; }
	void set_mid(int x,int y){ mid[0] = x; mid[1] = y; }
	void bullet_move(){ mid[0]--; }
	bool is_bullet_in_screen();

	//void delete_bullet(list<MyBullet>::iterator it);
	void draw_my_bullet();
	void destroy_my_bullet();
};