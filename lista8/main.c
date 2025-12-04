/****************************************************************************

			EXERCICIOS

*****************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.

1 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:
OBS.: As variaveis sao locais na funcao main().
    

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char

2 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.
OBS.: As variaveis sao locais na funcao main().

3 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faca uma
    funcao para compara-las usando ponteiros e retorne como resultado se 
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main(). 
    Imprima o resultado na funcao main(). Declare os vetores como variavel global

4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva 
    uma funcao que pesquise esta letra existe no vetor abaixo usando ponteiros. 
    Imprima o resultado da pesquisa no video na funcao main(). Passe como 
    informacao para a funcao a letra digitada. (utilize o comando return). 
    O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y

5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa funcao usando ponteiros. Utilize um comando de loop. 
    O vetor de estruturas deve ser declarado como variavel global.
       estrutura: nome, end, cidade, estado, cep

6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado 
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas declarado como variavel 
    global.
    	estrutura: dia, mes e ano
*/

#include <stdio.h>
#define ex6

#ifdef ex1
void gabarito(){
    printf("        10");
    printf("        20");
    printf("        30");
    printf("        40");
    printf("        50");
    printf("        60");
    printf("\n12345678901234567890123456789012345678901234567890123456789012345");
}

int main(){

    short int   a, *pa;
    int         b, *pb;
    long int    c, *pc;
    float       d, *pd;
    double      e, *pe;
    char        f, *pf;

    pa = &a;
    pb = &b;
    pc = &c;
    pd = &d;
    pe = &e;
    pf = &f;

    int resp = 1;
    
    while(resp == 1)
    {
        printf("\ndigite um numero pequeno");
        scanf("%hd",pa);
        printf("\ndigite um numero");
        scanf("%d",pb);
        printf("\ndigite um numero grande");
        scanf("%ld",pc);
        printf("\ndigite um numero de ponto flutuante");
        scanf("%f",pd);
        printf("\ndigite um numero de ponto flutuante maior");
        scanf("%lf",pe);
        getchar();
        printf("\ndigite uma letra");
        scanf("%c",pf);
    
        gabarito();
    
        printf("\n%9hd ",*pa);
        printf("\t   %9ld ",*pc);
        printf("\t      %9d ",*pb);
        printf("\n     %14f ",*pd);
        printf("\t  %14lf ",*pe);
        printf("   %14c ",*pf);

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

#ifdef ex2

int fim, numero, *pNumero, qtddNumeros;
float acumulador;
pNumero = &numero;

int main(){

    int resp = 1;
    
    while(resp == 1)
    {
        fim = 0;
        acumulador = 0;
        qtddNumeros = 0;

        while (fim == 0)
        {
            printf("\nDigite um numero: ");
            scanf("%d",pNumero);
    
            if(*pNumero < 0){
                fim = 1;
            }else{
                qtddNumeros++;
                acumulador += *pNumero;
            }
        }

        printf("A media dos numeros digitados e aproximadamente: %f",acumulador / qtddNumeros);

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

#ifdef ex3
char p1[11], p2[11];

int comparacao(){
    int count, iguais = 1;
    char *ptrP1 = p1, *ptrP2 = p2;
    for(count = 0; count < 10; count++){
        if(*(ptrP1 + count) != *(ptrP2 + count)){
            iguais = 0;
        }
    }
    return iguais;
}

int main(){


    int resp = 1;
    int igual = 0;

    while(resp == 1)
    {
        printf("\ndigite uma palavra de 10 letras");
        fflush(stdin);
        gets(p1);

        printf("\ndigite outra palavra de 10 letras");
        fflush(stdin);
        gets(p2);

        igual = comparacao();

        if(igual){
            printf("As palavras sao iguais");
        } else {
            printf("As palavras sao diferentes");
        }
        
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
char letras[14] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

int pesquisa(char *letra){
    int count, igual;
    for(count = 0; count < 10; count++){
        if(letras[count] == *letra){
            igual = 1;
        }
    }
    return igual;
}

int main(){

    int resp = 1;
    int igual = 0;
    char letra, *ptrLetra;
    ptrLetra = &letra;

    while(resp == 1)
    {
        igual = 0;

        printf("\ndigite uma letra ");
        scanf("%c",ptrLetra);

        igual = pesquisa(ptrLetra);

        if(igual){
            printf("A letra %c está na lista", *ptrLetra);
        } else {
            printf("A letra %c não está na lista", *ptrLetra);
        }
        
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

#ifdef ex5
// definição da estrutura
struct Cadastro {
    char nome[50];
    char end[50];
    char cidade[30];
    char estado[20];
    char cep[15];
};

// vetor global de 4 elementos
struct Cadastro registros[4];

// função para receber dados via teclado usando ponteiros
void receberDados(struct Cadastro *p) {
    for(int i = 0; i < 4; i++) {
        printf("\n--- Registro %d ---\n", i+1);

        printf("Digite o nome: ");
        gets(p[i].nome);

        printf("Digite o endereço: ");
        gets(p[i].end);

        printf("Digite a cidade: ");
        gets(p[i].cidade);

        printf("Digite o estado: ");
        gets(p[i].estado);

        printf("Digite o CEP: ");
        gets(p[i].cep);
    }
}

// função para imprimir os dados usando ponteiros
void imprimirDados(struct Cadastro *p) {
    printf("\n===== Dados cadastrados =====\n");
    for(int i = 0; i < 4; i++) {
        printf("\n--- Registro %d ---\n", i+1);
        printf("Nome: ");
        puts(p[i].nome);
        printf("Endereço: ");
        puts(p[i].end);
        printf("Cidade: ");
        puts(p[i].cidade);
        printf("Estado: ");
        puts(p[i].estado);
        printf("CEP: ");
        puts(p[i].cep);
    }
}

int main(){
    int resp = 1;
    
    while(resp == 1)
    {
        receberDados(registros);
        imprimirDados(registros);

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

#ifdef ex6

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