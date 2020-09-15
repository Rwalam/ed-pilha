#include <iostream>
#include <cstring>
#include <stack> // para usar a pilha do c++
using namespace std;

// Esta funcao devolve true se exp contiver uma
// sequencia bem-formada de parenteses e chaves e 
// devolve false se a sequencia estiver malformada.
bool BemFormada(char exp[]) {
    stack<char> pilha;
	
    for(int i = 0; exp[i] != '\0'; i++) {
        switch(exp[i]) {
            case ')': if(!pilha.empty() && pilha.top() == '(')
                          pilha.pop();
                      else return false;
                      break;
            case '}': if(!pilha.empty() && pilha.top() == '{')
                          pilha.pop();
                      else return false;
                      break;
            default : pilha.push(exp[i]);
        }
    }
    return pilha.empty();
}

// Supõe que posfix[] contem expressao posfixa valida
float calculaPosfixa(char posfix[], float val[]) {
	float a, b;
	stack<float> pilha;
	
	for(int i = 0; posfix[i] != '\0'; i++) {
		if(posfix[i] >= 'A' && posfix[i] <= 'Z') 
			pilha.push( val[posfix[i] - 'A'] );
		else {
			a = pilha.top(); pilha.pop();
			b = pilha.top(); pilha.pop();
			switch(posfix[i]) {
				case '+': pilha.push(b + a); break;
				case '-': pilha.push(b - a); break;
				case '*': pilha.push(b * a); break;
				case '/': pilha.push(b / a); break;
			}
		}	
	}
	return pilha.top();
}

/**
 * Funcao que converte uma expressao aritmetica
 * completamente parentizada para uma expressao
 * equivalente na notacao posfixa (polonesa reversa).
 * Supomos que cada operando eh uma letra do alfabeto
 * e que os operadores sao +, -, * e /
 * A funcao tambem supoe que a expressao passada por
 * parametro esta corretamente parentizada.
 */
char* ParentizadaParaPosfixa(char exp[]) { // prog04.cpp
    int iPos = 0;
    char *posfix = new char[ strlen(exp) ];
    stack<char> pilha;
	
    for(int i = 0; exp[i] != '\0'; i++) {
        switch(exp[i]) {
            case '(': break;
            case ')': posfix[iPos++] = pilha.top(); 
                      pilha.pop();
                      break;
            case '+':
            case '-':
            case '*':
            case '/': pilha.push(exp[i]);
                      break;
            default : posfix[iPos++] = exp[i];
        }	
    }
    posfix[iPos] = '\0';
    return posfix;
}

int main() {
	char expressao[] = "((A+B)*(C/D))";
	cout << "Expressao parentizada: " << expressao << endl;
	
	char *posfix = ParentizadaParaPosfixa(expressao);
	cout << "Expressao posfixa: " << posfix << endl;
	
	float valores[26] = {10,2,9,5};
	
	float resp = calculaPosfixa(posfix, valores);
	cout << "Valor da expressao: " << resp << endl;
	
	char exp[] = "({}(({}{}{{})))";
	if(BemFormada(exp))
		cout << "A expressao " << exp << " eh bem-formada" << endl;
	else 
		cout << "A expressao " << exp << " eh malformada" << endl;	
	
	return 0;
}
