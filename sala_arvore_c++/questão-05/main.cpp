#include <iostream>

using namespace std;

struct NoArvore{
	int data;
	NoArvore *esquerda;
	NoArvore *direita;
															
	NoArvore (int valor) : data(valor), esquerda(NULL), direita(NULL) {}
};

void preOrdem (NoArvore *raiz){
	if(raiz != NULL){
		cout << raiz -> data << " ";
		preOrdem(raiz -> esquerda);
		preOrdem(raiz -> direita);
		
	}
}

int somarArvore(NoArvore *raiz){
	int soma = 0;
	if(raiz != NULL){
		soma += raiz->data;
		soma += somarArvore(raiz -> esquerda);
		soma += somarArvore(raiz -> direita);
	}
	return soma;
}

int tamArvore(NoArvore *raiz){
	int cont = 0;
	if(raiz != NULL){
		cont += 1;
		cont += tamArvore(raiz -> esquerda);
		cont += tamArvore(raiz -> direita);
	}
	return cont;
}


int main() {
	NoArvore *raiz = new NoArvore (2);
	NoArvore *num1 = new NoArvore (7);
	NoArvore *num2 = new NoArvore (5);
	
	raiz -> esquerda = num1;
	raiz -> direita = num2;
	
	NoArvore *num3 = new NoArvore (2);
	NoArvore *num4 = new NoArvore (6);
	
	num1 -> esquerda = num3;
	num1 -> direita = num4;
	
	NoArvore *num5 = new NoArvore (5);
	
	num4 -> esquerda = num5;
	
	NoArvore *num6 = new NoArvore (11);
	
	num4 -> direita = num6;
	
	NoArvore *num7 = new NoArvore (9);
	NoArvore *num8 = new NoArvore (4);
	
	num2 -> direita = num7;
	num7 -> esquerda = num8;
	
	preOrdem(raiz);
	float tamanho = tamArvore(raiz);
	float tam = somarArvore(raiz);
	float media = tam / tamanho;
	cout << endl;
	printf("%.2f", media);
	
	return 0;
}

