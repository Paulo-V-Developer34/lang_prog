#include <stdio.h>
#define ex2

#ifdef ex1
main(){
    int x;
    int y;
    char continuar;

    do{
        x = 10;
        y = 3;
        printf("inicio");
        printf("\nx: %d, y: %d",x,y);
    
        x = x + y;
        y = x - y;
        x = x - y;
    
        printf("\nfim");
        printf("\nx: %d, y: %d",x,y);

        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');
    
}
#endif // ex

#ifdef ex2
int main(){

    short int a = 0;
    int b = 0;
    long int c = 0;
    float d = 0;
    double e = 0;
    char f, continuar;

    do{
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

        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');

    return 0;
}
#endif // ex4

#ifdef ex3
main(){
    int inteiro;
    int VLminimo;
    int resultado = 0;
    int aux = 1;
    char continuar;

    do{
        printf("digite um numero inteiro: ");
        scanf("%d",&inteiro);
     
        do{
            printf("digite um valor minimo: ");
            scanf("%d",&VLminimo);
     
            if(VLminimo<=inteiro){
                printf("Erro! Digite um numero maior que o valor inteiro!");
            }
        }while(VLminimo<=inteiro);
     
        while(resultado <= VLminimo){
            resultado = aux * inteiro;
            aux = aux + 1;
        }
     
        printf("menor multiplo de %d maior que %d. Resultado: %d",inteiro, VLminimo, resultado);

        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');
 
}
#endif
 
#ifdef ex4
main(){
    int segundos;
    char continuar;

    do{
        printf("\nDigite uma quantidade de segundos para converte-lo em horas, minutos e segundos: ");
        scanf("%d",&segundos);
     
        printf("\nO numero convertido virou: %dh %dmin %ds",(segundos/3600),((segundos%3600)/60),(((segundos%3600)%60)));

        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');
 
}
#endif

#ifdef ex5
int main()
{
	int numeroInvertido, numero, valido=0;
    char continuar;

    do{
        valido = 0;

        while(valido == 0) {
            printf("\nDigite um numero inteiro de 3 digitos");
            scanf("%d",&numero);
        
            if(numero / 1000 > 0) {
                printf("\nSeu numero e invalido, tente novamente");
            }else{
                valido = 1;
            }
        }
        //invertendo o número
        numeroInvertido = (numero/100)+(numero/10 - (numero/100 *10))*10 + (numero%10)*100;
        printf("\nO numero digitado, a saber, %d ordenado de forma invertida fica %d",numero,numeroInvertido);

        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');
	return 0;
}
#endif

