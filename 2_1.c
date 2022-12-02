#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* inp = fopen("2_1_inp", "r");
    char line[10] = {0};
    int i = 0, amount = 0;
    while (fgets(line, 10, inp))
    {
        printf("line[%04d]: %s", ++i, line);
        if (line[2] == 'Y')
            amount += 3 + (line[0] - 'A' + 1);
        else if (line[2] == 'Z')
            amount += 6 + ((line[0] - 'A' + 1) % 3 + 1);
        else
            amount += (line[0] - 'A' + 2) % 3 + 1;
        printf("amount == %d\n", amount);
    }
    fclose(inp);
    return 0;
}
