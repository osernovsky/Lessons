#include <stdio.h>

int main(void){

    int number;

    printf("Введите целое число:");
    scanf("%d", &number);

    if (number<0){
        printf("\nЧисло %d - отрицательное", number);
        } else if (number==0){
            printf("\nЧисло %d - равно нулю", number);
            } else{
                printf("\nЧисло %d - положительное", number);
                }
    return 0;
}