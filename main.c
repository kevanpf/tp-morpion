
#include <stdio.h>
#include "tic-tac-toe.h"

void afficher_grille(char tab[9])
{
    printf("\n");
    printf(" %c | %c | %c\n", tab[0], tab[1], tab[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tab[3], tab[4], tab[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tab[6], tab[7], tab[8]);
    printf("\n");
}

int verifier_victoire(char tab[9], char symbole)
{
    for (int i = 0; i < 9; i += 3)
    {
        if (tab[i] == symbole &&
            tab[i + 1] == symbole &&
            tab[i + 2] == symbole)
        {
            return 1;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (tab[i] == symbole &&
            tab[i + 3] == symbole &&
            tab[i + 6] == symbole)
        {
            return 1;
        }
    }

    if (tab[0] == symbole &&
        tab[4] == symbole &&
        tab[8] == symbole)
    {
        return 1;
    }

    if (tab[2] == symbole &&
        tab[4] == symbole &&
        tab[6] == symbole)
    {
        return 1;
    }

    return 0;
}

int grille_pleine(char tab[9])
{
    for (int i = 0; i < 9; i++)
    {
        if (tab[i] == ' ')
        {
            return 0;
        }
    }

    return 1;
}

void jouer_ordinateur(char tab[9])
{
    for (int i = 0; i < 9; i++)
    {
        if (tab[i] == ' ')
        {
            tab[i] = 'O';
            printf("L'ordinateur joue en case %d\n", i);
            break;
        }
    }
}

int main(void)
{
    char tab[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int choix;

    printf("Bienvenue dans le morpion !\n");
    printf("Choisissez une case entre 0 et 8.\n");

    afficher_grille(tab);

    while (1)
    {
        printf("Choisissez quelle case jouer (0-8) : ");

        if (scanf("%d", &choix) != 1)
        {
            printf("Vous devez entrer un nombre !\n");
            return 1;
        }

        if (choix < 0 || choix > 8)
        {
            printf("Case invalide !\n");
            continue;
        }

        if (tab[choix] != ' ')
        {
            printf("Cette case est déjà occupée !\n");
            continue;
        }

        tab[choix] = 'X';
        afficher_grille(tab);

        if (verifier_victoire(tab, 'X'))
        {
            printf("Bravo, vous avez gagné !\n");
            break;
        }

        if (grille_pleine(tab))
        {
            printf("Match nul !\n");
            break;
        }

        jouer_ordinateur(tab);
        afficher_grille(tab);

        if (verifier_victoire(tab, 'O'))
        {
            printf("L'ordinateur a gagné !\n");
            break;
        }

        if (grille_pleine(tab))
        {
            printf("Match nul !\n");
            break;
        }
    }

    printf("Fin de la partie.\n");

    return 0;
}
