#include <stdio.h>

// Меняем местами значение переменных по указателям

void swap(int *a, int *b){ 

    int temp = *a;
    *a=*b;
    *b=temp;
}

int main(void){

    int i;
    int j;

    // Ввод чисел пользователем

    printf("Введите первое число:");
    scanf("%d", &i);

    printf("Введите второе число:");
    scanf("%d", &j);

    // Меняем значение переменных, результат выводим

    swap(&i, &j);
    printf("Первое число теперь: %d, а второе число:%d\n", i, j);    

    return 0;
}