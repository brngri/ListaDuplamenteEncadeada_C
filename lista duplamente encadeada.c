/* author: @Bruno R. Negri */

#include <stdio.h>
#include <String.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct no
{
    int codigo;
    struct no *next, *back;
} no;

struct no *auxiliar, *corrente, *inicio, *fim, *deletar;

void enterData()
{
    printf("\nInsira o codigo: ");
    scanf("%i",&corrente->codigo);
}

void inserindo()
{
    corrente = (no*)malloc(sizeof(no));
    if(inicio == NULL)
    {
        inicio = corrente;
        inicio->next = NULL;
        inicio->back = NULL;
        auxiliar = corrente;
        enterData();
    }
    else
    {

        auxiliar->next = corrente;
        corrente->back = auxiliar;
        auxiliar = corrente;
        corrente->next = NULL;
        fim = corrente;

        enterData();
    }
}

void printar()
{
    printf("\n---Printando---");
    if(inicio == NULL)
    {
        printf("\nLista vazia!");
    }
    else
    {
        corrente = inicio;
        while(corrente)
        {
            printf("\n%i", corrente->codigo);
            corrente = corrente->next;
        }
    }
}

void printarInverso()
{
    printf("\n---Printando Inverso---");
    if(inicio == NULL)
    {
        printf("\nLista vazia!");
    }
    else
    {
        corrente = fim;
        while(corrente)
        {
            printf("\n%i", corrente->codigo);
            corrente = corrente->back;
        }
    }
}

void pesquisar()
{
    printf("\n---Pesquisando---");
    if(inicio == NULL)
    {
        printf("\nLista vazia!");
    }
    else
    {
        int flag = 0;
        printf("\nDigite o codigo que quer pesquisar: ");
        int codPesquisa;
        scanf("%i",&codPesquisa);
        if(codPesquisa == inicio->codigo)
        {
            printf("\nvalor [%i] encontrado",inicio->codigo);
            flag = 1;
        }
        else
        {
            corrente = inicio;
            while(corrente)
            {
                if(corrente->codigo == codPesquisa)
                {
                    printf("\nvalor [%i] encontrado",corrente->codigo);
                    flag = 1;
                    break;
                }
                corrente = corrente->next;
            }
        }
        if(flag == 0)
        {
            printf("\nCodigo nao encontrado");
        }
    }
}

void remover()
{
    //remover inico free inicio
    //reover meio (pesquisar com while -> free)
    //remover fim free fim
    printf("\n---Removendo---");
    int flag = 0;
    if(inicio == NULL)
    {
        printf("\nLista vazia!");
    }
    else
    {
        printf("\nDigite o codigo que quer remover: ");
        int codPesquisa;
        fflush(stdin);
        scanf("%i",&codPesquisa); // pesquisa inicio
        if(codPesquisa == inicio->codigo)
        {
            deletar = inicio;
            inicio = inicio->next;
            printf("\nvalor [%i] deletado no inicio",deletar->codigo);
            free(deletar);
            flag = 1;
        }
        else if(codPesquisa == fim->codigo)   // pesquisa final
        {
            deletar = fim;
            fim = fim->back;
            fim->next = NULL;
            printf("\nvalor [%i] deletado no fim",deletar->codigo);
            free(deletar);
            flag = 1;
        }
        else   // pesquisa meio
        {
            corrente = inicio;
            while(corrente)
            {
                if(corrente->codigo == codPesquisa)
                {
                    printf("\nvalor [%i] encontrado",corrente->codigo);
                    flag = 1;
                    deletar = corrente;
                    corrente = corrente->next;
                    corrente->back = deletar->back;
                    corrente = deletar->back;
                    corrente->next = deletar->next;
                    printf("\nvalor [%i] deletado",deletar->codigo);
                    free(deletar);

                }else{
                    corrente = corrente->next;
                }
            }
        }
    }
    if(flag == 0)
    {
        printf("\nCodigo nao encontrado");
    }
}

int main()
{
    printf("\n---Tabalea---");
    int controle = 1;
    while(controle != 0)
    {
        printf("\nEscolha\n1 - inserir\n2 - printar\n3 - printar inverso\n4 - pesquisar\n5 - remover\n0 - sair\n>>");
        scanf("%i",&controle);
        switch(controle)
        {
        case 1:
            inserindo();
            break;
        case 2:
            printar();
            break;
        case 3:
            printarInverso();
            break;
        case 4:
            pesquisar();
            break;
        case 5:
            remover();
            break;
        case 0:
            printf("\nSaindo...");
            break;
        default:
            printf("\nValor invalido");
        }
    }
    return 0;
}
