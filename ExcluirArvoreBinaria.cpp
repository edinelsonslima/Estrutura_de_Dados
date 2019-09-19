#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct No no;
struct No
{
	int valor;
	no* esq;
	no* dir;
};
no* inserir(no* raiz, int valor)
{
	no* novo = (no*) malloc(sizeof(no));
	novo->esq = NULL;
	novo->dir = NULL;
	novo->valor = valor;
	if(raiz == NULL)
	{
		raiz = novo;
	}
	else
	{
		no* auxRaiz = raiz;
		no* aux;
		while(auxRaiz != NULL)
		{
			aux = auxRaiz;
			if(valor <= auxRaiz->valor)
			{
				auxRaiz = auxRaiz->esq;
			}
			else
			{
				auxRaiz = auxRaiz->dir;
			}
		}
		if(valor <= aux->valor)
		{
			aux->esq = novo;
		}
		else
		{
			aux->dir = novo;
		}

	}
	return raiz;
}

bool pesquisar(no* raiz, int valor)
{
	if(raiz != NULL)
	{
		if(valor == raiz->valor)
		{
			pesquisar(raiz->esq, valor);
			pesquisar(raiz->dir, valor);
			return true;
		}
		return false;
	}

}

no* excluir(no * raiz, int v)
{
	if(raiz == NULL)
	{
		return raiz;
	}
	else
	{
		no* auxRemove = raiz;
		no* auxPai = NULL;

		while(auxRemove != NULL)
		{
			if(auxRemove->valor == v)
			{
				break;
			}
			auxPai = auxRemove;
			if(v <= auxRemove->valor)
			{
				auxRemove = auxRemove->esq;
			}
			else
			{
				auxRemove = auxRemove->dir;
			}
		}

		no* raizEsq = auxRemove->esq;
		no* maiorDir = raiz->esq;

		if(maiorDir != NULL)
		{
			while(maiorDir->dir != NULL)
			{
				raizEsq = maiorDir;
				maiorDir = maiorDir->dir;
			}
		}

		if(raiz->valor == v)
		{
			cout << maiorDir->valor << endl;
			cout << raizEsq->valor << endl;

			maiorDir->esq = raiz->esq;
			maiorDir->dir = raiz->dir;
			raizEsq->esq = NULL;
			free(raiz);	
		}

		raizEsq->dir = maiorDir->esq;
		maiorDir->esq = auxRemove->dir;
		maiorDir->dir = auxRemove->esq;
	
		if(v <= auxPai->valor)
		{
			auxPai->esq = maiorDir;
		}
		else
		{
			auxPai->dir = maiorDir;
		}
		free(auxRemove);
	}
	return raiz;
}
void imprimir(no * raiz)
{
	if(raiz != NULL)
	{
		cout << raiz->valor << " ";
		imprimir(raiz->esq);
		imprimir(raiz->dir);
	}
}

int main()
{
	no* raiz = NULL;
	raiz = inserir(raiz, 8);
	raiz = inserir(raiz, 3);
	raiz = inserir(raiz, 1);
	raiz = inserir(raiz, 6);
	raiz = inserir(raiz, 4);
	raiz = inserir(raiz, 2);
	raiz = inserir(raiz, 5);
	raiz = inserir(raiz, 7);
	raiz = inserir(raiz, 10);
	raiz = inserir(raiz, 14);
	raiz = inserir(raiz, 13);

	imprimir(raiz);
	cout << "\n" << endl;
	raiz = excluir(raiz, 8);
	imprimir(raiz);
	return 0;
}

