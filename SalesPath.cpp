#include <iostream>
#include <vector>
#include <algorithm>
//#include <queue>

using namespace std;

struct Node {
    int cost;
    vector<Node *> children;
    Node *parent;
};

int getCheapestCost(Node *rootNode) {
    // your code goes here

    if (rootNode->children.size() < 1)
        return rootNode->cost;

    vector<int> costs;
    for (Node &n : rootNode->children) {

        costs.push_back(rootNode->cost + getCheapestCost(n));
    }

    return std::min_element(costs.begin(), costs.end());
}

// Time: O(V), Space: O(Depth)
int main() {

    return 0;
}
/*
{0+{5+{4}}, 0+{3}}

*/