#include "node.h"
#include "snake.h"
#include<string>

node::node()
{

}

node::node(snake nodeSnake, std::string direction, int g, int parentIndex)
{
	this->nodeSnake = nodeSnake;
	this->direction = direction;
	this->g = g;
	this->parentIndex = parentIndex;
}