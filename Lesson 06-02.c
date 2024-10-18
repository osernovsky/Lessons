#include <stdio.h>

// Определяем структуру Student
struct Student {
    char name[50];
    int age;
    int group;
    float grade;
};

// Функция для вывода информации о студенте
void print_students(int size, struct Student *s) {

    for(int i=0; i<size; i++){
        printf("Студент номер %d:\n", i+1);
        printf("Имя: %s | ", s[i].name);
        printf("Возраст: %d\n", s[i].age);
        printf("Группа:%d | ", s[i].group);
        printf("Средний балл: %.2f\n", s[i].grade);
    }
}

int main(void) {
    int size=0;

    while (size <1){
    printf("Сколько всего студентов:");
    scanf("%d", &size);
    }

    struct Student student1[size];

    // Ввод данных о студенте

    for(int i=0; i<size; i++){
        printf("Введите имя %d студента: ", i+1);
        scanf("%49s", student1[i].name);
        printf("Введите возраст: ");
        scanf("%d", &student1[i].age);
        printf("Введите группу: ");
        scanf("%d", &student1[i].group);
        printf("Введите средний балл: ");
        scanf("%f", &student1[i].grade);
    }

    // Вывод данных
    print_students(size, student1);

    return 0;
}
