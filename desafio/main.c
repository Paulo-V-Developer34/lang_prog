#include <stdio.h>
#include <stdlib.h> // A função exit() está nesta biblioteca

// --- DEFINIÇÕES E VARIÁVEIS GLOBAIS ---
#define MAX_LIVROS 3
#define TAM_STRING 20
#define NOME_ARQUIVO "biblioteca.dat"

// Vetores globais, conforme solicitado
char livros[MAX_LIVROS][TAM_STRING];
char autores[MAX_LIVROS][TAM_STRING];

// --- FUNÇÕES AUXILIARES (para substituir funções proibidas) ---

/**
 * Compara duas strings caractere por caractere.
 * Retorna 0 se forem iguais, e 1 se forem diferentes.
 */
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

/**
 * Copia o conteúdo de uma string (origem) para outra (destino).
 */
void copiarString(char destino[], const char origem[]) {
    int i = 0;
    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0'; // Adiciona o caractere nulo para finalizar a string
}

/**
 * Limpa o buffer de entrada do teclado para evitar erros com scanf.
 */
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Lê uma string do teclado de forma segura, evitando estouro de buffer.
 */
void lerString(char* buffer, int tamanho) {
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && i < tamanho - 1) {
        buffer[i++] = c;
    }
    buffer[i] = '\0';
}


// --- FUNÇÕES DE MANIPULAÇÃO DE ARQUIVO ---

/**
 * Salva os vetores globais 'livros' e 'autores' no arquivo binário.
 */
void salvarDados() {
    FILE* arquivo = fopen(NOME_ARQUIVO, "wb");
    if (arquivo == NULL) {
        printf("\nERRO: Nao foi possivel abrir o arquivo para escrita.\n");
        return;
    }

    // Escreve todo o array de livros de uma vez
    fwrite(livros, sizeof(char), MAX_LIVROS * TAM_STRING, arquivo);
    // Escreve todo o array de autores de uma vez
    fwrite(autores, sizeof(char), MAX_LIVROS * TAM_STRING, arquivo);

    fclose(arquivo);
}

/**
 * Carrega os dados do arquivo binário para os vetores globais.
 */
void carregarDados() {
    FILE* arquivo = fopen(NOME_ARQUIVO, "rb");
    if (arquivo == NULL) {
        // Se o arquivo não existe, não há nada a carregar.
        // Podemos inicializar os vetores como vazios.
        for (int i = 0; i < MAX_LIVROS; i++) {
            livros[i][0] = '\0';
            autores[i][0] = '\0';
        }
        return;
    }

    fread(livros, sizeof(char), MAX_LIVROS * TAM_STRING, arquivo);
    fread(autores, sizeof(char), MAX_LIVROS * TAM_STRING, arquivo);

    fclose(arquivo);
}


// --- FUNÇÕES DO MENU ---

// 1 - Entrada de todos os dados
void entradaDeDados() {
    printf("\n--- Entrada de Dados ---\n");
    char tempLivro[TAM_STRING];

    for (int i = 0; i < MAX_LIVROS; i++) {
        printf("Digite o nome do Livro %d: ", i + 1);
        lerString(tempLivro, TAM_STRING);

        // Validação para não permitir livros duplicados
        int duplicado = 0;
        for(int j = 0; j < i; j++){
            if(compararStrings(livros[j], tempLivro) == 0){
                printf("ERRO: Este livro ja foi cadastrado. Tente novamente.\n");
                duplicado = 1;
                i--; // Força a repetição da entrada para a mesma posição
                break;
            }
        }
        if(!duplicado){
            copiarString(livros[i], tempLivro);
            printf("Digite o nome do Autor %d: ", i + 1);
            lerString(autores[i], TAM_STRING);
        }
    }
    salvarDados();
    printf("\nDados salvos com sucesso!\n");
}

