/*
Задача 8.
Посчитать, сколько слов начинается на каждую гласную букву (a,e,i,o,u).
*/

#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");
    FILE *f = fopen("in.txt", "r");
    char word[50];
    int count[5] = {0};  // a, e, i, o, u
    const char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    while (1 == fscanf(f, "%s", word)) {
        for (int i = 0; i < 5; ++i) {
            if (word[0] == vowels[i]) {
                ++count[i];
                break;
            }
        }
    }
    fclose(f);

    for (int i = 0; i < 5; ++i) {
        printf("%c: %d\n", vowels[i], count[i]);
    }
    return 0;
}