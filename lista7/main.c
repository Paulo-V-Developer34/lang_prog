#include <stdio.h>
#define ex3

#ifdef ex3
struct data {
    int dia;
    int mes;
    int ano;
    char nome_mes[10];
};

typedef struct data data;

int calcularDiferenca(){
    
}

data calendario[2];
int main(){
    printf("Este programa calcula a diferenca entre 2 datas");
    printf("\nEntre com a primeira data: \n");
    printf("Dia: ");
    scanf("%d",&calendario[0].dia);
    printf("\nMes: ");
    scanf("%d",&calendario[0].mes);
    printf("\nAno: ");
    scanf("%d",&calendario[0].ano);
    printf("\ndigite o mes por extenso: ");
    scanf("%s",&calendario[0].nome_mes[0]);

    printf("\nEntre com a segunda data: \n");
    printf("Dia: ");
    scanf("%d",&calendario[1].dia);
    printf("\nMes: ");
    scanf("%d",&calendario[1].mes);
    printf("\nAno: ");
    scanf("%d",&calendario[1].ano);
    printf("\ndigite o mes por extenso: ");
    scanf("%s",&calendario[1].nome_mes[0]);

    printf("\nA primeira data foi definida como: ");
    printf("%d/",calendario[0].dia);
    printf("%d/",calendario[0].mes);
    printf("%d, ",calendario[0].ano);
    printf("%s\n",calendario[0].nome_mes);

    printf("\nA segunda data foi definida como: ");
    printf("%d/",calendario[1].dia);
    printf("%d/",calendario[1].mes);
    printf("%d, ",calendario[1].ano);
    printf("%s\n",calendario[1].nome_mes);
    
    

    return 0;
}
#endif
