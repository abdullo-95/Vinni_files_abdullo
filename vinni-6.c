/*
Задача 6.
"Иванов 50000". Вывести фамилии сотрудников,
чьи зарплаты выше средней.
*/

#include <stdio.h>
#include <locale.h>
#define AR_LEN 100

struct Employee {
    char name[30];
    int salary;
};

int main(void) {
    setlocale(LC_ALL, "");
    struct Employee ar[AR_LEN], e;
    FILE *f = fopen("in.txt", "r");
    int count = 0, sum = 0;
    double avg;

    while (count < AR_LEN && 2 == fscanf(f, "%s %d", e.name, &e.salary)) {
        ar[count] = e;
        sum += e.salary;
        ++count;
    }
    fclose(f);

    avg = (double)sum / count;
    for (int i = 0; i < count; ++i) {
        if (ar[i].salary > avg) printf("%s\n", ar[i].name);
    }
    return 0;
}