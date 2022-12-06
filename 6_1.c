#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* inp = fopen("6_inp", "r");
    char line[5000] = {0};
    int i = 0;
    while (fgets(line, 5000, inp))
    {
        printf("line[%04d]: %s", ++i, line);
        int i = 0, flag = 0;
        while(1)
        {
            int letters[26] = {0};
            for (int j = 0; j < 14; j++)
            {
                if (letters[line[i + j] - 'a'] != 0)
                {
                    flag = 1;
                    break;
                }
                letters[line[i + j] - 'a']++;
            }
            if (flag == 0)
                break;
            i++;
            flag = 0;
        }
        printf("i = %d\n", i + 14);
    }
    fclose(inp);
    return 0;
}
