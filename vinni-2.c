/*
Задача 2.
Пользователь вводит N студентов: фамилия и оценка.
Найти средний балл и вывести фамилии тех, у кого оценка выше средней.
*/

#include <stdio.h>
#include <locale.h>
#define AR_LEN 100

struct Student {
    char name[30];
    int grade;
};

int main(void) {
    setlocale(LC_ALL, "");
    struct Student ar[AR_LEN];
    int n, i, sum = 0;
    double avg;

    printf("Сколько студентов? ");
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("%s %d", ar[i].name, &ar[i].grade);
        sum += ar[i].grade;
    }

    avg = (double)sum / n;
    printf("Средний балл: %.2f\n", avg);
    for (i = 0; i < n; ++i) {
        if (ar[i].grade > avg) printf("%s\n", ar[i].name);
    }
    return 0;
}