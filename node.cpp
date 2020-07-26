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
	this->h = (nodeSnake.head.i - nodeSnake.fruit.i)*(nodeSnake.head.i - nodeSnake.fruit.i) + (nodeSnake.head.j - nodeSnake.fruit.j)*(nodeSnake.head.j - nodeSnake.fruit.j);
	this->f = this->h;
	this->parentIndex = parentIndex;
}