#ifndef COMPARENODE_H
#define COMPARENODE_H
#include<vector>
#include "node.h"

class compareNode
{
public:
	std::vector<node> *nodes;
	compareNode(std::vector<node> &nodes);
	bool operator ()(int const &index1, int const &index2);
};

#endif // !COMPARENODE_H

