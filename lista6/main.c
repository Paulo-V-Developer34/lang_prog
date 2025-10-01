#include <stdio.h>
#define ex2

#ifdef ex1
int main() {
    int dia, mes, ano;

    // Entrada da data
    printf("Digite o dia: ");
    scanf("%d", &dia);
    printf("Digite o mes: ");
    scanf("%d", &mes);
    printf("Digite o ano: ");
    scanf("%d", &ano);

    // Ajuste para o algoritmo de Zeller
    if (mes < 3) {
        mes += 12;
        ano -= 1;
    }

    int k = ano % 100;      // Ano dentro do século
    int j = ano / 100;      // Século

    // Fórmula de Zeller
    int h = (dia + 13*(mes + 1)/5 + k + k/4 + j/4 + 5*j) % 7;

    // h = 0 -> sábado, 1 -> domingo, ..., 6 -> sexta
    char* dias[] = {
        "Sabado", "Domingo", "Segunda-feira", "Terca-feira",
        "Quarta-feira", "Quinta-feira", "Sexta-feira"
    };

    printf("O dia da semana é: %s\n", dias[h]);

    return 0;
}
#endif // ex1

#ifdef ex2
int diaHoje, mesHoje, anoHoje;
int diaNasc, mesNasc, anoNasc;
int diaIdade, mesIdade, anoIdade;
int diaAux, mesAux, anoAux;
int dataDeHojeFoiColocada = 0;

void receberDtNascimento(){
    do{
        //pegando a idade do usuário
        printf("\nDigite sua data de nascimento (use apenas numeros)");
        printf("\nDia: ");
        scanf("%d",&diaNasc);
        printf("\nMes: ");
        scanf("%d",&mesNasc);
        printf("\nAno: ");
        scanf("%d",&anoNasc);

        if(diaNasc <= 0 || mesNasc <= 0 || anoNasc <= 0 || diaNasc > diaHoje && mesNasc > mesHoje && anoNasc > anoHoje || anoNasc > anoHoje){
            printf("\nAlgum valor esta incorreto, tente novamente");
        }
    }while(diaNasc <= 0 || mesNasc <= 0 || anoNasc <= 0 || diaNasc > diaHoje && mesNasc > mesHoje && anoNasc > anoHoje || anoNasc > anoHoje);

    

    printf("\nA sua data de aniversário foi definida para %d/%d/%d",diaNasc, mesNasc, anoNasc);
}

void receberDtHoje(){
    while(dataDeHojeFoiColocada == 0 || diaHoje <= 0 || mesHoje <= 0 || anoHoje <= 0){
        //pegando a idade do usuário
        printf("\nDigite a data de hoje (use apenas numeros)");
        printf("\nDia: ");
        scanf("%d",&diaHoje);
        printf("\nMes: ");
        scanf("%d",&mesHoje);
        printf("\nAno: ");
        scanf("%d",&anoHoje);

        if(diaHoje <= 0 || mesHoje <= 0 || anoHoje <= 0){
            printf("\nAlgum valor esta incorreto, tente novamente");
        }
        dataDeHojeFoiColocada = 1;
    }
    printf("\nA data foi definida para %d/%d/%d",diaHoje, mesHoje, anoHoje);
}

// converterMes(int dia, int mes){

// }

// void converterDia(int dia, int mes){
// }

int diasNoMes(int mes, int ano) {
    if (mes == 2) { 
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) { 
        return 30;
    } else { 
        return 31;
    }
}

void calcularIdade() {
    
    int anoTemp = anoHoje;
    int mesTemp = mesHoje;
    int diaTemp = diaHoje;

    if (diaTemp < diaNasc) {
        mesTemp--; 
        
        diaTemp += diasNoMes(mesTemp, anoTemp);
    }
    diaIdade = diaTemp - diaNasc;

    if (mesTemp < mesNasc) {
        anoTemp--; 
        mesTemp += 12; 
    }
    mesIdade = mesTemp - mesNasc;
    anoIdade = anoTemp - anoNasc;
}


int main(){
    do{
        receberDtHoje();
        receberDtNascimento();
        calcularIdade();

        printf("\nSua idade e\': %d anos, %d meses e %d dias",anoIdade, mesIdade, diaIdade);
    }while(1);

    return 0;
}
#endif // ex2

#ifdef ex3

// versão antiga que fiquei com pena de deletar ;-;
// int main(){
//     int a = 7; //0000 0111
//     int b = 9; //0000 1001
//     int numerosIguais, reajuste, verificacao, resultado, lim=0;
    
