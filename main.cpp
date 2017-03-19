#include <iostream>
#include "agent.h"
#include <algorithm>
using namespace std;

int main(/*int argc,char* args*/) {
    //int size=0;
    /*if(argc<=1){
        while(size<=0){
            cout<<"enter number of queens: ";
            cin>>size;
        }
    }else{
        size = args[1];
    }
    while(size<=0){
        cout<<"enter number of queens: ";
        cin>>size;
    }*/
    srand(time(0));
    int j=5;
    while(j<100){
    Agent a(j);
    Node* p = a.search(a.getState());
    if(!p){
        cout<<"no solution";
        return 0;
    }
        cout<<j<<" queens:"<<endl;
        p->print();
        j++;
    }
}
