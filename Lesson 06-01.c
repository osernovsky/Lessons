#include <stdio.h>


float add (float a, float b){
    return a + b;
}

float multiply (float a, float b){
    return a * b;
}

float substraction (float a, float b){
    return a - b;
}

float divide (float a, float b){
    return a / b;
}

int main(void){

    float (*operation)(float, float);

    float a;
    float b;
    char operand;

    printf("Введите первое число:");
    scanf("%f", &a);

    printf("Введите второе число:");
    scanf("%f", &b);

    while (getchar() != '\n'); // Убираем \n

    printf("Введите операцию над числами (+)(-)(*)(/):");
    scanf("%c", &operand);

    switch (operand){
        case '+':
        operation = add;
        break;

        case '-':
        operation = substraction;
        break;
        
        case '*':
        operation = multiply;
        break;

        case '/':
        if (b!=0) operation = divide; else{
                printf("Делить на ноль нельзя.\n");
                return 1;
            }
        break;
        
        default:
        printf("Ошибка: Неизвестная операция.\n");
        return 1;
    }

    printf("Результат: %.2f\n", operation(a, b));
    
    return 0;
}