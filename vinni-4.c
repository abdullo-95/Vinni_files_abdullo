/*
Задача 4.
    Война_и_мир 1869
    Преступление_и_наказание 1866
Считать записи в массив структур и вывести только книги,
изданные после 1800 года.
*/

#include <stdio.h>
#include <locale.h>
#define AR_LEN 100

struct Book {
    char title[50];
    int year;
};

int main(void) {
    setlocale(LC_ALL, "");
    struct Book ar[AR_LEN];
    struct Book b;
    FILE *f = fopen("in.txt", "r");
    int count = 0;

    while (count < AR_LEN && 2 == fscanf(f, "%s %d", b.title, &b.year)) {
        ar[count] = b;
        ++count;
    }
    fclose(f);

    for (int i = 0; i < count; ++i) {
        if (ar[i].year > 1800) {
            printf("%s (%d)\n", ar[i].title, ar[i].year);
        }
    }
    return 0;
}