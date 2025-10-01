#include <stdio.h>
#define ex2
 
#ifdef ex1
char verificarDica(){
    char vd;
 
    printf("\nO numero e maio, menor ou igual ");
    scanf("%c",&vd);
    getchar();
 
    if(!(vd == '='|vd == '>'| vd == '<')){
        printf("\nO simbolo digitado e incorreto, tente novamente");
    }
 
    return vd;
}
 
main(){
    int acertou, numero, max, min;
    char dica;
    char continuar;

    do{
        acertou = 0, numero=50, max=99, min=1;
        while(acertou == 0){
            printf("\nO numero que voce escolheu e %d?", numero);
            dica = verificarDica();
            if(dica == '='){
                printf("\n Acertei!");
                acertou = 1;
            }else if(dica == '>'){
                min = numero;
                numero += (max - min)/2;
            }else{
                max = numero;
                numero -= (max - min)/2;
            }
        }
        printf("\nfim");

        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');
 
}
#endif

#ifdef ex2
main(){
    int acertou, numero, max, min, tentativas;
    char dica;
    char continuar;

    do{
        acertou=0, numero=50, max=99, min=1, tentativas=0;
        while(acertou == 0){
            printf("\nO numero que voce escolheu e %d?", numero);
            printf("\nO numero e maio, menor ou igual ");
            scanf("%c",&dica);
            getchar();
        
            if(!(dica == '='|dica == '>'| dica == '<')){
            }
            
            switch (dica){
                case '=':
                    printf("\n Acertei!");
                    acertou = 1;
                    break;
                case '>':
                    min = numero;
                    numero += (max - min)/2;
                    break;
                case '<':
                    max = numero;
                    numero -= (max - min)/2;
                    break;
                default:
                    printf("\nO simbolo digitado e incorreto, tente novamente");
                    tentativas--;//para não contar a tentativa em que o usuário digitou um caracter inválido
                    break;
            }
            tentativas++;
        }
        printf("\nQuantidade de tentativas: %d",tentativas);
        printf("\nfim");

        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');
 
}
#endif