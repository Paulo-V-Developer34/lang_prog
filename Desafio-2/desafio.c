#include "stdio.h";
#include "stdlib.h";

typedef struct biblioteca{
    char livro[40]; 
    char autor[40];
    float preco;
    int quantidade;
}biblioteca;

int main()
{
    biblioteca unidade;
    int opcao, aux = 1;

    while (aux == 1)
    {
        printf("\nDigite uma opcao: \n\n");
        printf("1- Entrada de todos os dados. \n");
        printf("2- Lista todos os livros  na tela. \n");
        printf("3- Pesquisar um livro pelo nome completo.\n");
        printf("4- Pesquisa o autor pela 1. letra do nome. \n");
        printf("5- Pesquisar livros por faixa de preco.\n");
        printf("6- Altera quantidade (+ entrada e - saida) pesquisado pelo nome completo.\n");
        printf("7- Altera preco do livro pesquisado pelo nome completo.\n");
        printf("8- Altera todos os dados pesquisado pelo nome completo.\n");
        printf("9- Exclui o registro logicamente pesquisado pelo nome completo.\n");
        printf("10- Sair\n\n");


        do
        {
            scanf("%d",&opcao);
            switch (opcao) {
                case 1:
                    getchar();
                    EntrarDados(&unidade);
                    break;
                case 2:
                    getchar();
                    ListarDados(&unidade);
                    break;  
                case 3:
                    getchar();
                    PesquisarLivro(&unidade);
                    break; 
                case 4:
                    getchar();
                    PesquisarAutor(&unidade);
                    break;
                case 5:
                    getchar();
                    PesquisarPreco(&unidade);
                    break; 
                case 6:
                    getchar();
                    AlteraQuantidade(&unidade);
                    break; 
                case 7:
                    getchar();
                    AlteraPreco(&unidade);
                    break; 
                case 8:
                    getchar();
                    AlterarDados(&unidade);
                    break; 
                case 9:
                    getchar();
                    ExcluirDados(&unidade);
                    break;
                case 10:
                    getchar();
                    aux = 0;
                    break;
                default:
                    printf("Opcao invalida! Digite novamente!\n");
                    opcao = 15;
            }
        } while (opcao == 15);
    }

    return 0;
}

