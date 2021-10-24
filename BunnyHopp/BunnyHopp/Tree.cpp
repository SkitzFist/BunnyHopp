#include "Tree.h"
#include <iostream>

Tree::Tree(const std::vector<int>& vec)
{
	//create nodes
	for (unsigned int i = 0; i < vec.size(); ++i) {
		Node* n = new Node(vec[i]);
		nodes.push_back(n);
	}
}

Tree::~Tree()
{
	
}

int Tree::getMaxJumps(int index, int jumps)
{
	Node* node = nodes[index];
	
	std::vector<int> jumpableNeighboursIndex;
	for (int i = -2; i < 3; ++i) {
		int newIndex = index + i;
		if (newIndex >= 0 && newIndex < (int)nodes.size() && newIndex != index) {
			if (nodes[index]->height > nodes[newIndex]->height) {
				jumpableNeighboursIndex.push_back(newIndex);
			}
		}
	}

	if (jumpableNeighboursIndex.size() == 0) {
		return jumps;
	}
	else {
		int highestJump = 0;
		for (unsigned int i = 0; i < jumpableNeighboursIndex.size(); ++i) {
			int jump = getMaxJumps(jumpableNeighboursIndex[i], (jumps + 1));
			if (jump > highestJump) {
				highestJump = jump;
			}
		}
		return highestJump;
	}
}

const std::vector<Node*> Tree::getNodes() const
{
	return nodes;
}
