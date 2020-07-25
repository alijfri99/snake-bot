#ifndef BFS_H
#define BFS_H
#include<vector>
#include "snake.h"
#include<string>

std::vector<std::string> bfs(snake s);
bool isGoal(snake s);
std::vector<std::string> solution(node n);

#endif // !BFS_H

