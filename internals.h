#ifndef MYPQ_H
#define MYPQ_H
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
#include <algorithm>
#include <limits>
#include "state.h"
class Node;
class InsertCompare;
typedef int Score;
class Node {
public:
    Node();
    Node(Node*,State,Score);	// score is distance or heuristic, depending
    bool operator==(const Node&);
    void traceBack();
    State getState() const;
    int getScore(int type);
    StateList getActions();
    Node* getParent(){return parent;}
    void print() const;   	// for debugging ...
private:
    Node* parent;
    State state;

};



#endif

