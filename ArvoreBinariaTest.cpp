#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Arvore no;

struct Arvore
{
	int valor;
	no* esq;
	no* dir;
};

no* inserir (no* raiz, int valor)
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
		no* raizAux = raiz;
		no* ant;
		while(raizAux != NULL)
		{
			ant = raizAux;
			if(raizAux->valor >= valor)
			{
				raizAux = raizAux ->esq;
			}
			else
			{
				raizAux = raizAux ->dir;
			}
		}
		if(ant->valor >= valor)
		{
			ant->esq = novo;
		}
		else
		{
			ant->dir = novo;
		}
	}


	return raiz;
}

void imprimir(no* raiz, int op)
{
	switch(op)
	{
		case 1://PRE ORDEM
		if(raiz != NULL)
		{
			cout << raiz->valor << " ";
			imprimir(raiz->esq,op);
			imprimir(raiz->dir,op);
		}
		break;

		case 2://IN ORDEM
		if(raiz != NULL)
		{
			imprimir(raiz->esq,op);
			cout << raiz->valor << " ";
			imprimir(raiz->dir,op);
		}
		break;
	
		case 3://POS ORDEM
		if(raiz != NULL)
		{
			imprimir(raiz->esq,op);
			imprimir(raiz->dir,op);
			cout << raiz->valor << " ";
		}
		break;
	}
}



void excluir(no*raiz, int valor)
{
	if(raiz != NULL)
	{
		if(valor == raiz->valor)
		{
			raiz->valor = NULL;
		}
		excluir(raiz->esq, valor);
		excluir(raiz->dir, valor);
	}
}

int main(int argc, char** argv)
{	int op;
	no* raiz = NULL;
	raiz = inserir(raiz, 8);
	raiz = inserir(raiz, 3);
	raiz = inserir(raiz, 1);
	raiz = inserir(raiz, 6);
	raiz = inserir(raiz, 4);
	raiz = inserir(raiz, 7);
	raiz = inserir(raiz, 10);
	raiz = inserir(raiz, 14);
	raiz = inserir(raiz, 13);

	cout<<"1.PRE ORDEM"<<endl;
	cout<<"2.IN ORDEM"<<endl;
	cout<<"3.POS ORDEM"<<endl;
	cout<<"\nSua opcao: ";
	cin>>op;

	imprimir(raiz,op);
	excluir(raiz, 01);
	cout<< endl;
	cout<<"| | | | | |  |  |  |"<<endl;
	imprimir(raiz,op);

	return 0;
}

/*void imprimir(no* raiz){
 *	no* esqAux = raiz->esq;
 *	no* raizAux = raiz;
 *	no* ant = raizAux;
 *	if(raiz != NULL)
 *	{
 *		cout << raiz->valor << endl;
 *	}
 *	while(esqAux!= NULL)
 *	{
 *		cout << esqAux->esq->valor << endl;
 *		cout << raiz ->dir->valor << endl;
 *	}
}*/


/*void excluir(no*raiz, int valor){
 *		else if(valor == raiz->esq->valor)
 *	{
 *		raiz->esq->valor = NULL;
 *	}
 *	else if(valor == raiz->dir->valor)
 *	{
 *		raiz->dir->valor = NULL;
 *	}
 *	}else
 *	{
 *	cout<<"\nPrimeiro insira elementos na Arvore"<<endl;
 *	}
}*/

