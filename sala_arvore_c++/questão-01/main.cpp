#include <iostream>

using namespace std;

struct NoArvore{
	int data;
	NoArvore *esquerda;
	NoArvore *direita;
															
	NoArvore (int valor) : data(valor), esquerda(NULL), direita(NULL) {}
};

void posOrdem (NoArvore *raiz){
	if(raiz != NULL){
		posOrdem(raiz -> esquerda);
		posOrdem(raiz -> direita);
		cout << raiz -> data << " ";
	}
}

void deleteArvore(NoArvore *raiz){
	if(raiz != NULL){
		deleteArvore(raiz -> esquerda);
		deleteArvore(raiz -> direita);
		delete raiz;
	}
}

int main() {
	NoArvore *raiz = new NoArvore (1);
	NoArvore *num1 = new NoArvore (2);
	NoArvore *num2 = new NoArvore (3);
	
	raiz -> esquerda = num1;
	raiz -> direita = num2;
	
	NoArvore *num3 = new NoArvore (4);
	
	num1 -> esquerda = num3;
	num1 -> direita = NULL;
	
	NoArvore *num4 = new NoArvore (5);
	
	num2 -> esquerda = num4;
	
	NoArvore *num5 = new NoArvore (6);
	
	num2 -> direita = num5;
	
	posOrdem(raiz);

	deleteArvore(raiz);
	
	posOrdem(raiz);
	
	return 0;
}
