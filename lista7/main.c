#define ex3
#include "stdio.h"

#ifdef ex1
struct dados {
    char texto[10]; 
    int numINT;
    long int numLONG;
    float numFLOAT;
    double numDOUBLE;
    unsigned char texto2[10];
    unsigned int numINT2;
    unsigned long int numLONG2;
};

struct dados estrutura;

int main()
{
    receberDados();
    ImprimirDados();

    return 0;
}

void receberDados()
{
    printf("Digite os dados da estrutura\n");
    printf("Texto\n");
    gets(estrutura.texto);

    printf("INT\n");
    scanf("%d", &estrutura.numINT);

    printf("Long\n");
    scanf("%ld", &estrutura.numLONG);

    printf("Float\n");
    scanf("%f", &estrutura.numFLOAT);

    printf("Double\n");
    scanf("%lf", &estrutura.numDOUBLE);

    printf("Texto unsigned\n");
    limparbuffer();
    gets(estrutura.texto2);

    printf("Int unsigned\n");
    scanf("%u", &estrutura.numINT2);

    printf("long unsigned\n");
    scanf("%lu", &estrutura.numLONG2);
}

void ImprimirDados()
{
    printf("        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-10s%-10d%-20ld%-20f%lf\n", estrutura.texto, estrutura.numINT, estrutura.numLONG, estrutura.numFLOAT, estrutura.numDOUBLE);  
    printf("          %-20s%-20u%lu", estrutura.texto2, estrutura.numINT2, estrutura.numLONG2);  
}

void limparbuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
#endif

#ifdef ex2
struct dados {
	char nome[30];
	char end[30];
	char cidade[10];
	char estado[10];
	int cep;
};

struct dados estrutura[4];

int main()
{
    receberDados();
    imprimirDados();
    return 0;
}

void receberDados()
{
    for (int i = 0; i < 4; i++)
    {
        printf("Digite os dados da estrutura %d: \n", i+1);
        printf("Digite o nome: \n");
        gets(estrutura[i].nome);

        printf("Digite o endereco: \n");
        gets(estrutura[i].end);

        printf("Digite a cidade: \n");
        gets(estrutura[i].cidade);

        printf("Digite o estado: \n");
        gets(estrutura[i].estado);

        printf("Digite o cep: \n");
        scanf("%d", &estrutura[i].cep);
        limparbuffer();
    }
}

void imprimirDados()
{
    for (int i = 0; i < 4; i++)
    {
        printf("Dados da estrutura %d:\n", i+1);
        printf("Nome: %s ", estrutura[i].nome);
        printf("Endereco: %s ", estrutura[i].end);
        printf("Cidade: %s ", estrutura[i].cidade);
        printf("Estado: %s ", estrutura[i].estado);
        printf("Cep: %d\n", estrutura[i].cep);
    }
}

void limparbuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
#endif

#ifdef ex3

struct Data
{
    int dia;
    int mes;
    int ano;
};

struct Data datas[2];

// Verifica se um ano é bissexto
int verificarBissexto(int ano) {
    return (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);
}

// Retorna número de dias em um mês
int diasNoMes(int mes, int ano) {
    int diasPorMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (mes == 2 && verificarBissexto(ano)) {
        return 29;
    }
    return diasPorMes[mes - 1];
}

// Converte uma data em "dias absolutos" desde 01/01/0001
int qtddDias(struct Data *data) {
    int total = 0;

    // Soma dias dos anos completos anteriores
    for (int i = 1; i < data->ano; i++) {
        total += verificarBissexto(i) ? 366 : 365;
    }

    // Soma dias dos meses completos anteriores no ano atual
    for (int i = 1; i < data->mes; i++) {
        total += diasNoMes(i, data->ano);
    }

    // Soma os dias do mês atual
    total += data->dia;

    return total;
}

int main(){
    struct Data *ptrDatas;
    ptrDatas = &datas[0];

    int resp = 1, dataDiferenca;
    
    while(resp == 1)
    {
        dataDiferenca = 0;

        printf("\nDigite uma data");
        printf("\nDia: ");
        scanf("%d",&ptrDatas[0].dia);
        printf("\nMes: ");
        scanf("%d",&ptrDatas[0].mes);
        printf("\nAno: ");
        scanf("%d",&ptrDatas[0].ano);

        printf("\nDigite outra data");
        printf("\nDia: ");
        scanf("%d",&ptrDatas[1].dia);
        printf("\nMes: ");
        scanf("%d",&ptrDatas[1].mes);
        printf("\nAno: ");
        scanf("%d",&ptrDatas[1].ano);

        dataDiferenca = diasDesdeOrigem(&ptrDatas[0])-diasDesdeOrigem(&ptrDatas[1]);
        if(dataDiferenca < 0){
            dataDiferenca = dataDiferenca * -1;
        }

        printf("\nA diferença entre a primeira data e a segunda data e\' %d dias",dataDiferenca);

        do{
            printf("\nQuer continuar o programa?\nDigite (1) para sim e (2) para nao:\n");
            scanf("%d", &resp);

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            if(resp != 1 && resp != 2)
            {
                printf("Erro digite 1 ou 2 como resposta!\n");
            }
        }while(resp != 1 && resp != 2);
    }

    return 0;
}
#endif

#ifdef ex4
struct dados {
    char nome[30]; 
    float peso;
    float altura;
};

struct dados estrutura[4];

main()
{
    int opcao, aux = 1;

    while (aux == 1)
    {
        printf("\nDigite uma opcao: \n\n");
        printf("1- Receber dados. \n");
        printf("2- Imprimir dados. \n");
        printf("3- Calcular IMC.\n");
        printf("4- Sair \n");

        do
        {
            scanf("%d",&opcao);
            switch (opcao) {
                case 1:
                    getchar();
                    receberDados();
                    break;
                case 2:
                    getchar();
                    imprimirDados();
                    break;  
                case 3:
                    getchar();
                    calcularIMC();
                    break; 
                case 4:
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

void receberDados()
{
    printf("Digite os dados da estrutura\n");
    

    for (int i = 0; i < 4; i++)
    {
        printf("Nome\n");
        gets(estrutura[i].nome);

        do
        {
            printf("Peso\n");
            scanf("%f", &estrutura[i].peso);

            if(estrutura[i].peso < 0)
            {
                printf("Peso Invalido!\n");
            }
        } while (estrutura[i].peso < 0);

        do
        {
            printf("Altura\n");
            scanf("%f", &estrutura[i].altura);

            if(estrutura[i].altura < 0)
            {
                printf("Altura Invalida!\n");
            }
        } while (estrutura[i].altura < 0);

        limparbuffer();
    }
}

void imprimirDados()
{
    for (int i = 0; i < 4; i++)
    {
        printf("Nome: %s, Altura: %.2f, Peso: %.2f\n", estrutura[i].nome, estrutura[i].altura/100.0f, estrutura[i].peso);
    }
}

void calcularIMC()
{
    float IMC = 0;
    float altura_m = 0;

    for (int i = 0; i < 4; i++)
    {
        altura_m = (float)estrutura[i].altura / 100.0f;
        IMC = (float)estrutura[i].peso/(altura_m*altura_m);
        printf("IMC do %s e: %.2f \n", estrutura[i].nome, IMC);
    }
}

void limparbuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
#endif