// 2 - Lista todos os dados na tela
void listarDados() {
    carregarDados();
    printf("\n--- Lista de Livros e Autores ---\n");
    int encontrou = 0;
    for (int i = 0; i < MAX_LIVROS; i++) {
        // Verifica se o primeiro caractere não é nulo (string não está vazia)
        if (livros[i][0] != '\0') {
            printf("Livro: %s | Autor: %s\n", livros[i], autores[i]);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum dado cadastrado.\n");
    }
}

// 3 - Pesquisa um livro completo
void pesquisarLivro() {
    carregarDados();
    char livroPesquisa[TAM_STRING];
    printf("\n--- Pesquisar Livro ---\n");
    printf("Digite o nome completo do livro a ser pesquisado: ");
    lerString(livroPesquisa, TAM_STRING);

    int encontrou = 0;
    for (int i = 0; i < MAX_LIVROS; i++) {
        if (compararStrings(livros[i], livroPesquisa) == 0) {
            printf("\nLivro encontrado!\n");
            printf("Livro: %s | Autor: %s\n", livros[i], autores[i]);
            encontrou = 1;
            break; // Para o loop pois só pode haver um livro com o mesmo nome
        }
    }

    if (!encontrou) {
        printf("\nLivro nao encontrado.\n");
    }
}

// 4 - Pesquisa o autor pela primeira letra
void pesquisarAutorLetra() {
    carregarDados();
    char letra;
    printf("\n--- Pesquisar Autor por Letra ---\n");
    printf("Digite a primeira letra do nome do autor: ");
    scanf(" %c", &letra);
    limparBuffer();

    int encontrou = 0;
    printf("\nResultados encontrados:\n");
    for (int i = 0; i < MAX_LIVROS; i++) {
        if (autores[i][0] == letra) {
            printf("Livro: %s | Autor: %s\n", livros[i], autores[i]);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum autor encontrado com a letra '%c'.\n", letra);
    }
}

// 5 - Altera todos os dados
void alterarDados() {
    carregarDados();
    char livroPesquisa[TAM_STRING];
    printf("\n--- Alterar Dados ---\n");
    printf("Digite o nome completo do livro que deseja alterar: ");
    lerString(livroPesquisa, TAM_STRING);

    int indice = -1;
    for (int i = 0; i < MAX_LIVROS; i++) {
        if (compararStrings(livros[i], livroPesquisa) == 0) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        printf("Livro encontrado. Insira os novos dados.\n");
        printf("Digite o novo nome para o livro: ");
        lerString(livros[indice], TAM_STRING);
        printf("Digite o novo nome para o autor: ");
        lerString(autores[indice], TAM_STRING);

        salvarDados();
        printf("\nDados alterados com sucesso!\n");
    } else {
        printf("\nLivro nao encontrado.\n");
    }
}

// 6 - Exclui dados
void excluirDados() {
    carregarDados();
    char livroPesquisa[TAM_STRING];
    printf("\n--- Excluir Dados ---\n");
    printf("Digite o nome completo do livro que deseja excluir: ");
    lerString(livroPesquisa, TAM_STRING);

    int indice = -1;
    for (int i = 0; i < MAX_LIVROS; i++) {
        if (compararStrings(livros[i], livroPesquisa) == 0) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        // Para "excluir", definimos o primeiro caractere como nulo ('\0')
        livros[indice][0] = '\0';
        autores[indice][0] = '\0';

        salvarDados();
        printf("\nDados excluidos com sucesso!\n");
    } else {
        printf("\nLivro nao encontrado.\n");
    }
}

// 7 - Saída
void saida() {
    printf("\nSaindo do programa. Ate mais!\n");
    exit(0);
}


// --- FUNÇÃO PRINCIPAL ---
int main() {
    int opcao;

    do {
        printf("\n--- MENU BIBLIOTECA ---\n");
        printf("1 - Entrada de todos os dados\n");
        printf("2 - Listar todos os dados\n");
        printf("3 - Pesquisar livro por nome completo\n");
        printf("4 - Pesquisar autor pela primeira letra\n");
        printf("5 - Alterar dados de um livro\n");
        printf("6 - Excluir dados de um livro\n");
        printf("7 - Sair\n");
        printf("------------------------\n");
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
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    } while (1); // Loop infinito, a saída é controlada pela função saida()

    return 0;
}