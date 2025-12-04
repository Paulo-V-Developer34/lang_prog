#include <stdio.h>
#define ex6

#ifdef ex1
struct Dados {
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
};

void receber(struct Dados *d) {
    printf("Digite um char: ");
    scanf(" %c", &d->c);
    printf("Digite um int: ");
    scanf("%d", &d->i);
    printf("Digite um long: ");
    scanf("%ld", &d->l);
    printf("Digite um float: ");
    scanf("%f", &d->f);
    printf("Digite um double: ");
    scanf("%lf", &d->d);
    printf("Digite um unsigned char: ");
    scanf("%hhu", &d->uc);
    printf("Digite um unsigned int: ");
    scanf("%u", &d->ui);
    printf("Digite um unsigned long: ");
    scanf("%lu", &d->ul);
}

void imprimir(struct Dados *d) {
    printf("\n      char      int                 long                float     double");
    printf("\n              unsigned char       unsigned int        unsigned long");
    printf("%10c%10d%20ld%20.2f%10.2lf\n", d->c, d->i, d->l, d->f, d->d);
    printf("%20hhu%20u%20lu\n", d->uc, d->ui, d->ul);
}

int main() {
    int resp = 1;
    struct Dados d;
    while(resp == 1) {
        receber(&d);
        imprimir(&d);
        do {
            printf("\nQuer continuar o programa?\nDigite (1) para sim e (2) para nao:\n");
            scanf("%d", &resp);
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if(resp != 1 && resp != 2) printf("Erro digite 1 ou 2 como resposta!");
        } while(resp != 1 && resp != 2);
    }
    return 0;
}
#endif

#ifdef ex2
int comparar(char *s1, char *s2) {
    int i=0;
    while(s1[i] != '\0' && s2[i] != '\0') {
        if(s1[i] != s2[i]) return 0;
        i++;
    }
    return (s1[i] == '\0' && s2[i] == '\0');
}

int main() {
    int resp = 1;
    char str1[11], str2[11];
    while(resp == 1) {
        printf("\nDigite a primeira string: ");
        gets(str1);
        printf("\nDigite a segunda string: ");
        gets(str2);
        int r = comparar(str1, str2);
        if(r){
            printf("\nAs palavras sao iguais");
        }else{
            printf("\nAs palavras sao diferentes");
        }
        do {
            printf("\nQuer continuar o programa?\nDigite (1) para sim e (2) para nao:");
            scanf("%d", &resp);
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if(resp != 1 && resp != 2) printf("Erro digite 1 ou 2 como resposta!");
        } while(resp != 1 && resp != 2);
    }
    return 0;
}
#endif

#ifdef ex3
void operacao(double *resultado) {
    char entrada[20];
    double valor;
    char op;
    *resultado = 0;
    while(1) {
        printf("\nDigite valor ou '=' para resultado: ");
        gets(entrada);
        if(entrada[0] == '=' && entrada[1] == '\0') break;
        sscanf(entrada, "%lf", &valor);
        printf("\nDigite operacao (+,-,*,/): ");
        scanf(" %c", &op);
        int c; while ((c = getchar()) != '\n' && c != EOF);
        switch(op) {
            case '+': *resultado += valor; break;
            case '-': *resultado -= valor; break;
            case '*': *resultado *= valor; break;
            case '/': if(valor != 0) *resultado /= valor; break;
        }
    }
}

int main() {
    int resp = 1;
    double resultado;
    while(resp == 1) {
        operacao(&resultado);
        printf("Resultado acumulado: %.2lf\n", resultado);
        do {
            printf("\nQuer continuar o programa?\nDigite (1) para sim e (2) para nao:");
            scanf("%d", &resp);
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if(resp != 1 && resp != 2) printf("\nErro digite 1 ou 2 como resposta!");
        } while(resp != 1 && resp != 2);
    }
    return 0;
}
#endif

#ifdef ex4
int pesquisa(char *vetor, int tamanho, char *letra) {
    for(int i=0; i<tamanho; i++) {
        if(*(vetor+i) == *letra) return 1;
    }
    return 0;
}

