#ifndef ASTAR_H
#define ASTAR_H
#include<vector>
#include "snake.h"
#include "node.h"

std::vector<std::string> aStar(snake s);
bool isGoal(const snake &s);
std::vector<std::string> solution(const std::vector<node> &nodes, node n);
std::vector<node> successor(const std::vector<node> &nodes, int currentIndex);

#endif // !ASTAR

