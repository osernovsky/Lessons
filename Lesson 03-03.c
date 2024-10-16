#include <stdio.h>

// Функция для рекурсивного метода, поддерживает и положительные и отрицательные запросы

int fibonacchi(int i){

    if (i>=0){ // Вычисляем для положительного числа
        if (i==0){
            return 0; // Частный случай нуля
        } else if (i==1){
            return 1; // Частный случай единицы
        } else{
            return fibonacchi(i-1)+fibonacchi(i-2);
        }
    } else{ // Вычисляем для отричательного числа
        if (i==-1){
            return 1; // Частный случай для минус один
        } else { if (i==-2){
            return -1; // Частный случай для минус два
        }
            return fibonacchi(i+2)-fibonacchi(i+1);
        }
    } 
}

// Функция для итеративного метода, поддерживает и положительные и отрицательные запросы и работает быстрей

int fibonacchi_iterative(int i){
        
    int prev1;
    int prev2;
    int result;

    if (i>=0){ // Вычисляем для положительного числа
        if (i==0){
            return 0; // Частный случай нуля
        } else if (i==1){
            return 1; // Частный случай единицы
        } else{
            int prev1=0;
            int prev2=1;
            for(int j=2; j<=i; j++){
                result = prev1 + prev2;
                prev1 = prev2;
                prev2 = result;
            }
        return result;
        }
    } else{ // Вычисляем для отрицательного числа
        if (i==-1){
            return 1; // Частный случай для минус один
        } else{
            prev1=1;
            prev2=0;
            for(int j=-2; j>=i; j--){
                result = prev2 - prev1;
                prev2 = prev1;
                prev1 = result;
            }
            return result;                
            }
        }
}

int main(void){

    int number;

    printf("Введите номер числа Фибначчи:");
    scanf("%d", &number);

    printf("Число Фибоначчи F(%d) рекурсивным методом = %d\n", number, fibonacchi(number));
    printf("Число Фибоначчи F(%d) итеративным методом = %d\n", number, fibonacchi_iterative(number));

    return 0;
}