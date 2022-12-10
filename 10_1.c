#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* inp = fopen("10_inp", "r");
    char line[10] = {0};
    int k = 0, x = 1, cycle = 0, amount = 0;
    while (fgets(line, 10, inp))
    {
        //printf("line[%04d]: %s", ++k, line);
        if (line[0] == 'n')
        {
            cycle++;
            if (cycle % 40 == 20)
            {
                printf("cycle = %d, x = %d, strength = %d\n", cycle, x, cycle * x);
                amount += cycle * x;
            }
        }
        else
        {
            cycle += 2;
            if (cycle % 40 == 20 || (cycle - 1) % 40 == 20)
            {
                int c = cycle;
                if (cycle % 2 != 0)
                    c--;
                printf("cycle = %d, x = %d, strength = %d\n", c, x, c * x);
                amount += c * x;
            }
            x += atoi(&line[4]);
        }
    }
    printf("x = %d, cycle = %d\namount = %d\n", x, cycle, amount);
    fclose(inp);
    return 0;
}
