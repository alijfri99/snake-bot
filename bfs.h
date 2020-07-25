#ifndef BFS_H
#define BFS_H
#include<vector>
#include "snake.h"
#include "node.h"

std::vector<std::string> bfs(snake s);
bool isGoal(const snake &s);
std::vector<std::string> solution(node *n);
std::vector<node *> successor(node *current);

#endif // !BFS_H

