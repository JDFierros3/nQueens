#include "internals.h"


using namespace std;


/********************************   Node   ******************************/

Node::Node() {
//    distance = SHRT_MAX;   // Infinite distance to goal
}

Node::Node(Node* p,State s,Score uc) {
    parent = p;
    state = s;

}

StateList Node::getActions(){
        StateList sl;
        for(unsigned int i=0;i<state.size();i++){
            int r= rand()%state.size();
            state.at(r)=i;
            sl.push_back(state);
        }
        return sl;
}

bool
Node::operator==(const Node& n) {
    return state == n.state;
}

void Node::print() const{
    for(unsigned int i=0;i<state.size();i++){
        for(unsigned int j=0;j<state.size();j++){
            if((unsigned)state.at(j)==i){
                cout<<"[Q]";
            }
            else{
                cout<<"[ ]";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}



void
Node::traceBack() {
    stack<Node*> ns;
    Node* p = this;
    while (p) {
        ns.push(p);
        p = p->parent;
    }
    while (!ns.empty()) {
        Node* np = ns.top();
        np->print();
        ns.pop();
    }
}

State
Node::getState() const {
    return state;
}
