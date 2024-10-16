#include <stdio.h>

long long int factorial(long long int n) {
    if (n == 0) {
        return 1;  // базовый случай
    }
    return n * factorial(n - 1);  // рекурсивный вызов
}

int main() {
    int i;
    long long int result;
    char number[50];
    int lenght;

    printf("Введите целое число:");
    scanf("%d", &i);
    result = factorial(i);

    sprintf(number,"%lld", result);
    lenght=strlen(number);

    printf("Факториал %d: ", i);

    for(int j=0;j<lenght;j++){
        if(j>0 && (lenght-j)%3==0){
            printf(" ");
        }
        printf("%c",number[j]);
    }

    printf("\n");
    
    return 0;
}