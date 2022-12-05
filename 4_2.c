#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* inp = fopen("4_inp", "r");
    char line[50] = {0};
    int i = 0, amount = 0;
    while (fgets(line, 50, inp))
    {
        int k = 0, num[4] = {0};
        printf("line[%04d]: %s", ++i, line);
        num[0] = atoi(line);
        num[1] = atoi(&line[(num[0] > 9) + 1]) * -1;
        num[2] = atoi(&line[(num[0] > 9) + (num[1] > 9) + 4]);
        num[3] = atoi(&line[(num[0] > 9) + (num[1] > 9) + (num[2] > 9) + 5]) * -1;
        if ((num[2] <= num[0] && num[3] >= num[0])
            || (num[2] <= num[1] && num[3] >= num[1])
            || (num[0] <= num[2] && num[1] >= num[3]))
            amount++;
        printf("num[0] = %d, num[1] = %d, num[2] = %d, num[3] = %d\n", num[0], num[1], num[2], num[3]);
        printf("amount == %d\n", amount);
    }
    fclose(inp);
    return 0;
}
