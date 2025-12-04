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
struct dados {
	int dia;
	int mes;
	int ano;
};

struct dados estrutura[2];

int main()
{
    int dias;
    for (int i = 0; i < 2; i++)
    {
        printf("Digite a data da estrutura %d:\n", i+1);
        do
        {
            printf("Dia:\n");
            scanf("%d", &estrutura[i].dia);

            if(estrutura[i].dia > 31 || estrutura[i].dia < 1)
            {
                printf("Dia invalido!\n");
            }
        } while (estrutura[i].dia > 31 || estrutura[i].dia < 1);

        do
        {
            printf("Mes:\n");
            scanf("%d", &estrutura[i].mes);

            if(estrutura[i].mes > 12 || estrutura[i].mes < 1)
            {
                printf("Mes invalido!\n");
            }
        } while (estrutura[i].mes > 12 || estrutura[i].mes < 1);

        do
        {
            printf("Ano:\n");
            scanf("%d", &estrutura[i].ano);

            if(estrutura[i].ano < 1)
            {
                printf("Ano invalido!\n");
            }
        } while (estrutura[i].ano < 1);
    }
    
    dias = calculoDias();
    printf("%d", dias);
    return 0;
}

int calculoDias()
{
    int aux = 0, contAno = 0, aux2 = 0;

    if((estrutura[0].ano%4 == 0) && (estrutura[0].mes > 2))
    {
        aux = 1;
        contAno = estrutura[1].ano - estrutura[0].ano;
    }
    
    //verifica quantos anos é bisexto
    aux2 = estrutura[0].ano + 1;
    for (int i = 0; i < contAno; i++)
    {
        if(aux2 %4 == 0)
        {
            aux = aux + 1;
        }
        aux2 = aux2 + 1;
    }

    //quantas vezes vai passar pelos meses
    contAno = contAno + 1;
    int meses = estrutura[0].mes;
    int dias = 0;
    int k = meses + 1;
    int n = 0;

    for (int j = 0; j < contAno; j++)
    {
        if (contAno == j)
        {
            n = estrutura[1].mes - 1;
        }
        else if (estrutura[1].ano == estrutura[0].ano)
        {
            n = estrutura[1].mes -1;
        }
        else
        {
            n = 12;
        }
        
        for(k; k < n; k++)
        {
            meses = meses + 1;
            if(meses == 2 && aux >= 1)
            {
                dias = dias + 29;
                aux = aux - 1;
            }
            else if(meses == 2)
            {
                dias = dias + 28;
            }
            else if(meses == 4 || meses == 6 || meses == 9 || meses == 11)
            {
                dias = dias + 30;
            }
            else
            {
                dias = dias + 31;
            }
        }

        k = 0;
    }

    int totalDias = 0;

    if(estrutura[0].mes == 4 || estrutura[0].mes == 6 || estrutura[0].mes == 9 || estrutura[0].mes == 11)
    {
        totalDias = (30 - estrutura[0].dia) + estrutura[1].dia + dias;
    }
    else if(estrutura[0].mes == 2 && estrutura[0].ano %4 == 0)
    {
        totalDias = (29 - estrutura[0].dia) + estrutura[1].dia + dias;
    }
    else if(estrutura[0].mes == 2)
    {
        totalDias = (28 - estrutura[0].dia) + estrutura[1].dia + dias;
    }
    else
    {
        totalDias = (31 - estrutura[0].dia) + estrutura[1].dia + dias;
    }

    return totalDias;
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