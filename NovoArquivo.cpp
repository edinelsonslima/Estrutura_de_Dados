#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Arvore no;
struct Arvore{
    int valor;
    
    no* esquerda;
    no* direita;
    
    
};

no* inserir (no* raiz, int valor){
    no* novo = (no*) malloc(sizeof(no));
    novo -> esquerda=NULL;
    novo -> direita=NULL;
    novo -> valor=valor;
    if(raiz==NULL){
        raiz=novo;
    }else{
        no* raizAux = raiz;
        no* ant;
        while(raizAux != NULL){
            ant=raizAux;
            if(raizAux -> valor>=valor){
                raizAux = raizAux -> esquerda;
            }else{
                raizAux = raizAux-> direita;
            }
        }
        if(ant -> valor >= valor){
            ant -> esquerda = novo;
        }else{
            ant->direita=novo;
        }
    }
    return raiz;
}

void exibirPreOrdem(no *raiz){
    if(raiz != NULL){
        cout<< raiz->valor <<endl;
        exibirPreOrdem(raiz->esquerda);
        exibirPreOrdem(raiz->direita);
    }
}

void exibirPosOrdem(no *raiz ){
    if (raiz != NULL){
        exibirPosOrdem(raiz->esquerda);
        exibirPosOrdem(raiz->direita);
        cout<<raiz->valor<<endl;
    }
}

void exibirEmOrdem(no *raiz){
    if(raiz != NULL){
        exibirEmOrdem(raiz->esquerda);
        cout<< raiz->valor <<endl;
        exibirEmOrdem(raiz->direita);
    }
}

bool Pesquisar (no *raiz, int v){
    if (raiz != NULL){
        while (raiz != NULL){
            if (raiz -> valor == v){
                return true;
            }else if (v <= raiz -> valor){
                raiz = raiz -> esquerda;
            }else{
                raiz = raiz -> direita;
            }
        }
    }
    return false;
}

no* remove(no* raiz,int v){
	no* novo = (no*) malloc(sizeof(no));
    no* no1;
    no* no2;
    
    
    if(raiz == NULL){
        return raiz;
    }else{
        no* AuxRem = raiz;
        no* paiAux = NULL;
        while(AuxRem != NULL){
            if(AuxRem -> valor == v){
                break;
            }
            paiAux = AuxRem;
            if (v <= AuxRem -> valor){
                AuxRem = AuxRem -> esquerda;
            }else{
                AuxRem = AuxRem -> direita;
            }
        }
    
        no* raizEsq = AuxRem -> esquerda;
        no* maiordir = raizEsq;
        
        
        
        while (maiordir -> direita != NULL){
            raizEsq = maiordir;
            maiordir = maiordir -> direita;
        }
        raizEsq -> direita = maiordir -> esquerda;
        maiordir -> direita = AuxRem -> esquerda;
        
        if (v <= paiAux -> valor){
            paiAux -> esquerda = maiordir;
        }else{
            paiAux -> direita = maiordir;
        }
        paiAux-> direita = maiordir-> direita;
		free(maiordir);       
    }
    return raiz;
 }