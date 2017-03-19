#ifndef AGENT_H
#define AGENT_H
#include "internals.h"
class Agent {
public:
    Agent();
    Agent(int s);
    void scramble();
    Node* search(State);
    void printExploredSet();
    void printFrontier();
    State getState() {return state;}

private:
    //ExploredSet exset;
    State state;
};

#endif
