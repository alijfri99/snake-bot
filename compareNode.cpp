#include "compareNode.h"
#include "node.h"
#include<vector>

compareNode::compareNode(std::vector<node> &nodes)
{
	this->nodes = &nodes;
}

bool compareNode::operator()(int const &index1, int const &index2)
{
	node node1 = nodes->at(index1);
	node node2 = nodes->at(index2);

	if (node1.f > node2.f)
		return true;
	else if (node1.f < node2.f)
		return false;
	else
		return node1.h > node2.h;
}
