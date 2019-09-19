#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct lista lst;

struct lista
{
	int v;
	lst* ant;
	lst* prox;
};

lst* iserir (lst* inicio, int valor)
{
	lst* novo = (lst*) malloc(sizeof(lst));
	novo->v = valor;
	if(inicio == NULL)
	{
		novo->ant = NULL;
		novo->prox = NULL;
		return novo;
	}
	else
	{
		novo->ant = NULL;
		novo->prox = inicio;
		inicio ->ant = novo;
		return novo;
	}
}

void imprimir(lst* inicio)
{
	for(lst* i = inicio; i != NULL; i = i->prox)
	{
		cout << i->v << " "<<endl;
	}
}

lst* excluir(lst* inicio)
{
	if(inicio != NULL)
	{
		lst* aux = inicio;
		inicio = inicio ->prox;
		if(inicio != NULL)
			inicio->ant = NULL;
		free(aux);
	}
	return inicio;
}

int main(int argc, char** argv)
{
	lst* inicio = NULL;
	inicio = iserir(inicio,40);
	inicio = iserir(inicio,30);
	inicio = iserir(inicio,20);
	inicio = iserir(inicio,10);
	imprimir(inicio);
	cout<<"---------------------"<<endl;
	excluir(inicio);
	imprimir(inicio);
	return 0;
}
