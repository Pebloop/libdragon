/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** epitech tools
*/

#include <stdlib.h>

int dg_strcmp(char const *s1, char const *s2)
{
    int c;

    for (c = 0; s1[c] == s2[c]; c++)
        if (s1[c] == '\0')
            return 0;
    return s1[c] - s2[c];
}
