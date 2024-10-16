#include <stdio.h>
#include <string.h>

int main(void){

    char realpass[10] = "true";
    char pass[10];

    do {
        printf("Введите пароль:");
        scanf("%s", pass);
    } while (strcmp(pass, realpass));
    printf("Пароль верный!\n");

    return 0;
}