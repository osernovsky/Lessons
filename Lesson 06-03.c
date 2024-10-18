#include <stdio.h>

// Определяем структуру
struct employee {
    char name[20];
    int age;
    float gross;
};

// Функция для вывода информации о зарплате

void print_gross(int size, struct employee *s, float change) {

    for(int i=0; i<size; i++){
        printf("Сотрудник номер %d, его зарплата:%.2f\n", i+1, s[i].gross);
    }
}

// Функция изменения зарплаты

void gross_change(int size, struct employee *s, float change) {

    for(int i=0; i<size; i++){
        s[i].gross *= (1 + change/100);
    }
}

int main(void) {

    int size=0;

    while (size <1){
    printf("Сколько всего сотрудников:");
    scanf("%d", &size);
    }

    struct employee emp[size];

    void (*operation) (int, struct employee*, float);

    // Ввод данных о сотрудниках

    for(int i=0; i<size; i++){
        printf("Введите имя %d сотрудника: ", i+1);
        scanf("%19s", emp[i].name);
        printf("Введите возраст: ");
        scanf("%d", &emp[i].age);
        printf("Введите зарплату: ");
        scanf("%f", &emp[i].gross);
    }

    // Вывод данных
    operation = print_gross;
    operation(size, emp, 0);

    // Изменяем зарплату на и выводим результат
    int change;
        printf("На сколько процентов изменяем зарплату?:");
        scanf("%d", &change);

    operation = gross_change;
    operation(size, emp, change);
    
    operation = print_gross;
    operation(size, emp, 0);

    return 0;
}