//     do{
//         //verificando numeros iguais
//         verificacao = 0;
//         numerosIguais = a & b; //0000 0001
//         reajuste = numerosIguais << 1; //0000 0010
//         verificacao = reajuste & a;
//         verificacao += reajuste & b;

//         lim++;

//     }while(verificacao != 0 && lim < 20);

//     resultado = a | b;

//     printf("O resultado da soma entre %d e %d e\' %d",a,b,resultado);
    
//     return 0;
// }

int main(){
    int c;
    int n1, n2;
    int bit_n1, bit_n2, bit_extra;
    int novo_numero, novo_bit;
    char continuar;

    do{
        novo_numero = 0;
        novo_bit = 0;

        //pegando os números
        printf("\nDigite um numero: ");
        scanf("%d",&n1);
        printf("\nDigite outro numero: ");
        scanf("%d",&n2);
        
        //irei percorrer todos os bits
        for(c = 0; c < 32; ++c){
            //pegando apenas 1 bit na posição c de cada número
            bit_n1 = n1&(1 << c);
            bit_n2 = n2&(1 << c);
    
            //fazendo a verificação dos bits, para resolver problemas como 1111 + 0101 = 1111, utilizando de ajustes para que fique 1111 + 0101 = 10100
            //o "bit_extra" fará a mediação de 1 bit + 1 bit = 1 bit na próxima casa binária
            if(bit_n1 & bit_n2){
                if(bit_extra == 1){
                    novo_bit = (1 << c);
                    novo_numero = novo_numero | novo_bit;
                }
                bit_extra = 1;
            }else{
                if(bit_n1 | bit_n2){
                    if(bit_extra == 0){
                        novo_bit = (1 << c);
                        novo_numero = novo_numero | novo_bit;
                    }
                }else{
                    if(bit_extra == 1){
                        novo_bit = (1 << c);
                        novo_numero = novo_numero | novo_bit;
                        bit_extra = 0;
                    }
                }
                
            }
        }
    
        printf("\nO resultado da soma entre %d e %d e\' %d",n1,n2,novo_numero);

        //perguntando se quer continuar
        printf("\nQuer continuar fazendo mais somas? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');

    return 0;
}
#endif

#ifdef ex4
int main() {
    int n1, n2;
    
    int soma, subtracao, multiplicacao;
    float divisao;

    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &n1);

    printf("Digite o segundo número inteiro: ");
    scanf("%d", &n2);


    soma = n1 + n2;

    subtracao = n1 - n2;

    multiplicacao = n1 * n2;

    if (n2 != 0) {
        divisao = (float)n1 / n2;
    } else {
        printf("\nDivisao por zero gera um erro, por isso nao podera ser mostrada");
        divisao = 0.0; 
    }

    printf("Calculos com os numeros %d e %d", n1, n2);

    printf("\nSoma:          %d + %d = %d", n1, n2, soma);
    printf("\nSubtração:     %d - %d = %d", n1, n2, subtracao);
    printf("\nMultiplicação: %d * %d = %d", n1, n2, multiplicacao);
    
    if (n2 != 0) {
        printf("\nDivisão:       %d / %d = %.2f", n1, n2, divisao);
    } else {
        printf("\nDivisão:       Impossível (Divisão por zero)\n");
    }

    return 0;
}
#endif

#ifdef ex5
int main() {
    int n1, n2;
    
    int soma, subtracao, multiplicacao;
    float divisao;

    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &n1);

    printf("Digite o segundo número inteiro: ");
    scanf("%d", &n2);


    soma = n1; 
    soma += n2;

    subtracao = n1;
    subtracao -= n2;

    multiplicacao = n1;
    multiplicacao *= n2;

    if (n2 != 0) {
        divisao = (float)n1;
        divisao /= n2;
    } else {
        printf("\nDivisao por zero gera um erro, por isso nao podera ser mostrada");
        divisao = 0.0; 
    }

    printf("Calculos com os numeros %d e %d", n1, n2);

    printf("\nSoma:          %d + %d = %d", n1, n2, soma);
    printf("\nSubtração:     %d - %d = %d", n1, n2, subtracao);
    printf("\nMultiplicação: %d * %d = %d", n1, n2, multiplicacao);
    
    if (n2 != 0) {
        printf("\nDivisão:       %d / %d = %.2f", n1, n2, divisao);
    } else {
        printf("\nDivisão:       Impossível (Divisão por zero)\n");
    }

    return 0;
}
#endif