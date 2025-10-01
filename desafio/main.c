int main(){
    char continuar;

    do{
        printf("\nQuer executar o programa novamente (digite \"s\" se sim)? ");
        getchar();
        scanf("%c", &continuar);
    }while(continuar == 's' || continuar == 'S');

    return 0;
}