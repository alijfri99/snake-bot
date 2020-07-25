#ifndef NODE_H
#define NODE_H
#include "snake.h"

class node
{
public:
	snake nodeSnake;
	std::string direction;
	int g;
	int parentIndex;
	node();
	node(snake nodeSnake, std::string direction, int g, int parentIndex);
};

#endif
