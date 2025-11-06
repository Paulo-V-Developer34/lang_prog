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
#define ex1

#ifdef ex1
int main(){

    short int a = 0;
    int b = 0;
    long int c = 0;
    float d = 0;
    double e = 0;
    char f;

    printf("\ndigite um numero pequeno");
    scanf("%hd",&a);
    printf("\ndigite um numero");
    scanf("%d",&b);
    printf("\ndigite um numero grande");
    scanf("%ld",&c);
    printf("\ndigite um numero de ponto flutuante");
    scanf("%f",&d);
    printf("\ndigite um numero de ponto flutuante maior");
    scanf("%lf",&e);
    getchar();
    printf("\ndigite uma letra");
    scanf("%c",&f);

    printf("        10");
    printf("        20");
    printf("        30");
    printf("        40");
    printf("        50");
    printf("        60");
    printf("\n12345678901234567890123456789012345678901234567890123456789012345");

    printf("\n%9hd ",a);
    printf("\t   %9ld ",c);
    printf("\t      %9d ",b);
    printf("\n     %14f ",d);
    printf("\t  %14lf ",e);
    printf("   %14c ",f);

    return 0;
}
#endif