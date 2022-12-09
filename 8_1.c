#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int main()
{
    FILE* inp = fopen("8_inp", "r");
    char line[200] = {0};
    int len = 99;         
    int grid[len][len], right[len][len], left[len][len], up[len][len], down[len][len];
    int amount = 0, i = 0, k = 0;
    while (fgets(line, 200, inp))
    {
        printf("line[%04d]: %s", ++k, line);
        for (int j = 0; j < len; j++)
            grid[i][j] = line[j] - '0';
        i++;
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (j == 0)
            {
                right[i][j] = -1;
                left[i][len - 1] = -1;
                down[j][i] = -1;
                up[len - 1][i] = -1;
            }
            else
            {
                right[i][j] = max(right[i][j - 1], grid[i][j - 1]);
                left[i][len - 1 - j] = max(left[i][len - j], grid[i][len - j]);
                down[j][i] = max(down[j - 1][i], grid[j - 1][i]);
                up[len - 1 - j][i] = max(up[len - j][i], grid[len - j][i]);
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (grid[i][j] <= min(min(down[i][j], up[i][j]), 
                                    min(left[i][j], right[i][j])))
                amount++;
        }
    }
    printf("amount = %d, uns = %d\n", amount, len*len - amount);
    fclose(inp);
    return 0;
}
