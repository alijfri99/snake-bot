#include "node.h"
#include "snake.h"
#include<string>

node::node(snake nodeSnake, std::string direction, int g, node *parent)
{
	this->nodeSnake = nodeSnake;
	this->direction = direction;
	this->g = g;
	this->parent = parent;
}