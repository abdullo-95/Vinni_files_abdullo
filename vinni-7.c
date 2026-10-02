/*
Задача 7.
"Смирнов 12.45" (фамилия и время в секундах).
Найти и вывести победителя (минимальное время).
*/

#include <stdio.h>
#include <locale.h>
#define AR_LEN 100

struct Runner {
    char name[30];
    double time;
};

int main(void) {
    setlocale(LC_ALL, "");
    struct Runner ar[AR_LEN], r;
    FILE *f = fopen("in.txt", "r");
    int count = 0, best = 0;

    while (count < AR_LEN && 2 == fscanf(f, "%s %lf", r.name, &r.time)) {
        ar[count] = r;
        ++count;
    }
    fclose(f);

    for (int i = 1; i < count; ++i) {
        if (ar[i].time < ar[best].time) best = i;
    }

    printf("Победитель: %s (%.2f)\n", ar[best].name, ar[best].time);
    return 0;
}