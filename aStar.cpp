#include<queue>
#include<unordered_map>
#include "aStar.h"
#include "snake.h"
#include "node.h"
#include "compareNode.h"
#include "tools.h"

bool isGoal(const snake &s)
{
	return(s.head.i == s.fruit.i&&s.head.j == s.fruit.j);
}

void solution(const std::vector<node> &nodes, node n, std::vector<std::string> &returnVector)
{
	while (n.parentIndex != NULL)
	{
		returnVector.push_back(n.direction);
		n = nodes[n.parentIndex];
	}
	returnVector.push_back(n.direction);
}

std::vector<node> successor(const std::vector<node> &nodes, int currentIndex)
{
	std::vector<node> result;
	node current = nodes[currentIndex];
	snake s = current.nodeSnake;
	snake sup, sdown, sleft, sright;
	sup = s;
	sdown = s;
	sleft = s;
	sright = s;

	sup.turn(direction::up);
	sup.move();

	sdown.turn(direction::down);
	sdown.move();

	sleft.turn(direction::left);
	sleft.move();

	sright.turn(direction::right);
	sright.move();

	node nup(sup, "up", (current.g) + 1, currentIndex);
	node ndown(sdown, "down", (current.g) + 1, currentIndex);
	node nleft(sleft, "left", (current.g) + 1, currentIndex);
	node nright(sright, "right", (current.g) + 1, currentIndex);

	switch (s.currentDirection) //add successor nodes to the result based on the current direction, and only if the snake stays within the map
	{
		case 0: //up
			if(!gameover(sup))
				result.push_back(nup);
			if(!gameover(sleft))
				result.push_back(nleft);
			if(!gameover(sright))
				result.push_back(nright);
			break;
		case 1: //down
			if(!gameover(sdown))
				result.push_back(ndown);
			if (!gameover(sleft))
				result.push_back(nleft);
			if (!gameover(sright))
				result.push_back(nright);
			break;
		case 2: //left
			if (!gameover(sup))
				result.push_back(nup);
			if (!gameover(sdown))
				result.push_back(ndown);
			if (!gameover(sleft))
				result.push_back(nleft);
			break;
		case 3: //right
			if (!gameover(sup))
				result.push_back(nup);
			if (!gameover(sdown))
				result.push_back(ndown);
			if (!gameover(sright))
				result.push_back(nright);
			break;
	}
	return result;
}

void aStar(snake s, std::vector<std::string> &returnVector)
{
	int time = 0;
	std::vector<node> nodes(100000);
	int index = 0;
	node init(s, "right", 0, NULL);
	nodes[index] = init;
	std::priority_queue<int, std::vector<int>, compareNode> frontier(nodes);
	std::unordered_map<std::string, bool> inFrontier;
	std::unordered_map<std::string, bool> inExplored;
	frontier.push(index);
	inFrontier[init.nodeSnake.hash()] = true;
	while (!frontier.empty())
	{
		int currentIndex = frontier.top();
		node current = nodes[currentIndex];
		frontier.pop();
		inFrontier[current.nodeSnake.hash()] = false;
		inExplored[current.nodeSnake.hash()] = true;
		std::vector<node> children = successor(nodes,currentIndex);
		while (!children.empty())
		{
			node temp = children.back();
			children.pop_back();
			if (inExplored[temp.nodeSnake.hash()] == false && inFrontier[temp.nodeSnake.hash()] == false)
			{
				if (isGoal(temp.nodeSnake))
				{
					solution(nodes, temp, returnVector);
					return;
				}
				index++;
				nodes[index] = temp;
				frontier.push(index);
				inFrontier[temp.nodeSnake.hash()] = true;
			}
		}
	}
	return;
}
