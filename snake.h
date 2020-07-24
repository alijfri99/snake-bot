#ifndef SNAKE_H
#define SNAKE_H
#include "point.h"

enum direction{up,down,left,right};

class snake
{
public:
	int bodysize;
	point head;
	point body[798];
	point blank;
	direction currentDirection;
	snake();
	void print();
	void follow();
	void move();
	void turn(direction dir);
};

#endif // !SNAKE_H

