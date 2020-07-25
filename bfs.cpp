#include "bfs.h"
#include "snake.h"
#include "node.h"
#include<queue>
#include<unordered_map>

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

	switch (s.currentDirection) //add successor nodes to the result based on the current direction
	{
		case 0: //up
			result.push_back(nup);
			result.push_back(nleft);
			result.push_back(nright);
			break;
		case 1: //down
			result.push_back(ndown);
			result.push_back(nleft);
			result.push_back(nright);
			break;
		case 2: //left
			result.push_back(nup);
			result.push_back(ndown);
			result.push_back(nleft);
			break;
		case 3: //right
			result.push_back(nup);
			result.push_back(ndown);
			result.push_back(nright);
			break;
	}
}

std::vector<std::string> bfs(snake s)
{
	node *init = new node(s, "GHOLI", 0, NULL);
	std::queue<node *> frontier;
	std::unordered_map<std::string, bool> explored;
	frontier.push(init);
	while (!frontier.empty())
	{
		node *current = frontier.back();
		frontier.pop();
		explored[current->nodeSnake.hash()] = true;
	}
}
