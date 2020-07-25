#ifndef BFS_H
#define BFS_H
#include<vector>
#include<queue>
#include "snake.h"
#include "node.h"

std::vector<std::string> bfs(snake s);
bool isGoal(const snake &s);
std::vector<std::string> solution(node nodes[], node n);
std::vector<node> successor(node nodes[], int currentIndex);
void deleteNodes(std::queue<node *> &q);

#endif // !BFS_H