int main() {
    int resp = 1;
    char vetor[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
    char entrada[2];
    while(resp == 1) {
        printf("Digite uma letra: ");
        scanf(entrada);
        char letra = entrada[0];
        int r = pesquisa(vetor, sizeof(vetor)/sizeof(char), &letra);
         if(r){
            printf("\nA letra %c esta na lista",);
        }else{
            printf("\nA letra %c nao esta na lista");
        }
        do {
            printf("\nQuer continuar o programa?\nDigite (1) para sim e (2) para nao:");
            scanf("%d", &resp);
            int c; while ((c = getchar()) != '\n' && c != EOF);
            if(resp != 1 && resp != 2) printf("\nErro digite 1 ou 2 como resposta!");
        } while(resp != 1 && resp != 2);
    }
    return 0;
}
#endif

#ifdef ex5
struct Registro {
    char nome[30];
    char end[50];
    char cidade[30];
    char estado[3];
    char cep[10];
};

void receber(struct Registro *r) {
    printf("Nome: "); gets(r->nome);
    printf("Endereco: "); gets(r->end);
    printf("Cidade: "); gets(r->cidade);
    printf("Estado: "); gets(r->estado);
    printf("CEP: "); gets(r->cep);
}

void imprimir(struct Registro *r, int n) {
    for (int i = 0; i < n; i++) {
        if (r[i].nome[0] == '\0') continue; 
        printf("\n======== Registro %d ========\n", i + 1);
        puts(r[i].nome);
        puts(r[i].end);
        puts(r[i].cidade);
        puts(r[i].estado);
        puts(r[i].cep);
    }
}

int main() {
    int resp = 1;
    struct Registro reg[4];
    while(resp == 1) {
        int opcao;
        printf("Menu:\n1 - Inserir registros");
        printf("\n2 - Imprimir registros");
        printf("\n3 - Sair\nOpcao: ")
        scanf("%d", &opcao);
        int c; while ((c = getchar()) != '\n' && c != EOF);
        switch(opcao) {
            case 1: for(int i=0;i<4;i++) receber(&reg[i]); break;
            case 2: imprimir(reg,4); break;
            case 3: resp = 2; break;
            default: printf("Opcao invalida!");
        }
        if(opcao!=3){
            do {
                printf("\nQuer continuar o programa?\nDigite (1) para sim e (2) para nao:");
                scanf("%d", &resp);
                int c; while ((c = getchar()) != '\n' && c != EOF);
                if(resp != 1 && resp != 2) printf("Erro digite 1 ou 2 como resposta!");
            } while(resp != 1 && resp != 2);
        }
    }
    return 0;
}
#endif

#include <stdio.h>

#ifdef ex6
struct Registro {
    char nome[30];
    char end[50];
    char cidade[30];
    char estado[3];
    char cep[10];
};

int comparacao(char *ptrP1, char *ptrP2){
    int count;
    for(count = 0; count < 29; count++){
        if(*(ptrP1 + count) != *(ptrP2 + count)){
            return 0;
        }
        if(*(ptrP1 + count) == '\0' && *(ptrP2 + count) == '\0'){
            return 1;
        }
    }
    return 1; 
}

void deixarVazio(struct Registro *r) {
    r->nome[0] = '\0';
    r->end[0] = '\0';
    r->cidade[0] = '\0';
    r->estado[0] = '\0';
    r->cep[0] = '\0';
}

/* CRUD */
void receber(struct Registro *r) {
    printf("Nome: "); gets(r->nome);
    printf("Endereco: "); gets(r->end);
    printf("Cidade: "); gets(r->cidade);
    printf("Estado: "); gets(r->estado);
    printf("CEP: "); gets(r->cep);
}

void imprimir(struct Registro *r, int n) {
    for (int i = 0; i < n; i++) {
        if (r[i].nome[0] == '\0') continue;
        printf("\n======== Registro %d ========\n", i + 1);
        puts(r[i].nome);
        puts(r[i].end);
        puts(r[i].cidade);
        puts(r[i].estado);
        puts(r[i].cep);
    }
}

int procurar(struct Registro *r, int n, char *nome) {
    for (int i = 0; i < n; i++) {
        if (r[i].nome[0] == '\0') continue;
        if (comparacao(r[i].nome, nome) == 1) return i;
    }
    return -1;
}

void alterar(struct Registro *r, int indice) {
    if (indice < 0) return;
    printf("\nAlterando registro:");
    printf("Novo nome: "); gets(r[indice].nome);
    printf("Novo endereco: "); gets(r[indice].end);
    printf("Nova cidade: "); gets(r[indice].cidade);
    printf("Novo estado: "); gets(r[indice].estado);
    printf("Novo CEP: "); gets(r[indice].cep);
    printf("Registro alterado.");
}

void excluir(struct Registro *r, int *n, int indice) {
    if (indice < 0 || indice >= *n) return;
    for (int i = indice; i < *n - 1; i++) {
        r[i] = r[i + 1];
    }
    deixarVazio(&r[*n - 1]);
    printf("\nRegistro excluido.");
}

void inserir_quatro(struct Registro *r, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n======== Inserindo registro %d ========\n", i + 1);
        receber(&r[i]);
    }
}

int main() {
    int resp = 1;
    struct Registro reg[4];
    int tamanho = 4;

    for (int i = 0; i < tamanho; i++) deixarVazio(&reg[i]);

    while (resp == 1) {
        int opcao;
        printf("\n======== Menu ========");
        printf("\n1 - Inserir 4 registros");
        printf("\n2 - Imprimir registros");
        printf("\n3 - Procurar por nome");
        printf("\n4 - Alterar por nome");
        printf("\n5 - Excluir por nome");
        printf("\n6 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        int c; while ((c = getchar()) != '\n' && c != EOF);

        switch (opcao) {
            case 1:
                inserir_quatro(reg, tamanho);
                break;
            case 2:
                imprimir(reg, tamanho);
                break;
            case 3: {
                char nome[30];
                puts("\nDigite o nome para procurar: ");
                gets(nome);
                int indice = procurar(reg, tamanho, nome);
                if (indice >= 0) {
                    printf("\nEncontrado no registro %d.\n", indice + 1);
                    printf("\nRegistro:");
                    puts(reg[indice].nome);
                    puts(reg[indice].end);
                    puts(reg[indice].cidade);
                    puts(reg[indice].estado);
                    puts(reg[indice].cep);
                } else {
                    puts("\nNome nao encontrado.");
                }
                break;
            }
            case 4: {
                char nome[30];
                printf("\nDigite o nome para alterar: ");
                gets(nome);
                int indice = procurar(reg, tamanho, nome);
                if (indice >= 0) {
                    alterar(reg, indice);
                } else {
                    printf("\nNome nao encontrado para alterar.");
                }
                break;
            }
            case 5: {
                char nome[30];
                printf("\nDigite o nome para excluir: ");
                gets(nome);
                int indice = procurar(reg, tamanho, nome);
                if (indice >= 0) {
                    excluir(reg, &tamanho, indice);
                } else {
                    printf("\nNome nao encontrado para excluir.");
                }
                break;
            }
            case 6:
                resp = 2;
                break;
            default:
                printf("\nOpcao invalida!");
        }
    }
    return 0;
}
#endif
