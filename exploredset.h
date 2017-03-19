#ifndef EXPLOREDSET_H
#define EXPLOREDSET_H

#include "internals.h"
#include <vector>
#include <algorithm>

typedef std::vector<Node*> ExploredNodes;
using namespace std;
class ExploredSet {
public:
    ExploredSet();
    ~ExploredSet();
    bool check(Node* n);
    bool add(Node* n);
    void print();
private:
    // this is what we need to do in C++ pre-2011 to be able to do
    // a conditional find in a vector.  This technique works for
    // any STL container that supports find_if
    struct NodeMatch {
        NodeMatch(Node *n) : toFind(n) {}
        bool operator() (const Node* n) {
            return (n->getState() == toFind->getState());
        }
        Node* toFind;
    };
    ExploredNodes exset;
};

#endif
