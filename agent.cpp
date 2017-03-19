#include "agent.h"
using namespace std;
Agent::Agent(){

}
Agent::Agent(int size){
    for(int i=0;i<size;i++){
        state.push_back((i+rand()%size)%size);
    }
}

void Agent::scramble(){
    for(unsigned int i=0;i<state.size();i++){
        state.at(i)=rand()%state.size();
    }
}
int scoreState(State s){
    int diff=0;
    unsigned int i;
    unsigned int j;
    int score;
    for(i=0;i<s.size();i++){
        for(j=i+1;j<s.size();j++){
            diff++;
            if(s.at(j)==s.at(i)) score++;
            else if(s.at(j)==(s.at(i))+diff)score++;
            else if(s.at(j)==(s.at(i))-diff)score++;
        }
        diff=0;
    }
    return score;
}
Node* Agent::search(State s){
    int ticks=0;
    int bscore = scoreState(s);
    Node* p = new Node(NULL,s,bscore);
    if(bscore==0)
        return p;
    while(true){
            if(bscore==0)
            return p;
        ticks++;
        if(ticks>200){
            scramble();
            p= new Node(NULL,getState(),scoreState(getState()));
            ticks=0;
        }
        if(bscore==0)
            return p;
        StateList sl = p->getActions();
        vector<State>::iterator ni;
        ticks++;
        for(ni=sl.begin();ni!= sl.end();ni++){
            int cscore = scoreState(*ni);
            Node* child = new Node(p,*ni,cscore);
            if(cscore<=bscore){
                bscore=cscore;
                p=child;
            }
        }
    }
}

