#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
typedef struct fila f;
struct fila
{
	int num;
	f* prox;
};

f* inserir(f* fim, int valor)
{
	f* novo = (f*) malloc(sizeof(f));
	novo->num = valor;
	if(fim != NULL)
		fim ->prox = novo;
	novo->prox = NULL;
	return novo;
}

f* excluir(f* inicio)
{
	if(inicio != NULL)
	{
		f*aux = inicio;
		inicio = inicio->prox;
		free(aux);
	}
	else
		cout << "Fila Vazia" << endl;
	return inicio;
}

void imprimir(f* inicio)
{
	for(f* i = inicio; i != NULL; i = i->prox)
	{
		cout << i->num << endl;
	}
}


int main()
{
	f*fim = NULL;
	f*inicio = NULL;

	fim = inserir(fim, 11);
	inicio = fim;
	fim = inserir(fim, 12);
	fim = inserir(fim, 13);
	imprimir(inicio);
	cout << endl;
	inicio = excluir(inicio);
	
	imprimir(inicio);

	return 0;
}
