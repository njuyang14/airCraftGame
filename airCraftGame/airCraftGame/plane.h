
class AirCraft{
private:
	//position of airCraft
	int x;
	int y;

public:
	AirCraft(int x_pos, int y_pos){
		x = x_pos;
		y = y_pos;
	}
	//move action
	void mv_up();
	void mv_down();
	void mv_left();
	void mv_right();
	//shoot bullet
	void shooting();

	void draw_my_plane(int xp,int yp);
};