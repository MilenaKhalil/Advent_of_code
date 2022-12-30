#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void min_path(int di, int dj, char map[41][95], int sol[41][95])
{
    if (di > 0 && map[di][dj] + 1 >= map[di - 1][dj])
    {
        if (sol[di][dj] + 1 < sol[di - 1][dj])
        {
            sol[di - 1][dj] = sol[di][dj] + 1;
            min_path(di - 1, dj, map, sol);
        }
    }
    if (dj > 0 && map[di][dj] + 1 >= map[di][dj - 1])
    {
        if (sol[di][dj] + 1 < sol[di][dj - 1])
        {
            sol[di][dj - 1] = sol[di][dj] + 1;
            min_path(di, dj - 1, map, sol);
        }
    }
    if (di < 40 && map[di][dj] + 1 >= map[di + 1][dj])
    {
        if (sol[di][dj] + 1 < sol[di + 1][dj])
        {
            sol[di + 1][dj] = sol[di][dj] + 1;
            min_path(di + 1, dj, map, sol);
        }
    }
    if (dj < 94 && map[di][dj] + 1 >= map[di][dj + 1])
    {
        if (sol[di][dj] + 1 < sol[di][dj + 1])
        {
            sol[di][dj + 1] = sol[di][dj] + 1;
            min_path(di, dj + 1, map, sol);
        }
    }
    return ;
}

void fill(int sol[41][95], int num)
{
    for (int i = 0; i < 41; i++)
        for (int j = 0; j < 95; j++)
            sol[i][j] = num;
}

#include <limits.h>

int main()
{
    FILE* inp = fopen("12_inp", "r");
    char line[100] = {0};
    char map[41][95] = {0};
    int sol[41][95];
    //track[0][0] = 1;
    fill(sol, INT_MAX / 2);
    int k = 0, si = 0, sj = 0, di, dj;                   // start, dest
    while (fgets(line, 100, inp))
    {
        int i = 0;
        //printf("line[%02d]: %s", k, line);
        while (line[i] != 0)
        {
            map[k][i] = line[i];
            if (line[i] == 'S')
            {
                si = k;
                sj = i;
                map[k][i] = 'a';
            }
            if (line[i] == 'E')
            {
                di = k;
                dj = i;
                map[k][i] = 'z';
            }
            i++;
        }
        k++;
    }
    sol[si][sj] = 0;
    min_path(si, sj, map, sol);
    int min = sol[di][dj];
    for (int i = 0; i < 41; i++)
    {
        for (int j = 0; j < 95; j++)
        {
            if (map[i][j] == 'a')
            {
                fill(sol, INT_MAX / 2);
                sol[i][j] = 0;
                min_path(i, j, map, sol);
                if (sol[di][dj] < min)
                    min = sol[di][dj];
            }
        }
    }
    printf("min = %d\n", min);
    fclose(inp);
    return 0;
}
