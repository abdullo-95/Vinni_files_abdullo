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


/*
Разбор по блокам
1. Подключения и константа

c
#include <stdio.h>
#include <locale.h>
#define AR_LEN 100
stdio.h — для fopen, fscanf, printf.

locale.h — чтобы русские буквы в консоли отображались корректно.

AR_LEN 100 — максимум книг, которые можем считать.

2. Структура

c
struct Book {
    char title[50];
    int year;
};
Описывает одну книгу: название (строка до 50 символов) + год издания.

3. Подготовка в main

c
setlocale(LC_ALL, "");       // включаем русский язык
struct Book ar[AR_LEN];      // массив из 100 книг
struct Book b;               // временная переменная для чтения одной книги
FILE *f = fopen("in.txt", "r");  // открываем файл на чтение
int count = 0;               // счётчик реально прочитанных книг
4. Чтение файла — самое интересное

c
while (count < AR_LEN && 2 == fscanf(f, "%s %d", b.title, &b.year)) {
    ar[count] = b;
    ++count;
}
fscanf возвращает число успешно считанных полей. Здесь ожидаем 2 (строка + число).

Условие 2 == fscanf(...) означает: «пока удаётся прочитать и название, и год — продолжай».

Если строка закончилась или формат неверный — fscanf вернёт не 2, и цикл остановится.

count < AR_LEN — защита от переполнения массива.

ar[count] = b; — копируем прочитанную книгу в массив.

++count — увеличиваем счётчик.

Итог: в ar лежат все книги, а в count — сколько их.

5. Закрытие файла

c
fclose(f);
Освобождаем файл. Обязательно.

6. Вывод с фильтром

c
for (int i = 0; i < count; ++i) {
    if (ar[i].year > 1800) {
        printf("%s (%d)\n", ar[i].title, ar[i].year);
    }
}*/
