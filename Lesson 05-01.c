#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


int main(void){

    // Объявляем переменные

    FILE *file;
    char filename[50];
    char string[100];
    char string_file[100];
    int lines;

    // Вводим имя файла
    printf("Введите название файла для записи:");
    scanf("%s", filename);
    getchar(); // Очищаем буфер ввода

    // Открываем файл для добавления, если не получилось то для записи

    file=fopen(filename, "a");
    if (file==NULL){
        file=fopen(filename, "w");
        if (file==NULL){        
            printf("Ошибка открытия файла.");
            return 1;
        }
    }

    // Вводим строку для записи

    printf("Введите строку для записи:");
    fgets(string, 100, stdin);

    // Случайным образом несколько раз записываем эту строку в файл

    srand(time(NULL));
    lines=(rand() % 100 + 1);
    char temp[50];

    // Записываем строки в файл и закрываем его

    for(int i=0; i<lines; i++){
        sprintf(temp, "%d", i+1);
        fprintf(file, "Строка %s: %s", temp, string);       
    }
    fclose(file);  

    // Открываем файл для чтения и выводим содержимое

    int linesread=0;

    file=fopen(filename, "r");
    if (file==NULL){
        printf("Ошибка открытия файла.");
        return 1;
    }

    while(fgets (string_file, 100, file)){
        linesread++;
        printf("%s", string_file);
    }

    fclose(file);  
    printf("Всего в файле %d строк\n", linesread);

    // Подсчитываем слова, алгоритм подсмотрел

    file=fopen(filename, "r");
    if (file==NULL){
        printf("Ошибка открытия файла.");
        return 1;
    } 

    int words=0;
    int inword=0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            // Если встретили пробел или символ новой строки — заканчиваем слово
            inword = 0;
        } else if (!inword) {
            // Начинаем новое слово
            inword = 1;
            words++;
        }
    }
    fclose(file);  
    printf("Всего в файле %d слов\n", words);
    
    return 0;
}