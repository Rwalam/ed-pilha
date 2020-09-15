#include <iostream>
#include <cstring>
#include "Item.h"
//#include <stack>
using namespace std;

typedef struct{
    Item vec;
    int topo;
    int size;
} Stack;

Stack criaPilha(int size){
    Stack a;
    a.size = size;
    do
        a.vec = new (nothrow) Item[size];
    while(a.vec == nullptr);
    
    a.topo = 

    return a; 
}


void empilhar(){

}




int main(){

}