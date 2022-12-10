#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* inp = fopen("10_inp", "r");
    char line[10] = {0};
    int k = 0, x = 1, cycle = -1, amount = 0;
    char grid[6][40] = {0};
    while (fgets(line, 10, inp))
    {
        //printf("line[%04d]: %s", ++k, line);
        if (line[0] == 'n')
        {
            cycle++;
            printf("cycle = %d, x = %d\n", cycle, x);
            if (cycle%40 == x || cycle%40 == x - 1 || cycle%40 == x + 1)
                grid[cycle / 40][cycle % 40] = '#';
            else
                grid[cycle / 40][cycle % 40] = '.';

        }
        else
        {
            for (int i = 0; i < 2; i++)
            {
                cycle++;
                printf("cycle = %d, x = %d\n", cycle, x);
                if (cycle%40 == x || cycle%40 == x - 1 || cycle%40 == x + 1)
                    grid[cycle / 40][cycle % 40] = '#';
                else
                    grid[cycle / 40][cycle % 40] = '.';
            }
            x += atoi(&line[4]);
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 40; j++)
            printf("%c", grid[i][j]);
        printf("\n");
    }
    //printf("x = %d, cycle = %d\namount = %d\n", x, cycle, amount);
    fclose(inp);
    return 0;
}
