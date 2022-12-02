#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* inp = fopen("1_1_inp", "r");
    char line[10] = {0};
    int i = 0, max1 = 0, max2 = 0, max3 = 0, amount = 0, k;
    while (fgets(line, 10, inp))
    {
        printf("line[%04d]: %s", ++i, line);
        
        k = atoi(line);
        printf("%d\n", k);
        amount += k;
        if (line[0] == '\n')
        {
            if (amount > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = amount;
            }
            else if (amount > max2)
            {
                max3 = max2;
                max2 = amount;
            }
            else if (amount > max3)
                max3 = amount;
            printf("%d\n", amount);
            amount = 0;
        }
    }
    printf("super_max = %d\n", max1 + max2 + max3);
    fclose(inp);
    return 0;
}
