/*
Rafaella Nunes Garcia
ADS -1° PERÍODO
13745376676
04/06/2025
*/


#include <stdio.h>
 #include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>

#define tam 1000
//=======================================================
//=======================================================
//=======================================================
//=======================================================
void MostrarVetor(int dia[], float valor_atual[], float valor_total[], char status[], char descri[][50], int tamanho)
{
    int cont;
    cont=0;
    printf("\n dia    descricao     status  valor da transacao   saldo atual \n");

    while(cont < tamanho)
    {
        if(strcmp(descri[cont],"dinheiro")==0)
        {
            printf(" %d   -    %8s    %3c       %.2f       %15.2f \n", dia[cont], descri[cont],status[cont] , valor_atual[cont], valor_total[cont]);
        }
        else
            printf(" %d   - %6s    %8c       %.2f       %15.2f \n", dia[cont], descri[cont],status[cont] , valor_atual[cont], valor_total[cont]);
        cont++;
    }
}
//=======================================================
void Valor(float v_atual[], int posi)
{

    printf("\n \n Informe o valor...: ");
    do
    {
        fflush(stdin);
        scanf("%f", &v_atual[posi]);
        if(v_atual[posi]<0)
            printf("\n Invalido mostre um valor positivo");
    }while(v_atual[posi]<0);
}
//=======================================================
void Tipo(char v[][50], int posi)
{


    printf("\n Informe o tipo de deposito (dinheiro, pix)...: ");
    do
    {
        fflush(stdin);
        gets(v[posi]);
        if(strcmp(v[posi], "dinheiro")!=0 && strcmp(v[posi], "pix")!=0)
            printf("\n Invalido... Verifique se digitou corretamente (dinheiro, pix)...: ");
    }while(strcmp(v[posi],"dinheiro")!=0 && strcmp(v[posi], "pix")!=0);


}
//=======================================================
void Dia(int v[],int posi)
{
    int cont_aux;
    if(posi>0)
        cont_aux=posi-1;
    else
        cont_aux=0;


    printf("\n \n Informe o dia da data de hoje...: ");
    do
    {
        fflush(stdin);
        scanf("%d", &v[posi]);
        if(v[posi]<1 || v[posi]>31 || v[posi]<v[cont_aux])
            printf("\n \n Invalido... Insira um numero maior que o dia valido...: ");
    }while(v[posi]<1 || v[posi]>31 || v[posi]<v[cont_aux]);

}
//=======================================================
void Inicializar_s(char v[][50], int tamanho)
{
    int cont;
    cont =0;

    while(cont<tamanho )
    {
        strcpy(v[cont], " ");
        cont++;
    }
}

//=======================================================
void Inicializar_c(char v[], int tamanho)
{
    int cont;
    cont =0;

    while(cont<tamanho )
    {
        v[cont]=' ';
        cont++;
    }
}

//=======================================================
void Inicializar_d(int v[], int tamanho)
{
    int cont;
    cont=0;

    while(cont<tamanho)
    {
        v[cont]=0;
        cont++;
    }
}

//=======================================================

void Inicializar_f(float v[], int tamanho)
{
    int cont;
    cont=0;

    while(cont<tamanho)
    {
        v[cont]=0.0;
        cont++;
    }
}

//=======================================================
int main()
{
    int op, fim, posi;
    op=posi=0;
    fim=3;

    float saldo_atual[tam], valor_total[tam];
    int dia[tam];
    char status[tam], descricao[tam][50];

    Inicializar_f(saldo_atual, tam);
    Inicializar_f(valor_total, tam);
    Inicializar_d(dia, tam);
    Inicializar_c(status, tam);
    Inicializar_s(descricao, tam);

    do
    {
        system("cls");
        printf("\n       TRANSACOES BANCARIAS");
        printf("\n \n 1) Deposito (entrada)");
        printf("\n 2) Retiradas (saida)");
        printf("\n 3) Relatorio saldo atual");
        printf("\n 4) Relatorio Extrato do periodo do mes");
        printf("\n 5) Finalizar");
        printf("\n Informe uma das opcoes 1, 2 3, 4 ou 5...: ");
        do
        {
            fflush(stdin);
            scanf("%d", &op);
            if(op<=0 || op>5)
                printf("\n \n Invalido... Informe uma das opcoes 1, 2 3, 4 ou 5...: ");
        }while(op<=0 || op>5);

        system("cls");

        if(op==5)
        {

            printf("\n 5) Finalizar");
            printf(" \n \n Aguarde a finalizacao do programa... \n \n");
            while(fim>=0)
            {
                Sleep(200);
                printf("%6d", fim);
                fim--;
            }
        }
        else
        {
            if(op==1)
            {
                printf("\n \n 1) Deposito (entrada)");

                Dia(dia, posi);
                Tipo(descricao, posi);
                Valor(saldo_atual, posi);
                valor_total[posi] = valor_total[posi-1] + saldo_atual[posi];
                status[posi]='C';
                posi++;


            }
            else
            {
                if(op==2)
                {
                    printf("\n 2) Retiradas (saida)");
                    Dia(dia, posi);
                    Tipo(descricao, posi);
                    Valor(saldo_atual, posi);


                    while(valor_total[posi-1] < saldo_atual[posi])
                    {
                        printf("\n Voce nao tem essa quantia... ");
                        Dia(dia, posi);
                        Tipo(descricao, posi);
                        Valor(saldo_atual, posi);
                    }

                        valor_total[posi] =valor_total[posi-1] - saldo_atual[posi];
                        status[posi]='D';
                        posi++;

                }
                else
                {
                    if(op==3)
                    {
                        printf("\n 3) Relatorio saldo atual");

                        printf("\n Saldo atual = R$%.2f", valor_total[posi-1]);
                    }
                    else
                    {
                        printf("\n 4) Relatorio Extrato do periodo do mes");

                        printf("\n Extrato completo \n ====================");
                        MostrarVetor(dia,saldo_atual,valor_total,status, descricao, posi);

                    }
                }
            }

            printf("\n \n Aperte qualquer tecla para voltar as Transacoes");
            getch();
        }




    }while(op!=5);

    printf("\n \n Beeijoo byeee");
}
