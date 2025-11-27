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
#define ex3

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
char letras[11] = {b,d,f,h,j,k,m,o,q,s,u,w,y};

int pesquisa(char *letra){
    int count;
    for(count = 0; count < 10; count++)
}

int main(){

    int resp = 1;
    int igual = 0;
    char letra, *ptrLetra;
    ptrLetra = &letra;

    while(resp == 1)
    {
        
        printf("\ndigite uma letra");
        scanf("%c",&ptrLetra);

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