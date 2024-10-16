#include <stdio.h>

int max(int a, int b){ // Сравниваем какое число больше, его и возвращаем

    if (a >= b) return a; else return b;
}

int main(void){

    int i;
    int j;

    // Ввод чисел пользователем

    printf("Введите первое число:");
    scanf("%d", &i);

    printf("Введите второе число:");
    scanf("%d", &j);

    // Сравниваем, результат выводим

    printf("Большее из них: %d\n", max(i,j));    

    return 0;
}