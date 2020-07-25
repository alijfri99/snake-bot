#include "bfs.h"
#include "snake.h"
#include "node.h"

bool isGoal(snake s)
{
	return(s.head.i == s.fruit.i&&s.head.j == s.fruit.j);
}

std::vector<std::string> bfs(snake s)
{
	node *init = new node(s, "", 0, NULL);
	if(isGoal)
}
