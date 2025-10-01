#define ex1
#include "stdio.h"

#ifdef ex1
char texto1[11];
char texto2[11];

int compara(char texto1[11], char texto2[11])
{
    int aux = 0, i;

    for(i = 0; i<10; i++)
    {
        if(texto1[i] == texto2[i])
        {
            aux = 1;
        }
        else
        {
            aux = 0;
            break;
        }
    }

    return aux;
}

main()
{
    int resp = 1, result, i;

    while(resp == 1)
    {
        do{
            printf("Digite a primeira string: \n");
            gets(texto1);

            i=0;

            while(texto1[i] != '\0')
            {
                i++;
            }

            if (i > 10)
            {
                printf("Erro! Limite de caracteres (10) excedido.\n");
            }
        }while(i > 10);

        do{
            printf("Digite a segunda string: \n");
            gets(texto2);

            i=0;

            while(texto2[i] != '\0')
            {
                i++;
            }

            if (i > 10)
            {
                printf("Erro! Limite de caracteres (10) excedido.\n");
            }
        }while(i > 10);

        result = compara(texto1, texto2);

        if(result == 1)
        {
            printf("Os textos sao iguais \n");
        }
        else
        {
            printf("Os textos sao diferentes \n");
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


#ifdef ex2
char nome1[8];
char nome2[8];
char nome3[8];
char nome4[8];
char nome5[8];

main()
{
    int resp = 1;
    while(resp == 1)
    {
        printf("Digite o nome 1: \n");
        scanf("%s",&nome1[0]);

        printf("Digite o nome 2: \n");
        scanf("%s",&nome2[0]);

        printf("Digite o nome 3: \n");
        scanf("%s",&nome3[0]);

        printf("Digite o nome 4: \n");
        scanf("%s",&nome4[0]);

        printf("Digite o nome 5: \n");
        scanf("%s",&nome5[0]);

        printf("        10        20        30        40        50\n");
        printf("12345678901234567890123456789012345678901234567890 \n");

        printf("  %-40s%.7s\n",nome1, nome5);
        printf("            %-20.7s%.7s\n", nome2, nome4);
        printf("                      %.7s\n", nome3);

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

#ifdef ex3
char texto[40];

int comprimento(char texto[40])
{
    int nCompr;

    while(texto[nCompr] != '\0')
    {
        nCompr++;
    }

    return nCompr;
}

main()
{
    int resp = 1;
    while(resp == 1)
    {
        printf("Digite uma string: \n");
        gets(texto);

        int nCompr = comprimento(texto);

        printf("comprimento e: %d", nCompr);

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

#ifdef ex4
char texto[11];

main()
{
    int i, resp = 1;

    while(resp == 1)
    {

        do{
            printf("Digite uma string: \n");
            gets(texto);

            i=0;

            while(texto[i] != '\0')
            {
                i++;
            }

            if (i > 10)
            {
                printf("Erro! Limite de caracteres (10) excedido.\n");
            }
        }while(i > 10);

        i = 0;

        while (texto[i] != '\0') {

            if (texto[i] >= 'a' && texto[i] <= 'z')
            {
                texto[i] = texto[i] - 32;
            }

            i++;
        }

        printf("Resultado da string em maiusculo: %s\n", texto);

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
char texto[11];

main()
{
    int resp;
    int i;

    do{

        do{
            printf("Digite uma string: \n");
            gets(texto);

            i=0;

            while(texto[i] != '\0')
            {
                i++;
            }

            if (i > 10)
            {
                printf("Erro! Limite de caracteres (10) excedido.\n");
            }
        }while(i > 10);

        i = 0;

        while (texto[i] != '\0') {

            if (texto[i] >= 'A' && texto[i] <= 'Z')
            {
                texto[i] = texto[i] + 32;
            }

            i++;
        }

        printf("Resultado da string em minusculo: %s\n", texto);

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

    }while(resp == 1);
}
#endif
