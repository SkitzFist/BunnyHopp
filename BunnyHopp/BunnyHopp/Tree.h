#ifndef _Tree
#define _Tree

#include <vector>

struct Node {
public:
	Node(int _height) {
		height = _height;
	}
	int height;
};

class Tree {
public:
	Tree(const std::vector<int>& vec);
	~Tree();

	int getMaxJumps(int startIndex, int jumps);
	const std::vector<Node*> getNodes() const;

private:
	std::vector<Node*> nodes;
	
};

#endif