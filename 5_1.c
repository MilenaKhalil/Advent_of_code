#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* inp = fopen("5_inp", "r");
    char line[50] = {0};
    int i = 0;
    char crates[9][60] = {{'B', 'Q', 'C'},
                            {'R', 'Q', 'W', 'Z'},
                            {'B', 'M', 'R', 'L', 'V'},
                            {'C', 'Z', 'H', 'V', 'T', 'W'},
                            {'D', 'Z', 'H', 'B', 'N', 'V', 'G'},
                            {'H', 'N', 'P', 'C', 'J', 'F', 'V', 'Q'},
                            {'D', 'G', 'T', 'R', 'W', 'Z', 'S'},
                            {'C', 'G', 'M', 'N', 'B', 'W', 'Z', 'P'},
                            {'N', 'J', 'B', 'M', 'W', 'Q', 'F', 'P'}};
    while (fgets(line, 50, inp))
    {
        int k, j, num[3] = {0};
        printf("line[%04d]: %s", ++i, line);
        num[0] = atoi(&line[5]);
        num[1] = atoi(&line[(num[0] > 9) + 12]) - 1;
        num[2] = atoi(&line[(num[0] > 9) + (num[1] > 9) + 17]) - 1;
        k = strlen(crates[num[1]]) - 1;
        j = strlen(crates[num[2]]);
        printf("num[0] = %d, num[1] = %d, num[2] = %d\n", num[0], num[1], num[2]);
        while (num[0]--)
        {
            crates[num[2]][j] = crates[num[1]][k];
            crates[num[1]][k] = 0;
            k--;
            j++;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 60; j++)
            printf("%c ", crates[i][j]);
        printf("\n");
    }
    fclose(inp);
    return 0;
}
