#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int modul(int a)
{
    if (a >= 0)
        return a;
    return a * -1;
}

void fix_tail(int ih, int jh, int* it, int* jt)
{
    if (modul(*it - ih) < 2 && modul(*jt - jh) < 2)
        return ;
    if (*it - ih > 0)
        *it -= 1;
    if (*jt - jh > 0)
        *jt -= 1;
    if (ih - *it > 0)
        *it += 1;
    if (jh - *jt > 0)
        *jt += 1;
}

int main()
{
    FILE* inp = fopen("9_inp", "r");
    char line[10] = {0};
    int tail[1000][1000] = {0};
    int coords[2][10] = {0};
    int amount = 0, k = 0, steps;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 10; j++)
            coords[i][j] = 500;
    }
    while (fgets(line, 10, inp))
    {
        printf("line[%04d]: %s", ++k, line);
        steps = atoi(&line[2]);
        int iter = 0, jiter = 0;
        if (line[0] == 'R')
            jiter = 1;
        if (line[0] == 'L')
            jiter = -1;
        if (line[0] == 'U')
            iter = -1;
        if (line[0] == 'D')
            iter = 1;
        //tail[coords[0][9]][coords[1][9]] = 1;
        while (steps--)
        {
            coords[0][0] += iter;
            coords[1][0] += jiter;
            for (int i = 0; i < 9; i++)
                fix_tail(coords[0][i], coords[1][i], &coords[0][i + 1], &coords[1][i + 1]);
            tail[coords[0][9]][coords[1][9]] = 1;
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            printf("%d", tail[i][j]);
            if (tail[i][j] == 1)
                amount++;
        }
        printf("\n");
    }
    printf("amount = %d\n", amount);
    fclose(inp);
    return 0;
}
