#include "bfs.h"
#include "snake.h"
#include "node.h"
#include<queue>
#include<unordered_map>
#include<iostream>

bool isGoal(const snake &s)
{
	return(s.head.i == s.fruit.i&&s.head.j == s.fruit.j);
}

std::vector<std::string> solution(node nodes[], node n)
{
	std::vector<std::string> result;
	while (n.parentIndex != NULL)
	{
		result.push_back(n.direction);
		n = nodes[n.parentIndex];
	}
	result.push_back(n.direction);
	return result;
}

void deleteNodes(std::queue<node *> &q)
{
	while (!q.empty())
	{
		node *temp = q.front();
		q.pop();
		delete temp;
	}
}

std::vector<node> successor(node nodes[], int currentIndex)
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
			if(sup.head.i>0)
				result.push_back(nup);
			if(sleft.head.j>0)
				result.push_back(nleft);
			if(sright.head.j<39)
				result.push_back(nright);
			break;
		case 1: //down
			if(sdown.head.i<19)
				result.push_back(ndown);
			if (sleft.head.j > 0)
				result.push_back(nleft);
			if (sright.head.j < 39)
				result.push_back(nright);
			break;
		case 2: //left
			if (sup.head.i > 0)
				result.push_back(nup);
			if (sdown.head.i < 19)
				result.push_back(ndown);
			if (sleft.head.j > 0)
				result.push_back(nleft);
			break;
		case 3: //right
			if (sup.head.i > 0)
				result.push_back(nup);
			if (sdown.head.i < 19)
				result.push_back(ndown);
			if (sright.head.j < 39)
				result.push_back(nright);
			break;
	}
	return result;
}

std::vector<std::string> bfs(snake s)
{
	node *nodes = new node[200000];
	int index = 0;
	node init(s, "", 0, NULL);
	nodes[index] = init;
	std::queue<int> frontier;
	std::unordered_map<std::string, bool> inFrontier;
	std::unordered_map<std::string, bool> inExplored;
	frontier.push(index);
	inFrontier[init.nodeSnake.hash()] = true;
	while (!frontier.empty())
	{
		int currentIndex = frontier.front();
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
					std::vector<std::string> sol = solution(nodes, temp);
					delete[] nodes;
					return sol;
				}
				index++;
				nodes[index] = temp;
				frontier.push(index);
				inFrontier[temp.nodeSnake.hash()] = true;
			}
		}
	}
}
