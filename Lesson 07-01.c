# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int struct_size = 0;

struct numbers_text{
    char name[50];
    int number;
};

// Функция инициализации места под структуру

int struct_size_modify(struct numbers_text **array1) {

    *array1 = realloc(*array1, struct_size * sizeof(struct numbers_text));

    if (*array1 == NULL) { // Проверка на успешное выделение памяти
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    return 0;
}


// Функция вывода массива на экран

void array_print(struct numbers_text *array) {
    for (int i = 0; i < struct_size; i++) {
        printf("%d - %s\n", array[i].number, array[i].name);
    }
}

// Функция добавления элемента к массиву

int main(void){

    struct numbers_text *array = NULL;

    while (struct_size < 1){
        printf("Введите начальный размер массива:");
        scanf("%d", &struct_size);
    }

    // Выделение памяти для массива структур
    struct_size_modify(&array);

    for(int i=0; i<struct_size; i++){
        array[i].number= i+1;
        //array[i].name="Text";
        strcpy(array[i].name, "Test");
    }

    array_print(array);
    
    free(array);
}