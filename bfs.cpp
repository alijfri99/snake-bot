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

std::vector<std::string> solution(node *n)
{
	std::vector<std::string> result;
	while (n->parent != NULL)
	{
		result.push_back(n->direction);
		n = n->parent;
	}
	return result;
}

std::vector<node *> successor(node *current)
{
	std::vector<node*> result;
	snake s = current->nodeSnake;
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

	node *nup = new node(sup, "up", (current->g) + 1, current);
	node *ndown = new node(sdown, "down", (current->g) + 1, current);
	node *nleft = new node(sleft, "left", (current->g) + 1, current);
	node *nright = new node(sright, "right", (current->g) + 1, current);

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
	std::cout << "In BFS!" << std::endl;
	node *init = new node(s, "GHOLI", 0, NULL);
	std::queue<node *> frontier;
	std::unordered_map<std::string, bool> inFrontier;
	std::unordered_map<std::string, bool> explored;
	frontier.push(init);
	inFrontier[init->nodeSnake.hash()] = true;
	while (!frontier.empty())
	{
		node *current = frontier.back();
		frontier.pop();
		inFrontier[current->nodeSnake.hash()] = false;
		explored[current->nodeSnake.hash()] = true;
		std::vector<node *> children = successor(current);
		while (!children.empty())
		{
			node *temp = children.back();
			children.pop_back();
			if (explored[temp->nodeSnake.hash()] == false && inFrontier[temp->nodeSnake.hash()] == false)
			{
				if (isGoal(temp->nodeSnake))
					return solution(temp);
				frontier.push(temp);
				inFrontier[temp->nodeSnake.hash()] = true;
			}
		}
	}
}
