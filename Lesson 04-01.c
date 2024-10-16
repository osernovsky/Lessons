#include <stdio.h>
#include <stdlib.h>

// Функция инициализации массива случайными числами от 1 до 100

void init(int massive[], int size){

    srand(time(NULL));
    
    for(int i=0; i<size; i++){
        massive[i]=(rand() % 99) + 1;
    }

}

// Функция "переворачивающая" элементы массива

void revert(int massive[], int size){
    int temp;
    for(int i=0; i<size/2; i++){
        temp = massive[i];
        massive[i]=massive[size-i-1];
        massive[size-i-1]=temp;
    }
}

int main(void){

    // Вводим размер массива и инициализируем его

    int size_m;
    printf("Введите размер массива:");
    scanf("%d", &size_m);
    
    int massive[size_m];

    init(massive, size_m);

    // Выводим получившийся массив на экран

    printf("Вывод массива случайных чисел\n");
    for(int i=0; i<size_m; i++){
        printf("%d ", massive[i]);
    }

    // Переворачиваем элементы и выводим результат

    revert(massive, size_m);

    printf("\nВывод массива случайных чисел в обратном порядке\n");
    for(int i=0; i<size_m; i++){
        printf("%d ", massive[i]);
    }

    printf("\n");
    return 0;
}