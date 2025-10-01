#include <stdio.h>
#define ex1

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
    int resp = 1;
    while(resp == 1)
    {
        guardar();
        separar();
        mostrar();

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
    int resp = 1;
    while(resp == 1)
    {
        guardar();
        separar();
        mostrar();

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
int vetor1[2][3];
int vetor2[2][3];
int vetor3[2][3];

main()
{
    int resp = 1;
    int i,n;

    while(resp == 1)
    {
        int aux = 0;
        while(aux != 2)
        {
            for(i=0; i<2; i++)
            {
                for(n=0; n<3; n++)
                {
                    if(aux == 0)
                    {
                        printf("Vetor 1 - Digite o numero de posicao %d da linha %d:\n", n, i);
                        scanf("%d", &vetor1[i][n]);
                    }
                    else
                    {
                        printf("Vetor 2 - Digite o numero de posicao %d da linha %d:\n", n, i);
                        scanf("%d", &vetor2[i][n]);
                    }
                }
            }
            aux = aux + 1;
        }

        for(i=0; i<2; i++)
        {
            for(n=0; n<3; n++)
            {
                vetor3[i][n] = vetor1[i][n] + vetor2[i][n];
            }
        }

        for(i=0; i<2; i++)
        {
            for(n=0; n<3; n++)
            {
                printf("O resultado da soma dos indices %d e %d e\' %d + %d = %d \n",i, n, vetor1[i][n], vetor2[i][n], vetor3[i][n]);
            }
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

}
#endif

#ifdef ex5

int vetor[10];

void main()
{
    int resp = 1;
    int n, i, aux, s;

    while(resp == 1)
    {
        for(n=0; n<10; n++)
        {
            printf("Digite o numero de posicao %d do vetor:\n", n);
            scanf("%d", &vetor[n]);

            for(i=-1; i<n; i++)
            {
                if(vetor[n] < vetor[i])
                {
                    aux = vetor[i];
                    vetor[i] = vetor[n];
                    vetor[n] = aux;
                }
            }
        }

        for (s = 0; s < n; s++) {
            printf("%d ", vetor[s]);
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
}

#endif
