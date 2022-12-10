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
    int amount = 0, k = 0, steps, ih = 500, jh = 500, it = 500, jt = 500;
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
        tail[it][jt] = 1;
        while (steps--)
        {
            jh += jiter;
            ih += iter;
            if (modul(ih - it) > 1 || modul(jh - jt) > 1)
                fix_tail(ih, jh, &it, &jt);
            tail[it][jt] = 1;
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            //printf("%d", tail[i][j]);
            if (tail[i][j] == 1)
                amount++;
        }
        printf("\n");
    }
    printf("amount = %d\n", amount);
    fclose(inp);
    return 0;
}
