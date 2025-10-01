#include <stdio.h>
#define ex3

#ifdef ex1
int numeros[10], indPar[5], indImp[5];

void guardar(){
    int c;
    for(c=0;c<10;c++){
        printf("\nDigite um numero para a posicao %d do vetor",c);
        scanf("%d",&numeros[c]);
    }
}

void separar(){
    int c;
    for(c=0;c<10;c++){
        if(!c==0){
            if(c%2==1){
                indPar[c/2]=numeros[c];
            }else{
                indImp[c/2]=numeros[c];
            }
        }else{
            indImp[0]=numeros[c];
        }
    }
}

void mostrar(){
    int c;
    printf("\nOs vetores sao:");
    printf("\nv: {");
    for(c=0;c<10;c++){
        printf("%d,",numeros[c]);
    }
    printf("\b}");
    
    printf("\nu: {");
    for(c=0;c<5;c++){
        printf("%d,",indImp[c]);
    }
    printf("\b}");
    
    printf("\nw: {");
    for(c=0;c<5;c++){
        printf("%d,",indPar[c]);
    }
    printf("\b}");
    
}

int main()
{
    char continuar;
    do{
        guardar();
        separar();
        mostrar();

        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');
    return 0;
}
#endif

#ifdef ex3
int numeros[10], indPar[10], indImp[10];
int impPosition=0, parPosition=0;

void guardar(){
    int c;
    for(c=0;c<10;c++){
        printf("\nDigite um numero para a posicao %d do vetor",c);
        scanf("%d",&numeros[c]);
    }
}

void separar(){
    int c;
    for(c=0;c<10;c++){
        if(!c==0){
            if(numeros[c]%2==1){
                indImp[impPosition]=numeros[c];
                impPosition++;
            }else{
                indPar[parPosition]=numeros[c];
                parPosition++;
            }
        }else{
            indPar[parPosition]=numeros[c];
            parPosition++;
        }
    }
}

void mostrar(){
    int c;
    printf("\nOs vetores sao:");
    printf("\nv: {");
    for(c=0;c<10;c++){
        printf("%d,",numeros[c]);
    }
    printf("\b}");
    
    printf("\nu: {");
    for(c=0;c<impPosition;c++){
        printf("%d,",indImp[c]);
    }
    printf("\b}");
    
    printf("\nw: {");
    for(c=0;c<parPosition;c++){
        printf("%d,",indPar[c]);
    }
    printf("\b}");
    
}

int main()
{
    char continuar;
    do{
        guardar();
        separar();
        mostrar();
        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');
    return 0;
}
#endif