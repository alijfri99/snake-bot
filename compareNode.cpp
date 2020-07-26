#include "compareNode.h"
#include "node.h"
#include<vector>

compareNode::compareNode(std::vector<node> &nodes)
{
	this->nodes = &nodes;
}

bool compareNode::operator()(int const &index1, int const &index2)
{
	return  nodes->at(index1).f > nodes->at(index2).f;
}
