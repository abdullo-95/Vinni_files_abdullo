/*
Задача 9.
Файл in.txt: "Петров 4" (фамилия, курс).
Вывести студентов в обратном порядке.
*/

#include <stdio.h>
#include <locale.h>
#define AR_LEN 100

struct Student {
    char name[30];
    int course;
};

int main(void) {
    setlocale(LC_ALL, "");
    struct Student ar[AR_LEN], s;
    FILE *f = fopen("in.txt", "r");
    int count = 0;

    while (count < AR_LEN && 2 == fscanf(f, "%s %d", s.name, &s.course)) {
        ar[count] = s;
        ++count;
    }
    fclose(f);

    for (int i = count - 1; i >= 0; --i) {
        printf("%s %d\n", ar[i].name, ar[i].course);
    }
    return 0;
}