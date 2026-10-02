/*
Задача 5.
"Молоко 89.50". Посчитать общую стоимость всех товаров.
*/

#include <stdio.h>
#include <locale.h>
#define AR_LEN 100

struct Product {
    char name[30];
    double price;
};

int main(void) {
    setlocale(LC_ALL, "");
    struct Product ar[AR_LEN], p;
    FILE *f = fopen("in.txt", "r");
    int count = 0;
    double total = 0;

    while (count < AR_LEN && 2 == fscanf(f, "%s %lf", p.name, &p.price)) {
        ar[count] = p;
        ++count;
    }
    fclose(f);

    for (int i = 0; i < count; ++i) {
        total += ar[i].price;
    }

    printf("Итого: %.2f\n", total);
    return 0;
}