void EntrarDados(biblioteca *pEstrutura)
{
    FILE *p;

    printf("Digite o nome do livro: \n");
    gets(pEstrutura->livro);

    printf("Digite o autor do livro: \n");
    gets(pEstrutura->autor);

    printf("Digite o preco do livro: \n");
    scanf("%f", &pEstrutura->preco);

    printf("Digite a quantidade de livro: \n");
    scanf("%d", &pEstrutura->quantidade);

    getchar();

    if ((p = fopen("desafio.txt", "a")) == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    fwrite(pEstrutura, sizeof(biblioteca), 1, p);

    fclose(p);
}

void ListarDados(biblioteca *pEstrutura)
{
    FILE *p;
    int r;

    if ((p = fopen("desafio.txt", "rb")) == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    while (1 == (r = fread(pEstrutura, sizeof(biblioteca), 1, p))) {

        if(pEstrutura->livro[0] != '*')
        {
            printf("Livro:%s \t", pEstrutura->livro);
            printf("Autor:%s \t", pEstrutura->autor);
            printf("Preco:R$ %.2f \t", pEstrutura->preco);
            printf("Qtd:%d\n", pEstrutura->quantidade);
        }
    }
    
    fclose(p);
}

void PesquisarLivro(biblioteca *pEstrutura)
{
    char nomeLivro[40];
    int aux = 0, i, r;
    FILE *p;

    printf("Digite o nome do livro:\n");
    gets(nomeLivro);

    if ((p = fopen("desafio.txt", "rb")) == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    while (1 == (r = fread(pEstrutura, sizeof(biblioteca), 1, p))) {
        for(i = 0; (nomeLivro[i] != '\0') || (pEstrutura->livro[i] != '\0'); i++)
        {
            if(nomeLivro[i] == pEstrutura->livro[i])
            {
                aux = 1;
            }
            else
            {
                aux = 0;
                break;
            }
        }

        if (aux == 1)
        {
            printf("Livro:%s \t", pEstrutura->livro);
            printf("Autor:%s \t", pEstrutura->autor);
            printf("Preco:R$ %.2f \t", pEstrutura->preco);
            printf("Qtd:%d\n", pEstrutura->quantidade);
        }
    }

    fclose(p);
}

void PesquisarAutor(biblioteca *pEstrutura)
{
    char nomeautor;
    int aux = 0, r;
    FILE *p;

    printf("Digite a primeira letra do autor:\n");
    nomeautor = getchar();

    if ((p = fopen("desafio.txt", "rb")) == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    while (1 == (r = fread(pEstrutura, sizeof(biblioteca), 1, p))) {
        if(nomeautor == pEstrutura->autor[0])
        {
            aux = 1;
        }
        else
        {
            aux = 0;
        }

        if(aux == 1)
        {
            if(pEstrutura->livro[0] != '*')
            {
                printf("Livro:%s \t", pEstrutura->livro);
                printf("Autor:%s \t", pEstrutura->autor);
                printf("Preco:R$ %.2f \t", pEstrutura->preco);
                printf("Qtd:%d\n", pEstrutura->quantidade);
            }
        }
    }

    fclose(p);
}

void PesquisarPreco(biblioteca *pEstrutura)
{
    FILE *p;
    float precoInf, precoSup;
    int r;

    printf("Digite o menor preco da faixa:\n");
    scanf("%f", &precoInf);

    printf("Digite o maior preco da faixa:\n");
    scanf("%f", &precoSup);

    if ((p = fopen("desafio.txt", "rb")) == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    while (1 == (r = fread(pEstrutura, sizeof(biblioteca), 1, p))) {
        if(pEstrutura->preco >= precoInf && pEstrutura->preco <= precoSup)
        {
            printf("Livro:%s \t", pEstrutura->livro);
            printf("Autor:%s \t", pEstrutura->autor);
            printf("Preco:R$ %.2f \t", pEstrutura->preco);
            printf("Qtd:%d\n", pEstrutura->quantidade);
        }
    }

    fclose(p);
}

void AlteraQuantidade(biblioteca *pEstrutura)
{
    char nomeLivro[40];
    int aux = 0, i, r, qntd;
    FILE *p;

    printf("Digite o nome do livro:\n");
    gets(nomeLivro);

    if ((p = fopen("desafio.txt", "r+b")) == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    while (1 == (r = fread(pEstrutura, sizeof(biblioteca), 1, p))) {
        for(i = 0; (nomeLivro[i] != '\0') || (pEstrutura->livro[i] != '\0'); i++)
        {
            if(nomeLivro[i] == pEstrutura->livro[i])
            {
                aux = 1;
            }
            else
            {
                aux = 0;
                break;
            }
        }

        if (aux == 1)
        {
            fseek(p, - (long)sizeof(biblioteca), 1);

            printf("Digite a quantidade:");
            scanf("%d", &qntd);

            pEstrutura->quantidade = pEstrutura->quantidade + qntd;

            fwrite(pEstrutura, sizeof(biblioteca), 1, p);

            printf("Livro:%s \t", pEstrutura->livro);
            printf("Autor:%s \t", pEstrutura->autor);
            printf("Preco:R$ %.2f \t", pEstrutura->preco);
            printf("Qtd:%d\n", pEstrutura->quantidade);

            break;
        }
    }

    fclose(p);
}

void AlteraPreco(biblioteca *pEstrutura)
{
    char nomeLivro[40];
    int aux = 0, i, r;
    FILE *p;

    printf("Digite o nome do livro:\n");
    gets(nomeLivro);

    if ((p = fopen("desafio.txt", "r+b")) == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    while (1 == (r = fread(pEstrutura, sizeof(biblioteca), 1, p))) {
        for(i = 0; (nomeLivro[i] != '\0') || (pEstrutura->livro[i] != '\0'); i++)
        {
            if(nomeLivro[i] == pEstrutura->livro[i])
            {
                aux = 1;
            }
            else
            {
                aux = 0;
                break;
            }
        }

        if (aux == 1)
        {
            fseek(p, - (long)sizeof(biblioteca), 1);

            printf("Digite o preco:");
            scanf("%f", &pEstrutura->preco);
            
            fwrite(pEstrutura, sizeof(biblioteca), 1, p);

            printf("Livro:%s \t", pEstrutura->livro);
            printf("Autor:%s \t", pEstrutura->autor);
            printf("Preco:R$ %.2f \t", pEstrutura->preco);
            printf("Qtd:%d\n", pEstrutura->quantidade);

            break;
        }
    }

    fclose(p);
}

void AlterarDados(biblioteca *pEstrutura)
{
    char nomeLivro[40];
    int aux = 0, i, r;
    FILE *p;

    printf("Digite o nome do livro:\n");
    gets(nomeLivro);

    if ((p = fopen("desafio.txt", "r+b")) == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    while (1 == (r = fread(pEstrutura, sizeof(biblioteca), 1, p))) {
        for(i = 0; (nomeLivro[i] != '\0') || (pEstrutura->livro[i] != '\0'); i++)
        {
            if(nomeLivro[i] == pEstrutura->livro[i])
            {
                aux = 1;
            }
            else
            {
                aux = 0;
                break;
            }
        }

        if (aux == 1)
        {
            fseek(p, - (long)sizeof(biblioteca), 1);

            printf("Digite o nome do livro: \n");
            gets(pEstrutura->livro);

            printf("Digite o autor do livro: \n");
            gets(pEstrutura->autor);

            printf("Digite o preco do livro: \n");
            scanf("%f", &pEstrutura->preco);

            printf("Digite a quantidade de livro: \n");
            scanf("%d", &pEstrutura->quantidade);

            getchar();
            
            fwrite(pEstrutura, sizeof(biblioteca), 1, p);

            printf("Livro:%s \t", pEstrutura->livro);
            printf("Autor:%s \t", pEstrutura->autor);
            printf("Preco:R$ %.2f \t", pEstrutura->preco);
            printf("Qtd:%d\n", pEstrutura->quantidade);

            break;
        }
    }

    fclose(p);
}

void ExcluirDados(biblioteca *pEstrutura)
{
    char nomeLivro[40];
    int aux = 0, i, r;
    FILE *p;

    printf("Digite o nome do livro:\n");
    gets(nomeLivro);

    if ((p = fopen("desafio.txt", "r+b")) == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }

    while (1 == (r = fread(pEstrutura, sizeof(biblioteca), 1, p))) {
        for(i = 0; (nomeLivro[i] != '\0') || (pEstrutura->livro[i] != '\0'); i++)
        {
            if(nomeLivro[i] == pEstrutura->livro[i])
            {
                aux = 1;
            }
            else
            {
                aux = 0;
                break;
            }
        }

        if (aux == 1)
        {
            fseek(p, -(long)sizeof(biblioteca), 1); 
            
            pEstrutura->livro[0] = '*'; 
            
            fwrite(pEstrutura, sizeof(biblioteca), 1, p);
            
            printf("Registro excluido logicamente com sucesso.\n"); 
            break;
        }
    }

    fclose(p);
}