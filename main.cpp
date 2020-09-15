#include <iostream>
#include "Stack.h"
#include "Item.h"
using namespace std;

int main(int argc, char *argv[])
{
	Stack pilha(20);

	Item it = 2.0;
	for(int i = 1; i <= 10; i++)
		pilha.push(it * i);

	while( ! pilha.empty() )
		cout << pilha.pop() << endl;

	return 0;
}