#include <stdio.h>

int lerInteiro(const char *pergunta){
    int x;
    printf("%s", pergunta);
    while (scanf("%d", &x) != 1){
        printf("\x1b[31mERRO: \x1b[0m\x1b[33m!!DIGITE APENAS NUMERO TIPO INTEIRO!!\x1b[0m\n");
        printf("%s", pergunta);
        while (getchar() != '\n');
    }
    return x;
}

double lerDouble(const char *pergunta){
    double x;
    printf("%s", pergunta);
    while (scanf("%lf", &x) != 1){
        printf("\x1b[31mERRO: \x1b[0m\x1b[33m!!DIGITE APENAS NUMERO TIPO DOUBLE!!\x1b[0m\n");
        printf("%s", pergunta);
        while (getchar() != '\n');
    }
    return x;
}

char lerChar(const char *pergunta){
    char x;
    printf("%s", pergunta);
    while (scanf(" %c", &x) != 1){
        printf("\x1b[31mERRO: \x1b[0m\x1b[33m!!DIGITE APENAS NUMERO TIPO CHAR!!\x1b[0m\n");
        printf("%s", pergunta);
        while (getchar() != '\n');
    }
    return x;
}