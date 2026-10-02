/*
Задача 10.
Файл in.txt: "Иванов 15000.50" (фамилия и баланс).
Вывести клиентов с отрицательным балансом (должников).
*/

#include <stdio.h>
#include <locale.h>
#define AR_LEN 100

struct Account {
    char name[30];
    double balance;
};

int main(void) {
    setlocale(LC_ALL, "");
    struct Account ar[AR_LEN], a;
    FILE *f = fopen("in.txt", "r");
    int count = 0;

    while (count < AR_LEN && 2 == fscanf(f, "%s %lf", a.name, &a.balance)) {
        ar[count] = a;
        ++count;
    }
    fclose(f);

    printf("Должники:\n");
    for (int i = 0; i < count; ++i) {
        if (ar[i].balance < 0) {
            printf("%s (%.2f)\n", ar[i].name, ar[i].balance);
        }
    }
    return 0;
}