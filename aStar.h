#ifndef ASTAR_H
#define ASTAR_H
#include<vector>
#include "snake.h"
#include "node.h"

void aStar(snake s, std::vector<std::string> &returnVector);
bool isGoal(const snake &s);
void solution(const std::vector<node> &nodes, node n, std::vector<std::string> &returnVector);
std::vector<node> successor(const std::vector<node> &nodes, int currentIndex);

#endif // !ASTAR

