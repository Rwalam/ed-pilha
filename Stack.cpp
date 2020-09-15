#include <iostream>
#include "Stack.h"
#include "Item.h"
using namespace std;

Stack::Stack(int n) {
    _capacity = n;
    _vec = new (std::nothrow) Item[n];
    if(_vec == nullptr) {
        cerr << "Memoria insuficiente" << endl;
        exit(1);
    }
    _top = 0;
}

Stack::~Stack() {
    if(_vec != nullptr) 
        delete[] _vec;
    cout << "Pilha destruida" << endl;
}

// Inserir elemento no topo
void Stack::push(Item v) {
    if(_top < _capacity) {
        _vec[_top] = v;
        _top++;
    }
    else cerr << "Estouro de pilha" << endl;
}

// Remover elemento do topo
Item Stack::pop() {
    if( !empty() ) {
        _top--;
        return _vec[_top];
    }
    else {
        cerr << "Pilha vazia" << endl;
        exit(1);
    }
}

// Consulta elemento no topo
// Supõe que só é chamado quando pilha tem elementos
Item Stack::top() {
    return _vec[_top-1];
}

// Pilha esta vazia?
bool Stack::empty() {
    return (_top == 0);
} 

// Pilha esta cheia?  
bool Stack::full() {
    return (_top == _capacity);
} 