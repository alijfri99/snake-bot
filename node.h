#ifndef NODE_H
#define NODE_H
#include "snake.h"

class node
{
public:
	snake nodeSnake;
	std::string direction;
	int g;
	node *parent;
	node(snake nodeSnake, std::string direction, int g, node *parent);
};

#endif
