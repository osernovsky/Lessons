#include <stdio.h>

// Функция заполнения таблицы значениями

void initialize_table(int sizetable, int table[sizetable][sizetable]){

    for(int i=0; i<sizetable; i++){
        for(int j=0;j<sizetable; j++){
            table[i][j]=(i+1)*(j+1);
        }
    }
}

// Функция вывода на экран таблицы

void print_table(int sizetable, int table[sizetable][sizetable]){

    for(int i=0; i<sizetable; i++){
        for(int j=0;j<sizetable; j++){
            if (table[i][j]<10){
                printf("    %d",table[i][j]); // количество пробелов для выравнивания таблицы
            } else{
                printf("  %d", table[i][j]); // уменьшаем на один пробел для двузначных
                }

        }
        printf("\n\n");
    }
}

int main(void){

    int size;

    // Определяем размер таблицы умножения
    do{
    printf("Введите размер таблицы, от 2 до 9:");
    scanf("%d", &size);
    } while (size <2 || size >9);

    int table[size][size];

    // Заполняем таблицу значениями
    initialize_table(size, table);

    //Выводим таблицу
    print_table(size, table);
    
    return 0;
}