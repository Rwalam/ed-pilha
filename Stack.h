#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Item.h"

class Stack {
    private: 
        Item *_vec; // Ponteiro para um vetor de Item
        int _top; // Posicao do proximo slot disponivel
        int _capacity; // Tamanho total do vetor
    public: 
        Stack(int n); // Construtor: recebe capacidade
        ~Stack(); // Destrutor: libera memoria alocada
        void push(Item v); // Inserir elemento no topo
        Item pop(); // Remover elemento do topo
        Item top(); // Consulta elemento no topo
        bool empty(); // Pilha esta vazia?
        bool full(); // Pilha esta cheia?
};
#endif
