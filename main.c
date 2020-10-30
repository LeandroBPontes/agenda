#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 3
#define BLOCK 5

typedef struct _contato
{
    char nome[30];
    char tel[8];
} contato;

contato **agenda;
int num_contatos = 0;
int num_blocos = 0;
int aux_num_contato;

void inic_agenda(void);
void insere(void);
void deleta(void);
void lista(void);
int item_menu(void);

int main(void)
{
    setlocale(LC_ALL, "");
    int item;
    inic_agenda();
    {
        for(;;)
        {


            item = item_menu();
            system("cls");
            switch(item)
            {
            case 1:
                system("cls");
                insere();
                system("cls");


                break;
            case 2:
                system("cls");
                deleta();

                break;
            case 3:
                system("cls");
                lista();

                break;
            case 4:
                exit(0);
            }
        }
    }
}


/* Retorna item de menu selecionado*/
int item_menu(void)
{

    char s[80];
    int c;

    printf("\n");
    printf("1. Inserir um contato\n");
    printf("2. Excluir um contato\n");
    printf("3. Listar contatos\n");
    printf("4. Sair\n");

    do
    {
        printf("\nEntre com sua escolha: ");
        gets(s);
        c = atoi(s);
    }
    while(c<0 || c>4);

    return c;
}

/*inicia agenda */
void inic_agenda(void)
{
    int i;

    agenda = malloc(BLOCK * sizeof(contato*));
    if (agenda == NULL)
    {
        printf("nao foi possivel alocar");
    }

    for (i = 0; i < BLOCK; i++)
    {
        agenda[i] = calloc(1, sizeof(contato));

    }
    if (agenda[i-1] == NULL)
    {
        printf("nao foi possivel alocar");
    }
    num_contatos = 0;
    num_blocos = 1;
}


/*insere agenda */

void insere(void)
{

    int i, contador, qtd;



    printf("\nQuantos contatos deseja inserir?");
    scanf("%d", &qtd);

    if(qtd >= num_contatos)
    {
        contador = qtd - num_contatos;

    }
    else
    {
        contador = num_contatos + qtd;

    }
    aux_num_contato = contador;

    for (i = num_contatos; i < contador; i++)
    {



        printf("\nNome do usuário: ");
        scanf("%s",agenda[i]->nome);
        printf("\nTelefone do usuário: ");
        scanf("%s",agenda[i]->tel);

        num_contatos++;

        if( agenda[i]->nome == NULL || agenda[i]->tel ==NULL)
        {
            printf("\nIMPOSSIVEL MALOCAR");
        }

        if((i >= (BLOCK * num_blocos -1)) && (num_blocos < MAX))
        {

            i = num_contatos;
            num_blocos++;
            agenda = realloc(agenda, BLOCK * num_blocos * sizeof(contato*));
            for(i = num_contatos; i < BLOCK * num_blocos; i++)
            {
                agenda[i] = calloc(1, sizeof(contato));
            }
            i = num_contatos - 1;

        }

    }
}

/* Apaga um contato */
void deleta(void)
{
    int i;
    char s[10];
    contato *auxiliar;

    printf("\n-----------------TELA DE EXCLUSÃO DE USUÁRIO------------------------\n\n");

    if (num_contatos ==0)
    {
        printf("\nSUA AGENDA SE ENCONTRA VAZIA\n");
        printf("\nINSTRUÇÕES PARA CADASTRAMENTO: \n");
        printf("\n1- ESCOLHA A ALTERNATIVA -INSERIR UM CONTATO- NA TELA DE MENU\n");
        printf("\n2- ENTRE COM O NOME E TELEFONE DO USUÁRIO\n");
        return;
    }

    printf("\nEntre com o número do contato que deseja deletar: ");
    gets(s);

    for(i = 0; i < aux_num_contato; i++)
    {
        if(strcasecmp(agenda[i]->tel, s)==0)
        {

            auxiliar = malloc(sizeof(contato));



            for (; i < aux_num_contato ; i++)
            {
                auxiliar = agenda[i];
                agenda[i] = agenda[i+1];
                agenda[i+1] = auxiliar;
            }

            num_contatos--;
            aux_num_contato--;

        }
    }

}

/* Mostra a lista de contatos na tela. */
void lista(void)
{
    int i;
    printf("\n-----------------TELA DE LISTAGEM DE CONTATOS------------------------\n\n");
    if(aux_num_contato == 0)
    {
        printf("\nSUA AGENDA SE ENCONTRA VAZIA\n");
        printf("\nINSTRUÇÕES PARA CADASTRAMENTO: \n");
        printf("\n1- ESCOLHA A ALTERNATIVA -INSERIR UM CONTATO- NA TELA DE MENU\n");
        printf("\n2- ENTRE COM O NOME E TELEFONE DO USUÁRIO\n");
        return;

    }

    for (i = 0; i < aux_num_contato; i++)
    {
        printf("\n-------------------------\n");
        printf("(%d) %s | %s\n", i+1, agenda[i]->nome, agenda[i]->tel);
        printf("-------------------------");
    }
    printf("\n\n");


}
