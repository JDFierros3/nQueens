#include "exploredset.h"
using namespace std;
ExploredSet::ExploredSet(){
}

ExploredSet::~ExploredSet(){

}

bool ExploredSet::check(Node* n){
	vector<Node*>::iterator vi;
	return find_if(exset.begin(),exset.end(),NodeMatch(n)) != exset.end();

	/*for(vi=exset.begin();vi!=exset.end();vi++){
		if(*vi==n)
			return true;
	}
	return false;*/
}

bool ExploredSet::add(Node* n){
    exset.push_back(n);
    return true;
}

void ExploredSet::print(){
    vector<Node*>::iterator si;
    for(si=exset.begin();si!=exset.end();si++){
//        *si->getState().print();
    }
}

