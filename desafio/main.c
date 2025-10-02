#include <stdio.h>
#include <stdlib.h> // A função exit() está nesta biblioteca

#define QTDD_ITENS 3
#define TAM_STRING 20
#define NOME_ARQUIVO "biblioteca.dat"

char livros1[TAM_STRING];
char livros2[TAM_STRING];
char livros3[TAM_STRING];
char autores1[TAM_STRING];
char autores2[TAM_STRING];
char autores3[TAM_STRING];


int compararStrings(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 1; // Diferentes
        }
        i++;
    }
    return 0; // Iguais
}

void copiarString(char destino[], const char origem[]) {
    int i = 0;
    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0'; // Adiciona o caractere nulo para finalizar a string
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerString(char* buffer, int tamanho) {
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && i < tamanho - 1) {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}


void salvarDados() {
    FILE* arquivo = fopen(NOME_ARQUIVO, "wb");
    if (arquivo == NULL) {
        printf("\nNao foi possivel abrir o arquivo para escrita.");
        return;
    }

    fwrite(livros1, sizeof(char), TAM_STRING, arquivo);
    fwrite(autores1, sizeof(char), TAM_STRING, arquivo);
    fwrite(livros2, sizeof(char), TAM_STRING, arquivo);
    fwrite(autores2, sizeof(char), TAM_STRING, arquivo);
    fwrite(livros3, sizeof(char), TAM_STRING, arquivo);
    fwrite(autores3, sizeof(char), TAM_STRING, arquivo);

    fclose(arquivo);
}

void carregarDados() {
    FILE* arquivo = fopen(NOME_ARQUIVO, "rb");
    if (arquivo == NULL) {
        return;
    }

    fread(livros1, sizeof(char), TAM_STRING, arquivo);
    fread(autores1, sizeof(char), TAM_STRING, arquivo);
    fread(livros2, sizeof(char), TAM_STRING, arquivo);
    fread(autores2, sizeof(char), TAM_STRING, arquivo);
    fread(livros3, sizeof(char), TAM_STRING, arquivo);
    fread(autores3, sizeof(char), TAM_STRING, arquivo);

    fclose(arquivo);
}


void entradaDeDados() {
    char tempLivro[TAM_STRING];

    for (int i = 0; i < QTDD_ITENS; i++) {
        printf("\nDigite o nome do Livro %d: ", i + 1);
        lerString(tempLivro, TAM_STRING);

        // Validação para não permitir livros duplicados
        int duplicado = 0;
        if(compararStrings(livros1, tempLivro) == 0 || compararStrings(livros2, tempLivro) == 0 || compararStrings(livros3, tempLivro) == 0){
                printf("\nEste livro ja foi cadastrado. Tente novamente.");
                duplicado = 1;
                i--; // Força a repetição da entrada para a mesma posição
                break;
        }
        if(!duplicado){
            switch (i)
            {
            case 0:
                copiarString(livros1, tempLivro);
                printf("Digite o nome do Autor %d: ", i + 1);
                lerString(autores1, TAM_STRING);
                break;
            case 1:
                copiarString(livros2, tempLivro);
                printf("Digite o nome do Autor %d: ", i + 1);
                lerString(autores2, TAM_STRING);
                break;
            case 2:
                copiarString(livros3, tempLivro);
                printf("Digite o nome do Autor %d: ", i + 1);
                lerString(autores3, TAM_STRING);
                break;
            }
            
        }
    }
    salvarDados();
    printf("\nDados salvos com sucesso!");
}

void listarDados() {
    carregarDados();
    int encontrou = 0;
    
    if (livros1[0] != '\0') {
        printf("\nLivro: %s | Autor: %s", livros1, autores1);
        encontrou = 1;
    }
    if (livros2[0] != '\0') {
        printf("\nLivro: %s | Autor: %s", livros2, autores2);
        encontrou = 1;
    }
    if (livros3[0] != '\0') {
        printf("\nLivro: %s | Autor: %s", livros3, autores3);
        encontrou = 1;
    }
    
    if (!encontrou) {
        printf("\nNenhum dado cadastrado.");
    }
}

void pesquisarLivro() {
    carregarDados();
    char livroPesquisa[TAM_STRING];
    printf("\nDigite o nome completo do livro a ser pesquisado: ");
    lerString(livroPesquisa, TAM_STRING);

    int encontrou = 0;
    
    if (compararStrings(livros1, livroPesquisa) == 0) {
        printf("\nLivro encontrado!");
        printf("\nLivro: %s | Autor: %s", livros1, autores1);
        encontrou = 1;
    }
    if (compararStrings(livros2, livroPesquisa) == 0) {
        printf("\nLivro encontrado!");
        printf("\nLivro: %s | Autor: %s", livros2, autores2);
        encontrou = 1;
    }
    if (compararStrings(livros3, livroPesquisa) == 0) {
        printf("\nLivro encontrado!");
        printf("\nLivro: %s | Autor: %s", livros3, autores3);
        encontrou = 1;
    }

    if (!encontrou) {
        printf("\nLivro nao encontrado.");
    }
}

void pesquisarAutorLetra() {
    carregarDados();
    char letra;
    printf("\nDigite a primeira letra do nome do autor: ");
    scanf(" %c", &letra);
    limparBuffer();

    int encontrou = 0;
    printf("\nResultados encontrados:");
    
    if (autores1[0] == letra) {
        printf("\nLivro: %s | Autor: %s", livros1, autores1);
        encontrou = 1;
    }
    if (autores2[0] == letra) {
        printf("\nLivro: %s | Autor: %s", livros2, autores2);
        encontrou = 1;
    }
    if (autores3[0] == letra) {
        printf("\nLivro: %s | Autor: %s", livros3, autores3);
        encontrou = 1;
    }
    

    if (!encontrou) {
        printf("\nNenhum autor encontrado com a letra '%c'.", letra);
    }
}

void alterarDados() {
    carregarDados();
    char livroPesquisa[TAM_STRING];
    printf("\nDigite o nome completo do livro que deseja alterar: ");
    lerString(livroPesquisa, TAM_STRING);

    int indice = -1;
    if (compararStrings(livros1, livroPesquisa) == 0) {
        indice = 0;
    }
    if (compararStrings(livros2, livroPesquisa) == 0) {
        indice = 1;
    }
    if (compararStrings(livros3, livroPesquisa) == 0) {
        indice = 2;
    }

    if (indice != -1) {
        printf("\nLivro encontrado. Insira os novos dados.");
        switch (indice)
        {
        case 0:
            printf("Digite o novo nome para o livro: ");
            lerString(livros1, TAM_STRING);
            printf("Digite o novo nome para o autor: ");
            lerString(autores1, TAM_STRING);
            break;

        case 1:
            printf("Digite o novo nome para o livro: ");
            lerString(livros2, TAM_STRING);
            printf("Digite o novo nome para o autor: ");
            lerString(autores2, TAM_STRING);
            break;
        
        case 2:
            printf("Digite o novo nome para o livro: ");
            lerString(livros3, TAM_STRING);
            printf("Digite o novo nome para o autor: ");
            lerString(autores3, TAM_STRING);
            break;
        }

        salvarDados();
        printf("\nDados alterados com sucesso!");
    } else {
        printf("\nLivro nao encontrado.");
    }
}

void excluirDados() {
    carregarDados();
    char livroPesquisa[TAM_STRING];
    printf("\nDigite o nome completo do livro que deseja excluir: ");
    lerString(livroPesquisa, TAM_STRING);

    int indice = -1;
    if (compararStrings(livros1, livroPesquisa) == 0) {
        indice = 0;
    }
    if (compararStrings(livros2, livroPesquisa) == 0) {
        indice = 1;
    }
    if (compararStrings(livros3, livroPesquisa) == 0) {
        indice = 2;
    }
    

    if (indice != -1) {
        switch (indice)
        {
        case 0:
            livros1[0] = '\0';
            autores1[0] = '\0';
            break;

        case 1:
            livros2[0] = '\0';
            autores2[0] = '\0';
            break;

        case 2:
            livros3[0] = '\0';
            autores3[0] = '\0';
            break;
        
        default:
            break;
        }

        salvarDados();
        printf("\nDados excluidos com sucesso!");
    } else {
        printf("\nLivro nao encontrado.");
    }
}

void saida() {
    printf("\nSaindo do programa. Ate mais!");
    exit(0);
}

int main() {
    int opcao;

    do {
        printf("\n--- MENU BIBLIOTECA ---\n");
        printf("\n1 - Entrada de todos os dados");
        printf("\n2 - Listar todos os dados");
        printf("\n3 - Pesquisar livro por nome completo");
        printf("\n4 - Pesquisar autor pela primeira letra");
        printf("\n5 - Alterar dados de um livro");
        printf("\n6 - Excluir dados de um livro");
        printf("\n7 - Sair");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        limparBuffer(); // Limpa o '\n' deixado pelo scanf

        switch (opcao) {
            case 1:
                entradaDeDados();
                break;
            case 2:
                listarDados();
                break;
            case 3:
                pesquisarLivro();
                break;
            case 4:
                pesquisarAutorLetra();
                break;
            case 5:
                alterarDados();
                break;
            case 6:
                excluirDados();
                break;
            case 7:
                saida();
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.");
                break;
        }
    } while (1);

    return 0;
}