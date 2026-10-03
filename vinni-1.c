/*
Задача 1.
Пользователь вводит 5 целых чисел. Найти и вывести их сумму.
*/

#include <stdio.h>
int main(void) {
	
    int ar[5];
    int i, sum = 0;

    printf("Введите 5 чисел:\n");
    for (i = 0; i < 5; ++i) {
        scanf("%d", &ar[i]);
    }

    for (i = 0; i < 5; ++i) {
        sum += ar[i];
    }

    printf("Абдулло, сумма = %d\n", sum);
	printf("Abdullo);
    return 0;
}
