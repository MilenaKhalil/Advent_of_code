#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* inp = fopen("3_inp", "r");
    char line0[50] = {0}, line1[50] = {0}, line2[50] = {0};
    int i = 0, amount = 0, k = 0;
    while (fgets(line0, 50, inp))
    {
        printf("line0[%04d]: %s", ++i, line0);
        fgets(line1, 50, inp);
        printf("line1[%04d]: %s", ++i, line1);
        fgets(line2, 50, inp);
        printf("line2[%04d]: %s", ++i, line2);
        char letters[52] = {0};
        for (int j = 0; j < strlen(line0) - 1; j++)
        {
            int y = 0;
            if (line0[j] >= 'A' && line0[j] <= 'Z')
                y = line0[j] - 'A' + 26;
            else
                y = line0[j] - 'a';
            letters[y] = 2;
        }
        for (int j = 0; j < strlen(line1) - 1; j++)
        {
            if (line1[j] >= 'A' && line1[j] <= 'Z' && letters[line1[j] - 'A' + 26] != 0)
                letters[line1[j] - 'A' + 26] = 6;
            else if (letters[line1[j] - 'a'] != 0 && line1[j] >= 'a' && line1[j] <= 'z')
                letters[line1[j] - 'a'] = 6;
        }
        while (k < strlen(line2))
        {
            if ((line2[k] <= 'Z' && line2[k] >= 'A' && letters[line2[k] - 'A' + 26] == 6) 
                || (line2[k] <= 'z' && line2[k] >= 'a' && letters[line2[k] - 'a'] == 6))
                break;
            k++;
        }
        if (line2[k] >= 'A' && line2[k] <= 'Z')
            amount += 1 + line2[k] - 'A' + 26;
        else
            amount += 1 + line2[k] - 'a';
        printf("amount == %d, line2[k] = %c\n", amount, line2[k]);
        k = 0;
    }
    fclose(inp);
    return 0;
}
