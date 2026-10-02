/*
Задача 3.
Ввести N дней: дата (число) и температура.
Найти день с самой высокой температурой и вывести его дату и значение.
*/

#include <stdio.h>
#include <locale.h>
#define AR_LEN 100

struct Day {
    int date;
    int temp;
};

int main(void) {
    setlocale(LC_ALL, "");
    struct Day ar[AR_LEN];
    int n, i, best = 0;

    printf("Сколько дней? ");
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("%d %d", &ar[i].date, &ar[i].temp);
    }

    for (i = 1; i < n; ++i) {
        if (ar[i].temp > ar[best].temp) best = i;
    }

    printf("Самый тёплый день: %d, температура %d\n",
           ar[best].date, ar[best].temp);
    return 0;
}