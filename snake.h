#ifndef SNAKE_H
#define SNAKE_H
#include "point.h"
#include<string>

enum direction{up,down,left,right};

class snake
{
public:
	int bodysize;
	int score;
	point head;
	point body[798];
	point blank;
	point fruit;
	direction currentDirection;
	snake();
	void print();
	void follow();
	void move();
	void turn(direction dir);
	void generateFruit();
	void increaseSize();
	std::string hash();
};

#endif // !SNAKE_H

