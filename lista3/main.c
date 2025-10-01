#define ex2
#include <stdio.h>
 
#ifdef ex1
int verifica(int num)
{
    int aux;
 
    if(num > 0)
    {
        aux = 1;
    }else{
        if(num < 0)
        {
            aux = 0;
        }
        else
        {
            aux = -1;
        }
    }
    return aux;
}
 
int soma(int num1,int num2)
{
    int aux = 0, c, maiorN, menorN;
 
 
    if(num1 > num2)
    {
        maiorN = num1;
        menorN = num2;
    }
    else{
        maiorN = num2;
        menorN = num1;
    }
 
    for(c = menorN+1; c<maiorN; ++c)
    {
        aux = c + aux;
    }
 
    return aux;
}
 
int mult(int num1,int num2)
{
    int aux = 1, c, maiorN, menorN;
 
 
    if(num1 > num2)
    {
        maiorN = num1;
        menorN = num2;
    }
    else{
        maiorN = num2;
        menorN = num1;
    }
 
    for(c = menorN+1; c<maiorN; ++c)
    {
        aux = c * aux;
    }
 
    return aux;
}
 
int div(int num1,int num2)
{
    return num1/num2;
}
 
main()
{
    int num1, num2, situacao1, situacao2;
    char continuar;
 
    do{
        printf("Digite o primeiro numero: \n");
        scanf("%d", &num1);
     
        printf("Digite o segundo numero: \n");
        scanf("%d", &num2);
     
        situacao1 = verifica(num1);
        situacao2 = verifica(num2);
     
        if(situacao1 == 1 && situacao2 == 1)
        {
            printf("\nSoma de todos os numeros entre %d e %d: %d",num1,num2,soma(num1, num2));
        }
     
        if(situacao1 == 0 && situacao2 == 0)
        {
            printf("\nMultiplicacao de todos os numeros entre %d e %d: %d",num1,num2,mult(num1, num2));
        }
     
        if(situacao1 == 1 && situacao2 == 0)
        {
            printf("\nDivisao entre %d e %d: %d",num1,num2,div(num1, num2));
        }
        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');
}
#endif
#ifdef ex2
int fnFatorial(int numero){
    int contador, fatorial=1;

    //calculando fatorial
    for(contador=numero;contador>=1;contador--){
        //printf("\nValor do contador: %d, Valor do fatorial: %d, valor do numero: %d",contador,fatorial,numero);
        fatorial = fatorial * contador;
    }

    return fatorial;
}

int somaAlgarismosFatorial(int numero){
    int contador, quantAlgarismos=0, soma=0, algarismo=0, posicao_algarismo = 1;//cuidado quando esquecer de inicializar variável, porque isso pode te dar muita dor de cabeça!

    //verificando a quantidade de algarismos
    for(contador=1; contador <= numero; contador = contador * 10){
        //printf("\nContador: %d, Divisao: %d",contador, numero/contador);
        if(numero/contador > 0){
            quantAlgarismos += 1;
        }else{
            break;
        }
    };
    //printf("\nQuantidade de algarismos: %d",quantAlgarismos);

    //calculando a soma de cada algarismo
    for(contador=1; contador <= quantAlgarismos; contador++){
        if(contador > 1){
            posicao_algarismo *= 10;
        }

        algarismo = numero/posicao_algarismo%10;
        //printf("\nAlgarismo: %d",algarismo);
        soma += algarismo;
    }

    return soma;
}

int main(){
    int N, fatorial, soma;
    char continuar;
    do{
        printf("\nDigite um numero inteiro: ");
        scanf("%d",&N);
    
        fatorial = fnFatorial(N);
        //printf("\nFatorial de %d: %d",N,fatorial);
    
        soma = somaAlgarismosFatorial(fatorial);
        printf("\nA soma dos algarismos do fatorial de %d e\' %d",N,soma);
        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');


    return 0;
}
#endif // ex2
 
#ifdef ex3
float soma(float numero, float numero2){
    float soma = numero + numero2;
    return soma;
}
float subtracao(float numero, float numero2){
    float sub = numero - numero2;
    return sub;
}
float multip(float numero, float numero2){
    float mult = numero * numero2;
    return mult;
}
float divisao(float numero, float numero2){
    float div = numero / numero2;
    return div;
}
 
main(){
    float n1, n2;
    char continuar;

    do{
        printf("Digite um numero: ");
        scanf("%f",&n1);
        printf("\nDigite outro numero: ");
        scanf("%f",&n2);
     
        printf("\nA Soma de %.2f e %.2f e:\t\t%.2f",n1,n2,soma(n1,n2));
        printf("\nA Subtracao de %.2f e %.2f e:\t\t%.2f",n1,n2,subtracao(n1,n2));
        printf("\nA Multiplicacao de %.2f e %.2f e:\t%.2f",n1,n2,multip(n1,n2));
        printf("\nA Divisao de %.2f e %.2f e:\t\t%.2f",n1,n2,divisao(n1,n2));

        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');
}
#endif // ex3
 
#ifdef ex4
float soma(float numero, float numero2){
    float soma = numero + numero2;
    return soma;
}
float subtracao(float numero, float numero2){
    float sub = numero - numero2;
    return sub;
}
float multip(float numero, float numero2){
    float mult = numero * numero2;
    return mult;
}
float divisao(float numero, float numero2){
    float div = numero / numero2;
    return div;
}
 
main(){
    float n1, n2;
    char continuar;

    do{
        do{
     
            printf("\nDigite um numero: ");
            scanf("%f",&n1);
            printf("\nDigite outro numero: ");
            scanf("%f",&n2);
     
            if(!(n1 == 0 || n2 == 0))
            {
                printf("\nA Soma de %.2f e %.2f e:\t\t%.2f",n1,n2,soma(n1,n2));
                printf("\nA Subtracao de %.2f e %.2f e:\t\t%.2f",n1,n2,subtracao(n1,n2));
                printf("\nA Multiplicacao de %.2f e %.2f e:\t%.2f",n1,n2,multip(n1,n2));
                printf("\nA Divisao de %.2f e %.2f e:\t\t%.2f",n1,n2,divisao(n1,n2));
            }
     
        }while(!(n1 == 0 || n2 == 0));
        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');
 
 
}
#endif // ex4
 
#ifdef ex5
#include <stdio.h>
float soma(float numero, float numero2){
    float soma = numero + numero2;
    return soma;
}
float subtracao(float numero, float numero2){
    float sub = numero - numero2;
    return sub;
}
float multip(float numero, float numero2){
    float mult = numero * numero2;
    return mult;
}
float divisao(float numero, float numero2){
    float div = numero / numero2;
    return div;
}
 
 
int main() {
    float acumulador, numero2, terminarCalculo;
    int qtddNumero, c;
    char operacao_calculadora;
    char continuar;
 
    printf("Digite o primeiro numero: \n");
    scanf(" %f",&acumulador);
 
    do{
        do{
            terminarCalculo=0;
            //escolhendo a operação
            printf("qual operacao voce quer realizar? digite valores entre +, x, /, -, =\n");
            scanf(" %c",&operacao_calculadora);
     
            if(!(operacao_calculadora == '='))
            {
                printf("Digite o proximo numero: \n");
                scanf(" %f",&numero2);
            }
     
            switch(operacao_calculadora) {
                case '+': {
                    acumulador = soma(acumulador, numero2);
                    break;
                };
                case 'x': {
                    acumulador = multip(acumulador, numero2);
                    break;
                };
                case '/': {
                    acumulador = divisao(acumulador, numero2);
                    break;
                };
                case '-': {
                    acumulador = subtracao(acumulador, numero2);
                    break;
                };
                case '=': {
                    terminarCalculo = 1;
                    break;
                };
                default: {
                    printf("houve um erro, tente novamente");
                }
            }
     
            printf("o resultado da operacao e\' %f \n", acumulador);
     
            if(!(operacao_calculadora == '='))
            {
                printf("\nagora faremos mais operacoes\n");
            }
     
        }while(terminarCalculo == 0);

        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');
    return 0;
}
#endif // ex3