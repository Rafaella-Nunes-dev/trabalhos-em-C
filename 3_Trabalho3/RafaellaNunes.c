#include <stdio.h>
#include <stdlib.h>

struct no
{
    struct no* esq;
    struct no* dir;
    int n;
};
typedef struct no No;

No* CriaNo(int valor){
    No* novo = malloc(sizeof(No));

    novo->dir = NULL;
    novo->esq = NULL;
    novo->n = valor;

    return novo;
}

int altura(No* Raiz)
{
    if(Raiz == NULL)
        return 0;
    int alturaesq = altura(Raiz->esq);
    int alturadir = altura(Raiz->dir);

    if(alturaesq>alturadir)
        return alturaesq + 1;
    else
        return alturadir + 1;
}

int FatorBalanceamento(No* Raiz)
{
    int fb = 0;
    if(Raiz != NULL)
    {
        fb = altura(Raiz->esq) - altura(Raiz->dir);
    }

    return fb;
}

No* RotDir(No* Raiz)
{
    No* filho = Raiz->esq;
    Raiz->esq = filho->dir;
    filho->dir = Raiz;

    return filho;
}

No* RotEsq(No* Raiz)
{
    No* filho = Raiz->dir;

    Raiz->dir = filho->esq;
    filho->esq = Raiz;

    return filho;
}

No* InsereNo(No* Raiz, int valor)
{
    if(Raiz == NULL)
    {
        No* novo = CriaNo(valor);
        return novo;
    }
    else
    {
        if(valor>Raiz->n)
            Raiz->dir = InsereNo(Raiz->dir, valor);
        else if (valor < Raiz->n)
            Raiz->esq = InsereNo(Raiz->esq, valor);
        else
            printf("Valor já existente na árvore");
        
    }

    int fb = FatorBalanceamento(Raiz);

    if(fb>1 && valor<Raiz->esq->n)
        return RotDir(Raiz);
    
    if(fb<-1 && valor>Raiz->dir->n)
        return RotEsq(Raiz);
    
    if(fb >1 && valor > Raiz->esq->n)
    {
        Raiz->esq = RotEsq(Raiz->esq);
        return RotDir(Raiz);
    }

    if(fb < -1 && valor < Raiz->dir->n)
    {
        Raiz->dir = RotDir(Raiz->dir);
        return RotEsq(Raiz);
    }

    return Raiz;

}

/*No* RotEsqDir(No* Raiz)
{
    Raiz->esq = RotEsq(Raiz->esq);
    return RotDir(Raiz);
}*/

No* EncontrarMenor(No* Raiz)
{
    if(Raiz != NULL)
    {
        if(Raiz->esq != NULL)
        {
            Raiz = EncontrarMenor(Raiz->esq);
        }
    }

    return Raiz;
}

int main()
{
    No* Raiz = NULL;
    int valores[20] = {30,10,20,40,50,25,45,43,41,70,65,15,5,8,55,58,57,75,80,78};
    int i=0;

    while (i<20)
    {
        Raiz = InsereNo(Raiz, valores[i]);
        i++;
    }
    


    return 0;
}