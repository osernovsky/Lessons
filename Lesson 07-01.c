# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int struct_size = 0;

struct numbers_text{
    char name[50];
    int number;
};

// Массивы с текстовыми представлениями чисел
const char *ones[] = {"ноль", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять"};
const char *teens[] = {"десять", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"};
const char *tens[] = {"", "", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};
const char *hundreds[] = {"", "сто", "двести", "триста", "четыреста", "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот"};

// Функция для конвертации числа в строку
void number_to_text(int num, char *result) {
    if (num < 0 || num > 1000) {
        strcpy(result, "Число вне диапазона");
        return;
    }

    if (num == 1000) {
        strcpy(result, "тысяча");
        return;
    }

    if (num >= 0 && num < 10) {
        strcpy(result, ones[num]);
    } else if (num >= 10 && num < 20) {
        strcpy(result, teens[num - 10]);
    } else if (num >= 20 && num < 100) {
        int ten = num / 10;
        int one = num % 10;
        
        strcpy(result, tens[ten]);
        if (one != 0) {
            strcat(result, " ");
            strcat(result, ones[one]);
        }
    } else {
        int hundred = num / 100;
        int ten = (num % 100) / 10;
        int one = num % 10;

        strcpy(result, hundreds[hundred]);

        int temp = ten * 10 + one;

        if (temp > 0 && temp < 10) {
            strcat(result, " ");
            strcat(result, ones[temp]);
        } else if (temp >= 10 && temp < 20) {
            strcat(result, " ");
            strcat(result, teens[temp - 10]);
        } else if (temp >= 20 && temp < 100) {
            int ten = temp / 10;
            int one = temp % 10;

            strcat(result, " ");
            strcat(result, tens[ten]);
            if (one != 0) {
                strcat(result, " ");
                strcat(result, ones[one]);
            }
        }

    }
}

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
        printf("%d - %s. ", array[i].number, array[i].name);
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
        number_to_text(i+1, array[i].name);
    }

    array_print(array);

    free(array);
}
