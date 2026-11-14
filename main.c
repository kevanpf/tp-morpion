
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char tab[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int choix;

    printf("%c", tab[0]);
    printf("%c", tab[1]);
    printf("%c\n", tab[2]);
    printf("%c", tab[3]);
    printf("%c", tab[4]);
    printf("%c\n", tab[5]);
    printf("%c", tab[6]);
    printf("%c", tab[7]);
    printf("%c", tab[8]);

    printf("\n");
    printf(" %c | %c | %c\n", tab[0], tab[1], tab[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tab[3], tab[4], tab[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tab[6], tab[7], tab[8]);

    printf("Choisissez ou jouer :\n");
    scanf("%d", &choix);

    return 0;
}
