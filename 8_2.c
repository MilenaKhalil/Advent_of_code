#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* inp = fopen("8_inp", "r");
    char line[200] = {0};
    int len = 99;         
    int grid[len][len], right[len][len], left[len][len], up[len][len], down[len][len];
    int max = 0, i = 0, k = 0;
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
            int u = 0, d = 0, l = 0, r = 0;
            while (j != len - 1 && j + r < len - 1 && grid[i][j] > grid[i][j + ++r]);
            while (i != len - 1 && i + d < len - 1 && grid[i][j] > grid[i + ++d][j]);
            while (j != 0 && j - l > 0 && grid[i][j] > grid[i][j - ++l]);
            while (i != 0 && i - u > 0 && grid[i][j] > grid[i - ++u][j]);
            if (u * d * l * r > max)
                max = u * d * l * r;
            //printf("u = %d, d = %d, l = %d, r = %d\n", u, d, l, r);
        }
        //printf("\n");
    }
    printf("max = %d\n", max);
    fclose(inp);
    return 0;
}
